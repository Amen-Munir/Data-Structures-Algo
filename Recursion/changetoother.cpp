//Amen Munir
//2022-CS-703 



#include<iostream>
#include<stack>
#include<queue>

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


};

stack<int> ConvertLinkedListtostack(linking &obj,stack<int> &s1)
{
 if(obj.head==NULL)
 {
  return s1;
 }
 else
 {
  s1.push(obj.head->data);
  obj.head=obj.head->next;
  return ConvertLinkedListtostack(obj, s1);
  
 }

}

queue<int> ConvertStackToQueueUsingRecursions(stack<int> s1, queue<int> q1)
{
    if(s1.empty())
    {
    return q1;
    }
    else
    {
   q1.push(s1.top());
    s1.pop();
    return ConvertStackToQueueUsingRecursions(s1, q1);
    }
}


linking convertLinkedListToQueueUsingReacurion(linking &obj, queue<int> q1)
{
    if(obj.head==NULL)
    {
        return obj;
    }
    else
    {
        q1.push(obj.head->data);
        obj.head=obj.head->next;
        return convertLinkedListToQueueUsingReacurion(obj, q1);
    }
}

int main()
{
cout << "NAME: AMEN MUNIR \n ROLL NO: 2022-CS-703" << endl;
linking list;
cout << "\t CURRENT LIST IS:" << endl;
list.InsertAtBeg(90);
list.InsertAtBeg(80);
list.InsertAtEnd(40);
list.InsertAtEnd(30);
stack<int> s1;
stack<int> s= ConvertLinkedListtostack(list, s1);
cout << "Convert Linked list to stack " << endl;

while(!s.empty())
{
    cout<<s.top()<<" ";
    s.pop();
}
cout << "\nConvert Stack to Queue " << endl;
queue<int> q1;
queue<int> q= ConvertStackToQueueUsingRecursions(s1, q1);
queue<int> q2= ConvertStackToQueueUsingRecursions(s1, q1);
while(!q.empty())
{
    cout<<q.front()<<" ";
    q.pop();
}
// cout<<"\n Covert Linked List to Queue"<<endl;
// queue<int> temp;
// queue<int> temp1=convertLinkedListToQueueUsingReacurion(list, temp);
// while(!temp1.empty())
// {
//     cout<<temp1.front()<<" ";
//     temp1.pop();
// }
cout << "\nconvert LinkedList to Queue " << endl;

while(!q2.empty())
{
    cout<<q2.front()<<" ";
    q2.pop();
}
}
