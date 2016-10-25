/* CS261- Assignment 1 - Q. 0*/
/* Name: Eric Stevens-001
// Name: Chad Gibeaut-002
 * Date: 10/5/2014
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>


void fooA(int* iptr){
	printf("\nstart the foo function\n");
	/*Print the value pointed to by iptr*/
	printf("the value pointed to by iptr* is: %d\n", *iptr);
	/*Print the address pointed to by iptr*/
	printf("the address pointed to by iptr* is: %p\n", iptr);
	/*Print the address of iptr itself*/
	printf("the adress of iptr is: %p\n", &iptr);
	printf("end the foo function\n\n");

}

int main(){
	printf("\n----------------------------------------------\n\n\n");
	/*declare an integer x*/
	int x = 0;
	/*print the address of x*/
	printf("the address of x is %p\n", &x);
	/*Call fooA() with the address of x*/
	fooA(&x);
	/*print the value of x*/
	printf("the value of x is %d\n", x);
	printf("\n\n\n----------------------------------------------\n");
	return 0;
}
