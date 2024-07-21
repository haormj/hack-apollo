package main

import (
	"log"

	"github.com/haormj/cyber/common"
	"github.com/haormj/cyber/transport/message"
	"github.com/haormj/cyber/transport/shm"
	"github.com/haormj/test/pb"
	"google.golang.org/protobuf/proto"
)

func main() {
	segment := shm.NewSegment(common.Hash([]byte("/test/hello2")))
	channelID := common.Hash([]byte("/test/hello3"))

	for {
		var info shm.ReadableInfo
		if !shm.ConditionNotifierInstance.Listen(100, &info) {
			// slog.Debug("not find")
			continue
		}
		if info.ChannelID != channelID {
			continue
		}
		log.Println("ChannelID", info.ChannelID)

		readableBlock := shm.ReadableBlock{
			Index: info.BlockIndex,
		}

		if !segment.AcquireBlockToRead(&readableBlock) {
			log.Println("AcquireBlockToRead failed")
			continue
		}

		var hello pb.Hello
		if err := proto.Unmarshal(readableBlock.Buf[:readableBlock.Block.MsgSize], &hello); err != nil {
			log.Println("proto.Unmarshal error", "err", err)
			segment.ReleaseReadBlock(&readableBlock)
			continue
		}
		log.Println("message", "hello", hello.GetHello())
		log.Println("block", readableBlock.Block.MsgSize, readableBlock.Block.MsgInfoSize)

		msgInfo := message.NewMessageInfo()
		if !msgInfo.Deserialize(readableBlock.Buf[readableBlock.Block.MsgSize : readableBlock.Block.MsgSize+readableBlock.Block.MsgInfoSize]) {
			log.Println("msgInfo.Deserialize failed")
			segment.ReleaseReadBlock(&readableBlock)
			continue
		}
		log.Println("msgInfo", "channelID", msgInfo.ChannelID, "senderID", msgInfo.SenderID)

		segment.ReleaseReadBlock(&readableBlock)
	}
}
