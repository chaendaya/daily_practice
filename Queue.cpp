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
		cout << "q 사이즈 : " << q_size << endl;
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
			cout << "큐가 비어있습니다." << endl;
	};

	void Peek() {
		if (q_size != 0)
			cout<< head->data << endl;
		else {
			cout << "head가 없습니다." << endl;
		}
	};
};

int main()
{
	my_queue q;

	q.Enqueue(10);	// 10 넣기
	q.Enqueue(20);	// 20 넣기
	q.Enqueue(30);	// 30 넣기

	q.Peek();		// 10 꺼내기
	q.Dequeue();	// 10 삭제
	q.Peek();		// 20 꺼내기
	q.Dequeue();	// 20 삭제
	q.Peek();		// 30 꺼내기
	q.Dequeue();	// 30 삭제

	q.Peek();		// head 없음 출력
	q.Dequeue();	// queue 비었음 출력
}
