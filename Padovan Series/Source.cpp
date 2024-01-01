#include<iostream>
using namespace std;
int main()
{
    int padovanSeries(int iterator, int fe, int se, int te, int nextPadovanNumber);
    int iterator = 20;
    int fe , se ,te, nextPadovanNumber;
    fe = se = te = 1; // in Padovan series of numbers the first 3 elements are 1
    nextPadovanNumber = 0;

    cout << fe << endl;
    cout << se << endl;
    cout << te << endl;    
    padovanSeries(iterator, fe, se, te, nextPadovanNumber);
    return 0;
}

int padovanSeries(int iterator, int fe, int se, int te, int  nextPadovanNumber)
{
    int ch = 3;



    if (ch == iterator)
        return 0;

    if (ch < iterator)
    {
        nextPadovanNumber = fe + se;
        fe = se;
        se = te;
        te = nextPadovanNumber;
        cout << nextPadovanNumber << endl;
        ch++;
        padovanSeries(iterator - 1, fe, se, te, nextPadovanNumber);
    }

}