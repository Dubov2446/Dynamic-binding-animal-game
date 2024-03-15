/*
File: animal.h

AUTHOR: Josue Lopez

Course/Class: CS302-002

Date: 19th Nomeber 2023

Program: CS302-002-program3

Description: Header file for animal class(including derived classes), besides
	     the basic funcitons, there are some funcitons that act as
	     wrapper function for the unique pointer that has been upcasted
	     and will at run time call the correct function depending on where
	     it's pointing to. Set Data and Display data act in a similar manner.

******************************* ANIMAL CLASS **********************************

Animal();
  - You wouldn't use this since you cannot create objects of this type since it's been
    declared as an ABC (abstract base class), however, this will still be called whenever
    we make another object that's derived from it to initialize the private member
    variables to their default value

virtual ~Animal();
  - You also would not call this, this is used to redirect the pointer/reference to call
    the correct destrutor since it has been declared as virtual. However, it will still
    be called resulting in the private memeber variables to be 'reset' to their
    default value.

virtual void set_data(const string& name, const string& breed);
  - You also would not call this, this is used to redirect the pointer/reference to call
    the correct version based off what it's pointing/referencing to AT RUN TIME.
    The base version is called by using Animal::set_data(args...) WITHIN the
    derivered that gets called first.

virtual void display() const;
  - You also would not call this, this is used to redirect the pointer/reference to call
    the correct version based off what it's pointing/referencing to AT RUN TIME.
    The base version is called by using Animal::display() WITHIN the
    derived that gets called first.

virtual void speak() const = 0;
  - Pure virtual function that does not 'exist' or is 'bodyless' in the base, but is
    used in the derived class. You would not call this one specificall, instead you
    would perform upcasting then you can call this function, and it'll redirect
    traffic to the correct class at run time

virtual void eat() const = 0;
  - Pure virtual function that does not 'exist' or is 'bodyless' in the base, but is
    used in the derived class. You would not call this one specificall, instead you
    would perform upcasting then you can call this function, and it'll redirect
    traffic to the correct class at run time

virtual void sleep() const = 0;
  - Pure virtual function that does not 'exist' or is 'bodyless' in the base, but is
    used in the derived class. You would not call this one specificall, instead you
    would perform upcasting then you can call this function, and it'll redirect
    traffic to the correct class at run time

virtual void is_vaccinated() const = 0; // for dog class
  - Pure virtual function that does not 'exist' or is 'bodyless' in the base, but is
    used in the derived class. You would not call this one specificall, instead you
    would perform upcasting then you can call this function, and it'll redirect
    traffic to the correct class at run time. For this function, it is unique to
    the Dog class, however, it still needs to be implemented in every class so
    that the class itself doesn't become abstract.

virtual void is_litter_box_full() const = 0; // for cat class
  - Pure virtual function that does not 'exist' or is 'bodyless' in the base, but is
    used in the derived class. You would not call this one specificall, instead you
    would perform upcasting then you can call this function, and it'll redirect
    traffic to the correct class at run time. For this function, it is unique to
    the Cat class, however, it still needs to be implemented in every class so
    that the class itself doesn't become abstract.

virtual void is_heater_on() const = 0; // for reptile class
  - Pure virtual function that does not 'exist' or is 'bodyless' in the base, but is
    used in the derived class. You would not call this one specificall, instead you
    would perform upcasting then you can call this function, and it'll redirect
    traffic to the correct class at run time. For this function, it is unique to
    the Reptile class, however, it still needs to be implemented in every class so
    that the class itself doesn't become abstract.

string get_name() const;
  - You would call this whenever you need to get the value stored in the private
    memeber variable 'name.'

string get_breed() const;
  - You would call this whenever you need to get the value stored in the private
    memeber variable 'breed.'

******************************* DOG CLASS **********************************

Dog();
  - You would call this whenever you want to create a new Dog object.

~Dog();
  - You wouldn't call this explicitely, called automatically and clears data

void set_data(const string& name, const string& breed);
  - You would call this to set the data of not only the Dog object, but also
    of the parent which of type Animal by doing Animal::set_data(args....).

void display() const;
  - You would call this to set the data of not only the Dog object, but also
    of the parent which of type Animal by doing Animal::display().

void speak() const;
  - You would call this to invoke the speak function for whatever object you
    are pointing/referencing to at run time, upcasting should be done prior

void eat() const;
  - You would call this to invoke the eat function for whatever object you
    are pointing/referencing to at run time, upcasting should be done prior

void sleep() const;
  - You would call this to invoke the sleep function for whatever object you
    are pointing/referencing to at run time, upcasting should be done prior

// unique to this class, but pure virtual in base
void is_vaccinated() const;
  - You would call this to invoke the is_vaccinated function for a Dog object you
    are pointing/referencing to at run time, upcasting should be done prior.
    This is unique only to a Dog object and will not work for other Types.
    RTTI in the form of typeid() is done to ensure the object we are pointing to
    is in fact a Dog object before calling this function.

// need to implent these or else dog with become abstract
void is_litter_box_full() const;
  - You wouldn't call these because it does nothing. It is required to be
    implemented because then Dog will become abstract itself, and if that
    happens, we won't be allowed to create Dog objects.

void is_heater_on() const;
  - You wouldn't call these because it does nothing. It is required to be
    implemented because then Dog will become abstract itself, and if that
    happens, we won't be allowed to create Dog objects.

// for RTTI
void run() const;
  - You would call this to invoke the run function for a Dog object you
    are pointing/referencing to at run time, downcasting should be done prior.
    This is unique only to a Dog object and will not work for other Types.
    RTTI in the form of typeid() is done to ensure the object we are pointing to
    is in fact a Dog object before calling this function.

******************************* CAT CLASS **********************************

Cat();
  - You would call this whenever you want to create a new Cat object.

~Cat();
  - You wouldn't call this explicitely, called automatically and clears data

void set_data(const string& name, const string& breed);
  - You would call this to set the data of not only the Cat object, but also
    of the parent which of type Animal by doing Animal::set_data(args....).

void display() const;
  - You would call this to set the data of not only the Cat object, but also
    of the parent which of type Animal by doing Animal::display().

void speak() const;
  - You would call this to invoke the speak function for whatever object you
    are pointing/referencing to at run time, upcasting should be done prior

void eat() const;
  - You would call this to invoke the eat function for whatever object you
    are pointing/referencing to at run time, upcasting should be done prior

void sleep() const;
  - You would call this to invoke the sleep function for whatever object you
    are pointing/referencing to at run time, upcasting should be done prior

// unique to this class, but pure virtual in base
void is_litter_box_full() const;
  - You would call this to invoke the is_vaccinated function for a Cat object you
    are pointing/referencing to at run time, upcasting should be done prior.
    This is unique only to a Cat object and will not work for other Types.
    RTTI in the form of typeid() is done to ensure the object we are pointing to
    is in fact a Cat object before calling this function.

// need to implent these or else dog with become abstract
void is_vaccinated() const;
  - You wouldn't call these because it does nothing. It is required to be
    implemented because then Cat will become abstract itself, and if that
    happens, we won't be allowed to create Cat objects.

void is_heater_on() const;
  - You wouldn't call these because it does nothing. It is required to be
    implemented because then Cat will become abstract itself, and if that
    happens, we won't be allowed to create Cat objects.

******************************* REPTILE CLASS **********************************

Reptile();
  - You would call this whenever you want to create a new Reptile object.

~Reptile();
  - You wouldn't call this explicitely, called automatically and clears data

void set_data(const string& name, const string& breed);
  - You would call this to set the data of not only the Reptile object, but also
    of the parent which of type Animal by doing Animal::set_data(args....).

void display() const;
  - You would call this to set the data of not only the Reptile object, but also
    of the parent which of type Animal by doing Animal::display().

void speak() const;
  - You would call this to invoke the speak function for whatever object you
    are pointing/referencing to at run time, upcasting should be done prior

void eat() const;
  - You would call this to invoke the eat function for whatever object you
    are pointing/referencing to at run time, upcasting should be done prior

void sleep() const;
  - You would call this to invoke the sleep function for whatever object you
    are pointing/referencing to at run time, upcasting should be done prior

// unique to this class, but pure virtual in base
void is_heater_on() const;
  - You would call this to invoke the is_heater_on function for a Reptile object
    you are pointing/referencing to at run time, upcasting should be done prior.
    This is unique only to a Reptile object and will not work for other Types.
    RTTI in the form of typeid() is done to ensure the object we are pointing to
    is in fact a Reptile object before calling this function.

void is_vaccinated() const;
  - This does nothing as it does not pertain to a Reptile class, it is only here
    so that it is implemented and does not make Reptile an abc (abstract base class)
    in the event that we don't implement it.

void is_litter_box_full() const;
  - This does nothing as it does not pertain to a Reptile class, it is only here
    so that it is implemented and does not make Reptile an abc (abstract base class)
    in the event that we don't implement it.

*/

#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using std::string;

class Animal
{
	public:
		// required
		Animal(); // constructors cannot be virtual
		virtual ~Animal();
		virtual void set_data(const string& name, const string& breed);
		virtual void display() const;

		// only for derived classes, need them in derived but we
		// don't need them in base, so pure virtual
		virtual void speak() const = 0;
		virtual void eat() const = 0;
		virtual void sleep() const = 0;

		// unique for 1 derived class, but pure virtual
		virtual void is_vaccinated() const = 0; // for dog class
		virtual void is_litter_box_full() const = 0; // for cat class
		virtual void is_heater_on() const = 0; // for reptile class

		string get_name() const;
		string get_breed() const;

	private:
		string name;
		string breed;
		int lvl_of_care;
		int temperament;
		int size;
		int friendliness;
};

class Dog : public Animal
{
	public:
		// required
		Dog();
		~Dog();
		void set_data(const string& name, const string& breed);
		void display() const;

		// pure vituals in base
		void speak() const;
		void eat() const;
		void sleep() const;

		// unique to this class, but pure virtual in base
		void is_vaccinated() const;

		// need to implent these or else dog with become abstract
		void is_litter_box_full() const;
		void is_heater_on() const;

		// for RTTI
		void run() const;

	private:
		bool vaccinated;
};

class Cat : public Animal
{
	public:
		// required
		Cat();
		~Cat();
		void set_data(const string& name, const string& breed);
		void display() const;

		// pure vituals in base
		void speak() const;
		void eat() const;
		void sleep() const;

		// unique to this class, but pure virtual in base
		void is_litter_box_full() const;

		// need to implent these or else dog with become abstract
		void is_vaccinated() const;
		void is_heater_on() const;

	private:
		bool has_litter_box;
};

class Reptile : public Animal
{
	public:
		// required
		Reptile();
		~Reptile();
		void set_data(const string& name, const string& breed);
		void display() const;

		// pure vituals in base
		void speak() const;
		void eat() const;
		void sleep() const;

		// unique to this class, but pure virtual in base
		void is_heater_on() const;

		// need to implent these or else dog with become abstract
		void is_vaccinated() const;
		void is_litter_box_full() const;

	private:
		bool has_heater;
};
#endif // ANIMAL_H
