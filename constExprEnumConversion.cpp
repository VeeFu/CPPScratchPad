#include <utility>
#include <vector>
#include <array>
#include <iostream>

enum class EnumClass : unsigned int{
    val0 = 0,
    val1,
    val2,
    val3,
    val4,
    val5,
    LAST
};

int f(){
    constexpr size_t arraySize = 7U;
    using classStringPair = std::pair<EnumClass, const char*>;
    using classStringContainer = std::array<classStringPair, arraySize>;

    constexpr classStringContainer csc {
        std::make_pair(EnumClass::val0, "val0"),
        std::make_pair(EnumClass::val1, "val1"),
        std::make_pair(EnumClass::val2, "val2"),
        std::make_pair(EnumClass::val3, "val3"),
        std::make_pair(EnumClass::val4, "val4"),
        std::make_pair(EnumClass::val5, "val5"),
        std::make_pair(EnumClass::LAST, "LAST")
        };
    static_assert(csc.size() == arraySize);
    static_assert(csc[0].first == EnumClass::val0);
    static_assert(csc.back().first == EnumClass::LAST, "missing enum value in ClassStringContainer");
    return 0;
}

int main(int argc, char const *argv[])
{
    f();
    return 0;
}
