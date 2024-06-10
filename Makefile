NAME	=	fdf.a

SRC		=	example.c

OBJ = $(SRC:.c=.o)

LIBFT_PATH	= libft/

LIBFT_NAME	= libft.a

LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

CC			=	cc

RM 			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
