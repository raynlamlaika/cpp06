NAME = Bureaucrat

SRC =   iter.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

CPP = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

HEADER = iter.hpp 

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP)  $(CFLAGS) $^ -o $(NAME)


%.o: %.cpp $(HEADER)
	$(CPP)  $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all