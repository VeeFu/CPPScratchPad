#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <utility>
#include <optional>
#include <typeinfo>

#include "DataSource.h"

namespace InputValidation {

    struct InputData{

    };

    struct Validation{

    };

};


using InputNameValue = std::pair <std::string, std::string>;
void f() {

};


// platonic ideal

DataSource ds({
    {"first_name",  "vince"},
    {"last_name",   "drake"},
    {"birth_state", "California"},
    {"birth_date",  "02-15-1977"},
    {"siblings",    "7"},
    {"gender",      "m"}
});

template <typename T>
struct InputField{
    using data_type = T;
    std::string name;
    T data;
};

template <typename T, typename StringType>
struct Validators{
    struct OneOf{
        static auto OneOf(auto &strCollection){
            return [&strCollection](const &StringType str){
                auto res = std::find_if(
                    std::cbegin(strCollection), 
                    std::cend(strCollection), 
                    str);
                return res != strCollection.cend();
            };
        }
    };
};

template <typename T>
struct ValidatedInputField : public InputField<T>{

};


void controlHandler(const DataSource &ds){
    
    // have to validate the datasource
    // some names are required
    // others are not and have a default
    // still others have an acceptable range
/*
    dataValidation genderValidation("gender")
        .required(onMissing(default("M")))
        .valueConstraint(compareInsensitive(anyOf{"m","f"}));
    
        
    .hasValidator(
        .hasDefault("Timmy")
        .isRequired()
        .maxLength(100);
*/
}



















