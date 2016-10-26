#include <iostream>
#include <vector>

int main(void)
{
	std::cout << "\nStart entering the strings, 'Quit' to quit!\n";
	std::string str = "";
	std::vector<std::string> v;
	std::cin >> str;
	while (str != "Quit")
	{
		v.push_back(str);
		std::cin >> str;
	}
	std::cout << "\nPresenting Strings as entered!\n";
	for(std::vector<std::string>::const_iterator i = v.begin(); i != v.end(); ++i)
		std::cout << '\n' << *i;

	std::cout << "\n\nDuplicates removed, and inserted order!\n";
	std::ostream_iterator<std::string> oo(std::cout, "\n");
	unique_copy(v.begin(), v.end(), oo);	// should print directly to cout and delimeter should be \n

	// sorted order
	std::cout << "\n\nSorted values\n";
	sort(v.begin(), v.end());
	unique_copy(v.begin(), v.end(), oo);

	std::cout << '\n';
	return 0;
}
