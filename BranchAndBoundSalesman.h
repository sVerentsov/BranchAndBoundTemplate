#pragma once
#include "BranchAndBound.h"
#include <vector>
using namespace std;

class BranchAndBoundSalesman :public BranchAndBound<vector<int>, vector<int>>
{
	int** c;
	int m;
	int n;
	vector<int> assignedJobs;
	int cursum = 0;
	int minCurSum = INT_MAX;	
public:
	//n - people
	//m - jobs
	BranchAndBoundSalesman(int _n, int _m, int** _c);
	bool ifCycles();
	bool nextBranch(vector<int>* watchedJobs) override;
	bool BoundingFunction(vector<int>* watchedJobs) override;
	vector<int>* preprocessing() override;
	void cancelBranch(vector<int>* watchedJobs) override;
	void postProcessing(vector<int>* lv) override;
};