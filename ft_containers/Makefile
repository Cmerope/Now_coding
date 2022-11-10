NAME 			= Containers

SRC 			= main.cpp

OBJ 			= $(SRC:.cpp=.o)

HEADERS			= vector.hpp


CC 				= c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(%.o): $(%.cpp)
				$(CC) -o $@ -c $(HEADERS) $^

$(NAME): $(OBJ)
				@echo "\nCompiling --->"
				@$(CC) -o $@ $^
				@echo "Done\n"

clean:
				@rm -rf $(OBJ)
				@echo "\nDelete objects\n"

fclean: 		clean
				@rm -rf $(NAME)
				@echo "\nDelete all\n"

re: 			fclean all

.PHONY:			all clean fclean re
