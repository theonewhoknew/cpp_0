#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_empty = 0;
	this->_overwrite = 0;
	std::cout << "Welcome to PhoneBookApp!"  << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Thank you for using this Phonebook. Bye!" << std::endl;
}

void PhoneBook::add(void)
{
	std::string str;
	int field;
	
	str = "";
	field = 0;
	if (this->_empty == 8)
	{
		this->_empty = 0;
		this->_overwrite = 1;
	}
	while (field == 0)
	{	
		std::cout << "Enter first name: ";
		std::getline(std::cin, str);
		if (!str.empty())
		{	
			this->_contacts[this->_empty].set_first(str);
			field++;
		}
		else
			std::cout << "Field cannot be empty! " << std::endl;	 
	}
	while (field == 1)
	{	
		std::cout << "Enter last name: ";
		std::getline(std::cin, str);
		if (!str.empty())
		{	
			this->_contacts[this->_empty].set_last(str);
			field++;
		}
		else
			std::cout << "Field cannot be empty! " << std::endl; 
	}
	while (field == 2)
	{
		std::cout << "Enter nickname: ";
		std::getline(std::cin, str);
		if (!str.empty())
		{	
			this->_contacts[this->_empty].set_nick(str);
			field++;
		}
		else
			std::cout << "Field cannot be empty! " << std::endl;	 
	}
	while (field == 3)
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, str);
		if (!str.empty())
		{	
			this->_contacts[this->_empty].set_phone(str);
			field++;
		}
		else
			std::cout << "Field cannot be empty! " << std::endl; 
	}
	while (field == 4)
	{
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, str);
		if (!str.empty())
		{	
			this->_contacts[this->_empty].set_secret(str);
			field++;
		}
		else
			std::cout << "Field cannot be empty! " << std::endl; 
	}
	if (this->_overwrite == 0)
		std::cout << "Contact added succesfully in slot " << this->_empty + 1 << "!" << std::endl;
	else
		std::cout << "No empty slots! Slot " << this->_empty + 1 << " overwritten with new contact!" << std::endl;
	this->_empty++;	
}

void PhoneBook::print(void)
{	
	int i;

	i = 0;
	std::cout << "    				CONTACTS                   " << std::endl;
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	if (this->_overwrite == 0)
	{
		while (i < this->_empty)
		{
			this->print_contact(i);
			i++;
		}
	}
	else
	{
		while (i < 8)
		{
			this->print_contact(i);
			i++;
		}
	}
	
	std::cout << "|__________|__________|__________|__________|" << std::endl;
}

void print_spaces(int number)
{
	for (int i = 0; i < number; i++)
	{
		std::cout << " ";
	}
}

void PhoneBook::print_contact(int slot)
{
	std::cout << "|         " << slot + 1;
	std::cout << "|";
	if (this->_contacts[slot].get_first().length() > 10)
	{
		std::cout << this->_contacts[slot].get_first().substr(0, 9);
		std::cout << ".";
	}
	else
	{
		print_spaces(10 - this->_contacts[slot].get_first().length());
		std::cout << this->_contacts[slot].get_first();
	}
	std::cout << "|";
	if (this->_contacts[slot].get_last().length() > 10)
	{
		std::cout << this->_contacts[slot].get_last().substr(0, 9);
		std::cout << ".";
	}
	else
	{
		print_spaces(10 - this->_contacts[slot].get_last().length());
		std::cout << this->_contacts[slot].get_last();
	}
	std::cout << "|";
	if (this->_contacts[slot].get_nick().length() > 10)
	{
		std::cout << this->_contacts[slot].get_nick().substr(0, 9);
		std::cout << ".";
	}
	else
	{
		print_spaces(10 - this->_contacts[slot].get_nick().length());
		std::cout << this->_contacts[slot].get_nick();
	}
	std::cout << "|" << std::endl;
}

void PhoneBook::search(void)
{
	std::string str;
	int done;
	int slot;

	done = 0;
	str = "";
	if (this->_empty == 0 && this->_overwrite == 0)
		std::cout << "Empty phonebook!" << std::endl;
	else
	{
		this->print();
		while (done == 0)
		{	
			std::cout << "Please, select a contact slot(1-8): ";
			std::getline(std::cin, str);
			slot = atoi(str.c_str());
			if (str.empty() || is_digits(str) == 0)
				std::cout << "Uh-oh, it looks like you didn't introduce a number." << std::endl;
			else if(slot == 0 || slot > 8)
				std::cout << "Wrong slot number! " << std::endl;
			else if (str[0] - '0' - 1 >= this->_empty && this->_overwrite == 0)
				std::cout << "This is an empty slot! " << std::endl;
			else
			{
				std::cout << "First name : " << this->_contacts[slot - 1].get_first() << std::endl;
				std::cout << "Last name : " << this->_contacts[slot - 1].get_last() << std::endl;
				std::cout << "Nickname : " << this->_contacts[slot - 1].get_nick() << std::endl;
				std::cout << "Phone Number : " << this->_contacts[slot - 1].get_phone() << std::endl;
				std::cout << "Darkest SEcret : " << this->_contacts[slot - 1].get_secret() << std::endl;
				done++;
			} 
		}
	}
}

int is_digits(std::string& str)
{	
	int i;

	i = 0;
    while(str[i] != '\0') 
	{
        if (!(str[i] >= 48 && str[i] <= 57)) 
            return (0);
		i++;
    }
	return (1);
}
