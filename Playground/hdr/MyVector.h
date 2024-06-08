#pragma once
#include <iostream>

namespace mystd
{
    template<typename T>
    class Vector
    {
    private:
        T* data = nullptr;
        size_t capacity = 0;
        size_t size = 0;
    public:
        Vector();
        Vector(size_t capacity);
        Vector(const Vector<T>& other) = delete;
        Vector(Vector<T>&& other) = delete;
        ~Vector();

        void PushBack(const T& value);
        void PushBack(T&& value);

        size_t Size() const;
        size_t Capacity() const;
        void Clear();

        T& operator[](size_t idx);
        const T& operator[](size_t idx) const;
        T& At(size_t idx);
        const T& At(size_t idx) const;
        T& First();
        const T& First() const;
        T& Last();
        const T& Last() const;

        Vector<T>& operator=(const Vector<T>& other) = delete;
        Vector<T>& operator=(Vector<T>&& other) = delete;

        template<typename T>
        friend std::ostream& operator<<(std::ostream& out, const Vector<T>& v);

        template<typename T>
        friend bool operator==(const Vector<T>& first, const Vector<T>& second);
        template<typename T>
        friend bool operator!=(const Vector<T>& first, const Vector<T>& second);
    private:
        void Reallocate();
        void DefaultAllocate();
        void DeleteAll();
    };

    template<typename T>
    Vector<T>::Vector() { DefaultAllocate(); }
    
    template<typename T>
    Vector<T>::Vector(size_t capacity) : capacity(capacity), size(0) { data = new T[capacity]; }
    
    template<typename T>
    Vector<T>::~Vector() { Clear(); }

    template<typename T>
    void Vector<T>::PushBack(const T& value)
    {
        if (capacity == size)
        {
            Reallocate();
        }
        data[size++] = value;
    }

    template<typename T>
    void Vector<T>::PushBack(T&& value)
    {
        if (capacity == size) 
        {
            Reallocate(); 
        }
        
        data[size++] = std::move(value);
    }

    template<typename T>
    size_t Vector<T>::Size() const { return size; }

    template<typename T>
    size_t Vector<T>::Capacity() const { return capacity; }

    template<typename T>
    void Vector<T>::Clear() 
    { 
        DeleteAll();
        DefaultAllocate();
    }

    template<typename T>
    T& Vector<T>::operator[](size_t idx) { return data[idx]; }

    template<typename T>
    const T& Vector<T>::operator[](size_t idx) const { return data[idx]; }

    template<typename T>
    T& Vector<T>::At(size_t idx) { return data[idx]; }

    template<typename T>
    const T& Vector<T>::At(size_t idx) const { return data[idx]; }

    template<typename T>
    T& Vector<T>::First() { return data[0]; }

    template<typename T>
    const T& Vector<T>::First() const { return data[0]; }

    template<typename T>
    T& Vector<T>::Last() { return data[size - 1]; }

    template<typename T>
    const T& Vector<T>::Last() const { return data[size - 1]; }

    template<typename T>
    std::ostream& operator<<(std::ostream& out, const Vector<T>& v)
    {
        if (v.size > 0)
        {
            for (size_t i = 0; i < v.size; i++) 
            {
                out << v.data[i] << " ";
            }
        }
        return out;
    }

    template<typename T>
    bool operator==(const Vector<T>& first, const Vector<T>& second)
    {
        if (&first == &second) return true;
        if (first.size != second.size) return false;

        for (size_t i = 0; i < first.size; i++)
        {
            if (first.data[i] != second.data[i]) return false;
        }

        return true;
    }

    template<typename T>
    bool operator!=(const Vector<T>& first, const Vector<T>& second)
    {
        if (&first == &second) return false;
        if (first.size != second.size) return true;

        for (size_t i = 0; i < first.size; i++)
        {
            if (first[i] != second[i]) return true;
        }

        return false;
    }

    template<typename T>
    void Vector<T>::Reallocate()
    {
        size_t newCapacity = (int)((float)capacity * 1.7f);
        T* newData = new T[newCapacity];

        for (size_t i = 0; i < size; i++)
        {
            newData[i] = std::move(data[i]);
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    template<typename T>
    void Vector<T>::DefaultAllocate()
    {
        capacity = 2;
        size = 0;
        data = new T[2];
    }

    template<typename T>
    void Vector<T>::DeleteAll()
    {
        delete[] data;
        size = 0;
        capacity = 0;
    }
}
