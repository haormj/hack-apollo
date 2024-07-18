## hack-apollo

### 概述

本项目主要是为了测试 https://github.com/ApolloAuto/apollo/ 中的一些特性

### 注意

- bazel 编译 proto 目录中有 - 就会报错

### 使用

- cd /path/to/apollo
- git clone 
- bazel build hack_apollo/...
- mainboard -d hack_apollo/timer_component/test.dag