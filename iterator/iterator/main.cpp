#include <iostream>
#include <list>
#include <map>

using namespace std;

int main(void)
{
	/*list<int> Numbers;


	Numbers.insert(Numbers.begin(), 50);
	Numbers.insert(Numbers.end(), 50);

	list<int>::iterator iter = Numbers.begin();

	Numbers.insert(iter, 25);

	++iter;

	Numbers.insert(iter, 150);


	for (list<int>::iterator iter = Numbers.begin(); iter != Numbers.end(); ++iter)
		cout << (*iter) << endl;*/

	map<string, int> List;

	List["AAA"] = 10;
	List["BBB"] = 20;
	List["CCC"] = 30;

	/*for (int i = 0; i < List.size(); ++i)
		cout << List[i] << endl;*/

	for (map<string, int>::iterator iter = List.begin(); iter != List.end(); ++iter)
		cout << iter->first << " : " << (*iter).second << endl;

	//======================================================
	//======================================================

	const int size = 16;

	int Array[size] = { 1,2,3,4,5,6,7 };

	/*for (int i = 0; i < size; ++i)
		cout << Array[i] << endl;*/

	int* iter = Array;

	cout << (*iter + 5) << endl;

	return 0;
}