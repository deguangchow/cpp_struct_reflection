///    Copyright (C) 2019 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    reflection_json
///
///    \author   deguangchow
///    \version  1.0
///    \2019/10/25

#pragma once
#ifndef REFELCTION_JSON_H
#define REFELCTION_JSON_H

#include "static_reflection.h"

//namespace {

template<typename T>
struct is_optional : std::false_type {};

template<typename T>
struct is_optional<std::unique_ptr<T>> : std::true_type {};

template<typename T>
constexpr bool is_optional_v = is_optional<std::decay_t<T>>::value;

template<typename T>
constexpr bool has_schema = std::tuple_size<decltype(StructSchema<T>())>::value;

//}//namespace

namespace nlohmann {

template<typename T>
struct adl_serializer<T, std::enable_if_t<::has_schema<T>>> {
    template<typename BasicJsonType>
    static void to_json(BasicJsonType &j, const T &value) {
        ForEachField(value, [&j](auto &&field, auto &&name) {
            j[name] = field;
        });
    }

    template<typename BasicJsonType>
    static void from_json(const BasicJsonType &j, T &value) {
        ForEachField(value, [&j](auto &&field, auto &&name) {
            // ignore missing field of optional
            if (::is_optional_v<decltype(field)> && j.find(name) == j.end()) {
                return;
            }

            j.at(name).get_to(field);
        });
    }
};

}//namespace nlohmann

DEFINE_STRUCT_SCHEMA(SimpleStruct,
    DEFINE_STRUCT_FIELD(bool_, "_bool"),
    DEFINE_STRUCT_FIELD(int_, "_int"),
    DEFINE_STRUCT_FIELD(double_, "_double"),
    DEFINE_STRUCT_FIELD(string_, "_string"),
    DEFINE_STRUCT_FIELD(optional_, "_optional"));

DEFINE_STRUCT_SCHEMA(NestedStruct,
    DEFINE_STRUCT_FIELD(nested_, "_nested"),
    DEFINE_STRUCT_FIELD(vector_, "_vector"));

void test_static_reflection_json() {
    auto const &jsonFromText = nlohmann::json::parse(g_sJsonTextInput);
    auto const &stNested = jsonFromText.get<NestedStruct>();
    auto const &jsonFromData = nlohmann::json(stNested);
    auto const &sJsonTextOutput = jsonFromData.dump(2);
    std::cout << sJsonTextOutput << std::endl;
}

#endif  //REFELCTION_JSON_H
