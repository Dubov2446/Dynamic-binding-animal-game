/*
File: node.h

AUTHOR: Josue Lopez

Course/Class: CS302-002

Date: 19th Nomeber 2023

Program: CS302-002-program3

Description: Header file for node class, besides the basic funcitons, there are
	     some funcitons that act as wrapper function for the unique pointer
	     that has been upcasted and will at run time call the correct function
	     depending on where it's pointing to. Set Data and Display data act
	     in a similar manner.

Node();
  - You use this whenever you want to create a new Node object, it will be
    initialized to default values for its private data members. You can set
    the information for the Node with other member functions.

~Node();
  - You wouldn't call this and don't need to do anything with it, it's already
    been explicitely set, you can change the contents if you add more data members

void set_data(const int& type_of_pet, const string& name, const string& breed);
  - You would call this from the binary search tree with root( val or ref options).

void display_data() const;
  - Displays the data from the object that we are pointing to at run time. You will
    call this from within the binary search tree with root.

void set_left(Node* ptr);
  - You would call this whenever you need to assign some value to the left pointer,
    this will modify the left pointer portion of the node.

void set_right(Node* ptr);
  - You would call this whenever you need to assign some value to the right pointer,
    this will modify the right pointer portion of the node.

Node*& get_left();
  - You would call this whenever you want to get the value of the left pointer,
    this is returned by reference.

Node*& get_right();
  - You would call this whenever you want to get the value of the right poinetr,
    this is returned by reference.

void set_name(const string& name);
  - You would call this whenever you need to assign some value to the name variable,
    this will modify the name portion of the node.

void set_breed(const string& breed);
  - You would call this whenever you need to assign some value to the breed variable,
    this will modify the breed portion of the node.

string get_name() const;
  - You would call this whenever you want to get the value of the name.

string get_breed() const;
  - You would call this whenever you want to get the value of the breed.

unique_ptr<Animal>& get_unique();
  - You would call this whenever you want to get the value of the unique_ptr poinetr,
    this is returned by reference.

// dynamic binding functions
void animal_speak() const;
  - You would call this from within the binary search tree via root to kickstart the
    speak part of the pet (located in animal.h), acts as a wrapper function from
    root to the private data portion of the Node.

void animal_eat() const;
  - You would call this from within the binary search tree via root to kickstart the
    eat part of the pet (located in animal.h), acts as a wrapper function from
    root to the private data portion of the Node.

void animal_sleep() const;
  - You would call this from within the binary search tree via root to kickstart the
    sleep part of the pet (located in animal.h), acts as a wrapper function from
    root to the private data portion of the Node.

void is_vaccinated() const;
  - You would call this from within the binary search tree via root to kickstart the
    vaccinated part of the pet (only exclusive to the Dog class located in animal.h),
    acts as a wrapper function from root to the private data portion of the Node.

void is_litter_box_full() const;
  - You would call this from within the binary search tree via root to kickstart the
    litter box part of the pet (only exclusive to the Cat class located in animal.h),
    acts as a wrapper function from root to the private data portion of the Node.

void is_heater_on() const;
  - You would call this from within the binary search tree via root to kickstart the
    heater box part of the pet (only exclusive to the Reptile class located in animal.h),
    acts as a wrapper function from root to the private data portion of the Node.
*/

#ifndef NODE_H
#define NODE_H

#include <memory>
#include <string>
#include "animal.h"

using std::unique_ptr;
using std::string;

class Node
{
	public:
		Node();
		~Node();

		void set_data(const int& type_of_pet, const string& name, const string& breed);
		void display_data() const;

		void set_left(Node* ptr);
		void set_right(Node* ptr);
		Node*& get_left();
		Node*& get_right();

		void set_name(const string& name);
		void set_breed(const string& breed);
		string get_name() const;
		string get_breed() const;

		unique_ptr<Animal>& get_unique();

		// dynamic binding functions
		void animal_speak() const;
		void animal_eat() const;
		void animal_sleep() const;
		void is_vaccinated() const;
		void is_litter_box_full() const;
		void is_heater_on() const;

	private:
		string name;
		string breed;
		Node* left;
		Node* right;
		unique_ptr<Animal> my_animal;
};

#endif // NODE_H
