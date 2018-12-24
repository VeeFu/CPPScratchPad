#include <string>
#include <array>
#include <iterator>

enum class Color
{
    RED = 0,
    ORANGE,
    YELLOW,
    GREEN,
    PURPLE,
    BLUE
};


constexpr bool compareStrings ( const char *first, const char *second)
{
    std::size_t firstLen = std::size(first);
    std::size_t secondLen = std::size(second);
    bool result = true;
    if (firstLen != secondLen){
        result = false;
    } else {
        std::size_t i = 0;
        while (i < firstLen && i < secondLen){
            result &= (first[i] == second[i]);
        }
    }
    return result;
}
void f() {
    compareStrings("RED", "RED");
    compareStrings("red", "RED");
    compareStrings("red1", "red");
}

// want to be able to write "RED"_c which yields the enum type Color::RED at compile-time
constexpr Color operator "" _color(const char *strColor, std::size_t strSize){
    
    std::array<char const [], 1> colorArray1 = {{"RED"}};

    std::array<char const [], 6> colorArray = {"RED","ORANGE","YELLOW","GREEN","PURPLE","BLUE"};
    std::array<Color const, 6>  colorEnumArray = {Color::RED, Color::ORANGE, Color::YELLOW, Color::GREEN, Color::PURPLE, Color::BLUE};

    static_assert(std::size(colorArray) == std::size(colorEnumArray));

    std::size_t arrayIndex = 0;
    while (arrayIndex < colorArray.size() ){
        if (compareStrings(strColor, colorArray[arrayIndex])){
            break;
        }
    }
    //static_assert(arrayIndex < sizeof(colorArray));
    return colorEnumArray[arrayIndex];
}
static_assert("RED"_color == Color::RED);
//static_assert("red"_color == Color::RED);
//static_assert("YELLOW"_color == Color::RED);


class ColorDescription
{
  public:
    std::string Name;
    std::string Description;
    std::string HelpText;
};


template <Color, typename desc_type = ColorDescription>
class ConfigDef
{
    using colorTag = Color;

    ConfigDef() = delete;
    ConfigDef(ConfigDef const &) = delete;
    ConfigDef &operator=(ConfigDef const &) = delete;
    ~ConfigDef() = delete;

    static desc_type desc;

  public:
    static auto getDescription()
    {
        return desc.Description;
    }
    static auto getHelpText()
    {
        return desc.HelpText;
    }
    static auto getName()
    {
        return desc.Name;
    }
};

template <> 
ColorDescription ConfigDef<Color::PURPLE>::desc = 
    {"PURPLE", "The color of a ripe eggplant.", "The combination of blue and red."};

#define COLORDEF(a,b,c) template <> ColorDescription ConfigDef<Color::a>::desc = {#a, b, c}

COLORDEF(RED,    "The color of a ripe strawberry", "primary color");
COLORDEF(ORANGE, "The color of a ripe strawberry", "combination of red and yellow");
COLORDEF(YELLOW, "The color of a ripe banana.",    "A primary color.");
COLORDEF(GREEN,  "The color of a ripe cucumber",   "primary color");

#undef COLORDEF

#include <iostream>
void test()
{
    std::cout << ConfigDef<Color::RED>::getName() << std::endl;
//    std::cout << ConfigDef<Color::BLUE>::getName() << std::endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
