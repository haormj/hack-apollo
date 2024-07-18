#include "cyber/component/component.h"
#include "cyber/component/timer_component.h"

class Test : public apollo::cyber::TimerComponent {
 public:
  bool Init() override;
  bool Proc() override;
};

CYBER_REGISTER_COMPONENT(Test)
