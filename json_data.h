///    Copyright (C) 2019 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    json_data
///
///    \author   deguangchow
///    \version  1.0
///    \2019/10/26

#pragma once
#ifndef JSON_DATA_H
#define JSON_DATA_H

#include "reflection_json.h"

DEFINE_STRUCT_SCHEMA(SimpleStruct,
    DEFINE_STRUCT_FIELD(bool_, "_bool"),
    DEFINE_STRUCT_FIELD(int_, "_int"),
    DEFINE_STRUCT_FIELD(double_, "_double"),
    DEFINE_STRUCT_FIELD(string_, "_string"),
    DEFINE_STRUCT_FIELD(optional_, "_optional"));

DEFINE_STRUCT_SCHEMA(NestedStruct,
    DEFINE_STRUCT_FIELD(nested_, "_nested"),
    DEFINE_STRUCT_FIELD(vector_, "_vector"));

void test_static_reflection_json_nested() {
    auto const &jsonFromText = nlohmann::json::parse(g_sJsonTextInput);
    auto const &stNested = jsonFromText.get<NestedStruct>();
    auto const &jsonFromData = nlohmann::json(stNested);
    auto const &sJsonTextOutput = jsonFromData.dump(2);
    std::cout << sJsonTextOutput << std::endl;
}

DEFINE_STRUCT_SCHEMA(Property,
    DEFINE_STRUCT_FIELD(sCode, "_code"),
    DEFINE_STRUCT_FIELD(sName, "_name"),
    DEFINE_STRUCT_FIELD(sUnit, "_unit"),
    DEFINE_STRUCT_FIELD(uCatagory, "_catagory"),
    DEFINE_STRUCT_FIELD(dAmount, "_amount"),
    DEFINE_STRUCT_FIELD(dPrice, "_price"),
    DEFINE_STRUCT_FIELD(dSummary, "_summary"));

DEFINE_STRUCT_SCHEMA(Item,
    DEFINE_STRUCT_FIELD(stProperty, "_property"),
    DEFINE_STRUCT_FIELD(vctChild, "_child"));

void test_static_reflection_json_item1() {
    auto const &jsonFromInput = nlohmann::json::parse(g_sJsonItem);
    auto const &stItem = jsonFromInput.get<Item>();
    auto const &jsonFromData = nlohmann::json(stItem);
    auto const &sJsonTextOutput = jsonFromData.dump(2);
    std::cout << sJsonTextOutput << std::endl;
}

void test_static_reflection_json_item2() {
    auto const &stItem = Item{
        { "010101001", "ping zheng chang di", "m2", 6, 2, 3, 6 },
        {
            { "1-1", "wa tu", "m2", 7, 10, 1.5, 15 },
            { "2-1", "tu shi fang", "gong ri", 7, 3.5, 2, 7 }
        }
    };
    auto const &jsonFromData = nlohmann::json(stItem);
    auto const &sJsonTextOutput = jsonFromData.dump(2);
    std::cout << sJsonTextOutput << std::endl;
}

#endif  //JSON_DATA_H
