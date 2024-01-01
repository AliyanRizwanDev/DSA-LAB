#include<iostream>
using namespace std;
class node {
public:
	node* next;
	node* pre;
	double Ndata;
	node() {
		next = NULL;
		pre = NULL;
		Ndata = 0;
	}
};
/*class doublyabstract {
public:
	virtual
	virtual void insertAtEnd(node* , double) = 0;

};*/

class doublylinkedlist/* :doublyabstract*/ {
public:
	node* head = NULL;
	bool isEmpty(node* head) {
		if (head == NULL) {
			return true;
		}
		else
			return false;
	}
	node* insertAtEnd(node* head, double data)
	{
		node* newnode = new node();
		newnode->Ndata = data;
		node* temp = head;
		while (temp != NULL)
		{

			if (temp->next == NULL)
			{
				newnode->next = NULL;
				temp->next = newnode;
				newnode->pre = temp;
			}
			temp = temp->next;
		}
		if (head == NULL) {
			newnode->next = NULL;
			newnode->pre = head;
		}
		return temp;
	}
	void insertAfter(node* prevref, double val) {
		node* newnode = new node();
		node* temp = head;
		newnode->Ndata = val;
		while (temp != prevref) {
			temp=temp->next;
		}
		if (temp == prevref) {
			newnode->next = prevref->next;
			newnode->pre = prevref;
			prevref->next = newnode;
		}
		else {
			return;
		}
	}
	void insertAtStart(node*h, double val) {
		node* newnode = new node();
		newnode->Ndata = val;
		if (h == NULL) {
			h->next = newnode;
			newnode->pre = h;
		}
		else {
			newnode->next = h->next;
			h->next = newnode;
			newnode->pre = h;
		}
	}
	void insertBefore(node*nextref,double val) {
		node* newnode = new node();
		node* temp = head;
		newnode->Ndata = val;
		while (temp != nextref) {
			temp = temp->next;
		}
		if (temp == nextref) {
			newnode->next = nextref;
			newnode->pre = nextref->pre;
		}
		else {
			return;
		}

	}
	node* insertMid(node* h, double val) {
		node* newnode = new node();
		node* temp = h;
		node* midref = NULL;
		newnode->Ndata = val;
		int n = 0;
		while (temp->next != NULL) {
			temp = temp->next;
			n++;
		}
		temp = h;
		if (n % 2 == 0) {
			n = n / 2;
		}
		else {
			n = n / 2;
			n = n + 1;
		}
		int t = 0;
		while(t==n) {
			temp = temp->next;
			t++;
			
		}
		midref = temp;
		return midref;
	}
	void deleteAtEnd(node* head) {
		node* temp = head;
		if (head == NULL) {
			return;
		}
		else {
			while (temp->next != NULL) {
				if (temp->next == NULL) {
					delete temp;
					temp->pre->next = NULL;
				}
				temp = temp->next;

			}
			return;
		}

	}
	void display(node* head) {
		
		node* temp = head;
		while (temp->next != NULL) {
			cout << temp->Ndata << endl;
			temp = temp->next;
		}
	}
};
int main() {
	doublylinkedlist obj;
	
	obj.insertAtEnd(obj.head, 10);
	obj.insertAtEnd(obj.head, 20);
	obj.insertAtEnd(obj.head, 30);
	obj.insertAtEnd(obj.head, 40);
	obj.display(obj.head);
}