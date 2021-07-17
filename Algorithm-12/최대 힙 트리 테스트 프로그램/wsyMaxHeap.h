#include "wsyHeapNode.h"
#define MAX_ELEMENT 200
class MaxHeap {
	HeapNode node[MAX_ELEMENT];	// 요소의 배열
	int size;	// 힙의 현재 요소의 개수
public : 
	MaxHeap() : size(0) { }
	bool isEmpty() {
		return size == 0;
	}
	bool isFull() {
		return size == MAX_ELEMENT-1;
	}

	HeapNode& getParent(int i) {	// 부모 노드
		return node[i/2];
	}
	HeapNode& getLeft(int i) {		// 왼쪽 자식 노드
		return node[i*2];
	}
	HeapNode& getRight(int i) {		// 오른쪽 자식 노드
		return node[i*2+1];
	}
	// 삽입 함수 : 힙에 키값 key를 갖는 새로운 요소를 삽입한다
	void insert(int key) {		
		if(isFull())		// 힙이 가득 찬 경우
			return;
		int i = ++size;		// 증가된 힙 크기 위치에서 시작

		// 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
		while(i != 1	// 루트가 아니고
			&& key>getParent(i).getKey()) {		// 부모 노드보다 키값이 크면
			node[i] = getParent(i);		// 부모를 자신노드로 끌어내림
			i /= 2;		// 한 헤벨 위로 상승
		}
		node[i].setKey(key);		// 최종 위치에 데이터 복사
	}
	// 삭제 함수 : 힙의 루트 노드를 반환하고 힙을 재구성한다.
	HeapNode remove() {		
		if(isEmpty())
			return NULL;
		HeapNode item = node[1];	// 루트노드(꺼낼 요소)
		HeapNode last = node[size--];		// 힙의 마지막 노드
		int parent = 1;		// 마지막 노드의 위치를 루트로 생각함
		int child = 2;		// 루트의 왼쪽 자식 위치
		while(child <= size) {		// 힙 트리를 벗어나지 않는 동안
			// 현재 노드의 자식 노드 중 더 큰 자식노드를 찾음
			if(child < size
				&& getLeft(parent).getKey() < getRight(parent).getKey())
				child++;		// child : 더 큰 자식 노드의 인덱스
			// 마지막 노드가 더 큰 자식보다 크면 ==> 이동완료
			if(last.getKey() >= node[child].getKey()) break;

			// 아니면 ==> 한 단계 아래로 이동
			node[parent] = node[child];
			parent = child;
			child *= 2;
		}
		node[parent] = last;		// 마지막 노드를 최종 위치에 저장
		return item;		// 루트 노드 반환
	}
	HeapNode find() {
		return node[1];
	}

	void display() {		// 히프 내용 출력 함수
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