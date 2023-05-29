NAME = push_swap
RM = rm -f
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = push_swap.c \
	sort.c \
	utils/checkinput.c \
	utils/fill_stack.c \
	utils/find_util.c \
	utils/get_util.c \
	utils/printlist.c \
	utils/times_func.c \
	utils/extra.c \
	moves/push.c \
	moves/revrotate.c \
	moves/rotate.c \
	moves/swap.c \
	libft/ft_atoi.c \
	libft/ft_bzero.c \
	libft/ft_calloc.c \
	libft/ft_isdigit.c \
	libft/ft_lsadd_back.c \
	libft/ft_lstnew.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
