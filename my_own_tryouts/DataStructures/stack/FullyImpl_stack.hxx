#ifndef _STACK_GENERIC_H_
#define _STACK_GENERIC_H_

#include <iostream>

namespace ds
{
	namespace stack
	{
		template<class T> class Stack
		{
			T* v;
			int max_size;
			int top;

			public:
			class Underflow {};
			class Overflow {};

			// constructor
			Stack(int s);
			// destructor
			~Stack();

			void push(T);
			T pop();
		};

		template<class T> void Stack<T>::push(T element)
		{
			if (top == max_size) throw Overflow();
			v[top] = element;
			++top;
		} 

		template<class T> T Stack<T>::pop()
		{   
			if (top == 0) throw Underflow();
			return v[--top];
		}   

		// constructor
		template<class T> Stack<T>::Stack(int size)
		{
			top = 0;
			max_size = size;
			v = new T[size];
			if (v == NULL)
			{
				std::cout << "\nMemory allocation for the buffer failed.";
				exit(1);
			}
		}	

		template<class T> Stack<T>::~Stack()
		{
			delete v;
		}



	}
}

#endif
