#include <iostream>
using namespace std;
class List
{
public:
	int* bucky;
	int currsize;
	int maxsize;
	int ele;


	virtual void removeElementFromSpecificPosition() = 0;
	virtual void firstRepeatingElement() = 0;
	virtual void firstNonRepeatingElement() = 0;
	virtual void findPairs() = 0;

};
class List2 : public List
{
public:
	List2()
	{
		maxsize = 5;
		currsize = 5;
	}
	List2(int maxsize, int currsize)
	{
		this->maxsize = maxsize;
		this->currsize = currsize;
	}
	void ArrayElements()
	{
		bucky = new int[maxsize];
		cout << "Enter elements of array: " << endl;
		for (int i = 0; i < maxsize; i++)
		{
			cin >> bucky[i];
		}
	}

	void removeElementFromSpecificPosition()
	{
		int pos;
		cout << "enter the position which u want to remove";
		cin >> pos;
		for (int i = pos - 1; i < maxsize; i++) {
			bucky[i] = bucky[i + 1];

		}
		maxsize--;
		Display();
	}
	void firstRepeatingElement()
	{
		int repn = 0;
		bool flag = true;
		for (int i = 0; i < maxsize; i++)
		{
			repn = bucky[i];
			for (int j = i + 1; j < maxsize; j++)
			{
				if (repn == bucky[j])
				{
					flag = true;
					break;
				}
				else
				{
					flag = false;
				}

			}
			if (flag)
			{
				cout << "the first Repeating Element are : " << repn << endl;
				break;
			}
		}
	}
	void firstNonRepeatingElement()
	{
		int nonrep = 0;
		bool flag = true;
		for (int i = 0; i < maxsize; i++)
		{
			nonrep = bucky[i];
			for (int j = i + 1; j < maxsize; j++)
			{
				if (nonrep != bucky[j])
				{
					flag = true;
				}
				else
				{
					flag = false;
					break;
				}

			}
			if (flag)
			{
				cout << "the first NonRepeating Element are : " << nonrep << endl;
				break;
			}
		}
	}
	void findPairs()
	{
		int p = 0;
		for (int i = 0; i < maxsize; i++)
		{
			p = bucky[i];
			for (int j = i + 1; j < maxsize; j++)
			{
				if (p + bucky[j] == 7)
				{
					cout << "( " << p << "," << bucky[j] << " )" << endl;
				}

			}
		}
	}
	void Display() {
		cout << "After alteration these are the elements" << endl;
		for (int i = 0; i < maxsize; i++) {
			cout << bucky[i] << endl;
		}
	}

	void checkarray()
	{
		int choice;
		cout << "press 1 for removing an element from a selected Position in array" << endl;
		cout << "press 2 to check first Repeating Element" << endl;
		cout << "press 3 to check first non Repeating Element" << endl;
		cout << "enter your choice";
		cin >> choice;
		if (choice == 1) {
			removeElementFromSpecificPosition();
		}
		else if (choice == 2) {
			void firstRepeatingElement();
		}
		else if (choice == 3) {
			firstNonRepeatingElement();
		}
		else if (choice == 4) {
			findPairs();
		}

	}
};
int main()
{
	List* obj;
	List2 obj2;
	obj = &obj2;
	obj2.ArrayElements();
	obj2.checkarray();
	return 0;
}