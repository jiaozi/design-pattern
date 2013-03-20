#include "item_base.h"

class Sales_item{
public:
	Sales_item():use(new std::size_t(1)),p(NULL){}
	Sales_item(const Item_base& item);
	Sales_item(const Sales_item& i):use(i.use),p(i.p)
	{
		++*use;
	}
	~Sales_item(){decrease_use();}
	Sales_item& operator=(const Sales_item& rhs);

	Item_base* operator->()const{
		if (p)
		{
			return p;
		}
		else
		{
			throw std::logic_error("unbound Sales_item.");
		}
	}
	
	Item_base& operator*()const{
		if(p)
			return *p;
		else
			throw std::logic_error("unbound Sales_item.");
	}
private:
	void decrease_use()
	{
		if (--*use == 0)
		{
			delete p;
			p = NULL;
		}
	}
	std::size_t *use;
	Item_base *p;
};

typedef bool (*comp)(const Sales_item& lrhs, const Sales_item &rrhs);