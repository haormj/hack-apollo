#include "hack_apollo/proto/echo.pb.h"

#include "cyber/component/component.h"
#include "cyber/component/timer_component.h"

class Test : public apollo::cyber::TimerComponent {
 public:
  bool Init() override;
  bool Proc() override;

 private:
  std::shared_ptr<apollo::cyber::Writer<Hello>> hello_writer_;
};

CYBER_REGISTER_COMPONENT(Test)
