#include <limits>
#include <cstdint>
#include <algorithm>
#include <cstring>
#include <iterator>

template <
    typename T = char, 
    typename sizeType = int, 
    std::size_t S = 4096
    >
class static_buffer{
    static_assert(S > 0, 
            "buffer size must be greater than zero");
    static_assert(S <= std::numeric_limits<sizeType>::max(), 
            "buffer size must not exceed max of sizeType");
private:
    T data[S] = {};

public:
    using size_type = sizeType;
    using value_type = T;

    constexpr sizeType size() const { return S;}
    constexpr operator T*(){return data;}
};

void changeBuffer(unsigned char *const buffer, const int bufferSize ){
    buffer[0] = 'a';
    buffer[1] = '\0';
}

void f()
{
    static_buffer<unsigned char, unsigned short> buff2;
    static_buffer<unsigned char, unsigned short, 4096> buff3;
    static_assert(
        std::is_same<decltype(std::size(buff3)), std::size_t >::value 
    );
    changeBuffer(buff2, std::size(buff2));

    unsigned char charbuffer[256] = {};
    static_assert(
        std::is_same<decltype(std::size(charbuffer)), std::size_t >::value 
    );
    changeBuffer(charbuffer, std::size(charbuffer));

}

int main(int argc, char const *argv[])
{
    f();
    return 0;
}
