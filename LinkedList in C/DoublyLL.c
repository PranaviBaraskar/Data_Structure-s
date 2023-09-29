
////////////////////////////////////////////////////////////////////////////////////////////////
//
//-------------------------***      DOUBLY LINEAR LINKED LIST :
//
////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////////////
//
//-----------*     STRUCTURE OF LINEAR LINKED LIST     *--------------------
//
////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;     // #

}NODE, *PNODE, **PPNODE;

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : Display()
//----------------------------------------------------------------------------------------------

void Display(PNODE Head)
{
    printf("Elements of Linked List are :\n");
    printf("NULL <=> ");

    while(Head != NULL)
    {
        printf("| %d | <=> ",Head->data);
        Head = Head->next;
    }

    printf("NULL \n");
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : Count()
//----------------------------------------------------------------------------------------------

int Count(PNODE Head)
{
    int iCnt = 0;

    while(Head != NULL)
    {
        iCnt++;
        Head = Head->next;
    }
    return iCnt;
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : InsertFirst()
//----------------------------------------------------------------------------------------------

void InsertFirst(PPNODE Head, int No)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;      //  #

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        (*Head)->prev = newn;
        newn->next = *Head;
        *Head = newn;
    }
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : InsertLast()
//----------------------------------------------------------------------------------------------

void InsertLast(PPNODE Head, int No)
{
    PNODE newn = NULL;
    PNODE temp = *Head;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;      //  #

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        newn->prev = temp;      //  #
        temp->next = newn;
    }
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : DeleteFirst()
//----------------------------------------------------------------------------------------------

void DeleteFirst(PPNODE Head)
{
    if(*Head == NULL)
    {
        return;
    }
    else if((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        free((*Head)->prev);
        (*Head)->prev = NULL;   
    }
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : DeleteLast()
//----------------------------------------------------------------------------------------------

void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;

    if(*Head == NULL)
    {
        return;
    }
    else if((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : InsertAtPos()
//----------------------------------------------------------------------------------------------

void InsertAtPos(PPNODE Head, int No, int iPos)
{
    PNODE newn = NULL;
    int iLength = 0;
    iLength = Count(*Head);

    int iCnt = 0;
    PNODE temp = *Head;

    if((iPos < 1) || (iPos > iLength+1))
    {
        printf("Invalid position\n");
    }
    else if (iPos == 1)
    {
        InsertFirst(Head,No);
    }
    else if(iPos == iLength+1)
    {
        InsertLast(Head,No);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        
        
        
    }
}

//----------------------------------------------------------------------------------------------
//           FUNCTION NAME : DeleteAtPos()
//----------------------------------------------------------------------------------------------

void DeleteAtPos(PPNODE Head, int iPos)
{
    int iLength = 0;
    iLength = Count(*Head);

    int iCnt = 0;
    PNODE temp = *Head;

    if((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid position\n");
    }
    else if (iPos == 1)
    {
        DeleteFirst(Head);
    }
    else if(iPos == iLength)
    {
        DeleteLast(Head);
    }
    else
    {
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;
    printf("\n");

    cout<<"\n--------------* Insert_First *---------------\n\n";

    InsertFirst(&First,101);
    InsertFirst(&First,51);
    InsertFirst(&First,21);
    InsertFirst(&First,11);

    iRet = Count(First);
    printf("Number of elements are : %d\n",iRet);

    Display(First);
    printf("\n");

    cout<<"\n--------------* Insert_Last *---------------\n\n";

    InsertLast(&First,111);
    InsertLast(&First,121);

    iRet = Count(First);
    printf("Number of elements are : %d\n",iRet);

    Display(First);
    printf("\n");

    cout<<"\n--------------* Insert_At_Pos *---------------\n\n";

    InsertAtPos(&First,55,4);
    iRet = Count(First);
    printf("Number of elements are : %d\n",iRet);

    Display(First);
    printf("\n");

    cout<<"\n--------------* Delete_At_Pos *---------------\n\n";

    DeleteAtPos(&First,4);
    iRet = Count(First);
    printf("Number of elements are : %d\n",iRet);

    Display(First);
    printf("\n");

    cout<<"\n--------------* Delete_First *---------------\n\n";

    DeleteFirst(&First);

    iRet = Count(First);
    printf("Number of elements are : %d\n",iRet);

    Display(First);
    printf("\n");

    cout<<"\n--------------* Delete_Last *---------------\n\n";
    
    DeleteLast(&First);

    iRet = Count(First);
    printf("Number of elements are : %d\n",iRet);

    Display(First);
    printf("\n");
    

    return 0;
}