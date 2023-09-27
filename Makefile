NAME_APP = main
LIB_NAME = libmain.a
TEST_NAME = test

CC = g++
CFLAGS = -Wall -Werror -MMD

OBJ_DIR = obj
BIN_DIR = bin
APP_DIR = src
LIB_DIR = libmain
TEST_DIR = test

APP_SRC = $(wildcard $(APP_DIR)/*.cpp)
LIB_SRC = $(wildcard $(LIB_DIR)/*.cpp)
TEST_SRC = $(wildcard $(TEST_DIR)/*.cpp)

APP_OBJ = $(patsubst $(APP_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(APP_SRC))
LIB_OBJ = $(patsubst $(LIB_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(LIB_SRC))
TEST_OBJ = $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(TEST_SRC))

APP_DEPS = $(patsubst %.o,%.d,$(APP_OBJ))
LIB_DEPS = $(patsubst %.o,%.d,$(LIB_OBJ))
TEST_DEPS = $(patsubst %.o,%.d,$(TEST_OBJ))

APP_PATH = $(BIN_DIR)/$(NAME_APP).exe
LIB_PATH = $(BIN_DIR)/$(LIB_NAME)
TEST_PATH = $(BIN_DIR)/$(TEST_NAME).exe

all: compile $(LIB_PATH) link

compile: $(APP_OBJ) $(LIB_OBJ) $(TEST_OBJ)

$(LIB_PATH): $(OBJ_DIR)/$(LIB_DIR)/sbros.o
    ar rcs $@ $<

link: $(OBJ_DIR)/$(APP_DIR)/main.o $(OBJ_DIR)/$(LIB_DIR)/sbros.o
    $(CC) -o $(APP_PATH) $^ -lgdi32 -lmingw32

clean:
    rm -rf $(OBJ_DIR)/* $(BIN_DIR)/*

run:
    $(APP_PATH)

test: $(TEST_PATH)

$(TEST_PATH): $(TEST_OBJ) $(LIB_PATH)
    $(CC) -o $@ $^

$(OBJ_DIR)/$(TEST_DIR)/ctest.o: $(TEST_DIR)/main1.c
    $(CC) $(CFLAGS) -c -o $@ $<

format:
    clang-format -i $(APP_SRC) $(LIB_SRC) $(TEST_SRC)

-include $(APP_DEPS) $(LIB_DEPS) $(TEST_DEPS)

.PHONY: all compile link clean run test format