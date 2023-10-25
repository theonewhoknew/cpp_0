#include <iostream>
#include <string>
#include <cstdio>
#include "../inc/Contact.hpp"
#include "../inc/PhoneBook.hpp"

int main(void)
{
	PhoneBook phonebook;

	std::string str;

	str = "";
	while (str.compare("EXIT"))
	{
		std::cout << "Press ADD, SEARCH or EXIT" << std::endl;
		std::cout << "Waiting for input...  ";
		std::getline(std::cin, str);
		if (std::cin.eof()) 
			break ;
		if (str.compare("ADD") == 0)
			phonebook.add();
		else if (str.compare("SEARCH") == 0)
			phonebook.search();
		else
			std::cout << "Wrong command!" << std::endl;
		
	} 
}