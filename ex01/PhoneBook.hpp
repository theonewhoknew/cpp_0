#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include "Contact.hpp"

class PhoneBook 
{

private:
	Contact _contacts[8];
	int 	_empty;
	int		_overwrite;

public:
	PhoneBook(void);
	~PhoneBook(void);
	void add(void);
	void search(void);
	void print(void);
	void print_contact(int slot);
	

};

int is_digits(std::string& str);
void print_spaces(int number);


#endif