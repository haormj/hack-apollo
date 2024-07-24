package main

import (
	"log"
	"time"

	"github.com/haormj/cyber/common"
	"github.com/haormj/cyber/pb"
	"github.com/haormj/cyber/transport"
	pb2 "github.com/haormj/test/pb"
	"github.com/spf13/cast"
	"google.golang.org/protobuf/proto"
)

func main() {
	transmitter, err := transport.CreateTransmitter[*pb2.Hello](
		&pb.RoleAttributes{
			HostName:    proto.String(common.GlobalDataInstance.HostName()),
			HostIp:      proto.String(common.GlobalDataInstance.HostIP()),
			ProcessId:   proto.Int32(int32(common.GlobalDataInstance.ProcessID())),
			NodeName:    proto.String("transmiter"),
			NodeId:      proto.Uint64(common.Hash([]byte("transmiter"))),
			ChannelName: proto.String("/test/hello"),
			ChannelId:   proto.Uint64(common.Hash([]byte("/test/hello"))),
		},
		pb.OptionalMode_SHM,
	)
	if err != nil {
		log.Fatalln(err)
	}

	i := 0
	for {
		if !transmitter.Transmit(&pb2.Hello{
			Hello: proto.String(cast.ToString(i)),
		}) {
			log.Println("transmit failed")
		}
		i++
		log.Println(i)
		time.Sleep(time.Second)
	}
}
