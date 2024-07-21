package main

import (
	"os"

	"github.com/haormj/cyber/common"
	"github.com/haormj/cyber/log"
	"github.com/haormj/cyber/pb"
	"github.com/haormj/cyber/transport/message"
	"github.com/haormj/cyber/transport/receiver"
	pb1 "github.com/haormj/test/pb"
	"google.golang.org/protobuf/proto"
)

func main() {
	r := receiver.NewShmReceiver[*pb1.Hello](
		&pb.RoleAttributes{
			HostName:    proto.String("jetson"),
			HostIp:      proto.String("192.168.50.92"),
			ProcessId:   proto.Int32(int32(os.Getpid())),
			NodeName:    proto.String("test02"),
			NodeId:      proto.Uint64(common.Hash([]byte("test02"))),
			ChannelName: proto.String("/test/hello3"),
			ChannelId:   proto.Uint64(common.Hash([]byte("/test/hello3"))),
			Id:          proto.Uint64(common.Hash([]byte("192.168.50.92"))),
		},
		func(msg *pb1.Hello, msgInfo *message.MessageInfo, attr *pb.RoleAttributes) {
			log.Logger.Debug(msg.GetHello())
		},
	)
	r.Enable()

	select {}
}
