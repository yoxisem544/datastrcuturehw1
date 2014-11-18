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

List * createList (List * list, int x, int y) // (a) requirment ok
{
	if (list != NULL)
	{
		list->x = x;
		list->y = y;
		list->nextNode = NULL;
	}
	else 
	{
		list = (List *)malloc(sizeof(List));
		list->x = x;
		list->y = y;
		list->nextNode = NULL;
	}

	return list;
}
int isEmpty (List * list) // (b) requirment
{
	if (list == NULL) 
	{
		printf("List is empty\n");
		return EMPTY;
	}

	printf("List is not empty\n");
	return NOTEMPTY;
}

int isEmptyForPrintList (List * list) // (b) requirment
{
	if (list == NULL) 
		return EMPTY;
	return NOTEMPTY;
}

void insertAtTheEndOfList (List * list, int x, int y) // (c) requirment ok
{
	List * tmpList = list;

	// search to the end of list
	while (tmpList->nextNode != NULL)
		tmpList = tmpList->nextNode;

	//malloc & init next node.
	tmpList->nextNode = (List *)malloc(sizeof(List));
	// createList(tmpList->nextNode, tmpList->x + 1, tmpList->y + 1);
	createList(tmpList->nextNode, x, y);
}

int searchXY (List * list, int x, int y) // (d) ok
{
	List * tmpList = list;

	while (tmpList != NULL)
	{
		if (tmpList->x == x && tmpList->y == y)
		{
			printf("Found (%d,%d)\n", x, y);
			return FOUND;
		}
		tmpList = tmpList->nextNode;
	}
	printf("(%d,%d) not found.\n", x, y);
	return NOTFOUND;
}

List * deletePoint (List * list, int x, int y) // (e) ok
{
	List * tmpList = list->nextNode;
	List * previousNode = list;

	if (previousNode->x == x && previousNode->y == y)
	{
		// printf("yes,x= %d, y= %d\n",previousNode->x,previousNode->y);
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
	if (isEmptyForPrintList(list) == NOTEMPTY)
	{
		List * tmpList = list; 

		printf("This is your list:\n");
		while (tmpList != NULL)
		{
			printf("(%d,%d)", tmpList->x, tmpList->y);
			if (tmpList->nextNode != NULL) 
				printf("->");
			tmpList = tmpList->nextNode;
		}
		printf("\n");
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
	char i;
	int j, k;

	printf("Please choose function:\n");
	printf("(a) Create a list of points. ex: a 1 2, create a starting point (1,2).\n");
	printf("(b) Determine if a list is empty.\n");
	printf("(c) Insert a point at the end of a list. ex: c 1 2, insert a point (1,2) at the end.\n");
	printf("(d) Search for a point. ex: d 1 2, search for point (1,2).\n");
	printf("(e) Delete a point. ex: e 1 2, delete point (1,2).\n");
	printf("(f) Print out a list.\n");
	printf("(g) Count the number of points in a list.\n");
	while (1)
	{
		printf("=> ");
		do {
			scanf("%c", &i);
		} while (i == 32 || i == 10);

		if (i == 'a')
		{
			do
			{
				scanf("%d", &j);
			} while (j == 32 || j == 10);
			do
			{
				scanf("%d", &k);
			} while (k == 32 || k == 10);

			list = createList(list, j, k);
		}
		else if (i == 'b')
			isEmpty(list);
		else if (i == 'c')
		{
			do
			{
				scanf("%d", &j);
			} while (j == 32 || j == 10);
			do
			{
				scanf("%d", &k);
			} while (k == 32 || k == 10);

			insertAtTheEndOfList(list, j, k);
		}
		else if (i == 'd')
		{
			do
			{
				scanf("%d", &j);
			} while (j == 32 || j == 10);
			do
			{
				scanf("%d", &k);
			} while (k == 32 || k == 10);

			searchXY(list, j, k);
		}
		else if (i == 'e')
		{
			do
			{
				scanf("%d", &j);
			} while (j == 32 || j == 10);
			do
			{
				scanf("%d", &k);
			} while (k == 32 || k == 10);

			list = deletePoint(list, j, k);
		}
		else if (i == 'f')
			printOutList(list);
		else if (i == 'g')
			countTheNumberOfPointsInList(list);
	}

	return 0;
}