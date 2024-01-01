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
		cout << "total sum is : " << sum;
		return;
	}
	
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
