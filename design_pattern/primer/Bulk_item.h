#pragma once
#include "item_base.h"
#include "Disc_item.h"
#include <string>

class Bulk_item:public Disc_item
{
public:
	/*Bulk_item():Disc_item("", 0.0, 0, 0.0){}*/
	Bulk_item(const std::string &book ="", double sales_price = 0.0, 
		std::size_t qty = 0, double disc_rate = 0.0):
			Disc_item(book, sales_price, qty, disc_rate){}

	Bulk_item(const Bulk_item &bulk_item):Disc_item(bulk_item){}

	Bulk_item& operator=(const Bulk_item& bulk_item)
	{
		if (this != &bulk_item)
		{
			Disc_item::operator =(bulk_item);
		}
		return *this;
	}
	double net_price(std::size_t n)const;
	
	Bulk_item* clone()const{
		return new Bulk_item(*this);
	}
private:
// 	std::size_t min_qty;
// 
// 	double discount;
};

void print_total(const Item_base &, std::size_t);