#include <iostream>
#include <string>
#include <map>
using namespace std;

class Book {
private:
	int shelf_no;
	string author;
	string header;
public:
	Book(){}
	Book(int sNo, string a, string h) : shelf_no(sNo), author(a), header(h){}
	int get_sNo() { return shelf_no; }
	string get_author() { return author; }
	string get_header() { return header; }
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

void addBook(map<int, Book>& books) {
	int bID, sNum;
	string aut, head;
	cout << "-------Enter New Book Data-------\n\n";
	cout << "Enter your book's ID number --> "; cin >> bID;
	cout << "Enter your book's shelf number --> "; cin >> sNum;
	if (!sNum or !bID) {
		cin.clear();
		cin.ignore(1000, '\n');
		throw Error("Invalid Shelf Number!!! ");
	}
	cin.ignore();
	cout << "Author: "; getline(cin, aut);
	cout << "Header: "; getline(cin, head);
	books[bID] = Book(sNum, aut, head);

	cout << "\nNew Book added !!! ";


}

void listBook(const map<int, Book>& books, bool& _runStatus) {
	string s;
	int count = 0;

	if (books.empty())
	{
		cout << "No Books Found!!!";
		return;
	}
	cout << "***** List of books *****\n\n";
	for (auto it = books.begin(); it != books.end(); it++) {
		int id = it->first;
		Book b = it->second;
		cout << "ID: " << id << endl;
		cout << "Author: " << b.get_author() << endl;
		cout << "Header: " << b.get_header() << endl;
		cout << "Shelf: " << b.get_sNo() << endl;
		cout << endl;
		count++;
	}
	//

	if (count == 0)
		cout << "No book registered..." << endl;
	cout << count << " member found...";
	cout << "\n\nPress M to return start...";
	cout << "\n\nPress Q to return quit...";
	cin >> s;
	if (s == "M" || s == "m")
		return;
	if (s == "Q" || s == "q")
		_runStatus = false;
}

void searchBook(const map<int, Book>& books, bool& _runstatus) {
	int num;
	cout << "Enter the ID number of book that you want to search--> ";
	cin >> num;
	if (!num) {
		cin.clear();
		cin.ignore(1000, '\n');
		throw Error("Invalid ID Number!!! ");
	}
	cout << endl;
	
	map<int, Book> ::const_iterator it = books.find(num);
	if (it != books.end()) {
		Book b = it->second;  // Why it cannot be const and we could not take referance???
		cout << "Author: " << b.get_author() << endl;
		cout << "Book Name: " << b.get_header() << endl;
		cout << "Shelf No: " << b.get_sNo() << endl;
	}
}

void deleteBook(map<int, Book>& books) {
	int num;
	cout << "Enter the ID number of book that you want to delete--> ";
	cin >> num;
	if (!num) {
		cin.clear();
		cin.ignore(1000, '\n');
		throw Error("Invalid ID Number!!! ");
	}
	cout << endl;
	books.erase(num);
	cout << "Book Deleted !!!";
}

int main() {
	map<int, Book> lib;
	int choice = 0;
	bool runStatus = true;


	do {
		try {
			cout << "\n\n-------Choose an operation-------\n\n";
			cout << "1. Add a new book" << endl;
			cout << "2. List the books" << endl;
			cout << "3. Search a book by shelf number" << endl;
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
			case 1:addBook(lib); break;
			case 2:listBook(lib, runStatus); break;
			case 3:searchBook(lib, runStatus); break;
			case 4:deleteBook(lib); break;
			case 5:runStatus = false; break;
			default:cout << "Invalid Operation! Please choose 1 to 5! "; break;
			}
		}
		catch (Error e) {
			cout << "Operation failed!!! " << e.getErr();
		}
	} while (runStatus);

}