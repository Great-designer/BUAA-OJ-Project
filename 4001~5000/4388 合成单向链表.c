#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int data;
    struct node *next;
};

struct node *find_tail_of_link_list(struct node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        struct node *tail = head;
        while (tail->next)
        {
            tail = tail->next;
        }
        return tail;
    }
}

struct node *add_node_to_link_list(struct node *head, struct node *new_node, int data)
{
    new_node->data = data;
    new_node->next = NULL;
    struct node *tail = find_tail_of_link_list(head);
    if (tail == NULL)
    {
        return new_node;
    }
    else
    {
        tail->next = new_node;
        return head;
    }
}

char buffer[64];

void output(struct node *head, struct node *tail)
{
    if (head == NULL)
    {
        printf("The link list is empty.\n");
        return;
    }
    struct node *n = head;
    putchar('\n');
    while (1)
    {
        sprintf(buffer, "%d", n->data);
        int len = (int) strlen(buffer);
        putchar('+');
        for (int i = 0; i < len; i++)
        {
            putchar('-');
        }
        printf(n == tail ? "+-+\n|%d|\\|" : "+----+\n|%d|next|", n->data);
        if (n == head)
        {
            printf(" <----head");
        }
        if (n == tail)
        {
            printf(" <----tail");
        }
        printf("\n+");
        for (int i = 0; i < len; i++)
        {
            putchar('-');
        }
        printf(n == tail ? "+-+\n " : "+-|--+\n ");
        if (n != tail)
        {
            for (int i = 0; i < len + 2; i++)
            {
                putchar('_');
            }
            printf("|\n |\n V\n");
        }
        if (n->next == NULL)
        {
            break;
        }
        n = n->next;
    }
    putchar('\n');
}

int main()
{
    int n;
    scanf("%d", &n);
    struct node *head = NULL, *tail;
    while (n--)
    {
        int data;
        scanf("%d", &data);
        struct node *new_node = (struct node *) malloc(sizeof(struct node));
        head = add_node_to_link_list(head, new_node, data);
    }
    tail = find_tail_of_link_list(head);
    output(head, tail);
    return 0;
}
