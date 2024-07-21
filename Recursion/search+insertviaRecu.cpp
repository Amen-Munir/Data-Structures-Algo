//Amen Munir
//2022-CS-703 



#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* next;
	node(int n)
	{
		data = n;
		next = NULL;

	}

};
class linking
{
public:
	node* head = NULL;

	void InsertAtBeg(int n)
	{
		node* new_node = new node(n);
		if (head == NULL)
		{
			head = new_node;
			new_node->next = NULL;

		}
		else
		{
			new_node->next = head;
			head = new_node;
		}
	}


	void print()
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
				cout << temp->data << " ";
				temp = temp->next;
			}
		}
	}

	void InsertAtEnd(int n)
	{
		node* new_node = new node(n);
		if (head == NULL)
		{
			head = new_node;

		}
		else
		{
			node* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;

			}
			temp->next = new_node;

		}
	}

	void Search(int key)
	{
		node* temp = head;
		while (temp!= NULL)
		{
			if (temp->data == key)
			{
				cout << "Number is Found" << endl;
				return;

			}
			else
			{
				temp = temp->next;


			}

		}
		cout << "Number Not Found";
	}


	void update(int prev, int n)
	{
		node* temp = head;
		while (temp!= NULL)
		{
			if (temp->data == prev)
			{
				temp->data=n;

			}
			else
			{
				temp = temp->next;


			}

		}
	}
		void InsertAfter(int num, int key)
		{
			node *new_node=new node(num);
			node *temp=head;
			while(temp!=NULL)
			{
				if(temp->data==key)
				{
					new_node->next = temp->next;
					temp->next = new_node;
					return;
				}
				else
				{
					temp=temp->next;
				}
			}
			cout<<"Number after which node is to be inserted in not found"<<endl;

		}

		void Delete(int key)
		{
			node *temp=head;
			node *prev;
			while(temp!=NULL)
			{
				if(temp->data==key)
				{
					prev->next=temp->next;
					delete temp;
					return;
				}
				else
				{
					prev=temp;
					temp=temp->next;
				}
			}
			cout<<"Number to be deleted is not found"<<endl;
		}

		 void SortinAsceding() {
        if (head == NULL || head->next == NULL) {
            //list has no elements ans is sorted 
			
            return;
        }

        bool swapped;
        do {
            swapped = false;
            node* prev = NULL;
            node* current = head;
            node* nextNode = head->next;

            while (nextNode != NULL) {
                if (current->data > nextNode->data) {
                    // Swap current and nextNode values.
                    int temp = current->data;
                    current->data= nextNode->data;
                    nextNode->data = temp;
                    swapped = true;
                }

                prev = current;
                current = nextNode;
                nextNode = nextNode->next;
            }
        } while (swapped);
    
}
void swap()
{
	 bool swapped;
        do {
            swapped = false;
            node* prev = NULL;
            node* current = head;
            node* nextNode = head->next;

            while (nextNode != NULL) {
                if (current->data > nextNode->data) {
                    // Swap current and nextNode values.
                    int temp = current->data;
                    current->data= nextNode->data;
                    nextNode->data = temp;
                    swapped = true;
                }

                prev = current;
                current = nextNode;
                nextNode = nextNode->next;
            }
        } while (swapped);
}

int lengthofnode()
{
	node* temp = head;
	int count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}
int calculatesum()
{
	
node* temp = head;
int sum=0;
for(int i=0;i<lengthofnode();i++)
{  if(i==0)
{
				continue;
}
	 if(i%2==0)
{
	

	sum=sum+temp->data;
	temp=temp->next;
}
else
temp=temp->next;


}
cout<<"Sum of all even nodes is: "<<sum<<endl;
return sum;
}

bool SearchUsingRec(node *head , int key )
{
    if(head==NULL)
    {
        return false;
    }

    else if(head->data==key)
        return true;

    else
    return SearchUsingRec(head->next,key);
}

bool delUsingRec(node *head , int key )
{
    if(head==NULL)
    {
        return false;
    }

    else if(head->data==key)
	   {
		Delete(key);
		return true;}

    else
    return SearchUsingRec(head->next,key);
}

bool InsertUsingrecursion(node*head, int val)
{
    if(head->next==NULL)
    {
        InsertAtEnd(val);
        return true;
    }
    else
    return InsertUsingrecursion(head->next,val);
}
int  greaters(node*head,int max)
{    
	if(head==NULL)
	{
	return max;
	}	
else if(max<head->next->data)
	{
		max=head->data;
		
	}
	else
	return greaters(head->next,max);
}
void display(node *head)
{
	if(head==NULL)
	{
	return;
	}
	else
	{display(head->next);
	cout << head->data<<" ";
}
}
};

int main()
{
cout << "NAME: AMEN MUNIR \n ROLL NO: 2022-CS-703" << endl;
linking list;
cout << "\t CURRENT LIST IS:" << endl;
list.InsertAtBeg(90);
list.InsertAtBeg(80);
list.InsertAtEnd(40);
list.InsertAtEnd(30);


list.print();
cout << endl;

cout << list.SearchUsingRec(list.head, 40) << endl; //quest7
cout << list.InsertUsingrecursion(list.head,16) << endl;  //quest 8
list.print();
cout << endl;
cout << list.greaters(list.head,list.head->data) << endl;  //quest 9
cout << endl;
list.display(list.head);//q10
cout<<list.delUsingRec(list.head,40)<<endl; 
list.print();
cout << endl;
}
