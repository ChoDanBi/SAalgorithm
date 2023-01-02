#include "NodeFactory.h"
#include <random>

int NodeFactory::GetRand(int _max)
{
	//시드값을 얻기 위한 rd 생성
	random_device rd;
	//난수 생성 엔진 초기화
	mt19937 gen(rd());
	//min~max까지의 난수 생성
	uniform_int_distribution<int> dis(0, _max);
	return dis(gen);
}

int NodeFactory::GetRand(int _min, int _max)
{
	//시드값을 얻기 위한 rd 생성
	random_device rd;
	//난수 생성 엔진 초기화
	mt19937 gen(rd());
	//min~max까지의 난수 생성
	uniform_int_distribution<int> dis(0, 1);
	return dis(gen);
}

//오브젝트 만들기
Node* NodeFactory::CreateNode(int _num)
{
	Node* node = new Node;
	node->SetNum(_num);
	return node;
}

Node* NodeFactory::CreateNode(vector<int> _binary)
{
	Node* node = new Node;
	node->SetBinary(_binary);
	return node;
}


