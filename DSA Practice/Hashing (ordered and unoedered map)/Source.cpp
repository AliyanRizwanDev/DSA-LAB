#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
	unordered_map<int, char> umap = { {1,'a'},{2,'b'} };
	cout << umap[1] << endl;
	cout << umap[2] << endl;

	//Update
	umap[1] = 'c';

	//iterate
	for (auto& elm : umap)
	{
		cout << elm.first << " " << elm.second << " ";
	}
	cout << endl;

	//Find/Search
	auto result = umap.find(2);
	if (result != umap.end())
	{
		cout << "Found " << result->first << " " << result->second << endl;
	}
	else
	{
		cout << "Not Found" << endl;
	}

	return 0;
}