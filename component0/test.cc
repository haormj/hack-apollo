#include "hack_apollo/component0/test.h"

bool ComponentTest::Init() {
  Foo foo;
  foo.RunOnce();
  AINFO << "component0 init finished";
  return true;
}