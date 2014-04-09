OBJS= parser.o mpc.o
PROGRAM= lisp
INCLUDE= -I../includes
LIBRARIES= edit
CC= cc
CFLAGS= -std=c99 -Wall

all: $(PROGRAM)

$(PROGRAM): $(OBJs)
			$(CC) $(CFLAGS) $(INCLUDE) -o $(PROGRAM) $(OBJS)

%.o:	src/%.c
		$(CC) $(CFLAGS) -o $@ $(INCLUDE) -c $<
	
clean: rm -f $(PROGRAM) $(OBJS)

