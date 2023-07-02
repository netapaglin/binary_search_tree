TARGET= bst.out
CC= gcc
CFLAGS= -ansi -g -pedantic 
OBJS= genBST.o genBSTTest.o 

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
	
genBSTo: genBST.h genBST.c 
	$(CC) $(CFLAGS) -c genBST.c
	
genBSTTest.o: genBSTTest.c genBST.h 
	$(CC) $(CFLAGS) -c genBSTTest.c
	
clean:
	rm -f $(TARGET) $(OBJS)

