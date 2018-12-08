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
class ColorDef
{
    using colorTag = Color;

    ColorDef() = delete;
    ColorDef(ColorDef const &) = delete;
    ColorDef &operator=(ColorDef const &) = delete;
    ~ColorDef() = delete;

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

#define COLORDEF(a,b,c) template <> ColorDescription ColorDef<Color::a>::desc = {#a, b, c}

COLORDEF(YELLOW, "The color of a ripe banana.",    "A primary color.");
COLORDEF(RED,    "The color of a ripe strawberry", "primary color");
COLORDEF(GREEN,  "The color of a ripe cucumber",   "primary color");
COLORDEF(ORANGE, "The color of a ripe strawberry", "combination of red and yellow");

#undef COLORDEF

#include <iostream>
void test()
{
    std::cout << ColorDef<Color::RED>::getName() << std::endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
