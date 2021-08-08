NAME= pipex.a

SRC= 	./src/pipex.c ./src/pathing.c ./libft/ft_split.c ./libft/ft_strchr.c ./libft/ft_strlen.c \
		./libft/ft_strlcpy.c ./libft/ft_putstr_fd.c ./libft/ft_putendl_fd.c \
		./libft/ft_strlcat.c ./libft/ft_strjoin.c ./libft/ft_strncmp.c \


OBJ= $(SRC:.c=.o)

CC= gcc

CFLAGS += -Werror -Wall -Wextra -I./

$(NAME): $(OBJ)
		-@gcc $(CFLAGS) $(SRC) -o pipex
		-ar -rc $(NAME) $(OBJ)
		ranlib $(NAME)
all:	$(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean

.PHONY: all clean fclean re