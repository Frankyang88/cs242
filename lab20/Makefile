

CC=gcc

CFLAGS=-ansi -pedantic -lm -W -Wall -O2 -g -c 


SOURCE1 = ./lab20a/*.c 

SOURCE2 = ./lab20b/*.c   

SOURCE3 = ./lab20c/*.c
	
OBJ1 = amain.o  
OBJ2 = bmain.o
OBJ3 = cmain.o

TARGET1= lab20a.o
TARGET2= lab20b.o
TARGET3= lab20c.o

$(TARGET1): $(SOURCE1)
	$(CC) $(SOURCE1)  $(CFLAGS) -o $(OBJ1)
	$(CC) -o $(TARGET1) $(OBJ1)
	chmod +x $(TARGET1)

$(TARGET2): $(SOURCE2)
	$(CC) $(SOURCE2) $(CFLAGS) -o $(OBJ2)
	$(CC) -o $(TARGET2) $(OBJ2)
	chmod +x $(TARGET2)
 
$(TARGET3): $(SOURCE3)
	$(CC) $(SOURCE3) $(CFLAGS) -o $(OBJ3)
	$(CC) -o $(TARGET3) $(OBJ3)
	chmod +x $(TARGET3) 


clean:
	rm -rf *.o 
	rm -rf tree-main
	rm -rf htable-main
