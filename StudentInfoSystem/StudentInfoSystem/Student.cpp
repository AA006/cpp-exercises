#include <iostream>
#include "Student.h"

Student::Student(int _id, string _name, int _examScore) {
	id = _id;
	name = _name;
	examScore = _examScore;
}
void Student::set_id(int i) { id = i; }
int Student::get_id() { return id; }
void Student::set_name(string n) { name = n; }
string Student::get_name() { return name; }
void Student::set_examScore(int eg) { examScore = eg; }
int Student::get_examScore() { return examScore; }

void Student::print() {
	cout << "ID: " << id << " Name: " << name << " Score: " << examScore << endl;
}
