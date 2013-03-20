#include "Bulk_item.h"
#include <iostream>

double Bulk_item::net_price(std::size_t n)const
{
	if (n < quantity)
	{
		return n * price;
	}
	else
	{
		return n * price * (1 - discound);
	}
}

void print_total(const Item_base &item, std::size_t n)
{
	std::cout << "ISBN:" << item.book() << "\tnumber sold:" << n << "\ttotal price:" << item.net_price(n) << std::endl;
}