NAME = libftprintf
CC = gcc 
INC = ft_printf.h
CFALGS = -Wall -Wextra -Werror

SRCS = ft_printf.c		\
		ft_putnbrbase.c	\
		ft_uplowx.c		\

OBJS = $(SRCS:.c=.o)

all: $(NAME).a

$(NAME).a: $(OBJS)
	ar -rcs $(NAME).a $(OBJS)

%.o: %.c $(INC)
	$(CC) -c $< -o $@ $(CFALGS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME).a

re: fclean all

.PHONY: all, clean, fclean, re
