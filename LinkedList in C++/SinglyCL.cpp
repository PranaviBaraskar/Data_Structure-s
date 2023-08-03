
/////////////////////////////////////////////////////////////////////////////////////////////////
//
//------------------------------* SINGLY CIRCULAR LINKED LIST *--------------------------------------
//
////////////////////////////////////////////////////////////////////////////////////////////////


#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////
//
//------------*    CLASS OF CIRCULAR LINKED LIST     *--------------------
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

//----------------------------------------------------------------------------------------------
//           INHERITED CLASS OF LinkedList :
//----------------------------------------------------------------------------------------------


class SinglyCL : public LinkedList
{
    private :
            PNODE Last;

    public :

        SinglyCL();
        ~SinglyCL();

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
//            FUNCTION NAME : SinglyLL()  [ CONSTRUCTOR ]
//----------------------------------------------------------------------------------------------

SinglyCL :: SinglyCL()
{
    Last = NULL;
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : ~SinglyLL()  [ DESTRUCTOR ]
//----------------------------------------------------------------------------------------------

SinglyCL :: ~SinglyCL()
{
    cout<<"Inside Destructor\n";
    PNODE temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : InsertFirst()
//----------------------------------------------------------------------------------------------

void SinglyCL :: InsertFirst(int iNo)
{
    PNODE newn = NULL;

    newn = new NODE(iNo);

    if(First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }

    Last -> next = First;

    iCount++;
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : InsertLast()
//----------------------------------------------------------------------------------------------

void SinglyCL :: InsertLast(int iNo)
{
    PNODE newn = NULL;

    newn = new NODE(iNo);

    if(First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last -> next = newn;
        Last = Last -> next;
    }

    Last -> next = First;
    
    iCount++;
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : InsertAtPos()
//----------------------------------------------------------------------------------------------

void SinglyCL :: InsertAtPos(int iNo, int iPos)
{
    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
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
        PNODE temp = First;

        for(int iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp = temp->next;
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

void SinglyCL :: DeleteFirst()
{
    if((First == NULL) && (Last == NULL))     
    {
        return; 
    }
    else if(First == Last)       
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else        
    {
        First = First->next;
        delete Last->next;    
        Last->next = First;
    }
    iCount--;
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : DeleteLast()
//----------------------------------------------------------------------------------------------

void SinglyCL :: DeleteLast()
{
    if((First == NULL) && (Last == NULL))     
    {
        return; 
    }
    else if(First == Last)       
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else        // LL contains more than one node
    {
        PNODE temp = First;
        
        while(temp->next != Last)
        {
		    temp = temp->next;
        }

        delete Last;
        Last = temp;
        Last->next = First;
    }
    iCount--;
}

//----------------------------------------------------------------------------------------------
//           FUNCTION NAME : DeleteAtPos()
//----------------------------------------------------------------------------------------------

void SinglyCL :: DeleteAtPos(int iPos)
{

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
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
        PNODE temp = First;
        PNODE tempX = NULL;

        for(int iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp = temp->next;
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

void SinglyCL :: Display()
{
    PNODE temp = First;

    if(First != NULL && Last != NULL)
    {
        cout<<"Elements of Singly Circular LinkedList : \n";
        cout<<"<- ";
        do
        {
            cout<<"| "<<temp->data<<" |->";
            temp = temp -> next;
        }while(temp != Last->next);
        
        cout<<"\n";
    }
    else
    {
        cout<<"Linked List is empty\n";
    }
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : CountNode()
//----------------------------------------------------------------------------------------------

int SinglyCL :: CountNode()
{
    return iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//-------------------------***      MAIN FUNCTION ENTRY :
//
////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    int iRet = 0;
    SinglyCL obj;

    cout<<"\n";
    cout<<"-------------------------SINGLY CIRCULAR LINKED LIST [int]--------------------\n\n";

    cout<<"--------------* Insert_First *---------------------------------------\n\n";

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.CountNode();
    cout<<"Numbers of elements in Singly Circular LinkedList : "<<iRet<<"\n";
    cout<<"\n";

    cout<<"--------------* Insert_Last *---------------------------------------\n\n";

    obj.InsertLast(101);
    obj.InsertLast(111);

    obj.Display();
    iRet = obj.CountNode();
    cout<<"Numbers of elements in Singly Circular LinkedList : "<<iRet<<"\n";
    cout<<"\n";

    cout<<"--------------* Insert_At_Pos *---------------------------------------\n\n";

    obj.InsertAtPos(55,4);

    obj.Display();
    iRet = obj.CountNode();
    cout<<"Numbers of elements in Singly Circular LinkedList : "<<iRet<<"\n";
    cout<<"\n";

    cout<<"--------------* Delete_At_Pos *---------------------------------------\n\n";

    obj.DeleteAtPos(4);

    obj.Display();
    iRet = obj.CountNode();
    cout<<"Numbers of elements in Singly Circular LinkedList : "<<iRet<<"\n";
    cout<<"\n";

    cout<<"--------------* Delete_First *---------------------------------------\n\n";

    obj.DeleteFirst();

    obj.Display();
    iRet = obj.CountNode();
    cout<<"Numbers of elements in Singly Circular LinkedList : "<<iRet<<"\n";
    cout<<"\n";

    cout<<"--------------* Delete_Last *---------------------------------------\n\n";

    obj.DeleteLast();

    obj.Display();
    iRet = obj.CountNode();
    cout<<"Numbers of elements in Singly Circular LinkedList : "<<iRet<<"\n";
    cout<<"\n";


    return 0;
}