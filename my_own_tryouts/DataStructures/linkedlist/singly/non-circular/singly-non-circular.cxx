#include <iostream>

namespace ds
{
	namespace linkedlist
	{
		namespace singly
		{
			namespace non_circular
			{
				// definitions starting here...
				template<class T> Linkedlist<T>::Linkedlist()
				{
					nodes_count = 0;
					head = NULL;
				}

				template<class T> Linkedlist<T>::~Linkedlist()
				{
					std::cout << "\nDestroying object\n";
					if (is_empty())
						return;
					NODEPTR temp;

					for(temp = head->next; head != NULL; head = temp, (head != NULL) && (temp = head->next))
						delete head;
				}

				template<class T> void Linkedlist<T>::add(T data)
				{
					NODEPTR newnode;

					newnode = getnewnode();
					newnode->info = data;
					if (is_empty())
						head = newnode;
					else
					{
						NODEPTR temp;
						for(temp = head; temp->next != NULL; temp = temp->next);
						temp->next = newnode;
					}
					nodes_count++;
				}

				template<class T> void Linkedlist<T>::insert_at_position(int pos, T data)
				{
					NODEPTR newnode;
					newnode = getnewnode();
					newnode->info = data;

					if ((pos < 1) || (is_empty() && pos > 1) || (pos > size() + 2))
					{
						std::cout << "\nWrong position to insert into!";
						return;
					}

					if (pos == 1)
					{
						// new node should be the first one
						if (!is_empty())
							newnode->next = head;
						head = newnode;
					}
					else if (pos == size() + 1)
					{
						// insert node at the last
						NODEPTR temp;
						for (temp = head; temp->next != NULL; temp = temp->next);
						temp->next = newnode;
					}
					else if (pos > 1 && pos <= size())
					{
						NODEPTR temp;
						int count = 1;
						temp = head;
						while (count++ < pos - 1)
							temp = temp->next;
						newnode->next = temp->next;
						temp->next = newnode;
					}
					nodes_count++;
				}

				template<class T> void Linkedlist<T>::remove_at_position(int pos)
				{
					if ((is_empty()) || (pos < 1) || (pos > size()))
					{
						std::cout << "\nWrong position to remove from!";
						return;
					}
					if (pos == 1)
					{
						// removing the first node
						NODEPTR temp;
						temp = head;
						head = head->next;
						delete temp;
					}
					else
					{
						NODEPTR temp;
						temp = head;
						int count = 1;
						while (count ++ < pos - 1)
							temp = temp->next;
						NODEPTR temp2 = temp->next;
						temp->next = temp2->next;
						delete temp2;
					}
				}
			}
		}
	}
}
