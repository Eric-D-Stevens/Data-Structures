
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>



int main(){

	clock_t t;
	
	t = clock();

	for(int x=0; x<100000; x++){	printf("\nFUCK!");}

	t = clock() - t;

	printf("\n\n\nClockSs: %f \n\n\n",(float)t/(float)CLOCKS_PER_SEC);
	printf("\n\n\nClockSs Per SeC: %f \n\n\n",(float)t/(float)CLOCKS_PER_SEC);


return 0;}
