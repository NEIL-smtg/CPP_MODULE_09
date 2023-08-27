NAME            =       PmergeMe
FILES           =       main PmergeMe
SRCS_DIR        =       srcs/
OBJS_DIR        =       objs/
SRCS            =       $(addprefix $(SRCS_DIR), $(addsuffix .cpp, $(FILES)))
OBJS            =       $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
CPP             =       c++
CFLAGS          =       -Wall -Werror -Wextra -std=c++98 -pedantic
RM             	=       rm -rf
FSAN            =       -fsanitize=address -g3

all:
	mkdir -p $(OBJS_DIR)
	make $(NAME)

$(OBJS_DIR)%.o:$(SRCS_DIR)%.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS_DIR)

fclean: clean 
	$(RM) $(NAME)

re: fclean all

leaks: all
	valgrind --leak-check=full ./$(NAME)
