#pragma once

class Number
{
private:
	double realPart;
	double imaginaryPart;

	Number()
	{

	}

public:
	Number(const int &newRealPart)
	{
		realPart = newRealPart;
		imaginaryPart = 0.0;
	}

	Number(const double &newRealPart)
	{
		realPart = newRealPart;
		imaginaryPart = 0.0;
	}

	Number(const double &newRealPart, const double &newImaginaryPart)
	{
		realPart = newRealPart;
		imaginaryPart = newImaginaryPart;
	}

	double getRealPart() const
	{
		return realPart;
	}

	double getImaginaryPart() const
	{
		return imaginaryPart;
	}

	friend Number operator+(Number summand1, const Number &summand2)
	{
		summand1.realPart += summand2.realPart;
		summand1.imaginaryPart += summand2.imaginaryPart;
		return summand1;
	}

	friend Number operator+(Number summand1, const double &summand2)
	{
		summand1.realPart += summand2;
		return summand1;
	}

	friend Number operator+(Number summand1, const int &summand2)
	{
		summand1.realPart += summand2;
		return summand1;
	}

	friend Number operator-(Number minuend, const Number &subtrahent)
	{
		minuend.realPart -= subtrahent.realPart;
		minuend.imaginaryPart -= subtrahent.imaginaryPart;
		return minuend;
	}

	friend Number operator-(Number minuend, const double &subtrahent)
	{
		minuend.realPart -= subtrahent;
		return minuend;
	}

	friend Number operator-(Number minuend, const int &subtrahent)
	{
		minuend.realPart -= subtrahent;
		return minuend;
	}

	Number& operator++()
	{
		realPart += 1.0;
		return *this;
	}

	Number operator++(int)
	{
		Number returnNumber(*this);
		++(*this);
		return returnNumber;
	}

	Number& operator--()
	{
		realPart -= 1.0;
		return *this;
	}

	Number operator--(int)
	{
		Number returnNumber(*this);
		--(*this);
		return returnNumber;
	}

	friend Number operator*(Number factor1, const Number &factor2);

	friend Number operator/(Number numerator, const Number &denominator);
};

bool operator<(const Number &one, const Number &other);

bool operator>(const Number &one, const Number &other);

bool operator<=(const Number &one, const Number &other);

bool operator>=(const Number &one, const Number &other);

bool operator==(const Number &one, const Number &other);

bool operator!=(const Number &one, const Number &other);

Number operator^(const Number &one, int power);
