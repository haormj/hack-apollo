module github.com/haormj/test

go 1.21.0

replace github.com/haormj/cyber => /home/haormj/project/github.com/haormj/cyber

require (
	github.com/haormj/cyber v0.0.0-00010101000000-000000000000
	github.com/spf13/cast v1.6.0
	google.golang.org/protobuf v1.34.2
)

require (
	github.com/google/uuid v1.6.0 // indirect
	golang.org/x/sys v0.22.0 // indirect
)
