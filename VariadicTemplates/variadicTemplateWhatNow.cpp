
#include <iostream>

// recursive case
template <typename T, typename... Rest>
constexpr double sum(T t, Rest... rest){
    return t + sum(rest...);
}

template <typename T>
void printToCout (T &&t){
    std::cout << t;
}

template <typename T, typename... Rest>
void printToCout (T t, Rest... rest){
    printToCout (t);
    std::cout << ", ";
    printToCout(rest...);
}

template <typename OStream, typename T>
OStream& streamInsert(OStream &os, T t){
    os << t;
    return os;
}

template <typename OStream, typename T, typename... All>
OStream& streamInsert(OStream &os, T t, All... all){
    streamInsert(os, t);
    streamInsert(os, ", ");
    streamInsert(os, all...);
    return os;
}

void f(){
    printToCout(1.2L, 1.6L, 7.3L, "asdf", "Hello", 123);
    std::cout << std::endl;
    streamInsert(std::cout, 1.2L, 1.6L, 7.3L, "asdf", "Hello", 123);
}

int main(int argc, char const *argv[])
{
    f();
    return 0;
}
