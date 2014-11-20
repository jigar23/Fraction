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
Fractions can be defined as: <br>
Fraction a(1,2); // a = 1/2 <br>
Fraction a(1); // a = 1/1 <br>
Fraction a; // by default a = 0/1 <br>
OR <br>
Fraction a; <br>
a.setValue(5,4); // a = 5/4 <br> <br>

NOTE: <br>
- If you set the den as 0, you will get 'divide by zero' error <br>
- a.num and a.den are private members. Accessig these members directly will throw error. <br> <br>

In order to change num or den, use the getNum()/setNum(int) or getDen()/setDen(int) functions <br>
a.setNum(1); <br>
b = a.getDen();<br>

========================================
Arithmetic operations
========================================
All the common arithmetic operations can be directly performed on these fractions <br><br>

Fraction a(1,2); <br>
Fraction b(-2,3); <br>
Fraction result; <br> <br>

E.g. Addition <br>
------------- <br>
result = a + b; <br>
result = 1 + a; <br>
result = a + 2; <br>
a += 1; <br>
a += b; <br> <br>

Similar operations can be performed for subtraction, multiplication and division. <br> <br>

NOTE: <br>
The file is designed to work only with integers. <br>
num = 3.3 will be converted to num = 3 <br>
den = 0.3 will be converted to den = 0 and will throw 'divide by zero' exception <br>
Also a = a + 3.3 --> a = a + 3 <br><br>

=============================================
Relational Operator
=============================================

Relational operations can be directly performed on fractions <br> <br>

a < b <br>
a <= b <br>
a < 2 <br>
2 < a <br>

Similar operations can be performed for > <br>

==============================================
Assignment operator
==============================================

a = b; <br><br>
 
NOTE: <br>
a = 2; // In this, a is *not* a fraction. <br>

==============================================
Display 
==============================================

Fractions can be directly displayed using cout <br><br>

cout << a; <br><br>

==== x ========== x ========== x ======= x ===== <br>

For any doubts, feel free to email me. <br>


























