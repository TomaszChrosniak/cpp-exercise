#pragma once
/*! \file Number.h
\brief This file holds the Number class, that allows for complex number representation
*/
#include <ostream>

/*! \class Number
\brief This class represents a complex number.
This class holds the real and imaginary parts of a number.
If the imaginary part is not needed, then it can be omitted.
Variables of type double can be easily converted to this type.
All of the necessary operators have been defined for this type, including the passing into a stream one.
*/
class Number
{
private:
	double realPart; /*!< The real part of the number. */
	double imaginaryPart; /*!< The complex part of the number. */

	Number()
	{

	}

public:
	/*! \brief A constructor allowing implicit cast from int to Number.
	\param[in] newRealPart the value of the created numbers real part
	*/
	Number(const int &newRealPart);
	/*! \brief A constructor allowing implicit cast from double to Number.
	\param[in] newRealPart the value of the created numbers real part
	*/
	Number(const double &newRealPart);
	/*! \brief A constructor initializing both parts of the number.
	\param[in] newRealPart the value of the created numbers real part
	*/
	Number(const double &newRealPart, const double &newImaginaryPart);

	/*! \brief Returns the real part of the number. */
	double getRealPart() const;
	/*! \brief Returns the imaginary part of the number. */
	double getImaginaryPart() const;

	/*! \brief An addition operator. 
	It realizes complex number addition.
	The process is straightforward - the real part of the result is the sum of the real parts of the summands.
	The imaginary part of the result is the sum of the imaginary parts of the summands.
	*/
	friend Number operator+(Number summand1, const Number &summand2);
	Number& operator +=(const Number& summand);

	/*! \brief A subtraction operator.
	It realizes complex number subtraction.
	The process is straightforward - the real part of the result is the difference between the real part of the minuend and the subtrahend.
	The imaginary part of the result is the difference between the imaginary part of the minuend and the subtrahend.
	*/
	friend Number operator-(Number minuend, const Number &subtrahent);
	Number& operator -=(const Number& subtrahent);

	/*! \brief Prefix incrementation operator.
	This operator increases the real number part value by 1.
	The value is returned after increment.
	*/
	Number& operator++();
	/*! \brief Postfix incrementation operator.
	This operator increases the real number part value by 1.
	The value is returned before increment.
	*/
	Number operator++(int);

	/*! \brief Prefix decrementation operator.
	This operator decreases the real number part value by 1.
	The value is returned after decrement.
	*/
	Number& operator--();
	/*! \brief Postfix decrementation operator.
	This operator decreases the real number part value by 1.
	The value is returned before decrement.
	*/
	Number operator--(int);

	/*! \brief A multiplication operator.
	This operator multiplies the two complex numbers.
	The process is the same as in bracket expansion, but i^2 has to be evaluated to -1.
	*/
	friend Number operator*(Number factor1, const Number &factor2);
	Number& operator *=(const Number& subtrahent);

	/*! \brief A division operator.
	This operator divides the two complex numbers.
	You have to multiply both the numerator and the denominator by the conjugate of the denominator.
	*/
	friend Number operator/(Number numerator, const Number &denominator);
	Number& operator /=(const Number& subtrahent);
};

/*! \brief A zero check operator.
\return true if both the real and imaginary parts are equal to zero.
*/
bool operator!(const Number &arg);

bool operator<(const Number &one, const Number &other);
bool operator<=(const Number &one, const Number &other);

bool operator>(const Number &one, const Number &other);
bool operator>=(const Number &one, const Number &other);

bool operator==(const Number &one, const Number &other);
bool operator!=(const Number &one, const Number &other);

Number operator^(const Number &one, int power);

std::ostream& operator<<(std::ostream& os, const Number& dt);
