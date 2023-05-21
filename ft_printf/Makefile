NAME = libft_printf.a

LIB = ar rcs
CFLAGS = -Wall -Wextra -Werror
CC				= gcc 
RM				= rm -f

S = src/

MY_SRC	= $Sft_printf.c $Shandles.c $Shandle_int.c \
			$Shandle_u.c $Shandle_hex.c $Shandle_p.c \
			$Shandle_cs.c

MY_OBJS = $(MY_SRC:$S%.c=$S%.o)

all:			$(NAME)

$(NAME): $(MY_OBJS)
			$(LIB) $(NAME) $(MY_OBJS)

%.o: $S%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
			$(RM) $(MY_OBJS) 
			

fclean:		clean
			$(RM) $(NAME)

re: fclean all
.PHONY: all clean fclean re

