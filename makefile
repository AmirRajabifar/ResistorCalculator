DEP_DIR = .d
INC_DIR = Headers
SRC_DIR = Sources
OBJ_DIR = Objects

$(shell mkdir -p $(DEP_DIR) >/dev/null)
$(shell mkdir -p $(OBJ_DIR) >/dev/null)

#CFLAGS = -c -Wall -I. -IHeaders
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.Td
CFLAGS = -c -Wall -I. -IHeaders
CC = gcc

OUTPUT_OPTION = -o $@

SRCS = $(SRC_DIR)/*.c 
OBJS = $(OBJ_DIR)/*.o


COMPILE.c = $(CC) $(DEPFLAGS) $(CFLAGS) 
POSTCOMPILE = mv -f $(DEP_DIR)/$*.Td $(DEP_DIR)/$*.d

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEP_DIR)/%.d
	$(COMPILE.c) $< $(OUTPUT_OPTION)
	#$(CC) $(CFLAGS) $(DEPFLAGS) $< -o $@
	$(POSTCOMPILE)

$(DEP_DIR)/%.d: ;
.PRECIOUS: $(DEP_DIR)/%.d

output: $(OBJS)
	$(CC) $^ -o $@

-include $(patsubst %,$(DEP_DIR)/%.d,$(basename $(SRCS)))

run: output
	./output

.PHONY: clean
clean: 
	rm -r $(OBJ_DIR) 
	rm -r $(DEP_DIR) 
	rm output
	-@echo "Clean completed"
