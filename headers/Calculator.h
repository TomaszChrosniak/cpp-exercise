#pragma once
/*! \file Calculator.h
\brief A file containing the Calculator class.
*/
#include <exception>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

#include <Operation.h>

/*! \class Calculator
\brief This is the class that performs and holds the performed operations.
*/
class Calculator
{
private:
	Number currentTotal; /*!< The current running total. */

	std::stringstream initialStringStream; /*!< The initial value set to the calculator held in a streamstream. */

	std::vector<Operation> operationList; /*!< A vector holding the history of performed operations. */

public:
	/*! \class DivisionByZeroException
	\brief This class represents the exception thrown by this class when a division by zero is attempted.
	*/
	class DivisionByZeroException : public std::exception
	{
	public:
		/*! \brief Returns the exception reson. */
		virtual const char* what() const throw()
		{
			return "Division by 0.";
		}
	};

	/*! \brief The default constructor. */
	Calculator();
	
	Calculator(const Number &initialValue);

	/*! \brief Returns the current running total.
	\return the current total
	*/
	double getCurrentTotal();

	Number getCurrentTotalComplex();

	/*! \brief Issues an addition operation with the specified operand.

	This method creates a new Operation object with OPERATION_TYPE::SUM set as its operation type, and the operand passed to it.
	The operation is then added to the operationList vector and the Operation::perform() method is called with the currentTotal passed to it.
	The result is saved in the currentTotal member.
	\param[in] value the operand value
	\return the calculated result of the operation
	\see Operation
	*/
	double addValue(const double &value);

	Number addValueComplex(const Number &value);

	/*! \brief Issues a subtraction operation with the specified operand.

	This method acts similarly to addValue, but creates a new Operation object with Operation::OPERATION_TYPE::SUBTRACTION set as its operation type.
	\param[in] value the operand value
	\return the calculated result of the operation
	\see Operation
	*/
	double subtractValue(const double &value);

	Number subtractValueComplex(const Number &value);

	/*! \brief Issues a multiplication operation with the specified operand.

	This method acts similarly to addValue, but creates a new Operation object with Operation::OPERATION_TYPE::MULTIPLICATION set as its operation type.
	\param[in] value the operand value
	\return the calculated result of the operation
	\see Operation
	*/
	double multiplyBy(const double &value);

	Number multiplyByComplex(const Number &value);

	/*! \brief Issues an addition operation with the specified operand.

	This method acts similarly to addValue, but creates a new Operation object with Operation::OPERATION_TYPE::DIVISION set as its operation type.
	If the operand is equal to zero, a DivisionByZeroException is thrown.
	\param[in] value the operand value
	\return the calculated result of the operation
	\see Operation, DivisionByZeroException
	*/
	double divideBy(const double &value);

	Number divideByComplex(const Number &value);

	/*! \brief Returns the total prior to performing the last operation.
	It calls the same method as undo, but does not update the currentTotal, nor does it remove the operations from the operationsList vector.
	\return the total prior to performing the last operation
	*/
	double getPreviousTotal();

	Number getPreviousTotalComplex();

	/*! \brief Undoes the last performed operation.
	This method calls undo on the last performed operation, which is held at the back of the operationList vector.
	The currentTotal is updated with the value returned.
	Then the last operation is removed from the operationList.
	\return the total after undoing the operation
	*/
	double undo();

	Number undoComplex();

	/*! \brief Returns the command history in string form.
	This method calls the Operation::toString() methods of all the consecutive Operation objects held in the vector.
	The results are being appended to the end of the string object holding the calculators initial value.
	\return a string holding the command history
	\see Operation
	*/
	std::string getOperationsString();

	/*! \brief Resets the calculator.
	This method clears the operationList vector, resets the currentTotal to 0, and updates the initialStringStream with the new total.
	*/
	void clear();
};
