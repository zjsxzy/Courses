#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

int m, n;
double z0;
vector<int> B, N;
vector<vector<double> > A;
vector<double> b;
vector<double> c;

int cnt = 0;

vector<vector<double> > SetSimplex(vector<double> maxFunction, vector<vector<double> > A, vector<double> b) {
	vector<vector<double> > simplex;

	int numVariables = maxFunction.size();
	int numEquations = A.size();
	int numCols = numVariables + numEquations + 1 + 1;

	for (int iRow = 0; iRow < numEquations; iRow++) {
		vector<double> row(numCols, 0);
		for (int iCol = 0; iCol < numVariables; iCol++) {
			row[iCol] = A[iRow][iCol];
		}
		row[numVariables + iRow] = 1;
		row[numCols - 1] = b[iRow];
		simplex.push_back(row);
	}

	vector<double> lastRow(numCols, 0);
	for (int iVar = 0; iVar < numVariables; iVar++) {
		lastRow[iVar] = 0 - maxFunction[iVar];
	}
	lastRow[numVariables + numEquations] = 1;
	simplex.push_back(lastRow);

	return simplex;
}

bool GetPivots(vector<vector<double> > simplex, int & pivotCol, int & pivotRow, bool & noSolution) {
	int numRows = simplex.size();
	int numCols = simplex[0].size();
	int numVariables = numCols - numRows - 1;

	noSolution = false;
	double min = 0;
	bool first = true;
	for (int iCol = 0; iCol < numCols - 2; iCol++) {
		double value = simplex[numRows - 1][iCol];
		if (value < 0) {
			if (first) {
				first = false;
				pivotCol = iCol;
				min = value;
			} else if (N[iCol] < N[pivotCol]){
				pivotCol = iCol;
				min = value;
			}
		}
	}

	if (min == 0) return false;

	double minRatio = 0.0;
	first = true;
	for (int iRow = 0; iRow < numRows - 1; iRow++) {
		double value = simplex[iRow][pivotCol];
		
		if (value > 0.0) {
			double colValue = simplex[iRow][numCols - 1];
			double ratio = colValue / value;

			if (ratio < 0) continue;

			if (first) {
				first = false;
				minRatio = ratio;
				pivotRow = iRow;
			} else if (ratio < minRatio) {
				minRatio = ratio;
				pivotRow = iRow;
			} else if (abs(ratio - minRatio) < 1e-6 && B[iRow] < B[pivotRow]) {
				pivotRow = iRow;
			}
		}
	}

	noSolution = first;
	return !noSolution;
}

vector<double> DoSimplex(vector<vector<double> > simplex, double &max) {
	int pivotCol, pivotRow;
	int numRows = simplex.size();
	int numCols = simplex[0].size();

	bool noSolution = false;
	while (GetPivots(simplex, pivotCol, pivotRow, noSolution)) {
		double pivot = simplex[pivotRow][pivotCol];

		for (int iCol = 0; iCol < numCols; iCol++) {
			simplex[pivotRow][iCol] /= pivot;
		}

		for (int iRow = 0; iRow < numRows; iRow++) {
			if (iRow != pivotRow) {
				double ratio = -1 * simplex[iRow][pivotCol];
				for (int iCol = 0; iCol < numCols; iCol++) {
					simplex[iRow][iCol] = simplex[pivotRow][iCol] * ratio + simplex[iRow][iCol];
				}
			}
		}
		cnt++;	
	}

	if (noSolution) {
		vector<double> vec;
		printf("UNBOUNDED\n");
		return vec;
	}

	//optimal
	max = simplex[numRows - 1][numCols - 1];
	int numVariables = numCols - numRows - 1;
	vector<double> x(numVariables, 0);

	for (int iCol = 0; iCol < numVariables; iCol++) {
		bool isUnit = true;
		bool first = true;
		double value;
		for (int iRow = 0; iRow < numRows; iRow++) {
			if (simplex[iRow][iCol] == 1.0 && first) {
				first = false;
				value = simplex[iRow][numCols - 1];
			} else if (simplex[iRow][iCol] != 0.0) {
				isUnit = false;
			}
		}

		if (isUnit && !first) {
			x[iCol] = value;
		} else {
			x[iCol] = 0.0;
		}
	}
	printf("%.5f\n", max + z0);
	printf("%d\n", cnt);

	return x;
}

int main() {
//	freopen("unitTests/dict2", "r", stdin);
	scanf("%d%d", &m, &n);
	B.resize(m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &B[i]);
	}

	N.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &N[i]);
	}

	b.resize(m);
	for (int i = 0; i < m; i++) {
		scanf("%lf", &b[i]);
	}

	A.resize(m);
	for (int i = 0; i < m; i++) {
		A[i].resize(n);
		for (int j = 0; j < n; j++) {
			scanf("%lf", &A[i][j]);
			A[i][j] *= -1.0;
		}
	}

	scanf("%lf", &z0);
	c.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &c[i]);
	}

	vector<vector<double> > simplex = SetSimplex(c, A, b);

	double max;
	vector<double> result = DoSimplex(simplex, max);

	/*printf("Result: Max =  %.5f\n", max + z0);
	for (int i = 0; i < result.size(); i++) {
		printf("x%d = %.5f ; ", i, result[i]);
	}
	printf("\n");*/
	return 0;
}

