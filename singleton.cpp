#include <cassert>

template <typename T>
class Singleton final
{
public:
    static T& getInstance()
    {
        static T instance;
        return instance;
    }

    // do not copy
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton) = delete;

    // do not move
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

    // do not create or delete
    Singleton() = delete;
    ~Singleton() = delete;
};

int main(int argc, char **argv)
{
    const int& instance = Singleton<int>::getInstance();
    assert(instance == 0);
    assert(&Singleton<int>::getInstance() == &Singleton<int>::getInstance());
    return 0;
}
