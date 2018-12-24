/*

    ConfigEnum : value used for accessing definition and setting runtime values

    ConfigDefinition : class type used to store definition values, such as name, description, and default values

    ConfigAccess : used for accessing values of the defintion

    ConfigRuntime : accesing runtime values of configuration settings?

*/

template <typename configEnum>
struct ConfigDefintion{
    using tag_type = configEnum;

};


template <typename config_enum> 
class ConfigClass {
    public:
    using enum_type = config_enum;
};