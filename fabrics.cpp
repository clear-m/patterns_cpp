#include <string>
#include <memory>

namespace fabric
{
    class Product
    {
    public:
        virtual void operation() const = 0;
    };

    class ConcreteProduct1 : public Product
    {
    public:
        void operation() const override
        {
            // Реализация операции для ConcreteProduct1
        }
    };

    class ConcreteProduct2 : public Product
    {
    public:
        void operation() const override
        {
            // Реализация операции для ConcreteProduct2
        }
    };

    class Fabric
    {
    public:
        static std::unique_ptr<Product> createProduct(const std::string &type)
        {
            if (type == "Product1")
            {
                return std::make_unique<ConcreteProduct1>();
            }
            else if (type == "Product2")
            {
                return std::make_unique<ConcreteProduct2>();
            }
            else
            {
                return nullptr;
            }
        }
    };
}

namespace abstract_fabric
{
    class AbstractProductA
    {
    public:
        virtual void operationA() const = 0;
    };

    class ConcreteProductA1 : public AbstractProductA
    {
    public:
        void operationA() const override
        {
            // Реализация операции для ConcreteProductA1
        }
    };

    class ConcreteProductA2 : public AbstractProductA
    {
    public:
        void operationA() const override
        {
            // Реализация операции для ConcreteProductA2
        }
    };

    class AbstractProductB
    {
    public:
        virtual void operationB() const = 0;
    };

    class ConcreteProductB1 : public AbstractProductB
    {
    public:
        void operationB() const override
        {
            // Реализация операции для ConcreteProductB1
        }
    };

    class ConcreteProductB2 : public AbstractProductB
    {
    public:
        void operationB() const override
        {
            // Реализация операции для ConcreteProductB2
        }
    };

    class AbstractFactory
    {
    public:
        virtual std::unique_ptr<AbstractProductA> createProductA() const = 0;
        virtual std::unique_ptr<AbstractProductB> createProductB() const = 0;
    };

    class ConcreteFactory1 : public AbstractFactory
    {
    public:
        std::unique_ptr<AbstractProductA> createProductA() const override
        {
            return std::make_unique<ConcreteProductA1>();
        }

        std::unique_ptr<AbstractProductB> createProductB() const override
        {
            return std::make_unique<ConcreteProductB1>();
        }
    };

    class ConcreteFactory2 : public AbstractFactory
    {
    public:
        std::unique_ptr<AbstractProductA> createProductA() const override
        {
            return std::make_unique<ConcreteProductA2>();
        }

        std::unique_ptr<AbstractProductB> createProductB() const override
        {
            return std::make_unique<ConcreteProductB2>();
        }
    };
}

int main(int argc, char **argv)
{
    {
        using namespace fabric;
        std::unique_ptr<Product> product1{Fabric::createProduct("Product1")};
        std::unique_ptr<Product> product2{Fabric::createProduct("Product2")};

        product1->operation();
        product2->operation();
    }
    {
        using namespace abstract_fabric;

        std::unique_ptr<AbstractFactory> factory1 = std::make_unique<ConcreteFactory1>();
        std::unique_ptr<AbstractProductA> productA1{factory1->createProductA()};
        std::unique_ptr<AbstractProductB> productB1{factory1->createProductB()};

        productA1->operationA();
        productB1->operationB();

        std::unique_ptr<AbstractFactory> factory2 = std::make_unique<ConcreteFactory2>();
        std::unique_ptr<AbstractProductA> productA2{factory2->createProductA()};
        std::unique_ptr<AbstractProductB> productB2{factory2->createProductB()};

        productA2->operationA();
        productB2->operationB();
    }

    return 0;
}