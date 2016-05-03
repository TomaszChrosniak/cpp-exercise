#include <Number.h>

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
	reverseDenom.imaginaryPart = -denominator.imaginaryPart;
	conjugatedDenom = denominator * reverseDenom;
	numerator = numerator * reverseDenom;
	numerator.realPart /= conjugatedDenom.realPart;
	numerator.imaginaryPart /= conjugatedDenom.realPart;
	return numerator;
}

bool operator<(const Number &one, const Number &other)
{
	if (other.getImaginaryPart() || one.getImaginaryPart())
		return false;
	else
		return (one.getRealPart() < other.getRealPart());
}

bool operator>(const Number &one, const Number &other)
{
	if (other.getImaginaryPart() || one.getImaginaryPart())
		return false;
	else
		return (one.getRealPart() > other.getRealPart());
}

bool operator<=(const Number &one, const Number &other)
{
	if (other.getImaginaryPart() || one.getImaginaryPart())
		return false;
	else
		return (one.getRealPart() <= other.getRealPart());
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
