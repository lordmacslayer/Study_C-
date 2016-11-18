#include <iostream>
#include "singly-non-circular.hxx"

using namespace ds::linkedlist::singly::non_circular;
int main(void)
{
	Linkedlist<char> clist;
	clist.add('a');
	clist.add('b');
	clist.add('c');
	clist.display();
	clist.insert_at_position(1, 's');
	clist.insert_at_position(5, 'i');
	clist.insert_at_position(3, 'd');
	clist.display();
	clist.remove_at_position(3);
	clist.display();
	clist.remove_at_position(9);
	clist.remove_at_position(5);
	clist.display();

	Linkedlist<std::string> slist;
	slist.add("siddharth");
	slist.add("bhise");
	slist.display();
	slist.insert_at_position(2, "manoj");
	slist.display();
	slist.insert_at_position(10, "family");
	slist.insert_at_position(4, "family");
	slist.display();
	slist.remove_at_position(1);
	slist.display();
	
	Linkedlist<int> ilist;
	ilist.add(100);
	ilist.remove_at_position(1);
	ilist.display();
	std::cout << std::endl;
	return 0;
}
