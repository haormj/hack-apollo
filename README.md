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

### 细节

- cyber 支持 pub/sub, req/rsp 模式
- cyber 目前支持数据驱动和定时两种
	- 数据驱动 Proc 最多支持接收 4 个 topic，其中第一个topic为驱动topic，当来数据时，会获取其他3个topic的最新数据，然后调用 proc
	- 若继承 Component 时，没有接收任何 topic，则不用实现 Proc，只会执行 Init
	- 数据驱动的 Component, 在调度时，会根据注册一个唤醒的回调，当来数据时，唤醒当前 croutine，然后获取数据，调用 proc
	- 时间驱动就是按照指定时间间隔，回调 Proc
- cyber 框架整体基于 channel 通信
	- 当启动一个 reader 时，会创建对应 channel buffer 来负责接收数据
	- 当向该 channel 写入数据时候，会出发通知，然后将数据写入到所有的订阅该 channel 的 buffer 中
- 如果实际场景中，不需要数据或者定频驱动，只是需要一个额外的任务，可以通过下面方式
	- 继承 Component<>, 然后重写 Init
	- 然后在 Init 中调用 apollo::cyber::Async 来启动异步任务，也可以将这个内容封装到一个类中 参考 component0