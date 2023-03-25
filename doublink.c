// Program for double linked list.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct dlist
{
    struct dlist *prev;
    int data;
    struct dlist *next;
};

struct dlist *start = NULL, *temp, *nw, *tail;

void insert_Beginning()
{
    nw = (struct dlist *)malloc(sizeof(struct dlist));
    puts("Enter the Data--");
    scanf("%d", &nw->data);
    nw->prev = NULL;
    nw->next = NULL;
    if (start == NULL)
    {
        tail = start = nw;
    }
    else
    {
        temp = start;
        temp->prev = nw;
        nw->next = temp;
        start = nw;
    }
    puts("Node Inserted");
}

void insert_Last()
{
    nw = (struct dlist *)malloc(sizeof(struct dlist));
    puts("Enter the data--");
    scanf("%d", &nw->data);
    nw->next = NULL;
    nw->prev = NULL;

    temp = start;
    if (start == NULL)
    {
        start = nw;
        tail = nw;
    }
    else
    {
        nw->prev = tail;
        tail->next = nw;
        tail = nw;
    }
    puts("Node Inseted");
}

void display()
{
    temp = start;
    if (start == NULL)
    {
        puts("List is Empty");
    }
    else
    {
        while (temp != NULL)
        {
            printf("\n%d", temp->data);
            temp = temp->next;
        }
    }
}

void search()
{
    int s, f = 0;
    if (start == NULL)
    {
        puts("List is empty");
    }
    else
    {
        puts("Enter the data to search");
        scanf("%d", &s);
        temp = start;
        while (temp != NULL)
        {
            if (temp->data == s)
            {
                f = 1;
                break;
            }
            temp = temp->next;
        }
        if (f == 0)
        {
            puts("Data Not Found");
        }
        else
        {
            printf("data found...");
        }
    }
}

void insert_after()
{
    int s, f = 0;
    if (start == NULL)
    {
        puts("List is empty");
    }
    else
    {
        puts("Enter the data to search");
        scanf("%d", &s);
        temp = start;
        while (temp != NULL)
        {
            if (temp->data == s)
            {
                f = 1;
                break;
            }
            temp = temp->next;
        }
        if (f == 0)
        {
            puts("Data Not Found");
        }
        else
        {
            nw = (struct dlist *)malloc(sizeof(struct dlist));
            printf("\nEnter the data--");
            scanf("%d", &nw->data);
            nw->prev = NULL;
            nw->next = NULL;
            if (temp->next == NULL)
            {
                nw->prev = temp;
                temp->next = nw;
                tail = nw;
            }
            else
            {
                nw->prev = temp;
                nw->next = temp->next;
                temp->next->prev = nw;
                temp->next = nw;
            }
            puts("After Node Inserted.....");
        }
    }
}

void insert_before()
{
    int s, f = 0;
    if (start == NULL)
    {
        puts("List is empty");
    }
    else
    {
        puts("Enter the data to search");
        scanf("%d", &s);
        temp = start;
        while (temp != NULL)
        {
            if (temp->data == s)
            {
                f = 1;
                break;
            }
            temp = temp->next;
        }
        if (f == 0)
        {
            puts("Data Not Found");
        }
        else
        {
            nw = (struct dlist *)malloc(sizeof(struct dlist));
            printf("\nEnter the data--");
            scanf("%d", &nw->data);
            nw->next = NULL;
            nw->prev = NULL;
            if (temp->prev == NULL)
            {
                nw->prev = temp->prev;
                nw->next = temp;
                temp->prev = nw;
                start = nw;
            }
            else
            {

                nw->next = temp;
                nw->prev = temp->prev;
                temp->prev->next = nw;
                temp->prev = nw;
            }
            puts("Before Node Inserted..");
        }
    }
}

void delete_first()
{
    if (start == NULL)
    {
        puts("List is Empty..");
    }
    else
    {
        temp = start;
        if (temp->next == NULL)
        {
            start = NULL;
            free(temp);
        }
        else
        {
            start = temp->next;
            temp->next->prev = NULL;
        }
        puts("First Node Deleted...");
    }
}

void delete_last()
{
    if (start == NULL)
    {
        puts("List is Empty");
    }
    else
    {

        if (tail->prev == NULL)
        {
            start = NULL;
            free(tail);
        }
        else
        {
            temp = tail;
            tail = temp->prev;
            temp->prev->next = NULL;
            free(temp);
        }
        puts("Last Node Deleted");
    }
}

void delete_anyNode()
{
    int s, f = 0;
    if (start == NULL)
    {
        puts("List is empty");
    }
    else
    {
        puts("Enter the data to search");
        scanf("%d", &s);
        temp = start;
        while (temp != NULL)
        {
            if (temp->data == s)
            {
                f = 1;
                break;
            }
            temp = temp->next;
        }
        if (f == 0)
        {
            puts("Data Not Found");
        }
        else
        {
            if (temp->prev == NULL)
            {
                start = temp->next;
                temp->next->prev = NULL;
                free(temp);
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                if (temp->next == NULL)
                {
                    tail = temp;
                }

                free(temp);
            }
            puts("Node Deleted..");
        }
    }
}

void modify()
{
    int s, f = 0;
    if (start == NULL)
    {
        puts("List is empty");
    }
    else
    {
        puts("Enter the data to search");
        scanf("%d", &s);
        temp = start;
        while (temp != NULL)
        {
            if (temp->data == s)
            {
                f = 1;
                break;
            }
            temp = temp->next;
        }
        if (f == 0)
        {
            puts("Data Not Found");
        }
        else
        {
            puts("Enter the new data..");
            scanf("%d", &temp->data);
            printf("Data Modified..");
        }
    }
}

int main()
{
    int ch;

    do
    {
        puts("\nPress");
        puts("1.Insert at begining");
        puts("2.Insert at last");
        puts("3.Display all data in nodes");
        puts("4.Search Node.");
        puts("5.Insert after node.");
        puts("6.Insert node before.");
        puts("7.Delete first Node.");
        puts("8.Delete last Node");
        puts("9.Delete by search");
        puts("10.Modify Data");
        puts("\n0.Exit");
        puts("Enter your choice-");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert_Beginning();
            break;
        case 2:
            insert_Last();
            break;
        case 3:
            display();
            break;
        case 4:
            search();
            break;
        case 5:
            insert_after();
            break;
        case 6:
            insert_before();
            break;
        case 7:
            delete_first();
            break;
        case 8:
            delete_last();
            break;
        case 9:
            delete_anyNode();
            break;
        case 10:
            modify();
            break;
        default:
            puts("Invalid choice");
        }

    } while (ch != 0);

    return 0;
}
