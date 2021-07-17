#include <stdio.h>
#include <time.h>
extern int sumAlgorithmA(int num);			//O(1) �˰���
extern int sumAlgorithmB(int num);			//O(n) �˰���
extern int sumAlgorithmC(int num);			//O(nn) �˰���

void iterAlgorithmA(int n, int times) {
	int i;
	for (i = 0; i < times; i++)
		sumAlgorithmA(n);
}
void iterAlgorithmB(int n, int times) {
	int i;
	for (i = 0; i < times; i++)
		sumAlgorithmB(n);
}
void iterAlgorithmC(int n, int times) {
	int i;
	for (i = 0; i < times; i++)
		sumAlgorithmC(n);
}

void main()
{
	clock_t t0, t1, t2, t3;
	double dA, dB, dC;
	int i;

	printf("(1) �˰��� ��Ȯ�� �׽�Ʈ\n");
	printf("AlgorithmA (7) = %d\n", sumAlgorithmA(7));
	printf("AlgorithmB (7) = %d\n", sumAlgorithmB(7));
	printf("AlgorithmC (7) = %d\n", sumAlgorithmC(7));

	printf("AlgorithmA (9) = %d\n", sumAlgorithmA(9));
	printf("AlgorithmB (9) = %d\n", sumAlgorithmB(9));
	printf("AlgorithmC (9) = %d\n", sumAlgorithmC(9));

	printf("\n(2) �˰��� ���� �ð� ��: A - B - C\n");
	for (i = 1000; ; i+=100) {
		t0 = clock();				//t0 �ð�����
		iterAlgorithmA(i, 100);	//O(1) �˰��� ����
		t1 = clock();				//t1 �ð�����
		iterAlgorithmB(i, 100);	//O(n) �˰��� ����
		t2 = clock();				//t2 �ð�����
		iterAlgorithmC(i, 100);	//O(n2) �˰��� ����
		t3 = clock();				//t3 �ð�����
		dA = (double)(t1 - t0) / CLOCKS_PER_SEC;
		dB = (double)(t2 - t1) / CLOCKS_PER_SEC;
		dC = (double)(t3 - t2) / CLOCKS_PER_SEC;

		printf("%5d: \t", i);
		printf("AlgorithmA : %lf\t", dA);
		printf("AlgorithmB : %lf\t", dB);
		printf("AlgorithmC : %lf\n", dC);
		//t3���� t2, t2���� t1, t1���� t0�� ������ �� ���
		if (dC > 1.0) break;		//�˰��� C�� ���� 5.0 �̻��̸� �ݺ��� ����
	}

	printf("\n(3) �˰��� ���� �ð� ��: B - C\n");
	for (i=10000; ; i+=100000) {
		t0 = clock();				//t0 �ð�����
		iterAlgorithmA(i, 100);		//O(1) �˰��� ����
		t1 = clock();				//t1 �ð�����
		iterAlgorithmB(i, 100);		//O(n) �˰��� ����
		t2 = clock();				//t2 �ð�����
		dA = (double)(t1 - t0) / CLOCKS_PER_SEC;
		dB = (double)(t2 - t1) / CLOCKS_PER_SEC;

		printf("%5dk: \t", i/1000);
		printf("AlgorithmA : %lf\t", dA);
		printf("AlgorithmB : %lf\n", dB);
		//t3���� t2, t2���� t1, t1���� t0�� ������ �� ���
		if (dB > 1.0) break;		//�˰��� C�� ���� 5.0 �̻��̸� �ݺ��� ����
	}
}