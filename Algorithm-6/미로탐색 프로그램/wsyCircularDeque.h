#include "wsyCircularQueue.h"

class CircularDeque : public CircularQueue {
public :
	CircularDeque() { }
	void addRear(Element val) {
		enqueue(val);	// enqueue() 호출
	}
	Element deleteFront() {
		return dequeue();	// dequeue() 호출
	}
	Element getFront() {
		return peek();	// peek() 호출
	}
	void addFront(Element val) {	// 전단에 삽입
		if(isFull())
			error("error : 덱이 포화상태입니다\n");
		else {
			data[front] = val;
			front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		}
	}
	Element deleteRear() {	// 후단에서 삭제
		if(isEmpty())
			error("error : 덱이 공백상태입니다\n");
		else {
			Element ret = data[rear];
			rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
			return ret;
		}
	}
	Element getRear() {	// 후단에서 peek
		if(isEmpty())
			error("error : 덱이 공백상태입니다.\n");
		else return data[rear];
	}
	void display() {	// CircularQueue::display()를 재정의
		printf("덱의 내용 : ");	// 이 출력코드만 다름
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
		for(int i = front + 1; i <= maxi; i++)
			printf("[%2d]", data[i % MAX_QUEUE_SIZE]);
		printf("\n");
	}
};
