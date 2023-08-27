NAME_APP = main
LIB_NAME = libmain.a
TEST_NAME = $(NAME_APP)-test

CC = g++
CFLAGS = -Wall -Werror
DEPSFLAGS = -MMD

OBJ_DIR = obj
BIN_DIR = bin
APP_DIR = src/app
LIB_DIR = src/libapp
TEST_DIR = test
LIB_TEST_DIR = libtest

APP_PATH = $(BIN_DIR)/$(NAME_APP)
LIB_PATH = $(OBJ_DIR)/$(LIB_DIR)/$(LIB_NAME)
TEST_PATH = $(BIN_DIR)/$(TEST_NAME)

APP_SRC = $(wildcard $(APP_DIR)/*.cpp) # Все файлы с расширением .c нужно найти в текущей директории
LIB_SRC = $(wildcard $(LIB_DIR)/*.cpp)
TEST_SRC = $(wildcard $(TEST_DIR)/*.c)
APP_OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(APP_SRC)) # Из .c заменяет в .o, SRC - какой список файлов
LIB_OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(LIB_SRC))
TEST_OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(TEST_SRC))
APP_DEPS = $(patsubst $(APP_OBJ), $(OBJ_DIR)/%.d, $(APP_OBJ)) # Из .o заменяет в .d
LIB_DEPS = $(patsubst $(LIB_OBJ), $(OBJ_DIR)/%.d, $(LIB_OBJ))
TEST_DEPS = $(patsubst $(TEST_OBJ), $(OBJ_DIR)/%.d, $(TEST_OBJ))

all: $(APP_PATH)

$(APP_PATH): $(APP_OBJ) $(LIB_PATH)
	$(CC) -I $(LIB_DIR) $^ -o $@ -lgdi32 -lmingw32

$(LIB_PATH): $(LIB_OBJ)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(DEPSFLAGS) -I $(LIB_DIR) -c $< -o $@ -lgdi32 -lmingw32

clean:
	rm $(APP_PATH) $(OBJ_DIR)/$(APP_DIR)/*.* $(OBJ_DIR)/$(LIB_DIR)/*.*
	rm $(TEST_PATH) $(OBJ_DIR)/$(TEST_DIR)/*.*

run: 
	$(BIN_DIR)/$(NAME_APP)

test: $(TEST_PATH)
	$(BIN_DIR)/$(TEST_NAME)

$(TEST_PATH): $(OBJ_DIR)/$(TEST_DIR)/main.o $(OBJ_DIR)/$(TEST_DIR)/ctest.o 
	$(CC) -I $(LIB_DIR) -I $(LIB_TEST_DIR) $^ $(LIB_PATH) -o $(BIN_DIR)/$(TEST_NAME) -lgdi32 -lmingw32

$(OBJ_DIR)/$(TEST_DIR)/main.o: $(TEST_DIR)/main.c
	$(CC) $(CFLAGS) $(DEPSFLAGS) -I $(LIB_TEST_DIR) -c $< -o $@

$(OBJ_DIR)/$(TEST_DIR)/ctest.o: $(TEST_DIR)/ctest.c
	$(CC) $(CFLAGS) $(DEPSFLAGS) -I $(LIB_DIR) -I $(LIB_TEST_DIR) -c $< -o $@

format: 
	clang-format -i --verbose $(APP_SRC) $(LIB_SRC)

-include $(LIB_DEPS) $(APP_DEPS) $(TEST_DEPS)

.PHONY: all run clean test format
