/*
 * Fraction.h
 *
 *  Created on: Nov 18, 2014
 *      Author: jigar
 */

#ifndef FRACTION_H_
#define FRACTION_H_
#include <iostream>

class Fraction
{
private:
	int num;
	int den;
public:

	Fraction();
	Fraction(int num, int den);
	void setValue(int num, int den);

	//Addition operator
	Fraction operator+(const Fraction& right);
	Fraction operator+(int right);
	friend Fraction operator+(int left, const Fraction& right);

	//Subtraction operator
	Fraction operator-(const Fraction& right);
	Fraction operator-(int right);
	friend Fraction operator-(int left, const Fraction& right);

	//Multiplication operator
	Fraction operator*(const Fraction& right);
	Fraction operator*(int right);
	friend Fraction operator*(int left, const Fraction& right);

	//Division operator
	Fraction operator/(const Fraction& right);
	Fraction operator/(int right);
	friend Fraction operator/(int left, const Fraction& right);

	//Relational operator
	bool operator==(Fraction& left);

	//Simplify
	void simplify();
	void display();
};


#endif /* FRACTION_H_ */
