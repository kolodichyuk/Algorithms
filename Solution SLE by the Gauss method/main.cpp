#include <iostream>
#include <vector>
#include <iterator>
#include <conio.h>
using namespace std;

void Swap(double&, double&);
vector<double> Gauss(vector<vector<double>>, vector<double>);

void Swap(double &a, double &b) {
	double temp = a;
	a = b;
	b = temp;
}

vector<double> Gauss(vector<vector<double>> matrix, vector<double> free) {
	int n = matrix.size();
	for (int k = 0; k < n; ++k) {
		if (matrix[k][k] == 0.0) {
			for (int i = k + 1; i < n; ++i) {
				if (matrix[i][k] != 0.0) {
					for (int j = 0; j < n; ++j)
						swap(matrix[i][j], matrix[k][j]);
					Swap(free[i], free[k]);
					break;
				}
			}
		}
		double div = matrix[k][k];
		for (int j = 0; j < n; ++j)
			matrix[k][j] /= div;
		free[k] /= div;
		for (int i = k + 1; i < n; ++i) {
			double multi = matrix[i][k];
			for (int j = 0; j < n; ++j)
				matrix[i][j] -= multi * matrix[k][j];
			free[i] -= multi * free[k];
		}
	}
	for (int k = n - 1; k > 0; --k) {
		for (int i = k - 1; i + 1 > 0; --i) {
			double multi = matrix[i][k];
			for (int j = 0; j < n; ++j)
				matrix[i][j] -= multi * matrix[k][j];
			free[i] -= multi * free[k];
		}
	}
	return free;
}

int main() {
	// matrix of coefficients for unknowns
	vector<vector<double>> matrix {
		{8, -2,  3,  6},
		{1, -3, -4,  0},
		{0,  8, -1,  3},
		{5, -2,  9, -6},
	};
	// vector of free coefficients the system of equations
	vector<double> free = {8, 5, 0, 7};
	auto result = Gauss(matrix, free); // run Gauss method
	// output the vector of answers
	cout << "X = {";
	for (auto it = result.begin(); it != result.end(); it++) {
		if (it != result.end() - 1)
			cout << *it << ", ";
		else
			cout << *it << "}\n"; 
	}
	_getch();
	return 0;
}
