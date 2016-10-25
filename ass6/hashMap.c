#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hashMap.h"

struct hashLink {
   KeyType key; /*the key is what you use to look up a hashLink*/
   ValueType value; /*the value stored with the hashLink, a pointer to int in the case of concordance*/
   struct hashLink * next; /*notice how these are like linked list nodes*/
};
typedef struct hashLink hashLink;

struct hashMap {
    hashLink ** table; /*array of pointers to hashLinks*/
    int tableSize; /*number of buckets in the table*/
    int count; /*number of hashLinks in the table*/
};
typedef struct hashMap hashMap;

/*the first hashing function you can use*/
int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

/*the second hashing function you can use*/
int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*he difference between stringHash1 and stringHash2 is on this line*/
	return r;
}

/* initialize the supplied hashMap struct*/
void _initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		{return;}
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}

/* allocate memory and initialize a hash map*/
hashMap *createMap(int tableSize) {
	assert(tableSize > 0);
	hashMap *ht;
	ht = malloc(sizeof(hashMap));
	assert(ht != 0);
	_initMap(ht, tableSize);
	return ht;
}

/*
 Free all memory used by the buckets.
 */
void _freeLinks (struct hashLink **table, int tableSize)
{
	for(int i=0;i<tableSize;i++)
	{	if(table[i] !=NULL)
		{
			
			while(table[i]->next !=NULL)
			{
				struct hashLink * temp= table[i];
				table[i]=table[i]->next;
				free(temp);
			}
		}
		
	}
}

/* Deallocate buckets, table, and hashTable structure itself.*/
void deleteMap(hashMap *ht) 
{
	assert(ht!= 0);
	/* Free all memory used by the buckets */
	_freeLinks(ht->table, ht->tableSize);
        /* Free the array of buckets */
        free(ht->table);
	/* free the hashMap struct */
	free(ht);
}

/*
Resizes the hash table to be the size newTableSize
*/
void _setTableSize(struct hashMap * ht, int newTableSize)
{//Our code
	assert(newTableSize > 0);
	struct hashMap *temp;
	temp = createMap(newTableSize);
	printf("\nOld Table Count: %d ",ht->count);
	for(int i=0; i < ht->tableSize; i++)
	{
		if(ht->table[i] != NULL)
		{	
			while(ht->table[i] != NULL)
			{
				insertMap(temp, ht->table[i]->key, ht->table[i]->value);
				temp->count++;
				removeKey(ht, ht->table[i]->key);
			}
		}
	}
	printf("\nTEMP Table Count: %d ",temp->count);
	*ht = *temp; 
	printf("\nNew Table Count: %d ",ht->count);
	return;
}

/*
 insert the following values into a hashLink, you must create this hashLink but
 only after you confirm that this key does not already exist in the table. For example, you
 cannot have two hashLinks for the word "taco".

 if a hashLink already exists in the table for the key provided you should
 replace the value for that key.  As the developer, you DO NOT FREE UP THE MEMORY FOR THE VALUE.
 We have to leave that up to the user of the hashMap to take care of since they may or may not
 have allocated the space with malloc.


 Also, you must monitor the load factor and resize when the load factor is greater than
 or equal LOAD_FACTOR_THRESHOLD (defined in hashMap.h).
 */
 


void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{//Our code
	//if (tableLoad(ht)==-1)
	if (tableLoad(ht)>LOAD_FACTOR_THRESHOLD)
	{
		printf("\nTable Count Before Resize: %d",ht->count);
		_setTableSize(ht,2*(ht->tableSize));
		printf("\nTable Count After Resize: %d \n",ht->count);
	}
	int hashIndex = stringHash1(k) % ht->tableSize;
    if (hashIndex < 0) { hashIndex += ht->tableSize;}
    struct hashLink * newLink = (struct hashLink *) malloc(sizeof(struct hashLink));
    assert(newLink);
    newLink->value = v;
	newLink->key = k;
    newLink->next = ht->table[hashIndex];
    ht->table[hashIndex] = newLink; /* add to bucket */
    ht->count++;
	//float ld=tableLoad(ht);
	//printf("\nHash Index: %d For: %s  LoadFactor= %f",hashIndex,k,ld);
	
	return;
}
/*
 this returns the value (which is void*) stored in a hashLink specified by the key k.
 if the user supplies the key "taco" you should find taco in the hashTable, then
 return the value member of the hashLink that represents taco.
 if the supplied key is not in the hashtable return NULL.
 */
ValueType atMap (struct hashMap * ht, KeyType k)
{//Our Code
	int index = stringHash1(k) % ht->tableSize;
    struct hashLink *temp = (struct hashLink*)malloc(sizeof(struct hashLink));
	temp = ht->table[index];
	
	if((strcmp(temp->key, k) == 0)){return (ht->table[index]->value) ;}
	while(temp->next !=NULL)
	{	
		temp = temp->next;
		if((strcmp(temp->key, k) == 0)){return temp->value;}
	}
	printf("\natMap: Doesnt Exist, or our code sucks");
	return 0;
}
/*
 a simple yes/no if the key is in the hashtable.
 0 is no, all other values are yes.
 */
int containsKey (struct hashMap * ht, KeyType k)
{//Out Code
	int index = stringHash1(k) % ht->tableSize;
	struct hashLink *temp = (struct hashLink*)malloc(sizeof(struct hashLink));
	temp = ht->table[index];
	if(temp==NULL)
	{
		//printf("\nNot Contained, index null: %s  ",k);
		return 0;
	}
	else if(strcmp(temp->key, k) == 0)
	{
		//printf("\nContained in first index: %s  YES!!",k);
		return 1;
	}
	else if(temp!=NULL && strcmp(temp->key, k) != 0)
	{
		//printf("\nIndex not null and key not at first index_  ");
		while(temp != NULL)
		{
		
			//printf("does %s equal %s ?",temp->key, k);
			if(strcmp(temp->key, k) == 0)
			{
				//printf("FOUND");
				//printf("\nContains: %s  YES!!",k);
				
				return 1;
			}
			temp = temp->next;
		}
	}
	//printf("\n not contaied: %s",k);
	return 0;
	
}

/*
 find the hashlink for the supplied key and remove it, also freeing the memory
 for that hashlink. it is not an error to be unable to find the hashlink, if it
 cannot be found do nothing (or print a message) but do not use an assert which
 will end your program.
 */
void removeKey (struct hashMap * ht, KeyType k)
{//Our Code
		//printf("\nstarting remove function");
		int index = stringHash1(k) % ht->tableSize;
		
			struct hashLink *temp_r = (struct hashLink*)malloc(sizeof(struct hashLink));
			temp_r = ht->table[index];
		
		if(temp_r == NULL)// if index is not taken
		{ 	
			printf("Does not exist");
			return;
		}
		
		
		else if(strcmp(temp_r->key, k) == 0)//if its the first link...
		{	//printf("\n...removing first index...");
			struct hashLink *temp = (struct hashLink*)malloc(sizeof(struct hashLink));
			temp = ht->table[index];
			ht->table[index] = temp->next; 
			ht->count--;
			free(temp);
			return;
		}
	
		else if(strcmp(ht->table[index]->key, k) != 0 && ht->table[index]->key != NULL) 
		{	
			//printf("\n...attempt to remove from inner link...");
			//printf("\n...attempt to remove from inner link...");
			
			struct hashLink *temp = (struct hashLink*)malloc(sizeof(struct hashLink));
			temp = ht->table[index];
			
			while(temp->next != NULL)
			{	
				//printf(".looking.");
				if(strcmp(temp->next->key, k) == 0)
				{
					//printf(".found.");
					struct hashLink *temp2 = (struct hashLink*)malloc(sizeof(struct hashLink));
					temp2 = temp->next;
					temp->next = temp2->next;
					free(temp2);
					ht->count--;
					return;
				}
				temp = temp->next;
			}
		}
		//printf("Does not exist OKKK");
		return;
		
}

/*
 returns the number of hashLinks in the table
 */
int size (struct hashMap *ht)
{	//Our Code
	return ht->count;
}

/*
 returns the number of buckets in the table
 */
int capacity(struct hashMap *ht)
{//Our Code
	return ht->tableSize;
}
/*
 returns the number of empty buckets in the table, these are buckets which have
 no hashlinks hanging off of them.
 */
int emptyBuckets(struct hashMap *ht)
{//Our Code
	int count=0;
	for (int i=0; i<(ht->tableSize);i++)
		{
			if (ht->table[i]==NULL){count++;}
		}
	return count;
}
/*
 returns the ratio of: (number of hashlinks) / (number of buckets)

 this value can range anywhere from zero (an empty table) to more then 1, which
 would mean that there are more hashlinks then buckets (but remember hashlinks
 are like linked list nodes so they can hang from each other)
 */
float tableLoad(struct hashMap *ht)
{//Our Code
	float load=(float)(ht->count)/(float)(ht->tableSize);
	return load;
}

/* print the hashMap */
 void printMap (struct hashMap * ht, keyPrinter kp, valPrinter vp)
{
	int i;
	struct hashLink *temp;
	for(i = 0;i < capacity(ht); i++){
		temp = ht->table[i];
		if(temp != 0) {
			printf("\nBucket Index %d -> ", i);
		}
		while(temp != 0){
                        printf("Key:");
                        (*kp)(temp->key);
                        printf("| Value: ");
                        (*vp)(temp->value);
			printf(" -> ");
			temp=temp->next;
		}
	}
}

/* print the keys/values ..in linear form, no buckets */
 void printKeyValues (struct hashMap * ht, keyPrinter kp, valPrinter vp)
{
	int i;
	
	struct hashLink *temp;
	for(i = 0;i < capacity(ht); i++){
		temp = ht->table[i];
		while(temp != 0){
                        (*kp)(temp->key);
			printf(":");
                        (*vp)(temp->value);
			printf("\n");
			temp=temp->next;
		}
	}
}
