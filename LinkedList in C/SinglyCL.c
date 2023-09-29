
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//------------------------------* SINGLY CIRCULAR LINKED LIST *--------------------------------------
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////////////
//
//------------*    STRUCTURE OF CIRCULAR LINKED LIST     *--------------------
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

void Display(PNODE Head, PNODE Tail)
{
    if((Head != NULL) && (Tail != NULL))
    {
        do 
        {
            printf("|%d| -> ",Head->data);
            Head = Head->next;
        }while(Head != Tail->next);

        printf("\n");
    }
    else
    {
        printf("Linked list is empty\n");
    }
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : Count()
//----------------------------------------------------------------------------------------------

int Count(PNODE Head, PNODE Tail)
{
    int iCnt = 0;

    if((Head != NULL) && (Tail != NULL))
    {
        do 
        {
            iCnt++;
            Head = Head->next;

        }while(Head != Tail->next);

        return iCnt;
    }
    else
    {
        return 0;
    }

}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : InsertFirst()
//----------------------------------------------------------------------------------------------

void InsertFirst(PPNODE Head, PPNODE Tail, int No)
{   
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    
    newn->data = No;
    newn->next = NULL;

    if((*Head == NULL) && (*Tail == NULL))
    {
        *Head  = newn;
        *Tail = newn;

    }
    else
    {
        newn->next = *Head;
        *Head = newn;

    }

    (*Tail)->next = *Head;
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : InsertLast()
//----------------------------------------------------------------------------------------------

void InsertLast(PPNODE Head, PPNODE Tail, int No)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    
    newn->data = No;
    newn->next = NULL;

    if((*Head == NULL) && (*Tail == NULL))
    {
        *Head  = newn;
        *Tail = newn;
    }
    else
    {
        (*Tail)->next = newn;
        (*Tail) = (*Tail) -> next;
    }
    (*Tail)->next = *Head;
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : DeleteFirst()
//----------------------------------------------------------------------------------------------

void DeleteFirst(PPNODE Head, PPNODE Tail)
{
    if((*Head == NULL) && (*Tail == NULL))
    {
        return;
    }
    else if(*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        free((*Tail)->next);
        (*Tail)->next = *Head;
    }
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : DeleteLast()
//----------------------------------------------------------------------------------------------

void DeleteLast(PPNODE Head, PPNODE Tail)
{
    PNODE temp = *Head;

    if((*Head == NULL) && (*Tail == NULL))
    {
        return;
    }
    else if(*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        while(temp->next != *Tail)
        {
            temp = temp->next;
        }

        free(*Tail);
        *Tail = temp;
        (*Tail)->next = *Head;
    }
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : InsertAtPos()
//----------------------------------------------------------------------------------------------

void InsertAtPos(PPNODE Head, PPNODE Tail, int No,int iPos)
{
    PNODE newn = NULL;
    int iLength = 0;
    PNODE temp = *Head;
    int iCnt = 0;

    iLength = Count(*Head, *Tail);

    if((iPos < 1) || (iPos > iLength+1))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(Head,Tail,No);
    }
    else if (iPos == iLength+1)
    {
        InsertLast(Head,Tail,No);
    }
    else
    {
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }
    
        newn = (PNODE)malloc(sizeof(NODE));
        
        newn->data = No;
        newn->next = NULL;

        newn->next = temp->next;
        temp->next = newn;
    }
}

//----------------------------------------------------------------------------------------------
//           FUNCTION NAME : DeleteAtPos()
//----------------------------------------------------------------------------------------------

void DeleteAtPos(PPNODE Head, PPNODE Tail, int iPos)
{
    int iLength = 0;
    PNODE temp = *Head;
    PNODE tempX = NULL;
    int iCnt = 0;

    iLength = Count(*Head, *Tail);

    if((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(Head,Tail);
    }
    else if (iPos == iLength)
    {
        DeleteLast(Head,Tail);
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
//                          ~*~     END_OF_FUNCTIONS    ~*~
//----------------------------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////////////////////
//
//-------------------------***      MAIN FUNCTION ENTRY :
//
////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{

 ////////////////////////////////////////////////////////////////////////////////////////////////
//
//-------------------------***     CALLS SINGLY CIRCULAR LINKED LIST :
//
////////////////////////////////////////////////////////////////////////////////////////////////

    PNODE First = NULL;
    PNODE Last = NULL;
    int iRet = 0;

    printf("\n");

    cout<<"--------------* Insert_First *---------------------------------------\n\n";

    InsertFirst(&First,&Last,51);
    InsertFirst(&First,&Last,21);
    InsertFirst(&First,&Last,11);

    Display(First,Last);
    iRet = Count(First,Last);

    printf("Number of nodes are : %d\n",iRet);
    printf("\n")

    cout<<"--------------* Insert_Last *---------------------------------------\n\n";


    InsertLast(&First,&Last,101);
    InsertLast(&First,&Last,111);
    InsertLast(&First,&Last,121);

    Display(First,Last);
    iRet = Count(First,Last);

    printf("Number of nodes are : %d\n",iRet);
    printf("\n");

    cout<<"--------------* Insert_At_Pos *---------------------------------------\n\n";

    InsertAtPos(&First,&Last,55,4);

    Display(First,Last);
    iRet = Count(First,Last);

    printf("Number of nodes are : %d\n",iRet);
    printf("\n");

    cout<<"--------------* Delete_At_Pos *---------------------------------------\n\n";

    DeleteAtPos(&First,&Last,4);
    Display(First,Last);
    iRet = Count(First,Last);

    printf("Number of nodes are : %d\n",iRet);
    printf("\n");

    cout<<"--------------* Delete_First *---------------------------------------\n\n";

    DeleteFirst(&First,&Last);

    Display(First,Last);
    iRet = Count(First,Last);

    printf("Number of nodes are : %d\n",iRet);
    printf("\n");

    cout<<"--------------* Delete_Last *---------------------------------------\n\n";
    
    DeleteLast(&First,&Last);

    Display(First,Last);
    iRet = Count(First,Last);

    printf("Number of nodes are : %d\n",iRet);
    printf("\n");

    return 0;
}