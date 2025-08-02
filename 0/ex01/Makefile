NAME = phonebook

CC = c++

FLAG = -Wall -Wextra -Werror -std=c++98

SRC = Main.cpp \
	  Contact.cpp \
	  PhoneBook.cpp

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) $(OBJ) -o $(NAME) 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
