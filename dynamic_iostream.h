///    Copyright (C) 2019 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    dynamic_iostream
///
///    \author   deguangchow
///    \version  1.0
///    \2019/10/24

#pragma once
#ifndef DYNAMIC_IOSTREAM_H
#define DYNAMIC_IOSTREAM_H

#include "dynamic_reflection.h"

void test_dynamic_reflection() {
    auto bool_converter = [](bool *field, const std::string &name) {
        std::cout << std::boolalpha << name << " : " << *field << std::endl;
    };
    auto int_converter = [](int *field, const std::string &name) {
        std::cout << name << " : " << *field << std::endl;
    };
    auto double_converter = [](double *field, const std::string &name) {
        std::cout << std::fixed << name << " : " << *field << std::endl;
    };
    auto string_converter = [](std::string *field, const std::string &name) {
        std::cout << name << " : " << *field << std::endl;
    };

    StructValueConverter<SimpleStruct> converter;
    converter.RegisterField(&SimpleStruct::bool_, "bool", ValueConverter<bool>(bool_converter));
    converter.RegisterField(&SimpleStruct::int_, "int", ValueConverter<int>(int_converter));
    converter.RegisterField(&SimpleStruct::double_, "double", ValueConverter<double>(double_converter));
    converter.RegisterField(&SimpleStruct::string_, "string", ValueConverter<std::string>(string_converter));

    SimpleStruct simple{ true, 2, 2.0, "hello dynamic reflection" };
    converter(&simple);
}

#endif  //DYNAMIC_IOSTREAM_H
