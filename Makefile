# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 12:20:06 by atabiti           #+#    #+#              #
#    Updated: 2022/05/04 11:04:26 by atabiti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS = ft_philo.c ft_tools.c ft_time.c  threadcreat.c ft_init.c ft_checker.c ft_start_routine.c 
OBJF =  ft_philo.o ft_tools.o ft_time.o threadcreat.o ft_init.o ft_checker.o ft_start_routine.o
FLAGS = -Wextra -Werror -Wall
all : $(NAME)
$(OBJF) : 
		gcc $(FLAGS) -c $(SRCS)
		
$(NAME) : $(OBJF)
	gcc   $(OBJF) -o $(NAME)


clean:
		rm -f *.o
		
fclean: clean
		rm -f philo

re: fclean all

