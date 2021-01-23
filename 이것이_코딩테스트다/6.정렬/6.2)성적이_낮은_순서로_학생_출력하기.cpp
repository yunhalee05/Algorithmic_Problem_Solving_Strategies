#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}
	//낮은점수부터 오름차순으로 설정(연산자 오버로딩)
	bool operator < (Student& other) {
		return this->score < other.score;
	}
};

int n;
vector <Student> v; 

int main() {

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string name;
		int score;
		cin >> name >> score;
		v.push_back(Student(name, score));

	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		cout << v[i].name << " ";
	}


	return 0;

}