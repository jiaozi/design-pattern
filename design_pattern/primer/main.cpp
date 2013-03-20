#include "item_base.h"
#include "Bulk_item.h"
#include "template.h"
#include "Queue.h"


int main()
{
// 	Bulk_item bulk_("book one", 20.0);
// 	Item_base base;
// 	Bulk_item derived;
// 
// 	print_total(base, 10);
// 	print_total(derived, 20);
// 
// 	//Disc_item disc_item;
// 	Item_base base2 = derived;

	int x[20];
	double y[10];

	arrary_init(x);
	arrary_init(y);

	Queue<int> intQue;
	intQue.push(0);
	intQue.push(1);
	intQue.push(2);
	intQue.push(3);

	std::cout << intQue << std::endl;

	short a[4] = {1, 2, 3, 4};
	Queue<int> qi(a, a + 4);

	const char* s1 = "hello";
	const char* s2 ="world";
	int i1 = 1, i2 = 2;
	compare(s1, s2);
	compare(i1, i2);
	return 0;
}