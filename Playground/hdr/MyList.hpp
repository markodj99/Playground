#pragma once
#include <iostream>

namespace
{
	template<typename T>
	class List
	{
	private:
		struct Element
		{
			T data;
			struct Element* next;
			struct Element* prev;
		}typedef Element;
		Element* head = nullptr;
		Element* tail = nullptr;
		size_t size = 0;
	public:

		List();
		List(const List<T>& other) = delete;
		List(List<T>&& other) = delete;
		~List();

		void PushFront(const T& value);
		void PushBack(const T& value);
		void InsertAt(const T& value, size_t idx);

		void PopFront();
		void PopBack();
		void DeleteAt(size_t idx);

		T* At(size_t idx);
		const T* const At(size_t idx) const;
		T* First();
		const T* const First() const;
		T* Last();
		const T* const Last() const;

		const Element* GetHead();
		const Element* const GetHead() const;
		const Element* GetTail();
		const Element* const GetTail() const;

		void Clear();
		size_t Size() const;

		List<T>& operator=(const List<T>& other) = delete;
		List<T>& operator=(List<T>&& other) = delete;

		template<typename T>
		friend std::ostream& operator<<(std::ostream& out, const List<T>& l);

		template<typename T>
		friend bool operator==(const List<T>& first, const List<T>& second);

		template<typename T>
		friend bool operator!=(const List<T>& first, const List<T>& second);
	private:
		void AddFirstElement(const T& value);
		void DeleteLastElement();
	};

	template<typename T>
	List<T>::List() : head(nullptr), tail(nullptr), size(0) { }

	template<typename T>
	List<T>::~List() { Clear(); }

	template<typename T>
	void List<T>::PushFront(const T& value)
	{
		if (size == 0)
		{
			AddFirstElement(value);
		}
		else
		{
			Element* newElement = new Element;
			newElement->data = value;
			newElement->next = head;
			newElement->prev = nullptr;
			head->prev = newElement;
			head = newElement;
			size++;
		}
	}

	template<typename T>
	void List<T>::PushBack(const T& value)
	{
		if (size == 0)
		{
			AddFirstElement(value);
		}
		else
		{
			Element* newElement = new Element;
			newElement->data = value;
			newElement->next = nullptr;
			newElement->prev = tail;
			tail->next = newElement;
			tail = newElement;
			size++;
		}
	}

	template<typename T>
	void List<T>::InsertAt(const T& value, size_t idx)
	{
		if (idx < 0 || idx > size + 1) return;

		if (idx == 0)
		{
			PushFront(value);
			return;
		}
		if (idx == size + 1)
		{
			PushBack(value);
			return;
		}

		Element* el = head;
		for (size_t i = 0; i < idx; i++)
		{
			el = el->next;
		}

		Element* newElement = new Element;
		newElement->data = value;
		newElement->next = el;
		newElement->prev = el->prev;

		Element* prev = newElement->prev;
		prev->next = newElement;
		el->prev = newElement;

		size++;
	}

	template<typename T>
	void List<T>::PopFront()
	{
		if (size < 1) return;

		if (size == 1)
		{
			DeleteLastElement();
		}
		else
		{
			Element* toDelete = head;
			head = head->next;
			head->prev = nullptr;
			delete toDelete;

			size--;
		}
	}

	template<typename T>
	void List<T>::PopBack()
	{
		if (size < 1) return;

		if (size == 1)
		{
			DeleteLastElement();
		}
		else
		{
			Element* toDelete = tail;
			tail = tail->prev;
			tail->next = nullptr;
			delete toDelete;

			size--;
		}
	}

	template<typename T>
	void List<T>::DeleteAt(size_t idx)
	{
		if (idx < 0 || idx > size || size == 0) return;
		if (idx == 0)
		{
			PopFront();
			return;
		}
		if (idx == size)
		{
			PopBack();
			return;
		}

		Element* el = head;
		for (size_t i = 0; i < idx; i++)
		{
			el = el->next;
		}

		Element* prev = el->prev;
		Element* next = el->next;

		prev->next = next;
		next->prev = prev;

		delete el;
		size--;
	}

	template<typename T>
	T* List<T>::At(size_t idx)
	{
		if (idx < 0 || idx > size || size == 0) return nullptr;
		if (idx == 0) return &head->data;

		Element* el = head;
		for (size_t i = 0; i < idx; i++)
		{
			el = el->next;
		}

		return &el->data;
	}

	template<typename T>
	const T* const List<T>::At(size_t idx) const
	{
		if (idx < 0 || idx > size || size == 0) return nullptr;
		if (idx == 0) return &head->data;

		Element* el = head;
		for (size_t i = 0; i < idx; i++)
		{
			el = el->next;
		}

		return &el->data;
	}

	template<typename T>
	T* List<T>::First() 
	{
		if (size == 0) return nullptr;
		return &head->data; 
	}

	template<typename T>
	const T* const List<T>::First() const
	{
		if (size == 0) return nullptr;
		return &head->data;
	}

	template<typename T>
	T* List<T>::Last() 
	{
		if (size == 0) return nullptr;
		return &tail->data; 
	}

	template<typename T>
	const T* const List<T>::Last() const 
	{
		if (size == 0) return nullptr;
		return &tail->data;
	}

	template<typename T>
	const List<T>::Element* List<T>::GetHead() { return head; }

	template<typename T>
	const List<T>::Element* const List<T>::GetHead() const { return head; }

	template<typename T>
	const List<T>::Element* List<T>::GetTail() { return tail; }

	template<typename T>
	const List<T>::Element* const List<T>::GetTail() const { return tail; }

	template<typename T>
	void List<T>::Clear()
	{
		Element* element = head;
		while (element)
		{
			Element* toDelete = element;
			element = element->next;
			delete toDelete;
		}

		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	
	template<typename T>
	size_t List<T>::Size() const { return size; }


	template<typename T>
	std::ostream& operator<<(std::ostream& out, const List<T>& l)
	{
		if (l.size > 0)
		{
			struct List<T>::Element* el = l.head;
			while (el)
			{
				out << el->data << " ";
				el = el->next;
			}
		}

		return out;
	}

	template<typename T>
	bool operator==(const List<T>& first, const List<T>& second)
	{
		if (&first == &second) return true;
		if (first.size != second.size) return false;

		struct List<T>::Element* el1 = first.head;
		struct List<T>::Element* el2 = second.head;
		while (el1)
		{
			if (el1->data != el2->data) return false;

			el1 = el1->next;
			el2 = el2->next;
		}

		return true;
	}

	template<typename T>
	bool operator!=(const List<T>& first, const List<T>& second)
	{
		if (&first == &second) return false;
		if (first.size != second.size) return true;

		struct List<T>::Element* el1 = first.head;
		struct List<T>::Element* el2 = second.head;
		while (el1)
		{
			if (el1->data != el2->data) return true;

			el1 = el1->next;
			el2 = el2->next;
		}

		return false;
	}
	
	template<typename T>
	void List<T>::AddFirstElement(const T& value)
	{
		head = new Element;
		head->data = value;
		head->next = head->prev = nullptr;
		tail = head;
		size++;
	}

	template<typename T>
	void List<T>::DeleteLastElement()
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
}