#include <string>
#include <memory>
#include <iostream>

// Интерфейс стратегии
class Strategy
{
public:
    virtual void do_algorithm(const std::string &data) const = 0;
};

// Конкретные стратегии
class ConcreteStrategyA : public Strategy
{
public:
    void do_algorithm(const std::string &data) const
    {
        std::cout << "Result ConcreteStrategyA: " << data << std::endl;
    }
};

class ConcreteStrategyB : public Strategy
{
public:
    void do_algorithm(const std::string &data) const
    {
        std::cout << "Result ConcreteStrategyB: " << data << std::endl;
    }
};

// Констекст
class Context
{
private:
    std::unique_ptr<Strategy> strategy_;

public:
    Context(std::unique_ptr<Strategy> strategy) : strategy_(std::move(strategy)){};
    ~Context()
    {
    }

    void set_strategy(std::unique_ptr<Strategy> strategy)
    {
        strategy_ = std::move(strategy);
    }

    void do_some_business_logic() const
    {
        strategy_->do_algorithm("Some data");
    }
};

int main(int argc, char **argv)
{
    auto context = std::make_unique<Context>(std::make_unique<ConcreteStrategyA>());
    context->do_some_business_logic();

    context->set_strategy(std::make_unique<ConcreteStrategyB>());
    context->do_some_business_logic();

    return 0;
}
