NAME = libftprintf.a
CC = cc
AR = ar rcs
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_hex.c ft_int.c ft_str.c 
OBJ_DIR		= ../obj/ft_printf

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	@$(AR) $(NAME) $?

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean :
	@$(RM) $(OBJ)
fclean : clean
	@$(RM) $(NAME)
re : fclean all

.PHONY : all clean fclean re