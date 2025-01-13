SRCS =	srcs/ft_split.c	\
		srcs/main.c		\

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