#pragma once
/*! \file Operation.h
\brief A file containing the Operation class.
*/

#include <string>
#include <sstream>
#include <iomanip>
#include <limits>

/*! \class Operation
 \brief A class that handles the operations performed by the calculator.
 */
class Operation
{
public:
	/*! An enum holding the defined operation types. */
	typedef enum {
		SUM, /*!< Instances that hold this value as the \sa{operationType} represent the addition operation. */
		SUBTRACTION, /*!< Instances that hold this value as the \sa{operationType} represent the subtraction operation. */
		MULTIPLICATION, /*!< Instances that hold this value as the \sa{operationType} represent the multiplication operation. */
		DIVISION, /*!< Instances that hold this value as the \sa{operationType} represent the division operation. */
		ERROR /*!< Instances that hold this value as the \sa{operationType} represent an errorneous operation. */
	} OPERATION_TYPE;

private:
	OPERATION_TYPE operationType; /*!< Holds the type of the operation performed by this instance of the Operation class. */
	double operationValue; /*!< Holds the operant for this operation. */
	double valueBeforeOperation; /*!< Holds the value before performing the operation. */
								 
	/*! \brief The default constructor made private.

	This is the default zero-argument constructor, that I don't want to be used.
	An operation should have its initial parameters specified at creation time, and hiding the zero-argument constructor enforces that.
	*/
	Operation(); 

public:
	/*! \brief The constructor.
	
	Constructor that requires specifying the member initial values.
	\param[in] newOperationType the type of the operation performed, should be one of the values from \see{OPERATION_TYPE}
	\param[in] newOperandValue the operand value
	*/
	Operation(const OPERATION_TYPE newOperationType, const double &newOperandValue);

	/*! \brief Performs the operation on a value.
	
	This method performes the operation set for this instance with the given operand.
	It also saves the given value in the \see{valueBeforeOperation} member.
	The return value is the calculated result.
	In case of dividing by zero, no operation takes place, and the return value is equal to the given argument.
	\param[in] currentValue the value on which the operation is to be performed
	\return the calculated result
	*/
	double perform(const double &currentValue);

	/*! \brief Returns the initial value from before performing the operation.

	This method returns the on which the operation was last performed on.
	\param currentValue the value before undoing the operation; not used
	\return the argument given when the operation was last performed
	*/
	double undo(const double &currentValue);

	/*! \brief Reverses the operation on the given argument.
	
	This method uses its operand to perform the opposite operation to the one set as this instances' operation type.
	This was initialy used as the undo method, but using it meant that any approximation errors introduced by an operation weren't undone.
	\param currentValue the value on which the opposite operation is to be performed
	\return the calculated result
	*/
	double performReverse(const double &currentValue);

	/*! \brief Returns the operation symbol and value.
	
	\return the operation symbol and value as a std::string object
	*/
	std::string toString();
};
