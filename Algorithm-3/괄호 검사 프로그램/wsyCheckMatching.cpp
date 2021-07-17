#include "wsyArrayStack.h"	// wsyArrayStack Ŭ���� �ڵ� ���

// �־��� ������ �о� ��ȣ ��Ī�� �˻��ϰ� ����� ����ϴ� �Լ�
bool checkMatching(char * filename) {
	FILE *fp = fopen(filename, "r");
	if(fp == NULL)
		error("Error : ������ �������� �ʽ��ϴ�.\n");

	int nLine = 1;	// ���� ������ ����
	int nChar = 0;	// ���� ������ ����

	ArrayStack stack;	// ���� ��ü
	stack.reset();	// ���� ��ü �ʱ�ȭ
	char ch;
	
	//bool bSingle = false;

	while((ch = getc(fp)) != EOF) {
		if(ch == '\n') nLine++;
		nChar++;

	//	if(ch == 39) {bSingle =! bSingle;}  

	//	if(bSingle)
	//		continue;

		if(ch == '[' || ch == '{' || ch == '(')	// ch�� ���� ��ȣ�� ��
			stack.push(ch);	// ���ÿ� ����
		else if(ch == ')' || ch == '}' || ch == ']') {	// ch�� ���� ��ȣ�� ��
			int prev = stack.pop();	// ���ÿ��� ��
			if((ch == ']' && prev != '[')
			|| (ch == ')' && prev != '(')
			|| (ch == '}' && prev != '{')) break;
		}
	}
	fclose(fp);
	printf("[%s] ���� �˻��� : \n", filename);
	if(!stack.isEmpty())
		printf("Error : �����߰�! (���μ� = %d, ���ڼ� = %d)\n\n", nLine, nChar);
	else
		printf("OK : ��ȣ�ݱ����� (���μ� = %d, ���ڼ� = %d)\n\n", nLine, nChar);
	return stack.isEmpty();
}

bool checkMatching2(char* filename) {
	FILE *fp = fopen(filename, "r");
	if(fp == NULL)
		error("Error : '������ �������� �ʽ��ϴ�.\n");

	ArrayStack stack;	// ���� ��ü

	int nLine = 1;	// line��ȣ 1������ ����
	int nChar = 0;	// ���� ���� ������ 0���� �ʱ�ȭ
	stack.reset();	// ���ο� ������ üũ�ϱ� ���� ���ð�ü �ʱ�ȭ
	char ch;	// ���� ���ڸ� ����
	int comment;	// �ּ�
	int cnt = 0;	// ����ǥ ī����
	int comCnt = 0;	// �ּ� ī����

	// cnt�� 0�̸� ������, 1�϶� ���� ����ǥ, 2�϶� ū ����ǥ
	// comCnt�� 0�̸� �ƹ��͵� ������� ����, /�� �� 1, //�� �� 2, /*�� ���� 3, */�� ���� 4

	while((ch = getc(fp)) != EOF) {
		if(ch == '\n')
			nLine++;
		nChar++;

		// �ּ� ����(//, /* */)

		if(comCnt == 0) {	// �ּ��� �ƹ��͵� ����
			if(ch == 47) {	// �ƽ�Ű �ڵ忡�� /�� 47
				stack.push(ch);	// ���ÿ� ����
				comCnt = 1;	// comCnt�� 1��
			}
		}

		else if(comCnt == 1) { // /�� ��
			comment = stack.pop();	// ���ÿ� �ִ� �����ø� ���鼭 comment�� ����
			if(ch == 47)	// �����ð� ������
				comCnt = 2;	// 2�� ī��Ʈ
			else if(ch == 42)	// ������ ī��Ʈ�� 1�� �� *�� ������
				comCnt = 3;	// 3���� ī��Ʈ
			else
				comCnt = 0; // �ڿ� /�� *�� ���� �ʾƼ� 0���� ī��Ʈ
		}

		else if (comCnt == 2) { // //�� ��
			if(ch == '\n')	// �ٹٲ� ���ڰ� ����
				comCnt = 0;	// 0���� ī��Ʈ
			else	// �ٹٲ� ���ڰ� ���� ������
				continue;	// �����
		}

		else if(comCnt == 3) {	// /*�� ��
			if(ch == 42)	// *�� ������
				comCnt = 4;	// 4�� ī��Ʈ
			else	// *�� ������ ������
				continue;	// �����
		}

		else if(comCnt == 4) { // *�ڿ� /���� Ȯ��
			if(ch == 47) // /�� ������
				comCnt = 0; // 0���� ī��Ʈ
			else	// /�� �ƴϸ�
				comCnt = 3;	// 3���� ī��Ʈ
		}


		// ���� ����ǥ, ū ����ǥ ����

		if(cnt == 0) {
			if(ch == 39)	// �ƽ�Ű�ڵ忡�� ���� ����ǥ�� 39
				cnt = 1;	// ���� ����ǥ�� ������ cnt 1
			else if(ch == 34)	// �ƽ�Ű �ڵ忡�� ū ����ǥ�� 34
				cnt = 2;	// ū ����ǥ�� ������ cnt 2
			else if(ch == '[' || ch == '{' || ch == '(')
				stack.push(ch);
			else if(ch == ')' || ch == '}' || ch == ']') {
				char prev = stack.pop();
				if((ch == ']' && prev != '[')
				|| (ch == ')' && prev != '(')
				|| (ch == '}' && prev != '{'))
					break;
			}
		}

		else if(cnt == 1) {	// ���� ����ǥ�� ���� ���� ��
			if(ch == 39)	// ���� ���� ����ǥ�� ������ 0���� �̵�
				cnt = 0;
			else
				continue;	// ���� ���� ����ǥ�� ������������ continue
		}

		else if(cnt == 2) {	// ū ����ǥ�� ���� ���� ��
			if(ch == 34)	// ���� ū ����ǥ�� ������ 0���� �̵�
				cnt = 0;
			else
				continue;	// ���� ū ����ǥ�� ������������ continue
		}
	}
	fclose(fp);
	printf("[%s] ���� �˻��� : \n(((((((((((((({{", filename);
	if(!stack.isEmpty())
		printf("Error : �����߰�! (���μ� = %d, ���ڼ� = %d)\n\n", nLine, nChar);
	else
		printf("OK : ��ȣ�ݱ����� (���μ� = %d, ���ڼ� = %d)\n\n", nLine, nChar);
	return stack.isEmpty();
};

// �� �Լ� : wsyArrayStack.h, wsyCheckMatching.cpp�� �� ���� �˻�
void main() {
	checkMatching("wsyArrayStack.h");	// ���� ������� �˻�
	checkMatching("wsyCheckMatching.cpp");	// cpp���� �˻�
	checkMatching2("wsyCheckMatching.cpp");	// �����ذ� �� �˻�
}