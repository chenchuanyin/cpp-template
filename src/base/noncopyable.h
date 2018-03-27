#ifndef CT_BASE_NONCOPYABLE_H_
#define CT_BASE_NONCOPYABLE_H_

namespace ct {
namespace base {

class Noncopyable {
 public:
  Noncopyable()  = default;
  ~Noncopyable() = default;

  Noncopyable(const Noncopyable&) = delete;
  Noncopyable operator=(const Noncopyable&) = delete;
};

}  // namespace base
}  // namespace ct

#endif  // CT_BASE_NONCOPYABLE_H_
