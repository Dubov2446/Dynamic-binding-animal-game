/*
File: bst.cpp

AUTHOR: Josue Lopez

Course/Class: CS302-002

Date: 19th Nomeber 2023

Program: CS302-002-program3

Description: Implementation file for Bst(Binary Search Tree) class, besides
	     the basic funcitons, there are some funcitons that act as
	     wrapper function for the unique pointer that has been upcasted
	     and will at run time call the correct function depending on where
	     it's pointing to.

************************* PUBLIC SECTION *****************************

Bst();
  - You don't need to change this unless you plan to modify the private section both in
    terms of members or their value when a new object of this type is created.

~Bst();
  - You don't need to change this unless you plan to modify the private section both in
    terms of members or their value when a new object of this type is destroyed.

void insert(const int& type_of_pet, const string& name, const string& breed);
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

void remove_item(const string& name, const string& breed);
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

void display() const;
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

void remove_all();
  - You do not need to do anything with this, it will traverse and properly delete
    all the nodes in the tree, regardless of the data inside of them.

// additional functions for dynamic binding stuff
void speak(const string& name, const string& breed) const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

void eat(const string& name, const string& breed) const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

void sleep(const string& name, const string& breed) const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

void is_vaccinated(const string& name, const string& breed) const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

void is_litter_box_full(const string& name, const string& breed) const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

void is_heater_on(const string& name, const string& breed) const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

************************* PRIVATE SECTION *****************************

void insert(const int& type_of_pet, const string& name, const string& breed, Node*& root);
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

void remove_item(const string& name, const string& breed, Node*& root);
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

void display(Node* root) const;
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

void remove_all(Node*& root);
  - Maintain this by updating it if you end up adding or changing the private member
    variables, otherwise no action is needed.

Node* min_right_sub_tree(Node*) const;
  - You do not need to change this unless you want to get the largest value in the
    right substree or plan to change it in any major way. However, for a bst
    there really is no reason not to have this or change it in any major way.

void delete_min_right_sub_tree(const string& name, const string& breed, Node*& root);
  - You do not need to change this unless you want to delete the largest value in the
    right substree or plan to change it in any major way. However, for a bst
    there really is no reason not to have this or change it in any major way.

// additional functions for dynamic binding stuff
void speak(const string& name, const string& breed, bool& found, Node* root) const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

void eat(const string& name, const string& breed, bool& found, Node* root) const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

void sleep(const string& name, const string& breed, bool& found, Node* root) const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

void is_vaccinated(const string& name, const string& breed, Node* root) const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

void is_litter_box_full(const string& name, const string& breed, Node* root) const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed

void is_heater_on(const string& name, const string& breed, Node* root) const;
  - Mantain this only if you wish to change what the function does, otherwise no
    action is needed
*/

#include "bst.h"
#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::swap;

Bst::Bst() : root{nullptr} {}

Bst::~Bst()
{
	remove_all(root);
	root = nullptr;
}

// public versions
void Bst::insert(const int& type_of_pet, const string& name, const string& breed)
{
	insert(type_of_pet, name, breed, root);
	return;
}

void Bst::remove_item(const string& name, const string& breed)
{
	remove_item(name, breed, root);
	return;
}

void Bst::display() const
{
	display(root);
	return;
}

void Bst::remove_all()
{
	remove_all(root);
	return;
}

void Bst::speak(const string& name, const string& breed) const
{
	if(!root)
		return; // empty tree
	bool found{false};
	speak(name, breed, found, root);
	if(!found)
		cout << "\nSorry, no matching information for " << name << " - " << breed << endl;
	return;
}

void Bst::eat(const string& name, const string& breed) const
{
	if(!root)
		return; // empty tree
	bool found{false};
	eat(name, breed, found, root);
	if(!found)
		cout << "\nSorry, no matching information for " << name << " - " << breed << endl;
	return;
}

void Bst::sleep(const string& name, const string& breed) const
{
	if(!root)
		return; // empty tree
	bool found{false};
	sleep(name, breed, found, root);
	if(!found)
		cout << "\nSorry, no matching information for " << name << " - " << breed << endl;
	return;
}

void Bst::is_vaccinated(const string& name, const string& breed) const
{
	if(!root)
		return; // empty tree
	is_vaccinated(name, breed, root);
	return;
}

void Bst::is_litter_box_full(const string& name, const string& breed) const
{
	if(!root)
		return; // empty tree
	is_litter_box_full(name, breed, root);
	return;
}

void Bst::is_heater_on(const string& name, const string& breed) const
{
	if(!root)
		return; // empty tree
	is_heater_on(name, breed, root);
	return;
}

// PRIVATE VERSIONS

void Bst::insert(const int& type_of_pet, const string& name, const string& breed, Node*& root)
{
	if(!root)
	{
		root = new Node();
		root->set_name(name);
		root->set_breed(breed);
		root->set_data(type_of_pet, name, breed);
		return;
	}

	else if(breed < root->get_breed())
		insert(type_of_pet, name, breed, root->get_left());

	else if(breed > root->get_breed())
		insert(type_of_pet, name, breed, root->get_right());

	else // breed == root->get_breed()
	{
		if(name < root->get_name())
			insert(type_of_pet, name, breed, root->get_left());
		else if(name > root->get_name())
			insert(type_of_pet, name, breed, root->get_right());
		else // breed and name both match, cannot enter a duplicate
			return;
	}
	return;
}

void Bst::remove_item(const string& name, const string& breed, Node*& root)
{
	if(!root)
	{
		cout << "\nNo matching information for: " << name << " - " << breed << endl;
		return; // didn't find it
	}

	else if(breed < root->get_breed())
		remove_item(name, breed, root->get_left());
	else if(breed > root->get_breed())
		remove_item(name, breed, root->get_right());
	else // breed == root->get_breed()
	{
		if(breed == root->get_breed() && name < root->get_name())
			remove_item(name, breed, root->get_left());
		else if(breed == root->get_breed() && name > root->get_name())
			remove_item(name, breed, root->get_right());
		else // breed == root->get_breed() && name == root->get_name()
		{
			// no children
			if(!root->get_left() && !root->get_right())
			{
				delete root;
				root = nullptr;
				return;
			}
			// has 1 child (left)
			else if(root->get_left() && !root->get_right())
			{
				Node* temp = root;
				root = root->get_left();
				delete temp;
				return;
			}
			// has 1 child (right)
			else if(!root->get_left() && root->get_right())
			{
				Node* temp = root;
				root = root->get_right();
				delete temp;
				return;
			}
			else // has 2 children
			{
				Node* temp = min_right_sub_tree(root->get_right());

				root->set_name(temp->get_name());
				root->set_breed(temp->get_breed());
				temp->set_name(name);
				temp->set_breed(breed);

				swap(temp->get_unique(), root->get_unique());

				delete_min_right_sub_tree(name, breed, root->get_right());
				return;
			}
		}
	}
	return;
}

void Bst::display(Node* root) const
{
	if(!root)
		return;

	display(root->get_left());
	cout << endl;
	root->display_data();
	cout << endl;
	display(root->get_right());
	return;
}

void Bst::remove_all(Node*& root)
{
	if(root)
	{
		remove_all(root->get_left());
		remove_all(root->get_right());
		delete root;
		root = nullptr;
	}
	return;
}

Node* Bst::min_right_sub_tree(Node* root) const
{
	if(!root->get_left())
		return root;
	return min_right_sub_tree(root->get_left());
}

void Bst::delete_min_right_sub_tree(const string& name, const string& breed, Node*& root)
{
	if(root->get_name() == name && root->get_breed() == breed && !root->get_left() && !root->get_right())
	{
		delete root;
		root = nullptr;
		return;
	}
	else if(root->get_name() == name && root->get_breed() == breed && !root->get_left() && root->get_right())
	{
		Node* temp = root;
		root = root->get_right();
		delete temp;
		return;
	}
	delete_min_right_sub_tree(name, breed, root->get_left());
	return;
}

void Bst::speak(const string& name, const string& breed, bool& found, Node* root) const
{
	if(!root)
		return;

	else if(breed < root->get_breed())
		speak(name, breed, found, root->get_left());
	else if(breed > root->get_breed())
		speak(name, breed, found, root->get_right());
	else // breed == root->get_breed()
	{
		if(name < root->get_name())
			speak(name, breed, found, root->get_left());
		else if(name > root->get_name())
			speak(name, breed, found, root->get_right());
		else // name == root->get_name()
		{
			root->animal_speak();
			found = true;
		}
	}
	return;
}

void Bst::eat(const string& name, const string& breed, bool& found, Node* root) const
{
	if(!root)
		return;

	else if(breed < root->get_breed())
		eat(name, breed, found, root->get_left());
	else if(breed > root->get_breed())
		eat(name, breed, found, root->get_right());
	else // breed == root->get_breed()
	{
		if(name < root->get_name())
			eat(name, breed, found, root->get_left());
		else if(name > root->get_name())
			eat(name, breed, found, root->get_right());
		else // name == root->get_name()
		{
			root->animal_eat();
			found = true;
		}
	}
	return;
}

void Bst::sleep(const string& name, const string& breed, bool& found, Node* root) const
{
	if(!root)
		return;

	else if(breed < root->get_breed())
		sleep(name, breed, found, root->get_left());
	else if(breed > root->get_breed())
		sleep(name, breed, found, root->get_right());
	else // breed == root->get_breed()
	{
		if(name < root->get_name())
			sleep(name, breed, found, root->get_left());
		else if(name > root->get_name())
			sleep(name, breed, found, root->get_right());
		else // name == root->get_name()
		{
			root->animal_sleep();
			found = true;
		}
	}
	return;
}

void Bst::is_vaccinated(const string& name, const string& breed, Node* root) const
{
	if(!root)
	{
		cout << "\nNo matching info for: " << name << " - " << breed << endl;
		return;
	}

	else if(breed < root->get_breed())
		is_vaccinated(name, breed, root->get_left());
	else if(breed > root->get_breed())
		is_vaccinated(name, breed, root->get_right());
	else // breed == root->get_breed()
	{
		if(name < root->get_name())
			is_vaccinated(name, breed, root->get_left());
		else if(name > root->get_name())
			is_vaccinated(name, breed, root->get_right());
		else // name == root->get_name()
		{
			root->is_vaccinated();
			return;
		}
	}
	return;
}

void Bst::is_litter_box_full(const string& name, const string& breed, Node* root) const
{
	if(!root)
	{
		cout << "\nNo matching info for: " << name << " - " << breed << endl;
		return;
	}

	else if(breed < root->get_breed())
		is_litter_box_full(name, breed, root->get_left());
	else if(breed > root->get_breed())
		is_litter_box_full(name, breed, root->get_right());
	else // breed == root->get_breed()
	{
		if(name < root->get_name())
			is_litter_box_full(name, breed, root->get_left());
		else if(name > root->get_name())
			is_litter_box_full(name, breed, root->get_right());
		else // name == root->get_name()
		{
			root->is_litter_box_full();
			return;
		}
	}
	return;
}

void Bst::is_heater_on(const string& name, const string& breed, Node* root) const
{
	if(!root)
	{
		cout << "\nNo matching info for: " << name << " - " << breed << endl;
		return;
	}

	else if(breed < root->get_breed())
		is_heater_on(name, breed, root->get_left());
	else if(breed > root->get_breed())
		is_heater_on(name, breed, root->get_right());
	else // breed == root->get_breed()
	{
		if(name < root->get_name())
			is_heater_on(name, breed, root->get_left());
		else if(name > root->get_name())
			is_heater_on(name, breed, root->get_right());
		else // name == root->get_name()
		{
			root->is_heater_on();
			return;
		}
	}
	return;
}
