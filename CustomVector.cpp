#include <iostream>

using namespace std;

template<typename T>
class Vector
{
	int m_capacity;
	int m_size;
	T* m_data;

public:
	Vector() : m_size(0), m_capacity(2),m_data(new T[m_capacity]){}
	Vector(T size): m_size(size), m_capacity(size *2), m_data(new T[m_capacity]){}
	Vector(Vector& data): m_size(data.m_size),m_capacity(data.m_capacity),m_data(new T[m_capacity]) {
		for (int i = 0; i < m_size; i++)
		{
			m_data[i] = data[i];
		}
	}

	~Vector()
	{
		delete m_data;
	}

	void reserve(int newCapacity)
	{
		T* temp = new T(newCapacity);
		for (int i = 0; i < m_size; i++)
		{
			temp[i] = m_data[i];
		}
		delete m_data;
		m_data = temp;
		m_capacity = newCapacity;
	}

	void push_back(T val)
	{
		if (m_size >= m_capacity)
		{
			reserve(m_capacity * 2);
		}
		m_data[m_size] = val;
		m_size++;
	}

	void pop_back()
	{
		if (m_size > 0)
			m_size--;
	}

	int size() const
	{
		return m_size;
	}

	bool empty() const
	{
		return m_size == 0;
	}

	T& operator [] (int index)
	{
		if (index < 0 || index > m_size)
		{
			return;
		}

		return m_data[index];
	}

	const T& operator [] (int index) const
	{
		if (index < 0 || index > m_size)
		{
			return;
		}

		return m_data[index];
	}

	void insertAt(const T& val, int index)
	{
		if (index < 0 || index > m_size)
		{
			return;
		}
		
		if (m_size >= m_capacity)
		{
			reserve(m_capacity * 2);
		}

		for (int i = m_size - 1; i >= index; i--)
		{
			m_data[i + 1] = m_data[i];
		}
		m_data[index] = val;
		m_size++;
	}

};

int main()
{
	Vector<int> intVec;
	intVec.push_back(4);
	intVec.push_back(8);
	intVec.push_back(12);
	intVec.pop_back();
	intVec[1];
	return 0;
}
