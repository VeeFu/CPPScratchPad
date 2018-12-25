#include <charconv>
#include <iostream>
#include <utility>
#include <tuple>
#include <string>
#include <cstdlib>

int main(int argc, char const *argv[])
{
    std::wstring testwstr {L"-20"};
    char charBytes[32];
    auto result = std::wcstombs(charBytes, testwstr.c_str(), 32);
    if (result == static_cast<std::size_t>(-1)) {
        std::cout << "Big error during string conversion. You don't know what you're doing." << '\n';
    };
    std::string teststr(charBytes);
    auto testVals = std::make_tuple(0, 0U);
    auto fromStringChars = [](const auto &teststr, auto &out){
        return std::from_chars(
            teststr.c_str(), 
            teststr.c_str() + teststr.size(), 
            out);
    };

    auto [ptr1, err1] = fromStringChars(teststr, std::get<int>(testVals));
    if (err1 == std::errc()){
        std::cout << "value : " << std::get<int>(testVals);
    } else {
        std::cout << "Error";
    }

    std::cout << std::endl;

    auto [ptr2, err2] = fromStringChars(teststr, std::get<unsigned>(testVals));

    if (err2 == std::errc()){
        std::cout << "value : " << std::get<int>(testVals);
    } else {
        std::cout << "Error";
    }

    std::cout << std::endl;

    return 0;
}
