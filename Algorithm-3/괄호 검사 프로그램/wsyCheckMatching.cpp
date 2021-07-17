#include "wsyArrayStack.h"	// wsyArrayStack 클래스 코드 사용

// 주어진 파일을 읽어 괄호 매칭을 검사하고 결과를 출력하는 함수
bool checkMatching(char * filename) {
	FILE *fp = fopen(filename, "r");
	if(fp == NULL)
		error("Error : 파일이 존재하지 않습니다.\n");

	int nLine = 1;	// 읽은 라인의 개수
	int nChar = 0;	// 읽은 문자의 개수

	ArrayStack stack;	// 스택 객체
	stack.reset();	// 스택 객체 초기화
	char ch;
	
	//bool bSingle = false;

	while((ch = getc(fp)) != EOF) {
		if(ch == '\n') nLine++;
		nChar++;

	//	if(ch == 39) {bSingle =! bSingle;}  

	//	if(bSingle)
	//		continue;

		if(ch == '[' || ch == '{' || ch == '(')	// ch가 열린 괄호일 때
			stack.push(ch);	// 스택에 넣음
		else if(ch == ')' || ch == '}' || ch == ']') {	// ch가 닫힌 괄호일 떼
			int prev = stack.pop();	// 스택에서 뺌
			if((ch == ']' && prev != '[')
			|| (ch == ')' && prev != '(')
			|| (ch == '}' && prev != '{')) break;
		}
	}
	fclose(fp);
	printf("[%s] 파일 검사결과 : \n", filename);
	if(!stack.isEmpty())
		printf("Error : 문제발견! (라인수 = %d, 문자수 = %d)\n\n", nLine, nChar);
	else
		printf("OK : 괄호닫기정상 (라인수 = %d, 문자수 = %d)\n\n", nLine, nChar);
	return stack.isEmpty();
}

bool checkMatching2(char* filename) {
	FILE *fp = fopen(filename, "r");
	if(fp == NULL)
		error("Error : '파일이 존재하지 않습니다.\n");

	ArrayStack stack;	// 스택 객체

	int nLine = 1;	// line번호 1번부터 시작
	int nChar = 0;	// 읽은 문자 개수는 0으로 초기화
	stack.reset();	// 새로운 파일을 체크하기 위해 스택객체 초기화
	char ch;	// 현재 문자를 읽음
	int comment;	// 주석
	int cnt = 0;	// 따옴표 카운터
	int comCnt = 0;	// 주석 카운터

	// cnt가 0이면 정상동작, 1일때 작은 따옴표, 2일때 큰 따옴표
	// comCnt가 0이면 아무것도 들어있지 않음, /일 때 1, //일 때 2, /*일 때는 3, */일 때는 4

	while((ch = getc(fp)) != EOF) {
		if(ch == '\n')
			nLine++;
		nChar++;

		// 주석 예외(//, /* */)

		if(comCnt == 0) {	// 주석에 아무것도 없음
			if(ch == 47) {	// 아스키 코드에서 /는 47
				stack.push(ch);	// 스택에 넣음
				comCnt = 1;	// comCnt를 1로
			}
		}

		else if(comCnt == 1) { // /일 때
			comment = stack.pop();	// 스택에 있는 슬래시를 빼면서 comment에 저장
			if(ch == 47)	// 슬래시가 들어오면
				comCnt = 2;	// 2로 카운트
			else if(ch == 42)	// 슬래시 카운트가 1일 때 *이 들어오면
				comCnt = 3;	// 3으로 카운트
			else
				comCnt = 0; // 뒤에 /나 *이 붙지 않아서 0으로 카운트
		}

		else if (comCnt == 2) { // //일 때
			if(ch == '\n')	// 줄바꿈 문자가 오면
				comCnt = 0;	// 0으로 카운트
			else	// 줄바꿈 문자가 오지 않으면
				continue;	// 계속함
		}

		else if(comCnt == 3) {	// /*일 때
			if(ch == 42)	// *이 들어오면
				comCnt = 4;	// 4로 카운트
			else	// *이 들어오지 않으면
				continue;	// 계속함
		}

		else if(comCnt == 4) { // *뒤에 /인지 확인
			if(ch == 47) // /가 맞으면
				comCnt = 0; // 0으로 카운트
			else	// /가 아니면
				comCnt = 3;	// 3으로 카운트
		}


		// 작은 따옴표, 큰 따옴표 예외

		if(cnt == 0) {
			if(ch == 39)	// 아스키코드에서 작은 따옴표는 39
				cnt = 1;	// 작은 따옴표가 들어오면 cnt 1
			else if(ch == 34)	// 아스키 코드에서 큰 따옴표는 34
				cnt = 2;	// 큰 따옴표가 들어오면 cnt 2
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

		else if(cnt == 1) {	// 작은 따옴표가 들어와 있을 때
			if(ch == 39)	// 다음 작은 따옴표가 들어오면 0으로 이동
				cnt = 0;
			else
				continue;	// 다음 작은 따옴표가 들어오기전까지 continue
		}

		else if(cnt == 2) {	// 큰 따옴표가 들어와 있을 때
			if(ch == 34)	// 다음 큰 따옴표가 들어오면 0으로 이동
				cnt = 0;
			else
				continue;	// 다음 큰 따옴표가 들어오기전까지 continue
		}
	}
	fclose(fp);
	printf("[%s] 파일 검사결과 : \n(((((((((((((({{", filename);
	if(!stack.isEmpty())
		printf("Error : 문제발견! (라인수 = %d, 문자수 = %d)\n\n", nLine, nChar);
	else
		printf("OK : 괄호닫기정상 (라인수 = %d, 문자수 = %d)\n\n", nLine, nChar);
	return stack.isEmpty();
};

// 주 함수 : wsyArrayStack.h, wsyCheckMatching.cpp의 두 파일 검사
void main() {
	checkMatching("wsyArrayStack.h");	// 스택 헤더파일 검사
	checkMatching("wsyCheckMatching.cpp");	// cpp파일 검사
	checkMatching2("wsyCheckMatching.cpp");	// 문제해결 후 검사
}