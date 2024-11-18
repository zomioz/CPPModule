
SOURCES = main.cpp \
			Contact.cpp \
			PhoneBook.cpp

OBJECTS = $(SOURCES:.cpp=.o)

NAME = PhoneBook

FLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

all : $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all