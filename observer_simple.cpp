#include <memory>
#include <vector>
#include <iostream>

class Observer
{
public:
    virtual void update() = 0;
};

class Subject
{
private:
    std::vector<std::shared_ptr<Observer>> observers;

public:
    void addObserver(const std::shared_ptr<Observer> & observer)
    {
        observers.push_back(observer);
    }
    void notifyObservers()
    {
        // perform notification
        std::cout << "notifying!" << std::endl;
        for (auto& observer : observers)
        {
            observer->update();
        }
    }
};

class ConcreteObserver : public Observer
{
public:
    void update() override
    {
        // been notified from subject here
        std::cout << "notified!" << std::endl;
    }
};


int main(int argc, char **argv)
{
    Subject subject;
    
    std::shared_ptr<Observer> observer_one{ new ConcreteObserver() };
    std::shared_ptr<Observer> observer_two{ new ConcreteObserver() };
    std::shared_ptr<Observer> observer_three{ new ConcreteObserver() };

    subject.addObserver(observer_one);
    subject.addObserver(observer_two);
    subject.addObserver(observer_three);

    subject.notifyObservers();

    return 0;
}
