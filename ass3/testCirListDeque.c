#include "cirListDeque.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
        
			struct cirListDeque *list;
	 list = createCirListDeque();
	
	/////////////////////////
	//CIRCULAR DEQUE INTERFACE TESTING
	/////////////////////////

	printf("\n\nTesting Deque Interface...\n");
	printf("\n\n");
	addBackCirListDeque(list, 3);  	//3	
	addBackCirListDeque(list, 6);	//3,6
	addFrontCirListDeque(list, 9);	//9,3,6
	addFrontCirListDeque(list, 10);	//10,9,3,6
	addBackCirListDeque(list, 2);	//10,9,3,6,2
	
	printf("The lists content should be: [10,9,3,6,2]\n");
	printf("Testing Print Function\n");
	printCirListDeque(list);
	
	printf("List Not Empty: ");
	if(isEmptyCirListDeque(list)==0){printf("PASS \n");}
	else { printf("FAIL\n");}
	
	printf("First Element: "); 
	if(frontCirListDeque(list)==10){printf("PASS\n"); removeFrontCirListDeque(list);}//9,3,6,1
	else { printf("FAIL\n");}
	
	printf("Second Element: ");
	if(frontCirListDeque(list)==9){printf("PASS\n"); removeFrontCirListDeque(list);}	//3,6,2
	else { printf("FAIL\n");}
	
	printf("Third Element: ");
	if(backCirListDeque(list)==2){printf("PASS\n"); removeBackCirListDeque(list);}	//3,6
	else { printf("FAIL\n");}
	
	printf("Forth Element: ");
	if(frontCirListDeque(list)==3){printf("PASS\n"); removeFrontCirListDeque(list);}	//6
	else { printf("FAIL\n");}
	
	printf("Final Element: ");
	if(frontCirListDeque(list)==6 && backCirListDeque(list)==6){printf("PASS\n"); removeFrontCirListDeque(list);}
	else { printf("FAIL\n");}
	
	printf("List Empty: ");
	if(isEmptyCirListDeque(list)==1){printf("PASS \n");}
	else { printf("FAIL\n");}

	/* Test your linked list in here! */

	printf("Hello from test code!\n");
	return 0;
}


