#include "wsyLocation2D.h"
#include <cstdio>
#include <cstdlib>

#define MAX_QUEUE_SIZE 100

inline void error(char* str) {
	printf("%s\n", str);
	exit(1);
}

typedef Location2D Element;	// 스택에 저장할 항목을 Location2D로 선언함

class CircularQueue {
protected : 
	int front;	// 첫번째 요소 앞의 위치
	int rear;	// 마지막 요소 위치
	Element data[MAX_QUEUE_SIZE];	// 요소의 배열
public :
	CircularQueue() {
		front = rear = 0;
	}
	bool isEmpty() {
		return front == rear;
	}
	bool isFull() {
		return (rear + 1) % MAX_QUEUE_SIZE == front;
	}
	void enqueue(Element val) {	// 큐에 삽입
		if(isFull())
			error("error : 큐가 포화상태입니다.\n");
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}
	Element dequeue() {	// 첫 항목을 큐에서 뺴서 반환
		if(isEmpty())
			error("error : 큐가 공백상태입니다.\n");
		else {
			 front = (front + 1) % MAX_QUEUE_SIZE;
			 return data[front];
		}
	}
	Element peek() {	// 첫 항목을 큐에서 뺴지 않고 반환
		if(isEmpty())
			error("error : 큐가 공백상태입니다.\n");
		else
			return data[(front + 1) % MAX_QUEUE_SIZE];
	}
	void display() {	// 큐의 모든 내용을 순서대로 출력
		printf("큐 내용 : ");
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
		for(int i = front + 1; i <= maxi; i++)
			data[i % MAX_QUEUE_SIZE].print();	// 변경
		printf("\n");
	}
};
