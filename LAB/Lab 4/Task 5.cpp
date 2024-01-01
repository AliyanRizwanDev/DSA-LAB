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
		sum_of_list(head,sum)
	}
	else
	{
		cout << "total sum is : " << sum;
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

void prodOfPrime(Node* temp)
{
	Node* ptr = *temp;
    Node* next;
	if (ptr->next==NULL){
		return;
	}
    int prod = 1;
   
    while (ptr != NULL) {
        
        if (isPrime(ptr->data))
            prod = prod * ptr->data;
            cout<<prod<<endl;
        
    }
    ptr=ptr->next;
    prodOfPrime(ptr);
}

void  AllOccurOfAnElement(Node* head, int x)
{
    
    if (head == NULL)
        return;
  
    Node* temp = head;
    Node* next;
  
   
    if (temp != NULL) {
  
       
        if (temp->data == x) {
            temp = temp->next;
            cout<<data<<endl;
            
        }
     AllOccurOfAnElement(temp,x);
    }
}
  
  void Reverse(Node* node)
{
    
    if (!node)
        return NULL;
 
    
    Node* temp = node->next;
    node->next = node->prev;
    node->prev = temp;
 
    
    if (!node->prev)
        return node;
 
   
    Reverse(node->prev);
}

int main()
{
	Node* head = NULL;
	head = insertatend(head, 1);
	head = insertatend(head, 12);
	head = insertatend(head, 14);
	head = insertatend(head, 120);
	head = insertatend(head, 160);
	head = insertatend(head, 40);
	head = insertatend(head, 10);
	display(head);
	int sum = 0;
	sum_of_list(head, sum);

	return 0;
}
