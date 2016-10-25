#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


//////////////////////////////////////////////////
/* Double Link*/
struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};
//////////////////////////////////////////////////

//////////////////////////////////////////////////
/* Double Linked List with Head and Tail Sentinels  */
struct linkedList{
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};
//////////////////////////////////////////////////

//////////////////////////////////////////////////
/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/
void _initList (struct linkedList *lst) {
	/* OUR CODE */
	assert(lst!=NULL);
	struct DLink *first = malloc(sizeof(struct DLink));
	struct DLink *last = malloc(sizeof(struct DLink));
	first->prev = NULL;
	first->next = last;
	last->prev = first;
	last->next = NULL;
	lst->firstLink = first;
	lst->lastLink = last;
	lst->size = 0;
}
//////////////////////////////////////////////////

//////////////////////////////////////////////////
/*
	 createList
	 param: none
	 pre: none
	 post: firstLink and lastLink reference sentinels
 */
struct linkedList *createLinkedList()
{
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}
//////////////////////////////////////////////////

//////////////////////////////////////////////////
/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
	/* OUR CODE */
	assert(lst!=NULL);
	assert(l!=NULL);
	struct DLink *add = malloc(sizeof(struct DLink));
	add->value = v;
	l->prev->next = add;
	add->prev = l->prev;
	add->next = l;
	l->prev = add;
	lst->size++;
	
}
//////////////////////////////////////////////////

//////////////////////////////////////////////////
/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/
void _removeLink(struct linkedList *lst, struct DLink *l)
{
	/* OUR CODE */
	assert(lst!=NULL);
	assert(l!=NULL);
	l->prev->next = l->next;
	l->next->prev = l->prev;
	free(l);
	lst->size--;			

}
//////////////////////////////////////////////////

//////////////////////////////////////////////////
/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/
int isEmptyList(struct linkedList *lst) {
	/* OUR CODE */
	assert(lst!=NULL);
	if(lst->size==0){return 1;}
	return(0);
}
//////////////////////////////////////////////////

//////////////////////////////////////////////////
/*
	De-allocate all links of the list
	param: 	lst 
	pre:	none
	post:	All links (including the two sentinels) are de-allocated
*/
void freeLinkedList(struct linkedList *lst)
{
	/* OUR CODE */
	/* call to remove link and free links memory */
	while(!isEmptyList(lst)){_removeLink(lst, lst->firstLink->next);}		
	/* remove the first and last sentinels */
	free(lst->firstLink);
	free(lst->lastLink);	
}
//////////////////////////////////////////////////

//////////////////////////////////////////////////
/* 	
	Deallocate all the links and the linked list itself. 
	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	the memory used by v->data is freed
*/
void deleteLinkedList(struct linkedList *lst)
{
	/* OUR CODE */
	assert (lst!=NULL);//what the fuck is v?
	freeLinkedList(lst);
	free(lst);
}
//////////////////////////////////////////////////

//////////////////////////////////////////////////
/*
	Function to print list
	Pre: lst is not null
*/
void _printList(struct linkedList* lst)
{
	/* OUR CODE */
	assert(lst!=NULL);
	struct DLink at;
	at.next = lst->firstLink->next;
	printf("\n\n[ ");
	while(at.next != lst->lastLink){
		printf("%d ", at.next->value);	
		at.next = at.next->next;
	}
	printf("]\n\n");
}
//////////////////////////////////////////////////

void printLinkedList(struct linkedList *lst){
	_printList(lst);
}
/* ************************************************************************
	Deque Interface Functions
************************************************************************ */

//////////////////////////////////////////////////
/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/
void addFrontList(struct linkedList *lst, TYPE e)
{	/* OUR CODE */
	assert(lst!=NULL);
	_addLinkBefore(lst, lst->firstLink->next, e);
}
//////////////////////////////////////////////////

//////////////////////////////////////////////////
/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/
void addBackList(struct linkedList *lst, TYPE e){
	/* OUR CODE */
	assert(lst!=NULL);
	_addLinkBefore(lst, lst->lastLink, e);
}
//////////////////////////////////////////////////

//////////////////////////////////////////////////
/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/
TYPE frontList (struct linkedList *lst) 
{
	/* OUR CODE */
	assert(lst!=NULL);
	assert(!isEmptyList(lst));
	return(lst->firstLink->next->value);
}
//////////////////////////////////////////////////

//////////////////////////////////////////////////
/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/
TYPE backList(struct linkedList *lst)
{
	/* OUR CODE */
	assert(lst!=NULL);
	assert(!isEmptyList(lst));
	return(lst->lastLink->prev->value);
}
//////////////////////////////////////////////////

//////////////////////////////////////////////////
/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/
void removeFrontList(struct linkedList *lst) 
{
	/* OUR CODE */
	assert(lst!=NULL);
	assert(!isEmptyList(lst));
	_removeLink(lst, lst->firstLink->next);
}
//////////////////////////////////////////////////

//////////////////////////////////////////////////
/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/
void removeBackList(struct linkedList *lst)
{	
	/* OUR CODE */
	assert(lst!=NULL);
	assert(!isEmptyList(lst));
	_removeLink(lst, lst->lastLink->prev);
}
//////////////////////////////////////////////////


/* ************************************************************************
	Stack Interface Functions
************************************************************************ */

//////////////////////////////////////////////////
/* 
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v)
{
	/* OUR CODE */
	assert(lst!=NULL);
	addFrontList(lst, v);

}
//////////////////////////////////////////////////

//////////////////////////////////////////////////
/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
*/
int containsList (struct linkedList *lst, TYPE e) {
	/* OUR CODE */
	assert(lst!=NULL);
	assert(!isEmptyList(lst));
	struct DLink at;//Temporary DLink used for checking
	at.next = lst->firstLink->next;
	while(at.next != lst->lastLink){
		if(at.next->value == e){ return 1;}
		else{at.next = at.next->next;}	
	}
	return(0);
}
//////////////////////////////////////////////////

//////////////////////////////////////////////////
/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
void removeList (struct linkedList *lst, TYPE e) {
	/* OUR CODE */
	assert(lst!=NULL);
	assert(!isEmptyList(lst));
	struct DLink at; // Temporary DLink used for checking
	at.next = lst->firstLink->next;
	while( at.next != lst->lastLink){
		if(at.next->value == e){_removeLink(lst, at.next); return;} 
		else{at.next = at.next->next;}	
	}
}
//////////////////////////////////////////////////
