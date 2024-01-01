#include <iostream>
using namespace std;
class List
{
public:
	int* bucky;
	int currentSize;
	int maximumSize;
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
		maximumSize = 5;
		currentSize = 5;
	}
	List2(int maxsize, int currsize)
	{
		this->maximumSize = maxsize;
		this->currentSize = currsize;
	}
	void createArr() {
		bucky = new int[maximumSize + 1];

		cout << "Enter elements of array and the size of array is 5: " << endl;
		for (int i = 0; i < maximumSize; i++)
		{
			cin >> bucky[i];
		}
	}
	void addElementAtFirstIndex()
	{

		cout << "Enter element to add: ";
		cin >> ele;
		maximumSize++;
		for (int i = maximumSize; i >= 0; i--)
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
		maximumSize++;
		bucky[maximumSize - 1] = ele;
		cout << endl;
		display();
	}
	void removeElementFromEnd()
	{
		maximumSize--;
		display();
	}
	void removeElementFromStart()
	{

		for (int i = 0; i < maximumSize; i++)
		{
			bucky[i] = bucky[i + 1];

		}
		maximumSize--;
		display();
	}
	void updateElementsFromList()
	{
		int in;
		cout << "Enter index to update: ";
		cin >> in;
		cout << "Enter element to add:";
		cin >> ele;
		maximumSize++;
		for (int i = maximumSize; i >= in; i--)
		{
			bucky[i + 1] = bucky[i];
		}
		bucky[in] = ele;
		display();
	}
	void display() {
		for (int i = 0; i < maximumSize; i++) {
			cout << bucky[i];
		}
		cout << endl;
		cout << "bye bye" << endl;
	}
	bool checkEmpty() {
		if (bucky == NULL)
			{
				cout << "The array is empty" << endl;
				return true;
			}
			else
			{
				cout << "The array is not empty" << endl;
				return false;
			}

	}
	bool checkFull() {
		if (bucky != NULL)
		{
			cout << "The array is full" << endl;
			return true;
		}
		else
		{
			cout << "The array is not full" << endl;
			return false;
		}

	}
	void checkSize() {
		cout << maximumSize;
	}
	void Insertion() {
		int ele;
		int in;
		cout << "Enter index to update: ";
		cin >> in;
		cout << "Enter element to add:";
		cin >> ele;
		maximumSize++;
		for (int i = maximumSize; i >= in; i--)
		{
			bucky[i + 1] = bucky[i];
		}
		bucky[in] = ele;
		display();
		
	}
	void lastElement() {
		cout << bucky[maximumSize - 1];

	}
	void searchElement() {
		cout << "enter number u want to find ";
		cin >> ele;
		bool flag = true;
		for (int i = 0; i < maximumSize; i++)
		{
			if (ele == bucky[i])
			{
				flag == true;

			}
			else
			{
				flag == false;
			}
		}
		if (flag)
		{
			cout << "nunber exist in this array " << endl;
		}
		else
		{
			cout << "nunber dosen't exist in this array " << endl;
		}
	}
	
	void checkarray()
	{
		int option;
		cout << "press 1 to enter an element in the start of the array " << endl;
		cout << "press 2 to enter the element at the end of array" << endl;
		cout << "press 3 to delete the element at the start of array" << endl;
		cout << "press 4 to delete the element at the end of array" << endl;
		cout << "press 5 to update the element of array" << endl;
		cout << "press 6 for empty " << endl;
		cout << "press 7 for full " << endl;
		cout << "press 8 for size " << endl;
		cout << "press 9 for insertAt(int index, T value):" << endl;
		cout << "press 10 for  Type last " << endl;
		cout << "press 11 for  search(Type) " << endl;
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
		else if (option == 6)
		{
			checkEmpty();
		}
		else if (option == 7)
		{
			checkFull();
		}
		else if (option == 8)
		{
			checkSize();
		}
		else if (option == 9)
		{
			Insertion();
		}
		else if (option == 10)
		{
			
			lastElement();
		}
		else if (option == 11)
		{
			searchElement();

		}

	}
};
int main()
{
	List* obj;
	List2 obj2;
	obj2.createArr();
	obj2.checkarray();
	return 0;
}