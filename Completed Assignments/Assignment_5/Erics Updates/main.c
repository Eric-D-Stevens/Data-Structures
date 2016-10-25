// CS 261: Assignment 5 // 
// Chad Gibeaut && Eric Stevens //
// November 13, 2014 //
// Main ToDo List Functions //
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
	char cmd = ' ';
	DynArr* mainList = createDynArr(10);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n** TO-DO LIST APPLICATION **\n\n");
	do
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\nPress:\n'l' to load to-do list from a file.");
		printf("\n's' to save to-do list to a file,");
		printf("\n'a' to add a new task,");
		printf("\n'g' to get the first task,");
		printf("\n'r' to remove the first task,");
		printf("\n'p' to print the list");
		printf("\n'e' to exit the program\n");
		/* get input command (from the keyboard) */
		cmd = getchar();
		if (cmd=='l')
		{
			FILE *fp;
			fp=fopen("todo.txt", "r");
			loadList(mainList, fp);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		}//end 'l'

		if (cmd=='s')
		{
			FILE *fp;
			fp=fopen("todo.txt","w");
			saveList(mainList,fp);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		}//end 's'
		
		if (cmd=='a')
		{
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			char name[128];
			int pri;

			printf("\nName of task to complete:(Press tab and then enter when done)");
			scanf("%[^\t]s", name);

			printf("Priority of task:");
			if(scanf("%d", &pri) == 1)
			{
				TYPE task = createTask(pri,name);
				addHeap(mainList, task, compare);
			}
			else
			{
				printf("ERROR-----priority is not an integer\n");
			}
		}//end 'a'
		
		if (cmd=='g')
		{
			printf("\n\n\n\n\n\n\n\n\n\n");
			TaskP task;
			task = getMinHeap(mainList);
			int pri=task->priority;
			char *name=task->description;
			printf("Name:%s   Priority:%d",name,pri);
		}//end 'g'
		
		if (cmd=='r')
		{
			removeMinHeap(mainList,compare);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		}//end 'r'
		
		if (cmd=='p'){printf("\n\n\n\n\n\n\n\n\n\n");printList(mainList);}
		/* clear the trailing newline character */
		while (getchar() != '\n');

		/* Note: We have provided functions called printList(), saveList() and loadList() for you
		   to use.  They can be found in toDoList.c */
	}
	while(cmd != 'e');
	/* delete the list */
	deleteDynArr(mainList);

	return 0;
}
