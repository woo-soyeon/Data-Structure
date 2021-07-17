#include "wsyCircularQueue.h"

class CircularDeque : public CircularQueue {
public :
	CircularDeque() { }
	void addRear(Element val) {
		enqueue(val);	// enqueue() ȣ��
	}
	Element deleteFront() {
		return dequeue();	// dequeue() ȣ��
	}
	Element getFront() {
		return peek();	// peek() ȣ��
	}
	void addFront(Element val) {	// ���ܿ� ����
		if(isFull())
			error("error : ���� ��ȭ�����Դϴ�\n");
		else {
			data[front] = val;
			front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		}
	}
	Element deleteRear() {	// �Ĵܿ��� ����
		if(isEmpty())
			error("error : ���� ��������Դϴ�\n");
		else {
			Element ret = data[rear];
			rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
			return ret;
		}
	}
	Element getRear() {	// �Ĵܿ��� peek
		if(isEmpty())
			error("error : ���� ��������Դϴ�.\n");
		else return data[rear];
	}
	void display() {	// CircularQueue::display()�� ������
		printf("���� ���� : ");	// �� ����ڵ常 �ٸ�
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
		for(int i = front + 1; i <= maxi; i++)
			printf("[%2d]", data[i % MAX_QUEUE_SIZE]);
		printf("\n");
	}
};
