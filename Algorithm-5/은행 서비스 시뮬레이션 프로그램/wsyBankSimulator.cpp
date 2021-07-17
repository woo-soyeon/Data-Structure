#include <ctime>	// C 헤더파일 <time.h>포함과 동일
#include "wsyBankSimulator.h"

void main() {
	srand((unsigned int)time(NULL));	
	BankSimulator sim;	// 시뮬레이터 객체 생성
	sim.readSimulationParameters();	// 시뮬레이션 파라미터 설정
	sim.run();	// 시뮬레이션 시작
	sim.printStat();	// 시뮬레이션 결과 출력

	getchar();
	getchar();
}