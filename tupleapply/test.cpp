#include <iostream>
#include <tuple>
#include <vector>
#include <utility>

template <typename T>
void print_vec(std::vector<T> &v){
    std::cout << "vector encountered : ";
    for (auto & elem : v){
        std::cout << "[ " << elem << "] ";
    }
}
void f(){
    auto some_function = [](auto&& x) { 
        std::cout << x << std::endl;
    };
    auto the_tuple2 = std::make_tuple(
        std::vector<int>{1,2,3,4},
        std::vector<float>{1.1f, 1.2f, 1.3f}, 
        std::vector<char>{'a','b','c'}
        );
    auto the_tuple = std::make_tuple(1, 2.5f, 'a', "asdf");

    std::apply([&](auto& ...x){(..., some_function(x));}, the_tuple);
    std::apply([&](auto& ...x){(..., print_vec(x));}, the_tuple2);
}

int main(int argc, char const *argv[])
{
    f();
    return 0;
}
