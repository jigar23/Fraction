/*
 * debug.cc
 *
 *  Created on: Nov 18, 2014
 *      Author: jigar
 */

#include <iostream>
#include <assert.h>
#include <ostream>
#include "src/Fraction.h"
using namespace std;

int main()
{
	Fraction a(1,2);
	Fraction b(3,4);
	Fraction check;

	//Test cases for additions
	Fraction result = a + b;
	check.setValue(5,4);
	assert((check == result) && "Wrong result for + (obj + obj)");
	cout << "Test Case: (obj + obj)		: PASSED" << endl;
	result = a + 3;
	check.setValue(7,2);
	assert((check == result) && "Wrong result for + (obj + const)");
	cout << "Test Case: (obj + const)	: PASSED" << endl;
	result = 3 + a;
	assert((check == result) && "Wrong result for + (const + obj)");
	cout << "Test Case: (const + obj)	: PASSED" << endl;
	Fraction self(1);
	self += a;
	check.setValue(3,2);
	assert((check == self) && "Wrong result for += (obj += obj)");
	cout << "Test Case: (obj += obj)		: PASSED" << endl;
	self.setValue(1);
	self += 2;
	check.setValue(3);
	assert((check == self) && "Wrong result for += (obj += const)");
	cout << "Test Case: (obj += const)	: PASSED" << endl << endl;

	//Test cases for subtractions
	result = a - b;
	check.setValue(-1,4);
	assert((check == result) && "Wrong result for - (obj - obj)");
	cout << "Test Case: (obj - obj)		: PASSED" << endl;
	result = a - 3;
	check.setValue(-5,2);
	assert((check == result) && "Wrong result for - (obj - const)");
	cout << "Test Case: (obj - const)	: PASSED" << endl;
	result = 3 - a;
	check.setValue(5,2);
	assert((check == result) && "Wrong result for - (const - obj)");
	cout << "Test Case: (const - obj)	: PASSED" << endl;
	self.setValue(1);
	self -= a;
	check.setValue(1,2);
	assert((check == self) && "Wrong result for -= (obj -= obj)");
	cout << "Test Case: (obj -= obj)		: PASSED" << endl;
	self.setValue(1);
	self -= 2;
	check.setValue(-1);
	assert((check == self) && "Wrong result for -= (obj -= const)");
	cout << "Test Case: (obj -= const)	: PASSED" << endl << endl;

	//Test cases for division
	a.setValue(-1,2);
	b.setValue(3,2);
	result = a / b;
	check.setValue(-1,3);
	assert((check == result) && "Wrong result for / (obj / obj)");
	cout << "Test Case: (obj / obj)		: PASSED" << endl;
	result = a / 3;
	check.setValue(-1,6);
	assert((check == result) && "Wrong result for / (obj / const)");
	cout << "Test Case: (obj / const)	: PASSED" << endl;
	result = 3 / b;
	check.setValue(2,1);
	assert((check == result) && "Wrong result for / (const / obj)");
	cout << "Test Case: (const / obj)	: PASSED" << endl;
	self.setValue(1);
	self /= a;
	check.setValue(-2);
	assert((check == self) && "Wrong result for /= (obj / obj)");
	cout << "Test Case: (obj /= obj)		: PASSED" << endl;
	self.setValue(1);
	self /= 2;
	check.setValue(1,2);
	assert((check == self) && "Wrong result for /= (obj / const)");
	cout << "Test Case: (obj /= const)	: PASSED" << endl << endl;

	//Test cases for multiplication
	a.setValue(-1,2);
	b.setValue(-2,3);
	result = a * b;
	check.setValue(1,3);
	assert((check == result) && "Wrong result for * (obj * obj)");
	cout << "Test Case: (obj * obj)		: PASSED" << endl;
	result = a * 3;
	check.setValue(-3,2);
	assert((check == result) && "Wrong result for * (obj * const)");
	cout << "Test Case: (obj * const)	: PASSED" << endl;
	result = 3 * b;
	check.setValue(-2,1);
	assert((check == result) && "Wrong result for * (const * obj)");
	cout << "Test Case: (const * obj)	: PASSED" << endl;
	self.setValue(1);
	self *= a;
	check.setValue(-1,2);
	assert((check == self) && "Wrong result for *= (obj *= obj)");
	cout << "Test Case: (obj *= obj)		: PASSED" << endl;
	self.setValue(1);
	self *= 2;
	check.setValue(2);
	assert((check == self) && "Wrong result for *= (obj *= const)");
	cout << "Test Case: (obj *= const)	: PASSED" << endl << endl;

	//Test cases for less than
	result.setValue(-1,2);
	check.setValue(1,3);
	assert((result < check) && "Wrong result for < (obj < obj)");
	cout << "Test Case: (obj < obj)		: PASSED" << endl;
	check.setValue(-3,2);
	assert((check < -1) && "Wrong result for < (obj < const)");
	cout << "Test Case: (obj < const)	: PASSED" << endl;
	check.setValue(2,1);
	assert((1/2 < check) && "Wrong result for < (const < obj)");
	cout << "Test Case: (const < ob)		: PASSED" << endl;
	check.setValue(-1,2);
	assert((result <= check) && "Wrong result for <= (obj <= obj)");
	cout << "Test Case: (obj <= obj)		: PASSED" << endl;
	check.setValue(-3,2);
	assert(!(result <= -2) && "Wrong result for <= (obj <= const)");
	cout << "Test Case: (obj <= const)	: PASSED" << endl << endl;

	//Test cases for greater than
	result.setValue(-1,2);
	check.setValue(1,3);
	assert((check > result) && "Wrong result for > (obj > obj)");
	cout << "Test Case: (obj > obj)		: PASSED" << endl;
	check.setValue(2,1);
	assert((check > 1/2) && "Wrong result for > (const > obj)");
	cout << "Test Case: (const > obj)	: PASSED" << endl;
	check.setValue(-3,2);
	assert((-1 > check) && "Wrong result for > (obj > const)");
	cout << "Test Case: (obj > const)	: PASSED" << endl;
	check.setValue(1,2);
	assert((check >= 1/2) && "Wrong result for > (const >= obj)");
	cout << "Test Case: (const >= obj)	: PASSED" << endl;
	check.setValue(-3,2);
	assert((-1 >= check) && "Wrong result for > (obj > const)");
	cout << "Test Case: (obj >= const)	: PASSED" << endl << endl;

	//Test cases for relational equal operator
	result.setValue(-1,-2);
	check.setValue(1,2);
	assert((check == result) && "Wrong result for == ((-,-) == (+,+))");
	cout << "Test Case: ((-,-) == (+,+))	: PASSED" << endl;
	result.setValue(10,8);
	check.setValue(5,4);
	assert((check == result) && "Wrong result for == ((ax,ay) == (x,y))");
	cout << "Test Case: ((ax,ay) == (x,y))	: PASSED" << endl;
	check.setValue(-1,1);
	assert((check == -1) && "Wrong result for == ((-1,1) == -1)");
	cout << "Test Case: ((-1,1) == -1)	: PASSED" << endl;
	assert((-1 == check) && "Wrong result for == (-1 == (-1,1))");
	cout << "Test Case: (-1 == (-1,1))	: PASSED" << endl << endl;

	//Test cases for relational not equal operator
	result.setValue(-1,-2);
	check.setValue(1,2);
	assert(!(check != result) && "Wrong result for != ((-,-) != (+,+))");
	cout << "Test Case: ((-,-) != (+,+)))	: PASSED" << endl;
	result.setValue(1,-2);
	check.setValue(1,2);
	assert((check != result) && "Wrong result for != ((+,-) != (+,+))");
	cout << "Test Case: ((+,-) != (+,+)))	: PASSED" << endl;
	check.setValue(-1,1);
	assert((check != -2) && "Wrong result for != ((-1,1) != -2)");
	cout << "Test Case: ((-1,1) != -2)	: PASSED" << endl;
	assert((-2 != check) && "Wrong result for != (-2 = (-1,1))");
	cout << "Test Case: (-2 != (-1,1))	: PASSED" << endl << endl;

	//Test Cases for assignment operator
	result.setValue(3,2);
	a = result;
	assert((a == result) && "Wrong result for =");
	cout << "Test Case: (=)			: PASSED" << endl << endl;

	//Test cases for cout
	a.setValue(-1,2);
	b.setValue(3,1);
	std::cout << a;
	std::cout << b;
	cout << "Test Case: cout			: PASSED" << endl << endl;

	cout << "-----------------------------" << endl;
	std::cout << "Has passed all the test cases" << std::endl;
	cout << "-----------------------------" << endl;

	return 0;
}


