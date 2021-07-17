#include <stdio.h>
#include <time.h>
extern int sumAlgorithmA(int num);			//O(1) 알고리즘
extern int sumAlgorithmB(int num);			//O(n) 알고리즘
extern int sumAlgorithmC(int num);			//O(nn) 알고리즘

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

	printf("(1) 알고리즘 정확도 테스트\n");
	printf("AlgorithmA (7) = %d\n", sumAlgorithmA(7));
	printf("AlgorithmB (7) = %d\n", sumAlgorithmB(7));
	printf("AlgorithmC (7) = %d\n", sumAlgorithmC(7));

	printf("AlgorithmA (9) = %d\n", sumAlgorithmA(9));
	printf("AlgorithmB (9) = %d\n", sumAlgorithmB(9));
	printf("AlgorithmC (9) = %d\n", sumAlgorithmC(9));

	printf("\n(2) 알고리즘 실행 시간 비교: A - B - C\n");
	for (i = 1000; ; i+=100) {
		t0 = clock();				//t0 시간측정
		iterAlgorithmA(i, 100);	//O(1) 알고리즘 실행
		t1 = clock();				//t1 시간측정
		iterAlgorithmB(i, 100);	//O(n) 알고리즘 실행
		t2 = clock();				//t2 시간측정
		iterAlgorithmC(i, 100);	//O(n2) 알고리즘 실행
		t3 = clock();				//t3 시간측정
		dA = (double)(t1 - t0) / CLOCKS_PER_SEC;
		dB = (double)(t2 - t1) / CLOCKS_PER_SEC;
		dC = (double)(t3 - t2) / CLOCKS_PER_SEC;

		printf("%5d: \t", i);
		printf("AlgorithmA : %lf\t", dA);
		printf("AlgorithmB : %lf\t", dB);
		printf("AlgorithmC : %lf\n", dC);
		//t3에서 t2, t2에서 t1, t1에서 t0을 감산한 값 출력
		if (dC > 1.0) break;		//알고리즘 C의 값이 5.0 이상이면 반복문 종료
	}

	printf("\n(3) 알고리즘 실행 시간 비교: B - C\n");
	for (i=10000; ; i+=100000) {
		t0 = clock();				//t0 시간측정
		iterAlgorithmA(i, 100);		//O(1) 알고리즘 실행
		t1 = clock();				//t1 시간측정
		iterAlgorithmB(i, 100);		//O(n) 알고리즘 실행
		t2 = clock();				//t2 시간측정
		dA = (double)(t1 - t0) / CLOCKS_PER_SEC;
		dB = (double)(t2 - t1) / CLOCKS_PER_SEC;

		printf("%5dk: \t", i/1000);
		printf("AlgorithmA : %lf\t", dA);
		printf("AlgorithmB : %lf\n", dB);
		//t3에서 t2, t2에서 t1, t1에서 t0을 감산한 값 출력
		if (dB > 1.0) break;		//알고리즘 C의 값이 5.0 이상이면 반복문 종료
	}
}