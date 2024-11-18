
SOURCES = tests.cpp \
			Account.cpp

OBJECTS = $(SOURCES:.cpp=.o)

NAME = Account

FLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	c++ $(FLAGS) $(OBJECTS) -o $(NAME)

all : $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
