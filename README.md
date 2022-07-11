
_Printf
=======

Printf is a function that is used to printf a of chars and at the same time choose a format for that string.
In this aproach, the _printf function is going to recieve a array of chars which is going to contain all of the characters to print and its format.
Besides the format, it is able to recieve all of the parameters for its format, such as integers, strings, chars, etc.


Printf functions
================

%d
This is used to print a variable of type int in base 10.

%i
Does the same as "%d". Only difference would be in scanf (man scanf).

%c
Prints a variable containing an ASCII value.

%s
Prints an array of strings.

Printf behavior
===============

As said, this function recieves an array of chars and other arguments that will be printed as well as the array of chars.
This function will begin to go through the entire array of chars and is going to check each character and therefore take a decision on what to do with those. It returns the amount of characters printed.
As it goes through it will check if the current character is a "%", in any other case it will just print the character it is currently checking and add one to the counter. In the case the character is a "%" and the next character is another "%" it will print only one of those symbols and add one to the counter. In the case that the next character isn't the symbol the function will make a call to another function that is going to take the decision of what to do with the character that is right after the "%".
In the get_function function the script checks for a coincidence for any of the available functions (see Printf functions above). If it finds a coincidence the function makes a call to the function that prints the requested format function. Otherwise, it only prints "%" and the following character.
In each of the called functions the script will go through the arguments and print each of the characters. These functions will return the amount of characters printed so the main counter adds those new counted characters.
As it goes through the format array it will eventually find a NULL character which will be the ending character. When that happens it will finish the function by returning the counter as an ingeter


Some examples
=============

Let's say that the user wants to print his age. The user would have to type

_printf("My age is %d\n", age);

What this will do is take the "My age is " format and print it as stated without anything fancy until it reaches the "%". There it checks for the following character which in this case is a "d" which indicates that the parameter that it recieves is going to be a decimal so it prints the value of "age". After that it prints a "\n" which does a line jump.

There are some cases in which maybe it doesn't recieve an existing function so it will just print the characters as stated as in the example beneath.

_printf ("Hi!, %h\n");
