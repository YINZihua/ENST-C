## Definifion of variables

CC		= gcc
LD		= gcc
AR		= ar
RM		= rm

SRC_DIR		= /src
LIB_DIR		= /lib
INCLUDE_DIR	= /inc

CFLAGS		= -c -Wall 
LDFLAGS		= -g -lc

LIB_FILES 	= linked_list_utils

EXEC_NAME	= linked-list-exe


## Target liblinked-list-utils.a
## archive linked-list.o into library liblinked-list-utils.a
liblinked-list-utils.a:	linked-list.o
	AR -r lib$(LIB_FILES).a linked-list.o


## Target main.o
## compile main.c to produce an object file (main.o)
main.o: .$(SRC_DIR)/main.c
	CC -Wall -c -L.$(SRC_DIR) main.c


## Target linked-list.o
## compile linked-list.c to produce an object file (linked-list.o)
linked-list.o: .$(SRC_DIR)/linked-list.c
	CC -Wall -c -L./$(SRC_DIR) linked-list.c

## Target $(EXEC_NAME)
## link liblinked-list-utils.a and main.o to produce the executable (linked-list-exe)
$(EXEC_NAME): .$(LIB_DIR)/lib$(LIB_FILES).a
	gcc -Wall main.o -L.$(LIB_DIR) $(LIB_FILES) -o $(EXEC_NAME)


## Target all: Useful? Where should be put in the makefile? 
all: $(EXEC_NAME) liblinked-list-utils.a




## Target clean
clean:
	$(RM) *.o $(LIB_DIR)/*.a $(EXEC_NAME)
