/*! \file main.cpp
\brief This file holds the application demonstrating the library.

This application takes the user input command/chain of commands, and performs them sequentially.
The numeric arguments can be written in regular or scientific format.
The commands should have the following format:
+FLOATING_POINT_VALUE - performs an addition operation with the given FLOATING_POINT_VALUE
-FLOATING_POINT_VALUE - performs an subtraction operation with the given FLOATING_POINT_VALUE
*FLOATING_POINT_VALUE - performs an multiplication operation with the given FLOATING_POINT_VALUE
xFLOATING_POINT_VALUE - performs an multiplication operation with the given FLOATING_POINT_VALUE
/FLOATING_POINT_VALUE - performs an division operation with the given FLOATING_POINT_VALUE
h - displays the command history
c - resets the calculator
u - undoes the last operation
q - exits the application

If a number is provided without any of the listed arithmetic operators, the calculator resets,
and the given value is added to the initial calculator value.

The commands can be chained as follows:
+12.4*2/4+8c12/4*3
This will perform the operation in the order in which they were written in (it disregards the mathematical order of operations).
In this example the result will be 9, because upon reaching the letter 'c', the calculator will reset.
*/
#include <Calculator.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <regex>

using namespace std;

/*! \brief Extracts a single numerical value from the given input string.

This function processes the input, starting from the character number specified by offset.
The found value is written to the value parameter.
\param[in] offset the character number that the analysis should begin on
\param[in] input the parsed string
\param[out] numberOfCharsRead the number of read characters
\param[out] value the numerical value found
*/
int getValueFromCommandString(const int &offset, string &input,  int &numberOfCharsRead, double &value)
{
	smatch stringMatches;
	string truncatedInput = input.substr(offset, input.length() - offset);
	if(!regex_search(truncatedInput, stringMatches, regex("^[\\d\\.]+")))
	{
		numberOfCharsRead = 0;
		return 0;
	}
	value = stod(stringMatches.str());
	numberOfCharsRead = stringMatches.str().length();
	return 1;
}

int main(int argc, char **argv)
{
	Calculator calc;
	string commandString;
	int numberOfCharactersRead;
	double value;
	cout << setprecision(std::numeric_limits<double>::digits10 + 1);
	while (true)
	{
		cout << "Current total: " << calc.getCurrentTotal() << endl;
		cin >> commandString;
		for (unsigned int i = 0; i < commandString.length(); ++i)
			switch (commandString.at(i))
			{
			case '+':
				i++;
				if (getValueFromCommandString(i, commandString, numberOfCharactersRead, value) > 0)
				{
					calc.addValue(value);
					i += (numberOfCharactersRead-1);
				}
				break;
			case '-':
				i++;
				if (getValueFromCommandString(i, commandString, numberOfCharactersRead, value) > 0)
				{
					calc.subtractValue(value);
					i += (numberOfCharactersRead - 1);
				}
				break;
			case '*':
			case 'x':
				i++;
				if (getValueFromCommandString(i, commandString, numberOfCharactersRead, value) > 0)
				{
					calc.multiplyBy(value);
					i += (numberOfCharactersRead - 1);
				}
				break;
			case '/':
				i++;
				if (getValueFromCommandString(i, commandString, numberOfCharactersRead, value) > 0)
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
				cout << "Undoing the last operation." << endl;
				calc.undo();
				break;
			case 'q':
				return 0;
			default:
				if (getValueFromCommandString(i, commandString, numberOfCharactersRead, value) > 0)
				{
					calc.clear();
					calc.addValue(value);
					i += (numberOfCharactersRead-1);
				}
				break;
			}
	}
}
