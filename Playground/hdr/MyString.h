#pragma once
#include <iostream>

namespace mystd
{
	class String
	{
	private:
		char* data = nullptr;
		size_t size = 0;
	public:
		String();
		String(const char* other);
		String(const String& other);
		String(String&& other) noexcept;
		~String();

		size_t Size() const;
		bool IsEmpty() const;
		void Clear();

		friend std::ostream& operator<<(std::ostream& out, const String& s);
		friend std::istream& operator>>(std::istream& in, String& v);

		char& operator[](size_t idx);
		const char& operator[](size_t idx) const;
		char& At(size_t idx);
		const char& At(size_t idx) const;
		char& First();
		const char& First() const;
		char& Last();
		const char& Last() const;
		
		String& operator=(const char* s);
		String& operator=(const String& s);
		String& operator=(String&& s) noexcept;

		friend bool operator==(const String& first, const String& second);
		friend bool operator!=(const String& first, const String& second);
	};

	String::String() : data(nullptr), size(0) { }

	String::String(const char* other)
	{
		if (other)
		{
			size = 0;
			while (other[size] != '\0')
			{
				size++;
			}
			data = new char[size + 1];

			for (size_t i = 0; i < size; i++)
			{
				data[i] = other[i];
			}
			data[size] = '\0';
		}
		else
		{
			data = nullptr;
			size = 0;
		}
	}

	String::String(const String& other): size(other.size), data(new char[other.size + 1])
	{
		for (size_t i = 0; i < size; i++)
		{
			data[i] = other.data[i];
		}
		data[size] = '\0';
	}

	String::String(String&& other) noexcept : size(other.size), data(other.data)
	{
		other.size = 0;
		other.data = nullptr;
	}

	String::~String() { delete[] data; }

	size_t String::Size() const { return size; }

	bool String::IsEmpty() const { return size == 0; }

	void String::Clear() 
	{ 
		delete[] data;
		data = nullptr;
		size = 0;
	}

	std::ostream& operator<<(std::ostream& out, const String& s)
	{
		if (s.size > 0)
		{
			out << s.data;
		}
		return out;
	}

	std::istream& operator>>(std::istream& in, String& v)
	{
		char buffer[512];
		in.getline(buffer, 512);

		if (buffer)
		{
			if (v.data)
			{
				delete[] v.data;
			}

			v.size = 0;
			while (buffer[v.size] != '\0')
			{
				v.size++;
			}
			v.data = new char[v.size + 1];

			for (size_t i = 0; i < v.size; i++)
			{
				v.data[i] = buffer[i];
			}
			v.data[v.size] = '\0';
		}
		else
		{
			v.data = nullptr;
			v.size = 0;
		}
		return in;
	}

	char& String::operator[](size_t idx) { return data[idx]; }

	const char& String::operator[](size_t idx) const { return data[idx]; }

	char& String::At(size_t idx) { return data[idx]; }

	const char& String::At(size_t idx) const { return data[idx]; }

	char& String::First() { return data[0]; }

	const char& String::First() const { return data[0]; }

	char& String::Last() { return data[size - 1]; }

	const char& String::Last() const { return data[size - 1]; }

	String& String::operator=(const char* s)
	{
		if (!s) return *this;
		if (data)
		{
			delete[] data;
		}

		size = 0;
		while (s[size] != '\0')
		{
			size++;
		}
		data = new char[size + 1];

		for (size_t i = 0; i < size; i++)
		{
			data[i] = s[i];
		}
		data[size] = '\0';

		return *this;
	}

	String& String::operator=(const String& s)
	{
		if (this == &s) return *this;
		if (data)
		{
			delete[] data;
		}

		size = s.size;
		data = new char[size + 1];

		for (size_t i = 0; i < size; i++)
		{
			data[i] = s.data[i];
		}
		data[size] = '\0';

		return *this;
	}

	String& String::operator=(String&& s) noexcept
	{
		if (this == &s) return *this;
		if (data)
		{
			delete[] data;
		}

		size = s.size;
		data = s.data;

		s.size = 0;
		s.data = nullptr;

		return *this;
	}

	bool operator==(const String& first, const String& second)
	{
		if (&first == &second) return true;
		if (first.size != second.size) return false;

		for (int i = 0; i < first.size; i++)
		{
			if (first.data[i] != second.data[i]) return false;
		}
			
		return true;
	}

	bool operator!=(const String& first, const String& second)
	{
		if (&first == &second) return false;
		if (first.size != second.size) return true;

		for (int i = 0; i < first.size; i++)
		{
			if (first.data[i] != second.data[i]) return true;
		}

		return false;
	}
}