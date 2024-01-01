#include<iostream>
using namespace std;

class Mylist
{

public:
	int* bucky;
	int maxSize = 5;
	int currentSize;



	virtual void removeElementFromSpecificPositionList() = 0;
	virtual void firstRepeatingElement() = 0;
	virtual void firstNonRepeatingElement() = 0;
	virtual void findPairs() = 0;
	virtual void countFrequencyOfEachElement() = 0;
	virtual void leftRotate() = 0;
	virtual void rightRotate() = 0;
};

class list2 : public Mylist
{
public:

	void removeElementFromSpecificPositionList()
	{
		bucky = new int[maxSize + 1];
		cout << "Enter elements of array: " << endl;
		for (int i = 0; i < maxSize; i++)
		{
			cin >> bucky[i];
		}
		int ele, nonele = 0;
		cout << "Enter the number to remove from the arrey: ";
		cin >> ele;

		for (int i = 0; i < maxSize; i++)
		{
			if (bucky[i] != ele) {
				bucky[nonele] = bucky[i];
				nonele++;
			}
		}
		for (int i = nonele; i < maxSize; i++) {
			bucky[i] = ele;
		}
		maxSize--;
		for (int i = 0; i < maxSize; i++)
		{
			cout << bucky[i] << " ";
		}
		cout << endl;
	}
	void firstRepeatingElement()
	{
		bucky = new int[maxSize];
		cout << "Enter elements of array: " << endl;
		for (int i = 0; i < maxSize; i++)
		{
			cin >> bucky[i];
		}
		for (int i = 0; i < maxSize; i++) {
			int j;
			for (int j = i + 1; j < maxSize; j++)
			{
				if (bucky[i] == bucky[j])
				{
					cout << "First repeating: ";
					cout << bucky[i];
					i = maxSize;
					break;
				}

			}

		}
	}
	void firstNonRepeatingElement()
	{
		bucky = new int[maxSize];
		cout << "Enter elements of array: " << endl;
		for (int i = 0; i < maxSize; i++)
		{
			cin >> bucky[i];
		}
		for (int i = 0; i < maxSize; i++)
		{
			int j;
			for (j = 0; j < maxSize; j++)
			{
				if (i != j && bucky[i] == bucky[j])
					break;
			}
			cout << endl;
			if (j == maxSize)
			{
				cout << bucky[i];
			}

		}


	}
	virtual void findPairs()
	{
		bucky = new int[maxSize];
		cout << "Enter elements of array: " << endl;

		for (int i = 0; i < maxSize; i++)
		{
			cin >> bucky[i];
		}

		int sum = 0, count = 0;
		cout << "Enter Sum: ";
		cin >> sum;
		for (int i = 0; i < maxSize; i++)
		{
			for (int j = i + 1; j < maxSize; j++)
			{
				if (bucky[i] + bucky[j] == sum)
				{
					cout << bucky[i] << "," << bucky[j] << " ";
					count++;
				}
			}
		}
	}
	void countFrequencyOfEachElement()
	{
		int* visited = new int[maxSize + 1];
		bucky = new int[maxSize];
		cout << "Enter elements of array: " << endl;

		for (int i = 0; i < maxSize; i++)
		{
			cin >> bucky[i];
		}

		for (int i = 0; i < maxSize; i++) {

			if (visited[i] == 1)
				continue;


			int count = 0;
			for (int j = 0; j < maxSize; j++) {
				if (bucky[i] == bucky[j]) {
					visited[j] = 1;
					count++;
				}
			}
			cout << bucky[i] << ": " << count << endl;

		}
	}

	void leftrotatebyone(int arr[], int size)
	{
		int temp = arr[0], i;
		for (i = 0; i < size - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[maxSize - 1] = temp;
	}

	void leftRotate()
	{
		bucky = new int[maxSize + 1];
		cout << "Enter elements of array: " << endl;
		for (int i = 0; i < maxSize; i++)
		{
			cin >> bucky[i];
		}
		int n;
		cout << "Enter How much u wanna rotate: ";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			leftrotatebyone(bucky, maxSize);
		}
		for (int i = 0; i < maxSize; i++)
		{
			cout << bucky[i] << " ";
		}
	}

	void rightRotateByOne(int Arr[], int size)
	{
		int temp = bucky[size - 1];
		for (int i = size - 2; i >= 0; i--) {
			bucky[i + 1] = bucky[i];
		}
		bucky[0] = temp;
	}
	void rightRotate()
	{
		bucky = new int[maxSize + 1];
		cout << "Enter elements of array: " << endl;
		for (int i = 0; i < maxSize; i++)
		{
			cin >> bucky[i];
		}
		int n;
		cout << "Enter How much u wanna rotate: ";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			rightRotateByOne(bucky, maxSize);
		}
	}
	void Option() {
		int choice;
		cout << " to remove Element From Specific Position List enter 1" << endl;
		cout << "To Check first Repeating Element enter 2" << endl;
		cout << "To check first Non Repeating Element enter 3" << endl;
		cout << "To find Pairs in the array enter 4" << endl;
		cout << "To check count Frequency Of Each Element enter 5" << endl;
		cout << "To rotate the array left enter 6 " << endl;
		cout << "To rotate the array right enter 7" << endl;
		cout << "please enter your choice:";
		cin >> choice;

		if (choice == 1) {
			removeElementFromSpecificPositionList();
		}
		else if (choice==2) {
			firstRepeatingElement();
		}
		else if (choice ==3 ) {
			firstNonRepeatingElement();
		}
		else if (choice == 4) {
			findPairs();
		}
		else if (choice == 5) {
			countFrequencyOfEachElement();
		}
		else if (choice == 6) {
			leftRotate();
		}
		else if (choice == 7) {
			rightRotate();
		}
	}
};
int main()
{

	Mylist* obj;
	list2 obj2;
	obj = &obj2;
	obj2.Option();
	return 0;
}