NAME	:=	push_swap
CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror
OBJ_DIR	:=	obj

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

OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)
DEP := $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
	@echo "✅ push_swap compiled successfully!"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "🧹 Object files removed"

fclean: clean
	@rm -f $(NAME)
	@echo "🗑️  Everything removed"

re: fclean all

.PHONY: all clean fclean re