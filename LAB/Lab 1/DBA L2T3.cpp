#include<iostream>
using namespace std;
class ksmall {



};
int main() {
	const int  size = 7;
	int bucky[size] = { 12, 3, 5, 7, 4, 19, 26 };
	int k;
	cout << "enter the value of k:";
	cin >> k;




	int b;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (bucky[i] > bucky[j])
			{
				b = bucky[i];
				bucky[i] = bucky[j];
				bucky[j] = b;
			}
		}
	}
	cout << endl << "the sorted values are" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << bucky[i];
	}
	cout << bucky[k] << endl;
	return 0;
}