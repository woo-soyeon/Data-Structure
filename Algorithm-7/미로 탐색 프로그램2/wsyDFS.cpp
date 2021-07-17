//#pragma once
//#include <stdio.h>
//#include "wsyLinkedStack.h"
//
//const int MAZE_SIZE = 6;	// �̷� �� ũ�� ����
//char map[MAZE_SIZE][MAZE_SIZE] = {	// �̷� �� ������
//	{'1', '1', '1', '1', '1', '1'},
//	{'e', '0', '1', '0', '0', '1'},
//	{'1', '0', '0', '0', '1', '1'},
//	{'1', '0', '1', '0', '1', '1'},
//	{'1', '0', '1', '0', '0', 'x'},
//	{'1', '1', '1', '1', '1', '1'}
//};
//
//// (r, c)�� �� �� �ִ� ��ġ������ �˻��ϴ� �Լ�
//// (r, c)�� �迭 �ȿ� �ְ�, ���� �� ���ִ� ��ġ '0'�̰ų� �ⱸ 'x'�̾�� ��
//bool isValidLoc(int r, int c) {
//	if(r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE)
//		return false;
//	else return map[r][c] == '0' || map[r][c] == 'x';
//}
//
//void main() {
//	LinkedStack locStack;
//	Location2D entry(1,0);	// �Ա� ��ü
//	Node *n = new Node(entry);
//	locStack.push(n);	// ���� �Ա� ��ġ ����
//
//	while(locStack.isEmpty() == false) {	// ���� ������� �ʴ� ����
//		n = locStack.pop();
//		Location2D here(n->row, n->col);	// ���� front ��� ��ü ����
//		delete n;
//
//		int r = here.row;
//		int c = here.col;
//		printf("(%d,%d)", r, c);	// ���� ��ġ�� ȭ�鿡 ���
//		if(map[r][c] == 'x') {	// �ⱸ�̸� -> Ž�� ����
//			printf("�̷� Ž�� ����\n");
//			return;
//		}
//		else {
//			map[r][c] = '.';	// ������ġ�� "������" ó��
//			if(isValidLoc(r - 1, c))
//				locStack.push(new Node(Location2D(r - 1, c)));
//			if(isValidLoc(r + 1, c))
//				locStack.push(new Node(Location2D(r + 1, c)));
//			if(isValidLoc(r, c - 1))
//				locStack.push(new Node(Location2D(r, c - 1)));
//			if(isValidLoc(r, c + 1))
//				locStack.push(new Node(Location2D(r, c + 1)));
//		}
//
//	}
//	printf("�̷�Ž������\n");
//}
