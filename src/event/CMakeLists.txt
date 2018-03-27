set(SRCS ae.c zmalloc.c)

add_library(event STATIC ${SRCS})
target_link_libraries(event c)
