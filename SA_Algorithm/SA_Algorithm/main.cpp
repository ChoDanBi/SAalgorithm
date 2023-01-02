#include "header.h"
#include <time.h>

#include "NodeFactory.h"
#include "Node.h"

double dur(const clock_t& start, const clock_t& finish) {
	return (double)(finish - start) / CLOCKS_PER_SEC;
}

int main(void) {
	clock_t start, finish;
	cout << "*****TA Algorithm*****\n";
	start = clock();




	finish = clock();
	cout << "\n\n걸린시간: " << dur(start, finish);
	return 0;
}