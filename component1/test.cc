#include "hack_apollo/component1/test.h"

bool ComponentTest::Init() {
  AINFO << "component init finished";
  return true;
}

bool ComponentTest::Proc(const std::shared_ptr<Hello>& hello) {
  AINFO << "component proc finished" << hello->hello();
  return true;
}