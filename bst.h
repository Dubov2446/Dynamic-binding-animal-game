/*
File: bst.h

AUTHOR: Josue Lopez

Course/Class: CS302-002

Date: 19th Nomeber 2023

Program: CS302-002-program3

Description: Header file for Bst(Binary Search Tree) class, besides
	     the basic funcitons, there are some funcitons that act as
	     wrapper function for the unique pointer that has been upcasted
	     and will at run time call the correct function depending on where
	     it's pointing to.

NOTE: ALL FUNCTIONS THAT SEARCH FOR ANYTHING, FIRST COMPARE BREED THEN
      IT GOES BY NAME.

************************* PUBLIC SECTION *****************************

Bst();
  - You use this whenever you want to create a new Bst object, it will be
    initialized to default values for its private data members. You can set
    the information for the Bst with other member functions.

~Bst();
  - You wouldn't call this and don't need to do anything with it, it's already
    been explicitely set, you can change the contents if you add more data members

void insert(const int& type_of_pet, const string& name, const string& breed);
  - You would call this whenever you want to insert another object into the
    tree calling the insert function, passing in appropriate arguments.

void remove_item(const string& name, const string& breed);
  - You would call this whenever you want to delete an object from the
    tree calling the remove_item function, passing in appropriate arguments

void display() const;
  - You would call this whenever you want to have all the elements in the
    tree displayed. Performs an inorder traversal.

void remove_all();
  - You would call this if you want to DELETE ALL the elements in the tree,
    however, if you do not call this it won't result in a memory leak
    since it is called automatically in the destructor.

		// additional functions for dynamic binding stuff
void speak(const string& name, const string& breed) const;
  - You would call this if you want to invoke the speak function for whichever
    animal you're pointing/refering to (upcasting is assmued to have been done
    prior). Requires correct arguments.

void eat(const string& name, const string& breed) const;
  - You would call this if you want to invoke the eat function for whichever
    animal you're pointing/refering to (upcasting is assmued to have been done
    prior). Requires correct arguments.

void sleep(const string& name, const string& breed) const;
  - You would call this if you want to invoke the sleep function for whichever
    animal you're pointing/refering to (upcasting is assmued to have been done
    prior). Requires correct arguments.

void is_vaccinated(const string& name, const string& breed) const;
  - You would call this if you want to invoke the is_vaccinated function for whichever
    animal you're pointing/refering to (upcasting is assmued to have been done
    prior). Requires correct arguments.

void is_litter_box_full(const string& name, const string& breed) const;
  - You would call this if you want to invoke the is_litter_box_full function
    for whichever animal you're pointing/refering to (upcasting is assmued
    to have been done prior). Requires correct arguments.

void is_heater_on(const string& name, const string& breed) const;
  - You would call this if you want to invoke the is_heater_on function for whichever
    animal you're pointing/refering to (upcasting is assmued to have been done
    prior). Requires correct arguments.

************************* PRIVATE SECTION *****************************

void insert(const int& type_of_pet, const string& name, const string& breed, Node*& root);
  - Private verison of the insert function, same thing, except this is private because it
    deals with the root, and that is not somehing to expose. Also, this is where
    the recursion happens.

void remove_item(const string& name, const string& breed, Node*& root);
  - Private verison of the remove_item function, same thing, except this is private because it
    deals with the root, and that is not somehing to expose. Also, this is where
    the recursion happens.

void display(Node* root) const;
  - Private verison of the display function, same thing, except this is private because it
    deals with the root, and that is not somehing to expose. Also, this is where
    the recursion happens. Display does an inorder traversal to display contents

void remove_all(Node*& root);
  - Private verison of the remove_all function, same thing, except this is private because it
    deals with the root, and that is not somehing to expose. Also, this is where
    the recursion happens.

Node* min_right_sub_tree(Node*) const;
  - There exist no public verison of this, you would call this when you want to find the node with
    the 'minimum' value in the right sub tree. This would happen in the situation where you want
    to delete a node with two children.

void delete_min_right_sub_tree(const string& name, const string& breed, Node*& root);
  - There exist no public version of this, you would call this when you want to delete the node
    with the 'minimum' value in the right sub tere. This would happen in the situaiton where you want
    to delete a node with two children and you've already copied over it's contents so you can delete
    it now.

// additional functions for dynamic binding stuff
void speak(const string& name, const string& breed, bool& found, Node* root) const;
  - You would call this whenever you want an animal to invoke a speak command. Requires
    correct arguments in order to search for that animal.

void eat(const string& name, const string& breed, bool& found, Node* root) const;
  - You would call this whenever you want an animal to invoke a eat command. Requires
    correct arguments in order to search for that animal.

void sleep(const string& name, const string& breed, bool& found, Node* root) const;
  - You would call this whenever you want an animal to invoke a sleep command. Requires
    correct arguments in order to search for that animal.

void is_vaccinated(const string& name, const string& breed, Node* root) const;
  - You would call this whenever you want an animal to invoke a is_vaccinated command.
    Requires correct arguments in order to search for that animal. RTTI happens
    to ensure that only Dog objects get this call since it is unquie to ONLY
    the Dog class

void is_litter_box_full(const string& name, const string& breed, Node* root) const;
  - You would call this whenever you want an animal to invoke a is_litter_box_full command.
    Requires correct arguments in order to search for that animal. RTTI happens
    to ensure that only Cat objects get this call since it is unquie to ONLY
    the Cat class

void is_heater_on(const string& name, const string& breed, Node* root) const;
  - You would call this whenever you want an animal to invoke a is_heater_on command.
    Requires correct arguments in order to search for that animal. RTTI happens
    to ensure that only Reptile objects get this call since it is unquie to ONLY
    the Reptile class

*/
#ifndef BST_H
#define BSH_H

#include "node.h"
#include <string>

using std::string;

class Bst
{
	public:
		Bst();
		~Bst();

		void insert(const int& type_of_pet, const string& name, const string& breed);
		void remove_item(const string& name, const string& breed);
		void display() const;
		void remove_all();

		// additional functions for dynamic binding stuff
		void speak(const string& name, const string& breed) const;
		void eat(const string& name, const string& breed) const;
		void sleep(const string& name, const string& breed) const;
		void is_vaccinated(const string& name, const string& breed) const;
		void is_litter_box_full(const string& name, const string& breed) const;
		void is_heater_on(const string& name, const string& breed) const;


	private:
		Node* root;

		void insert(const int& type_of_pet, const string& name, const string& breed, Node*& root);
		void remove_item(const string& name, const string& breed, Node*& root);
		void display(Node* root) const;
		void remove_all(Node*& root);
		Node* min_right_sub_tree(Node*) const;
		void delete_min_right_sub_tree(const string& name, const string& breed, Node*& root);

		// additional functions for dynamic binding stuff
		void speak(const string& name, const string& breed, bool& found, Node* root) const;
		void eat(const string& name, const string& breed, bool& found, Node* root) const;
		void sleep(const string& name, const string& breed, bool& found, Node* root) const;
		void is_vaccinated(const string& name, const string& breed, Node* root) const;
		void is_litter_box_full(const string& name, const string& breed, Node* root) const;
		void is_heater_on(const string& name, const string& breed, Node* root) const;
};

#endif // BST_H
