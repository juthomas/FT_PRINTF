# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/20 14:55:57 by juthomas          #+#    #+#              #
#    Updated: 2017/04/04 13:13:13 by juthomas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re
.SUFFIXES:

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

CC = clang

OBJ_PATH = objects

H = ./include


#	./sources/ft_converter_2.c ./sources/ft_converter_3.c \#
#	./sources/converter/uintmax_t/ft_putnbr_uintmax_t.c \#
#	./sources/converter/int/ft_putnbr_int.c \
#	./sources/converter/intmax_t/ft_putnbr_intmax_t.c \
#	./sources/converter/long_int/ft_putnbr_long_int.c \

SRC = ./sources/ft_printf_1.c ./sources/ft_printf_2.c \
	./sources/ft_printf_3.c ./sources/ft_printf_4.c \
	./sources/ft_printf_5.c ./sources/ft_printf_6.c \
	./sources/ft_printf_7.c \
	./sources/ft_putnbr_printf.c sources/ft_atoi.c \
	./sources/ft_color.c ./sources/ft_dollard.c ./sources/ft_converter_1.c \
	./sources/ft_converter_2.c ./sources/ft_converter_3.c \
	./sources/ft_converter_4.c ./sources/ft_converter_5.c \
	./sources/ft_converter_6.c ./sources/ft_multiple_base.c \
	./sources/converter/long_long_int/ft_putnbr_long_long_int.c \
	./sources/converter/unsi_long_long/ft_putnbr_unsi_long_long.c \
	./sources/libft/ft_isdigit.c ./sources/libft/ft_isalnum.c \
	./sources/libft/ft_isascii.c ./sources/libft/ft_atoi.c \
	./sources/libft/ft_isalpha.c ./sources/libft/ft_strcat.c \
	./sources/libft/ft_strcmp.c ./sources/libft/ft_strcpy.c \
	./sources/libft/ft_strdup.c ./sources/libft/ft_strlcat.c \
	./sources/libft/ft_strlen.c ./sources/libft/ft_strncat.c \
	./sources/libft/ft_strncmp.c ./sources/libft/ft_strncpy.c \
	./sources/libft/ft_strnstr.c ./sources/libft/ft_strstr.c \
	./sources/libft/ft_isprint.c ./sources/libft/ft_toupper.c \
	./sources/libft/ft_tolower.c ./sources/libft/ft_strchr.c \
	./sources/libft/ft_strrchr.c ./sources/libft/ft_bzero.c \
	./sources/libft/ft_memset.c ./sources/libft/ft_memcpy.c \
	./sources/libft/ft_memccpy.c ./sources/libft/ft_memmove.c \
	./sources/libft/ft_memchr.c ./sources/libft/ft_itoa.c \
	./sources/libft/ft_lstadd.c ./sources/libft/ft_lstdel.c \
	./sources/libft/ft_lstdelone.c ./sources/libft/ft_lstiter.c \
	./sources/libft/ft_lstmap.c ./sources/libft/ft_lstnew.c \
	./sources/libft/ft_memalloc.c ./sources/libft/ft_memdel.c \
	./sources/libft/ft_putchar.c ./sources/libft/ft_putchar_fd.c \
	./sources/libft/ft_putendl.c ./sources/libft/ft_putendl_fd.c \
	./sources/libft/ft_putnbr.c ./sources/libft/ft_putnbr_fd.c \
	./sources/libft/ft_putstr.c ./sources/libft/ft_putstr_fd.c \
	./sources/libft/ft_strclr.c ./sources/libft/ft_strdel.c \
	./sources/libft/ft_strequ.c ./sources/libft/ft_striter.c \
	./sources/libft/ft_striteri.c ./sources/libft/ft_strjoin.c \
	./sources/libft/ft_strmap.c ./sources/libft/ft_strmapi.c \
	./sources/libft/ft_strnequ.c ./sources/libft/ft_strnew.c \
	./sources/libft/ft_strsplit.c ./sources/libft/ft_strsub.c \
	./sources/libft/ft_strtrim.c ./sources/libft/ft_memcmp.c \
	./sources/libft/ft_putbit.c ./sources/libft/ft_itoa_base.c \
	./sources/libft/ft_atoi_base.c ./sources/libft/ft_putnbr_base.c \
	./sources/libft/ft_convert_base.c ./sources/libft/ft_putchar_printf.c \
	./sources/libft/ft_putstr_printf.c ./sources/libft/ft_straddc.c \
	./sources/libft/ft_putwchar_fd.c ./sources/libft/ft_putwchar_printf.c \
	./sources/libft/ft_putwstr_fd.c ./sources/libft/ft_putwstr_printf.c \
	./sources/libft/ft_putstr_len_printf.c \
	./sources/libft/ft_putwstr_len_printf.c

#	ft_putnbr_int.o ft_putnbr_intmax_t.o \
#	ft_putnbr_long_int.o ft_putnbr_uintmax_t.o \
#	ft_converter_2.o ft_converter_3.c \#
OBJ = ft_printf_1.o ft_printf_2.o ft_printf_3.o ft_printf_4.o ft_printf_5.o \
	ft_printf_6.o ft_printf_7.o \
	ft_putnbr_printf.o ft_atoi.o ft_dollard.o \
	ft_converter_1.o ft_converter_2.o ft_converter_3.o ft_converter_4.o \
	ft_converter_5.o ft_converter_6.o ft_multiple_base.o \
	ft_putnbr_long_long_int.o \
	ft_putnbr_unsi_long_long.o ft_color.o \
	ft_isdigit.o ft_isalnum.o ft_isascii.o \
	ft_atoi.o ft_isalpha.o ft_strcat.o ft_strcmp.o \
	ft_strcpy.o ft_strdup.o ft_strlcat.o ft_strlen.o ft_strncat.o \
	ft_strncmp.o ft_strncpy.o ft_strnstr.o \
	ft_strstr.o ft_isprint.o ft_toupper.o ft_tolower.o \
	ft_strchr.o ft_strrchr.o ft_bzero.o ft_memset.o ft_memcpy.o \
	ft_memccpy.o ft_memmove.o ft_memchr.o ft_itoa.o ft_lstadd.o \
	ft_lstdel.o ft_lstdelone.o ft_lstiter.o ft_lstmap.o ft_lstnew.o \
	ft_memalloc.o ft_memdel.o ft_putchar.o ft_putchar_fd.o \
	ft_putendl.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o \
	ft_putstr.o ft_putstr_fd.o ft_strclr.o ft_strdel.o ft_strequ.o \
	ft_striter.o ft_striteri.o ft_strjoin.o ft_strmap.o ft_strmapi.o \
	ft_strnequ.o ft_strnew.o ft_strsplit.o ft_strsub.o ft_strtrim.o \
	ft_memcmp.o ft_putbit.o ft_itoa_base.o ft_atoi_base.o \
	ft_putnbr_base.o ft_convert_base.o ft_putchar_printf.o \
	ft_putstr_printf.o ft_straddc.o ft_putwchar_fd.o ft_putwchar_printf.o \
	ft_putwstr_fd.o ft_putwstr_printf.o ft_putstr_len_printf.o \
	ft_putwstr_len_printf.o

OBJ_R = $(addprefix $(OBJ_PATH)/,$(OBJ))

$(NAME):
	@echo "\033[00;96m"
	@echo "\nMAKE \n"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) -c $(SRC) -I $(H)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	mv *.o $(OBJ_PATH)

all: $(NAME)


clean:
	@echo "\033[00;91m"
	@echo "\nCLEAN \n"
	rm -rf $(OBJ_R)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
fclean: clean
	rm -rf $(NAME)

re: fclean all;
