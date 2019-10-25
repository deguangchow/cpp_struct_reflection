///    Copyright (C) 2019 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    dynamic reflection : 动态反射
///
///    \author   deguangchow
///    \version  1.0
///    \2019/10/24

#pragma once
#ifndef DYNAMIC_REFLECTION_H
#define DYNAMIC_REFLECTION_H

//通用的转换接口
template<typename FieldType>
using ValueConverter = std::function<void(FieldType* field, const std::string &name)>;

//接口
template<typename StructType>
class FieldConverterBase {
public:
    virtual ~FieldConverterBase() = default;
    virtual void operator()(StructType *obj) const = 0;
};

//实现类
template<typename StructType, typename FieldType>
class FieldConverter : public FieldConverterBase<StructType> {
public:
    FieldConverter(const std::string &name, FieldType StructType::*pointer, ValueConverter<FieldType> converter)
        : field_name_(name), field_pointer_(pointer), value_converter_(converter) {
    }
    void operator()(StructType *obj) const override {
        return value_converter_(&(obj->*field_pointer_), field_name_);
    }

private:
    std::string                 field_name_;        //字段名称
    FieldType StructType::      *field_pointer_;    //字段的 成员指针 (member pointer)（即字段位置）
    ValueConverter<FieldType>   value_converter_;   //字段的映射方法
};

//注册类
template<class StructType>
class StructValueConverter {
public:
    template<typename FieldType>
    void RegisterField(FieldType StructType::*field_pointer, const std::string &field_name,
        ValueConverter<FieldType> value_converter) {
        fields_.push_back(std::make_unique<FieldConverter<StructType, FieldType>>(
            field_name, field_pointer, std::move(value_converter)));
    }

    void operator()(StructType *obj) const {
        for (const auto &field_converter : fields_) {
            (*field_converter)(obj);
        }
    }
private:
    std::vector<std::unique_ptr<FieldConverterBase<StructType>>> fields_;
};

#endif  //DYNAMIC_REFLECTION_H
