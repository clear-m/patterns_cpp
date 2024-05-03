#include <string>
#include <memory>
#include <algorithm>
#include <iostream>

// Требуемый интерфейс
class Target
{
public:
    virtual std::string Request() const = 0;
};

// Адаптируемый класс
class Adaptee
{
public:
    std::string SpecificRequest() const
    {
        return ".eetpadA eht fo roivaheb laicepS";
    }
};

// Wrapper (Адаптер)
class Wrapper : public Target
{
private:
    std::unique_ptr<Adaptee> adaptee_;
public:
    Wrapper(std::unique_ptr<Adaptee> adaptee) : adaptee_(std::move(adaptee)) {}
    std::string Request() const override
    {
        std::string to_reverse = this->adaptee_->SpecificRequest();
        std::reverse(to_reverse.begin(), to_reverse.end());
        return "Adapter: (TRANSLATED) " + to_reverse;
    }
};

int main(int argc, char **argv)
{
    Wrapper wrapper(std::make_unique<Adaptee>());
    std::cout << wrapper.Request() << std::endl;
    return 0;
}
