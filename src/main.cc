/*
 * main.cc
 *
 *  Created on: Nov 18, 2014
 *      Author: jigar
 */

#include <iostream>
#include <assert.h>
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

	//Test cases for multiplication
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

	//Test cases for division
	a.setValue(-1,2);
	b.setValue(-2,3);
	result = a * b;
	check.setValue(1,3);
	assert((check == result) && "Wrong result for - (obj - obj)");
	result = a * 3;
	check.setValue(-3,2);
	assert((check == result) && "Wrong result for - (obj - const)");
	result = 3 * b;
	check.setValue(-2,1);
	assert((check == result) && "Wrong result for - (const - obj)");

	//Test cases for relational assignment operator
	result.setValue(-1,-2);
	check.setValue(1,2);
	assert((check == result) && "Wrong result for == ((-,-) = (+,+))");
	result.setValue(1,-2);
	check.setValue(-1,2);
	assert((check == result) && "Wrong result for == ((-,+) = (+,-))");
	result.setValue(10,8);
	check.setValue(5,4);
	assert((check == result) && "Wrong result for == ((ax,ay) = (x,y))");

	std::cout << "Has passed all the test cases" << std::endl;

	return 0;
}


