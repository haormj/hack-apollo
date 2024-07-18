#include "hack_apollo/timer_component/test.h"

bool Test::Init() {
  config_ = std::make_shared<TimerComponentConfig>();
  if (!apollo::cyber::common::GetProtoFromFile(config_file_path_,
                                               config_.get())) {
    return false;
  }
  hello_writer_ = node_->CreateWriter<Hello>(config_->channel_name());
  AINFO << "init finished";
  return true;
}

bool Test::Proc() {
  seq_id_++;
  auto hello = std::make_shared<Hello>();
  hello->set_hello(std::to_string(seq_id_));
  hello_writer_->Write(hello);
  AINFO << "proc finished " << config_->channel_name();
  return true;
}