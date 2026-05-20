#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Staff {
private:
	int personnelNo;
	string name;
	string staffType;
public:
	Staff(int pNo, string n, string s) : personnelNo(pNo), name(n), staffType(s) {}
	int getPNo() {return personnelNo;}
	string getName() {return name;}
	string getStaffType() {return staffType;}
	void print() const {
		cout << "Personnel Number: " << personnelNo << endl;
		cout << "Full Name: " << name << endl;
		cout << "Staff: " << staffType << endl;
		cout << endl;
	}
};

class Error {
private:
	string err;
public:
	Error(string e) : err(e) {}
	string getErr() {
		return err;
	}
};

void addMember(vector<Staff>& members) {
	int pNo;
	string name, role;
	cout << "-------Enter Staff Member Data-------\n\n";
	cout << "Personnel Number: "; cin >> pNo;
	if (!pNo) {
		cin.clear();
		cin.ignore(1000, '\n');
		throw Error("Invalid Personnel Number!!! ");
	}
	cin.ignore();
	cout << "Full Name: "; getline(cin, name);
	cout << "Staff Role: "; getline(cin, role);
	members.push_back(Staff(pNo, name, role));	
	//members.emplace_back(pNo, name, role);	// if we are using vector with objects, we can use emplace_back method. It is more efficient for memory. But in this program, it's not important.
	cout << "\nNew Staff Member added !!! ";
}

void listMember(const vector<Staff>& members, bool& _runStatus) {
	string s;
	int count = 0;
	for (const Staff& m : members) {
		m.print();
		count++;
	}
	if (count == 0)
		cout << "No member registered..." << endl;
	cout << count << " member found...";
	cout << "\n\nPress M to return start...";
	cout << "\n\nPress Q to return quit...";
	cin >> s;
	if (s == "M" || s == "m")
		return;
	if (s == "Q" || s == "q")
		_runStatus = false;
}

void searchMember(const vector<Staff>& members, bool& _runStatus) {
	int num;
	string s;
	bool found = false;
	cout << "Enter personnel number to search--> ";
	cin >> num;
	if (!num) {
		cin.clear();
		cin.ignore(1000, '\n');
		throw Error("Invalid Personnel Number!!! ");
	}
	cout << endl;
	for (Staff m : members) {	
		if (num == m.getPNo()) {
			cout << "Staff Member Found !!!\n\n";
			m.print();
			cout << "\n\nPress M to return start...";
			cout << "\n\nPress Q to return quit...";
			cin >> s;
			if (s == "M" || s == "m")
				return;
			if (s == "Q" || s == "q")
				_runStatus = false;
			found = true;
		}
	}
	if (!found) 
		cout << "No Staff Member Found :(";
	
}

void deleteMember(vector<Staff>& members) {
	for (const Staff& m : members) m.print();
	int num;
	cout << "Enter personnel number to delete--> ";
	cin >> num;
	if (!num) {
		cin.clear();
		cin.ignore(1000, '\n');
		throw Error("Invalid Personnel Number!!! ");
	}
	cout << endl;
	for (auto itr = members.begin(); itr != members.end(); itr++) {
		if (itr->getPNo() == num) {
			members.erase(itr);
			cout << "Staff Member Deleted !!!\n\n";
			return;
		}
	}
	cout << "Staff Member Not Found :(";
}

int main() {
	vector<Staff> member;
	int choice = 0;
	bool runStatus = true;
	
		
	do {
		try {
			cout << "\n\n-------Choose an operation-------\n\n";
			cout << "1. Add a staff member" << endl;
			cout << "2. List the members" << endl;
			cout << "3. Search a staff member" << endl;
			cout << "4. Delete a member" << endl;
			cout << "5. Quit" << endl;
			cout << "--> ";
			cin >> choice;
			if (!choice) {
				cin.clear();
				cin.ignore(1000, '\n');
				throw Error("Invalid Operation Number!!! ");
			}

			cout << endl;

			switch (choice)
			{
			case 1:addMember(member); break;
			case 2:listMember(member, runStatus); break;
			case 3:searchMember(member, runStatus); break;
			case 4:deleteMember(member); break;
			case 5:runStatus = false; break;
			default:cout << "Invalid Operation! Please choose 1 to 5! "; break;
			}
		} 
		catch (Error e) {
			cout << "Operation failed!!! " << e.getErr();
		}
	} while (runStatus);


}