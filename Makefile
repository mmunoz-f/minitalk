# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miguel <miguel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/12 15:40:15 by mmunoz-f          #+#    #+#              #
#    Updated: 2021/07/13 04:58:57 by miguel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TIME =   $(shell date +'%d/%m/%Y %H:%M:%S')
M =
CC = clang
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

SOURCE = minitalk_utils.c
SOURCE_OBJS = $(SOURCE:.c=.o)

SERVER = server
SERVER_SOURCE = server.c
SERVER_OBJS = $(SERVER_SOURCE:.c=.o)

CLIENT = client
CLIENT_SOURCE = client.c
CLIENT_OBJS = $(CLIENT_SOURCE:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(SOURCE_OBJS) $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $@ $(SOURCE) $(SERVER_OBJS)

$(CLIENT): $(SOURCE_OBJS) $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $@ $(SOURCE) $(CLIENT_OBJS)

clean:
	rm -f $(SOURCE_OBJS) $(CLIENT_OBJS) $(SERVER_OBJS)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

push: fclean
	git add .
	git commit -m "$(TIME) - $(M)"
	git push origin master

.PHONY: all clean fclean re push
