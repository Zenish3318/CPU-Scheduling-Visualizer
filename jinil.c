#include <stdio.h>
#include <stdlib.h>
#define max 100

int stack[max];
int top = -1;

void push(val)
{
    
    if(top == max - 1)
    {
        printf("satck was overflow");
    }
    else
    {
        stack[++top] = val;
        printf("val pushed");
    }
}
void pop()
{   
    if(top == -1)
    {
        printf("stack is overflow");
    }
    else
    {
        printf("popped %d",stack[--top]);
    }
}
void PEEP(int pos) {
    int index = top - pos + 1;
    if (index < 0 || index > top) {
        printf("Invalid Position\n");
    } else {
        printf("Element at position %d from top: %d\n", pos, stack[index]);
    }
}
void change(int pos,int val)
{
    int index = top - pos + 1;
    if(index<0 || index>top)
    {
        printf("invalid position");
    }
    else
    {
        stack[index]= val;
        printf("value was changed");
    }
}
void display()
{   int i;
    if(top == -1)
    {
        printf("stcak is empty");
    }
    else
    {
        for ( i = top; i >=0; i--)
        {
            printf("%d\n",stack[i]);
        }
        
    }
}
int main()
{
    int choice,pos,val;

    while(1)
    {
        printf("**____stack operetion____**\n");
        printf(" ENTER YOUR CHOICE \n ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
        printf("enter val to push");
        scanf("%d",&val);
        push(val);
        break;

        case 2:
        pop();
        break;

        case 3:
        printf("Enter position from top to PEEP: ");
                scanf("%d", &pos);
                PEEP(pos);
        break;

        case 4:
        printf("enter pos for change value");
        scanf("%d",&pos);
        printf("enter val for change ");
        scanf("%d",val);
        change(pos,val);
        break;

        case 5:
        display();
        break;

        case 6:
        return 0;
        
        default:
        printf("invelid choice");
            break;
        }
    }
    return 0;
}