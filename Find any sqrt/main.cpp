#include <iostream>
#include <conio.h>
double FAS(double);

using namespace std;
int main() {
	cout << "Sqrt(25): "  << FAS(25) << "\n"
             << "Sqrt(11): "  << FAS(11) << "\n"
	     << "Sqrt(31): "  << FAS(31) << "\n"
	     << "Sqrt(46): "  << FAS(46) << "\n"
             << "Sqrt(64): "  << FAS(64) << "\n"
	     << "Sqrt(72): "  << FAS(72) << "\n";
	_getch();
	return 0;
}

double FAS(double value) {
	double result = 0.0;
	for (int i = 1; i <= 200; i++)
		result -= (result * result - value) / (2 * value);
	return result;
}
