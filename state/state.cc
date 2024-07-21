#include <atomic>
#include <cstddef>
#include <iomanip>
#include <iostream>

#include "cyber/common/util.h"
#include "cyber/transport/message/message_info.h"
#include "cyber/transport/shm/block.h"
#include "cyber/transport/shm/condition_notifier.h"
#include "cyber/transport/shm/readable_info.h"

class Sta {
 public:
  //   virtual void hello() {}
  bool a = false;
  std::atomic<bool> need_remap_ = {true};
  std::atomic<uint32_t> seq_ = {3};
  std::atomic<uint32_t> reference_count_ = {1};
  std::atomic<uint64_t> ceiling_msg_size_ = {2};
};

struct IndicatorA {
  std::atomic<uint64_t> next_seq = {0};
  apollo::cyber::transport::ReadableInfo infos[4096];
  uint64_t seqs[4096] = {0};
};

struct ReadableInfo {
  uint64_t host_id_;
  uint32_t block_index_;
  uint64_t channel_id_;
};

int main() {
  Sta a;
  std::cout << sizeof(Sta) << std::endl;
  std::cout << offsetof(Sta, need_remap_) << std::endl;        // 4
  std::cout << offsetof(Sta, seq_) << std::endl;               // 4
  std::cout << offsetof(Sta, reference_count_) << std::endl;   // 8
  std::cout << offsetof(Sta, ceiling_msg_size_) << std::endl;  // 8
  std::cout << sizeof(std::atomic<bool>) << std::endl;
  char* base = reinterpret_cast<char*>(&a);
  for (int i = 0; i < 24; i++) {
    std::cout << std::hex << std::setw(2) << std::setfill('0')
              << static_cast<int>(base[i]) << " ";
  }
  std::cout << std::dec << std::endl;
  std::cout << "block" << std::endl;
  std::cout << sizeof(apollo::cyber::transport::Block) << std::endl;
  std::cout << std::hex << apollo::cyber::common::Hash("/test/hello1")
            << std::endl;
  std::cout << sizeof(size_t) << std::endl;
  std::cout << "Indicator"
            << sizeof(apollo::cyber::transport::ConditionNotifier::Indicator)
            << std::endl;
  std::cout << "ReadableInfo " << sizeof(ReadableInfo) << std::endl;
  std::cout << sizeof(std::atomic<uint64_t>) << std::endl;

  apollo::cyber::transport::ReadableInfo readableInfo(1, 2, 3);
  apollo::cyber::transport::MessageInfo messageInfo;
  messageInfo.set_channel_id(1);
  messageInfo.set_seq_num(2);

  return 0;
}