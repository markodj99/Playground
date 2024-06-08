#pragma once

namespace
{
	template<typename T>
	class List
	{
	private:
		struct Element {
			T data;
			struct Element* next;
			struct Element* prev;
		};
		Element* head = nullptr;
		Element* tail = nullptr;
		size_t size = 0;
	public:

		List();
		List(const List<T>& other);
		List(List<T>&& other) = delete;
		~List();

		void PushFront(const T& value);
		void PushBack(const T& value);
		void InsertAt(const T& value, size_t idx);

		void PopFront();
		void PopBack();
		void DeleteAt(size_t idx);


	};
}