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


struct ConfigStrings{
    static constexpr size_t arraySize = 7U;
    using classStringPair = std::pair<const EnumClass, const char*>;
    using classStringContainer = const std::array<classStringPair, arraySize>;
    static constexpr classStringContainer csc {
        std::pair{EnumClass::val0, "val0"},
        std::pair{EnumClass::val1, "val1"},
        std::pair{EnumClass::val2, "val2"},
        std::pair{EnumClass::val3, "val3"},
        std::pair{EnumClass::val4, "val4"},
        std::pair{EnumClass::val5, "val5"},
        std::pair{EnumClass::LAST, "LAST"},
        };
    static_assert(csc.size() == arraySize);
    static_assert(csc.size() == csc.max_size());
    static_assert(csc[0].first == EnumClass::val0);
    static_assert(csc.back().first == EnumClass::LAST, "missing enum value in ClassStringContainer");
    static constexpr int f(){
        unsigned i = 1;
        for (;i < csc.size(); ++i){
            static_assert(
                (unsigned)csc[i].first
                //1 == static_cast<unsigned>(csc[i].first) - static_cast<unsigned>(csc[i-1].first)
            );
        }
        
    }
};

int main(int argc, char const *argv[])
{
    ConfigStrings::f();

    return 0;
}
