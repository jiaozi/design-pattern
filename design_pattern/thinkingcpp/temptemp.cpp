#include <cstddef>
#include <iostream>

template<class T, size_t N> class Array{
	enum{INIT = 10};
	T* data;
	size_t capacity;
	size_t count;
public:
	Array():count(0), data(new T[INIT]), capacity(INIT){}

	~Array(){delete []data;}
	void push_back(const T& t)
	{
		if (count == capacity)
		{
			size_t newCap = capacity * 2;
			T* newData = new T[newCap];
			memcpy(newData, data, capacity * sizeof(T));
			delete []data;
			data = newData;
			capacity = newCap;
		}
		data[count++] = t;
	}
	void pop_back(){
		if(count > 0)
			--count;
	}
	T* begin(){return data;}
	T* end(){return data + count;}
};

template<class T, template<class> class Seq> class Container
{
	Seq<T> seq;
public:
	void append(const T& t){seq.push_back(t);}
	T* begin(){return seq.begin();}
	T* end(){return seq.end();}
};

int main()
{
	Container<int, Array> container;
	container.append(1);
	container.append(2);
	int *p = container.begin();
	while(p != container.end())
		std::cout << *p++ << std::endl;

	return 0;
}