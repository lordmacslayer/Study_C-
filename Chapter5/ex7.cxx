#include <iostream>

int main(void)
{
	char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	typedef struct calendar
	{
		char *month;
		int days;
	}CAL;

	CAL cal[12];

	for(int i = 0; i < 12; ++i)
	{
		std::cout << days[i] << ' ' << months[i] << '\n';
		cal[i].month = months[i];
		cal[i].days = days[i];
	}	

	for (int i = 0; i < 12; ++i)
	{
		std::cout << "FROM STRUCT\t" << cal[i].days << ' ' << cal[i].month << '\n';
	}

	std::cout << '\n';
	return 0;
}
