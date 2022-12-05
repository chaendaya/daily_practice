#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class my_queue {

private:
	int q_size;
	Node* head;
	Node* tail;

public:
	my_queue() {
		q_size = 0;
		head = tail = NULL;
	}
	~my_queue() {}

	void Enqueue(int x)
	{
		Node* newNode = new (Node);
		newNode->data = x;

		if (tail != NULL) {
			tail->next = newNode;
			tail = newNode;	
		}
		else {
			head = tail = newNode;
		}
		q_size++;
		cout << "q ������ : " << q_size << endl;
	};

	void Dequeue()
	{
		if (q_size != 0) {
			
			Node* delNode = head;
			head = head->next;
			delete delNode;
			q_size--;
		}
		else
			cout << "ť�� ����ֽ��ϴ�." << endl;
	};

	void Peek() {
		if (q_size != 0)
			cout<< head->data << endl;
		else {
			cout << "head�� �����ϴ�." << endl;
		}
	};
};

int main()
{
	my_queue q;

	q.Enqueue(10);	// 10 �ֱ�
	q.Enqueue(20);	// 20 �ֱ�
	q.Enqueue(30);	// 30 �ֱ�

	q.Peek();		// 10 ������
	q.Dequeue();	// 10 ����
	q.Peek();		// 20 ������
	q.Dequeue();	// 20 ����
	q.Peek();		// 30 ������
	q.Dequeue();	// 30 ����

	q.Peek();		// head ���� ���
	q.Dequeue();	// queue ����� ���
}
