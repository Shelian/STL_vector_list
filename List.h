#pragma once
#include "Iterator.h"
template<class T>
struct __ListNode
{
	__ListNode<T>* _next;
	__ListNode<T>* _prev;
	T _data;

	__ListNode(const T& x=T())
		:_data(x)
		, _next(NULL)
		, _prev(NULL)
	{}
};

//T T& T*
//T const T& const T*
template<class T,class Ref,class Ptr>
struct __ListIterator
{
	typedef __ListIterator<T, Ref, Ptr> Self;
	typedef __ListNode<T> ListNode;

	typedef BidirectionalIteratorTag IteratorCategory;
	typedef T ValueType;
	typedef Ptr Pointer;
	typedef Ref Reference;
	typedef ptrdiff_t DifferenceType;

public:
	__ListIterator(ListNode* x) :_node(x){}
	__ListIterator(){}

	bool operator==(const Self& x )const
	{
		return _node == x._node;
	}

	bool operator!=(const Self& x)const
	{
		return _node != x._node;
	}

	Reference operator*()const
	{
		return _node->_data;
	}

	Reference operator->()const
	{
		return &(operator*());
	}

	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	Self operator++(int)
	{
		Self tmp = *this;
		_node = _node->_next;

		return tmp;
	}

	Self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	Self operator--(int)
	{
		Self tmp = *this;
		_node = _node->_prev;

		return tmp;
	}

	ListNode* _node;//对象里面有一个节点，节点的指针去访问，Iterator本身是一个对象
};


template<class T>
class List
{
	typedef __ListNode<T> ListNode;
public:
	typedef __ListIterator<T, T&, T*> Iterator;
	typedef __ListIterator<T, const T&, const T*> ConstIterator;

	List()
	{
		_head = new ListNode();
		_head->_next = _head;
		_head->_prev = _head;
	}

	~List()
	{
		Clear();
		delete _head;
	}

	void Clear()
	{
		Iterator it = Begin();
		while (it != End())
		{
			Iterator del = it;
			++it;

			delete del._node;
		}

		_head->_next = _head;
		_head->_prev = _head;
	}

	Iterator Begin()
	{
		return _head->_next;
	}

	ConstIterator Begin()const
	{
		return _head->_next;
	}

	Iterator End()
	{
		return _head;
	}

	ConstIterator End()const
	{
		return _head;
	}

	void PushBack(const T& x)
	{
		Insert(End(), x);
	}

	void PushFront(const T& x)
	{
		Insert(Begin(), x);
	}

	void PopBack()
	{
		Erase(--End());
	}

	void PopFront()
	{
		Erase(Begin());
	}

	void Insert(Iterator pos, const T& x)
	{
		ListNode* tmp = new ListNode(x);

		ListNode* cur = pos._node;
		ListNode* prev = cur->_prev;

		prev->_next = tmp;
		tmp->_prev = prev;

		tmp->_next = cur;
		cur->_prev = tmp;
	}


	Iterator Erase(Iterator pos)
	{
		ListNode* next = pos._node->_next;
		ListNode* prev = pos._node->_prev;

		prev->_next = next;
		next->_prev = prev;

		delete pos._node;

		return next;
	}

protected:
	ListNode* _head;

};

void PrintList1(List<int>& l)
{
	List<int>::Iterator it = l.Begin();
	while (it != l.End())
	{
		(*it)++;
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void TestList()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);

	l.PopBack();
	l.PopBack();

	PrintList1(l);
}