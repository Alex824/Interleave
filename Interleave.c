#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *next;
    int data;
}node;

///Signatures
node *addNode(node *head, int data);
node *createNode(int data);
void printList(node* head);
node *interleave(node *head1, node *head2);

int main(void)
{
    ///Creates two linked lists with random assortments, these can be changed
    ///or edited to one's liking
    int i=0;

    node *List1 = NULL;
    node *List2 = NULL;

    node *Cross = NULL;

    for(i=1; i<6; i++)
        List1=addNode(List1, i*5);

    for(i=1; i<8; i++)
        List2=addNode(List2, i*4);

    printList(List1);
    printList(List2);

    Cross=interleave(List1, List2);

    printList(Cross);

    return 0;
}

node *createNode(int data)
{
    node *ptr = malloc(sizeof(node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

node *addNode(node *head, int data)
{
    node *temp;
    if (head == NULL)
        return createNode(data);

    temp=head;
    while(temp->next!=NULL)
        temp=temp->next;

    temp->next = createNode(data);
    return head;

}

void printList(node* head)
{
    node* temp=malloc(sizeof(node*));
    temp=head;
    while(temp!=NULL)
    {
        printf("%d -> ", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

node *interleave(node *head1, node *head2)
{
    int i=0;
    node *newList = NULL;
    node *temp1 = head1;
    node *temp2 = head2;

    for(i=0; temp1!=NULL || temp2!=NULL; i++)
    {
        if(i%2==0)
        {
            if(temp1!=NULL)
            {
                newList=addNode(newList, temp1->data);
                temp1=temp1->next;
            }
            else if(temp1==NULL && temp2!=NULL)
            {
                newList=addNode(newList, temp2->data);
                temp2=temp2->next;
            }
            else if(temp1==NULL && temp2==NULL)
                break;
        }
        else
        {
            if(temp2!=NULL)
            {
                newList=addNode(newList, temp2->data);
                temp2=temp2->next;
            }
            else if(temp2==NULL && temp1!=NULL)
            {
                newList=addNode(newList, temp1->data);
                temp1=temp1->next;
            }
            else if(temp1==NULL && temp2==NULL)
                break;
        }
    }

    return newList;
}
