#include<iostream>
using namespace std;
template <class T>

class Node
{
public:
	T data;
	Node* next;
};
template <class T>
class LinkedList
{
protected:
	Node<T>* tail;
	Node<T>* head;

public:
	virtual void insertAtFront(T) = 0;

	virtual void insertAtEnd(T) = 0;

	virtual T removeFromFront() = 0;

	virtual T removeFromEnd() = 0;
};

template <class T>
class List : protected LinkedList<T>
{

public:
	List()
	{
		head = nullptr;
		tail = nullptr;
	}

	T front()
	{
		if (head != nullptr)
			return head->data;
	}

	T back()
	{
		if (head != nullptr)
			return tail->data;
	}

	bool empty()
	{
		if (head == nulllptr)
			return true;
		return false;
	}

	int size()
	{
		int count = 0;

		if (head == nullptr)
		{
			return count;
		}

		Node<T>* temp = new Node<T>;
		temp = head;

		while (temp != tail)
		{
			temp = temp->next;
			count++;
		}
		count++;
		return count;
	}

	void insertAtFront(T d)
	{
		Node<T>* temp = new Node<T>;
		temp->data = d;

		if (head == tail && head == nullptr)
		{
			temp->next = nullptr;
			head = temp;
			tail = temp;

		}
		else
		{
			temp->next = head;
			head = temp;
			tail->next = head->next;//circular implementation
		}
		temp = nullptr;
	}

	void insertAtEnd(T d)
	{
		Node<T>* temp = new Node<T>;
		temp->data = d;

		temp->next = nullptr;

		if (head == nullptr)
		{
			head = temp;
			tail = temp;
		}

		tail->next = temp;
		tail = temp;
		tail->next = head->next;//circular implementation

		temp = nullptr;
	}

	T removeFromFront()
	{
		Node<T>* temp = new Node<T>;

		temp = head;

		head = head->next;

		temp->next = nullptr;
		tail->next = head->next;//circular implementation

		return temp->data;
	}

	T removeFromEnd()
	{
		if (head != nullptr)
		{
			Node<T>* rNode = new Node<T>;
			Node<T>* temp = new Node<T>;

			temp->next = head;

			while (temp->next != tail)
			{
				temp = temp->next;
			}

			tail = temp;

			rNode = temp->next;

			temp->next = nullptr;
			temp = nullptr;
			tail->next = head->next;//circular implementation

			return rNode->data;
		}
	}


	void Sort()
	{
		if (head != nullptr)
		{
			Node<T>* point = new Node<T>;
			Node<T>* temp = new Node<T>;

			T temp_var;
			point = head;

			while (point->next != tail)
			{
				temp = point->next;

				while (true)
				{
					if (temp->data < point->data)
					{
						temp_var = temp->data;
						temp->data = point->data;
						point->data = temp_var;
					}

					temp = temp->next;

					if (temp == tail)
					{
						if (temp->data < point->data)
						{
							temp_var = temp->data;
							temp->data = point->data;
							point->data = temp_var;
						}
						break;
					}

				}
				point = point->next;
			}

			if (temp->data < point->data)
			{
				temp_var = temp->data;
				temp->data = point->data;
				point->data = temp_var;
			}
		}
	}

	void insertSorted(T d)
	{
		if (head != nullptr)
		{
			Node<T>* temp = new Node<T>;
			temp->data = d;

			tail->next = temp;
			temp->next = nullptr;
			tail = temp;
			temp = nullptr;

			Sort();
		}
	}

	void reverseList()
	{
		if (head != nullptr)
		{
			Node<T>* fNode = new Node<T>;
			Node<T>* eNode = new Node<T>;
			Node<T>* findNode = new Node<T>;

			T temp;

			fNode = head;
			eNode = tail;

			int s = size();
			for (int i = 0; i < s / 2; i++)
			{
				temp = eNode->data;
				eNode->data = fNode->data;
				fNode->data = temp;

				fNode = fNode->next;

				findNode = head;
				while (findNode->next != eNode)
				{
					findNode = findNode->next;
				}
				eNode = findNode;
				findNode = nullptr;
			}

		}

	}

	void print()
	{
		if (head == nullptr)
		{
			cout << "List is Empty!" << endl << endl;
		}
		else
		{
			Node<T>* temp = new Node<T>;
			temp = head;

			while (temp != tail)
			{
				cout << temp->data << "    ";
				temp = temp->next;
			}
			cout << tail->data << "    ";
			cout << endl << endl;
		}
	}
};



int main()
{
	List<int> obj;
	int choice;
	do 
	{
		cout << "If You want to insert at front then press 1" << endl;
		cout << "If You want to insert at end then press 2" << endl;
		cout << "If You want to print then press 3" << endl;
		cout << "If You want to remove from end then press 4" << endl;
		cout << "If You want to remove from front then press 5" << endl;
		cout << "If You want to perform insert in the sorted then press 6" << endl;
		cout << "If You want to reverse the list then press 7" << endl;
		cout << "If You want to check if the queue is empty then press 8" << endl;
		cout << "If You want to check the size then press 9" << endl;
		cout << "If You want to sort then press 10" << endl;
		cout << "If You want to end the process then press 0" << endl;
		cout << "Now Enter your choice";
		cin >> choice;

		if (choice == 1) {
			for (int i = 1; i <= 5; i++)
			{
				obj.insertAtFront(i);
			}

			obj.print();
		}
		else if (choice ==2 ) {
			for (int i = 6; i <= 10; i++)
			{
				obj.insertAtEnd(i);
			}

			obj.print();
		}
		else if (choice == 3) {
			obj.print();
		}
		else if (choice == 4) {
			cout << obj.removeFromEnd() << endl << endl;

			obj.print();
		}
		else if (choice ==5 ) {
			cout << obj.removeFromFront() << endl << endl;

			obj.print();
		}
		else if (choice ==6 ) {
			obj.insertSorted(8);

			obj.print();
		}
		else if (choice ==7 ) {
			obj.reverseList();

			obj.print();
		}
		else if (choice == 8) {
			obj.empty();
		}
		else if (choice == 9) {
			obj.size();

		}
		else if (choice ==10 ) {
			obj.Sort();
		}
	} while (choice != 0);
	

	return 0;
}
