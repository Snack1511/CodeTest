#pragma once
#include<list>
template <class... ARGS>
class FDelegate
{
public:
	typedef typename std::list<std::function<void(ARGS...)>>::iterator iterator;
	//리턴 형식을 void로 고정
	void operator () (const ARGS... args)
	{
		for (auto& func : functions)
		{
			func(args...);
		}
	}

	FDelegate& operator += (std::function<void(ARGS...)> const& func)
	{
		functions.push_back(func);
		return *this;
	}

	FDelegate& operator -= (std::function<void(ARGS...)> const& func)
	{

		/*
		std::function::target 템플릿 멤버 함수를 사용 할 때, 
		템플릿 클래스의 템플릿 멤버 함수를 호출하게 되면 
		컴파일러가 타입을 제대로 추론하지 못해 
		템플릿 멤버 함수에 대해서 컴파일 오류를 발생 시킨다. 
		때문에 컴파일러에게 명시적으로 템플릿 함수라는 것을 알려 주기 위해 
		함수의 호출 부 앞에 'template' 키워드를 붙여 주었다.
		출처: https://kukuta.tistory.com/207 [HardCore in Programming:티스토리]
		*/
		
		void(* const* func_ptr)(ARGS...) = func.template target<void(*)(ARGS...)>();
		const std::size_t func_hash = func.target_type().hash_code();

		if (nullptr == func_ptr)
		{
			for (auto iter = functions.begin(); iter != functions.end(); iter++)
			{
				if (func_hash == (*iter).target_type().hash_code())
				{
					functions.erase(iter);
					return *this;
				}
			}
		}

		else
		{
			for (auto iter = functions.begin(); iter != functions.end(); iter++)
			{
				void(* const* delegate_ptr)(ARGS...) = (*iter).template target<void(*)(ARGS...)>();
				if (nullptr != delegate_ptr && *func_ptr == *delegate_ptr)
				{
					functions.erase(iter);
					return *this;
				}
			}
		}

		return *this;
	}

	iterator begin()
	{
		return functions.begin();
	}

	iterator end()
	{
		return functions.end();
	}

	void Clear()
	{
		functions.clear();
	}

private:
	typedef std::list<std::function<void(ARGS...)>> FunctionList;
	std::list<std::function<void(ARGS...)>> functions;
};