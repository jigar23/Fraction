Fraction
========

Includes mathematical operations for fractions

=========================================
Compiling
=========================================




To use the file,
#include "src/Fraction.h" in your file.

=========================================
Defining Fractions
=========================================
Fractions can be defined as:
Fraction a(1,2); // a = 1/2
Fraction a(1); // a = 1/1
Fraction a; // by default a = 0/1
OR
Fraction a;
a.setValue(5,4); // a = 5/4

NOTE:
- If you set the den as 0, you will get 'divide by zero' error
- a.num and a.den are private members. Accessig these members directly will throw error.

In order to change num or den, use the getNum()/setNum(int) or getDen()/setDen(int) functions
a.setNum(1);
b = a.getDen();

========================================
Arithmetic operations
========================================
All the common arithmetic operations can be directly performed on these fractions

Fraction a(1,2);
Fraction b(-2,3);
Fraction result;

E.g. Addition
-------------
result = a + b;
result = 1 + a;
result = a + 2;
a += 1;
a += b;

Similar operations can be performed for subtraction, multiplication and division.

NOTE:
The file is designed to work only with integers.
num = 3.3 will be converted to num = 3
den = 0.3 will be converted to den = 0 and will throw 'divide by zero' exception
Also a = a + 3.3 --> a = a + 3

=============================================
Relational Operator
=============================================

Relational operations can be directly performed on fractions

a < b
a <= b
a < 2
2 < a

Similar operations can be performed for >

==============================================
Assignment operator
==============================================

a = b;

NOTE:
a = 2; // In this, a is *not* a fraction.

==============================================
Display
==============================================

Fractions can be directly displayed using cout

cout << a;

==== x ========== x ========== x ======= x =====

For any doubts, feel free to email me.


























