//Chads file 11/9
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
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\nPress:\n"
             "'l' to load to-do list from a file\n"
             "'s' to save to-do list to a file\n"
             "'a' to add a new task\n"
             "'g' to get the first task\n"
             "'r' to remove the first task\n"
             "'p' to print the list\n"
             "'e' to exit the program\n"
             );
      /* get input command (from the keyboard) */
      cmd = getchar();
		if (cmd=='l')
		{
			FILE *fp;
			fp=fopen("todo.txt", "r");
			loadList(mainList, fp);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		}
		if (cmd=='s')
		{
			FILE *fp;
			fp=fopen("todo.txt","w");
			saveList(mainList,fp);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		}//end 's'
		if (cmd=='a')
		{
			char name[128];
			int pri;
			printf("Priority of task:");
			if(scanf("%d", &pri) == 1)
			{
					TYPE task = createTask((int)pri,name);
					addHeap(mainList, task, compare);
			}
			else
			{
				printf("ERROR-----priority is not an integer\n");
			}
			printf("\nName of task to complete:");
			scanf("%s", name);
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
