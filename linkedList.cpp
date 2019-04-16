#include <iostream>

using namespace std;

struct node
{
	int val;
	node *next;
};

class linked_list
{
private:
	node *head, *tail;
public:
	linked_list()
	{
		head = NULL;
		tail = NULL;
	}

	void addNode(int n)
	{
		node *tmp = new node;
		tmp->val = n;
		tmp->next = NULL;

		if (head == NULL)
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			tail->next = tmp;
			tail = tail->next;
		}
	}

	void delNode(
		int delVal,
		bool delAll=true) // default to delete all matched values
	{
		node *tmp = head;
		node *prev = NULL;

		while (NULL != tmp)
		{
			if (tmp->val == delVal)
			{
				if (NULL == prev) // it is the head
				{
					node *tmp_head = head;
					head = tmp;

					if (NULL == tmp_head->next) // the only node
						tail = NULL;

					tmp = head = head->next;
					delete tmp_head;
				}
				else
				{
					prev->next = tmp->next;
					delete tmp;
					tmp = prev->next;

					if (NULL == tmp)
						tail = prev;
				}

				if (false == delAll) // only wants to delete one matched node
					break;
			}
			else
			{
				prev = tmp;
				tmp = tmp->next;
			}
		}
	}

	void traverse()
	{
		node *tmp = this->head;
		while (NULL != tmp)
		{
			cout << tmp->val << " ";
			tmp = tmp->next;

		}
		cout << endl;
	}
};

int main()
{
	linked_list a;
	a.addNode(1);
	a.addNode(2);
	a.addNode(3);
	a.addNode(2);
	a.addNode(4);

	//a.delNode(1);
	// a.delNode(2);
	 a.delNode(2, false);
	//a.delNode(4);

	a.traverse();
	return 0;
}

//////////////////////////////////////////////////////////////
//
// Sample Output:
//
// 1 3 2 4
