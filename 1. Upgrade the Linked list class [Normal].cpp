// 1. Upgrade the Linked list class [Normal]
#include <iostream>
using namespace std;

struct Node {	// 노드 구조
	int data;
	Node* next;
	Node* prev;
};

class my_list {
private:
	int length, index;	// length:리스트 길이	index:현재 가리키는 노드의 인덱스 
	Node* head;
	Node* current;
	Node* tail;

public:
	my_list() :length(0), index(0), head(NULL), current(NULL), tail(NULL) {}

	my_list& append(int data) {
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;

		if (tail != NULL) {
			newNode->prev = tail;
			tail = tail->next = newNode;
		}
		else {
			newNode->prev = NULL;
			head = current = tail = newNode;
		}
		length++;
		return *this;
	}

	my_list& append(my_list& l) {
		l.head->prev = tail;
		tail->next = l.head;
		tail = l.tail;

		length += l.length;
		return *this;
	}

	my_list& next() {
		current = current->next;
		index++;
		return *this;
	}

	int get() { return current->data; }
	void rewind() { current = head; index = 0; }
	void info() { cout << "length : " << length << " \tcurrent : " << index << endl; }

	// append as an operator
	my_list& operator+(int value) {
		return append(value);
	}

	// concatenate a list
	my_list& operator+(my_list& l) {
		return append(l);
	}

	// remove a 'n'-th node
	my_list& operator-(int n) {

		if (n == 0) {	// 0번째, 즉 head를 삭제할 때
			Node* delNode = head;	// head가 가리키는 노드의 주소를 복사
			head = head->next;
			head->prev = NULL;
			delete delNode;
		}
		else if (n > 0) {	// n(양수)번째 노드를 삭제할 때
			Node* delNode = head;
			for (int i = 0; i < n; i++) {
				delNode = delNode->next;
			}
			(delNode->prev)->next = delNode->next;
			delete delNode;
		}
		else if (n < 0) {	// n(음수)번째 노드를 삭제할 때
			Node* delNode = tail;
			for (int i = n; i < -1; i++) {
				delNode = delNode->prev;
			}
			(delNode->prev)->next = delNode->next;
			delete delNode;
		}
		length--;
		return *this;
	}

	void printall() {
		Node* loop;
		cout << "list : ";
		for (loop = head; loop != NULL; loop = loop->next) {
			cout << "[" << loop->data << "]" << " ";
		}
		cout << endl << "index : ";
		for (int i = 0; i < length; i++) {
			cout << i << "     ";
		}
		cout << endl;
	}
};

int main() {
	my_list l;
	my_list ll;

	l.append(10).append(20).append(30).append(40);
	l.next().next();
	cout << l.get() << endl;

	ll = ll + 100 + 200 + 300;
	ll.next();
	cout << ll.get() << endl;

	ll = ll + l;
	ll.printall();

	ll.next().next().next();
	cout << ll.get() << endl;

	ll = ll - -2;
	ll.next();
	cout << ll.get() << endl;
	ll.printall();
}