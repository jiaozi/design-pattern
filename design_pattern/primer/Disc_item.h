#include "item_base.h"

class Disc_item:public Item_base
{
public:
	Disc_item(const std::string &book = "", double sales_price = 0.0, 
		std::size_t qty = 0, double disc_rate = 0.0):Item_base(book, sales_price),quantity(qty), discound(disc_rate){}

	std::pair<std::size_t, double> discount_policy()const
	{
		return std::make_pair(quantity, discound);
	}
	virtual double net_price(std::size_t n)const = 0;
// 	virtual Disc_item* clone()const{
// 		return new Disc_item(*this);
// 	}
protected:
	std::size_t quantity;
	double discound;
};