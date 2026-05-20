#include <iostream>
#include <string>
#include "Student.h"
#include <list>

using namespace std;

void showMenu() {
	cout << "\n";
	cout << "* * * * * * * * * * *\n";
	cout << "*       MENU        *\n";
	cout << "* * * * * * * * * * *\n\n\n";
	cout << "1.Add new student\n";
	cout << "2.List students\n";
	cout << "3.Delete Student\n";
	cout << "4.Search student\n";
	cout << "5. Quit\n\n";
}

void addStudent(list<Student>& lst) {
	int id, score;
	string name;
	cout << "Student ID: ";
	cin >> id;
	if (!id) {
		cin.clear();
		cin.ignore(1000, '\n');
	}
	cin.ignore();
	cout << "Name: ";
	getline(cin, name);
	cout << "Score: "; cin >> score;
	Student std(id, name, score);
	lst.push_back(std);

}

void listStudent(list<Student>& lst) {
	list<Student>::iterator it;
	cout << endl;
	for (it = lst.begin(); it != lst.end(); it++) {
		it->print();
		cout << endl;
	}
}

void deleteStudent(list<Student>& lst) {
	int id;
	bool found = false;
	cout << "\nEnter the ID of student you want to delete->";
	cin >> id;
	list<Student>::iterator it;
	for (it = lst.begin(); it != lst.end(); it++) {
		if (it->get_id() == id) {
			lst.erase(it);
			cout << "\nStudent deleted!\n";
			return;
		}
	}
	if (!found)
		cout << "Student not Found! ";
}

void searchStudent(list<Student>& lst) {
	int id;
	bool found = false;
	cout << "Enter the ID you would like to search->";
	cin >> id;
	list<Student>::iterator it;
	for (it = lst.begin(); it != lst.end(); it++) {
		if (it->get_id() == id) {
			it->print();
			cout << endl;
			found = true;
		}
	}
	if (!found)
		cout << "Student not found! ";
}

int main() {
	list<Student> lStudent;
	int choice = 0;
	bool runStatus = true;
	do {
		showMenu();
		cout << "Enter your choice--> ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			addStudent(lStudent);
			break;
		case 2:
			listStudent(lStudent);
			break;
		case 3:
			deleteStudent(lStudent);
			break;
		case 4:
			searchStudent(lStudent);
			break;
		case 5:
			runStatus = false; break;
		default:
			cout << "Wrong choice, try again!";
			break;
		}
	} while (runStatus);
}