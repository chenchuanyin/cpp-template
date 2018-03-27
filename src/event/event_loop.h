#ifndef CT_EVENT_EVENTLOOP_H_
#define CT_EVENT_EVENTLOOP_H_

#include "base/noncopyable.h"

extern "C" {
#include "ae/ae.h"
}

namespace ct {
namespace event {
class EventLoop : public ct::base::Noncopyable {
 public:
  EventLoop();
  ~EventLoop();

  void Loop();
  void Stop();

  void CreateEvent();
  void DeleteEvent();

 private:
  aeEventLoop *handler;
};

}  // namespace event
}  // namespace ct

#endif  // CT_EVENT_EVENTLOOP_H_
