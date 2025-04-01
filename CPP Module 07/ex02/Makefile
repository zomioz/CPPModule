SRCS = main.cpp

NAME = "Array"

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all