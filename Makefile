# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/26 16:00:22 by tefroiss          #+#    #+#              #
#    Updated: 2021/12/27 00:39:49 by tefroiss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	push_swap

SRCS		=	srcs/list.c \
				srcs/list_push.c \
				srcs/swap.c \
				srcs/all_rotate.c \
				srcs/check_list.c \
				srcs/which_action.c \
				utils/str_n_arg.c \
				utils/ft_split.c 
				
MAIN 		= 	srcs/main.c

OBJS_MAIN 	= 	$(MAIN:.c=.o)
OBJS		=	$(SRCS:.c=.o)

CC			=	clang

CFLAGS		+=	-Wall -Wextra -Werror

RM			=	rm -f

CLEAN		=	clean

INCLUDES	=	./includes/push_swap.h

#########################################################################################
#										MAKE											#
#########################################################################################

%.o			:	%.c ${INCLUDES}
				$(CC) $(CFLAGS) -c $< -o $@

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(OBJS_MAIN)
				${CC} ${CFLAGS} ${OBJS} ${OBJS_MAIN} -o ${NAME}

clean		:
				$(RM) $(OBJS)
				$(RM) ${OBJS_MAIN}

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re