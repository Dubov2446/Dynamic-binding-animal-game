/*

File: main.cpp

AUTHOR: Josue Lopez

Course/Class: CS302-002

Date: 19th Nomeber 2023

Program: CS302-002-program3

Description: main/driver file for program, there is only one function
	     that act as wrapper function for the menu for options to pick from.
	     User can pick whatever option they want and continue to do so
	     until they decide they want to quit the program or enter in a wrong
	     option, failure to enter a valid option will result in the
	     termination of the program, user will be notified.
void menu();
  - You would call this whenever you want to display the menu for the user. You do not
    need to do anything to this function unless you decide to change/modifiy the options.
*/

#include "animal.h"
#include "bst.h"
#include <iostream> // output/input
#include <string> // string

using std::string;
using std::cout;
using std::endl;
using std::cin;

void menu();

int main()
{
	// TESTING DOG CLASS (DYNAMIC BINDING)

	/*
	Animal* ptr = new Dog;

	cout << "Testing Dog with upcasting" << endl << endl;
	ptr->set_data("Kevin", "Pitbull");
	cout << endl;
	ptr->display();
	cout << endl;
	ptr->speak();
	ptr->eat();
	ptr->sleep();
	ptr->is_vaccinated();

	// testing out the two other pure virtual function in base
	// that I had to implement so that Dog wouldn't become abstract too
	ptr->is_litter_box_full();
	ptr->is_heater_on();

	Dog* dog_ptr = dynamic_cast<Dog*>(ptr);
	if(dog_ptr)
		dog_ptr->run();

	delete ptr;
	*/


	/*
	// TESTING CAT CLASS (DYNAMIC BINDING)
	Animal* ptr = new Cat;

	cout << "Testing Cat with upcasting" << endl << endl;
	ptr->set_data("Wolfgang", "German Shepard");
	cout << endl;
	ptr->display();
	cout << endl;
	ptr->speak();
	ptr->eat();
	ptr->sleep();
	ptr->is_litter_box_full();

	// testing out the two other pure virtual function in base
	// that I had to implement so that Cat wouldn't become abstract too
	ptr->is_vaccinated();
	ptr->is_heater_on();

	delete ptr;
	*/

	/*
	// TESTING Reptile CLASS (DYNAMIC BINDING)
	Animal* ptr = new Reptile;

	cout << "Testing Reptile with upcasting" << endl << endl;
	ptr->set_data("Jerry", "Gecko");
	cout << endl;
	ptr->display();
	cout << endl;
	ptr->speak();
	ptr->eat();
	ptr->sleep();
	ptr->is_heater_on();

	// testing out the two other pure virtual function in base
	// that I had to implement so that Cat wouldn't become abstract too
	ptr->is_vaccinated();
	ptr->is_litter_box_full();

	delete ptr;
	*/

	Bst tree;

	int option{int()};
	string name{string()};
	string breed{string()};

	try
	{
		do
		{
			menu();
			cout << "Enter option: ";
			cin >> option;
			cin.ignore(100, '\n');

			if(option < 0 || option > 10)
				throw option;


			switch(option)
			{
				case 0:
					break;
				case 1:
					cout << "what type of pet is it? " << endl;
					cout << "1 - Dog" << endl;
					cout << "2 - Cat" << endl;
					cout << "3 - Reptile" << endl;
					cout << "Enter option: ";
					cin >> option;
					cin.ignore(100, '\n');

					cout << "Enter pet name: ";
					getline(cin, name);
					cout << "Enter pet breed: ";
					getline(cin, breed);

					tree.insert(option, name, breed);
					break;
				case 2:
					cout << endl << "Remember, case sensitive..." << endl;
					cout << "Enter pet name to remove: ";
					getline(cin, name);
					cout << "Enter pet breed to remove: ";
					getline(cin, breed);

					tree.remove_item(name, breed);

					break;
				case 3:
					tree.display();
					break;
				case 4:
					tree.remove_all();
					break;
				case 5:
					cout << "Enter pet name: ";
					getline(cin, name);
					cout << "Enter pet breed: ";
					getline(cin, breed);

					tree.speak(name, breed);
					break;
				case 6:
					cout << "Enter pet name: ";
					getline(cin, name);
					cout << "Enter pet breed: ";
					getline(cin, breed);

					tree.eat(name, breed);
					break;
				case 7:
					cout << "Enter pet name: ";
					getline(cin, name);
					cout << "Enter pet breed: ";
					getline(cin, breed);

					tree.sleep(name, breed);
					break;
				case 8:
					cout << "Enter pet name: ";
					getline(cin, name);
					cout << "Enter pet breed: ";
					getline(cin, breed);

					tree.is_vaccinated(name, breed);
					break;
				case 9:
					cout << "Enter pet name: ";
					getline(cin, name);
					cout << "Enter pet breed: ";
					getline(cin, breed);

					tree.is_litter_box_full(name, breed);
					break;
				case 10:
					cout << "Enter pet name: ";
					getline(cin, name);
					cout << "Enter pet breed: ";
					getline(cin, breed);

					tree.is_heater_on(name, breed);
					break;

				default:
					break;
			}
			cout << endl;
		}
		while(option != 0);
	}

	catch(...)
	{
		cout << endl << endl;
		cout << "INVALID ENTRY. PROGRAM IS ENDING, PLEASE READ";
		cout << " THE INSTRUCTIONS/OPTIONS BETTER NEXT TIME ??????????? HELLO??????";
		cout << endl << endl;
	}
	return 0;
}

void menu()
{
	cout << endl;
	cout << "PLEASE PICK ONE OF THE OPTIONS...." << endl;
	cout << "1 - insert" << endl;
	cout << "2 - remove item" << endl;
	cout << "3 - display" << endl;
	cout << "4 - remove all" << endl;
	cout << "5 - animal speak" << endl;
	cout << "6 - animal eat" << endl;
	cout << "7 - animal sleep" << endl;
	cout << "8 - check vaccine status" << endl;
	cout << "9 - check litter box status" << endl;
	cout << "10 - check heater status" << endl;
	cout << "0 - quit program..." << endl << endl << endl;

	cout << "SIDE NOTE: THIS PROGRAM IS CASE SENSITIVE";
	cout << " and you cannot enter a duplicate animal with" << endl;
	cout << "the same name and breed. Remember, 'Poodle' is NOT the same as 'poodle'";
	cout << endl << endl;
	return;
}

