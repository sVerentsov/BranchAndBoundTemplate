
#include "BranchAndBoundAssignment.h"
#include <algorithm>
using namespace std;
BranchAndBoundAssignment::BranchAndBoundAssignment(int _n, int _m, int** _c)
{
	n = _n;
	m = _m;
	c = new int*[n];
	for (int i = 0; i < n; i++)
	{
		c[i] = new int[m];
		for (int j = 0; j < m; j++)
			c[i][j] = _c[i][j];
	}

}
bool BranchAndBoundAssignment::nextBranch(vector<int>* watchedJobs)
{
	if (assignedJobs.size() == m)
		return false;
	if (watchedJobs->size() == m)
		return false;
	for (int i = 0; i < m; i++)
	{
		if (!count(watchedJobs->begin(), watchedJobs->end(), i) && !count(assignedJobs.begin(), assignedJobs.end(), i))
		{
			watchedJobs->push_back(i);
			assignedJobs.push_back(i);
			cursum += c[i][assignedJobs.size() - 1];
			return true;
		}
	}
	return false;
}
bool BranchAndBoundAssignment::BoundingFunction(vector<int>* watchedJobs)
{
	int lowerbound = cursum;
	for (int i = assignedJobs.size(); i < n; i++)
	{
		int min = INT_MAX;
		for (int j = 0; j < m; j++)
		{
			if (!count(assignedJobs.begin(), assignedJobs.end(), j) && c[i][j] < min)
				min = c[i][j];
		}
		lowerbound += min;
	}
	if (minCurSum < lowerbound)
		return false;
	else return true;
}
vector<int>* BranchAndBoundAssignment::preprocessing()
{
	return new vector<int>();
}

void BranchAndBoundAssignment::cancelBranch(vector<int>* watchedJobs)
{
	cursum -= c[assignedJobs[assignedJobs.size() - 1]][assignedJobs.size() - 1];
	assignedJobs.pop_back();
}

void BranchAndBoundAssignment::postProcessing(vector<int>* lv)
{
	if (assignedJobs.size() == m) {
		minCurSum = 0;
		for (int i = 0; i < n; i++)
			minCurSum += c[assignedJobs[i]][i];
		curAnswer = assignedJobs;
	}
	if (assignedJobs.size() != 0)
	{
		cursum -= c[assignedJobs[assignedJobs.size() - 1]][assignedJobs.size() - 1];
		assignedJobs.pop_back();
	}
	delete lv;
}