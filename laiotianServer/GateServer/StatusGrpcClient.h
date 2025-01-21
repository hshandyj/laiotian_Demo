#pragma once
#include <grpcpp/grpcpp.h>
#include "message.grpc.pb.h"
#include "Singleton.h"
#include <condition_variable>
#include <queue>
using grpc::Channel;
using grpc::Status;
using grpc::ClientContext;
using message::GetChatServerReq;
using message::GetChatServerRsp;
using message::StatusService;

class StatusConPool 
{
public:
    StatusConPool(size_t poolSize, std::string host, std::string port);
    ~StatusConPool();
    std::unique_ptr<StatusService::Stub> getConnection();
    void returnConnection(std::unique_ptr<StatusService::Stub> context);
    void Close();
private:
    int poolSize_;
    std::string host_;
    std::string port_;
    int b_stop_;
    std::queue<std::unique_ptr<StatusService::Stub>> connections_;
    std::mutex mutex_;
    std::condition_variable cond_;

};

class StatusGrpcClient :public Singleton<StatusGrpcClient> 
{
	friend Singleton<StatusGrpcClient>;
public:

    ~StatusGrpcClient() {

    }
    GetChatServerRsp GetChatServer(int uid);

private:
    StatusGrpcClient();
    std::unique_ptr<StatusConPool> pool_;

};