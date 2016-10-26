#include <iostream>

int main(void)
{
	std::string strarr[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	void print_months(std::string (&)[12]);

	print_months(strarr);
	std::cout << '\n';
	return 0;
}

void print_months(std::string (&str)[12])
{
	for(int i = 0; i < 12; i++)
	{
		std::cout << '\n' << str[i];
	}
}
