#ifndef CONTACT_H
# define CONTACT_H
# include <iostream>

class Contact 
{
private:

	std::string _first;
	std::string _last;
	std::string _nick;
	std::string	_phone;
	std::string	_secret;

public:
	Contact( void );
	~Contact( void );

	std::string get_first(void) const;
	std::string get_last(void) const;
	std::string get_nick(void) const;
	std::string	get_phone(void) const;
	std::string	get_secret(void) const;
	void 		set_first(std::string str);
	void  		set_last(std::string str);
	void  		set_nick(std::string str);
	void 		set_phone(std::string str);
	void 		set_secret(std::string str); 		

};

#endif