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

/**
 * Function for addition operation
 * Used when adding two fractions
 */
Fraction Fraction::operator+(const Fraction& right)
{
	Fraction sum;
	sum.num = (this->num * right.den + right.num * this->den);
	sum.den = this->den * right.den;
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
	sum.num = (this->num  + right * this->den);
	sum.den = this->den;
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
 * Function for subtraction operation
 * Used when subtracting two fractions
 */
Fraction Fraction::operator-(const Fraction& right)
{
	Fraction diff;
	diff.num = (this->num * right.den - right.num * this->den);
	diff.den = this->den * right.den;
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
	diff.num = (this->num  - right * this->den);
	diff.den = this->den;
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
 * Function for multiplication operation
 * Used when multiplying two fractions
 */
Fraction Fraction::operator*(const Fraction& right)
{
	Fraction product;
	product.num = (this->num * right.num);
	product.den = this->den * right.den;
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
	product.num = (this->num * right);
	product.den = this->den;
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
 * Function for division operation
 * Used when dividing two fractions
 */
Fraction Fraction::operator/(const Fraction& right)
{
	Fraction i_product;
	i_product.num = (this->num * right.den);
	i_product.den = this->den * right.num;
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
	i_product.num = this->num;
	i_product.den = this->den * right;
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
 * Relational operator
 */
bool Fraction::operator==(Fraction& left)
{
	this->simplify();
	left.simplify();
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
 * This function simplifies and normalizes the fraction
 * e.g. 10/8 = 5/4
 * e.g. 1/-2 = -1/2
 * e.g. -1/-2 = 1/2
 */
void Fraction::simplify()
{
	int gcd_o = gcd(this->num, this->den);
	this->num = this->num/gcd_o;
	this->den = this->den/gcd_o;

	//If denominator 0
	if(this->den == 0)
		throw std::overflow_error("Divide by zero exception");

	//Normalize the values
	// if fraction = 1/-2, make it -1/2
	// we will not have case -1/-2 as the gcd will take care of it
	if (this->den < 0){
		this->num = -this->num;
		this->den = -this->den;
	}

}
