#pragma once
#include <iostream>

namespace mystd
{
	template<typename T>
	class ScopedPtr
	{
	private:
		T* ptrToData = nullptr;
	public:
		ScopedPtr();
		ScopedPtr(T* ptr);
		ScopedPtr(const ScopedPtr<T>& other) = delete;
		ScopedPtr(ScopedPtr<T>&& other) = delete;
		~ScopedPtr();

		T* Get();
		const T* const Get() const;
		
		ScopedPtr<T>& operator=(T* ptr);
		ScopedPtr<T>& operator=(const ScopedPtr<T>& other) = delete;
		ScopedPtr<T>& operator=(ScopedPtr<T>&& other) = delete;

		T& operator*();
		const T& const operator*() const;

		T* operator->();
		const T* const operator->() const;
		
		explicit operator bool() const;

		template<typename T>
		friend std::ostream& operator<<(std::ostream& out, const ScopedPtr<T>& ptr);

		bool IsValid() const;
	};

	template<typename T>
	ScopedPtr<T>::ScopedPtr() : ptrToData(nullptr){ }

	template<typename T>
	ScopedPtr<T>::ScopedPtr(T* ptr) : ptrToData(ptr) { }
	
	template<typename T>
	ScopedPtr<T>::~ScopedPtr() { delete ptrToData; }

	template<typename T>
	T* ScopedPtr<T>::Get() { return ptrToData; }

	template<typename T>
	ScopedPtr<T>& ScopedPtr<T>::operator=(T* ptr)
	{
		if (!ptrToData)
		{
			if (ptr)
			{
				ptrToData = ptr;
			}
		}

		return *this;
	}

	template<typename T>
	const T* const ScopedPtr<T>::Get() const { return ptrToData; }

	template<typename T>
	T& ScopedPtr<T>::operator*() { return *ptrToData; }

	template<typename T>
	const T& const ScopedPtr<T>::operator*() const { return *ptrToData; }

	template<typename T>
	T* ScopedPtr<T>::operator->() { return ptrToData; }

	template<typename T>
	const T* const ScopedPtr<T>::operator->() const { return ptrToData; }

	template<typename T>
	ScopedPtr<T>::operator bool() const { return ptrToData != nullptr; }

	template<typename T>
	std::ostream& operator<<(std::ostream& out, const ScopedPtr<T>& ptr)
	{
		if (ptr)
		{
			out << *ptr;
		}

		return out;
	}

	template<typename T>
	bool ScopedPtr<T>::IsValid() const { return ptrToData != nullptr; }
}