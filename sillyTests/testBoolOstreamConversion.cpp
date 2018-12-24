#include <utility>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <array>

void testStringstreamBoolConversions(){
    std::vector<
        std::pair<
            bool, std::vector<std::string> 
        >
    > 
    testBoolTypes 
    {
        {
            true, {
                {"on"},
                {"1"},
                {"yes"},
                {"YES"},
                {"true"},
                {"TRUE"},
                {"affirmative"},
                {"AFFIRMATIVE"},
                {"confirm"},
                {"CONFIRM"},
            }
        },
        {
            false, {
                {"off"},
                {"0"},
                {"no"},
                {"NO"},
                {"false"},
                {"TRUE"},
                {"affirmative"},
                {"AFFIRMATIVE"},
                {"confirm"},
                {"CONFIRM"},
            }
        }
    };
    for (const auto& [expected, testset]: testBoolTypes ){
        for (const auto &test : testset){
            std::stringstream ss(test);
            //std::ios_base::fmtflags::_S_boolalpha;
            ss << std::setiosflags(std::ios_base::fmtflags::_S_boolalpha);
            bool actual{};
            ss >> actual;
            //std::cout << std::setiosflags(std::ios_base::boolalpha);
            if (!ss){
                std::cout << "Error : cannot convert to bool : " << test << '\n';
            } else if (actual == expected) {
                std::cout << "Success : " << test << " == " << expected << '\n';
            } else {
                std::cout << "Failure : " << test << " != " << expected << '\n';
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    testStringstreamBoolConversions();    
    return 0;
}

