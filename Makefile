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

APP_SRC = $(wildcard $(APP_DIR)/*.cpp) # Все файлы с расширением .c/.cpp нужно найти в текущей директории
LIB_SRC = $(wildcard $(LIB_DIR)/*.cpp)
TEST_SRC = $(wildcard $(TEST_DIR)/*.c)
APP_OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(APP_SRC)) # Из .c/.cpp заменяет в .o, SRC - какой список файлов
LIB_OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(LIB_SRC))
TEST_OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(TEST_SRC))
APP_DEPS = $(patsubst $(APP_OBJ), $(OBJ_DIR)/%.d, $(APP_OBJ)) # Из .o заменяет в .d
LIB_DEPS = $(patsubst $(LIB_OBJ), $(OBJ_DIR)/%.d, $(LIB_OBJ))
TEST_DEPS = $(patsubst $(TEST_OBJ), $(OBJ_DIR)/%.d, $(TEST_OBJ))

all: compile libmain.a link

compile:
	g++ -Isrc/libapp -c src/app/main.cpp -o obj/main.o -lgdi32 -lmingw32
	g++ -Isrc/libapp -c src/libapp/sbros.cpp -o obj/sbros.o -lgdi32 -lmingw32

libmain.a:obj/sbros.o
	ar rcs $@ $^

link:
	g++ obj/main.o obj/sbros.o -o bin/main.exe -lgdi32 -lmingw32

clean:
	rm $(APP_PATH) $(OBJ_DIR)/$(APP_DIR)/*.* $(OBJ_DIR)/$(LIB_DIR)/*.*
	rm $(TEST_PATH) $(OBJ_DIR)/$(TEST_DIR)/*.*

run: 
	$(BIN_DIR)/$(NAME_APP)

test: $(TEST_PATH)
	$(BIN_DIR)/$(TEST_NAME)

$(TEST_PATH): $(OBJ_DIR)/$(TEST_DIR)/main.o $(OBJ_DIR)/$(TEST_DIR)/ctest.o 
	$(CC) -I $(LIB_PATH) -I $(LIB_DIR) -I $(LIB_TEST_DIR) $^ -o $(BIN_DIR)/$(TEST_NAME) -lm -lgdi32 -lmingw32

$(OBJ_DIR)/$(TEST_DIR)/main.o: $(TEST_DIR)/main.c
	$(CC) $(CFLAGS) $(DEPSFLAGS) -I $(LIB_TEST_DIR) -c $< -o $@

$(OBJ_DIR)/$(TEST_DIR)/ctest.o: $(TEST_DIR)/main1.c
	$(CC) $(CFLAGS) $(DEPSFLAGS) -I $(LIB_DIR) -I $(LIB_TEST_DIR) -c $< -o $@

format: 
	clang-format -i --verbose $(APP_SRC) $(LIB_SRC)

-include $(LIB_DEPS) $(APP_DEPS) $(TEST_DEPS)

.PHONY: all run clean test format
