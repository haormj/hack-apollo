#include "hack_apollo/proto/echo.pb.h"

#include "cyber/component/component.h"

class Foo {
 public:
  void RunOnce() {
    auto res = apollo::cyber::Async(&Foo::Task, this);
    // AINFO << res;
  }

  void Task() { AINFO << "async task"; }
};

class ComponentTest : public apollo::cyber::Component<> {
 public:
  bool Init() override;
};

CYBER_REGISTER_COMPONENT(ComponentTest)