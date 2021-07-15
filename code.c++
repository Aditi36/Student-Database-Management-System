#include <iostream>
#include <list>
using namespace std;

class Student
{
	public:
		int roll;
		string name, address;
};

list<Student> l;

void create()
{
	Student obj;
	cout << "Enter details: \n";
	cout << "Enter student's name: ";
	cin >> obj.name;
	cout << "Enter student's roll no: ";
	cin >> obj.roll;
	cout << "Enter student's address: ";
	cin >> obj.address;
	cout << endl;

	l.push_back(obj);

	cout << "New student added successfully!!\n\n";
}

void find()
{
	if(l.empty())
	{
		cout << "No students in database!!\n\n";
		return;
	}
	int r, flag = 0;
	cout << "Enter roll number of student: ";
	cin >> r;
	list<Student>::iterator itr;
	for(itr = l.begin(); itr != l.end(); ++itr)
	{
		if(itr->roll == r)
		{
			cout << "\nName: " << itr->name << "\t";
			cout << "Roll: " << itr->roll << "\t";
			cout << "Address: " << itr->address << endl << endl;
			flag = 1;
			break;
		}
	}
	if(!flag)
	{
		cout << "Student not found!!\n";
		find();
	}
}

void read()
{
	if(!l.empty())
	{
		cout << "\nAll Entries: " << l.size() << endl;
		list<Student>::iterator itr;
		for(itr = l.begin(); itr != l.end(); ++itr)
		{
			cout << "\nName: " << itr->name << "\t";
			cout << "Roll: " << itr->roll << "\t";
			cout << "Address: " << itr->address;
		}
		cout << endl << endl;
	}
	else
		cout << "No students in database!!\n\n";
}

void update()
{
	if(l.empty())
	{
		cout << "No students in database!!\n\n";
		return;
	}
	list<Student>::iterator itr;
	int r, flag = 0;
	cout << "Enter roll number of student: ";
	cin >> r;
	for(itr = l.begin(); itr != l.end(); ++itr)
	{
		if(itr->roll == r)
		{
			cout << "\nEnter Name: ";
			cin >> itr->name;
			cout << "\nEnter roll: ";
			cin >> itr->roll;
			cout << "\nEnter address: ";
			cin >> itr->address;
			flag = 1;
			break;
		}
	}
	if(flag)
		cout << "Updated successfully!!\n\n";
	else 
	{
		cout << "Student not found!!\n";
		update();
	}
}

void remove()
{
	if(l.empty())
	{
		cout << "No students in database!!\n\n";
		return;
	}
	list<Student>::iterator itr;
	int r, flag = 0;
	cout << "Enter roll number of student: ";
	cin >> r;
	for(itr = l.begin(); itr != l.end(); ++itr)
	{
		if(itr->roll == r)
		{
			l.erase(itr);
			flag = 1;
			break;
		}
	}
	if(flag)
		cout << "Deleted successfully!!\n\n";
	else 
	{
		cout << "Student not found!!\n";
		remove();
	}
}

int main()
{
	int choice;
	while(1)
	{
		cout << "STUDENT DATABASE \n\n";
		cout << "Menu:\n";
		cout << "1. Add new student\n";
		cout << "2. Find a student\n";
		cout << "3. Show all students\n";
		cout << "4. Update student details\n";
		cout << "5. Delete a student\n";
		cout << "6. Exit\n\n";
		cout << "Enter your choice: ";
		cin >> choice;
		cout << endl;

		switch(choice)
		{
			case 1: create(); break;
			case 2: find(); break;
			case 3: read(); break;
			case 4: update(); break;
			case 5: remove(); break;
			case 6: cout << "Thank you...\n"; exit(0);
			default: cout << "Invalid choice. Try again.\n\n";
		}
	}
	return 0;
}
