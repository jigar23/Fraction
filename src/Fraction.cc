/*
 * Fraction.cc
 *
 *  Created on: Nov 18, 2014
 *      Author: jigar
 */

#include "Fraction.h"
#include <math.h>
/**
 * Default constructor;
 */
Fraction::Fraction()
{
	num = 0;
	den = 1;
}

/**
 * Parameterized constructor;
 */
Fraction::Fraction(int num, int den)
{
	this->num = num;
	this->den = den;
}

void Fraction::setValue(int num, int den)
{
	this->num = num;
	this->den = den;
}

/**
 * Function for addition operation
 * Used when adding two fractions
 */
Fraction Fraction::operator+(const Fraction& right)
{
	Fraction sum;
	sum.num = (this->num * right.den + right.num * this->den);
	sum.den = this->den * right.den;
	simplify(sum);
	return sum;
}

/**
 * Function for addition operation
 * Used when adding fraction with integer
 */
Fraction Fraction::operator+(int right)
{
	Fraction sum;
	sum.num = (this->num  + right * this->den);
	sum.den = this->den;
	simplify(sum);
	return sum;
}

/**
 * Friend Function for addition operation
 * Used when adding integer with fraction
 */
Fraction operator+(int left, const Fraction& right)
{
	Fraction sum;
	sum.num = (left * right.den + right.num);
	sum.den = right.den;
	sum.simplify(sum);
	return sum;
}

/**
 * Relational operator
 */
bool Fraction::operator==(const Fraction left)
{
	return (this->num == left.num && this->den == left.den);
}

void Fraction::display()
{
	std::cout << num << "/" << den << std::endl;
}

/**
 * Takes GCD of 2 numbers
 * useful when simplifying fraction
 * Refer simplify()
 */
int gcd(double num, double den){
    if(den == 0){
       return num;
    }
    return gcd(den, fmod(num, den));
}

/**
 * This function simplifies the fraction
 * e.g. 10/8 = 5/4
 */
void Fraction::simplify(Fraction& result)
{
	int gcd_o = gcd(result.num, result.den);
	result.num = result.num/gcd_o;
	result.den = result.den/gcd_o;
}
