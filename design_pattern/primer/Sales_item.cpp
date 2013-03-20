#include "Sales_item.h"

Sales_item& Sales_item::operator =(const Sales_item& rhs)
{
	++*rhs.use;
	decrease_use();
	use = rhs.use;
	p = rhs.p;

	return *this;
}

Sales_item::Sales_item(const Item_base &item):use(new std::size_t(1)),p(item.clone())
{
	
}