#include <stdio.h>
#include <stdlib.h>

struct slist
{
    int n;
    struct slist *next;
} *temp, *start = NULL, *nw;
// struct slist *nw;
//  struct slist *temp,*start=NULL;

void insertlast()
{
    int d;
    nw = (struct slist *)malloc(sizeof(struct slist));
    if (nw == NULL)
    {
        printf("\nMemory not Allocted");
    }
    else
    {
        printf("\nEnter the the data--");
        scanf("%d", &d);
        nw->n = d;
        nw->next = NULL;
        if (start == NULL)
        {
            start = nw;
        }
        else
        {
            temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = nw;
        }
        printf("One Node Inserted");
    }
}

void insert_after()

{
    int s, f = 0;
    temp = start;
    printf("Enter the Data To be searched");
    scanf("%d", &s);

    while (temp != NULL)
    {
        if (temp->n == s)
        {
            f = 1;
            break;
        }
        temp = temp->next;
    }
    if (f == 0)
    {
        printf("Data not found");
    }
    else
    {
        nw = (struct slist *)malloc(sizeof(struct slist));
        printf("Enter the data to be inserted in new node");
        scanf("%d", &nw->n);
        nw->next = temp->next;
        temp->next = nw;
        printf("Node Inserted");
    }
}

void insert_before()
{
    int s, f = 0;
    struct slist *prev = NULL;
    temp = start;
    printf("Enter the Data To be searched-");
    scanf("%d", &s);

    while (temp != NULL)
    {
        if (temp->n == s)
        {
            f = 1;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if (f == 0)
    {
        printf("Data not found");
    }
    else
    {
        nw = (struct slist *)malloc(sizeof(struct slist));
        printf("Enter the data to be inserted -");
        scanf("%d", &nw->n);
        if (prev == NULL)
        {
            nw->next = start;
            start = nw;
            printf("Node inserted");
        }
        else
        {
            nw->next = temp;
            prev->next = nw;
            printf("Node Inserted");
        }
    }
}

void reverse_list()
{
    struct slist *prev, *r;
    prev = NULL;
    r = temp = start;

    if (temp == NULL)
    {
        printf("List is empty");
    }
    else
    {
        while (temp != NULL)
        {
            temp = temp->next;
            r->next = prev;
            prev = r;
            r = temp;
        }

        start = prev;
        if (prev == NULL)
            printf("Only one node is on list");
        else
        {
            printf("Node Reversed");
        }
    }
}

void display()
{
    temp = start;
    if (temp == NULL)
    {
        printf("\nList Empty");
    }
    else
    {
        while (temp != NULL)
        {
            printf("\n%d", temp->n);
            temp = temp->next;
        }
    }
}

void search()
{
    int f = 0, s;
    printf("\nEnter The Data to search-- ");
    scanf("%d", &s);
    temp = start;
    if (temp == NULL)
    {
        printf("\nList is Empty");
    }
    while (temp != NULL)
    {
        if (temp->n == s)
        {
            f = 1;
            break;
        }
        temp = temp->next;
    }
    if (f == 1)
    {
        printf("\nData Found");
    }
    else
    {
        printf("\nNOt Found");
    }
}

void insertfirst()
{
    int a;
    nw = (struct slist *)malloc(sizeof(struct slist));
    if (nw == NULL)
    {
        printf("Memory not allocated");
    }
    else
    {
        printf("Enter the data--");
        scanf("%d", &a);
        nw->n = a;
        nw->next = start;
        start = nw;
    }
    printf("One NOde Inserted");
}

void deletefirst()
{
    if (start == NULL)
    {
        printf("\nList is Empty");
    }
    else
    {
        temp = start;
        start = start->next;
        temp->next = NULL;
        free(temp);
    }
    printf("\nFirst Node Deleted");
}

void deletelast()
{
    struct slist *prev = NULL;
    if (start == NULL)
    {
        printf("List is Empty");
    }

    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL)
        {
            start == NULL;
        }
        else
        {
            prev->next = NULL;
            free(temp);
        }
    }
    printf("Last Node Deleted");
}

void modify()
{
    int f = 0, s;
    temp = start;
    if (temp == NULL)
    {
        printf("List is Empty");
    }
    else
    {
        printf("\nEnter The Data You want to modify");
        scanf("%d", &s);
        while (temp != NULL)
        {
            if (temp->n == s)
            {
                f = 1;
                break;
            }
            temp = temp->next;
        }
        if (f == 0)
        {
            printf("Data not found");
        }
        else
        {
            printf("\nEnter new data");
            scanf("%d", &temp->n);
            printf("\nData Modified Sucessfully...");
        }
    }
}

void delete_any_node()
{
    struct slist *prev = NULL;
    temp = start;
    int f = 0, s;
    if (temp == NULL)
    {
        printf("List Empty");
    }
    else
    {
        printf("\nEnter the node data to delete");
        scanf("%d", &s);
        while (temp != NULL)
        {
            if (temp->n == s)
            {
                f = 1;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        if (f == 0)
        {
            printf(" Data Not Found");
        }
        else
        {
            if (prev == NULL)
            {
                start = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            printf("\nOne node deleted");
        }
    }
}

void sort_slist()
{
    struct slist *t1,*t2;
    int s;
    t1=start;
    while (t1->next!=NULL)
    {
        t2 =t1->next;
        while (t2!=NULL)
        {
            if (t1->n<t2->n)
            {
                s=t1->n;
                t1->n=t2->n;
                t2->n=s;

            }
            t2=t2->next;
        }
        t1=t1->next;
    }
    puts("Node Sorted");
}


void main()
{
    int ch;
    do
    {
        printf("\nPress");
        printf("\n1.Insert node at last..");
        printf("\n2.Display all nodes..");
        printf("\n3.Search data in nodes..");
        printf("\n4.Insert node at first..");
        printf("\n5.Delete node at last..");
        printf("\n6.Delete node at first..");
        printf("\n7.Modify  data at any node..");
        printf("\n8.Delete any node..");
        printf("\n9.Insert node after searched data");
        printf("\n10.Insert node before searched data");
        printf("\n11.Reverse node");
        printf("\n12.Sort the node");
        printf("\n0.Exit");
        

        printf("\nEnter your choice--\n");
        
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insertlast();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            insertfirst();
            break;
        case 5:
            deletelast();
            break;
        case 6:
            deletefirst();
            break;
        case 7:
            modify();
            break;
        case 8:
            delete_any_node();
            break;
        case 9:
            insert_after();
            break;
        case 10:
            insert_before();
            break;
        case 11:
            reverse_list();
            break;
        case 12:
            sort_slist();
            break;
        default:
            printf("-\nInvalid Choice");
        }
    } while (ch != 0);
}