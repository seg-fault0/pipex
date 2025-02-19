SRCS =	srcs/error.c	\
		srcs/luncher.c	\
		srcs/exit.c		\
		srcs/ft_split.c	\
		srcs/init.c		\
		srcs/main.c		\
		srcs/utils.c	\

BSRCS = bonus/error_bonus.c					\
		bonus/luncher_bonus.c				\
		bonus/exit_bonus.c					\
		bonus/ft_split_bonus.c				\
		bonus/get_next_line_bonus.c			\
		bonus/get_next_line_utils_bonus.c	\
		bonus/init_bonus.c					\
		bonus/main_bonus.c					\
		bonus/utils_bonus.c					\

OBG	=	$(SRCS:.c=.o)
BOBG =	$(BSRCS:.c=.o)

NAME = pipex
BNAME = pipex_bonus

FLAGS = -Wall -Wextra -Werror

I = -I ./includes/

all : $(NAME)
bonus : $(BNAME)

$(NAME) : $(OBG)
	cc $^ -o $@
$(BNAME) : $(BOBG)
	cc $^ -o $@

$(OBG) : %.o : %.c ./includes/pipex.h
	cc -c $(FLAGS) $(I) $< -o $@
$(BOBG) : %.o : %.c ./includes/pipex_bonus.h
	cc -c $(FLAGS) $(I) $< -o $@

clean : 
	rm -f $(OBG) $(BOBG)

fclean : clean
	rm -f $(NAME) $(BNAME)

re : fclean all
bre : fclean bonus

.PHONY : clean
