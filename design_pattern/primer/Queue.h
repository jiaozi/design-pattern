#pragma  once
#include <iostream>

template<class Type> class Queue;
template<class Type> std::ostream& operator<<(std::ostream &os, const Queue<Type> &q);
template<class Type> class QueueItem
{
	friend class Queue<Type>;
	friend std::ostream& operator<<<Type>(std::ostream &os, const Queue<Type> &q);
	Type item;
	QueueItem *next;
	QueueItem(const Type &t):item(t),next(NULL){}
};

template<class Type> class Queue
{
	friend std::ostream& operator<<<Type>(std::ostream &os, const Queue<Type> &q);
public:
	Queue():head(NULL),tail(NULL){}
	Queue(const Queue &Q):head(NULL),tail(NULL)
	{
		copy_element(Q);
	}
	Queue& operator=(const Queue&);
	~Queue(){destroy();}

	Queue& front(){return head->item;}
	const Queue& front()const{return head->item;}
	void push(const Type&);
	void pop();
	bool empty()const{return head == NULL;}
	template<class it> Queue(it beg, it end):head(NULL), tail(NULL){copy_elems(beg, end);}
	template<class iter> void assign(iter, iter);
private:
	QueueItem<Type> *head;
	QueueItem<Type> *tail;
	void destroy();
	void copy_element(const Queue &Q);
	template<class iter> void copy_elems(iter, iter);
};

template<class T> template<class iter> void Queue<T>::assign(iter beg, iter end)
{
	destroy();
	copy_elems(beg, end);
}

template<class T> template<class iter> void Queue<T>::copy_elems(iter beg, iter end)
{
	while(beg != end)
	{
		push(*beg);
		++beg;
	}
}
template<class Type> std::ostream& operator<<(std::ostream &os, const Queue<Type> &q)
{
	os << "<";
	QueueItem<Type> *p;
	for (p = q.head; p; p = p->next)
	{
		os << p->item << " ";
	}
	os << ">";

	return os;
}

template<class Type> void Queue<Type>::destroy()
{
	while(!empty())
		pop();
}

template<class Type> void Queue<Type>::pop()
{
	QueueItem<Type> *p = head;
	head = head->next;
	delete p;
}

template<class Type> void Queue<Type>::push(const Type& val)
{
	QueueItem<Type> *pt = new QueueItem<Type>(val);

	if (empty())
	{
		head = tail = pt;
	}
	else
	{
		tail->next = pt;
		tail = pt;
	}
}

template<class Type> void Queue<Type>::copy_element(const Queue &Q)
{
	for (QueueItem<Type> *pt = Q.head; pt; pt = pt->next)
	{
		push(pt->item);
	}
}