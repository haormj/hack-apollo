#include "hack_apollo/proto/echo.pb.h"
#include "hack_apollo/timer_component/proto/config.pb.h"

#include "cyber/component/component.h"
#include "cyber/component/timer_component.h"
#include "cyber/cyber.h"

class Test : public apollo::cyber::TimerComponent {
 public:
  bool Init() override;
  bool Proc() override;

 private:
  std::shared_ptr<apollo::cyber::Writer<Hello>> hello_writer_ = nullptr;
  std::shared_ptr<TimerComponentConfig> config_ = nullptr;
  int64_t seq_id_ = 1;
};

CYBER_REGISTER_COMPONENT(Test)
