#pragma once
#include "wsyBinaryNode.h"
#include "wsyCircularQueue.h"
#include <stdlib.h>

class BinaryTree : public BinaryNode {
   BinaryNode* root;
public :
   BinaryTree() : root(NULL) { }
   void setRoot(BinaryNode* node) {
      root = node;
   }
   BinaryNode* getRoot() {
      return root;
   }

   void printinorder() {
      printf("\n    inorder : "); return root -> inorder(root);
   }
   void preorder() {
      printf("\n   preorder : "); return root -> preorder(root);
   }
   void postorder() {
      printf("\n  postorder : "); return root -> postorder(root);
   }
      // 이진트리의 레벨 순회 연산
   void levelorder() {
      printf("\n levelorder : ");
      if(!isEmpty()) {
         CircularQueue q;
         q.enqueue(root);
         while(!q.isEmpty()) {
            BinaryNode* n = q.dequeue();
            if(n != NULL) {
               printf(" [%c] ", n -> data);
               q.enqueue(n -> left);
               q.enqueue(n -> right);
            }
         }
      }
      printf("\n");
   }
   int getCount() {
      return root -> getCount(root);
   }
   int getHeight() {
      return root -> getHeight(root);
   }
   int getLeafCount() {
      return root -> getLeafCount(root);
   }
   // 수식트리 계산 함수
   int evaluate() {
		return evaluate(root);
	}
   // 순환 호출에 의해 node를 루트로 하는 수식 트리의 계산 함수
	int evaluate(BinaryNode *node) {
		if(node == NULL) 
			return 0;
		if(node -> isLeaf())
			return node -> data;
		else {
			int op1 = evaluate(node -> left);
			int op2 = evaluate(node -> right);
			switch(node -> data) {
				case '+' : return op1 + op2;
				case '-' : return op1 - op2;
				case '*' : return op1 * op2;
				case '/' : return op1 / op2;
			}
			return 0;
		}
	}

	// 디렉터리 용량 계산 함수
	int calcSize() {
		return calcSize(root);
	}
	// 순환 호출에 의해 node를 루트로 하는 트리의 전체 용량 계산 함수
	int calcSize(BinaryNode *node) {
		if(node == NULL) 
			return 0;
		return node -> data + calcSize(node -> left) + calcSize(node -> right);
	}
};