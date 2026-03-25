////////////////////////////////////////////////////////////////////////////////////////////////
//
//  GENERALISED DATA STRUCTURE LIBRARY
//
//////////////////////////////////////////////////////////////////////////////////////////////

/*

---------------------------------------------------------------------------------------------------------------
    Type                      Name of class for node                  Name of class for functionality
---------------------------------------------------------------------------------------------------------------
    Singly Linear              SinglyLLLnode                                      SinglyLLL           
    Singly Circular            SinglyCLLnode                                      SinglyCLL           
    Doubly Linear              DoublyLLLnode                                      DoublyLLL           
    Doubly Circular            DoublyCLLnode                                      DoublyCLL           
    Stack                      Stacknode                                          Stack
    Queue                      Queuenode                                          Queue

---------------------------------------------------------------------------------------------------------------

*/

#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////
//
//                 SINGLY LINEAR LINKED LIST USING GENERIC APPROACH
//
//////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name    : SinglyLLLnode
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Used for node structure
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLLLnode
{
    public:

        T data;
        SinglyLLLnode<T>*next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name    : SinglyLLL
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Prototypes of function
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLLL
{
    private:       
                      
        SinglyLLLnode<T>* first;
        int iCount;

    public:

        SinglyLLL();
        void InsertFirst(T);
        void InsertLast(T);

        void DeleteFirst();
        void DeleteLast();

        void Display();
        int Count();

        void InsertAtPos(T, int );
        void DeleteAtPos(int);
    
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : SinglyLLL
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Used to initialize characterstics
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"Singly Linear Linked List gets created\n";
    this->first = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Input         : Data of node
//  Output        : Nothing
//  Description   : Used to insert node at first position
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertFirst(T no)                
{
    SinglyLLLnode<T> * newn = NULL;
    newn = new SinglyLLLnode<T>(no);

    newn->next = this->first;
    this->first = newn ;

    this->iCount++;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Input         : Data of node
//  Output        : Nothing
//  Description   : Used to insert node at Last position
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    SinglyLLLnode<T>* newn = NULL;
    newn = new SinglyLLLnode<T>(no);
    SinglyLLLnode<T>* temp = NULL;

    if(this->iCount == 0)                 
    {
        this->first = newn;
    }
    else
    {
        temp = this->first ;
        
        while(temp->next != NULL)
        {
        temp = temp->next;
        }

        temp->next = newn;
    }

    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Used to delete node at first position
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T>* temp = NULL;

    if(this->first == NULL)
    {
        return ;
    }
    else if(this->first->next == NULL)                    
    {
        delete this->first ;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first->next;
        delete temp;
    }

    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Used to delete node at Last position
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteLast()
{
    SinglyLLLnode<T>* temp =NULL;

    if(this->first == NULL)
    {
        return ;
    }
    else if(this->first->next == NULL)                    
    {
        delete this->first ;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        while ((temp->next->next != NULL))
        {
            temp = temp->next;
        }
        
        delete temp->next;
        temp->next = NULL;
        
    }

    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Used Display linked list
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: Display()
{
    SinglyLLLnode<T>* temp = NULL;
    temp = this->first ;
    int iCnt = 0;

    for(iCnt = 1 ; iCnt <= this->iCount ; iCnt++)             
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Used to count number of elements in Linked List
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLLL<T> :: Count()
{
    return this->iCount;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertAtFirst
//  Input         : Data of node , position of node
//  Output        : Nothing
//  Description   : Used to insert node at given position position
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertAtPos(T no , int pos)
{
    SinglyLLLnode<T>* temp =NULL;
    SinglyLLLnode<T>* newn =NULL;
    
    if(pos < 1 || pos > (this->iCount+1))
    {
        cout<<"Invalid position\n";
        return ;
    }
    
    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == (this->iCount+1))
    {
        this->InsertLast(no);
    }
    else
    {
        int iCnt = 0;
        newn = new SinglyLLLnode<T>(no) ;

        temp = this->first;

        for(iCnt = 1 ; iCnt < pos -1 ; iCnt++)
        {
            temp = temp-> next;
        }

        newn->next = temp->next;
        temp->next = newn;
        this->iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtFirst
//  Input         : position of node
//  Output        : Nothing
//  Description   : Used to Delete node at given position
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    SinglyLLLnode<T>* temp =NULL;
    SinglyLLLnode<T>* target =NULL;

    if(pos < 1 || pos > (this->iCount))
    {
        cout<<"Invalid position\n";
        return ;
    }
    
    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == (this->iCount))
    {
        this->DeleteLast();
    }
    else
    {
        int iCnt = 0;
        temp = this->first;

        for(iCnt = 1 ; iCnt < pos -1 ; iCnt++)
        {
            temp = temp-> next;
        }

        target = temp ->next ;
        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//                  DOUBLY LINEAR LINKED LIST USING GENERIC APPROACH
//
//////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name    : DoublyLLLnode
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Used for node structure
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyLLLnode
{
    public:

        T data;
        DoublyLLLnode*next;
        DoublyLLLnode*prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name    : DoublyLLL
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Prototype of functions
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyLLL
{
    private:

        DoublyLLLnode<T>*first;
        int iCount;
        
    public:

        DoublyLLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T , int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DoublyLLL
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Used to intialize characterstics
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Doubly linear Linked list gets created\n";
    this->first = NULL;
    this->iCount = 0 ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Input         : Data of node
//  Output        : Nothing
//  Description   : Used to insert node at first position
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: InsertFirst(T no )
{
    DoublyLLLnode<T>*newn = NULL;
    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first =  newn;
    }
    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Input         : Data of node
//  Output        : Nothing
//  Description   : Used to insert node at Last position
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> ::InsertLast(T no)
{
    DoublyLLLnode<T>*newn = NULL;
    DoublyLLLnode<T>*temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }

    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertAtFirst
//  Input         : Data of node , position of node
//  Output        : Nothing
//  Description   : Used to insert node at given position
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: InsertAtPos(T no , int pos)
{
    int iCnt =0 ;

    if((pos < 1) || (pos > this->iCount +1))
    {
        cout<<"invalid position\n";
        return ;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if( pos == (iCount+1))
    {
        this->InsertLast(no);
    }
    else
    {
        DoublyLLLnode<T>*temp =NULL;
        DoublyLLLnode<T>*newn = NULL;

        newn = new DoublyLLLnode<T>(no);
        temp = this->first;

        for(iCnt = 1 ; iCnt < pos-1 ; iCnt++)
        {
            temp = temp-> next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this-iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Used to delete node at first position
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: DeleteFirst()
{
    if(this->first == NULL)                                     
    {
        cout<<"Linked list is Empty\n";
        return;
    }
    else if( this->first->next == NULL)                         
    {
        delete this->first ;
        this->first = NULL;
    }
    else                                                       
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }

    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Used to delete node at last position
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: DeleteLast()
{
    if(this->first == NULL)                                    
    {
        cout<<"Linked list is Empty\n";
        return;
    }
    else if( this->first->next == NULL)                         
    {
        delete this->first ;
        this->first = NULL;
    }
    else                                                        
    {
        DoublyLLLnode<T>*temp = NULL;
        temp = this->first;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Input         : position of node
//  Output        : Nothing
//  Description   : Used to insert node at first position
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    int iCnt =0 ;
    DoublyLLLnode<T>*temp =NULL;

    if((pos < 1) || (pos > this->iCount))
    {
        cout<<"invalid position\n";
        return ;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if( pos == (iCount))
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1 ; iCnt < pos-1 ; iCnt++)
        {
            temp = temp-> next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this-iCount--;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Used to Display Linked List
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: Display()
{
    DoublyLLLnode<T>*temp = NULL;
    temp = this->first;

    cout<<"\nNULL<=>";

    while (temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }

    cout<<"NULL\n";  
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Used to count number of node
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//                  SINGLY CIRCULAR LINKED LIST USING GENERIC APPROACH
//
//////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name    : SinglyCLL
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Used for Structure of node
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCLLnode
{
    T data;
    SinglyCLLnode<T>*next;

    SinglyCLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name    : SinglyCLL
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Prototype of functions
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCLL
{
    private:

        SinglyCLLnode<T>*first;
        SinglyCLLnode<T>*last;
        int iCount;

    public:

        SinglyCLL();
        void InsertFirst(T);
        void InsertLast(T );
        void InsertAtPos(T , int );

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : SinglyCLL
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Used intialization of characterstics
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyCLL<T> :: SinglyCLL()
{
    cout<<"Singly Circular Linked List gets created\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Input         : data of node
//  Output        : Nothing
//  Description   : Used to insert node at first position
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: InsertFirst(T no)
{
    SinglyCLLnode<T>* newn = NULL;
    newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else  
    {
        newn->next = this->first;
        this->first = newn;
    
    }
    
    this->last->next = this->first;

    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Input         : data of node
//  Output        : Nothing
//  Description   : Used to insert node at Last position
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>

void SinglyCLL<T> :: InsertLast( T no)
{
    SinglyCLLnode<T>* newn = NULL;
    newn = new SinglyCLLnode<T>(no);

    if(first == NULL || last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn ;
        this->last = newn;
    }

    this->last->next = this->first;

    this->iCount ++ ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertAtPos
//  Input         : data of node , postion of node
//  Output        : Nothing
//  Description   : Used to insert node at given position
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: InsertAtPos(T no, int pos)
{   
    SinglyCLLnode<T>* temp = NULL;
    SinglyCLLnode<T>* newn = NULL;

    newn = new SinglyCLLnode<T>(no) ;


    if(pos <1 || pos >(iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        temp = this->first;

        int iCnt = 0;
        for(iCnt = 1 ; iCnt < pos-1 ; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Used to Delete node at first position
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: DeleteFirst()
{

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Nothing to delete\n";
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->last->next;
        this->last->next = this->first;
    }

    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Used to Delete node at Last position
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>

void SinglyCLL<T> :: DeleteLast()
{
    SinglyCLLnode<T>* temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Nothing to delete\n";
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != this->first)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = this->first;
    }

    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Input         : position of node
//  Output        : Nothing
//  Description   : Used to Delete node at given position
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: DeleteAtPos(int pos)
{
    SinglyCLLnode<T>* temp = NULL;
    SinglyCLLnode<T>* target = NULL;
    
    if(pos <1 || pos >(iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        int iCnt = 0;

        for(iCnt = 1 ; iCnt < pos-1 ; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Used Display Linked List
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: Display()
{
    SinglyCLLnode<T>* temp = NULL;
    temp = this->first;

    if(temp == NULL)
    {
        cout<<"Linked list is Empty\n";
        return ;
    }

    cout<<"\n->";

    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next ;
    } while (temp != this->first);

    cout<<"\n";
    
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Used to Count number of nodes
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyCLL<T> :: Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//                  DOUBLY CIRCULAR LINKED LIST USING GENERIC APPROACH
//
//////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name    : DoublyCLLnode
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Used for structure of node
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCLLnode
{
    T data ; 
    DoublyCLLnode<T>*next;
    DoublyCLLnode<T>*prev;

    DoublyCLL(T no)
    {
        this->data = no;
        this->next = NULL;
        this->prev = NULL;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name    : DoublyCLL
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Prototype of functions
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCLL
{
    private:
        DoublyCLLnode<T>* first;
        DoublyCLLnode<T>* last;
        int iCount;

    public:
        DoublyCLL();

        void InsertFirst(T );
        void InsertLast(T);
        void InsertAtPos(T, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
    
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DoublyCLL
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Used to intialize the characterstics
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
DoublyCLL<T> :: DoublyCLL()
{
    cout<<"Doubly Circular Linked List gets created\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0 ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Input         : data of node
//  Output        : Nothing
//  Description   : Used insert node at First position
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T >
void DoublyCLL<T> :: InsertFirst(T no )
{
    struct DoublyCLLnode<T>* newn = NULL;
    newn = new struct DoublyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        first->prev= newn;
        this->first = newn;
    }

    this->last->next = this->first;
    this->first-> prev = this->last;

    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Input         : data of node
//  Output        : Nothing
//  Description   : Used insert node at Last position
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>

void DoublyCLL<T> :: InsertLast(T no)
{
    struct DoublyCLLnode<T>* newn = NULL;
    newn = new struct DoublyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        newn->prev = this->last;
        this->last = newn;

    }

    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertAtFirst
//  Input         : data of node , position of node
//  Output        : Nothing
//  Description   : Used insert node at given position
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T >

void DoublyCLL<T> ::InsertAtPos(T no , int pos)
{
    struct DoublyCLLnode<T>* temp = NULL;
    struct DoublyCLLnode<T>* newn = NULL;

    newn = new struct DoublyCLLnode<T>(no);

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos ==1)
    {
        this->InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        int iCnt = 0; 
        temp = this->first;

        for(iCnt =1 ; iCnt < pos -1 ;iCnt++)
        {
            temp = temp->next;
        }

        newn -> next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Used Delete node at First position
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> ::DeleteFirst()
{
    if(this->first == NULL && this->last == NULL)
    {
        cout<<"List is Empty\n";
        return;
    }
    else if( this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
    }

    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Used insert node at Last position
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> ::DeleteLast()
{
    if(this->first == NULL && this->last == NULL)
    {
        cout<<"List is Empty\n";
        return;
    }
    else if( this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->last = this->last->prev;
        delete this->last->next;
    }
    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Input         : position of node
//  Output        : Nothing
//  Description   : Used Delete node at given position
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> ::DeleteAtPos(int iPos)
{
    struct DoublyCLLnode<T>* temp = NULL;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos ==1)
    {
        this->DeleteFirst();
    }
    else if(iPos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        int iCnt = 0; 
        temp = this->first;

        for(iCnt =1 ; iCnt < iPos -1 ;iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Used Display linked list
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: Display()
{
    struct DoublyCLLnode<T>* temp = NULL;
    temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Linked List is Empty\n";
        return;
    }

    cout<<"\n<=>";

    do
    {
        cout<<"| "<<temp->data<<" | <=>";
        temp = temp->next;

    } while (temp != this->first);

    cout<<"\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Used to count number of nodes
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCLL<T> :: Count()
{
    return this->iCount;
}


////////////////////////////////////////////////////////////////////////////////////////////////
//
//                            STACK USING GENERIC APPROACH
//
//////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name    : Stacknode
//  Input         : data of stack
//  Output        : Nothing
//  Description   : Structure of stack
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Stacknode
{
    public:

        T data;
        Stacknode<T>*next;

        Stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name    : Stack
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Prototype of function
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Stack
{
    private:

        Stacknode<T>*first;
        int iCount;

    public:

        Stack();
        void Push(T);                                        
        T Pop();                                            
        T Peep();
        void Display();
        int Count();

};

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Stack
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Initialization of members (Constructor)
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
Stack<T> :: Stack()
{
    cout<<"Stack gets created succesfully...\n";
    this->first = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Push
//  Input         : data of stack
//  Output        : Nothing
//  Description   : Used to insert element into stack
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Stack<T>:: Push(T no)
{
    Stacknode<T>*newn = NULL;
    newn = new Stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}  

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Pop
//  Input         : Nothing
//  Output        : Removed element from stack
//  Description   : Remove element from the stack
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T Stack<T> :: Pop()
{
    T Value = 0;
    Stacknode<T>*temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is Empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp ;

    this->iCount--;

    return Value;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Peep
//  Input         : Nothing
//  Output        : Return the element from of the stack
//  Description   : Return the topmodt element of the stack
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T Stack<T> :: Peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack is Empty\n";
        return -1;
    }

    Value = this->first->data;

    return Value;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Display the element of the stack
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Stack<T> ::  Display()
{
    Stacknode<T>*temp = NULL;
    temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is Empty.\n";
        return;
    }

    while (temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Used to count number of element in the stack
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int Stack<T> :: Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//                  QUEUE USING GENERIC APPROACH
//
//////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name    : Queuenode
//  Input         : Data of Queue
//  Output        : Nothing
//  Description   : structure of queue
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Queuenode
{
    public:

        T data;
        Queuenode<T>*next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name    : Queue
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Prototype of functions
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Queue
{
    private:

        Queuenode<T> *first;
        Queuenode<T> *last;
        int iCount;

    public:

        Queue();
        void enqueue(T);                                                  
        T dequeue();                                                   
        void Display();
        int Count();

};

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Queue
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Intialization of members(Constructor)
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
Queue<T> :: Queue()
{
    cout<<"Queue gets created succesfully...\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : enqueue
//  Input         : data for queue
//  Output        : Nothing
//  Description   : Insert the element in the queue
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Queue<T> :: enqueue(T no)
{
    Queuenode<T>*newn = NULL;
    newn = new Queuenode<T>(no);

    if(this->first == NULL && this->last ==NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;
    }
    
    this->iCount++;
}  

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : dequeue
//  Input         : Nothing
//  Output        : Return the removed element from queue
//  Description   : Remove element from queue
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T Queue<T> :: dequeue()
{
    T Value = 0;
    Queuenode<T>*temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is Empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp ;

    this->iCount--;

    return Value;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Display elements of queue
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Queue<T> ::  Display()
{
    Queuenode<T>*temp = NULL;
    temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is Empty.\n";
        return;
    }

    while (temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<"\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Count number of elements into queue
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int Queue<T> :: Count()
{
    return this->iCount;
}


/////////////////////////////////END OF LIBRARY////////////////////////////////////////////////

int main()
{
    return 0 ;
}
