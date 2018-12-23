#define CATCH_CONFIG_MAIN
#include "single_include/catch2/catch.hpp"
#include "DataSource.h"
#include <string>

template < typename T> 
void printOptional(const std::optional<T> &optValue) {
    std::cout << "got an optional containing : ";
    if (optValue){
        std::cout << *optValue << '\n';
    } else {
        std::cout << "nothing" << '\n';
    }
}

DataSource ds({
    {"first_name",  "vince"},
    {"last_name",   "drake"},
    {"birth_state", "California"},
    {"birth_date",  "02-15-1977"},
    {"siblings",    "7"},
    {"gender",      "m"}
});

TEST_CASE("Datasource cannot convert \"m\" into float"){
    REQUIRE( ds.get<float>("gender").has_value() == false );
}

TEST_CASE("Datsource can read a single char value"){
    REQUIRE( ds.get<char>("gender").has_value() == true);
}
TEST_CASE("Datasource can read the single string from 'gender'"){
    auto genderVal = ds.get<std::string>("gender");
    std::string genderStr (*genderVal);
    REQUIRE( genderStr == "m");
}