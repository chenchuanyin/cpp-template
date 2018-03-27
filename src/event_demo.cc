extern "C" {
#include "event/ae.h"
}

#include <iostream>

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void socket_readable(aeEventLoop *loop, int fd, void *data, int mask) {
  std::cout << "socket_readable" << std::endl;
  char buf[1024];
  int read_num = read(fd, buf, sizeof(buf));

  if (read_num == 0) {
    perror("read() error");
    close(fd);
    aeDeleteFileEvent(loop, fd, mask);
  }
  write(fd, buf, strlen(buf));

  printf("%s\n", buf);
}

void socket_writable(aeEventLoop *loop, int fd, void *data, int mask) {
  char buf[1024];
  sprintf(buf, "%s", "hello world");
  int write_num = write(fd, buf, sizeof(buf));

  if (write_num == 0) {
    perror("write() error");
    close(fd);
    aeDeleteFileEvent(loop, fd, mask);
  }
  printf("%s\n", buf);
}

void setNoblocking(int fd) {
  int flags = fcntl(fd, F_GETFL, 0);
  fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}

void socket_listenable(aeEventLoop *loop, int fd, void *data, int mask) {
  std::cout << "socket_listenable" << std::endl;

  struct sockaddr_in client_addr;
  int addrlen = sizeof(client_addr);
  int newfd;

  while((newfd = accept(fd, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen)) != -1) {
    std::cout << "new socket" << std::endl;
    setNoblocking(newfd);
    aeCreateFileEvent(loop, newfd, AE_READABLE, socket_readable, NULL);
  }
}

int main(int argc, char **argv) {
   aeEventLoop *event_loop = aeCreateEventLoop(1024);
   if (event_loop == NULL) {
     std::cerr << "aeCreateEventLoop call failed." << std::endl;
     return -1;
   }
   int listener;
   if ((listener = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
     perror("socket() call error");
     exit(1);
   }
   setNoblocking(listener);
   int yes;
   if (setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
     perror("setsockopt() call error");
     exit(1);
   }
   struct sockaddr_in server_addr;
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = INADDR_ANY;
   server_addr.sin_port = htons(1500);
   if (bind(listener, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
     perror("bind() call error");
     exit(1);
   }
   if (listen(listener, 10) == -1) {
     perror("listen() call error");
     exit(1);
   }
   aeCreateFileEvent(event_loop, listener, AE_READABLE, socket_listenable, NULL);
   aeMain(event_loop);
   aeDeleteEventLoop(event_loop);

   return 0;
}
