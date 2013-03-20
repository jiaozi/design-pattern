#include <iostream>
#include <list>
#include <vector>
#include <memory>
#include <string>
#include <bitset>

template<class T, template<class U, class = std::allocator<U>> class Seq>
class Container
{
	Seq<T> seq;
public:
	void push_back(const T& t){seq.push_back(t);}
	typename Seq<T>::iterator begin(){return seq.begin();}
	typename Seq<T>::iterator end(){return seq.end();}
};

template<class T, template<class U, class = std::allocator<U>> class Seq>
void printSeq(Seq<T>& seq){
	for (typename Seq<T>::iterator iter = seq.begin(); iter != seq.end();)
	{
		std::cout << *iter++ << std::endl;
	}
}
using namespace std;
template<class charT, size_t N>
std::basic_string<charT> bitsetTostring(const std::bitset<N>& bs)
{
	return bs. template std::to_string<charT, std::char_traits<charT>.std::allocator<charT>>();
}

int main()
{
	Container<int, std::vector> vContainer;
	vContainer.push_back(1);
	vContainer.push_back(2);
	for (std::vector<int>::iterator iter = vContainer.begin(); iter != vContainer.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}

	Container<int, std::list> lContainer;
	lContainer.push_back(3);
	lContainer.push_back(4);
	for (std::list<int>::iterator iter = lContainer.begin(); iter != lContainer.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}

	std::vector<int> v;
	v.push_back(5);
	v.push_back(6);
	printSeq(v);

	std::bitset<10> bs;
	bs.set(1);
	bs.set(5);
	std::cout << bs << std::endl;
	std::string s = bitsetTostring<char>(bs);
	std::cout << s << std::endl;
	return 0;
}