NAME		=	./LeapMousseDemon

SRC_CORE = 		Classes/Core/Core.cpp\
				Classes/Core/Controler.cpp\
				Classes/Core/GetWindowsID.cpp\
				Classes/Core/Prosse.cpp\
				Classes/Core/CoreShared.cpp\

SRC_OUTPUT =	Classes/Output/Output.cpp\

SRC_GESTUAl = 	Classes/Gestual/Gesture.cpp\
				Classes/Gestual/LeftSlide.cpp\
				Classes/Gestual/GestureList.cpp\
				Classes/Gestual/DownSlide.cpp\
				Classes/Gestual/UpSlide.cpp\
				Classes/Gestual/RightSlide.cpp\
				Classes/Gestual/TopSlide.cpp\
				Classes/Gestual/BottomSlide.cpp\
				Classes/Gestual/Pointer.cpp\
				Classes/Gestual/Tap.cpp\
				Classes/Gestual/Rotation.cpp\
				
SRC_MAIN = 		main.cpp

SRC		= 		$(SRC_MAIN)\
				$(SRC_CORE)\
				$(SRC_OUTPUT)\
				$(SRC_GESTUAl)\
				

OBJ		=       $(SRC:.cpp=.o)


LDFLAGS		+=	-lm /lib64/libLeap.so -L usr/local/lib

CXXFLAGS	+=	 -std=c++11 -Wall -ggdb3 -I ./lib -I ../common -I ./Classes/Core -I ./Classes/Gestual -I ./Classes/Output

CXX		=	clang++

all		:	$(NAME) 

$(NAME)		:	$(OBJ)
			$(CXX) $^ -o $@ $(LDFLAGS)

clean		:
			rm -vf $(OBJ) 

fclean		:	clean
			rm -vf $(NAME)

re		:	fclean all

.PHONY		:	clean fclean re
