SOURCES = main.cpp \
			Zombie.cpp \
			zombieHorde.cpp

OBJECTS = $(SOURCES:.cpp=.o)

NAME = "Moar brainz!"

FLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJECTS)
	c++ $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

all : $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all