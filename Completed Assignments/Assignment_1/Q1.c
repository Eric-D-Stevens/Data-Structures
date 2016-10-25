/* CS261- Assignment 1 - Q. 1*/
/* Name: Eric Stevens-001
// Name: Chad Gibeaut-002
 * Date: 10/5/2014
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
struct student{
	int id;
	int score;
};

struct student* allocate(){
	/*Allocate memory for ten students*/
	struct student * list = malloc(10 * sizeof(struct student));
	/*return the pointer*/
	return list;
}

void generate(struct student* students){
	/*Generate random ID and scores for 10 students, ID being between 1 and 10, scores between 0 and 100*/
	srand(time(NULL));
	int ids[10];
	int randids[10];
	int randscore[10];
	for(int i=0 ; i < 10 ; i++){ids[i]=(i+1);}
	for(int i=0 ; i < 10 ; i++){randids[i]=(0);}
	for(int i=0 ; i < 10 ; i++){
		int check = 0;
		do{
			int x = rand()%10;
			if(randids[x]==0){
				randids[x] = i+1;
				 randscore[x]=(rand()%100);
				 check = 1;}
			else ;
		}while(check == 0);
	}
	for(int i=0 ; i < 10 ; i++){
		students[i].id = randids[i];
		students[i].score = randscore[i];
	}
}

void output(struct student* students){
	/*Output information about the ten students in the format:
	  ID1 Score1
	  ID2 score2
	  ID3 score3
	  ...
	  ID10 score10*/

	printf("\n\n");
	for(int i=0 ; i < 10 ; i++){printf(" id: %d     score: %d\n\n", students[i].id, students[i].score);}
	printf("\n\n");
}

void summary(struct student* students){
	/*Compute and print the minimum, maximum and average scores of the ten students*/
	struct student minstud;
	struct student maxstud;
	int min = 100;
	int max = 0;
	int avg = 0;
	for(int i=0;i<10;i++){
		if(students[i].score < min){minstud = students[i]; min = minstud.score;}
		if(students[i].score > max){maxstud = students[i]; max = maxstud.score;}
		avg = avg + students[i].score;
	}
	printf("\n\n");
	printf("Minimum Score  id: %d     score: %d\n\n", minstud.id, minstud.score);
	printf("Maximum Score  id: %d     score: %d\n\n", maxstud.id, maxstud.score);
	printf("Average Score  score: %d\n\n ", avg/10);
	printf("\n\n");

}


void deallocate(struct student* stud){
	/*Deallocate memory from stud*/
	if(stud != NULL){free(stud);}
	else ;
}

int main(){
	struct student* stud = NULL;

	/*call allocate*/
	stud = allocate();
	/*call generate*/
	generate(stud);
	/*call output*/
	output(stud);
	/*call summary*/
	summary(stud);
	/*call deallocate*/
	deallocate(stud);
	return 0;
}
