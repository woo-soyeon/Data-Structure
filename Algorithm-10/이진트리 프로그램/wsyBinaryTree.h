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
      // ����Ʈ���� ���� ��ȸ ����
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
   // ����Ʈ�� ��� �Լ�
   int evaluate() {
		return evaluate(root);
	}
   // ��ȯ ȣ�⿡ ���� node�� ��Ʈ�� �ϴ� ���� Ʈ���� ��� �Լ�
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

	// ���͸� �뷮 ��� �Լ�
	int calcSize() {
		return calcSize(root);
	}
	// ��ȯ ȣ�⿡ ���� node�� ��Ʈ�� �ϴ� Ʈ���� ��ü �뷮 ��� �Լ�
	int calcSize(BinaryNode *node) {
		if(node == NULL) 
			return 0;
		return node -> data + calcSize(node -> left) + calcSize(node -> right);
	}
};