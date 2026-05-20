#pragma once
#pragma once
#include <iostream>
using namespace std;

class Student {
private:
	int id;
	string name;
	int examScore;
public:
	Student(int _id, string _name, int _examScore);
	void set_id(int _id);
	void set_name(string n);
	void set_examScore(int eg);
	int get_id();
	string get_name();
	int get_examScore();
	void print();

};
