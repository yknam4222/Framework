#include <iostream>
#include <map>
#include <list>

using namespace std;

typedef struct Score
{
	string name;
	int Kor;
	int Eng;
	int Math;

	Score() : Kor(0), Eng(0), Math(0) {}

	Score( int _Kor, int _Eng, int _Math) : Kor(_Kor), Eng(_Eng), Math(_Math) {}
};

int main(void)
{
	/*map<string, Score> List;

	string key = "ȫ";
	Score score = Score(10, 20, 30);

	List.insert(make_pair(key, score));
	
	score = Score(100, 200, 300);
	score.name = "�浿";

	List[key] = score;

	cout << key + List[key].name<< endl;
	cout << List[key].Kor << endl;
	cout << List[key].Eng << endl;
	cout << List[key].Math << endl;

	multimap<string, Score> multiList;

	multiList.insert(make_pair(key, score));
	multiList.insert(make_pair(key, score));

	for (multimap<string, Score>::iterator iter = multiList.begin(); iter != multiList.end(); ++iter)
	{
		cout << "[" << iter->first << "]" << endl;
		cout << "����" << iter->first << " : " << iter->second.Kor << endl;
		cout << "����" << iter->first << " : " << iter->second.Eng << endl;
		cout << "����" << iter->first << " : " << iter->second.Math << endl << endl;
	}*/

	map<string, list<Score>> StudentList;

	string key = "ȫ";
	Score score = Score(10, 20, 30);
	score.name = "�浿";

	StudentList[key].push_back(score);


	return 0;
}

