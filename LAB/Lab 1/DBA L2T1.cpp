#include <iostream>
using namespace std;
class List
{
public:
	int* bucky;
	int currentsize;
	int maxsize;
	int ele;
	virtual void addElementAtFirstIndex() = 0;
	virtual void addElementAtLastIndex() = 0;
	virtual void removeElementFromEnd() = 0;
	virtual void removeElementFromStart() = 0;
	virtual void updateElementsFromList() = 0;
};
class List2 : public List
{
public:
	List2()
	{
		maxsize = 5;
		currentsize = 5;
	}
	List2(int maxsize, int currsize)
	{
		this->maxsize = maxsize;
		this->currentsize = currsize;
	}
	void createArr() {
		bucky = new int[maxsize + 1];

		cout << "Enter elements of array and the size of array is 5: " << endl;
		for (int i = 0; i < maxsize; i++)
		{
			cin >> bucky[i];
		}
	}
	void addElementAtFirstIndex()
	{

		cout << "Enter element to add: ";
		cin >> ele;
		maxsize++;
		for (int i = maxsize; i >= 0; i--)
		{
			bucky[i + 1] = bucky[i];

		}
		cout << "After adding at first index:" << endl;
		bucky[0] = ele;
		display();
	}
	void addElementAtLastIndex()
	{

		cout << "Enter element to add: ";
		cin >> ele;
		maxsize++;
		bucky[maxsize - 1] = ele;
		cout << endl;
		display();
	}
	void removeElementFromEnd()
	{
		maxsize--;
		display();
	}
	void removeElementFromStart()
	{

		for (int i = 0; i < maxsize; i++)
		{
			bucky[i] = bucky[i + 1];

		}
		maxsize--;
		display();
	}
	void updateElementsFromList()
	{
		int in;
		cout << "Enter index to update: ";
		cin >> in;
		cout << "Enter element to add:";
		cin >> ele;
		maxsize++;
		for (int i = maxsize; i >= in; i--)
		{
			bucky[i + 1] = bucky[i];
		}
		bucky[in] = ele;
		display();
	}
	void checkarray()
	{
		int option;
		cout << "press 1 to enter an element in the start of the array " << endl;
		cout << "press 2 to enter the element at the end of array" << endl;
		cout << "press 3 to delete the element at the start of array" << endl;
		cout << "press 4 to delete the element at the end of array" << endl;
		cout << "press 5 to update the element of array" << endl;
		cout << "please enter your choice here :";
		cin >> option;



		if (option == 1) {
			addElementAtFirstIndex();
		}
		else if (option == 2) {
			addElementAtLastIndex();
		}
		else if (option == 3) {
			removeElementFromStart();
		}
		else if (option == 4) {
			removeElementFromEnd();
		}
		else if (option == 5) {
			updateElementsFromList();
		}

	}
	void display() {
		for (int i = 0; i < maxsize; i++) {
			cout << bucky[i];
		}
		cout << endl;
		cout << "bye bye" << endl;
	}
};
int main()
{
	List* obj;
	List2 obj2;
	obj = &obj2;
	obj2.createArr();
	obj2.checkarray();

	return 0;
}