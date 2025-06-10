
CC= gcc
DEBUGFLAG = -g -ffile-prefix-map=$(CURDIR)=.
LDFLAG = -lm
ROOT = dr-files
ARG =


INC= $(ROOT)/include
CFlags= -Wall -I$(INC)
SRC= $(ROOT)/src
EXE= $(ROOT)/bin/main
OBJ= $(ROOT)/obj


C_FILES=$(wildcard $(SRC)/*/*.c) main.c
PROG_OBJ=$(patsubst $(SRC)/%.c,$(OBJ)/%.o, $(C_FILES))


CC_CALL= $(CC) $(CFlags) $(DEBUGFLAG)
 
target: build
 
build: $(PROG_OBJ) main.o
	$(CC_CALL) $(PROG_OBJ) -o $(EXE) $(LDFLAG)

$(OBJ)/%.o:$(SRC)/%.c
	$(CC_CALL) -c $< -o $@

main.o: main.c
	$(CC_CALL) -c $< -o $(OBJ)/$@

execute:
	./$(EXE) $(ARG)

access:
	sudo ./$(EXE)

debug:
	gdb ./$(EXE)
clean:
	rm -f $(OBJ)/*/*.o main.o
