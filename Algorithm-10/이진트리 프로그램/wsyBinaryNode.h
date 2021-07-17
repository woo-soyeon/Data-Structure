#pragma once
#include <cstdio>

class BinaryNode {

public :
	int data;	// 트리에 저장할 데이터
	BinaryNode* left;	// 왼쪽 자식 노드의 포인터
	BinaryNode* right;	// 오른쪽 자식 노드의 포인터
	BinaryNode* root;	

	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL)
		: data(val), left(l), right(r) { }
	bool isLeaf() {
		return left == NULL && right == NULL;
	}
	bool isEmpty() {
      return root == NULL;
   }

	// 이진트리의 inorder 순회 연산
    void inorder(BinaryNode *node) {		// 순환적인 트리의 순회 함수
      if(node != NULL) {
         inorder(node -> left);
         printf(" [%c] ", node -> data);
         inorder(node -> right);
      }
   }

   // 이진트리의 preorder 순회 연산
  void preorder(BinaryNode *node) {	// 순환적인 트리의 순회 함수
      if(node != NULL) {
         printf(" [%c] ", node -> data);
         if(node -> left != NULL) preorder(node -> left);
         if(node -> right != NULL) preorder(node -> right);
      }
   }

   // 이진트리의 postorder 순회 연산
   void postorder(BinaryNode *node) {	// 순환적인 트리의 순회 함수
      if(node != NULL) {
         if(node -> left != NULL) postorder(node -> left);
         if(node -> right != NULL) postorder(node -> right);
         printf(" [%c] ", node -> data);
      }
   }



   // 트리의 노드 개수를 구하는 함수
   
   // 순환 호출에 의해 node를 루트로 하는 서브트리의 노드 수 계산 함수
   int getCount(BinaryNode *node) {
      if(node == NULL)
         return 0;
      return 1 + getCount(node -> left) + getCount(node -> right);
   }

   // 트리의 높이를 구하는 함수
   
   // 순환 호출에 의해 node를 루트로 하는 서브트리의 높이 계산 함수
   int getHeight(BinaryNode *node) {
      if(node == NULL)
         return 0;
      int hLeft = getHeight(node -> left);
      int hRight = getHeight(node -> right);
      return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
      }
   
   // 트리의 단말노드 개수를 구하는 함수
   
   // 순환 호출에 의해 node를 루트로 하는 서브트리의 단말 노드 수 계산 함수
   int getLeafCount(BinaryNode *node) {
      if(node == NULL) return 0;
      if(node -> isLeaf()) return 1;
      else return getLeafCount(node -> left) + getLeafCount(node -> right);
   }
};