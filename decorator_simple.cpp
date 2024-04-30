#include <memory>
#include <string>
#include <iostream>

// Базовый интерфейс компонента
class Component
{
public:
    virtual std::string Operation() const = 0;
};

// Конкретная реализация компонента
class ConcreteComponent : public Component
{
public:
    std::string Operation() const override
    {
        return "ConcreteComponent";
    }
};

// Базовый класс декаратора
class Decorator : public Component
{
protected:
    std::shared_ptr<Component> component_;

public:
    Decorator(const std::shared_ptr<Component>& component) : component_(component) {}
    
    std::string Operation() const override
    {
        return component_->Operation();
    }
};

// Конкретный декаратор
class ConcreteDecoratorA : public Decorator
{
public:
    ConcreteDecoratorA(const std::shared_ptr<Component>& component) : Decorator(component) {}
    
    std::string Operation() const override
    {
        return "ConcreteDecoratorA(" + Decorator::Operation() + ")";
    }
};

// Конкретный декоратор
class ConcreteDecoratorB : public Decorator 
{
public:
    ConcreteDecoratorB(const std::shared_ptr<Component>& component) : Decorator(component) {}
    
    std::string Operation() const override
    {
        return "ConcreteDecoratorB(" + Decorator::Operation() + ")";
    }
};

int main(int argc, char **argv)
{
    // Создаем базовый компонент
    std::shared_ptr<Component> component{ new ConcreteComponent() };
    std::cout << "Client: I get a simple component:\n";
    std::cout << component->Operation() << "\n\n";

    // Обертываем компонент в декораторы
    std::shared_ptr<Component> decorator_one{ new ConcreteDecoratorA(component) };
    std::shared_ptr<Component> decorator_two{ new ConcreteDecoratorB(decorator_one) };

    std::cout << "Client: Now I've got a decorated component:\n";
    std::cout << decorator_two->Operation() << "\n";

    return 0;
}