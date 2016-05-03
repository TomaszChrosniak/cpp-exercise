#include <Number.h>

Number::Number(const int &newRealPart)
{
	realPart = newRealPart;
	imaginaryPart = 0.0;
}

Number::Number(const double &newRealPart)
{
	realPart = newRealPart;
	imaginaryPart = 0.0;
}

Number::Number(const double &newRealPart, const double &newImaginaryPart)
{
	realPart = newRealPart;
	imaginaryPart = newImaginaryPart;
}

double Number::getRealPart() const
{
	return realPart;
}

double Number::getImaginaryPart() const
{
	return imaginaryPart;
}

Number operator+(Number summand1, const Number &summand2)
{
	summand1.realPart += summand2.realPart;
	summand1.imaginaryPart += summand2.imaginaryPart;
	return summand1;
}

Number operator+(Number summand1, const double &summand2)
{
	summand1.realPart += summand2;
	return summand1;
}

Number operator+(Number summand1, const int &summand2)
{
	summand1.realPart += summand2;
	return summand1;
}

Number& Number::operator +=(const Number& summand)
{
	(*this) = (*this) + summand;
	return (*this);
}

Number operator-(Number minuend, const Number &subtrahent)
{
	minuend.realPart -= subtrahent.realPart;
	minuend.imaginaryPart -= subtrahent.imaginaryPart;
	return minuend;
}

Number operator-(Number minuend, const double &subtrahent)
{
	minuend.realPart -= subtrahent;
	return minuend;
}

Number operator-(Number minuend, const int &subtrahent)
{
	minuend.realPart -= subtrahent;
	return minuend;
}

Number& Number::operator -=(const Number& subtrahent)
{
	(*this) = (*this) - subtrahent;
	return (*this);
}

Number& Number::operator++()
{
	realPart += 1.0;
	return *this;
}

Number Number::operator++(int)
{
	Number returnNumber(*this);
	++(*this);
	return returnNumber;
}

Number& Number::operator--()
{
	realPart -= 1.0;
	return *this;
}

Number Number::operator--(int)
{
	Number returnNumber(*this);
	--(*this);
	return returnNumber;
}

Number& Number::operator *=(const Number& subtrahent)
{
	(*this) = (*this) * subtrahent;
	return (*this);
}

Number& Number::operator /=(const Number& subtrahent)
{
	(*this) = (*this) / subtrahent;
	return (*this);
}

Number operator*(Number factor1, const Number & factor2)
{
	Number returnNumber;
	returnNumber.realPart = factor1.realPart * factor2.realPart
		- factor1.imaginaryPart * factor2.imaginaryPart;
	returnNumber.imaginaryPart = factor1.realPart * factor2.imaginaryPart
		+ factor1.imaginaryPart * factor2.realPart;
	return returnNumber;
}

Number operator/(Number numerator, const Number & denominator)
{
	Number reverseDenom(denominator), conjugatedDenom;
	if (!numerator.getImaginaryPart() && !denominator.getImaginaryPart())
	{
		// THIS IS NECESSARY TO ELIMINATE APPROXIMATION ERRORS WHEN DEALING WITH REAL NUMBERS!
		numerator.realPart = numerator.getRealPart() / denominator.getRealPart();
	}
	else
	{
		reverseDenom.imaginaryPart = -denominator.imaginaryPart;
		conjugatedDenom = denominator * reverseDenom;
		numerator = numerator * reverseDenom;
		numerator.realPart /= conjugatedDenom.realPart;
		numerator.imaginaryPart /= conjugatedDenom.realPart;
	}
	return numerator;
}

bool operator!(const Number &arg)
{
	if (arg.getImaginaryPart() == 0.0)
		return (arg.getRealPart() == 0.0);
	return false;
}

bool operator<(const Number &one, const Number &other)
{
	if (other.getImaginaryPart() || one.getImaginaryPart())
		return false;
	else
		return (one.getRealPart() < other.getRealPart());
}

bool operator<=(const Number &one, const Number &other)
{
	if (other.getImaginaryPart() || one.getImaginaryPart())
		return false;
	else
		return (one.getRealPart() <= other.getRealPart());
}

bool operator>(const Number &one, const Number &other)
{
	if (other.getImaginaryPart() || one.getImaginaryPart())
		return false;
	else
		return (one.getRealPart() > other.getRealPart());
}

bool operator>=(const Number &one, const Number &other)
{
	if (other.getImaginaryPart() || one.getImaginaryPart())
		return false;
	else
		return (one.getRealPart() >= other.getRealPart());
}

bool operator==(const Number &one, const Number &other)
{
	if (other.getImaginaryPart() == one.getImaginaryPart()
		&& other.getRealPart() == one.getRealPart())
		return true;
	return false;
}

bool operator!=(const Number &one, const Number &other)
{
	return !(one == other);
}

Number operator^(const Number &one, int power)
{
	if (power == 0)
		return Number(1, 0);
	if (power == 1)
		return one;
	if (power == 2)
		return (one * one);
	return one ^ (power - 1);
}

std::ostream& operator<<(std::ostream& outputStream, const Number& numberToStream)
{
	outputStream << numberToStream.getRealPart();
	if (numberToStream.getImaginaryPart() != 0.0)
	{
		if (numberToStream.getImaginaryPart() > 0.0)
			outputStream << "+";
		outputStream << "i" << numberToStream.getImaginaryPart();
	}
	return outputStream;
}
