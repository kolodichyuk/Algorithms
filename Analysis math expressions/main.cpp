#include <iostream>
#include <conio.h>
#include "analysis.h"

using namespace std;
int main() {
	Analysis* analysis = new Analysis();
	cout << "2+2*2 = "                 << analysis->Calculation("2+2*2") 
		   << "\n3.5*2+3 = "             << analysis->Calculation("3.5*2+3") 
		   << "\n(5*6 - 3) + 3^(2*2) = " << analysis->Calculation("(5*6 - 3) + 3^(9%5)")
		   << "\n4.562*2 + 3 - 5/2 + (3*2 + 5)*6.3/2 + 5*(25 - 4)*2^5 = " 
		                                 << analysis->Calculation("22*2 + 3 - 5/2 + (3*2 + 5)*10/2 + 5*(25 - 4)*2%3") << "\n";
	_getch();
	delete analysis;
	return 0;
}
