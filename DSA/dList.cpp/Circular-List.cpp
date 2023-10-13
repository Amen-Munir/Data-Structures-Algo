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
else
{
    node*new_node=new node(n);
    new_node->prev = tail;
    new_node->next=head;
    head->prev=new_node;
    head = new_node;
    tail->next = head;
}


}

void insertAfter(int num )
{
 if(head==NULL)
 {
   node*new_node=new node(num);
    head=new_node;
    tail=new_node;
    new_node->next = head;
    new_node->prev = head;
 }
 else if(head->next==head)
 {
    node*new_node=new node(num);
    new_node->prev = head;
    new_node->next=head;
    tail = new_node;
    head-> prev = new_node;
 }
 else
 {    node*new_node=new node(num);
    new_node->next=head;
    new_node->prev = tail;
    head->prev = new_node;
    tail->next = new_node;
    tail = new_node;
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
			while (temp==head)
			{
				cout << temp->value << " ";
                temp = temp->next;
                if(temp->next==head)
                {
                break;
                }

				
			}
		}
	}

 void deleteNode(int n)
 {
        node *temp;
        bool isfound = false;

        while (temp != NULL)
        {
            if (temp->value == n)
            {
                isfound = true;
                break;
            }
            temp = temp->next;
 }
 if(isfound==false)
 {
  cout << "\nValue to be deleted is not found in the list" << endl;

 }


 }


};

    int main()

{
    dlist list;
    
    cout << "\n---------------------Circular List  -----------------------------------"<<endl;
    
    list.insertbefore(5);
   
    list.printForward();
    list.insertAfter(6);
    list.printForward();
     
}