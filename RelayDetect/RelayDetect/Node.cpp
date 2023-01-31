#include "Node.h"
#include "SensorManager.h"

Node::Node(){}

Node::Node(int _range)
{
	int dy[2] = { -1, 1 };
	int dx[2] = { -1, 1 };
	int* Detect = SMINS->GetDetect();
}

void Node::Show()
{
	cout << "Make Complete\n";
}
