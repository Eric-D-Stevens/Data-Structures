#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char* argv[]) {
printf("Helllllooooo\n");

	struct linkedList *list;
	 list = createLinkedList();
	
	/////////////////////////
	//DEQUE INTERFACE TESTING
	/////////////////////////

	printf("\n\nTesting Deque Interface...\n");
	printf("\n\n");
	addBackList(list, 3);  	//3	
	addBackList(list, 6);	//3,6
	addFrontList(list, 9);	//9,3,6
	addFrontList(list, 10);	//10,9,3,6
	addBackList(list, 2);	//10,9,3,6,2
	
	printf("The lists content should be: [10,9,3,6,2]\n");
	printf("Testing Print Function\n");
	printLinkedList(list);
	
	printf("List Not Empty: ");
	if(isEmptyList(list)==0){printf("PASS \n");}
	else { printf("FAIL\n");}
	
	printf("First Element: "); 
	if(frontList(list)==10){printf("PASS\n"); removeFrontList(list);}//9,3,6,1
	else { printf("FAIL\n");}
	
	printf("Second Element: ");
	if(frontList(list)==9){printf("PASS\n"); removeFrontList(list);}	//3,6,2
	else { printf("FAIL\n");}
	
	printf("Third Element: ");
	if(backList(list)==2){printf("PASS\n"); removeBackList(list);}	//3,6
	else { printf("FAIL\n");}
	
	printf("Forth Element: ");
	if(frontList(list)==3){printf("PASS\n"); removeFrontList(list);}	//6
	else { printf("FAIL\n");}
	
	printf("Final Element: ");
	if(frontList(list)==6 && backList(list)==6){printf("PASS\n"); removeFrontList(list);}
	else { printf("FAIL\n");}
	
	printf("List Empty: ");
	if(isEmptyList(list)==1){printf("PASS \n");}
	else { printf("FAIL\n");}


	///////////////////////
	//BAG INTERFACE TESTING
	///////////////////////

	printf("\n\nTesting Bag Interface...\n");
	printf("\n\n");
	addList(list, 3);  	//3
	addList(list, 6);  	//6,3
	addList(list, 9);  	//9,6,3
	addList(list, 10);  //10,9,6,3
	addList(list, 2);  	//2,10,9,6,3	
	printf("The lists content should be: [2,10,9,6,3]\n");	
	printf("Testing Print Function\n");
	printLinkedList(list);
	
	printf("List Not Empty: ");
	if(isEmptyList(list)==0){printf("PASS \n");}
	else { printf("FAIL\n");}
	
	printf("10 Element: ");
	if(containsList(list,10)==1){printf("PASS\n"); removeList(list,10);}	//3,6,9,1
	else { printf("FAIL\n");}
	
	printf("3 Element: ");
	if(containsList(list,3)==1){printf("PASS\n"); removeList(list,3);}	//6,9,1
	else { printf("FAIL\n");}
	
	printf("2 Element: ");
	if(containsList(list,2)==1){printf("PASS\n"); removeList(list,2);}	//6,9
	else { printf("FAIL\n");}	

	printf("6 Element: ");
	if(containsList(list,6)==1){printf("PASS\n"); removeList(list,6);}	//9
	else { printf("FAIL\n");}
	
	printf("9 Element: ");
	if(containsList(list,9)==1){printf("PASS\n"); removeList(list,9);}	//Empty
	else { printf("FAIL\n");}
	
	printf("List Empty: ");
	if(isEmptyList(list)==1){printf("PASS \n");}
	else { printf("FAIL\n");}

	return 0;
}	



