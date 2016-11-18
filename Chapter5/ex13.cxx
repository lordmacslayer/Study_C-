#include <iostream>

typedef struct Date
{
		int dd;
		int mm;
		int yy;
}DATE;

// validate date
bool validateDate(int dd, int mm, int yy)
{
	if (mm <= 0 || mm >12 || dd <= 0 || yy <= 0)
		return false;
	switch (mm)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return (dd <= 31);
			break;
		case 2:
			if (yy % 4 == 0)
				return (dd <= 29);
			else
				return (dd <= 28);
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			return (dd <= 30);
			break;
		default:
			return false;
	}
}

// init a date
void initDate(DATE *date, int d, int m, int y)
{
	if (validateDate(d, m, y))
	{
		date->dd = d;
		date->mm = m;
		date->yy = y;
	}
	else
	{
		std::cout << "\nWrong date entered!";
	}
}

void acceptDate(DATE *date)
{
	std::cout << "\nEnter the day: ";
	int  d;
	std::cin >> d;
	std::cout << "\nEnter the month: ";
	int m;
	std::cin >> m;
	std::cout << "\nEnter the year: ";
	int y;
	std::cin >> y;

	initDate(date, d, m, y);
}

void printDate(const DATE *date)
{
	if (date != 0)
	{
		std::cout << std::endl;
		std::cout << date->dd << "/" << date->mm << "/" << date->yy;
	}
	else
		std::cerr << "\nDate object passed to displayDate is NULL!";
}

int main(void)
{
	DATE d1, d2, d3;

	initDate(&d1, 31, 10, 2016);
	acceptDate(&d2);
	d3 = d2;

	printDate(&d1);
	printDate(&d2);
	printDate(&d3);
	std::cout << std::endl;
	return 0;
}
