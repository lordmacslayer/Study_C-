#ifndef _TREE_H_
#define _TREE_H_

namespace ds
{
	namespace tree
	{
		template <class T> class Tree
		{
			public:
				Tree():root(0) 
				{}
				void add(T info);
//				void getCommonAncestor(T info1, T info2);
				void inorder();
				void preorder();
				void postorder();
			private:
				struct _tree
				{
					T info;
					struct _tree *left;
					struct _tree *right;

					void inorder();
					void preorder();
					void postorder();
					friend std::ostream& operator<<(std::ostream& out, const _tree * node)
					{
						out << " " << node->info << " ";
						return out;
					}
				};
				typedef struct _tree TREE;
				typedef struct _tree * TREEPTR;
				TREEPTR root;
				// inline
				TREEPTR getnode()
				{
					TREEPTR newnode = new TREE;
					if (newnode == 0)	// NULL check
						return 0;
					newnode->left = 0;
					newnode->right = 0;
					return newnode;
				}
		};

		template <class T> void Tree<T>::add(T info)
		{
			TREEPTR p;
			TREEPTR q;
			
			if (root == 0)
			{
				root = getnode();
				root->info = info;
			}
			p = q = root;
			while ((info != p->info) && (q != 0))
			{
				p = q;
				if (info < p->info)
					q = p->left;
				else
					q = p->right;

			}
			// either info == p->info OR q has got NULL
			if (info == p->info)
				std::cerr << "\nDuplicate number not allowed!";
			else
			{	
				TREEPTR newnode = getnode();
				if (newnode == 0)
					std::cerr << "\nFailed to insert the data \"" << info << "\": Couldn't allocate memory for new node!";
				else
				{
					newnode->info = info;
					if (info < p->info)
						p->left = newnode;
					else
						p->right = newnode;
				}
			}
		} // end of add

		template <class T> void Tree<T>::preorder()
		{
			std::cout << "Pre-order: ";
			root->preorder();
		}
		template <class T> void Tree<T>::inorder()
		{
			std::cout << "In-order: ";
			root->inorder();
		}
		template <class T> void Tree<T>::postorder()
		{
			std::cout << "Post-order: ";
			root->postorder();
		}
		template <class T> void Tree<T>::_tree::preorder()
		{
			TREEPTR temp = this;
			if (temp == 0)
				return;
			std::cout << temp;
			if (temp->left != 0)
				(temp->left)->preorder();
			if (temp->right != 0)
				(temp->right)->preorder();
		}
		template <class T> void Tree<T>::_tree::inorder()
		{
			TREEPTR temp = this;
			if (temp == 0)
				return;
			if (temp->left != 0)
				(temp->left)->inorder();
			std::cout << temp;
			if (temp->right != 0)
				(temp->right)->inorder();
		}
		template <class T> void Tree<T>::_tree::postorder()
		{
			TREEPTR temp = this;
			if (temp == 0)
				return;
			if (temp->left != 0)
				(temp->left)->postorder();
			if (temp->right != 0)
				(temp->right)->postorder();
			std::cout << temp;
		} // end of post order
	}	// ns tree
}// ns ds
#endif
