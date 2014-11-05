#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0
#define NOTEMPTY -1
#define FOUND 2
#define NOTFOUND 3

typedef struct _List
{
	int x;
	int y;
	struct _List *nextNode;
} List;

void createList (List * list,int x, int y) // (a) requirment ok
{
	list->x = x;
	list->y = y;
	list->nextNode = NULL;
}
int isEmpty (List * list) // (b) requirment
{
	if (list == NULL) 
		return EMPTY;
	return NOTEMPTY;
}

void insertAtTheEndOfList (List * list) // (c) requirment ok
{
	List * tmpList = list;

	// search to the end of list
	while (tmpList->nextNode != NULL)
		tmpList = tmpList->nextNode;

	//malloc & init next node.
	tmpList->nextNode = (List *)malloc(sizeof(List));
	createList(tmpList->nextNode, tmpList->x + 1, tmpList->y + 1);
}

int searchXY (List * list, int x, int y) // (d) ok
{
	List * tmpList = list;

	while (tmpList != NULL)
	{
		if (tmpList->x == x && tmpList->y == y)
			return FOUND;
		tmpList = tmpList->nextNode;
	}

	return NOTFOUND;
}

List * deletePoint (List * list, int x, int y) // (e) ok
{
	List * tmpList = list->nextNode;
	List * previousNode = list;

	if (previousNode->x == x && previousNode->y == y)
	{
		printf("yes,x= %d, y= %d\n",previousNode->x,previousNode->y);
		previousNode = previousNode->nextNode;
		return previousNode;
	}

	while (tmpList != NULL)
	{
		//delete point
		if (tmpList->x == x && tmpList->y == y)
		{	
			//check if list does have next node.
			if (tmpList->nextNode != NULL)
				previousNode->nextNode = tmpList->nextNode;
			else if (tmpList->nextNode == NULL)
				previousNode->nextNode = NULL;

			return list;
		}
		tmpList = tmpList->nextNode;
		previousNode = previousNode->nextNode;
	}

	return list;
}

void printOutList (List * list) // (f) ok
{
	if (isEmpty(list) == NOTEMPTY)
	{
		List * tmpList = list; 
		int counter = 1;
		while (tmpList != NULL)
		{
			printf("index = %d, x = %d, y = %d\n", counter, tmpList->x, tmpList->y);
			counter += 1;
			tmpList = tmpList->nextNode;
		}
	}
	else
		printf("%s\n", "This list is empty");
}

int countTheNumberOfPointsInList (List * list) // (g) ok
{
	int counter = 0;
	List * tmpList = list;

	while (tmpList != NULL)
	{
		counter += 1;
		tmpList = tmpList->nextNode;
	}

	printf("Count of list is %d\n", counter);
	return counter;
}






int main ()
{
	//init list & set next node to NULL
	List *list;
	char i, j, k;

	while (1)
	{
		printf("Please choose function:\n");
		printf("(a) Create a list of points.\n");
		printf("(b) Determine if a list is empty.\n");
		printf("(c) Insert a point at the end of a list.\n");
		printf("(d) Search for a point.\n");
		printf("(e) Delete a point.\n");
		printf("(f) Print out a list.\n");
		printf("(g) Count the number of points in a list.\n");
		printf("=> ");
		do {
			scanf("%c", &i);
		} while (i == 32 || i == 10);
	}

	return 0;
}