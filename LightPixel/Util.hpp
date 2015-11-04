#ifndef _UTIL_HPP
#define _UTIL_HPP
#pragma once

#include <PreDeclare.hpp>
#include <string>

//namespace 
//{
	std::string& Convert(std::string& strDest, std::wstring const & wstrSrc);
	std::wstring& Convert(std::wstring& wstrDest, std::string const & strSrc);

	template <typename T, typename... Args>
	inline std::shared_ptr<T> MakeSharedPtr(Args&& ... args)
	{
		return std::shared_ptr<T>(new T(std::forward<Args>(args)...), std::default_delete<T>());
	}
//}
#endif