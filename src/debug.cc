/*
 * main.cc
 *
 *  Created on: Nov 18, 2014
 *      Author: jigar
 */

#include <iostream>
#include <assert.h>
#include <ostream>
#include "Fraction.h"

int main()
{
	Fraction a(1,2);
	Fraction b(3,4);
	Fraction check;

	//Test cases for additions
	Fraction result = a + b;
	check.setValue(5,4);
	assert((check == result) && "Wrong result for + (obj + obj)");
	result = a + 3;
	check.setValue(7,2);
	assert((check == result) && "Wrong result for + (obj + const)");
	result = 3 + a;
	assert((check == result) && "Wrong result for + (const + obj)");
	Fraction self(1);
	self += a;
	check.setValue(3,2);
	assert((check == self) && "Wrong result for += (obj + obj)");
	self.setValue(1);
	self += 2;
	check.setValue(3);
	assert((check == self) && "Wrong result for += (obj + const)");

	//Test cases for subtractions
	result = a - b;
	check.setValue(-1,4);
	assert((check == result) && "Wrong result for - (obj - obj)");
	result = a - 3;
	check.setValue(-5,2);
	assert((check == result) && "Wrong result for - (obj - const)");
	result = 3 - a;
	check.setValue(5,2);
	assert((check == result) && "Wrong result for - (const - obj)");
	self.setValue(1);
	self -= a;
	check.setValue(1,2);
	assert((check == self) && "Wrong result for -= (obj - obj)");
	self.setValue(1);
	self -= 2;
	check.setValue(-1);
	assert((check == self) && "Wrong result for -= (obj - const)");

	//Test cases for division
	a.setValue(-1,2);
	b.setValue(3,2);
	result = a / b;
	check.setValue(-1,3);
	assert((check == result) && "Wrong result for / (obj / obj)");
	result = a / 3;
	check.setValue(-1,6);
	assert((check == result) && "Wrong result for / (obj / const)");
	result = 3 / b;
	check.setValue(2,1);
	assert((check == result) && "Wrong result for / (const / obj)");
	self.setValue(1);
	self /= a;
	check.setValue(-2);
	assert((check == self) && "Wrong result for /= (obj / obj)");
	self.setValue(1);
	self /= 2;
	check.setValue(1,2);
	assert((check == self) && "Wrong result for /= (obj / const)");

	//Test cases for multiplication
	a.setValue(-1,2);
	b.setValue(-2,3);
	result = a * b;
	check.setValue(1,3);
	assert((check == result) && "Wrong result for * (obj * obj)");
	result = a * 3;
	check.setValue(-3,2);
	assert((check == result) && "Wrong result for * (obj * const)");
	result = 3 * b;
	check.setValue(-2,1);
	assert((check == result) && "Wrong result for * (const * obj)");
	self.setValue(1);
	self *= a;
	check.setValue(-1,2);
	assert((check == self) && "Wrong result for *= (obj * obj)");
	self.setValue(1);
	self *= 2;
	check.setValue(2);
	assert((check == self) && "Wrong result for *= (obj * const)");

	//Test cases for less than
	result.setValue(-1,2);
	check.setValue(1,3);
	assert((result < check) && "Wrong result for < (obj < obj)");
	check.setValue(-3,2);
	assert((check < -1) && "Wrong result for < (obj < const)");
	check.setValue(2,1);
	assert((1/2 < check) && "Wrong result for < (const < obj)");
	check.setValue(-1,2);
	assert((result <= check) && "Wrong result for < (obj < obj)");
	check.setValue(-3,2);
	assert(!(result <= -2) && "Wrong result for < (obj < const)");

	//Test cases for greater than
	result.setValue(-1,2);
	check.setValue(1,3);
	assert((check > result) && "Wrong result for > (obj > obj)");
	check.setValue(2,1);
	assert((check > 1/2) && "Wrong result for > (const > obj)");
	check.setValue(-3,2);
	assert((-1 > check) && "Wrong result for > (obj > const)");
	check.setValue(1,2);
	assert((check >= 1/2) && "Wrong result for > (const > obj)");
	check.setValue(-3,2);
	assert((-1 >= check) && "Wrong result for > (obj > const)");

	//Test cases for relational equal operator
	result.setValue(-1,-2);
	check.setValue(1,2);
	assert((check == result) && "Wrong result for == ((-,-) == (+,+))");
	result.setValue(10,8);
	check.setValue(5,4);
	assert((check == result) && "Wrong result for == ((ax,ay) == (x,y))");
	check.setValue(-1,1);
	assert((check == -1) && "Wrong result for == ((-1,1) == -1)");
	assert((-1 == check) && "Wrong result for == (-1 == (-1,1))");

	//Test cases for relational not equal operator
	result.setValue(-1,-2);
	check.setValue(1,2);
	assert(!(check != result) && "Wrong result for != ((-,-) != (+,+))");
	result.setValue(1,-2);
	check.setValue(1,2);
	assert((check != result) && "Wrong result for != ((+,-) != (+,+))");
	check.setValue(-1,1);
	assert((check != -2) && "Wrong result for != ((-1,1) != -2)");
	assert((-2 != check) && "Wrong result for != (-2 = (-1,1))");

	//Test cases for cout
	a.setValue(-1,2);
	b.setValue(3,1);
	std::cout << a;
	std::cout << b;

	std::cout << "Has passed all the test cases" << std::endl;

	return 0;
}



