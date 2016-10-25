#ifndef __LISTDEQUE_H
#define __LISTDEQUE_H

# ifndef TYPE
# define TYPE      int
# define TYPE_SIZE sizeof(int)
# endif
# ifndef LT
# define LT(A, B) ((A) < (B))
# endif

# ifndef EQ
# define EQ(A, B) ((A) == (B))
# endif

typedef struct linkedList linkedList;			//HAD TO CHANGE THIS LINE....

struct linkedList *createLinkedList();
void deleteLinkedList(struct linkedList *lst);
void printLinkedList(struct linkedList *lst);

/* Deque Interface */
int 	isEmptyList(struct linkedList *lst);		//In test code
void  addBackList(struct linkedList *lst, TYPE e);	//In test code
void 	addFrontList(struct linkedList *lst, TYPE e);	//In test code

TYPE  frontList(struct linkedList *lst);	//In test code
TYPE 	backList(struct linkedList *lst);	//In test code

void  removeFrontList(struct linkedList *lst);	//In test code
void 	removeBackList(struct linkedList *lst);	//In test code

/*Bag Interface */
void addList(struct linkedList *lst, TYPE v);
int containsList(struct linkedList *lst, TYPE e);
void removeList(struct linkedList *lst, TYPE e);

#endif

