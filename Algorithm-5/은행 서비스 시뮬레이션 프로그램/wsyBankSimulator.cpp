#include <ctime>	// C ������� <time.h>���԰� ����
#include "wsyBankSimulator.h"

void main() {
	srand((unsigned int)time(NULL));	
	BankSimulator sim;	// �ùķ����� ��ü ����
	sim.readSimulationParameters();	// �ùķ��̼� �Ķ���� ����
	sim.run();	// �ùķ��̼� ����
	sim.printStat();	// �ùķ��̼� ��� ���

	getchar();
	getchar();
}