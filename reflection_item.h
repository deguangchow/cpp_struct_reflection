///    Copyright (C) 2019 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    reflection_item : item ∑¥…‰
///
///    \author   deguangchow
///    \version  1.0
///    \2019/10/26

#pragma once
#ifndef REFLECTION_ITEM_H
#define REFLECTION_ITEM_H

namespace core {

template<typename, typename>
struct item_serializer {
	template<typename BasicItemType, typename ValueType>
	static auto from_item(BasicItemType&& item, ValueType& val) noexcept(
		noexcept(::core::from_item(std::forward<BasicItemType>(item), val)))
		-> decltype(::core::from_item(std::forward<BasicItemType>(item), val), void())
	{
		::core::from_item(std::forward<BasicItemType>(item), val);
	}

	template <typename BasicItemType, typename ValueType>
	static auto to_item(BasicItemType& item, ValueType&& val) noexcept(
		noexcept(::core::to_item(item, std::forward<ValueType>(val))))
		-> decltype(::core::to_item(item, std::forward<ValueType>(val)), void())
	{
		::core::to_item(item, std::forward<ValueType>(val));
	}
};

}//core


#endif	//REFLECTION_ITEM_H
