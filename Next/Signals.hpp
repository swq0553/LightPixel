#ifndef _SIGNALS_HPP
#define _SIGNALS_HPP
#pragma once

#include <functional>
#include <vector>
namespace LightPixel 
{
	template<typename... Types>
	class Slot
	{
	public:
		Slot(const std::function<void(Types...)>& callable)
			:callable(callable)
		{}
		Slot& operator =(const std::function<void(Types...)>& callable)
		{
			this->callable = callable;
		}
		void operator() (Types... args)
		{
			this->callable(args...);
		}
	private:
		std::function<void(Types...)> callable;
	};
	
	template<typename... types>
	class Signal
	{
	public:
		void operator() (types... args)
		{
			for (auto& callable : this->callables)
			{
				callable(args...);
			}
		}
		int connect(const std::function<void(types...)>& callable)
		{
			this->callables.push_back(Slot<types...>(callable));
			return this->callables.size() - 1;
		}
		void disconnect(int handle)
		{
			this->callables.erase(this->callables.begin() + handle);
		}
		void disconnectAll()
		{
			this->callables.clear();
		}
	private:
		std::vector<Slot<types...>> callables;
	};
} // namespace Signals
#endif