traget:build
	$(CC_CALL) -w  -c $(FUNCTION)
	$(CC_CALL) -w  -c $(MAIN)
	$(CC_CALL)  $(MAIN_O) $(FUNCTION_O) -o $(EXE_NAME)
EXE_NAME = output
CC = gcc 
CCFLAGS= 
CC_CALL= $(CC)$(CCFLAGS)

#EXAMPLE=17
MAIN=main.c
BUILD=/home/bhavik_23/yocto/meta-bhavik/recipes-intern/dr2/files/src/build/
BIN=/home/bhavik_23/yocto/meta-bhavik/recipes-intern/dr2/files/src/bin/
BINFILE=executable
FUNCTION=dennisR_module2_function_*.c
MAIN_O=main.o
FUNCTION_O=dennisR_module2_function_*.o


build:	
	$(CC_CALL)  $(MAIN) $(FUNCTION) -o $(EXE_NAME) 

$(MAIN_O):
	$(CC_CALL) -w  -c $(MAIN) 

$(FUNCTION_O):
	$(CC_CALL) -w  -c $(FUNCTION)

objfile:
	mv $(FUNCTION_O) $(BUILD)
	

binfile:
	cp $(EXE_NAME) $(BINFILE)
	mv $(BINFILE) $(BIN)

execute:	
	./$(EXE_NAME)

clean:
	rm -f *.o
	rm -f $(EXE_NAME)

cleanbuild:
	rm build/*.o
#%.o:	%.c
#	$(CC) -c $< -o $@
