#include <iostream>
#include <algorithm>

int count(const std::string& input, const std::string& pattern)
{
	int count = 0;
	std::string str = input;
	int pos;
	while ((pos = str.find(pattern)) != std::string::npos)
	{
		++count;
		str.erase(pos, pattern.length());
	}
	return count;
}

int count(const char *input, const char *pattern)
{
	int count = 0;
	int diff = strlen(input) - strlen(pattern);
	std::cout << "\nCalculating C-Style!\n";
	for (int i = 0; i <= diff; ++i)
	{
		if (input[i] == pattern[0])
		{
			int j, ip;
			for (j = 1, ip = i+1; pattern[j] != '\0'; j++, ip++)
			{
				if (input[ip] != pattern[j])
				{
					break;
				}	
			}
			if (pattern[j] == '\0') 	// this means that the inner for loop found a substring.
			{
				++count;
				i = ip - 1;
				continue;
			}
		}
	}
	return count;
}	

int main(void)
{
	std::string str_input;
	std::cout << "\nEnter the input string: ";
	std::cin >> str_input;

	std::string str_pattern;
	std::cout << "\nEnter the pattern that is supposed to be searched in \"" << str_input << "\": ";
	std::cin >> str_pattern;

	std::cout << "\nOccurrences of the string \"" << str_pattern << "\" in the string \"" << str_input << "\" is " << count(str_input, str_pattern) << " time(s)";
	std::cout << "\nNow trying with char * from C! ... ";
	char inp_cstr[2048];
	std::cout << "Enter the string. I am going to store it in C-style!: ";
	std::cin >> inp_cstr;
	std::cout << "\nEnter the pattern that you want to search in the C-style string: ";
	char pat_cstr[2048];
	std::cin >> pat_cstr;
	std::cout << "\nOccurrences of the C-style string \"" << pat_cstr << "\" in the C-style string \"" << inp_cstr << "\" is " << count(inp_cstr, pat_cstr) << " time(s)";
	std::cout << "\n";
	return 0;
}
