# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/21 12:14:22 by ilazar            #+#    #+#              #
#    Updated: 2025/03/21 15:49:11 by ilazar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

NAME = phonebook

INC = PhoneBook.hpp

SRCS = PhoneBook.cpp

OBJS = $(SRCS:.cpp=.o)


all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re