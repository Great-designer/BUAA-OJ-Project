#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person
{
	char SelfName[20];
	char FatherName[20];
	int Generation;
	struct Person *Next;
	struct Person *Previous;

};

struct Person *Head = NULL;
struct Person *Tail = NULL;

void RenewTheList()
{
	struct Person *EndPtr = Tail->Previous;
	while (EndPtr->Previous!= NULL)
	{
		if (strcmp(EndPtr->FatherName, EndPtr->Previous->SelfName) != 0)
		{
			struct Person *HeadPtr = Head;
			while (HeadPtr->Next != NULL)
			{
				if (strcmp(EndPtr->FatherName, HeadPtr->SelfName) == 0)
				{
					EndPtr->Next->Previous = EndPtr->Previous;
					EndPtr->Previous->Next = EndPtr->Next;
					if (EndPtr->Next==NULL)
					{
						Tail=EndPtr->Previous;
					}
					EndPtr->Previous = HeadPtr;
					EndPtr->Next = HeadPtr->Next;
					HeadPtr->Next->Previous = EndPtr;
					HeadPtr->Next = EndPtr;
					EndPtr=Tail;
					break;
				}
				HeadPtr = HeadPtr->Next;
			}
		}
		EndPtr = EndPtr->Previous;
	}
	if (Head->Next->Next&&(Head->SelfName,Head->Next->FatherName)!=0)
	{
		struct Person* NewHead=Head;
		struct Person *HeadPtr = Head;
		while (HeadPtr->Next != NULL)
		{
			if (strcmp(Head->FatherName, HeadPtr->SelfName) == 0)
			{
				NewHead=Head->Next;
				Head->Next->Previous = Head->Previous;
				Head->Previous = HeadPtr;
				Head->Next = HeadPtr->Next;
				HeadPtr->Next->Previous = Head;
				HeadPtr->Next = Head;
				break;
			}
			HeadPtr = HeadPtr->Next;
		}
		Head=NewHead;
	}
	return;
}

struct Person *CheckExist(char *FatherName)
{

	if (Head->Next == NULL)
	{
		return NULL;
	}
	struct Person *Ptr = Head;
	while (Ptr != NULL)
	{
		if (strcmp(Ptr->SelfName, FatherName) == 0)
		{
			return Ptr;
		}
		Ptr = Ptr->Next;
	}
	return NULL;

}

int main()
{
	Head = (struct Person *)malloc(sizeof(struct Person));
	Head->Next = NULL;
	Head->Previous = NULL;
	Tail = Head;
	char Self[20] = {};
	char Father[20] = {};

	while (~scanf("%s %s", Self, Father))
	{
		char c=0;
		while ((c=getchar() )!= '\n'&&c!=-1);
		struct Person *Check = CheckExist(Father);
		if (Check != NULL)
		{
			struct Person *Temp = (struct Person *)malloc(sizeof(struct Person));
			Temp->Next = Check->Next;
			Temp->Previous = Check;
			Check->Next = Temp;
			Temp->Next->Previous = Temp;
			strcpy(Temp->SelfName, Self);
			strcpy(Temp->FatherName, Father);
		}
		else
		{
			struct Person *Temp = (struct Person *)malloc(sizeof(struct Person));
			Temp->Previous = Tail;
			Temp->Next = NULL;
			Tail->Next=Temp;
			strcpy(Tail->SelfName, Self);
			strcpy(Tail->FatherName, Father);
			Tail=Temp;
		}
	}
	RenewTheList();
	struct Person *PrintPtr = Head;
	while (PrintPtr->Next!=NULL)
	{
		printf("%s %s\n",PrintPtr->SelfName,PrintPtr->FatherName);
		PrintPtr=PrintPtr->Next;
		free(PrintPtr->Previous);
		PrintPtr->Previous=NULL;
	}
	return 0;
}