#pragma once
#include "wsyBinaryNode.h"
#include <stdlib.h>

inline void error(char* str) {
   fprintf(stderr, "%s\n", str);
   exit(1);
};
#define MAX_QUEUE_SIZE 100

class CircularQueue {
   int front;	// ù���� ��� ���� ��ġ
   int rear;	// ������ ��� ��ġ
   BinaryNode* data[MAX_QUEUE_SIZE];	//����� �迭
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
   void enqueue(BinaryNode* n) {	// ť�� ����
      if(isFull()) error(" Error : ť�� ��ȭ�����Դϴ�.\n");
      else {
         rear = (rear + 1) % MAX_QUEUE_SIZE;
         data[rear] = n;
      }
   }
   BinaryNode* dequeue() {		// ù �׸��� ť���� ���� ��ȯ
      if(isEmpty()) error(" Error : ť�� ��������Դϴ�\n");
      else {
         front = (front + 1) % MAX_QUEUE_SIZE;
         return data[front];
      }
   }
};