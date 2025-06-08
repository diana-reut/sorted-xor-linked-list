#include <iostream>
#include "sortedXORList.h"
#include "IteratorSortedXORList.h"

int main()
{
	sortedXORList my_list;

	my_list.insert(10);
	my_list.insert(5);
	my_list.insert(7);
	my_list.insert(9);
	my_list.insert(4);

	IteratorSortedXORList it = my_list.iterator();

	it.first();
	while (it.valid())
	{
		std::cout << it.getCurrent() << " ";
		it.next();
	}

	return 0;
}