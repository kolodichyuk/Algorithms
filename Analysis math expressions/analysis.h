#include <cstdlib>
#include <cctype>
using namespace std;

// class which implements analysis math expressions
class Analysis {
	private: 
		enum TokenTypes { NONE, DELIMITER, NUMBER } tokenType;
		string exp, token, allOperations = "+-*/^%()";
		int expIdx;

		#pragma region Analysis expression 
		double LowestPriority(double &result) {
			string operation = "";
			double partialResult = 0.0;
			result = SecondPriority(result);
			while ((operation = token) == "+" || operation == "-") {
				GetToken();
				partialResult = SecondPriority(partialResult);
				if (operation == "-")
					result -= partialResult;
				else if (operation == "+")
					result += partialResult;
			}
			return result;
		}
		double SecondPriority(double &result) {
			string operation = "";
			double partialResult = 0.0;
			result = ThirdPriority(result);
			while ((operation = token) == "*" || operation == "/" || operation == "%") {
				GetToken();
				partialResult = ThirdPriority(partialResult);
				if (operation == "*")
					result *= partialResult;
				else if (operation == "/")
					result /= partialResult;
				else if (operation == "%")
					result = (int)result % (int)partialResult; 
			}
			return result;
		}
		double ThirdPriority(double &result) {
			double partialResult = 0.0, ex = 0.0;
			int temp = 0;
			result = Evalute(result);
			if (token == "^") {
				GetToken();
				partialResult = ThirdPriority(partialResult);
				ex = result;
				if (partialResult == 0.0)
					return 1.0;
				for (temp = (int)partialResult - 1; temp > 0; temp--)
					result *= ex;
			}
			return result;
		}
		double Evalute(double &result) {
			string operation = "";
			if ((tokenType == DELIMITER) && token == "+" || token == "-") {
				operation = token;
				GetToken();
			}
			result = HighestPriority(result);
			if (operation == "-")
				result = -result;
			return result;
		}
		double HighestPriority(double &result) {
			if (token == "(") {
				GetToken();
				result = LowestPriority(result);
				GetToken();
				return result;
			} else
				return Atom(result);
		}
		double Atom(double &result) {
			if (tokenType == NUMBER) {
				result = atof(token.c_str());
				GetToken();
				return result;
			} else {
				result = 0.0;
				return result;
			}
		}
		#pragma endregion

		#pragma region Getting a token
		void GetToken() {
			tokenType = NONE;
			token = "";
			if (expIdx == exp.length())
				return;
			while (expIdx < exp.length() && exp[expIdx] == ' ')
				expIdx++;
			if (expIdx == exp.length())
				return;
			if (IsDelim(exp[expIdx])) {
				token += exp[expIdx];
				expIdx++;
				tokenType = DELIMITER;
			} else if (isdigit(exp[expIdx])) {
				while (!IsDelim(exp[expIdx])) {
					token += exp[expIdx];
					expIdx++;
					if (expIdx >= exp.length())
						break;
				}
				tokenType = NUMBER;
			}
		}
		bool IsDelim(char token) {
			if (allOperations.find(token) != string::npos)
				return true;
			return false;
		}
		#pragma endregion
	public:
		double Calculation(string expStr) {
			double result = 0.0;
			exp = expStr;
			expIdx = 0;
			GetToken();
			if (token == "")
				return 0.0;
			result = LowestPriority(result);
			if (token != "")
				return 0.0;
			return result;
		}
};
