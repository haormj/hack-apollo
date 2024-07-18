#include "hack_apollo/timer_component/test.h"

bool Test::Init() {
  hello_writer_ = node_->CreateWriter<Hello>("/test/hello");
  AINFO << "init finished";
  return true;
}

bool Test::Proc() {
  auto hello = std::make_shared<Hello>();
  hello->set_hello("1");
  hello_writer_->Write(hello);
  AINFO << "proc finished";
  return true;
}