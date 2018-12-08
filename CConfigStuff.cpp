
// config system
/*
each option should:
    * have unique a compiler-aware symbol
    * should have a unique string associated
    * should have a runtime value of some type
    * should have a default value
    * should bave a natural language description

configuration should be:
    * serializable
    * setable with the compiler symbol
*/
#include <map>
#include <vector>
#include <string>
#include <functional>

#include <cassert>

enum class ConfigTag : unsigned;

//template <ConfigTag>
struct CConfigDefinition
{
    using tag = ConfigTag;
    //using value_type = dataType;
    ConfigTag const defnTag;
    std::string const name;
    std::string const description;
    std::string currentValue;
    std::string const defaultValue;

    CConfigDefinition(
        ConfigTag _tag,
        std::string _name,
        std::string _desc,
        std::string _curr,
        std::string _def) : defnTag(_tag),
                            name(_name),
                            description(_desc),
                            currentValue(_curr),
                            defaultValue(_def)
    {
    }
};

struct ConfigContainer
{
  private:
    using storage_type = std::map<ConfigTag, CConfigDefinition>;
    using index_type = std::map<std::string const, storage_type::iterator>;

    static storage_type configStorage;
    static index_type configStringIndex;

  public:
    static void insertDefinition(CConfigDefinition &&newDef)
    {
        auto [insertedConfigItem, bStorageInserted] =
            configStorage.insert({newDef.defnTag, std::move(newDef)});

        auto [insertedIndexItem, bIndexInserted] =
            configStringIndex.insert({insertedConfigItem->second.name, insertedConfigItem});
    }

    static void insertDefinition(std::initializer_list<CConfigDefinition> initList)
    {
        for (auto &initItem : initList)
        {
            auto [insertedConfigItem, bStorageInserted] =
                configStorage.insert({initItem.defnTag, initItem});
            auto [insertedIndexItem, bIndexInserted] =
                configStringIndex.insert({insertedConfigItem->second.name, insertedConfigItem});
        }
    }
    //    static void addDefinitions()
};

ConfigContainer::storage_type ConfigContainer::configStorage{};
ConfigContainer::index_type ConfigContainer::configStringIndex{};

struct ConfigNamespace
{
};

enum class ConfigTag : unsigned
{
    FIRST_THING = 0,
    SECOND_THING,
    THIRD_THING
};

int main(int argc, char const *argv[])
{
    ConfigContainer::insertDefinition(
        {ConfigTag::FIRST_THING, "first.thing", "This is the first thing", "", "First Default"});
    // ideally want compile time error
    // during ConfigDefinition creation
    ConfigContainer::insertDefinition({
        {ConfigTag::FIRST_THING, "first.thing", "This is the first thing", "", "First Default"},
        {ConfigTag::SECOND_THING, "second.thing", "This is the second thing", "", "Second Default"},
    });

    return 0;
}

/*
CConfigDefinition<ConfigTag::FIRST_THING, int>
    FirstConfigValue{"config.first", "The first config value", "FIRSTCURRENT", "FIRSTDEFAULT"};
*/
/*
class IConfiguration
{
    bool addConfigOption(optionTag, configDefinition);
    bool setConfigOption(optionTag, value);
    value getConfigOption(optionTag);
    configDefinition findConfigOption(optionName);
};
*/
