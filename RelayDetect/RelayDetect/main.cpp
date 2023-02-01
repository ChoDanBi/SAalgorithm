#include "header.h"
#include "Node.h"
#include "SensorManager.h"


int main() {

	SMINS->Init(16,3,2);
	
	Node* node = new Node;

	SMINS->ShowBoard();

	return 0;
}
