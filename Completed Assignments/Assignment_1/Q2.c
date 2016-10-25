/* CS261- Assignment 1 - Q. 2*/
/* Name: Eric Stevens-001
// Name: Chad Gibeaut-002
 * Date: 10/5/2014
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a=*a*2;
    /*Set b to half its original value*/
    *b=*b/2;
    /*Assign a+b to c*/
    c=*a+*b;
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 7, 8, 9 respectively*/
    int x=7;
    int y=8;
    int z=9;
    /*Print the values of x, y and z*/
    printf("X= %d\n", x );
    printf("Y= %d\n", y);
    printf("Z= %d\n", z);


    /*Call foo() appropriately, passing x,y,z as parameters*/
    printf("Returned Value: %d\n",foo(&x,&y,&z));
    /*Print the value returned by foo*/

    /*Print the values of x, y and z again*/
    printf("X= %d\n", x );
    printf("Y= %d\n", y);
    printf("Z= %d\n", z);

    /*Is the return value different than the value of z?  Why?*/
    // Yes it is different, because the value of z was never changed, where as the pointers to x and y were changed to reflect the new value
    return 0;
}


