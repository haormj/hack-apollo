package main

import (
	"os"

	"github.com/haormj/cyber/common"
	"github.com/haormj/cyber/log"
	"github.com/haormj/cyber/pb"
	"github.com/haormj/cyber/transport"
	"github.com/haormj/cyber/transport/message"
	pb1 "github.com/haormj/test/pb"
	"google.golang.org/protobuf/proto"
)

func main() {
	_, err := transport.CreateReceiver[*pb1.Hello](&pb.RoleAttributes{
		HostName:    proto.String("jetson"),
		HostIp:      proto.String("192.168.50.92"),
		ProcessId:   proto.Int32(int32(os.Getpid())),
		NodeName:    proto.String("test02"),
		NodeId:      proto.Uint64(common.Hash([]byte("test02"))),
		ChannelName: proto.String("/test/hello1"),
		ChannelId:   proto.Uint64(common.Hash([]byte("/test/hello1"))),
		Id:          proto.Uint64(common.Hash([]byte("192.168.50.92"))),
	},
		pb.OptionalMode_SHM,
		func(msg *pb1.Hello, msgInfo *message.MessageInfo, attr *pb.RoleAttributes) {
			log.Logger.Debug(msg.GetHello())
		})
	if err != nil {
		panic(err)
	}

	select {}
}
