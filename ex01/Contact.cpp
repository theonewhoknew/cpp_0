#include <iostream>
#include "Contact.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{

}

std::string Contact::get_first(void) const
{
	return (this->_first);
}

std::string Contact::get_last(void) const
{
	return (this->_last);
}

std::string Contact::get_nick(void) const
{
	return (this->_nick);
}

std::string Contact::get_phone(void) const
{
	return (this->_phone);
}

std::string	Contact::get_secret(void) const
{
	return (this->_secret);
}

void		Contact::set_first(std::string str)
{
	this->_first = str;
}

void		Contact::set_last(std::string str)
{
	this->_last = str;
}

void		Contact::set_nick(std::string str)
{
	this->_nick = str;
}

void		Contact::set_phone(std::string str)
{
	this->_phone = str;
}

void		Contact::set_secret(std::string str)
{
	this->_secret = str;
}