/* CS261- Assignment 2 - calc.c*/
/* Name:Eric Stevens(001) && Chad Gibeaut(002)
 * Date:
 * Solution description:
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "dynamicArray.h"


/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;
	
	//Deals with e and pi
	if (strcmp(s, "e") == 0){*num = 2.718281; return 1;}
	if (strcmp(s, "pi") == 0){*num = 3.14159; return 1;}
		
	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	
	
	
	else 
	{
		returnNum = strtod(s, &end);
		/* If there's anythin in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
	double n1;
	double n2;
	double n;
	n1 = topDynArr(stack); popDynArr(stack);
	n2 = topDynArr(stack); popDynArr(stack);
	n = n1+n2;
	pushDynArr(stack, n);	
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	double n1;
	double n2;
	double n;
	n1 = topDynArr(stack); popDynArr(stack);
	n2 = topDynArr(stack); popDynArr(stack);
	n = n2-n1;
	pushDynArr(stack, n);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	double n1;
	double n2;
	double n;
	n1 = topDynArr(stack); popDynArr(stack);
	n2 = topDynArr(stack); popDynArr(stack);
	n = (n2/n1);
	pushDynArr(stack, n);
}

//MULTIPLY
void multiply(struct DynArr *stack)
{
	double n1;
	double n2;
	double n;
	n1 = topDynArr(stack); popDynArr(stack);
	n2 = topDynArr(stack); popDynArr(stack);
	n = (n2 * n1);
	pushDynArr(stack, n);
}

//POWER
void power(struct DynArr *stack)
{
	double n1;
	double n2;
	double n;
	n1 = topDynArr(stack); popDynArr(stack);
	n2 = topDynArr(stack); popDynArr(stack);
	n = pow(n2, n1);
	pushDynArr(stack, n);
}

//SQUARE
void square(struct DynArr *stack)
{
	double n2;
	double n;
	n2 = topDynArr(stack); popDynArr(stack);
	n = pow(n2, 2);
	pushDynArr(stack, n);
}

//CUBE
void cube(struct DynArr *stack)
{
	double n2;
	double n;
	n2 = topDynArr(stack); popDynArr(stack);
	n = pow(n2, 3);
	pushDynArr(stack, n);
}

//ABSOLUTE VALUE
void absfun(struct DynArr *stack)
{
	double n2;
	double n;
	n2 = topDynArr(stack); popDynArr(stack);
	n = abs(n2);
	pushDynArr(stack, n);
}

//SQUARE ROOT
void squareroot(struct DynArr *stack)
{
	double n2;
	double n;
	n2 = topDynArr(stack); popDynArr(stack);
	n = sqrt(n2);
	pushDynArr(stack, n);
}

//e TO THE POWER OF
void exponent(struct DynArr *stack)
{
	double n2;
	double n;
	n2 = topDynArr(stack); popDynArr(stack);
	n = pow(2.718281, n2);
	pushDynArr(stack, n);
}

//NATURAL LOG
void natlog(struct DynArr *stack)
{
	double n2;
	double n;
	n2 = topDynArr(stack); popDynArr(stack);
	n = log(n2);
	pushDynArr(stack, n);
}

//LOG BASE 10
void logfun(struct DynArr *stack)
{
	double n2;
	double n;
	n2 = topDynArr(stack); popDynArr(stack);
	n = log10(n2);
	pushDynArr(stack, n);
}
///////////////////////////
//////////////////////////

double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	char *s;
	struct DynArr *stack;

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++) 
	{
		s = inputString[i];
		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if(strcmp(s, "+") == 0)
			add(stack);
		else if(strcmp(s,"-") == 0)
			subtract(stack);
		else if(strcmp(s, "/") == 0)
			divide(stack);
		else if(strcmp(s, "x") == 0)
			multiply(stack);
		else if(strcmp(s, "^") == 0)
			power(stack);
		else if(strcmp(s, "^2") == 0)
			square(stack);	
		else if(strcmp(s, "^3") == 0)
			cube(stack);
		else if(strcmp(s, "abs") == 0)
			absfun(stack);
		else if(strcmp(s, "sqrt") == 0)
			squareroot(stack);
		else if(strcmp(s, "exp") == 0)
			exponent(stack);
		else if(strcmp(s, "ln") == 0)
			natlog(stack);
		else if(strcmp(s, "log") == 0)
			logfun(stack);
		else if(isNumber(s, &result)){pushDynArr(stack, result);}
		else 
		{
			printf("\n\nINVALID ENTRY\n\n "); exit(1);
		}
	}	//end for 

	
	result = topDynArr(stack);
	popDynArr(stack);
	if(isEmptyDynArr(stack) == 1){return result;}
	printf("\n\nINVALID ENTRY\n\n "); exit(1);
	return 0;
}

int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;
	
	printf("\n\n%f\n\n",calculate(argc,argv));
	
	return 0;
}
