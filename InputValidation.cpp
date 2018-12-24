#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <utility>
#include <optional>
//#include <typeinfo>
#include <functional>

#include "DataSource.h"


template <typename T, typename StringType>
struct Validators{
    using StringList = std::vector<StringType>;
    using StringValidator = std::function<bool(const StringType&)>;
    using StringValidatorList = std::vector<StringValidator>;

    static auto OneOf(const StringList &strCollection)
    {
        return [&strCollection](const StringType &str)
        {
            auto res = std::find_if(
                std::cbegin(strCollection), 
                std::cend(strCollection), 
                str);
            return res != strCollection.cend();
        };
    }
};

template <typename T, typename StringType>
struct InputField{
    using data_type = T;
    using string_type = StringType;

    StringType name;
    StringType dataString;
    T dataNative;
};

template <typename T, typename StringType>
struct ValidatedInputField : public InputField<T, StringType>{
    using typename Validators<T, StringType>::StringValidatorList;
    using typename Validators<T, StringType>::StringValidator;

    StringValidatorList conditions;

    ValidatedInputField& addValidator(StringValidator &&v){
        conditions.emplace_back(v);
        return *this;
    }

    bool Validate(){
        bool result = true;
        for (auto v : conditions){
            result &= v(this->dataString);
        }
        return result;
    }
};

void test (){
    DataSource ds({
        {"first_name",  "vince"},
        {"last_name",   "drake"},
        {"birth_state", "California"},
        {"birth_date",  "02-15-1977"},
        {"siblings",    "7"},
        {"gender",      "m"}
    });
    ValidatedInputField<std::string, std::string> BirthState;

}


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
