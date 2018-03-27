set(SRCS
  event_loop.cc
  ae/ae.c
  ae/zmalloc.c)

add_library(event STATIC ${SRCS})
target_link_libraries(event c)
