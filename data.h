///    Copyright (C) 2019 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    SimpleStruct
///
///    \author   deguangchow
///    \version  1.0
///    \2019/10/24

#pragma once
#ifndef DATA_H
#define DATA_H

struct SimpleStruct {
    bool                    bool_;
    int                     int_;
    double                  double_;
    std::string             string_;
    std::unique_ptr<bool>   optional_;
};

struct NestedStruct {
    SimpleStruct                nested_;
    std::vector<SimpleStruct>   vector_;
};

static auto const &g_sJsonTextInput = "{"
"  \"_nested\": {"
"    \"_bool\": false,"
"    \"_int\": 0,"
"    \"_double\": 0,"
"    \"_string\": \"foo\""
"  },"
"  \"_vector\": [{"
"    \"_bool\": true,"
"    \"_int\": 1,"
"    \"_double\": 1,"
"    \"_string\": \"bar\","
"    \"_optional\": true"
"  },{"
"    \"_bool\": true,"
"    \"_int\": 2,"
"    \"_double\": 2.0,"
"    \"_string\": \"baz\","
"    \"_optional\": false"
"  }]"
"}";

#endif  //DATA_H
