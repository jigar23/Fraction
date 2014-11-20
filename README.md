Fraction
========

Includes mathematical operations for fractions

=========================================
Compiling
=========================================

Clone the repo: <br>
git clone git@github.com:jigar23/Fraction.git <br>

or Directly download the zip file. <br>

<b> Compile the code as : </b> <br> 
g++ debug.cc src/Fraction.cc -o debug <br>
./debug <br>

This will check if all the test cases are passed. <br>

Enter your own code in main.cc and compile as follows: <br>
g++ main.cc src/Fraction.cc -o main <br>
./main <br>

=========================================
Defining Fractions
=========================================
Fractions can be defined as: <br>
Fraction a(1,2); // a = 1/2 <br>
Fraction a(1); // a = 1/1 <br>
Fraction a; // by default a = 0/1 <br>
OR <br>
Fraction a; <br>
a.setValue(5,4); // a = 5/4 <br>

NOTE: <br>
- If you set the den as 0, you will get 'divide by zero' error <br>
- a.num and a.den are private members. Accessig these members directly will throw error. <br>

In order to change num or den, use the getNum()/setNum(int) or getDen()/setDen(int) functions <br>
a.setNum(1); <br>
b = a.getDen();<br>

========================================
Arithmetic operations
========================================
All the common arithmetic operations can be directly performed on these fractions <br>

Fraction a(1,2); <br>
Fraction b(-2,3); <br>
Fraction result; <br>

E.g. Addition <br>
------------- <br>
result = a + b; <br>
result = 1 + a; <br>
result = a + 2; <br>
a += 1; <br>
a += b; <br>

Similar operations can be performed for subtraction, multiplication and division. <br>

NOTE: <br>
The file is designed to work only with integers. <br>
num = 3.7 will be converted to num = 3 <br>
den = 0.9 will be converted to den = 0 and will throw 'divide by zero' exception <br>
Also a = a + 3.7 --> a = a + 3 <br>

=============================================
Relational Operator
=============================================

Relational operations can be directly performed on fractions <br>

a < b <br>
a <= b <br>
a < 2 <br>
2 < a <br>

Similar operations can be performed for > <br>

==============================================
Assignment operator
==============================================

a = b; <br>
 
NOTE: <br>
a = 2; // In this, a is *not* a fraction. <br>

==============================================
Display 
==============================================

Fractions can be directly displayed using cout <br>

cout << a; <br>

==== x ========== x ========== x ======= x ===== <br>

For any doubts, feel free to email me. <br>


























