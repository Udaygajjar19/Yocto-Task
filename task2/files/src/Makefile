all:	build 
EXE_NAME = helloworld
CC=gcc
file1=helloworld.c
#file2=
#file1_o=$(file1:.c=.o)
#file2_o=$(file2:.c=.o)

build: 
	
	$(CC)  $(file1)  -o $(EXE_NAME)

#$(file1_o):
#	$(CC)  -c $(file1)

#$(file2_o).o:
#       $(CC) -w -c $(file2)

execute:
	./$(EXE_NAME)

clean:
	rm -f *.o
	rm -f $(EXE_NAME)
#%.o:   %.c
#       $(CC) -c $< -o $@
