#pragma once
#include <ostream>

class Number
{
private:
	double realPart;
	double imaginaryPart;

	Number()
	{

	}

public:
	Number(const int &newRealPart);
	Number(const double &newRealPart);
	Number(const double &newRealPart, const double &newImaginaryPart);

	double getRealPart() const;
	double getImaginaryPart() const;

	friend Number operator+(Number summand1, const Number &summand2);
	friend Number operator+(Number summand1, const double &summand2);
	friend Number operator+(Number summand1, const int &summand2);
	Number& operator +=(const Number& summand);

	friend Number operator-(Number minuend, const Number &subtrahent);
	friend Number operator-(Number minuend, const double &subtrahent);
	friend Number operator-(Number minuend, const int &subtrahent);
	Number& operator -=(const Number& subtrahent);

	Number& operator++();
	Number operator++(int);

	Number& operator--();
	Number operator--(int);

	friend Number operator*(Number factor1, const Number &factor2);
	Number& operator *=(const Number& subtrahent);

	friend Number operator/(Number numerator, const Number &denominator);
	Number& operator /=(const Number& subtrahent);
};

bool operator!(const Number &arg);

bool operator<(const Number &one, const Number &other);
bool operator<=(const Number &one, const Number &other);

bool operator>(const Number &one, const Number &other);
bool operator>=(const Number &one, const Number &other);

bool operator==(const Number &one, const Number &other);
bool operator!=(const Number &one, const Number &other);

Number operator^(const Number &one, int power);

std::ostream& operator<<(std::ostream& os, const Number& dt);
