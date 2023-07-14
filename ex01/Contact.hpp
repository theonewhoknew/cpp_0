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

	std::string getFirst(void) const;
	std::string getLast(void) const;
	std::string getNick(void) const;
	std::string	getPhone(void) const;
	std::string	getSecret(void) const;
	void 		setFirst(std::string str);
	void  		setLast(std::string str);
	void  		setNick(std::string str);
	void 		setPhone(std::string str);
	void 		setSecret(std::string str); 		

};

#endif