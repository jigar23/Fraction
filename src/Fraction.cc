/*
 * Fraction.cc
 *
 *  Created on: Nov 18, 2014
 *      Author: jigar
 */

#include "Fraction.h"
#include <math.h>
#include <stdexcept>
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

	if(den == 0){
		std::cout << "0 value set in den" << std::endl;
		throw std::overflow_error("Divide by zero exception");
	}
	this->den = den;
}

void Fraction::setValue(int num, int den)
{
	this->num = num;

	if(den == 0){
		std::cout << "0 value set in den" << std::endl;
		throw std::overflow_error("Divide by zero exception");
	}
	this->den = den;
}

int Fraction::getDen() const {
	return den;
}

void Fraction::setDen(int den) {
	if(den == 0){
		std::cout << "0 value set in den" << std::endl;
		throw std::overflow_error("Divide by zero exception");
	}
	this->den = den;
}

int Fraction::getNum() const {
	return num;
}

void Fraction::setNum(int num) {
	this->num = num;
}

/**
 * Function for addition operation
 * Used when adding two fractions
 */
Fraction Fraction::operator+(const Fraction& right)
{
	Fraction sum;
	sum.num = (num * right.den + right.num * den);
	sum.den = den * right.den;
	sum.simplify();
	return sum;
}

/**
 * Function for addition operation
 * Used when adding fraction with integer
 */
Fraction Fraction::operator+(int right)
{
	Fraction sum;
	sum.num = (num  + right * den);
	sum.den = den;
	sum.simplify();
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
	sum.simplify();
	return sum;
}

/**
 * Function for addition operation
 * Used when self adding two fractions
 */
Fraction& Fraction::operator+=(const Fraction& right)
{
	num = (num * right.den + right.num * den);
	den = den * right.den;
	this->simplify();
	return *this;
}

/**
 * Function for addition operation
 * Used when self adding fraction with integer
 */
Fraction& Fraction::operator+=(int right)
{
	num = (num  + right * den);
	this->simplify();
	return *this;
}

/**
 * Function for subtraction operation
 * Used when subtracting two fractions
 */
Fraction Fraction::operator-(const Fraction& right)
{
	Fraction diff;
	diff.num = (num * right.den - right.num * den);
	diff.den = den * right.den;
	diff.simplify();
	return diff;
}

/**
 * Function for subtraction operation
 * Used when subtracting fraction with integer
 */
Fraction Fraction::operator-(int right)
{
	Fraction diff;
	diff.num = (num  - right * den);
	diff.den = den;
	diff.simplify();
	return diff;
}

/**
 * Friend Function for subtraction operation
 * Used when subtracting integer with fraction
 */
Fraction operator-(int left, const Fraction& right)
{
	Fraction diff;
	diff.num = (left * right.den - right.num);
	diff.den = right.den;
	diff.simplify();
	return diff;
}

/**
 * Function for subtraction operation
 * Used when self subtracting two fractions
 */
Fraction& Fraction::operator-=(const Fraction& right)
{
	num = (num * right.den - right.num * den);
	den = den * right.den;
	this->simplify();
	return *this;
}

/**
 * Function for subtraction operation
 * Used when self subtracting fraction with integer
 */
Fraction& Fraction::operator-=(int right)
{
	num = (num  - right * den);
	this->simplify();
	return *this;
}

/**
 * Function for multiplication operation
 * Used when multiplying two fractions
 */
Fraction Fraction::operator*(const Fraction& right)
{
	Fraction product;
	product.num = (num * right.num);
	product.den = den * right.den;
	product.simplify();
	return product;
}

/**
 * Function for multiplication operation
 * Used when multiplying fraction with integer
 */
Fraction Fraction::operator*(int right)
{
	Fraction product;
	product.num = (num * right);
	product.den = den;
	product.simplify();
	return product;
}

/**
 * Friend Function for multiplication operation
 * Used when multiplying integer with fraction
 */
Fraction operator*(int left, const Fraction& right)
{
	Fraction product;
	product.num = (left * right.num);
	product.den = right.den;
	product.simplify();
	return product;
}

/**
 * Function for multiplication operation
 * Used when self multiplying two fractions
 */
Fraction& Fraction::operator*=(const Fraction& right)
{
	num = (num * right.num);
	den = den * right.den;
	this->simplify();
	return *this;
}

/**
 * Function for multiplication operation
 * Used when self multiplying fraction with integer
 */
Fraction& Fraction::operator*=(int right)
{
	num = (num * right);
	this->simplify();
	return *this;
}

/**
 * Function for division operation
 * Used when dividing two fractions
 */
Fraction Fraction::operator/(const Fraction& right)
{
	Fraction i_product;
	i_product.num = (num * right.den);
	i_product.den = den * right.num;
	i_product.simplify();
	return i_product;
}

/**
 * Function for division operation
 * Used when dividing fraction with integer
 */
Fraction Fraction::operator/(int right)
{
	Fraction i_product;
	i_product.num = num;
	i_product.den = den * right;
	i_product.simplify();
	return i_product;
}

/**
 * Friend Function for multiply operation
 * Used when dividing integer with fraction
 */
Fraction operator/(int left, const Fraction& right)
{
	Fraction i_product;
	i_product.num = left * right.den;
	i_product.den = right.num;
	i_product.simplify();
	return i_product;
}

/**
 * Function for multiplication operation
 * Used when self multiplying two fractions
 */
Fraction& Fraction::operator/=(const Fraction& right)
{
	num = (num * right.den);
	den = den * right.num;
	this->simplify();
	return *this;
}

/**
 * Function for multiplication operation
 * Used when self multiplying fraction with integer
 */
Fraction& Fraction::operator/=(int right)
{
	den = den * right;
	this->simplify();
	return *this;
}

/**
 * Function for less than operation
 */
bool Fraction::operator<(const Fraction& right)
{
	return ((float)num/den < (float)right.num/right.den);
}

/**
 * Function for less than operation
 */
bool Fraction::operator<(int right)
{
	return ((float)num/den < right);
}

/**
 * Friend Function for less than operation
 */
bool operator<(int left, const Fraction& right)
{
	return (left < (float)right.num/right.den);
}

/**
 * Function for less than equal to operation
 */
bool Fraction::operator<=(const Fraction& right)
{
	return ((float)num/den <= (float)right.num/right.den);
}

/**
 * Function for less than equal to operation
 */
bool Fraction::operator<=(int right)
{
	return ((float)num/den <= right);
}

/**
 * Friend Function for less than equal to operation
 */
bool operator<=(int left, const Fraction& right)
{
	return (left <= (float)right.num/right.den);
}

/**
 * Function for greater than operation
 */
bool Fraction::operator>(const Fraction& right)
{
	return ((float)num/den > (float)right.num/right.den);
}

/**
 * Function for greater than operation
 */
bool Fraction::operator>(int right)
{
	return ((float)num/den > right);
}

/**
 * Friend Function for greater than operation
 */
bool operator>(int left, const Fraction& right)
{
	return (left > (float)right.num/right.den);
}

/**
 * Function for greater than equal to operation
 */
bool Fraction::operator>=(const Fraction& right)
{
	return ((float)num/den >= (float)right.num/right.den);
}

/**
 * Function for greater than equal to operation
 */
bool Fraction::operator>=(int right)
{
	return ((float)num/den >= right);
}

/**
 * Friend Function for greater than equal to operation
 */
bool operator>=(int left, const Fraction& right)
{
	return (left >= (float)right.num/right.den);
}

/**
 * Relational equal operator
 */
bool Fraction::operator==(const Fraction& right)
{
	return ((float)num/den == (float)right.num/right.den);
}

/**
 * Relational equal operator
 */
bool Fraction::operator==(int right)
{
	return ((float)num/den == right);
}

/**
 * Relational equal operator
 */
bool operator==(int left, const Fraction& right)
{
	return (left == (float)right.num/right.den);
}


/**
 * Relational not equal operator
 */
bool Fraction::operator!=(const Fraction& right)
{
	return ((float)num/den != (float)right.num/right.den);
}

/**
 * Relational not equal operator
 */
bool Fraction::operator!=(int right)
{
	return ((float)num/den != right);
}

/**
 * Relational not equal operator
 */
bool operator!=(int left, const Fraction& right)
{
	return (left != (float)right.num/right.den);
}

/**
 * Assignment operator
 */
Fraction& Fraction::operator=(const Fraction &right)
{
	num = right.num;
	den = right.den;
	return *this;
}

/**
 * cout
 */
std::ostream& operator<<(std::ostream &out, const Fraction &right)
{
	if (right.den != 1)
		out << right.num << "/" << right.den;
	else
		out << right.num;
	return out;
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
 * This function simplifies and normalizes the fraction
 * e.g. 10/8 = 5/4
 * e.g. 1/-2 = -1/2
 * e.g. -1/-2 = 1/2
 */
void Fraction::simplify()
{
	int gcd_o = gcd(num, den);
	num = num/gcd_o;
	den = den/gcd_o;

	//If denominator 0
	if(den == 0)
		throw std::overflow_error("Divide by zero exception");

	//Normalize the values
	// if fraction = 1/-2, make it -1/2
	// we will not have case -1/-2 as the gcd will take care of it
	if (den < 0){
		num = -num;
		den = -den;
	}

}
