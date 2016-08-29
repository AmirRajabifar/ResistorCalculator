INC_DIR = Headers
SRC_DIR = Sources
OBJ_DIR = Objects
#CXXFLAGS = -c -Wall -I. -IHeaders
CXXFLAGS = -c -Wall -I. -IHeaders
CC = gcc

SRCS = $(SRC_DIR)/*.c 
OBJS = $(OBJ_DIR)/*.o
#The wildcard and patsubt commads will come handy

DEPS = $(INC_DIR)/*.h
#need to use an automatic dependency generator

output: $(OBJ_DIR)/main.o $(OBJ_DIR)/function.o
	$(CC) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) $(CXXFLAGS) $< -o $@


run: output
	./output

clean: 
	rm $(OBJ_DIR)/*.o 
	rm output
	-@echo "Clean completed"