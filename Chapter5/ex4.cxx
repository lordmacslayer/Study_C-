#include <iostream>

int main(void)
{
	void swap(int *, int *);
	std::cout << "\nEnter the values of 2 integers: ";
	int n1, n2;
	std::cin >> n1 >> n2;
	swap(&n1, &n2);
	std::cout << "\nThe values of swapped integers: " << n1 << ' ' << n2;
	std::cout << '\n';
	return 0;
}

void swap(int *n1, int *n2)
{
	*n1 = *n1 + *n2;
	*n2 = *n1 - *n2;
	*n1 -= *n2;
}
