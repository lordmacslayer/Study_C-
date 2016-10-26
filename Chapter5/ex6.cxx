#include <iostream>

int main(void)
{
	char cc = 'a';
	unsigned char uc = 49;
	signed char sc = 3300;

	void f(char), g(char&), h(const char&);

	f('a'); 	// legal 
	g('a');		// illegal	temporary
	h('a');		// legal	temporary

	f(49);		// legal
	g(49);		// illegal	temporary
	h(49);		// legal temporary

	f(3300);	// illegal, warning! 
	g(3300);	// illegal temporary
	h(3300);	// illegal	temporary, warning!

	f(cc);		// legal
	g(uc);		// illegal
	h(sc);		// illegal, warning (but not shown, same as h(3300))

	std::cout << '\n';
	return 0;
}

void f(char arg)
{
	std::cout << "\nInside function f() with arg = " << arg;
}

void g(char& arg)
{
	std::cout << "\nInside function g() with arg = " << arg;
}

void h(const char& arg)
{
	std::cout << "\nInside function h() with arg = " << arg;
}
/*
ex6.cxx:12:4: error: non-const lvalue reference to type 'char' cannot bind to a temporary of type 'char'
        g('a');
          ^~~
ex6.cxx:9:23: note: passing argument to parameter here
        void f(char), g(char&), h(const char&);
                             ^
ex6.cxx:16:4: error: non-const lvalue reference to type 'char' cannot bind to a temporary of type 'int'
        g(49);
          ^~
ex6.cxx:9:23: note: passing argument to parameter here
        void f(char), g(char&), h(const char&);
                             ^
ex6.cxx:20:4: error: non-const lvalue reference to type 'char' cannot bind to a temporary of type 'int'
        g(3300);
          ^~~~
ex6.cxx:9:23: note: passing argument to parameter here
        void f(char), g(char&), h(const char&);
                             ^
ex6.cxx:24:4: error: non-const lvalue reference to type 'char' cannot bind to a value of unrelated type 'unsigned char'
        g(uc);
          ^~
ex6.cxx:9:23: note: passing argument to parameter here
        void f(char), g(char&), h(const char&);
                             ^
ex6.cxx:7:19: warning: implicit conversion from 'int' to 'signed char' changes value from 3300 to -28 [-Wconstant-conversion]
        signed char sc = 3300;
                    ~~   ^~~~
ex6.cxx:19:4: warning: implicit conversion from 'int' to 'char' changes value from 3300 to -28 [-Wconstant-conversion]
        f(3300);
        ~ ^~~~
ex6.cxx:21:4: warning: implicit conversion from 'int' to 'const char' changes value from 3300 to -28 [-Wconstant-conversion]
        h(3300);
        ~ ^~~~
3 warnings and 4 errors generated.
*/
