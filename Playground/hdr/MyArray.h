#pragma once

namespace mystd
{
	template<typename T, size_t SIZE>
	class Array
	{
	private:
		T data[SIZE];
	public:
		Array();
		Array(const Array<T, SIZE>& other);
		Array(Array<T, SIZE>&& other) = delete;

		T& operator[](size_t indx);
		const T& operator[](size_t indx) const;
		T& At(size_t idx);
		const T& At(size_t idx) const;
		T& First();
		const T& First() const;
		T& Last();
		const T& Last() const;

		template<typename T, size_t SIZE>
		friend std::ostream& operator<<(std::ostream& out, const Array<T, SIZE>& a);

		template<typename T, size_t SIZE>
		friend bool operator==(const Array<T, SIZE>& first, const Array<T, SIZE>& second);
		template<typename T, size_t SIZE>
		friend bool operator!=(const Array<T, SIZE>& first, const Array<T, SIZE>& second);

		Array<T, SIZE>& operator=(const Array<T, SIZE>& other);
		Array<T, SIZE>& operator=(Array<T, SIZE>&& other) = delete;

		constexpr size_t Size() const;
	};

	template<typename T, size_t SIZE>
	Array<T, SIZE>::Array() { memset(data, 0, sizeof(T) * SIZE); }

	template<typename T, size_t SIZE>
	Array<T, SIZE>::Array(const Array<T, SIZE>& other)
	{
		for (size_t i = 0; i < SIZE; i++)
		{
			data[i] = other.data[i];
		}
	}

	template<typename T, size_t SIZE>
	T& Array<T, SIZE>::operator[](size_t idx) { return data[idx]; }

	template<typename T, size_t SIZE>
	const T& Array<T, SIZE>::operator[](size_t idx) const { return data[idx]; }

	template<typename T, size_t SIZE>
	T& Array<T, SIZE>::At(size_t idx) { return data[idx]; }

	template<typename T, size_t SIZE>
	const T& Array<T, SIZE>::At(size_t idx) const { return data[idx]; }

	template<typename T, size_t SIZE>
	T& Array<T, SIZE>::First() { return data[0]; }

	template<typename T, size_t SIZE>
	const T& Array<T, SIZE>::First() const { return data[0]; }

	template<typename T, size_t SIZE>
	T& Array<T, SIZE>::Last() { return data[SIZE - 1]; }

	template<typename T, size_t SIZE>
	const T& Array<T, SIZE>::Last() const { return data[SIZE - 1]; }

	template<typename T, size_t SIZE>
	std::ostream& operator<<(std::ostream& out, const Array<T, SIZE>& a)
	{
		if (SIZE > 0)
		{
			for (size_t i = 0; i < SIZE; i++)
			{
				out << a.data[i] << " ";
			}
		}
		return out;
	}

	template<typename T, size_t SIZE>
	bool operator==(const Array<T, SIZE>& first, const Array<T, SIZE>& second)
	{
		if (&first == &second) return true;
		
		for (size_t i = 0; i < SIZE; i++)
		{
			if (first.data[i] != second.data[i]) return false;
		}

		return true;
	}

	template<typename T, size_t SIZE>
	bool operator!=(const Array<T, SIZE>& first, const Array<T, SIZE>& second)
	{
		if (&first == &second) return false;

		for (size_t i = 0; i < SIZE; i++)
		{
			if (first.data[i] != second.data[i]) return true;
		}

		return false;
	}

	template<typename T, size_t SIZE>
	Array<T, SIZE>& Array<T, SIZE>::operator=(const Array<T, SIZE>& other)
	{
		for (size_t i = 0; i < SIZE; i++)
		{
			data[i] = other.data[i];
		}
		return *this;
	}

	template<typename T, size_t SIZE>
	constexpr size_t Array<T, SIZE>::Size() const { return SIZE; }
}