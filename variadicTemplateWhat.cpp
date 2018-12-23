#include <iostream>



// base case
template <typename T>
constexpr double sum(T t){
    return t;
}

// recursive case
template <typename T, typename... Rest>
constexpr double sum(T t, Rest... rest){
    return t + sum(rest...);
}


void f(){
    std::cout << sum(1.2L, 1.6L, 7.3L);
}

int main(int argc, char const *argv[])
{
    f();
    return 0;
}
