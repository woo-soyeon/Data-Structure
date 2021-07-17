#include <cstdio>
#include <cstdlib>
#define MAX_QUEUE_SIZE 100


struct Customer {
	int id;	// 고객 변호
	int tArrival;	// 고객이 도착한 시각
	int tService;	// 이 고객의 서비스에 필요한 시간
	Customer(int i = 0, int tArr = 0, int tServ = 0)
		: id(i), tArrival(tArr), tService(tServ) {}
};

inline void error (char *str) {
	printf("%s\n", str);
	exit(1);
}

class CustomerQueue {
protected :
	int front;	// 첫번째 요소 위치
	int rear;	// 마지막 요소 위치
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
	void enqueue(Customer val) {	// 큐에 삽입
		if(isFull())
			error("error : 큐가 포화상태입니다. \n");
		else {
			rear = (rear + 1) %MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}
	Customer dequeue() {	// 첫 항목을 큐에서 빼서 반환
		if(isEmpty())
			error("error : 큐가 공백상태입니다. \n");
		else {
			front = (front + 1) %MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	Customer peek() {	// 첫 항목을 큐에서 빼지 않고 반환
		if(isEmpty())
			error("error : 큐가 공백상태입니다. \n");
		else
			return data[(front + 1) % MAX_QUEUE_SIZE];
	}
};





