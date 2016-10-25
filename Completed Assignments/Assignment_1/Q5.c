/* CS261- Assignment 1 - Q. 5*/
/* Name: Eric Stevens-001
// Name: Chad Gibeaut-002
 * Date: 10/5/2014
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void studly(char* word){

     /*Convert to studly caps*/
     int count;
     for(count=0;word[count]!=NULL;count++){
        if (count%2==0)
        {
            if (word[count]>95){word[count]=toUpperCase(word[count]);}

        }
        else
        {
          if (word[count]<95){word[count]=toLowerCase(word[count]);}
        }


     }
        //if count=0
            //make uppercase
            //count=1
        //elseif count=1
            //make lowercase
            //count=0

}

int main(){
    /*Read word from the keyboard using scanf*/
    char phrase[20];
    char *input;
    input=phrase;
    printf("Please enter a word:\n");
    scanf("%s",input);

    /*Call studly*/
    studly(input);
    /*Print the new word*/
    //printf("%d\n",sizeof(input));
    printf("%s\n\n\n\n\n",input);
    return 0;
}
