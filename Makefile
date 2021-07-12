# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/12 15:40:15 by mmunoz-f          #+#    #+#              #
#    Updated: 2021/07/12 15:59:36 by mmunoz-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TIME =   $(shell date +'%d/%m/%Y %H:%M:%S')
M =
CC = clang
CFLAGS = -Wall -Wextra -Werror -g

SERVER = server
SERVER_SOURCE =
SERVER_OBJS = $(SERVER_SOURCE:.c=.o)

CLIENT = client
CLIENT_SOURCE =
CLIENT_OBJS = $(CLIENT_SOURCE:.c=.o)

all: $(CLIENT) $(SERVER)

$(SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS_SOURCE)

fclean: clean
	rm -f $(NAME)

re: fclean all

push: fclean
	git add .
	git commit -m "$(TIME) - $(M)"
	git push origin master

.PHONY: all clean fclean re push
