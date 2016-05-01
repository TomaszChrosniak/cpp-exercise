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
	double currentTotal; /*!< The current running total. */

	std::stringstream initialStringStream; /*!< The initial value set to the calculator held in a streamstream. */

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

	std::vector<Operation> operationList; /*!< A vector holding the history of performed operations. */

	/*! \brief The default constructor. */
	Calculator();
	
	/*! \brief The constructor that allows to set a different initial value. */
	Calculator(const double &initialValue);

	/* \brief Returns the current running total.
	\return the current total
	*/
	double getCurrentTotal();

	/*! \brief Issues an addition operation with the specified operand.

	This method creates a new \see{Operation} object with \see{Operation::OPERATION_TYPE::SUM} set as its operation type, and the operand passed to it.
	The operation is then added to the operation history and the \see{Operation::perform(double currentValue)} method is called with the currentTotal passed to it.
	The result is saved in the currentTotal member.
	\param[in] value the operand value
	\return the calculated result of the operation
	*/
	double addValue(const double &value);

	/*! \brief Issues a subtraction operation with the specified operand.

	This method acts similarly to \see{addValue}, but creates a new \see{Operation} object with \see{Operation::OPERATION_TYPE::SUBTRACTION}.
	\param[in] value the operand value
	\return the calculated result of the operation
	*/
	double subtractValue(const double &value);

	/*! \brief Issues a multiplication operation with the specified operand.

	This method acts similarly to \see{addValue}, but creates a new \see{Operation} object with \see{Operation::OPERATION_TYPE::MULTIPLICATION} set as its operation type.
	\param[in] value the operand value
	\return the calculated result of the operation
	*/
	double multiplyBy(const double &value);

	/*! \brief Issues an addition operation with the specified operand.

	This method acts similarly to \see{addValue}, but creates a new \see{Operation} object with \see{Operation::OPERATION_TYPE::DIVISION} set as its operation type, and the operand passed to it.
	If the operand is equal to zero, a \see{DivisionByZeroException} is thrown.
	\param[in] value the operand value
	\return the calculated result of the operation
	*/
	double divideBy(const double &value);

	/*! \brief Returns the total prior to performing the last operation.
	It calls the same method as \see{undo}, but does not update the currentTotal, nor does it remove the operations from the \see{operationsList} vector.
	\return the total prior to performing the last operation
	*/
	double getPreviousTotal();

	/*! \brief Undoes the last performed operation.
	This method calls undo on the last performed operation, which is held at the back of the operationsList vector.
	The currentTotal is updated with the value returned.
	Then the last operation is removed from the operationsList.
	\return the total after undoing the operation
	*/
	double undo();

	/*! \brief Returns the command history in string form.
	This method calls the toString methods of all the consecutive Operation objects held in the vector.
	The results are being appended to the end of the string object holding the calculators initial value.
	\return a string holding the command history
	*/
	std::string getOperationsString();

	/*! \brief Resets the calculator.
	This method clears the operationsList vector, resets the currentTotal to 0, and updates the initial value stringstream with the new total.
	*/
	void clear();
};
