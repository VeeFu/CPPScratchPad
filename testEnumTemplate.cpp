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
    static desc_type desc;
    ColorDef() = delete;
    ColorDef(ColorDef const &) = delete;
    ColorDef &operator=(ColorDef const &) = delete;
    ~ColorDef() = delete;

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
ColorDescription ColorDef<Color::RED>::desc = {"RED", "The color of a ripe strawberry", "primary color"};
template <>
ColorDescription ColorDef<Color::GREEN>::desc = {"GREEN", "The color of a ripe cucumber", "primary color"};
template <>
ColorDescription ColorDef<Color::ORANGE>::desc = {"ORANGE", "The color of a ripe strawberry", "combination of red and yellow"};

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
