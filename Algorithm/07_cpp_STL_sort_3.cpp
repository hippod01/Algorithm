//데이터를 묶어서 정렬하는 법

#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Student {

public:
	string name;
	int score;

	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}
	// 정렬 기준은 '점수가 작은 순서' 

	bool operator <(Student &student) {
		return this->score < student.score;
	}
};

//연산자 오버로딩 공부
bool compare(Student a, Student b){
	return a.score < b.score;
}

int main(void) {
	Student students[] = {
		Student("나동빈", 90),
		Student("이상욱", 93),
		Student("박한울", 97),
		Student("강종구", 87),
		Student("이태일", 92)
	};
	sort(students, students + 5, compare);
	for(int i = 0; i < 5; i++) {
		cout << students[i].name << ' ';
	}
}