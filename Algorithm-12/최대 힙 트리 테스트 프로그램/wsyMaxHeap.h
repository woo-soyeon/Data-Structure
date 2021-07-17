#include "wsyHeapNode.h"
#define MAX_ELEMENT 200
class MaxHeap {
	HeapNode node[MAX_ELEMENT];	// ����� �迭
	int size;	// ���� ���� ����� ����
public : 
	MaxHeap() : size(0) { }
	bool isEmpty() {
		return size == 0;
	}
	bool isFull() {
		return size == MAX_ELEMENT-1;
	}

	HeapNode& getParent(int i) {	// �θ� ���
		return node[i/2];
	}
	HeapNode& getLeft(int i) {		// ���� �ڽ� ���
		return node[i*2];
	}
	HeapNode& getRight(int i) {		// ������ �ڽ� ���
		return node[i*2+1];
	}
	// ���� �Լ� : ���� Ű�� key�� ���� ���ο� ��Ҹ� �����Ѵ�
	void insert(int key) {		
		if(isFull())		// ���� ���� �� ���
			return;
		int i = ++size;		// ������ �� ũ�� ��ġ���� ����

		// Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
		while(i != 1	// ��Ʈ�� �ƴϰ�
			&& key>getParent(i).getKey()) {		// �θ� ��庸�� Ű���� ũ��
			node[i] = getParent(i);		// �θ� �ڽų��� �����
			i /= 2;		// �� �캧 ���� ���
		}
		node[i].setKey(key);		// ���� ��ġ�� ������ ����
	}
	// ���� �Լ� : ���� ��Ʈ ��带 ��ȯ�ϰ� ���� �籸���Ѵ�.
	HeapNode remove() {		
		if(isEmpty())
			return NULL;
		HeapNode item = node[1];	// ��Ʈ���(���� ���)
		HeapNode last = node[size--];		// ���� ������ ���
		int parent = 1;		// ������ ����� ��ġ�� ��Ʈ�� ������
		int child = 2;		// ��Ʈ�� ���� �ڽ� ��ġ
		while(child <= size) {		// �� Ʈ���� ����� �ʴ� ����
			// ���� ����� �ڽ� ��� �� �� ū �ڽĳ�带 ã��
			if(child < size
				&& getLeft(parent).getKey() < getRight(parent).getKey())
				child++;		// child : �� ū �ڽ� ����� �ε���
			// ������ ��尡 �� ū �ڽĺ��� ũ�� ==> �̵��Ϸ�
			if(last.getKey() >= node[child].getKey()) break;

			// �ƴϸ� ==> �� �ܰ� �Ʒ��� �̵�
			node[parent] = node[child];
			parent = child;
			child *= 2;
		}
		node[parent] = last;		// ������ ��带 ���� ��ġ�� ����
		return item;		// ��Ʈ ��� ��ȯ
	}
	HeapNode find() {
		return node[1];
	}

	void display() {		// ���� ���� ��� �Լ�
		for(int i = 1, level = 1; i <= size; i++) {
			if(i == level) {
				printf("\n");
				level *= 2;
			}
			node[i].display();
		}
		printf("\n------------------------------------------");
	}
};