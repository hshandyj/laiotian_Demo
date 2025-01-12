#ifndef SINGLETON_H
#define SINGLETON_H
#include "global.h"
template<typename T>
class Singleton{//单例模式父类，c++11写法
protected:
    Singleton()=default;
    Singleton(const Singleton<T>&)=delete;
    Singleton& operator = (const Singleton<T>& st) = delete;
    static std::shared_ptr<T> _instance;

public:
    static std::shared_ptr<T> GetInstance(){
        static std::once_flag s_flage;
        std::call_once(s_flage,[&](){
            _instance=std::shared_ptr<T>(new T);
        });
        return _instance;
    }
    void PrintAddress(){
        std::cout<<_instance.get()<<std::endl;
    }
    ~Singleton(){
        std::cout<<"this is singleton destruct"<<std::endl;
    }
};
template<typename T>
std::shared_ptr<T> Singleton<T>::_instance=nullptr;
#endif // SINGLETON_H
