SOURCES = ClapTrap.cpp \
			ScavTrap.cpp \
			FragTrap.cpp \
			main.cpp

OBJECTS = $(SOURCES:.cpp=.o)

NAME = FragTrap

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
