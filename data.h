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

struct Property {
	std::string sCode;
	std::string sName;
	std::string sUnit;
	unsigned uCatagory;
	double dAmount;
	double dPrice;
	double dSummary;
};

struct Item {
	Property stProperty;
	std::vector<Item> vctChild;
};

static auto const &g_sJsonItem = "{"
"\"_child\": ["
"{"
"	\"_child\": [],"
"		\"_property\": {"
"		\"_amount\": 10.0,"
"		\"_catagory\": 7,"
"		\"_code\": \"1-1\","
"		\"_name\": \"wa tu\","
"		\"_price\": 1.5,"
"		\"_summary\": 15.0,"
"		\"_unit\": \"m2\""
"}"
"	},"
"	{"
"		\"_child\": [],"
"		\"_property\": {"
"		\"_amount\": 3.5,"
"		\"_catagory\": 7,"
"		\"_code\": \"2-1\","
"		\"_name\": \"tu shi fang\","
"		\"_price\": 2.0,"
"		\"_summary\": 7.0,"
"		\"_unit\": \"gong ri\""
"	}"
"	}"
" ],"
" \"_property\": {"
"	  \"_amount\": 2.0,"
"	  \"_catagory\": 6,"
"	  \"_code\": \"010101001\","
"	  \"_name\": \"ping zheng chang di\","
"	  \"_price\": 3.0,"
"	  \"_summary\": 6.0,"
"	  \"_unit\": \"m2\""
" }"
"}";
#endif  //DATA_H
