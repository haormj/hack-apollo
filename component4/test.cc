#include "hack_apollo/component4/test.h"

bool ComponentTest::Init() {
  AINFO << "component init finished";
  return true;
}

bool ComponentTest::Proc(const std::shared_ptr<Hello>& hello,
                         const std::shared_ptr<Hello>& hello2,
                         const std::shared_ptr<Hello>& hello3,
                         const std::shared_ptr<Hello>& hello4) {
  AINFO << "component proc finished" << " 1: " << hello->hello()
        << ", 2: " << hello2->hello() << ", 3: " << hello3->hello()
        << ", 4: " << hello4->hello();
  return true;
}