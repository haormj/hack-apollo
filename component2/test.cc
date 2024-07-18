#include "hack_apollo/component2/test.h"

bool ComponentTest::Init() {
  AINFO << "component init finished";
  return true;
}

bool ComponentTest::Proc(const std::shared_ptr<Hello>& hello,
                         const std::shared_ptr<Hello>& hello2) {
  AINFO << "component proc finished" << " 1: " << hello->hello()
        << ", 2: " << hello2->hello();
  return true;
}