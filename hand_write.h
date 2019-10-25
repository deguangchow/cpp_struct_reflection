///    Copyright (C) 2019 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    hand wirte to serialize json.
///
///    \author   deguangchow
///    \version  1.0
///    \2019/10/24

#pragma once
#ifndef HAND_WRITE_H
#define HAND_WRITE_H

void to_json(nlohmann::json &j, const SimpleStruct &value) {
    j["_bool"] = value.bool_;
    j["_int"] = value.int_;
    j["_double"] = value.double_;
    j["_string"] = value.string_;
    j["_optional"] = value.optional_;
}

void from_json(const nlohmann::json &j, SimpleStruct &value) {
    j.at("_bool").get_to(value.bool_);
    j.at("_int").get_to(value.int_);
    j.at("_double").get_to(value.double_);
    j.at("_string").get_to(value.string_);
    j.at("_bool").get_to(value.bool_);
    if (j.find("_optional") != j.end()) {
        j.at("_optional").get_to(value.optional_);
    }
}

void to_json(nlohmann::json &j, const NestedStruct &value) {
    j["_nested"] = value.nested_;
    j["_vector"] = value.vector_;
}

void from_json(const nlohmann::json &j, NestedStruct &value) {
    j.at("_nested").get_to(value.nested_);
    j.at("_vector").get_to(value.vector_);
}

void test_hand_write() {
    auto const &jsonFromText = nlohmann::json::parse(g_sJsonTextInput);
    auto &stNested = jsonFromText.get<NestedStruct>();
    stNested.nested_.string_ += " in nested struct";
    auto const &jsonFromData = nlohmann::json(stNested);
    auto const &sJsonTextOutput = jsonFromData.dump(2);
    std::cout << sJsonTextOutput << std::endl;
}

#endif  //HAND_WRITE_H
