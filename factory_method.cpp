#include <type_traits>
#include <memory>

// Абстрактная форма
class Shape
{
public:
    virtual void draw() = 0;
};

// Конкретная форма
class Circle : public Shape
{
public:
    void draw() override
    {
        // Реализация рисования круга
    }
};

class Square : public Shape
{
public:
    void draw() override
    {
        // Реализация рисования квадрата
    }
};

class ShapeFactory
{
public:
    virtual std::unique_ptr<Shape> createShape() = 0;
};

class CircleFactory : public ShapeFactory
{
public:
    std::unique_ptr<Shape> createShape() override
    {
        return std::make_unique<Circle>();
    }
};

// Клиентский код
int main(int argc, char **argv)
{
    auto circle_factory = std::make_unique<CircleFactory>();
    auto circle = circle_factory->createShape();
    circle->draw();
    
    return 0;
}
