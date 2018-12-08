#include <string>

enum class Color
{
    RED = 0,
    ORANGE,
    YELLOW,
    GREEN,
    PURPLE,
    BLUE
};


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
