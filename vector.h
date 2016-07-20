#pragma once
#include <vector>
#include<assert.h>
template<class T>
class Vector
{
public:
	typedef T ValueType;
	typedef ValueType* Iterator;
	typedef const ValueType* ConstIterator;

	Vector()
		:_start(NULL)
		, _finish(NULL)
		, _endOfStorage(NULL)
	{}

	~Vector()
	{
		delete[] _start;
		_start = _finish = _endOfStorage = NULL;
	}

	Iterator Begin()
	{
		return _start;
	}

	ConstIterator Begin() const
	{
		return _start;
	}

	Iterator End()
	{
		return _finish;
	}

	ConstIterator End()const
	{
		return _finish;
	}

	void PushBack(const T& x)
	{
		_CheckStorage();

		*_finish = x;
		_finish++;
	}

	void PopBack()
	{
		assert(_finish != _start);
		--finish;
	}

	size_t Size()
	{
		return _finish - _start;		//这里finish是一个开区间，所以不用加1
	}

	ValueType& operator[](size_t index)//返回修值取引用，便于修改
	{
		assert(_start + index < _finish);

		return _start[index];
	}

	void _CheckStorage()
	{
		if (_finish == _endOfStorage)
		{
			size_t size = _finish - _start;
			size_t newSize = 2 * size + 3;
			ValueType* tmp = new ValueType[newSize];
			for (int i = 0; i < size; i++)
			{
				tmp[i] = _start[i];
			}
			delete[] _start;
			_start = tmp;
			_finish = _start + size;
			_endOfStorage = _start + newSize;
		}
	}

private:
	Iterator _start;
	Iterator _finish;
	Iterator _endOfStorage;
};

void PrintVector1(const Vector<int>& v)
{
	Vector<int>::ConstIterator it = v.Begin();
	while (it != v.End())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
void PrintVector2(Vector<int>& v)
{
	Vector<int>::Iterator it = v.Begin();
	while (it != v.End())
	{
		(*it)++;
		cout << *it << " ";
		++it;
	}
	cout << endl;
}


void TestVector1()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);

	PrintVector1(v);
	PrintVector2(v);

	for (size_t i = 0; i < v.Size(); ++i)
	{
		v[i]++;
		cout << v[i] << " ";
	}
	cout << endl;
}
//void TestVector()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	cout<<"size?"<<v.size()<<endl;
//	cout<<"capacity?"<<v.capacity()<<endl;
//	cout<<"maxsize?"<<v.max_size()<<endl;
//
//	vector<int>::iterator it = v.begin();
//	while(it != v.end())
//	{
//		cout<<*it<<" ";
//		++it;
//	}
//
//	for (size_t i = 0; i < v.size(); ++i)
//	{
//		cout<<v[i]<<" ";
//	}
//
//	cout<<endl;
//}