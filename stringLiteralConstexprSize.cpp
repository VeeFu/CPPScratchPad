#include <iterator>
#include <array>
// #include <c++/8/experimental/array>

static_assert(std::size("abc") == 4);

std::size_t constexpr length(const char* str)
{
    return *str ? 1 + length(str + 1) : std::size_t{0};
}

void f(){
    constexpr char testStr[] = "abc";
    static_assert(std::size(testStr) == 4);
    static_assert(length(testStr) == 3);
}

void g(){

    constexpr const char* strArray1[4] = {
        "red",
        "blue",
        "green",
        "orange"
    };
    constexpr const std::size_t sizeArray1[4] = {
        3UL,
        5UL,
        6UL,
        7UL
    };

    static_assert(std::size(strArray1) == std::size(sizeArray1));
    static_assert(length(strArray1[0]) == sizeArray1[0]);

    auto colorArray1 = std::experimental::make_array("RED");
    std::array<const char *, 1UL> colorArray2 ={"RED"};
    static_assert(std::size(colorArray1) == 1);
    static_assert(std::size(colorArray2) == 1);

    //std::array<char const [], 1> const colorArray1 {"RED"};

}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
