#include<iostream>
#include<string>
#include<fstream>
using namespace std;
template<typename T>
class Example{
	
public:
		me()
		{ 
		}
		
		T add (T x,T y){
			T result=x+y;
			cout<<result<<endl;
			}
	
	
};
template<T>

class e2: public Example
{
		
	
	
};

int main(){
	Example <float>obj;
	obj.add(3.9f,5.6f);
	return 0;
}
