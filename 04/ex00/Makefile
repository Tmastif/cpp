# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/21 12:14:22 by ilazar            #+#    #+#              #
#    Updated: 2025/04/28 12:18:06 by ilazar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

NAME = a.out

SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongCat.cpp WrongAnimal.cpp

OBJS = $(SRCS:.cpp=.o)


all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -I. -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re