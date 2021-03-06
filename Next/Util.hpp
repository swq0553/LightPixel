#ifndef _UTIL_HPP
#define _UTIL_HPP
#pragma once

#include <PreDeclare.hpp>
#include <string>

namespace LightPixel
{
	std::string& Convert(std::string& strDest, std::wstring const & wstrSrc);
	std::wstring& Convert(std::wstring& wstrDest, std::string const & strSrc);

	template <typename T, typename... Types>
	inline std::shared_ptr<T> MakeSharedPtr(Types... args)
	{
		return std::shared_ptr<T>(new T(args...));
	}
}
#endif