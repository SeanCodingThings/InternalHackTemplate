PROJECT_NAME = VaxMenu
CC = gcc
CXX = -std=c17
SRC_PATH = src
SRC_FILES = $(wildcard $(SRC_PATH)/*.c)
OBJ_PATH = build
OBJ_FILES = $(patsubst $(SRC_PATH)/%.c,$(OBJ_PATH)/%.o,$(SRC_FILES))
CFLAGS_RELEASE = -s -O2 ${CXX} -shared -o
CFLAGS_DEBUG = -ggdb ${CXX} -Wall -Wextra -shared -o

# Targets
all: release

release: CFLAGS = $(CFLAGS_RELEASE)
release: $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(PROJECT_NAME).dll $(OBJ_FILES)
	@echo "Release build completed successfully."

debug: CFLAGS = $(CFLAGS_DEBUG)
debug: $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(PROJECT_NAME)_debug.dll $(OBJ_FILES)
	@echo "Debug build completed successfully."

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $@ -c $<

$(OBJ_PATH):
	@mkdir -p $@

clean:
	@rm -rf $(OBJ_PATH) $(PROJECT_NAME).dll $(PROJECT_NAME)_debug.dll
	@echo "Clean completed successfully."

.PHONY: all release debug clean
