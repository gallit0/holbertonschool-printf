
_Printf
=======

Printf is a function that is used to printf an array of chars and at the same time choose a format for that string.
In this aproach, the _printf function is going to recieve a array of chars which is going to contain all of the characters to print and its format.
Besides the format, it is able to recieve all of the parameters for its format, such as integers, strings, chars, etc.


_Printf functions
=================

%d
Prints a variable of type int in base 10.

%i
Does the same as "%d". Only differences would be in scanf (man scanf).

%c
Prints a variable containing an ASCII value.

%s
Prints an array of chars.

%b
Prints a variable of type int in base 2.

%u
Prints a variable of type unsigned int.

%o
Prints a variable of type int in base 8.

%x
Prints a variabe of type int in base 16 with lowercase letters.

%X
Does the same as "%x" but uppercase.

%S
Prints an array of chars but replaces non printable characters to their value in hexadecimal.

_Printf behavior
================

As said, this function recieves an array of chars and other arguments that will be printed as well as the array of chars.
This function will begin to go through the entire array of chars and is going to check each character and therefore take a decision on what to do with those. It returns the amount of characters printed.
As it goes through it will check if the current character is a "%", in any other case it will just print the character it is currently checking and add one to the counter. In the case the character is a "%" and the next character is another "%" it will print only one of those symbols and add one to the counter. In the case that the next character isn't the symbol the function will make a call to another function that is going to take the decision of what to do with the character that is right after the "%".
In the get function the script checks for a coincidence for any of the available functions (see Printf functions above). If it finds a coincidence the function makes a call to the function that prints the requested format function. Otherwise, it only prints "%" and the following character.
In each of the called functions the script will go through the arguments and print each of the characters. These functions will return the amount of characters printed so the main counter adds those new counted characters.
As it goes through the format array it will eventually find a NULL character which will be the ending character. When that happens it will finish the function by returning the counter as an ingeter


Some examples
=============

Let's say that the user wants to print his age. The user would have to type

_printf("My age is %d\n", age);

What this will do is take the "My age is " format and print it as stated without anything fancy until it reaches the "%". There it checks for the following character which in this case is a "d" which indicates that the parameter that it recieves is going to be a decimal so it prints the value of "age". After that it prints a "\n" which does a line jump.

There are some cases in which maybe it doesn't recieve an existing function so it will just print the characters as stated as in the example beneath.

_printf ("Hi!, %h\n");


Flowchart
=========

```mermaid
graph TD;
        Start0(Printf)-->If0{Is format NULL?}
        If0-->|Yes|Return0(Return -1)
        If0-->|No|While0{Go through format}
        While0-->If1{Is the character '%'<br> and the following<br>NULL or '%'?}
        If1-->|Yes|Put0[Print '%']-->While0
        If1-->|No|If2{Is the character '%'}
        If2-->|Yes|Call0[Call get_function]-->While0
        If2-->|No|Put1[Print character]-->While0
        While0-->|No more characters|Return1(Return counter of chars)


        Start1(get_func)-->For0{Go through struct<br>of functions}
        For0-->|Yes|If3{Function equals to character<br>after the '%'}-->|Yes|Return2(Call function)
        If3-->|No|For0
        For0-->|No|Put2[Print '%' and the character]-->Return3(Return 2)
```
