#include <LightPixel.hpp>
#include "Util.hpp"

#include <vector>
#include <sstream>
#include <stdio.h>
#include <windows.h>

//namespace 
//{
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

	StringVec Split(std::string str, std::string pattern)
	{
		std::string::size_type pos;
		StringVec result;
		str += pattern;
		int size = str.size();

		for (int i = 0; i < size; i++)
		{
			pos = str.find(pattern, i);
			if (pos < size)
			{
				std::string s = str.substr(i, pos - i);
				result.push_back(s);
				i = pos + pattern.size() - 1;
			}
		}
		return result;
	}

	int Str2Int(std::string str)
	{
		int value;
		std::stringstream ss(str);
		ss >> value;
		return value;
	}

	float Str2Float(std::string str)
	{
		float value;
		std::stringstream ss(str);
		ss >> value;
		return value;
	}

	//}