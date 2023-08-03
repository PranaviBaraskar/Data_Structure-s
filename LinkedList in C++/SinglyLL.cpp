
////////////////////////////////////////////////////////////////////////////////////////////////
//
//-------------------------***      SINGLY LINEAR LINKED LIST :
//
////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////
//
//------------*    CLASS OF SINGLY LINEAR LIST     *--------------------
//
////////////////////////////////////////////////////////////////////////////////////////////////

typedef class Node
{
    public :
        int data;
        Node *next;
    
    public :
        Node(int Value)
        {
            data = Value;
            next = NULL;
        }

}NODE, *PNODE;

//----------------------------------------------------------------------------------------------
//           CLASS OF SINGLY LINEAR AND DECLEARATION OF FUNCTIONS
//----------------------------------------------------------------------------------------------

class LinkedList
{
    public :
        PNODE First;
        int iCount;

    public:
        LinkedList()
        {
            First = NULL;
            iCount = 0;
        }

        virtual void InsertFirst(int iNo) = 0;
        virtual void InsertLast(int iNo) = 0;
        virtual void InsertAtPos(int iNo, int iPos) = 0;

        virtual void DeleteFirst() = 0;
        virtual void DeleteLast() = 0;
        virtual void DeleteAtPos(int iPos) = 0;

        virtual void  Display() = 0;
        virtual int CountNode() = 0;
};

class SinglyLL : public LinkedList
{
    public :

        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void  Display();
        int CountNode();
};

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : InsertFirst()
//----------------------------------------------------------------------------------------------

void SinglyLL :: InsertFirst(int iNo)
{
    PNODE newn = NULL;

    newn = new NODE(iNo);

    if(First == NULL)
    {
        First = newn;
    }
    else 
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : InsertLast()
//----------------------------------------------------------------------------------------------

void SinglyLL :: InsertLast(int iNo)
{
    PNODE newn = NULL;

    newn = new NODE(iNo);

    if(First == NULL)
    {
        First = newn;
    }
    else 
    {
        PNODE temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : InsertAtPos()
//----------------------------------------------------------------------------------------------

void SinglyLL :: InsertAtPos(int iNo, int iPos)
{
    PNODE temp = First;

    int iCnt = 0;
    
    if((iPos < 1) || (iPos > iCount+1))     
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(iNo);
    }
    else
    {
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
	        temp = temp -> next;
        }  
        PNODE newn = new NODE(iNo);

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : DeleteFirst()
//----------------------------------------------------------------------------------------------

void SinglyLL :: DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {   
        delete First;
        First = NULL;
    }
    else
    {
        PNODE temp = First;
        First = First->next;
        delete temp;
    }
    iCount--;
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : DeleteLast()
//----------------------------------------------------------------------------------------------

void SinglyLL :: DeleteLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {   
        delete First;
        First = NULL;
    }
    else
    {
        PNODE temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

//----------------------------------------------------------------------------------------------
//           FUNCTION NAME : DeleteAtPos()
//----------------------------------------------------------------------------------------------

void SinglyLL :: DeleteAtPos(int iPos)
{
    PNODE temp = First;
    PNODE tempX = NULL;

    int iCnt = 0;
    
    if((iPos < 1) || (iPos > iCount))     
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
	        temp = temp -> next;
        }  

        tempX = temp->next;

        temp->next = temp->next->next;
        delete tempX;

        iCount--;
    }
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : Display()
//----------------------------------------------------------------------------------------------

void SinglyLL :: Display()
{
    PNODE temp = First;

    cout<<"Elements of Singly Linear LinkedList : \n";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<" NULL\n";
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : CountNode()
//----------------------------------------------------------------------------------------------

int SinglyLL :: CountNode()
{
    return iCount;
}

//----------------------------------------------------------------------------------------------
//                          ~*~     END_OF_CLASS     ~*~
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
//-------------------------***     CALLS SINGLY LINEAR LINKED LIST :
//
////////////////////////////////////////////////////////////////////////////////////////////////

    int iRet = 0;
    SinglyLL obj;

    cout<<"\n";

    cout<<"\n--------------* Insert_First *---------------\n\n";

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.CountNode();
    cout<<"Numbers of elements in Singly Linear LinkedList : "<<iRet<<"\n";
    cout<<"\n";

    cout<<"\n--------------* Insert_Last *---------------\n\n";

    obj.InsertLast(101);
    obj.InsertLast(111);

    obj.Display();
    iRet = obj.CountNode();
    cout<<"Numbers of elements in Singly Linear LinkedList : "<<iRet<<"\n";
    cout<<"\n";

    cout<<"\n--------------* Insert_At_Pos *---------------\n\n";

    obj.InsertAtPos(55,4);

    obj.Display();
    iRet = obj.CountNode();
    cout<<"Numbers of elements in Singly Linear LinkedList : "<<iRet<<"\n";
    cout<<"\n";

    cout<<"\n--------------* Delete_At_Pos *---------------\n\n";

    obj.DeleteAtPos(4);

    obj.Display();
    iRet = obj.CountNode();
    cout<<"Numbers of elements in Singly Linear LinkedList : "<<iRet<<"\n";
    cout<<"\n";

    cout<<"\n--------------* Delete_First *---------------\n\n";

    obj.DeleteFirst();

    obj.Display();
    iRet = obj.CountNode();
    cout<<"Numbers of elements in Singly Linear LinkedList : "<<iRet<<"\n";
    cout<<"\n";

    cout<<"\n--------------* Delete_Last *---------------\n\n";

    obj.DeleteLast();

    obj.Display();
    iRet = obj.CountNode();
    cout<<"Numbers of elements in Singly Linear LinkedList : "<<iRet<<"\n";
    cout<<"\n";


    return 0;
}