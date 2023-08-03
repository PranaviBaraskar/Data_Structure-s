
////////////////////////////////////////////////////////////////////////////////////////////////
//
//-------------------------***      DOUBLY CIRCULAR LINKED LIST :
//
////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////
//
//-----------*     CLASS OF CIRCULAR LINKED LIST     *--------------------
//
////////////////////////////////////////////////////////////////////////////////////////////////


typedef class Node
{
    public :
        int data;
        Node *next;
        Node *prev;
    
    public :
        Node(int Value)
        {
            data = Value;
            next = NULL;
        }

}NODE, *PNODE;

//----------------------------------------------------------------------------------------------
//           CLASS OF DOUBLY CIRCULAR AND DECLEARATION OF FUNCTIONS
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

class DoublyCL : public LinkedList
{
    private :
            PNODE Last;

    public :

        DoublyCL();
        ~DoublyCL();

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
//            FUNCTION NAME : DoublyCL()  [ CONSTRUCTOR ]
//----------------------------------------------------------------------------------------------

DoublyCL :: DoublyCL()
{
    Last = NULL;
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : ~DoublyCL()  [ DESTRUCTOR ]
//----------------------------------------------------------------------------------------------

DoublyCL :: ~DoublyCL()
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

void DoublyCL :: InsertFirst(int iNo)
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
        First->prev = newn;
        newn->next = First;
        First = newn;
    }

    Last -> next = First;
    First->prev = Last;

    iCount++;
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : InsertLast()
//----------------------------------------------------------------------------------------------

void DoublyCL :: InsertLast(int iNo)
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
        newn->prev = Last;
        Last = newn;
    }

    First->prev = Last;
    Last -> next = First;
    
    iCount++;
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : InsertAtPos()
//----------------------------------------------------------------------------------------------

void DoublyCL :: InsertAtPos(int iNo, int iPos)
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
        temp -> next -> prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : DeleteFirst()
//----------------------------------------------------------------------------------------------

void DoublyCL :: DeleteFirst()
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
        First->prev = Last;
    }
    iCount--;
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : DeleteLast()
//----------------------------------------------------------------------------------------------

void DoublyCL :: DeleteLast()
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
        Last = Last->prev;
        delete Last->next;

        First->prev = Last;
        Last->next = First;
        
    }
    iCount--;
}

//----------------------------------------------------------------------------------------------
//           FUNCTION NAME : DeleteAtPos()
//----------------------------------------------------------------------------------------------

void DoublyCL :: DeleteAtPos(int iPos)
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

        for(int iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next -> prev = temp;

        iCount--;
    
    }
}

//----------------------------------------------------------------------------------------------
//            FUNCTION NAME : Display()
//----------------------------------------------------------------------------------------------

void DoublyCL :: Display()
{
    PNODE temp = First;

    if(First != NULL && Last != NULL)
    {
        cout<<"Elements of Doubly Circular LinkedList : \n";
        cout<<"<=> ";
        do
        {
            cout<<"| "<<temp->data<<" |<=>";
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

int DoublyCL :: CountNode()
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
//-------------------------***      DOUBLY CIRCULAR LINKED LIST :
//
////////////////////////////////////////////////////////////////////////////////////////////////

    int iRet = 0;
    DoublyCL obj;

    cout<<"-------------------------DOUBLY CIRCULAR LINKED LIST--------------------\n\n";

    cout<<"\n";

    cout<<"\n--------------* Insert_First *---------------\n\n";

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.CountNode();
    cout<<"Numbers of elements in Doubly Circular LinkedList : "<<iRet<<"\n";
    cout<<"\n";

    cout<<"\n--------------* Insert_Last *---------------\n\n";

    obj.InsertLast(101);
    obj.InsertLast(111);

    obj.Display();
    iRet = obj.CountNode();
    cout<<"Numbers of elements in Doubly Circular LinkedList : "<<iRet<<"\n";
    cout<<"\n";

    cout<<"\n--------------* Insert_At_Pos *---------------\n\n";

    obj.InsertAtPos(55,4);

    obj.Display();
    iRet = obj.CountNode();
    cout<<"Numbers of elements in Doubly Circular LinkedList : "<<iRet<<"\n";
    cout<<"\n";
    
    cout<<"\n--------------* Delete_At_Pos *---------------\n\n";

    obj.DeleteAtPos(4);

    obj.Display();
    iRet = obj.CountNode();
    cout<<"Numbers of elements in Doubly Circular LinkedList : "<<iRet<<"\n";
    cout<<"\n";

    cout<<"\n--------------* Delete_First *---------------\n\n";

    obj.DeleteFirst();

    obj.Display();
    iRet = obj.CountNode();
    cout<<"Numbers of elements in Doubly Circular LinkedList : "<<iRet<<"\n";
    cout<<"\n";

    cout<<"\n--------------* Delete_Last *---------------\n\n";

    obj.DeleteLast();

    obj.Display();
    iRet = obj.CountNode();
    cout<<"Numbers of elements in Doubly Circular LinkedList : "<<iRet<<"\n";
    cout<<"\n";


    return 0;
}