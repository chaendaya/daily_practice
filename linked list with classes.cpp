#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};


class my_list
{
private:
	int size;
	int count;
	Node* head, *tail, *current;

public:
	my_list() {
		size = 0;
		count = 0;
		head = tail = current = NULL;
	}
	~my_list() {}

	my_list& append(int x)
	{
		Node* newNode = new(Node);
		newNode->data = x;

		if (tail != NULL) {
			tail->next = newNode;
			tail = newNode;
		}
		else {
			head = tail = newNode;
			current = head;
			count = 1;
		}
		size++;
		return *this;
	}
	
	my_list& next()
	{
		current = current->next;
		count++;
		return *this;
	}
	int get()
	{
		return current->data;
	}
	my_list& rewind()
	{
		current = head;
		return *this;
	}
	void info()
	{
		cout << "length : " << size << "\t" << "current : " << count << endl;
	}
};

int main()
{
	my_list l;

	l.append(10).append(20).append(30).append(40);

	l.next().next();
	cout << l.get() << endl;

	l.info();

	l.rewind();
	cout << l.get() << endl;
}