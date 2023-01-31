#include "header.h"
#include "Node.h"
#include "SensorManager.h"


int main() {

	SMINS->Init(16,3,2);
	SMINS->ShowBoard();
	
	Node* node = new Node;
	node->Show();

	return 0;
}
