SOURCES = AMateria.cpp \
			Character.cpp \
			MateriaSource.cpp \
			Ice.cpp \
			Cure.cpp \
			main.cpp

OBJECTS = $(SOURCES:.cpp=.o)

NAME = AMateria

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

all : $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all