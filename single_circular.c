#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cslist
{
    int n;
    struct cslist *next;
} *start = NULL, *nw, *temp, *tail;

void insert_last()
{
    nw = (struct cslist *)malloc(sizeof(struct cslist));
    nw->next = NULL;
    if (nw == NULL)
    {
        puts("Memory not allocated");
    }
    puts("Enter the data");
    scanf("%d", &nw->n);
    if (start == NULL)
    {
        start = nw;
        nw->next = nw;
        tail = nw;
    }
    else
    {
        temp = start;
        while (temp->next != start)
        {
            temp = temp->next;
        }
        nw->next = start;
        temp->next = nw;
        tail = nw;
    }
    printf("Node Inseted at last..");
}

void insert_first()
{
    nw = (struct cslist *)malloc(sizeof(struct cslist));

    printf("Enter the data--");
    scanf("%d", &nw->n);

    nw->next = start;
    start = nw;
    tail->next = start;
    printf("\nNode Inserted at First");
}

void search()
{
    int s, f = 0;

    if (start == NULL)
    {
        puts("List is Empty");
    }
    else
    {
        puts("Enter the data to be search");
        scanf("%d", &s);
        temp = start;
        do
        {
            if (temp->n == s)
            {
                f = 1;
                break;
            }

            temp = temp->next;

        } while (temp != start);
        if (f == 0)
        {
            puts("Data not found");
        }
        else
        {
            puts("Data found");
        }
    }
}

void insert_after()
{
    int s, f = 0;
    // struct cslist *prev=NULL;
    if (start == NULL)
    {
        puts("List is Empty");
    }
    else
    {
        puts("Enter the data to be search");
        scanf("%d", &s);
        temp = start;
        do
        {
            if (temp->n == s)
            {
                f = 1;
                break;
            }
            // prev=temp;
            temp = temp->next;

        } while (temp != start);
        if (f == 0)
        {
            puts("Data not found");
        }
        else
        {

            nw = (struct cslist *)malloc(sizeof(struct cslist));
            puts("Enter the data");
            scanf("%d", &nw->n);

            nw->next = temp->next;
            temp->next = nw;
            if (nw->next == start)
            {
                tail = nw;
            }

            puts("Node Inserted After");
        }
    }
}

void insert_before()
{
    int s, f = 0;
    struct cslist *prev = NULL;
    if (start == NULL)
    {
        puts("List is Empty");
    }
    else
    {
        puts("Enter the data to be search");
        scanf("%d", &s);
        temp = start;
        do
        {
            if (temp->n == s)
            {
                f = 1;
                break;
            }
            prev = temp;
            temp = temp->next;

        } while (temp != start);
        if (f == 0)
        {
            puts("Data not found");
        }
        else
        {
            nw = (struct cslist *)malloc(sizeof(struct cslist));
            puts("Enter the data");
            scanf("%d", &nw->n);
            if (prev == NULL)
            {
                nw->next = start;
                start = nw;
                tail->next = start;
            }
            else
            {
                nw->next = temp;
                prev->next = nw;
            }
            puts("Node Inserted");
        }
    }
}

void showlist()
{
    if (start == NULL)
    {
        printf("List is empty");
    }
    else
    {

        temp = start;
        do
        {
            printf("\n%d", temp->n);
            temp = temp->next;

        } while (temp != start);
    }
}

void delete_last()
{
    struct cslist *prev = NULL;
    temp = start;
    if (start == NULL)
    {
        puts("List is Empty");
    }
    else
    {
        if (start->next == start)
        {
            start = NULL;
        }
        else
        {
            while (temp->next != start)
            {
                prev = temp;
                temp = temp->next;
            }
            tail = prev;
            tail->next = start;
            temp->next = NULL;
            free(temp);
        }
        puts("Last node deleted");
    }
}

void delete_first()
{
    if (start == NULL)
    {
        printf("\nList is Empty");
    }
    else
    {
        if (start->next == start)
        {
            start = NULL;
        }
        else
        {
            temp = start;
            start = start->next;
            temp->next = NULL;
            tail->next = start;
            free(temp);
        }
        puts("First node deleted");
    }
}

void delete_anyNode()
{
    if (start == NULL)
    {
        puts("List is empty");
    }
    else
    {
        int s, f = 0;
        struct cslist *prev = NULL;
        puts("Enter the data to search");
        scanf("%d", &s);
        if (start->n == s)
        {
            start = NULL;
        }
        else
        {
            temp = start;
            do
            {
                if (temp->n == s)
                {
                    f = 1;
                    break;
                }
                prev = temp;
                temp = temp->next;
            } while (temp != start);
            if (f == 0)
            {
                puts("Data not found");
            }
            else
            {
                if (temp->next == start)
                {
                    tail = prev;
                    tail->next = start;
                    temp->next = NULL;
                    free(temp);
                }
                else
                {
                    prev->next = temp->next;
                    temp->next = NULL;
                    free(temp);
                }
            }
        }
        puts("Node Deleted");
    }
}

void modify()
{
    int s, f = 0;

    if (start == NULL)
    {
        puts("List is Empty");
    }
    else
    {
        puts("Enter the data to be search");
        scanf("%d", &s);
        temp = start;
        do
        {
            if (temp->n == s)
            {
                f = 1;
                break;
            }

            temp = temp->next;

        } while (temp != start);
        if (f == 0)
        {
            puts("Data not found");
        }
        else
        {
            puts("Enter new data");
            scanf("%d", &temp->n);
            puts("Data Modified");
        }
    }
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
        switch (ch)
        {
        case 1:
            insert_last();
            break;
        case 2:
            insert_first();
            break;
        case 3:
            showlist();
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
            delete_last();
            break;
        case 8:
            delete_first();
            break;
        case 9:
            delete_anyNode();
            break;
        case 10:
            modify();
            break;
        default:
            printf("Invalid Choice");
        }

    } while (ch != 0);
}
