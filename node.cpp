/*
File: node.cpp

AUTHOR: Josue Lopez

Course/Class: CS302-002

Date: 19th Nomeber 2023

Program: CS302-002-program3

Description: Cpp file for node class, besides the basic funcitons, there are
	     some funcitons that act as wrapper function for the unique pointer
	     that has been upcasted and will at run time call the correct function
	     depending on where it's pointing to. Set Data and Display data act
	     in a similar manner.

Node();
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

~Node();
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

void set_data(const int& type_of_pet, const string& name, const string& breed);
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

void display_data() const;
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

void set_left(Node* ptr);
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

void set_right(Node* ptr);
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

Node*& get_left();
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

Node*& get_right();
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

void set_name(const string& name);
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

void set_breed(const string& breed);
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

string get_name() const;
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

string get_breed() const;
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

unique_ptr<Animal>& get_unique();
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

// dynamic binding functions
void animal_speak() const;
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

void animal_eat() const;
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

void animal_sleep() const;
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

void is_vaccinated() const;
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

void is_litter_box_full() const;
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

void is_heater_on() const;
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.
*/

#include "node.h"
#include <string>
#include <iostream> // output/input
#include <typeinfo> // need typeid for RTTI

using std::string;
using std::cout;
using std::endl;

Node::Node() : name{""}, breed{""}, left{nullptr}, right{nullptr}, my_animal{nullptr} {}

Node::~Node()
{
	name = string();
	breed = string();
	left = nullptr;
	right = nullptr;
	if(my_animal)
		my_animal.reset();
	my_animal = nullptr;
}

void Node::set_data(const int& type_of_pet, const string& name, const string& breed)
{
	if(type_of_pet == 1) // dog
	{
		my_animal.reset(new Dog());
		my_animal->set_data(name, breed);
	}
	else if(type_of_pet == 2) // cat
	{
		my_animal.reset(new Cat());
		my_animal->set_data(name, breed);
	}
	else // reptile
	{
		my_animal.reset(new Reptile());
		my_animal->set_data(name, breed);
	}

	return;
}

void Node::display_data() const
{
	my_animal->display();
	return;
}

void Node::set_left(Node* ptr)
{
	left = ptr;
	return;
}

void Node::set_right(Node* ptr)
{
	right = ptr;
	return;
}

Node*& Node::get_left()
{
	return left;
}

Node*& Node::get_right()
{
	return right;
}

void Node::set_name(const string& name)
{
	this->name = name;
	return;
}

void Node::set_breed(const string& breed)
{
	this->breed = breed;
	return;
}

string Node::get_name() const
{
	return name;
}

string Node::get_breed() const
{
	return breed;
}

unique_ptr<Animal>& Node::get_unique()
{
	return my_animal;
}

void Node::animal_speak() const
{
	cout << endl;
	my_animal->speak();
	cout << endl;
	return;
}

void Node::animal_eat() const
{
	cout << endl;
	my_animal->eat();
	cout << endl;
	return;
}

void Node::animal_sleep() const
{
	cout << endl;
	my_animal->sleep();
	cout << endl;
	return;
}

void Node::is_vaccinated() const
{
	if(typeid(*my_animal) == typeid(Dog))
	{
		cout << endl << "Animal vaccine status: ";
		my_animal->is_vaccinated();
	}
	else
	{
		cout << endl << "Sorry vaccines only apply to Dogs...";
		if(typeid(*my_animal) == typeid(Cat))
			cout << " not cats...";
		else // typeid(*my_animal) == type(Reptile)
			cout << " not reptiles...";
		cout << endl;
	}
	return;
}

void Node::is_litter_box_full() const
{
	if(typeid(*my_animal) == typeid(Cat))
	{
		cout << endl << "Cat's litter box status: ";
		my_animal->is_litter_box_full();
	}
	else
	{
		cout << endl << "Sorry, litter boxes only apply to cats...";
		if(typeid(*my_animal) == typeid(Dog))
			cout << " not dogs...";
		else // typeid(*my_animal) == type(Reptile)
			cout << " not reptiles...";
		cout << endl;
	}
	return;
}

void Node::is_heater_on() const
{
	if(typeid(*my_animal) == typeid(Reptile))
	{
		cout << endl << "Reptiles heater status: ";
		my_animal->is_heater_on();
	}
	else
	{
		cout << endl << "Sorry, heaters only apply to reptiles...";
		if(typeid(*my_animal) == typeid(Dog))
			cout << " not dogs...";
		else // typeid(*my_animal) == type(Cat)
			cout << " not cats...";
		cout << endl;
	}
	return;
}
