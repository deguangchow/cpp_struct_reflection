///    Copyright (C) 2019 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    optional_json : 解析json可选字段
///
///    \author   deguangchow
///    \version  1.0
///    \2019/10/24

#pragma once
#ifndef OPTIONAL_JSION_H
#define OPTIONAL_JSION_H

namespace nlohmann {

template<typename T>
struct adl_serializer<std::unique_ptr<T>> {
    static void to_json(json &j, const std::unique_ptr<T> &opt) {
        j = opt ? json(*opt) : json(nullptr);
    }

    static void from_json(const json &j, std::unique_ptr<T> &opt) {
        opt = !j.is_null() ? std::make_unique<T>(j.get<T>()) : nullptr;
    }
};

}//namespace nlohmann

#endif  //OPTIONAL_JSION_H
