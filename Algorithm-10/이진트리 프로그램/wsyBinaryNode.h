#pragma once
#include <cstdio>

class BinaryNode {

public :
	int data;	// Ʈ���� ������ ������
	BinaryNode* left;	// ���� �ڽ� ����� ������
	BinaryNode* right;	// ������ �ڽ� ����� ������
	BinaryNode* root;	

	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL)
		: data(val), left(l), right(r) { }
	bool isLeaf() {
		return left == NULL && right == NULL;
	}
	bool isEmpty() {
      return root == NULL;
   }

	// ����Ʈ���� inorder ��ȸ ����
    void inorder(BinaryNode *node) {		// ��ȯ���� Ʈ���� ��ȸ �Լ�
      if(node != NULL) {
         inorder(node -> left);
         printf(" [%c] ", node -> data);
         inorder(node -> right);
      }
   }

   // ����Ʈ���� preorder ��ȸ ����
  void preorder(BinaryNode *node) {	// ��ȯ���� Ʈ���� ��ȸ �Լ�
      if(node != NULL) {
         printf(" [%c] ", node -> data);
         if(node -> left != NULL) preorder(node -> left);
         if(node -> right != NULL) preorder(node -> right);
      }
   }

   // ����Ʈ���� postorder ��ȸ ����
   void postorder(BinaryNode *node) {	// ��ȯ���� Ʈ���� ��ȸ �Լ�
      if(node != NULL) {
         if(node -> left != NULL) postorder(node -> left);
         if(node -> right != NULL) postorder(node -> right);
         printf(" [%c] ", node -> data);
      }
   }



   // Ʈ���� ��� ������ ���ϴ� �Լ�
   
   // ��ȯ ȣ�⿡ ���� node�� ��Ʈ�� �ϴ� ����Ʈ���� ��� �� ��� �Լ�
   int getCount(BinaryNode *node) {
      if(node == NULL)
         return 0;
      return 1 + getCount(node -> left) + getCount(node -> right);
   }

   // Ʈ���� ���̸� ���ϴ� �Լ�
   
   // ��ȯ ȣ�⿡ ���� node�� ��Ʈ�� �ϴ� ����Ʈ���� ���� ��� �Լ�
   int getHeight(BinaryNode *node) {
      if(node == NULL)
         return 0;
      int hLeft = getHeight(node -> left);
      int hRight = getHeight(node -> right);
      return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
      }
   
   // Ʈ���� �ܸ���� ������ ���ϴ� �Լ�
   
   // ��ȯ ȣ�⿡ ���� node�� ��Ʈ�� �ϴ� ����Ʈ���� �ܸ� ��� �� ��� �Լ�
   int getLeafCount(BinaryNode *node) {
      if(node == NULL) return 0;
      if(node -> isLeaf()) return 1;
      else return getLeafCount(node -> left) + getLeafCount(node -> right);
   }
};