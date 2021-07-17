#include <cstdio>
#include <cstdlib>
#define MAX_QUEUE_SIZE 100


struct Customer {
	int id;	// �� ��ȣ
	int tArrival;	// ���� ������ �ð�
	int tService;	// �� ���� ���񽺿� �ʿ��� �ð�
	Customer(int i = 0, int tArr = 0, int tServ = 0)
		: id(i), tArrival(tArr), tService(tServ) {}
};

inline void error (char *str) {
	printf("%s\n", str);
	exit(1);
}

class CustomerQueue {
protected :
	int front;	// ù��° ��� ��ġ
	int rear;	// ������ ��� ��ġ
	Customer data[MAX_QUEUE_SIZE];
public :
	CustomerQueue() {
		front = rear = 0;
	}
	bool isEmpty() {
		return front == rear;
	}
	bool isFull() {
		return (rear + 1) %MAX_QUEUE_SIZE == front;
	}
	void enqueue(Customer val) {	// ť�� ����
		if(isFull())
			error("error : ť�� ��ȭ�����Դϴ�. \n");
		else {
			rear = (rear + 1) %MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}
	Customer dequeue() {	// ù �׸��� ť���� ���� ��ȯ
		if(isEmpty())
			error("error : ť�� ��������Դϴ�. \n");
		else {
			front = (front + 1) %MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	Customer peek() {	// ù �׸��� ť���� ���� �ʰ� ��ȯ
		if(isEmpty())
			error("error : ť�� ��������Դϴ�. \n");
		else
			return data[(front + 1) % MAX_QUEUE_SIZE];
	}
};





