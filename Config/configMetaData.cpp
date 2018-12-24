
#include <iostream>

struct Data{
    int mA;
};

struct DataMemberA{
    using data_type = decltype(Data::mA);
    inline static const char * configLocation = "company.config.data.mA";
    static bool validator(const data_type &a) {
        return a > 0 && a < 3000;
    }
    inline static const data_type defaultValue = 50;
};

template <typename Class, typename Member>
struct MemberMetaStrings{ };
template <>
struct MemberMetaStrings<Data, int>{

};

template <typename Class, typename Member>
struct MetaMember{
    using data_type = decltype(Class::Member);
    inline static const char * configLocation = "company.config.data.mA";
    static bool validator(const data_type &a) {
        return a > 0 && a < 3000;
    }
    inline static const data_type defaultValue = 50;
};

void f(){
    Data d1{35};
}

int main(int argc, char const *argv[])
{
    f();
    return 0;
}
