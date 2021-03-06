#include <Next.hpp>
#include "Util.hpp"

#include <vector>
#include <stdio.h>
#include <windows.h>

namespace LightPixel
{
	std::string& Convert(std::string& dest, std::wstring const & src)
	{
		int const mbs_len = WideCharToMultiByte(CP_ACP, 0, src.c_str(), static_cast<int>(src.size()), nullptr, 0, nullptr, nullptr);
		std::vector<char> tmp(mbs_len + 1);
		WideCharToMultiByte(CP_ACP, 0, src.c_str(), static_cast<int>(src.size()), &tmp[0], mbs_len, nullptr, nullptr);
		dest.assign(tmp.begin(), tmp.end() - 1);

		return dest;
	}

	std::wstring& Convert(std::wstring& dest, std::string const & src)
	{
		int const wcs_len = MultiByteToWideChar(CP_ACP, 0, src.c_str(), static_cast<int>(src.size()), nullptr, 0);
		std::vector<wchar_t> tmp(wcs_len + 1);
		MultiByteToWideChar(CP_ACP, 0, src.c_str(), static_cast<int>(src.size()), &tmp[0], wcs_len);

		dest.assign(tmp.begin(), tmp.end() - 1);

		return dest;
	}
}