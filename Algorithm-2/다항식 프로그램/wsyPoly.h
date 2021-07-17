#include <cstdio>
#define MAX_DEGREE 80	// 다항식의 처리 가능한 최대차수 +1
class Polynomial {
	int degree;		// 다항식의 최고 차수
	float coef[MAX_DEGREE];		// 각 항에 대한 계수
public :
	Polynomial() { degree = 0; }	// 생성자 : 최대 차수를 0으로 초기화

	// 다항식의 내용을 입력받는 멤버함수
	void read() {
		printf("다항식의 최고 차수를 입력하시오 : ");
		scanf("%d", &degree);
		printf("각 항의 계수를 입력하시오 (총 %d개) : ", degree+1);
		for(int i = 0; i <= degree; i++)
			scanf("%f", coef+degree-i);
	}
	// 다항식의 내용을 화면에 출력하는 함수
	void display(char *str = "Poly = ") {	// 디폴트 매개변수 사용
		printf("\t%s", str);
		for(int i = 0; i < degree; i++) 
			printf("%5.1f x^%d + ", coef[i], degree-i);
		printf("%4.1f\n", coef[degree]);
	}
	void display2(char *str = "Poly = ") {	// 디폴트 매개변수 사용
		printf("\t%s", str);
		if(degree != 0)	// 최고 차항이 0이 아니면
			printf("%5.1f x^%d", coef[0], degree);	// 최고 차항을 출력
		for(int i = 1; i < degree; i++) {	// 최고 차항 이후
			if(coef[i] == 0)
				continue;	// 계수가 0인 항은 출력하지 않음
			else if(coef[i] == 1)
				printf(" + x^%d",degree-i);
			else if(coef[i] == -1)
				printf(" - x^%d",degree-i);
			else if(coef[i] > 1)
				printf(" + %5.1f x^%d", coef[i], degree-i);
			else
				printf(" - %5.1f x^%d", -(coef[i]), degree-i);	// 음수일 경우 - 출력
		}
		if(coef[degree] != 0) {	// 계수가 0이 아닐 때
			if(degree != 0)
				if(coef[degree] > 0)
					printf(" + %5.1f", coef[degree]);
				else
					printf(" - %5.1f", -(coef[degree]));
			else
				printf("%5.1f", coef[degree]);
		}
		else
			if(degree == 0)
				printf("0");
		printf("\n");
	}
	// 다항식 a와 b 를 더하는 함수. a와 b를 더해 자신의 다항식 설정
	void add(Polynomial a, Polynomial b) {
		if (a.degree > b.degree) {	// a항 > b항
			*this = a;	// a 다항식을 자기 객체에 복사
			for(int i = 0; i <= b.degree; i++)
				coef[i+(degree-b.degree)] += b.coef[i];
		}
		else {	// a항 <= b항
			*this = b;	// b 다항식을 자신에 복사
			for(int i = 0; i <= a.degree; i++)
				coef[i+(degree-a.degree)] += a.coef[i];
		}
	}
	// 다항식 a와 b를 뺴는 함수. a와 b를 빼서 자신의 다항식 설정
	void sub(Polynomial a, Polynomial b) {
		if (a.degree > b.degree) {	// a항 > b항
			*this = a;	// a 다항식을 자기 객체에 복사
			for(int i = 0; i <= b.degree; i++)
				coef[i+(degree-b.degree)] -= b.coef[i];
		}
		else {	// a항 <= b항
			*this = b;	// b 다항식을 자신에 복사
			for(int i = 0; i <= a.degree; i++)
				coef[i+(degree-a.degree)] -= a.coef[i];
		}
	}
	// 다항식 a와 b를 곱하는 함수. a와 b를 곱해서 자신의 다항식 설정
	void mult(Polynomial a, Polynomial b) {
		degree = a.degree + b.degree;		// 곱한 최고 차수는 a, b의 최고차수 합
		for(int i = 0; i<= degree; i++)
			coef[i] = 0;
		for(int i = 0; i <= a.degree; i++)
			for (int j = 0; j <= b.degree; j++)
				coef[i + j] += a.coef[i] * b.coef[j];
	}
	// 최고차항의 계수가 0이아닌 값이 나오도록 하는 함수
	void trim() {
		for( ; ; ) {
			if(coef[degree] == 0) {	// 최고 차항의 계수가 0이면
				degree--;	// 최고 차항을 1 줄임
				//for (int i = 0; i <= degree; i--)
				//	coef[i] = coef[i+1];	// 줄어든 만큼 한칸씩 옮김
				if(degree == 0)	// 상수항이 되면 종료
					break;
			}
			else	// 최고 차항의 계수가 0이 아니면 종료
				break;
		}
	}
	bool isZero() {return degree == 0;}		// 최고차수가 0인가?
	void negate() {		// 모든 계수의 부호를 바꿈
		for(int i = 0; i < degree; i++ )
			coef[i] = -coef[i];		// 계수의 부호를 바꿈
	}
};