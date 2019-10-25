///    Copyright (C) 2019 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    stdafx.h
///
///    \author   deguangchow
///    \version  1.0
///    \2019/10/25

// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <functional>
#include <tuple>
#include <type_traits>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::function;

//third-part
#include "nlohmann\json.hpp"
#include "optional_json.h"
using nlohmann::json;


#include "data.h"

