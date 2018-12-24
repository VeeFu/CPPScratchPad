#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <utility>
#include <optional>
#include <typeinfo>

class DataSource {
public:
    using DataMap = std::vector<std::pair<std::string, std::string>>;

    DataMap m_data;

public:
    DataSource (DataMap&& dataIn){
        m_data = dataIn;
    }
    template <typename T>
    std::optional<T> get(const std::string &field_name){
        auto found = std::find_if(m_data.cbegin(), m_data.cend(), 
            [&field_name](const auto &entry){
                return field_name == entry.first;
            });
        if (found != m_data.cend()){
            std::stringstream ss(found->second);
            T temp{};
            if (ss >> temp){
                return temp;
            }
        }
        return {};
    }

    template <typename T>
    std::vector<std::optional<T>> getAll(const std::string &field_name){
        std::vector<std::optional<T>> temp;
        auto field_name_matches_key = [&field_name](const auto &entry){
            return field_name == entry.first;
        };

        auto found = std::find_if( m_data.cbegin(), m_data.cend(), field_name_matches_key);
        while (found != m_data.cend())
        {
            temp.emplace_back(*found);
            found = std::find_if( m_data.cbegin(), m_data.cend(), field_name_matches_key);
        }
        return temp;
    }
};