/*
 * Fraction.h
 *
 *  Created on: Nov 18, 2014
 *      Author: jigar
 */

#ifndef FRACTION_H_
#define FRACTION_H_
#include <iostream>
#include <ostream>

class Fraction
{
private:
	int num;
	int den;
public:

	Fraction();
	Fraction(int num, int den = 1);
	void setValue(int num, int den = 1);

	//Addition operator
	Fraction operator+(const Fraction& right);
	Fraction operator+(int right);
	friend Fraction operator+(int left, const Fraction& right);
	//self addition a+=b
	Fraction& operator+=(const Fraction& right);
	Fraction& operator+=(int right);

	//Subtraction operator
	Fraction operator-(const Fraction& right);
	Fraction operator-(int right);
	friend Fraction operator-(int left, const Fraction& right);
	//self subtraction a-=b
	Fraction& operator-=(const Fraction& right);
	Fraction& operator-=(int right);

	//Multiplication operator
	Fraction operator*(const Fraction& right);
	Fraction operator*(int right);
	friend Fraction operator*(int left, const Fraction& right);
	//self multiplication a*=b
	Fraction& operator*=(const Fraction& right);
	Fraction& operator*=(int right);

	//Division operator
	Fraction operator/(const Fraction& right);
	Fraction operator/(int right);
	friend Fraction operator/(int left, const Fraction& right);
	//self addition a/=b
	Fraction& operator/=(const Fraction& right);
	Fraction& operator/=(int right);

	//less than operator
	bool operator<(const Fraction &right);
	bool operator<(int left);
	friend bool operator<(int left, const Fraction& right);
	//less than equal to operator
	bool operator<=(const Fraction &right);
	bool operator<=(int left);
	friend bool operator<=(int left, const Fraction& right);

	//greater than operator
	bool operator>(const Fraction &right);
	bool operator>(int left);
	friend bool operator>(int left, const Fraction& right);
	//greater than equal to operator
	bool operator>=(const Fraction &right);
	bool operator>=(int left);
	friend bool operator>=(int left, const Fraction& right);

	//cout
	friend std::ostream& operator<<(std::ostream &out, const Fraction &right);

	//Relational equal operator
	bool operator==(const Fraction& left);
	bool operator==(int right);
	friend bool operator==(int left, const Fraction &right);

	//Relational not equal operator
	bool operator!=(const Fraction& left);
	bool operator!=(int right);
	friend bool operator!=(int left, const Fraction &right);

	//Simplify
	void simplify();
};


#endif /* FRACTION_H_ */
