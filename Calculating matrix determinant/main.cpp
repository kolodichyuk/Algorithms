#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;
void ToUpperTriangular(vector<vector<double>> &matrix);

void ToUpperTriangular(vector<vector<double>> &matrix) {
	int n = matrix.size(), temp;
	double v;
	for (int k = 0; k < n - 1; k++) {
		temp = k;
		for (int i = k + 1; i < n; i++) {
			if (fabs(matrix[temp][k]) < fabs(matrix[i][k])) {
				temp = i;
			}
		}
		if (temp != k) {
			for (int j = 0; j < n; j++) {
				v = matrix[temp][j];
				matrix[temp][j] = matrix[k][j];
				matrix[k][j] = v;
			}
		}
		for (int i = k + 1; i < n; i++) {
			v = matrix[i][k] / matrix[k][k];
			matrix[i][k] = 0;
			if (v != 0)
				for (int j = k + 1; j < n; j++) {
					matrix[i][j] = matrix[i][j] - v * matrix[k][j];
				}
		}
	}
}

int main() {
	// inital matrix
	vector<vector<double>> matrix {
		{8, 1, 6, 2},
		{6, 4, 4, 1},
		{2, 0, 3, 5},
		{7, 9, 3, 2},
	};
	// bringing the matrix to the upper triangular shape
	ToUpperTriangular(matrix);
	// calculating determinant
	double det = 1;
	for (int i = 0; i < matrix.size(); i++)
		det *= matrix[i][i];
	cout << "det: " << det;
	_getch();
	return 0;
}
