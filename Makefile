NAME	:=	push_swap
CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror -g

SRC := \
	helper.c \
	main.c \
	parsing.c \
	parsing2.c \
	movies_swap.c \
	movies_push.c \
	movies_rotate.c \
	movies_rrotate.c \
	children.c \
	algo_rythmic.c \

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
	@echo "☼.☼ push_swap compiled successfully!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re