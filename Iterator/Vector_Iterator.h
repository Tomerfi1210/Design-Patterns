#pragma once
#include <iostream>
#include <memory>
#include <algorithm>

using namespace std;
template <typename T>
class Vector
{
private:
	T* m_vec;
	size_t size;
public:
	~Vector()
	{
		delete[] m_vec;
	}
	void push_back(const T& val)
	{
		T* tmp = new T[size];
		for (int i = 0; i < size; i++)
			tmp[i] = m_vec[i];
		m_vec = new T[size + 1];
		for (int i = 0; i < size; i++)
			m_vec[i] = tmp[i];
		m_vec[size] = val;
		size++;
		delete[] tmp;
	}

	size_t get_size() const { return size; }

	class Iterator
	{
	private:
		T* curr;
	public:
		Iterator(T* p) : curr(p) { ; }
		T& operator*()
		{
			return *curr;
		}
		bool operator!=(const Iterator& other)
		{
			return *curr != *other.curr;
		}
		Iterator& operator++()
		{
			curr++;
			return *this;
		}

	};

	Iterator begin()
	{
		return Iterator(this->m_vec);
	}

	Iterator end()
	{
		return Iterator(this->m_vec + size);
	}
};


int main()
{
	unique_ptr<Vector<int>> vec = make_unique<Vector<int>>();
	vec->push_back(7.3);
	vec->push_back(2);
	vec->push_back(3);

	for_each(vec->begin(), vec->end(), [](int value) { cout << value << " "; });
	return 0;
}