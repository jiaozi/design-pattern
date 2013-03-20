#pragma once

#include <string>

class Item_base
{
public:
	Item_base(const std::string &book = "", 
				double sales_price = 0.0):
					isbn(book),price(sales_price) {}

	Item_base(const Item_base &item):isbn(item.isbn),price(item.price){}

	Item_base& operator=(const Item_base& item)
	{
		if(this != &item)
		{
			isbn = item.isbn;
			price = item.price;
		}	

		return *this;
	}
	std::string book(void)const {return isbn;}
	virtual double net_price(std::size_t n)const {return n * price;}
	virtual ~Item_base() {}

	virtual Item_base* clone()const{
		return new Item_base(*this);
	}
private:
	std::string isbn;
protected:
	double price;
};