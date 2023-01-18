#include "header.h"
#include <time.h>
#include "SimulatedAnnealing.h"

void duration(const clock_t& start, const clock_t& finish);

int main(void) {
	cout << "*****SA Algorithm*****\n";

	clock_t start, finish;
	start = clock();
	//==========================

	//SA->Init(0.5, 0.5, 0.1, 31, 2, 1);

	SA->Init(0.5, 0.5, 0.1, 16, 2, 3);
	//SA->Start();

	

	//==========================
	finish = clock(); duration(start, finish); return 0;
}

void duration(const clock_t& start, const clock_t& finish) {
	double dur = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n\n걸린 시간: " << dur << endl;
}