#pragma once
#include "header.h"
#include "NodeManager.h"

class SimulatedAnnealing
{
private:
	static SimulatedAnnealing* Instance;

public:
	static SimulatedAnnealing* GetInstance() {
		if (Instance == NULL)
			Instance = new SimulatedAnnealing();
		return Instance;
	}

private:
	double AcceptanceProbabilty;
	double Temperature;
	double Difference;

public:	//Init
	void Init(const double& _accept, const double& _temp, const double& _diff);
	void Init(const double& _accept, const double& _temp, const double& _diff, const int& _range);
	void Init(const double& _accept, const double& _temp, const double& _diff, const int& _range, const int& _num);

public:	//SA
	void Start();
	void Finish() { cout << "FinalNum: "; NM->ShowCurNode(); }
	void Simulating();

public:	//functions
	int GetDistance(const int& _curfit, const int& _nearfit) { return (_nearfit - _curfit); }
	int GetDistance(const int* _curfit, const int *_nearfit) { return (*_nearfit - *_curfit); }

	double GetPercent(int d) { return pow(E, -(d / Temperature)); }

	bool ChkAbletoChange(Node* _node, const int& _dis, const int& _per, int* _i, int* _size);


public:	//get
	double GetAccept() { return AcceptanceProbabilty; }
	double GetTemp() { return Temperature; }
	double GetDiff() { return Difference; }

public: //set
	double SetAccept(int _accept) { AcceptanceProbabilty = _accept; }
	double SetTemp(int _temp) { Temperature = _temp; }
	double SetDiff(int _diff) { Difference = _diff; }

public:
	SimulatedAnnealing(): AcceptanceProbabilty(0.0), Temperature(0.0), Difference(0.0) {};
private:
	~SimulatedAnnealing() {};
};
