

struct minLetters{
    static const char *configStr = "config.password.minletters";
    using native_type = unsigned int;
    using serialization_type = std::string;
};

template <typename Attr>
constexpr char *getConfigStr(){
    return Attr::configStr;
}

void f() {
    
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
