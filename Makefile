SRCS =	srcs/error.c	\
		srcs/ft_split.c	\
		srcs/init.c		\
		srcs/main.c		\
		srcs/utils.c	\

OBG =	$(SRCS:.c=.o)

NAME = pipex

FLAGS = -Wall -Wextra -Werro

I = -I ./includes/

all:$(NAME)

$(NAME) : $(OBG)
	cc $^ -o $@

$(OBG) : %.o : %.c ./includes/pipex.h
	cc -c $(I) $< -o $@

clean : 
	rm -fr $(OBG)

fclean : clean
	rm -fr $(NAME)

.PHONY : clean