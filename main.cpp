#include <iostream>
#include <fstream>

using namespace std;
#include "BranchAndBound.h"
#include "BranchAndBoundSalesman.h"


int main()
{
	ifstream in("input.txt");
	int m, n;
	in >> m >> n;
	int** c = new int*[m];
	for (int i = 0; i < m; i++)
	{
		c[i] = new int[n];
		for (int j = 0; j < n; j++)
			in >> c[i][j];
	}

	BranchAndBoundSalesman baba(n, m, c);
	baba.branchAndBound();
	for each (int var in baba.curAnswer)
	{
		cout << var<<" ";
	}
}