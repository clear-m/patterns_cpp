#include <memory>
#include <iostream>

class Subject
{
public:
    virtual void request() = 0;
};

class RealSubject : public Subject
{
public:
    void request() override
    {
        std::cout << "RealSubject: Обработка запроса." << std::endl;
    }
};

class Proxy : public Subject
{
private:
    std::unique_ptr<RealSubject> realSubject_;
public:
    Proxy(std::unique_ptr<RealSubject> realSubject = nullptr) :
        realSubject_(std::move(realSubject))
    {
    }
    void request() override
    {
        if (!realSubject_)
        {
            realSubject_ = std::make_unique<RealSubject>();
        }
        std::cout << "Proxy: Передача запроса реальному объекту." << std::endl;
        realSubject_->request();
    }
};

int main(int argc, char **argv)
{
    Proxy proxy;
    proxy.request();
    return 0;
}
