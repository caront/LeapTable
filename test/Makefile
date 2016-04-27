NAME		=	test

SRC		= 		main.cpp\

				

OBJ		=       $(SRC:.cpp=.o)

LDFLAGS		+=	-lapileap -L ../api_leap/lib 

CXXFLAGS	+=	-Wall -ggdb3 -std=c++11 -I ../api_leap/include

CXX			=	clang++

all			:	$(NAME) 

$(NAME)		:	$(OBJ)
				$(CXX) $^ -o $@ $(LDFLAGS)

clean		:
				rm -vf $(OBJ) 

fclean		:	clean
				rm -vf $(NAME)

re			:	fclean all

.PHONY		:	clean fclean re
