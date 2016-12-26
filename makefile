
INC_DIR = Headers
SRC_DIR = Sources
OBJ_DIR = Objects
#CXXFLAGS = -c -Wall -I. -IHeaders
$(shell mkdir -p $(OBJ_DIR) >/dev/null)

CXXFLAGS = -c -Wall -I. -IHeaders
CC = g++

SRCS = $(SRC_DIR)/*.cpp 
OBJS = $(OBJ_DIR)/*.o
#The wildcard and patsubt commads will come handy

DEPS = $(INC_DIR)/*.h
#need to use an automatic dependency generator

resistor: $(OBJ_DIR)/main.o $(OBJ_DIR)/Resistor.o
	$(CC) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS)
	$(CC) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean: 
	rm -r $(OBJ_DIR) 
	#rm -r $(DEP_DIR) 
	rm resistor
	-@echo "Clean completed"
