#include <atomic>
#include <cstddef>
#include <iomanip>
#include <iostream>

#include "cyber/transport/shm/block.h"

class Sta {
 public:
  //   virtual void hello() {}
  bool a = false;
  std::atomic<bool> need_remap_ = {true};
  std::atomic<uint32_t> seq_ = {3};
  std::atomic<uint32_t> reference_count_ = {1};
  std::atomic<uint64_t> ceiling_msg_size_ = {2};
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

  return 0;
}