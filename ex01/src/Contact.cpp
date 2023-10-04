#include <iostream>
#include "../inc/Contact.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{

}

std::string Contact::getFirst(void) const
{
	return (this->_first);
}

std::string Contact::getLast(void) const
{
	return (this->_last);
}

std::string Contact::getNick(void) const
{
	return (this->_nick);
}

std::string Contact::getPhone(void) const
{
	return (this->_phone);
}

std::string	Contact::getSecret(void) const
{
	return (this->_secret);
}

void		Contact::setFirst(std::string str)
{
	this->_first = str;
}

void		Contact::setLast(std::string str)
{
	this->_last = str;
}

void		Contact::setNick(std::string str)
{
	this->_nick = str;
}

void		Contact::setPhone(std::string str)
{
	this->_phone = str;
}

void		Contact::setSecret(std::string str)
{
	this->_secret = str;
}