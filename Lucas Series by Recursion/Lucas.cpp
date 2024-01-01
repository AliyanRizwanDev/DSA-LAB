#include <iostream>
using namespace std;
int main()
{
	int lucasSeries(int n, int temp, int temp1);  //identifier for the function
	int fE, sE;
	fE = sE = 0;
	cout << "entere the first 2 elements of the lucas series";
	cin >> fE;  //first element
	cin >> sE;  // second element
	int n = 11;
	lucasSeries(n, fE, sE); 	//will pass the values to the function named Lucas series
	return 0;
}

int lucasSeries(int n, int temp, int temp1)
{
	int newLucasNumber, ch;

	ch = 0;
	if (ch > n)
		return 0;

	if (ch < n)
	{

		newLucasNumber = temp + temp1;
		temp = temp1;
		temp1 = newLucasNumber;
		ch = ch + 2;
		cout << newLucasNumber << endl;
		lucasSeries(n - 2, temp, temp1);
	}

}