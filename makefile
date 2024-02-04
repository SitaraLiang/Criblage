SRC_DIR := src
INCLUDE_DIR := include
OBJ_DIR := obj
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
CC = gcc
CFLAGS = -g -Wall
DOCGEN = doxygen
EXEC = main 

all: $(EXEC) doc archive

$(EXEC): $(OBJS)
	$(CC) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	$(CC) -c $< -o $@ -I$(INCLUDE_DIR) 

doc:
	$(DOCGEN)

archive:
	tar cfJ archive.tar.xz $(SRC_DIR) $(INCLUDE_DIR) $(OBJ_DIR) Doxyfile

clean:
	rm -rf $(OBJ_DIR)/*.o $(EXEC) doc archive.tar archive
