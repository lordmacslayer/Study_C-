#ifndef _SINGLY_NON_CIRCULAR_H_
#define _SINGLY_NON_CIRCULAR_H_

namespace ds
{
	namespace linkedlist
	{
		namespace singly
		{
			namespace non_circular
			{
				template<class T> class Linkedlist
				{
					protected:
						struct node
						{
							T info;
							struct node *next;
						};
						typedef struct node * NODEPTR;
						typedef struct node NODE;

						NODEPTR head;
						int nodes_count;

						NODEPTR getnewnode()
						{
							NODEPTR newnode;
							newnode = new NODE;
							if (newnode == NULL)
							{
								std::cout << "\nFailed to allocate memory for new node!";
								exit(1);
							}
							newnode->next = NULL;
							return newnode;
						}

					public:
						// constructor and destructor
						Linkedlist();
						~Linkedlist();
						bool is_empty()	{ return head == NULL; }
						int size() { return nodes_count; } // returns the number of nodes
						void add(T data);
						void insert_at_position(int pos, T data);
						void remove_at_position(int pos);
						
						void display()
						{
							NODEPTR temp;
							std::cout << '\n';
							if (is_empty())
							{
								std::cout << "\nThe list is empty!\n";
								return;
							}
							std::cout << "Displaying...\n";
							for (temp = head; temp != NULL; temp = temp->next)
							{
								std::cout << ' ' << temp->info << ' ';
							}
							std::cout << '\n';
						}
				};
			}
		}
	}
}

#ifndef _SINGLY_NON_CIRC_IMPL_
#define _SINGLY_NON_CIRC_IMPL_
#include "singly-non-circular.impl"
#endif

#endif
