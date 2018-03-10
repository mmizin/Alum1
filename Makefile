NAME = alum1
SRCS = 	main.c ft_bzero.c ft_lstnew.c ft_memccpy.c ft_memcpy.c ft_memdel.c ft_memmove.c \
		 ft_memset.c ft_strchr.c ft_strclr.c ft_strdup.c \
		  ft_strjoin.c ft_strlen.c ft_strncat.c ft_strnew.c ft_strrchr.c ft_strsub.c \
		   get_next_line.c f_valid.c my_ft_setyourchar.c ft_strsplit.c my_ft_lettercount.c \
		    my_ft_wordcount.c ft_atoi.c

INCLUDES = libft.h
CC = gcc -Wall -Wextra -Werror

all: $(NAME)

%.o:%.c
	$(CC) -I $(INCLUDES) -c $^

$(NAME): *.o
	$(CC) *.o -o $(NAME)

clean:
	/bin/rm -rf *.o *.out

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

