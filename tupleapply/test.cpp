#include <iostream>
#include <tuple>
#include <vector>
#include <utility>
#include <functional>

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

struct Foo{
    int m_thing = 10;
    void FooFunc(int i){
        std::cout << "FooFunc(" << i <<") : "<< (i*m_thing) << "\n";
    }
};

void g() {

    Foo foo;
    auto i = std::make_tuple(&Foo::FooFunc, foo, 10 );
    std::invoke(&Foo::FooFunc, foo, 10);
}

struct NamedMembers{
    static inline std::tuple<std::pair
};

int main(int argc, char const *argv[])
{
    g();
    f();
    return 0;
}
