#include <utility>
#include <array>
#include <tuple>

enum class configTag : unsigned int{
    Setting1 = 0,
    Setting2,
    Setting3,
};

    using configDef = std::tuple<configTag, const char*, const char*>;

    template <int size>
    using configDefArray = std::array<configDef, size>;

constexpr bool InitializeConfigDefinitions (){
    configDefArray<3> configs {
    // constexpr std::array<configDef, 3> configs
        std::make_tuple(configTag::Setting1, "Setting1", "Setting1 Description"),
        std::make_tuple(configTag::Setting1, "Setting2", "Setting2 Description"),
        std::make_tuple(configTag::Setting1, "Setting3", "Setting3 Description")
    };
    return true;
};

constexpr bool f(){

    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
