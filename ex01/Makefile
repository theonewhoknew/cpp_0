NAME = phonebookapp

CLASS = PhoneBook.cpp Contact.cpp

SRC = main.cpp

COMP = c++ -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME) : $(CLASS) $(SRC)
	$(COMP) $(CLASS) $(SRC) -o $(NAME)

clean : 
	rm -f $(NAME)