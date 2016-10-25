/* CS261- Assignment 1 - Q. 3*/
/* Name: Eric Stevens-001
// Name: Chad Gibeaut-002
 * Date: 10/5/2014
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void sort(int* number, int n){
	/*Sort the given array number , of length n*/
	int hole = 0;
	int * new = malloc(n * sizeof(int));
	for(int k = 0; k < n + 1; k++){
		for(int i = 0; i < n ; i++){
			if(number[i] == k){
				new[hole] = k;
				hole++;
				number[i] = n+10;
			}
			else;
		}
	}
	for(int x = 0; x<n; x++){number[x]=new[x];}
	free(new);
}

int main(){
	srand(time(NULL));
	/*Declare an integer n and assign it a value of 20.*/
	int n = 20;
	/*Allocate memory for an array of n integers using malloc.*/
	int * list = malloc(n * sizeof(int));
	/*Fill this array with random numbers between 0 and n, using rand().*/
	for(int i = 0; i < n; i++){list[i] = rand()%20 + 1;}
	/*Print the contents of the array.*/
	printf("\n\n\n");
	for(int i = 0; i < n; i++){printf("%d ", list[i]);}
	printf("\n");
	/*Pass this array along with n to the sort() function.*/
	sort(list, n);
	/*Print the contents of the array.*/
	for(int i = 0; i < n; i++){printf("%d ", list[i]);}
	printf("\n\n\n");
	free(list);
	return 0;
}
