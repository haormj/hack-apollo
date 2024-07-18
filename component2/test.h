#include "hack_apollo/proto/echo.pb.h"

#include "cyber/component/component.h"

class ComponentTest : public apollo::cyber::Component<Hello, Hello> {
 public:
  bool Init() override;
  bool Proc(const std::shared_ptr<Hello>&,
            const std::shared_ptr<Hello>&) override;
};

CYBER_REGISTER_COMPONENT(ComponentTest)