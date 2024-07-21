package main

import (
	"log"
	"os"
	"time"

	"github.com/haormj/cyber/common"
	pb2 "github.com/haormj/cyber/pb"
	"github.com/haormj/cyber/transport"
	"github.com/haormj/test/pb"
	"github.com/spf13/cast"
	"google.golang.org/protobuf/encoding/prototext"
	"google.golang.org/protobuf/proto"
)

func main() {
	b, err := prototext.Marshal(common.GlobalDataInstance.Config())
	if err != nil {
		log.Fatalln(err)
	}

	log.Println(string(b))
	t, err := transport.NewTransport[*pb.Hello]().CreateTransmitter(&pb2.RoleAttributes{
		HostName:    proto.String("jetson"),
		HostIp:      proto.String("127.0.0.1"),
		ProcessId:   proto.Int32(int32(os.Getpid())),
		NodeName:    proto.String("test02"),
		NodeId:      proto.Uint64(common.Hash([]byte("test02"))),
		ChannelName: proto.String("/test/hello10"),
		ChannelId:   proto.Uint64(common.Hash([]byte("/test/hello10"))),
		Id:          proto.Uint64(common.Hash([]byte("192.168.50.92"))),
	}, pb2.OptionalMode_SHM.Enum())
	if err != nil {
		log.Fatalln(err)
	}

	i := 0
	for {
		r := t.Transmit(&pb.Hello{
			Hello: proto.String(cast.ToString(i)),
		})
		log.Println(r, i)
		i++
		time.Sleep(time.Second)
	}
}
