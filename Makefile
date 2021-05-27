# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honlee <honlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 10:27:59 by honlee            #+#    #+#              #
#    Updated: 2021/05/27 11:06:33 by honlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######### SHARE PART ##########
SHARE_DIR	=		./srcs_share/
SHARE_SRCNAME = 	\
					util1.c\
					util2.c\

SHARE_SRCS		=	${addprefix ${SHARE_DIR}, ${SHARE_SRCNAME}}
SHARE_OBJS		=	${SHARE_SRCS:.c=.o}

######### CLIENT PART #########
CLIENT_DIR	=		./srcs_client/
CLIENT_SRCNAME	=	\
					main.c\

CLIENT_SRCS	=	${addprefix ${CLIENT_DIR}, ${CLIENT_SRCNAME}}
CLIENT_NAME	=	client
CLIENT_OBJS	=	${CLIENT_SRCS:.c=.o}

######### SERVER PART #########
SERVER_DIR = 	./srcs_server/
SERVER_SRCNAME	=	\
						main.c\

SERVER_SRCS		=	${addprefix ${SERVER_DIR}, ${SERVER_SRCNAME}}
SERVER_NAME		=	server
SERVER_OBJS		=	${SERVER_SRCS:.c=.o}


######### COMMON ORDER PART ########
INCDIR		=		./includes/

CC			=		gcc
CF			=		-Wall -Wextra -Werror

all			:		${CLIENT_NAME} ${SERVER_NAME}

.c.o		:
					${CC} ${CF} -c $< -o ${<:.c=.o} -I${INCDIR}

${CLIENT_NAME}		:	${CLIENT_OBJS} ${SHARE_OBJS}
					${CC} ${CF} ${CLIENT_OBJS} ${SHARE_OBJS} -o ${CLIENT_NAME}

${SERVER_NAME}	:	${SERVER_OBJS} ${SHARE_OBJS}
					${CC} ${CF} ${SERVER_OBJS} ${SHARE_OBJS} -o ${SERVER_NAME}

fclean		:		cclean sclean
					rm -f ${CLIENT_NAME}
					rm -f ${SERVER_NAME}

cclean		:		
					rm -f ${CLIENT_OBJS}
					rm -f ${SHARE_OBJS}

sclean		:
					rm -f ${SERVER_OBJS}
					rm -f ${SHARE_OBJS}

clean		:		cclean sclean

re			:		fclean all