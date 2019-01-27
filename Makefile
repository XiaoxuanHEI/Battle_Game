CC=g++

SRCS=main.cpp

OBJS=$(SRCS:.cpp=.o)

EXEC=aow

start:$(OBJS)
	$(CC) -o $(EXEC) $(OBJS)

.cpp.o:
	$(CC) -o $@ -c $<

clean:
	rm -rf $(OBJS)

