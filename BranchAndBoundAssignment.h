#pragma once
#include "BranchAndBound.h"
#include <vector>
using namespace std;

class BranchAndBoundAssignment :public BranchAndBound<vector<int>, vector<int>>
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
	BranchAndBoundAssignment(int _n, int _m, int** _c);
	bool nextBranch(vector<int>* watchedJobs) override;
	bool BoundingFunction(vector<int>* watchedJobs) override;
	vector<int>* preprocessing() override;
	void cancelBranch(vector<int>* watchedJobs) override;
	void postProcessing(vector<int>* lv) override;
};