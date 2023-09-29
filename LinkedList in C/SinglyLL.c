
////////////////////////////////////////////////////////////////////////////////////////////////
//
//-------------------------***      SINGLY LINEAR LINKED LIST :
//
////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////////////
//
//------------*    STRUCTURE OF SINGLY LINEAR LIST     *--------------------
//
////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct Node
{
    int data;
    struct Node *next;

}NODE, *PNODE, **PPNODE;

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : Display()
//----------------------------------------------------------------------------------------------

void Display(PNODE Head)
{
    printf("Elements of linkedlist are : \n");

    while(Head != NULL)
    {
        printf("| %d | -> ",Head->data);
        Head = Head->next;
    }
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : Count()
//----------------------------------------------------------------------------------------------

int Count(PNODE Head)
{
    int iCount = 0;

    while(Head != NULL)
    {
        iCount++;
        Head = Head->next;
    }
    printf("NULL\n");

    return iCount;
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : InsertFirst()
//----------------------------------------------------------------------------------------------

void InsertFrist(PPNODE Head, int No)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
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

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        PNODE temp = *Head;

        while(temp->next != NULL)
        {
            temp = temp -> next;
        }

        temp->next = newn;
    }
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : DeleteFirst()
//----------------------------------------------------------------------------------------------

void DeleteFirst(PPNODE Head)
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
        *Head = (*Head) -> next;
        free(temp);
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
        
        while(temp->next->next !=  NULL)
        {
            temp = temp->next;
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
    int iLength = 0;
    iLength = Count(*Head);

    PNODE newn = NULL;
    int iCnt = 0;
    PNODE temp = *Head;

    if((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(Head);
    }
    else if(iPos == iLength)
    {
        DeleteLast(Head);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = No;
        newn->next = NULL;

        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

    }

}

//----------------------------------------------------------------------------------------------
//           FUNCTION NAME : DeleteAtPos()
//----------------------------------------------------------------------------------------------


void DeleteAtPos(PPNODE Head, int iPos)
{
    int iLength = 0;
    iLength = Count(*Head);

    PNODE newn = NULL;
    int iCnt = 0;
    PNODE temp = *Head;
    PNODE tempX = NULL;

    if((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
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

        tempX = temp->next;

        temp->next = temp->next->next;

        free(tempX);
    }

}

//----------------------------------------------------------------------------------------------
//                          ~*~     END_OF_FUNCTIONS     ~*~
//----------------------------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////////////////////
//
//-------------------------***      MAIN FUNCTION ENTRY :
//
////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE First = NULL;
    int iRet = 0;

///////////////////////////////////////////////////////////////////////////////////////////////
//
//-------------------------***     CALLS SINGLY LINEAR LINKED LIST :
//
////////////////////////////////////////////////////////////////////////////////////////////////

    cout<<"\n--------------* Insert_First *---------------\n\n";

    InsertLast(&First,11);
    InsertLast(&First,21);
    InsertLast(&First,51);
    InsertLast(&First,101);

    Display(First);
    iRet = Count(First);

    printf("Number of nodes are : %d\n",iRet);

    cout<<"\n--------------* Insert_Last *---------------\n\n";

    InsertFrist(&First,10);
    InsertFrist(&First,20);

    Display(First);

    iRet = Count(First);
    printf("Number of nodes are : %d\n",iRet);

    cout<<"\n--------------* Insert_At_Pos *---------------\n\n";

    InsertAtPos(&First,25,5);

    Display(First);

    iRet = Count(First);
    printf("Number of nodes are : %d\n",iRet);

    cout<<"\n--------------* Delete_At_Pos *---------------\n\n";

    DeleteAtPos(&First,5);

    Display(First);

    iRet = Count(First);
    printf("Number of nodes are : %d\n",iRet);

    cout<<"\n--------------* Delete_First *---------------\n\n";

    DeleteFirst(&First);
    Display(First);

    iRet = Count(First);
    printf("Number of nodes are : %d\n",iRet);

    cout<<"\n--------------* Delete_Last *---------------\n\n";

    DeleteLast(&First);
    Display(First);

    iRet = Count(First);
    printf("Number of nodes are : %d\n",iRet);

    
//------------------------------------------------------------------------------------------------------
//                          ~*~     END_OF_PROGRAM     ~*~
//-------------------------------------------------------------------------------------------------------


    return 0;
}
