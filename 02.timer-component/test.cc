#include "hack-apollo/02.timer-component/test.h"

bool Test::Init() {
  AINFO << "init";
  return true;
}

bool Test::Proc() {
  AINFO << "proc";
  return true;
}