#include<iostream>
using namespace std;
class node
{ 
    public:
    int value;
    node *next = NULL;
    node *prev = NULL;

    node(int n)
    {
        value = n;

    }

};
class dlist
{
 public:
        node *head = NULL;
        node* tail=NULL;
    


void insertbefore(int n)
{
   
    if(head==NULL && tail==NULL)
{
   node*new_node=new node(n);
    head=new_node;
    tail=new_node;
    new_node->next = head;
    new_node->prev = head;

}


}
void  InsertBefore(int key, int n)
    {
          if (head == NULL && tail == NULL)
    {
        cout << "The key is not found";
        return;

    }
    else 
    {
        node *current = head;
        while(current!=NULL)
        {
            bool isfound = false;
            if (current->value == key)
            {
                isfound= true;

                if (current == head)
                {
                    node *new_node = new node(n);
                    new_node->prev = NULL;
                    new_node->next = head;
                    head->prev = new_node;
                    head = new_node;
                     return;
                }
                else if (current == tail)
                {
                    node *new_node = new node(n);
                    new_node->prev = tail->prev;
                    new_node->next = tail;
                    tail->prev->next = new_node;
                    tail->prev = new_node;
                     return;
                }
                else
                {
                    node *new_node = new node(n);
                    new_node->next = current;
                    new_node->prev = current->prev;
                    current->prev->next = new_node;
                    current->prev = new_node;
                     return;
                }
               

        }
        current = current->next;

        }
           
     
        }
    }
void deleteStart()
{
            node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
}
 void printForward()
	{
		node* temp = head;
		if (temp == NULL)
		{
			cout << "List is empty" << endl;
		}
		else
		{
			while (temp != NULL)
			{
				cout << temp->value << " ";
				temp = temp->next;
			}
		}
	}
void InsertAtStart(int n)
    {
        node *new_node = new node(n);

        if(head==NULL && tail==NULL)
        {
            head = new_node;
            tail = new_node;

        }
        else
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;

        }
    }
 void deleteAtEnd()
{
    node* temp=tail;
    tail = tail->prev;
    tail->next = NULL;
    delete temp;
}
 
 void deleteNode(int n)
 {
    node*temp=head;
    bool isfound=false;

    while(temp!=NULL)
    {
        if(temp->value==n)
        {
            isfound=true;
            break;
            
        }
        temp = temp->next;
 }
 if(isfound==false)
 {
        cout << "\nValue to be deleted is not found" << endl;

 }
 else if(temp==head)
 {
        deleteStart();
 }
 else if(temp==tail)
 {
        deleteAtEnd();
      
 }
else
{

temp->prev->next=temp->next;
temp->next->prev = temp->prev;
delete temp;

}
 }
    
 void Remove(int n)
 {
    node*temp=head;
    bool isfound=false;

    while(temp!=NULL)
    {
        if(temp->value==n)
        {
            isfound=true;
            break;
            
        }
        temp = temp->next;
 }
 if(isfound==false)
 {
        cout << "\nValue to be deleted is not found" << endl;

 }
 else if(temp==head)
 {
        deleteStart();
 }
 else if(temp==tail)
 {
        deleteAtEnd();
      
 }
else
{

temp->prev->next=temp->next;
temp->next->prev = temp->prev;
delete temp;

}
 }

void PrintReverse()
    {
       node* temp = tail;
		if (tail == NULL && head==NULL)
		{
			cout << "List is empty" << endl;
		} 
        else
		{
			while (temp != NULL)
			{
				cout << temp->value << " ";
				temp = temp->prev;
			}
		}
    }

 
 
 
 void InsertBefore(int num)
 { 
    node *new_node = new node(num);
    
     if (head == NULL && tail == NULL)
     {
            head = new_node;
            tail = new_node;

        }
        else
        {
             head->next=tail;
           tail->prev = head;
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
            new_node->prev=tail;
            tail->next = head;
        }

    
 }
 

 void InsertAfter(int num)
 {
 node *new_node = new node(num);
        if(head==NULL && tail==NULL)
        {

            head = new_node;
            tail = new_node;

        }
        else
        {
            new_node->prev = tail;
            new_node->next=head;
            tail->next=new_node;
            head->prev = new_node;
            tail = new_node;
        }
 }
 
 };

    
    int main()

{
    dlist list;
    // list.InsertAtStart(90);
    // list.InsertAtStart(80);
    // list.InsertAtStart(70);
    //  list.InsertAtStart(60);
    //   list.InsertAtStart(50);
    // list.InsertBefore(80,0);
    cout << "\n---------------------1.Insert Before Number -----------------------------------"<<endl;
    list.printForward();
    list.InsertAfter(5);
    list.printForward();
}