// Code generated by protoc-gen-go.
// source: echo.proto
// DO NOT EDIT!

package service

import proto "github.com/golang/protobuf/proto"
import fmt "fmt"
import math "math"

import "io"
import "log"
import "net"
import "net/rpc"
import "time"
import protorpc "github.com/chai2010/protorpc"

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

type Message struct {
	Msg string `protobuf:"bytes,1,opt,name=msg" json:"msg,omitempty"`
}

func (m *Message) Reset()         { *m = Message{} }
func (m *Message) String() string { return proto.CompactTextString(m) }
func (*Message) ProtoMessage()    {}

type EchoRequest struct {
	Msg string `protobuf:"bytes,1,opt,name=msg" json:"msg,omitempty"`
}

func (m *EchoRequest) Reset()         { *m = EchoRequest{} }
func (m *EchoRequest) String() string { return proto.CompactTextString(m) }
func (*EchoRequest) ProtoMessage()    {}

type EchoResponse struct {
	Msg string `protobuf:"bytes,1,opt,name=msg" json:"msg,omitempty"`
}

func (m *EchoResponse) Reset()         { *m = EchoResponse{} }
func (m *EchoResponse) String() string { return proto.CompactTextString(m) }
func (*EchoResponse) ProtoMessage()    {}

type EchoService interface {
	Echo(in *EchoRequest, out *EchoResponse) error
	EchoTwice(in *EchoRequest, out *EchoResponse) error
}

// AcceptEchoServiceClient accepts connections on the listener and serves requests
// for each incoming connection.  Accept blocks; the caller typically
// invokes it in a go statement.
func AcceptEchoServiceClient(lis net.Listener, x EchoService) {
	srv := rpc.NewServer()
	if err := srv.RegisterName("EchoService", x); err != nil {
		log.Fatal(err)
	}

	for {
		conn, err := lis.Accept()
		if err != nil {
			log.Fatalf("lis.Accept(): %v\n", err)
		}
		go srv.ServeCodec(protorpc.NewServerCodec(conn))
	}
}

// RegisterEchoService publish the given EchoService implementation on the server.
func RegisterEchoService(srv *rpc.Server, x EchoService) error {
	if err := srv.RegisterName("EchoService", x); err != nil {
		return err
	}
	return nil
}

// NewEchoServiceServer returns a new EchoService Server.
func NewEchoServiceServer(x EchoService) *rpc.Server {
	srv := rpc.NewServer()
	if err := srv.RegisterName("EchoService", x); err != nil {
		log.Fatal(err)
	}
	return srv
}

// ListenAndServeEchoService listen announces on the local network address laddr
// and serves the given EchoService implementation.
func ListenAndServeEchoService(network, addr string, x EchoService) error {
	lis, err := net.Listen(network, addr)
	if err != nil {
		return err
	}
	defer lis.Close()

	srv := rpc.NewServer()
	if err := srv.RegisterName("EchoService", x); err != nil {
		return err
	}

	for {
		conn, err := lis.Accept()
		if err != nil {
			log.Fatalf("lis.Accept(): %v\n", err)
		}
		go srv.ServeCodec(protorpc.NewServerCodec(conn))
	}
}

type EchoServiceClient struct {
	*rpc.Client
}

// NewEchoServiceClient returns a EchoService stub to handle
// requests to the set of EchoService at the other end of the connection.
func NewEchoServiceClient(conn io.ReadWriteCloser) *EchoServiceClient {
	c := rpc.NewClientWithCodec(protorpc.NewClientCodec(conn))
	return &EchoServiceClient{c}
}

func (c *EchoServiceClient) Echo(in *EchoRequest) (out *EchoResponse, err error) {
	if in == nil {
		in = new(EchoRequest)
	}
	out = new(EchoResponse)
	if err = c.Call("EchoService.Echo", in, out); err != nil {
		return nil, err
	}
	return out, nil
}
func (c *EchoServiceClient) EchoTwice(in *EchoRequest) (out *EchoResponse, err error) {
	if in == nil {
		in = new(EchoRequest)
	}
	out = new(EchoResponse)
	if err = c.Call("EchoService.EchoTwice", in, out); err != nil {
		return nil, err
	}
	return out, nil
}

// DialEchoService connects to an EchoService at the specified network address.
func DialEchoService(network, addr string) (*EchoServiceClient, error) {
	c, err := protorpc.Dial(network, addr)
	if err != nil {
		return nil, err
	}
	return &EchoServiceClient{c}, nil
}

// DialEchoServiceTimeout connects to an EchoService at the specified network address.
func DialEchoServiceTimeout(network, addr string, timeout time.Duration) (*EchoServiceClient, error) {
	c, err := protorpc.DialTimeout(network, addr, timeout)
	if err != nil {
		return nil, err
	}
	return &EchoServiceClient{c}, nil
}

type EchoService2 interface {
	Echo(in *EchoRequest, out *EchoResponse) error
	EchoTwice(in *EchoRequest, out *EchoResponse) error
	Foo(in *Message, out *Message) error
}

// AcceptEchoService2Client accepts connections on the listener and serves requests
// for each incoming connection.  Accept blocks; the caller typically
// invokes it in a go statement.
func AcceptEchoService2Client(lis net.Listener, x EchoService2) {
	srv := rpc.NewServer()
	if err := srv.RegisterName("EchoService2", x); err != nil {
		log.Fatal(err)
	}

	for {
		conn, err := lis.Accept()
		if err != nil {
			log.Fatalf("lis.Accept(): %v\n", err)
		}
		go srv.ServeCodec(protorpc.NewServerCodec(conn))
	}
}

// RegisterEchoService2 publish the given EchoService2 implementation on the server.
func RegisterEchoService2(srv *rpc.Server, x EchoService2) error {
	if err := srv.RegisterName("EchoService2", x); err != nil {
		return err
	}
	return nil
}

// NewEchoService2Server returns a new EchoService2 Server.
func NewEchoService2Server(x EchoService2) *rpc.Server {
	srv := rpc.NewServer()
	if err := srv.RegisterName("EchoService2", x); err != nil {
		log.Fatal(err)
	}
	return srv
}

// ListenAndServeEchoService2 listen announces on the local network address laddr
// and serves the given EchoService2 implementation.
func ListenAndServeEchoService2(network, addr string, x EchoService2) error {
	lis, err := net.Listen(network, addr)
	if err != nil {
		return err
	}
	defer lis.Close()

	srv := rpc.NewServer()
	if err := srv.RegisterName("EchoService2", x); err != nil {
		return err
	}

	for {
		conn, err := lis.Accept()
		if err != nil {
			log.Fatalf("lis.Accept(): %v\n", err)
		}
		go srv.ServeCodec(protorpc.NewServerCodec(conn))
	}
}

type EchoService2Client struct {
	*rpc.Client
}

// NewEchoService2Client returns a EchoService2 stub to handle
// requests to the set of EchoService2 at the other end of the connection.
func NewEchoService2Client(conn io.ReadWriteCloser) *EchoService2Client {
	c := rpc.NewClientWithCodec(protorpc.NewClientCodec(conn))
	return &EchoService2Client{c}
}

func (c *EchoService2Client) Echo(in *EchoRequest) (out *EchoResponse, err error) {
	if in == nil {
		in = new(EchoRequest)
	}
	out = new(EchoResponse)
	if err = c.Call("EchoService2.Echo", in, out); err != nil {
		return nil, err
	}
	return out, nil
}
func (c *EchoService2Client) EchoTwice(in *EchoRequest) (out *EchoResponse, err error) {
	if in == nil {
		in = new(EchoRequest)
	}
	out = new(EchoResponse)
	if err = c.Call("EchoService2.EchoTwice", in, out); err != nil {
		return nil, err
	}
	return out, nil
}
func (c *EchoService2Client) Foo(in *Message) (out *Message, err error) {
	if in == nil {
		in = new(Message)
	}
	out = new(Message)
	if err = c.Call("EchoService2.Foo", in, out); err != nil {
		return nil, err
	}
	return out, nil
}

// DialEchoService2 connects to an EchoService2 at the specified network address.
func DialEchoService2(network, addr string) (*EchoService2Client, error) {
	c, err := protorpc.Dial(network, addr)
	if err != nil {
		return nil, err
	}
	return &EchoService2Client{c}, nil
}

// DialEchoService2Timeout connects to an EchoService2 at the specified network address.
func DialEchoService2Timeout(network, addr string, timeout time.Duration) (*EchoService2Client, error) {
	c, err := protorpc.DialTimeout(network, addr, timeout)
	if err != nil {
		return nil, err
	}
	return &EchoService2Client{c}, nil
}
