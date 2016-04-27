CC = clang++

DEBUG = yes

ifeq ($(DEBUG),yes)
	CXXFLAGS = -Wall -g -std=c++11
	LDFLAGS = -Wall -g -lm -ltinyxml2 -lsfml-graphics -lsfml-audio -lsfml-system -lsfml-window -L /usr/local/lib
else
	CXXFLAGS = -Wall -std=c++11
	LDFLAGS = -Wall -lm -lsfml-graphics  -ltinyxml2 -lsfml-audio -lsfml-system -lsfml-window -L /usr/local/lib
endif


NAME = libapileap.so

INCPATH = ./include

SRCPATH = ./source

LIBPATH = ./lib

BINPATH = ./bin

OBJPATH = $(SRCPATH)

OUT = $(LIBPATH)/$(NAME)

INCLUDES = -I $(INCPATH)

SRCLIB = 	$(SRCPATH)/CallBackListener.cpp\
		$(SRCPATH)/Controller.cpp\
		$(SRCPATH)/Log.cpp\
		$(SRCPATH)/Page.cpp\
		$(SRCPATH)/UIObject.cpp\
		$(SRCPATH)/UIText.cpp\
		$(SRCPATH)/CollectionElement.cpp\
		$(SRCPATH)/PageConstructor.cpp\
		$(SRCPATH)/UIButton.cpp\
		$(SRCPATH)/UIObjectList.cpp\
		$(SRCPATH)/UIWindow.cpp\
		$(SRCPATH)/Core.cpp\
		$(SRCPATH)/UIButtonCircle.cpp\
		$(SRCPATH)/WindowXMlReader.cpp\
		$(SRCPATH)/CallBack.cpp\
		$(SRCPATH)/ScreenInfo.cpp\
		$(SRCPATH)/EventListener.cpp\


SRC = $(SRCLIB) $(SRCTINY)

OBJ = $(SRC:.cpp=.o)


default: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(LDFLAGS) -shared -o $@ $^

$(OBJPATH)/%.o: $(SRCPATH)/%.cpp 
	$(CC) $(CXXFLAGS) $(INCLUDES) -fpic -c $< -o $@

.PHONY: clean cleanall

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OUT)

re : fclean default