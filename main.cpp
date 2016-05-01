#include <iostream>
#include <Calculator.h>
#include <string>
#include <iomanip>

using namespace std;

double value;

int getValueFromCommandString(const int &offset, string &input,  int &numberOfCharsRead)
{
	std::locale loc;
	std::ios::iostate state;
	std::string::iterator end;
	numberOfCharsRead = std::use_facet<std::num_get<char, std::string::iterator> >(loc).get(input.begin()+offset, input.end(), std::cin, state, value) - input.begin() - offset;
	if (numberOfCharsRead > 0)
		return 1;
	return 0;
}

int main(int argc, char **argv)
{
	Calculator calc;
	string commandString;
	int numberOfCharactersRead;
	cout << setprecision(std::numeric_limits<double>::digits10 + 1);
	while (true)
	{
		cout << "Current total: " << calc.getCurrentTotal() << endl;
		cin >> commandString;
		for (unsigned int i = 0; i < commandString.length(); ++i)
		{
			switch (commandString.at(i))
			{
			case '+':
				i++;
				if (getValueFromCommandString(i, commandString, numberOfCharactersRead) > 0)
				{
					calc.addValue(value);
					i += (numberOfCharactersRead-1);
				}
				break;
			case '-':
				i++;
				if (getValueFromCommandString(i, commandString, numberOfCharactersRead) > 0)
				{
					calc.subtractValue(value);
					i += (numberOfCharactersRead - 1);
				}
				break;
			case '*':
				i++;
				if (getValueFromCommandString(i, commandString, numberOfCharactersRead) > 0)
				{
					calc.multiplyBy(value);
					i += (numberOfCharactersRead - 1);
				}
				break;
			case 'x':
				i++;
				if (getValueFromCommandString(i, commandString, numberOfCharactersRead) > 0)
				{
					calc.multiplyBy(value);
					i += (numberOfCharactersRead - 1);
				}
				break;
			case '/':
				i++;
				if (getValueFromCommandString(i, commandString, numberOfCharactersRead) > 0)
				{
					try {
						calc.divideBy(value);
					}
					catch (Calculator::DivisionByZeroException e)
					{
						std::cerr << e.what() << endl;
					}
					i += (numberOfCharactersRead - 1);
				}
				break;
			case 'h':
				cout << "Displaying command history:" << endl << calc.getOperationsString();
				break;
			case 'c':
				cout << "Clearing history." << endl;
				calc.clear();
				break;
			case 'u':
				calc.undo();
				break;
			case 'q':
				return 0;
			default:
				if (getValueFromCommandString(i, commandString, numberOfCharactersRead) > 0)
				{
					calc.clear();
					calc.addValue(value);
					i += (numberOfCharactersRead-1);
				}
				break;
			}
		}
	}
}
