#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct book
{
    char author[105];
    char name[105];
    char returned;
};

struct book library[105];

int compareBook(const void*p1,const void*p2)
{
    struct book*a=(struct book*)p1;
    struct book*b=(struct book*)p2;
    if(!strcmp(a->author,b->author))
    {
        return (strcmp(a->name,b->name)>0);
    }
    return strcmp(a->author,b->author)>0;
}

int compareint(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}

char End[7]="END";
char Borrow[7]="BORROW";
char Return[7]="RETURN";
char Shelve[7]="SHELVE";
int librarysize;
int returnStack[105];
int stacksize;
char tmp[315];
char tmpBookname[105];
char tmpInstruct[7];

void readline()
{
    scanf("%[^\n]",tmp);
    getchar();
}

void addSingleBook()
{
    int startIndex=1;
    int n=strlen(tmp);
    int endIndex=1;
    while(endIndex<n&&tmp[endIndex]!='"')
    {
        ++endIndex;
    }
    strncpy(library[librarysize].name,tmp+startIndex,endIndex-1);
    endIndex+=4;
    strncpy(library[librarysize].author,tmp+endIndex,n-endIndex);
    library[librarysize++].returned=1;
}

void addBook()
{
    readline();
    while(strcmp(End,tmp))
    {
        addSingleBook();
        readline();
    }
    qsort(library,librarysize,sizeof(struct book),compareBook);
}

void getBookname()
{
    strncpy(tmpBookname,tmp+8,strlen(tmp)-9);
}

void getInstruct()
{
    strncpy(tmpInstruct,tmp,6);
}

int locateBook(char *bookname)
{
    int i;
    for(i=0;i<105;++i)
    {
        if(!strcmp(bookname,library[i].name))
        {
            return i;
        }
    }
    return -1;
}

void borrowBook(char* bookname)
{
    library[locateBook(bookname)].returned=0;
}

void returnBook(char* bookname)
{
    int i=locateBook(bookname);
    returnStack[stacksize++]=i;
}

int findFront(int bookNumber)
{
    int i;
    for(i=bookNumber-1;i>=0;--i)
    {
        if(library[i].returned)
        {
            return i;
        }
    }
    return -1;
}

void shelve()
{
    qsort(returnStack,stacksize,sizeof(int),compareint);
    int i;
    for(i=0;i<stacksize;++i)
    {
        int k=findFront(returnStack[i]);
        if(k<0)
        {
            printf("Put \"%s\" first\n",library[returnStack[i]].name);
        }
        else
        {
            printf("Put \"%s\" after \"%s\"\n",library[returnStack[i]].name,library[k].name);
        }
        library[returnStack[i]].returned=1;
    }
    stacksize=0;
    memset(returnStack,0,sizeof(returnStack));
}

void request()
{
    readline();
    while(strcmp(End,tmp))
    {
        getInstruct();
        if(!strcmp(tmpInstruct,Shelve))
        {
            shelve();
        }
        else if(!strcmp(tmpInstruct,Borrow))
        {
            getBookname();
            borrowBook(tmpBookname);
            memset(tmpBookname,0,sizeof(tmpBookname));
        }
        else if(!strcmp(tmpInstruct,Return))
        {
            getBookname();
            returnBook(tmpBookname);
            memset(tmpBookname,0,sizeof(tmpBookname));
        }
        else
        {
            printf("Error Instruction!\n");
        }
        readline();
    }
}

int main()
{
    addBook();
    request();
    printf("END");
    return 0;
}
