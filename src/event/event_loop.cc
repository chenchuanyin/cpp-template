#include "event_loop.h"

namespace ct {
namespace event {

EventLoop::EventLoop() {
  handler = aeCreateEventLoop(1024);
  if (handler == NULL) {
  }
}

EventLoop::~EventLoop() {
  if (handler) {
    aeDeleteEventLoop(handler);
  }
}

void EventLoop::Loop() { aeMain(handler); }

void EventLoop::Stop() { aeStop(handler); }

void EventLoop::CreateEvent() {
  // aeCreateFileEvent(handler, int fd, int mask, aeFileProc *proc, void
  // *clientData)
}

void EventLoop::DeleteEvent() {
  // aeDeleteFileEvent(loop, int fd, int mask)
}

}  // namespace event
}  // namespace ct
