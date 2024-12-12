NAME	:=	libMatrixOperand.so

HEADERDIR	:=	include
BUILDDIR	:=	build
SOURCEDIR 	:=	src
SOURCES	:=	$(shell find $(SOURCEDIR) -name '*.c')
HEADERS	:=	$(shell find $(HEADERDIR) -name '*.h')
OBJECTS	:=	$(SOURCES:.c=.o)

FLAGS 		:=	-Iinclude
CPPFLAGS	:=	-Iinclude -fPIC -Wall -Wextra -Werror -g
LDFLAGS		:=	-shared

CC	:=	gcc

all:	$(NAME)

clean:
	rm -f $(OBJECTS)

clean_all:
	rm -f $(OBJECTS) $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(CPPFLAGS) -o $(NAME) $(OBJECTS) $(LDFLAGS)