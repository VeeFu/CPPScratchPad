#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <utility>
#include <optional>
#include <typeinfo>

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



















