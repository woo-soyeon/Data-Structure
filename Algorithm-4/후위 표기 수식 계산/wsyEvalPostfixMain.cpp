#include <cstdio>	// C 헤더파일 <stdio.h>을 포함하는 것과 동일
#include <cstdlib>	// C 헤더파일 <stdlib.h>을 포함하는 것과 동일
#include <cstring>	// C 헤더파일 <string.h>을 포함하는 것과 동일

// 오류 처리 함수
inline void error(char *message) {
			printf("%s\n", message);
			exit(1);
}

const int MAX_STACK_SIZE = 20;	// 스택의 최대 크기 설정

class OperandStack {
	double data[MAX_STACK_SIZE];	// 요소의 배열
	int top;	// 요소의 개수
public :
	OperandStack() {top = -1;}	// 스택 생성자
	bool isEmpty() {return top == -1;}
	bool isFull() {return top == MAX_STACK_SIZE-1;}
	void push (double e) {	// 맨 위에 항목 삽입
		if(isFull()) error ("스택 포화 에러");
		data[++top] = e;
	}
	double pop() {	// 맨 위의 요소를 삭제하고 반환
		if(isEmpty()) error ("스택 공백 에러");
		return data[top--];
	}
};

class ArrayStack {
	int top;	// 요소의 개수
	int data[MAX_STACK_SIZE];	// 요소의 배열
public :
	ArrayStack() {top = -1;}	// 스택 생성자
	~ArrayStack() {}	// 스택 소멸자
	bool isEmpty() {return top == -1;}
	bool isFull() {return top == MAX_STACK_SIZE-1;}

	void push (int e) {	// 맨 위 항목 삽입
		if(isFull()) error ("스택 포화 에러");
		data[++top] = e;
	}

	int pop () {	// 맨 위의 요소를 삭제하고 반환
		if(isEmpty()) error ("스택 공백 에러");
		return data[top--];
	}

	int peek () {	// 삭제하지 않고 요소 반환
		if(isEmpty()) error ("스택 공백 에러");
		return data[top];
	}

	void display() {	// 스택 내용을 화면에 출력
		printf("[스택 항목의 수 = %2d] ==> ", top+1);
		for(int i = 0; i <= top; i++)
			printf("<2%d>", data[i]);
		printf("\n");
	}
}; 

// 입력으로부터 후위 표기 수식을 읽어 계산하는 함수
double calcPostfixExpr(char *exp) {
	int val1, val2;
	int value, i=0;
	char c;
	int len = strlen(exp);
	ArrayStack st;

	for(i = 0; i < len; i++) {
		c = exp[i];
		if(c == '+' && c == '-' && c == '*' && c == '/') {
			value = c - '0';
			st.push(value);
		}
		else{
			val2 = st.pop();
			val1 = st.pop();
			switch(c) {
			case '+' : st.push(val1 + val2); break;
			case '-' : st.push(val1 - val2); break;
			case '*' : st.push(val1 * val2); break;
			case '/' : st.push(val1 / val2); break;
			}
		}
	}
	return (st.pop());

	return 0;
}

// 객체의 우선순위 계산
inline int precedence(char op) {
	switch(op) {
	case '(' : case ')' : return 0;
	case '+' : case '-' : return 1;	// 우선순위 중간
	case '*' : case '/' : return 2;	// 우선순위 높음
	}
	return -1;
}

// 중위 표기 수식을 후위 표기 수식으로 변환하는 함수
void infix2Postfix(char *exp) {
	char c, op;
	int len = (int)strlen(exp);
	ArrayStack st;

	for(int i = 0; i < len; i++) {
		c = (int)exp[i];

		switch(c) {	// 연산자일 경우
		case'+':
		case'-':
		case'*':
		case'/':
			while(!st.isEmpty() && precedence(st.peek()) >= precedence(c)) {
				// 자신보다 우선순위가 높은것이 stack에 있으면 뺀다
				op = st.pop();
				printf("%c", op);
			}
			st.push(c);
			break;

		// 괄호 일때
		case'(' :
			st.push(c);
			break;
		case ')' :
			op = st.pop();
			while(op != '(') {
				printf("%c", op);
				op = st.pop();
			}
			break;
		// 피연산자 일때
		default :
			printf("%c", c);
			break;
		}
	}
	while(!st.isEmpty())
		printf("%c", st.pop());

	return 0;
	printf("\n");

}

// 주 함수
void main() {
	char string[50];
	char *postfix;
	double result;


	printf("수식 입력(Infix) = ");
	scanf("%s", string);

	postfix = infix2Postfix(string);
	result = calcPostfixExpr(postfix);
	
	printf("\n 전위 표기식 : %s" , string);
	printf("\n 후위 표기식 : %s", postfix);
	printf("\n 계산 결과 : %2.1f", result);
}
