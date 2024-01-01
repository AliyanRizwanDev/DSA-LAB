#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
};
Node* head = NULL;
Node* newNode(int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	head = newNode;
	return newNode;
}
Node* insertatend(Node* head, int data)
{
	if (head == NULL)
		return newNode(data);
	else
	{
		head->next = insertatend(head->next, data);
	}
	return head;
}
void display(Node* head)
{
	Node* temp = head;
	if (temp != NULL) {
		cout << "The list contains: ";
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	else {
		cout << "The list is empty.\n";
	}
}
void sum_of_list(Node* head,int sum)
{
	Node* temp = head;
	if (temp != NULL) {
		cout << "The list contains: ";
		sum += temp->data;
		temp = temp->next;
		cout << sum << endl;
		sum_of_list(temp,sum);
	}
	else
	{
		cout << "total sum is : " << sum<<endl;
		return;
	}
	
}

bool isPrime(int n)
{
   
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
 
    
    if (n % 2 == 0 || n % 3 == 0)
        return false;
 
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}

void prodOfPrime(Node* head,int prod)
{
	Node* ptr = head->next;
    	if (ptr->next==NULL){
		return;
	}
    
   cout<<endl<<"line wise product"<<endl;
    while (isPrime(ptr->data)!=false) {
        
        if (isPrime(ptr->data))
            prod = prod * ptr->data;
            
            cout<<prod<<endl;
         ptr=ptr->next;
    }
    cout<<"your total product is:"<<prod<<endl;
    ptr=ptr->next;
    prodOfPrime(ptr,prod);
}
	
void  AllOccurOfAnElement(Node* temp, int x ,int count)
{
    if (temp == NULL)
        return;
   // Node* temp = head;
    if (temp->next != NULL) {  
        if (temp->data == x) {  
          count++;        
		 
        }    
    }
    temp=temp->next;
    cout<<count<<endl;
    AllOccurOfAnElement(temp,x,count);  
}

int main()
{
	Node* head = NULL;
	head = insertatend(head, 1);
	head = insertatend(head, 13);
	head = insertatend(head, 23);
	head = insertatend(head, 23);
	head = insertatend(head, 160);
	head = insertatend(head, 40);
	head = insertatend(head, 10);
//	display(head);
//	int sum = 0;
//	int product=1;
//	sum_of_list(head, sum);
//	prodOfPrime(head,product);
int count=0;
Node* temp=head;
 AllOccurOfAnElement(temp,23,count);
	return 0;
}







  


