#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochayche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/28 21:27:19 by ochayche          #+#    #+#              #
#    Updated: 2017/03/28 21:27:20 by ochayche         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

GCC = gcc

# F = -Wall -Wextra -Werror

NAME = filler

INCL = libft/libft.a ft_printf/libftprintf.a

OBJECT = 	filler.o \
			read_map.o \
			create_priority.o \
			read_token_size.o \
			player_step.o \
			error_filler.o

.PHONY: all clean fclean re bug debug

all: $(NAME)
	@make -C libft/
	@make -C ft_printf/

$(NAME): $(OBJECT)
		@make -C libft/
		@make -C ft_printf/
		$(GCC) $(F) -o $(NAME) $(OBJECT) $(INCL)

clean:
	@make clean -C libft/
	@make clean -C ft_printf/
	rm -rf $(OBJECT)

fclean: clean
	@make fclean -C libft/
	@make fclean -C ft_printf/
	@rm -rf $(NAME) a.out

re: fclean all

r: all
	./$(NAME) $(TEST)

bug:
	gcc -g filler.c read_map.c read_token_size.c player_step.c error_filler.c $(INCL)

debug: bug
	lldb -- ./resources/filler_vm -p1 a.out -p2 resources/players/champely.filler -f  maps/map00 

%.o: ./%.c
	$(GCC) $(F) -o $@ -c $< -I ./
