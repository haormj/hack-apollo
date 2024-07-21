package main

import (
	"log"
	"time"

	"github.com/haormj/cyber/transport/shm"
)

func main() {
	s := shm.NewXSISegment(0xf4db4759)
	if !s.OpenOnly() {
		log.Fatalln("open failed")
	}

	for {
		log.Println(s.State().Seq(), s.State().CeilingMsgSize())
		log.Println(len(s.Blocks()), s.Blocks()[0].MsgSize, s.Blocks()[0].MsgInfoSize)
		log.Println(len(s.BlockBufs()[0]))
		time.Sleep(time.Second)
	}
}
