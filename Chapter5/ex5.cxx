#include <iostream>
#include <string.h>

int main(void)
{
	char str[] = "a short string";
	std::cout << "Size of the str[] = " << sizeof(str);
	std::cout << "\nLength of the str[] = " << strlen(str);
	std::cout << '\n';
	return 0;
}
