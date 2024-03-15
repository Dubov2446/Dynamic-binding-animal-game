/*
File: animal.h

AUTHOR: Josue Lopez

Course/Class: CS302-002

Date: 19th Nomeber 2023

Program: CS302-002-program3

Description: Implementation file for animal class(including derived classes),
	     besides the basic funcitons, there are some funcitons that act as
	     wrapper function for the unique pointer that has been upcasted
	     and will at run time call the correct function depending on where
	     it's pointing to. Set Data and Display data act in a similar manner.

******************************* ANIMAL CLASS **********************************

Animal();
  - You don't need to change this unless you plan to modify the private section both in
    terms of members or their value when a new object of this type is created.

virtual ~Animal();
  - You don't need to change this unless you plan to modify the private section both in
    terms of members or their value when a new object of this type is destroyed.

virtual void set_data(const string& name, const string& breed);
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

virtual void display() const;
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

virtual void speak() const = 0;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

virtual void eat() const = 0;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

virtual void sleep() const = 0;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

virtual void is_vaccinated() const = 0; // for dog class
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

virtual void is_litter_box_full() const = 0; // for cat class
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

virtual void is_heater_on() const = 0; // for reptile class
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

string get_name() const;
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

string get_breed() const;
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

******************************* DOG CLASS **********************************

Dog();
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

~Dog();
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

void set_data(const string& name, const string& breed);
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

void display() const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

void speak() const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

void eat() const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

void sleep() const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

// unique to this class, but pure virtual in base
void is_vaccinated() const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

// need to implent these or else dog with become abstract
void is_litter_box_full() const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

void is_heater_on() const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

// for RTTI
void run() const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

******************************* CAT CLASS **********************************

Cat();
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

~Cat();
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

void display() const;
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

void speak() const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

void eat() const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

void sleep() const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

// unique to this class, but pure virtual in base
void is_litter_box_full() const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

// need to implent these or else dog with become abstract
void is_vaccinated() const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

void is_heater_on() const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

******************************* REPTILE CLASS **********************************

Reptile();
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

~Reptile();
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

void set_data(const string& name, const string& breed);
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

void display() const;
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

void speak() const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

void eat() const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

void sleep() const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

// unique to this class, but pure virtual in base
void is_heater_on() const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

void is_vaccinated() const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

void is_litter_box_full() const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

*/

#include "animal.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

// BASE CLASS
Animal::Animal() : name{""}, breed{""}, lvl_of_care{0}, temperament{0},
		   size{0}, friendliness{0} {}

Animal::~Animal()
{ // set members to their default value
	name = string();
	breed = string();
	lvl_of_care = int();
	temperament = int();
	size = int();
	friendliness = int();
}

void Animal::set_data(const string& name, const string& breed)
{
	this->name = name;
	this->breed = breed;

	cout << "Enter animal level of care out of ten (1 - 10): ";
	cin >> lvl_of_care;

	cout << "Enter animal temperament out of ten (1 - 10): ";
	cin >> temperament;

	cout << "Enter animal size out of ten (1 - 10): ";
	cin >> size;

	cout << "Enter animal friendliness out of ten (1 - 10): ";
	cin >> friendliness;

	cin.ignore(100, '\n');

	return;
}

void Animal::display() const
{
	cout << "Name: " << name << endl;
	cout << "Breed: " << breed << endl;
	cout << "Level of care: " << lvl_of_care << "/10" << endl;
	cout << "Temperament: " << temperament << "/10" << endl;
	cout << "Size: " << size << "/10" << endl;
	cout << "Friendliness: " << friendliness << "/10" << endl;

	return;
}

// DOG CLASS

Dog::Dog() : vaccinated{false} {}

Dog::~Dog()
{
	vaccinated = bool();
}

void Dog::set_data(const string& name, const string& breed)
{
	Animal::set_data(name, breed);
	char temp{char()};

	cout << "is the dog vaccinated (y or n): ";
	cin >> temp;

	if(temp == 'y' || temp == 'Y')
		vaccinated = true;
	else
		vaccinated = false;
	cin.ignore(100, '\n');
	return;
}

void Dog::display() const
{
	Animal::display();
	cout << "dog is ";
	if(vaccinated)
		cout << "vaccinated!";
	else
		cout << "not vaccinated...";
	cout << endl;
	return;
}

void Dog::speak() const
{
	cout << "Woof Woof!" << endl;
	return;
}

void Dog::eat() const
{
	cout << "Dog is eating!" << endl;
	return;
}

void Dog::sleep() const
{
	cout << "Dog is sleeping... (shhhhh)" << endl;
	return;
}


void Dog::is_vaccinated() const
{
	if(vaccinated)
		cout << "good, dog is up to date with vaccines!";
	else
		cout << "bad, dog is not up to date with vaccines...";
	cout << endl;
	return;
}

// empty since pure virtual in base, so dog doesn't become abstract
void Dog::is_litter_box_full() const
{
	return;
}

void Dog::is_heater_on() const
{
	return;
}

// FOR RTTI
void Dog::run() const
{
	cout << "Dog is running!" << endl;
	return;
}

// CAT CLASS

Cat::Cat() : has_litter_box{false} {}

Cat::~Cat()
{
	has_litter_box = bool();
}

void Cat::set_data(const string& name, const string& breed)
{
	Animal::set_data(name, breed);
	char temp{char()};

	cout << "does cat have a litter box (y or n): ";
	cin >> temp;

	if(temp == 'y' || temp == 'Y')
		has_litter_box = true;
	else
		has_litter_box = false;
	cin.ignore(100, '\n');
	return;
}

void Cat::display() const
{
	Animal::display();

	cout << "Cat ";

	has_litter_box ? cout << "has" : cout << "doesn't have";

	cout << " a litter box" << endl;

	return;
}

void Cat::speak() const
{
	cout << "Meow Meow!" << endl;
	return;
}

void Cat::eat() const
{
	cout << "Cat is eating (tuna)" << endl;
	return;
}

void Cat::sleep() const
{
	cout << "Cat is sleeping.... (shhhhhhhh)" << endl;
	return;
}

void Cat::is_litter_box_full() const
{
	if(has_litter_box)
		cout << "Litter box is full!";
	else
		cout << "Cat does not have a litter box";
	cout << endl;
	return;
}

// won't use them, just need to implemnt to cat doesn't become abstract
void Cat::is_vaccinated() const
{
	return;
}

void Cat::is_heater_on() const
{
	return;
}

// REPTILE CLASS

Reptile::Reptile() : has_heater{false} {}

Reptile::~Reptile()
{
	has_heater = bool();
}

void Reptile::set_data(const string& name, const string& breed)
{
	Animal::set_data(name, breed);

	char temp{char()};

	cout << "does reptile have a heater box (y or n): ";
	cin >> temp;

	if(temp == 'y' || temp == 'Y')
		has_heater = true;
	else
		has_heater = false;
	cin.ignore(100, '\n');
	return;
}

void Reptile::display() const
{
	Animal::display();

	if(has_heater)
		cout << "Reptile has a heater";
	else
		cout << "Reptile does not have a heater";
	return;
}

void Reptile::speak() const
{
	cout << "*hisssss sound*" << endl;
	return;
}

void Reptile::eat() const
{
	cout << "Reptile is eating" << endl;
	return;
}

void Reptile::sleep() const
{
	cout << "Reptile is sleeping....(shhhhh)" << endl;
	return;
}

void Reptile::is_heater_on() const
{
	if(has_heater)
		cout << "good, Heater is on!";
	else
		cout << "negative, Reptile doesn't have a heater";
	cout << endl;
	return;
}

// don't need these, implemented to avoid reptile turing abstract
void Reptile::is_vaccinated() const
{
	return;
}

void Reptile::is_litter_box_full() const
{
	return;
}
