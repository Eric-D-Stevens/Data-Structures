/* CS261- Assignment 1 - Q.4*/
/* Name: Eric Stevens-001
// Name: Chad Gibeaut-002
 * Date: October 6, 2014
 * Solution description: This program uses function from Q1 and Q3
			modified to handle the task. The modifications
			make the program more powerful by allowing for
			any int sized value to be plugged in for n.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student{
	int id;
	int score;
};

struct student* allocate(int n){
	/*Allocate memory for ten students*/
	struct student * list = malloc(n * sizeof(struct student));
	/*return the pointer*/
	return list;
}

void generate(struct student* students, int n){
	/*Generate random ID and scores for n students, ID being between 1 and 10, scores between 0 and 100*/
	srand(time(NULL));
	int ids[n];
	int randids[n];
	int randscore[n];
	for(int i=0 ; i < n ; i++){ids[i]=(i+1);}
	for(int i=0 ; i < n ; i++){randids[i]=(0);}
	for(int i=0 ; i < n ; i++){
		int check = 0;
		do{
			int x = rand()%n;
			if(randids[x]==0){
				randids[x] = i+1;
				randscore[x]=(rand()%100);
				check = 1;}
			else ;
		}while(check == 0);
	}
	for(int i=0 ; i < n ; i++){
		students[i].id = randids[i];
		students[i].score = randscore[i];
	}
}

void output(struct student* students, int n){
	/*Output information about the ten students in the format:
	  ID1 Score1
	  ID2 score2
	  ID3 score3
	  ...
	  ID10 score10*/

	printf("\n\n");
	for(int i=0 ; i < n ; i++){printf(" id: %d     score: %d\n\n", students[i].id, students[i].score);}
	printf("\n\n");
}

void sort(struct student* students, int n){
	/*Sort the n students based on their score*/
	/* Remember, each student must be matched with their original score after sorting */
	int hole = 0;
	struct student * new = malloc(n * sizeof(struct student));
	for(int k = 1; k < n+1; k++){
		for(int i = 0; i < n ; i++){
			if(students[i].id == k){
				new[hole] = students[i];
				hole++;
				students[i].id = -1;
				break;
			}
			else;
		}
	}
	for(int x = 0; x<n; x++){students[x]=new[x];}
	free(new);
}

int main(){
	/*Declare an integer n and assign it a value.*/
	int n = 13;
	/*Allocate memory for n students using malloc.*/
	struct student* list = NULL;
	list = allocate(n);
	/*Generate random IDs and scores for the n students, using rand().*/
	generate(list, n);
	/*Print the contents of the array of n students.*/
	output(list, n);
	/*Pass this array along with n to the sort() function*/
	sort(list, n);
	/*Print the contents of the array of n students.*/
	output(list, n);
	return 0;
}
