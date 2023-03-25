#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct cdlist
{
    struct cdlist *prev;
    int n;
    struct cdlist *next;
}*start=NULL,*tail=NULL,*nw,*temp;

void insert_last()
{
    nw=(struct cdlist*)malloc(sizeof(struct cdlist));
    printf("\nEnter the data--");
    scanf("%d",&nw->n);
    if (start==NULL)
    {
        start=nw;
        tail=nw;
      nw->next=start;
      nw->prev=start;

    }
    else{
        nw->prev=tail;
        tail->next=nw;
        tail=nw;
        nw->next=start;
    }
    puts("Last node inserted");
}


void main()
{
int ch;
do
{
     puts("\n1.Insert node at last");
        puts("2.Insert at node at first");
        puts("3.Display all data");
        puts("4.Search data in node");
        puts("5.Insert node after");
        puts("6.Insert node before");
        puts("7.Delete node at last");
        puts("8.Delete node at first");
        puts("9.Delete any node by search");
        puts("10.Modify the data");

        puts("Enter your Choice--");
        scanf("%d", &ch);

        
} while (ch!=0);

}