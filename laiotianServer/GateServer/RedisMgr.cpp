#include "RedisMgr.h"
#include "ConfigMgr.h"
RedisMgr::RedisMgr()
{
    auto gCfgMgr = ConfigMgr::Inst();
    auto host = gCfgMgr["Redis"]["Host"];
    auto port = gCfgMgr["Redis"]["Port"];
    auto pwd = gCfgMgr["Redis"]["Passwd"];
    con_pool_.reset(new RedisConPool(5,host.c_str(),atoi(port.c_str()),pwd.c_str()));
}
RedisMgr::~RedisMgr()
{

}


bool RedisMgr::Get(const std::string& key, std::string& value)
{
    auto connect = con_pool_->getConnection();
    if (connect == nullptr) {
        return false;
    }

    auto reply = (redisReply*)redisCommand(connect, "GET %s", key.c_str());
    if (reply == NULL) {
        std::cout << "[ GET  " << key << " ] failed" << std::endl;
        freeReplyObject(reply);
        con_pool_->returnConnection(connect);
        return false;
    }

    if (reply->type != REDIS_REPLY_STRING) {
        std::cout << "[ GET  " << key << " ] failed" << std::endl;
        freeReplyObject(reply);
        con_pool_->returnConnection(connect);
        return false;
    }

    value = reply->str;
    freeReplyObject(reply);
    std::cout << "Succeed to execute command [ GET " << key << "  ]" << std::endl;
    con_pool_->returnConnection(connect);
    return true;
}

bool RedisMgr::Set(const std::string& key, const std::string& value) {
    //执行redis命令行
    auto connect = con_pool_->getConnection();
    if (connect == nullptr) {
        return false;
    }

    auto reply = (redisReply*)redisCommand(connect, "SET %s %s", key.c_str(), value.c_str());

    //如果返回NULL则说明执行失败
    if (NULL == reply)
    {
        std::cout << "Execut command [ SET " << key << "  " << value << " ] failure ! " << std::endl;
        freeReplyObject(reply);
        con_pool_->returnConnection(connect);
        return false;
    }

    //如果执行失败则释放连接
    if (!(reply->type == REDIS_REPLY_STATUS && (strcmp(reply->str, "OK") == 0 || strcmp(reply->str, "ok") == 0)))
    {
        std::cout << "Execut command [ SET " << key << "  " << value << " ] failure ! " << std::endl;
        freeReplyObject(reply);
        con_pool_->returnConnection(connect);
        return false;
    }

    //执行成功 释放redisCommand执行后返回的redisReply所占用的内存
    freeReplyObject(reply);
    std::cout << "Execut command [ SET " << key << "  " << value << " ] success ! " << std::endl;
    con_pool_->returnConnection(connect);
    return true;
}

bool RedisMgr::Auth(const std::string& password)
{
    auto connect = con_pool_->getConnection();
    if (connect == nullptr) {
        return false;
    }
    auto reply = (redisReply*)redisCommand(connect, "AUTH %s", password.c_str());
    if (reply->type == REDIS_REPLY_ERROR) {
        std::cout << "authentication failed" << std::endl;
        //执行成功 释放redisCommand执行后返回的redisReply所占用的内存
        freeReplyObject(reply);
        con_pool_->returnConnection(connect);
        return false;
    }
    else {
        //执行成功 释放redisCommand执行后返回的redisReply所占用的内存
        freeReplyObject(reply);
        std::cout << "authentication success" << std::endl;
        con_pool_->returnConnection(connect);
        return true;
    }
}

bool RedisMgr::LPush(const std::string& key, const std::string& value)
{
    auto connect = con_pool_->getConnection();
    if (connect == nullptr) {
        return false;
    }
    auto reply = (redisReply*)redisCommand(connect, "LPUSH %s %s", key.c_str(), value.c_str());
    if (NULL == reply)
    {
        std::cout << "Execut command [ LPUSH " << key << "  " << value << " ] failure ! " << std::endl;
        freeReplyObject(reply);
        con_pool_->returnConnection(connect);
        return false;
    }

    if (reply->type != REDIS_REPLY_INTEGER || reply->integer <= 0) {
        std::cout << "Execut command [ LPUSH " << key << "  " << value << " ] failure ! " << std::endl;
        freeReplyObject(reply);
        con_pool_->returnConnection(connect);
        return false;
    }

    std::cout << "Execut command [ LPUSH " << key << "  " << value << " ] success ! " << std::endl;
    freeReplyObject(reply);
    con_pool_->returnConnection(connect);
    return true;
}

bool RedisMgr::LPop(const std::string& key, std::string& value) {
    auto connect = con_pool_->getConnection();
    if (connect == nullptr) {
        return false;
    }
    auto reply = (redisReply*)redisCommand(connect, "LPOP %s ", key.c_str());
    if (reply == nullptr || reply->type == REDIS_REPLY_NIL) {
        std::cout << "Execut command [ LPOP " << key << " ] failure ! " << std::endl;
        freeReplyObject(reply);
        con_pool_->returnConnection(connect);
        return false;
    }
    value = reply->str;
    std::cout << "Execut command [ LPOP " << key << " ] success ! " << std::endl;
    freeReplyObject(reply);
    con_pool_->returnConnection(connect);
    return true;
}

bool RedisMgr::RPush(const std::string& key, const std::string& value) {
    auto connect = con_pool_->getConnection();
    if (connect == nullptr) {
        return false;
    }
    auto reply = (redisReply*)redisCommand(connect, "RPUSH %s %s", key.c_str(), value.c_str());
    if (NULL == reply)
    {
        std::cout << "Execut command [ RPUSH " << key << "  " << value << " ] failure ! " << std::endl;
        freeReplyObject(reply);
        con_pool_->returnConnection(connect);
        return false;
    }

    if (reply->type != REDIS_REPLY_INTEGER || reply->integer <= 0) {
        std::cout << "Execut command [ RPUSH " << key << "  " << value << " ] failure ! " << std::endl;
        freeReplyObject(reply);
        con_pool_->returnConnection(connect);
        return false;
    }

    std::cout << "Execut command [ RPUSH " << key << "  " << value << " ] success ! " << std::endl;
    freeReplyObject(reply);
    con_pool_->returnConnection(connect);
    return true;
}

bool RedisMgr::RPop(const std::string& key, std::string& value) {
    auto connect = con_pool_->getConnection();
    if (connect == nullptr) {
        return false;
    }
    auto reply = (redisReply*)redisCommand(connect, "RPOP %s ", key.c_str());
    if (reply == nullptr || reply->type == REDIS_REPLY_NIL) {
        std::cout << "Execut command [ RPOP " << key << " ] failure ! " << std::endl;
        freeReplyObject(reply);
        con_pool_->returnConnection(connect);
        return false;
    }
    value = reply->str;
    std::cout << "Execut command [ RPOP " << key << " ] success ! " << std::endl;
    freeReplyObject(reply);
    con_pool_->returnConnection(connect);
    return true;
}

bool RedisMgr::HSet(const std::string& key, const std::string& hkey, const std::string& value) {
    auto connect = con_pool_->getConnection();
    if (connect == nullptr) {
        return false;
    }
    auto reply = (redisReply*)redisCommand(connect, "HSET %s %s %s", key.c_str(), hkey.c_str(), value.c_str());
    if (reply == nullptr || reply->type != REDIS_REPLY_INTEGER) {
        std::cout << "Execut command [ HSet " << key << "  " << hkey << "  " << value << " ] failure ! " << std::endl;
        freeReplyObject(reply);
        con_pool_->returnConnection(connect);
        return false;
    }
    std::cout << "Execut command [ HSet " << key << "  " << hkey << "  " << value << " ] success ! " << std::endl;
    freeReplyObject(reply);
    con_pool_->returnConnection(connect);
    return true;
}


bool RedisMgr::HSet(const char* key, const char* hkey, const char* hvalue, size_t hvaluelen)
{
    auto connect = con_pool_->getConnection();
    if (connect == nullptr) {
        return false;
    }
    const char* argv[4];
    size_t argvlen[4];
    argv[0] = "HSET";
    argvlen[0] = 4;
    argv[1] = key;
    argvlen[1] = strlen(key);
    argv[2] = hkey;
    argvlen[2] = strlen(hkey);
    argv[3] = hvalue;
    argvlen[3] = hvaluelen;
    
    auto reply = (redisReply*)redisCommandArgv(connect, 4, argv, argvlen);
    if (reply == nullptr || reply->type != REDIS_REPLY_INTEGER) {
        std::cout << "Execut command [ HSet " << key << "  " << hkey << "  " << hvalue << " ] failure ! " << std::endl;
        freeReplyObject(reply);
        con_pool_->returnConnection(connect);
        return false;
    }
    std::cout << "Execut command [ HSet " << key << "  " << hkey << "  " << hvalue << " ] success ! " << std::endl;
    freeReplyObject(reply);
    con_pool_->returnConnection(connect);
    return true;
}


std::string RedisMgr::HGet(const std::string& key, const std::string& hkey)
{
    auto connect = con_pool_->getConnection();
    if (connect == nullptr) {
        return "";
    }
    const char* argv[3];
    size_t argvlen[3];
    argv[0] = "HGET";
    argvlen[0] = 4;
    argv[1] = key.c_str();
    argvlen[1] = key.length();
    argv[2] = hkey.c_str();
    argvlen[2] = hkey.length();
    auto reply = (redisReply*)redisCommandArgv(connect, 3, argv, argvlen);
    if (reply == nullptr || reply->type == REDIS_REPLY_NIL) {
        freeReplyObject(reply);
        con_pool_->returnConnection(connect);
        std::cout << "Execut command [ HGet " << key << " " << hkey << "  ] failure ! " << std::endl;
        return "";
    }

    std::string value = reply->str;
    freeReplyObject(reply);
    con_pool_->returnConnection(connect);
    std::cout << "Execut command [ HGet " << key << " " << hkey << " ] success ! " << std::endl;
    return value;
}


bool RedisMgr::Del(const std::string& key)
{
    auto connect = con_pool_->getConnection();
    if (connect == nullptr) {
        return false;
    }
    auto reply = (redisReply*)redisCommand(connect, "DEL %s", key.c_str());
    if (reply == nullptr || reply->type != REDIS_REPLY_INTEGER) {
        std::cout << "Execut command [ Del " << key << " ] failure ! " << std::endl;
        freeReplyObject(reply);
        con_pool_->returnConnection(connect);
        return false;
    }
    std::cout << "Execut command [ Del " << key << " ] success ! " << std::endl;
    freeReplyObject(reply);
    con_pool_->returnConnection(connect);
    return true;
}

bool RedisMgr::ExistsKey(const std::string& key)
{
    auto connect = con_pool_->getConnection();
    if (connect == nullptr) {
        return false;
    }
    auto reply = (redisReply*)redisCommand(connect, "exists %s", key.c_str());
    if (reply == nullptr || reply->type != REDIS_REPLY_INTEGER || reply->integer == 0) {
        std::cout << "Not Found [ Key " << key << " ]  ! " << std::endl;
        freeReplyObject(reply);
        con_pool_->returnConnection(connect);
        return false;
    }
    std::cout << " Found [ Key " << key << " ] exists ! " << std::endl;
    freeReplyObject(reply);
    con_pool_->returnConnection(connect);
    return true;
}

void RedisMgr::Close()
{
    con_pool_->close();
    con_pool_->ClearConnections();
}

RedisConPool::RedisConPool(size_t poolSize, const char* host, int port, const char* pwd)
    : poolSize_(poolSize), host_(host), port_(port), b_stop_(false), pwd_(pwd), counter_(0) {
    for (size_t i = 0; i < poolSize_; ++i) {
        auto* context = redisConnect(host, port);
        if (context == nullptr || context->err != 0) {
            if (context != nullptr) {
                redisFree(context);
            }
            continue;
        }

        auto reply = (redisReply*)redisCommand(context, "AUTH %s", pwd);
        if (reply->type == REDIS_REPLY_ERROR) {
            std::cout << "Auth failed" << std::endl;
            //执行成功 释放redisCommand执行后返回的redisReply所占用的内存
            freeReplyObject(reply);
            continue;
        }

        //执行成功 释放redisCommand执行后返回的redisReply所占用的内存
        freeReplyObject(reply);
        std::cout << "Auth success" << std::endl;
        connections_.push(context);
    }

    check_thread_ = std::thread([this]() {
        while (!b_stop_) {
            counter_++;
            if (counter_ >= 60) {
                checkThread();
                counter_ = 0;
            }

            std::this_thread::sleep_for(std::chrono::seconds(1)); // 每隔 30 秒发送一次 PING 命令
        }
        });

}

RedisConPool::~RedisConPool()
{
}

void RedisConPool::ClearConnections()
{
    std::lock_guard<std::mutex> lock(mutex_);
    while (!connections_.empty()) {
        auto* context = connections_.front();
        redisFree(context);
        connections_.pop();
    }
}

void RedisConPool::close()
{
    b_stop_ = true;
    cond_.notify_all();
    check_thread_.join();
}

redisContext* RedisConPool::getConnection()
{
    std::unique_lock<std::mutex> lock(mutex_);
    cond_.wait(lock, [this]() {
        if (b_stop_) {
            return true;
        }
        return !connections_.empty();
        });
    if (b_stop_) {
        return nullptr;
    }
    auto* connect = connections_.front();
    connections_.pop();
    return connect;
}

void RedisConPool::returnConnection(redisContext* connect)
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (b_stop_) {
        return;
    }
    connections_.push(connect);
    cond_.notify_one();
}

void RedisConPool::checkThread()
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (b_stop_) {
        return;
    }
    auto pool_size = connections_.size();
    for (int i = 0; i < pool_size && !b_stop_; i++) {
        auto* context = connections_.front();
        connections_.pop();
        try {
            auto reply = (redisReply*)redisCommand(context, "PING");
            if (!reply) {
                std::cout << "redis ping failed" << std::endl;
                connections_.push(context);
                continue;
            }
            freeReplyObject(reply);
            connections_.push(context);
        }
        catch (std::exception& exp) {
            std::cout << "Error keeping connection alive: " << exp.what() << std::endl;
            redisFree(context);
            context = redisConnect(host_, port_);
            if (context == nullptr || context->err != 0) {
                if (context != nullptr) {
                    redisFree(context);
                }
                continue;
            }

            auto reply = (redisReply*)redisCommand(context, "AUTH %s", pwd_);
            if (reply->type == REDIS_REPLY_ERROR) {
                std::cout << "Auth failed" << std::endl;
                //执行成功 释放redisCommand执行后返回的redisReply所占用的内存
                freeReplyObject(reply);
                continue;
            }
            std::cout << "Auth success" << std::endl;
            //执行成功 释放redisCommand执行后返回的redisReply所占用的内存
            freeReplyObject(reply);
            connections_.push(context);
        }
    }
}
