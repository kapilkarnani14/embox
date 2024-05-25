/**
 * Autogenerated by Thrift Compiler (0.13.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef HelloSvc_H
#define HelloSvc_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "hello_types.h"



#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class HelloSvcIf {
 public:
  virtual ~HelloSvcIf() {}
  virtual void hello_func(std::string& _return) = 0;
  virtual void hello_func2(const std::string& var1, const int64_t var2) = 0;
  virtual void hello_func3(const std::string& var1, const Hello_struct& struct1, const MyInteger var3) = 0;
};

class HelloSvcIfFactory {
 public:
  typedef HelloSvcIf Handler;

  virtual ~HelloSvcIfFactory() {}

  virtual HelloSvcIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(HelloSvcIf* /* handler */) = 0;
};

class HelloSvcIfSingletonFactory : virtual public HelloSvcIfFactory {
 public:
  HelloSvcIfSingletonFactory(const ::std::shared_ptr<HelloSvcIf>& iface) : iface_(iface) {}
  virtual ~HelloSvcIfSingletonFactory() {}

  virtual HelloSvcIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(HelloSvcIf* /* handler */) {}

 protected:
  ::std::shared_ptr<HelloSvcIf> iface_;
};

class HelloSvcNull : virtual public HelloSvcIf {
 public:
  virtual ~HelloSvcNull() {}
  void hello_func(std::string& /* _return */) {
    return;
  }
  void hello_func2(const std::string& /* var1 */, const int64_t /* var2 */) {
    return;
  }
  void hello_func3(const std::string& /* var1 */, const Hello_struct& /* struct1 */, const MyInteger /* var3 */) {
    return;
  }
};


class HelloSvc_hello_func_args {
 public:

  HelloSvc_hello_func_args(const HelloSvc_hello_func_args&);
  HelloSvc_hello_func_args& operator=(const HelloSvc_hello_func_args&);
  HelloSvc_hello_func_args() {
  }

  virtual ~HelloSvc_hello_func_args() noexcept;

  bool operator == (const HelloSvc_hello_func_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const HelloSvc_hello_func_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const HelloSvc_hello_func_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class HelloSvc_hello_func_pargs {
 public:


  virtual ~HelloSvc_hello_func_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _HelloSvc_hello_func_result__isset {
  _HelloSvc_hello_func_result__isset() : success(false) {}
  bool success :1;
} _HelloSvc_hello_func_result__isset;

class HelloSvc_hello_func_result {
 public:

  HelloSvc_hello_func_result(const HelloSvc_hello_func_result&);
  HelloSvc_hello_func_result& operator=(const HelloSvc_hello_func_result&);
  HelloSvc_hello_func_result() : success() {
  }

  virtual ~HelloSvc_hello_func_result() noexcept;
  std::string success;

  _HelloSvc_hello_func_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const HelloSvc_hello_func_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const HelloSvc_hello_func_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const HelloSvc_hello_func_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _HelloSvc_hello_func_presult__isset {
  _HelloSvc_hello_func_presult__isset() : success(false) {}
  bool success :1;
} _HelloSvc_hello_func_presult__isset;

class HelloSvc_hello_func_presult {
 public:


  virtual ~HelloSvc_hello_func_presult() noexcept;
  std::string* success;

  _HelloSvc_hello_func_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _HelloSvc_hello_func2_args__isset {
  _HelloSvc_hello_func2_args__isset() : var1(false), var2(false) {}
  bool var1 :1;
  bool var2 :1;
} _HelloSvc_hello_func2_args__isset;

class HelloSvc_hello_func2_args {
 public:

  HelloSvc_hello_func2_args(const HelloSvc_hello_func2_args&);
  HelloSvc_hello_func2_args& operator=(const HelloSvc_hello_func2_args&);
  HelloSvc_hello_func2_args() : var1(), var2(0) {
  }

  virtual ~HelloSvc_hello_func2_args() noexcept;
  std::string var1;
  int64_t var2;

  _HelloSvc_hello_func2_args__isset __isset;

  void __set_var1(const std::string& val);

  void __set_var2(const int64_t val);

  bool operator == (const HelloSvc_hello_func2_args & rhs) const
  {
    if (!(var1 == rhs.var1))
      return false;
    if (!(var2 == rhs.var2))
      return false;
    return true;
  }
  bool operator != (const HelloSvc_hello_func2_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const HelloSvc_hello_func2_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class HelloSvc_hello_func2_pargs {
 public:


  virtual ~HelloSvc_hello_func2_pargs() noexcept;
  const std::string* var1;
  const int64_t* var2;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class HelloSvc_hello_func2_result {
 public:

  HelloSvc_hello_func2_result(const HelloSvc_hello_func2_result&);
  HelloSvc_hello_func2_result& operator=(const HelloSvc_hello_func2_result&);
  HelloSvc_hello_func2_result() {
  }

  virtual ~HelloSvc_hello_func2_result() noexcept;

  bool operator == (const HelloSvc_hello_func2_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const HelloSvc_hello_func2_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const HelloSvc_hello_func2_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class HelloSvc_hello_func2_presult {
 public:


  virtual ~HelloSvc_hello_func2_presult() noexcept;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _HelloSvc_hello_func3_args__isset {
  _HelloSvc_hello_func3_args__isset() : var1(false), struct1(false), var3(false) {}
  bool var1 :1;
  bool struct1 :1;
  bool var3 :1;
} _HelloSvc_hello_func3_args__isset;

class HelloSvc_hello_func3_args {
 public:

  HelloSvc_hello_func3_args(const HelloSvc_hello_func3_args&);
  HelloSvc_hello_func3_args& operator=(const HelloSvc_hello_func3_args&);
  HelloSvc_hello_func3_args() : var1(), var3(0) {
  }

  virtual ~HelloSvc_hello_func3_args() noexcept;
  std::string var1;
  Hello_struct struct1;
  MyInteger var3;

  _HelloSvc_hello_func3_args__isset __isset;

  void __set_var1(const std::string& val);

  void __set_struct1(const Hello_struct& val);

  void __set_var3(const MyInteger val);

  bool operator == (const HelloSvc_hello_func3_args & rhs) const
  {
    if (!(var1 == rhs.var1))
      return false;
    if (!(struct1 == rhs.struct1))
      return false;
    if (!(var3 == rhs.var3))
      return false;
    return true;
  }
  bool operator != (const HelloSvc_hello_func3_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const HelloSvc_hello_func3_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class HelloSvc_hello_func3_pargs {
 public:


  virtual ~HelloSvc_hello_func3_pargs() noexcept;
  const std::string* var1;
  const Hello_struct* struct1;
  const MyInteger* var3;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

class HelloSvcClient : virtual public HelloSvcIf {
 public:
  HelloSvcClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  HelloSvcClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void hello_func(std::string& _return);
  void send_hello_func();
  void recv_hello_func(std::string& _return);
  void hello_func2(const std::string& var1, const int64_t var2);
  void send_hello_func2(const std::string& var1, const int64_t var2);
  void recv_hello_func2();
  void hello_func3(const std::string& var1, const Hello_struct& struct1, const MyInteger var3);
  void send_hello_func3(const std::string& var1, const Hello_struct& struct1, const MyInteger var3);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class HelloSvcProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<HelloSvcIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (HelloSvcProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_hello_func(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_hello_func2(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_hello_func3(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  HelloSvcProcessor(::std::shared_ptr<HelloSvcIf> iface) :
    iface_(iface) {
    processMap_["hello_func"] = &HelloSvcProcessor::process_hello_func;
    processMap_["hello_func2"] = &HelloSvcProcessor::process_hello_func2;
    processMap_["hello_func3"] = &HelloSvcProcessor::process_hello_func3;
  }

  virtual ~HelloSvcProcessor() {}
};

class HelloSvcProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  HelloSvcProcessorFactory(const ::std::shared_ptr< HelloSvcIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< HelloSvcIfFactory > handlerFactory_;
};

class HelloSvcMultiface : virtual public HelloSvcIf {
 public:
  HelloSvcMultiface(std::vector<std::shared_ptr<HelloSvcIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~HelloSvcMultiface() {}
 protected:
  std::vector<std::shared_ptr<HelloSvcIf> > ifaces_;
  HelloSvcMultiface() {}
  void add(::std::shared_ptr<HelloSvcIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void hello_func(std::string& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->hello_func(_return);
    }
    ifaces_[i]->hello_func(_return);
    return;
  }

  void hello_func2(const std::string& var1, const int64_t var2) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->hello_func2(var1, var2);
    }
    ifaces_[i]->hello_func2(var1, var2);
  }

  void hello_func3(const std::string& var1, const Hello_struct& struct1, const MyInteger var3) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->hello_func3(var1, struct1, var3);
    }
    ifaces_[i]->hello_func3(var1, struct1, var3);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class HelloSvcConcurrentClient : virtual public HelloSvcIf {
 public:
  HelloSvcConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  HelloSvcConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void hello_func(std::string& _return);
  int32_t send_hello_func();
  void recv_hello_func(std::string& _return, const int32_t seqid);
  void hello_func2(const std::string& var1, const int64_t var2);
  int32_t send_hello_func2(const std::string& var1, const int64_t var2);
  void recv_hello_func2(const int32_t seqid);
  void hello_func3(const std::string& var1, const Hello_struct& struct1, const MyInteger var3);
  void send_hello_func3(const std::string& var1, const Hello_struct& struct1, const MyInteger var3);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif



#endif
