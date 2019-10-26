///    Copyright (C) 2019 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    简单的C++结构体字段反射.
///     https://cloud.tencent.com/developer/article/1522545
///    \author   deguangchow
///    \version  1.0
///    \2019/10/24

#include "stdafx.h"
#include "hand_write.h"
#include "dynamic_iostream.h"
#if 0
#include "static_iostream.h"
#else
#include "json_data.h"
#endif

int main() {
#if 0
    test_hand_write();

    test_dynamic_reflection();

    test_static_reflection();
    test_static_reflection_json_nested();
	test_static_reflection_json_item1();
	test_static_reflection_json_item2();
#endif

	test_static_reflection_json_item2();

    return 0;
}

