# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/28 14:44:00 by taejkim           #+#    #+#              #
#    Updated: 2021/01/04 21:31:14 by taejkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c \
		ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strncmp.c ft_atoi.c \
		ft_strchr.c ft_strrchr.c ft_strnstr.c \
		ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_itoa.c ft_strmapi.c

OBJ = $(subst .c,.o,$(SRC))

CFLAGS = -Wall -Werror -Wextra

$(NAME):
	gcc $(CFLAGS) -c $(SRC)
	ar -rcs $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
