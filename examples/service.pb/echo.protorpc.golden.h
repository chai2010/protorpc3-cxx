

class EchoService_Stub;

class EchoService : public ::google::protobuf::rpc::Service {
 protected:
  // This class should be treated as an abstract interface.
  inline EchoService() {};
 public:
  virtual ~EchoService();

  typedef EchoService_Stub Stub;

  static const ::google::protobuf::ServiceDescriptor* descriptor();

  virtual const ::google::protobuf::rpc::Error Echo(
    const ::service::EchoRequest* request,
    ::service::EchoResponse* response);
  virtual const ::google::protobuf::rpc::Error EchoTwice(
    const ::service::EchoRequest* request,
    ::service::EchoResponse* response);

  // implements Service ----------------------------------------------

  const ::google::protobuf::ServiceDescriptor* GetDescriptor();
  const ::google::protobuf::rpc::Error CallMethod(
    const ::google::protobuf::MethodDescriptor* method,
    const ::google::protobuf::Message* request,
    ::google::protobuf::Message* response);
  const ::google::protobuf::Message& GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const;
  const ::google::protobuf::Message& GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const;

 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(EchoService);
};

class EchoService_Stub : public EchoService {
 public:
  EchoService_Stub(::google::protobuf::rpc::Caller* client);
  EchoService_Stub(::google::protobuf::rpc::Caller* client, bool client_ownership);
  ~EchoService_Stub();

  // implements EchoService ------------------------------------------

  const ::google::protobuf::rpc::Error Echo(
    const ::service::EchoRequest* request,
    ::service::EchoResponse* response);
  const ::google::protobuf::rpc::Error EchoTwice(
    const ::service::EchoRequest* request,
    ::service::EchoResponse* response);

 private:
  ::google::protobuf::rpc::Caller* client_;
  bool owns_client_;
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(EchoService_Stub);
};
