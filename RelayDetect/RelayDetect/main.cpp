#include "header.h"
#include "Node.h"
#include "SensorManager.h"


int main() {

	SMINS->Init(16);
	SMINS->ShowBoard();
	
	Node* node = new Node(16);
	node->Show();



	return 0;
}
