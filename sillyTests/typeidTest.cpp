#include <typeinfo>
#include <iostream>

enum class Test: char{
    Value1=0,
    Value2,
    Value3
};

void f() {
    auto a  = Test::Value1;
    std::cout << typeid(a).name() << std::endl;
    std::cout << typeid(Test::Value1).name() << std::endl;
    std::cout << typeid(Test::Value2).name() << std::endl;
    std::cout << typeid(Test::Value3).name() << std::endl;
}

int main(int argc, char const *argv[])
{
    f();
    return 0;
}
