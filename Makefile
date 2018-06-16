# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcincean <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/11 13:22:37 by vcincean          #+#    #+#              #
#    Updated: 2018/02/11 13:30:15 by vcincean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

colleen:
	gcc -Wall -Wextra -Werror Colleen.c -o Colleen

grace:
	gcc -Wall -Wextra -Werror Grace.c -o Grace

sully:
	mkdir test_sully/
	gcc -Wall -Wextra -Werror Sully.c -o test_sully/Sully

all: colleen grace sully

clean:
	rm -f Colleen
	rm -f Grace
	rm -f Grace_kid.c
	rm -rf test_sully/

fclean: clean


