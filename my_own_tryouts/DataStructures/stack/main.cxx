#include <iostream>
#include "stack.hxx"

using namespace ds::stack;

int main(void)
{
	Stack<char> sc(3);		// stack of 300 characters
	sc.push('a');
	sc.push('b');
	sc.push('c');
	sc.push('c');

	for (int i = 0; i < 3; ++i)
	{
		std::cout << "\npopped ==> " << sc.pop();
	}
	std::cout << std::endl;
	return 0;
}
