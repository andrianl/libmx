# ======== variables ========
NAME := libmx.a

# -- files and dirs --
INC_DIR := inc
OBJ_DIR := obj
SRC_DIR := src

INC_FILES := $(wildcard $(INC_DIR)/*.h)
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_FILES:%.c=%.o)))

# -- commands --

RM := rm -rdf
MKDIR := mkdir -p

CC := clang
WFLAGS = -Wall -Wextra -Werror -Wpedantic
DFLAGS = -O2 -g3 -ftrapv -fstandalone-debug
HFLAGS = -I$(INC_DIR)


COMPILE = $(CC) -std=c11 -pipe $(WFLAGS) $(HFLAGS)

# ========== body =========

all: ${NAME}

${NAME}: $(OBJ_FILES)
	@ar rcs $(NAME) $(OBJ_FILES)

$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
	@$(CC) $(CFLAGS) -c $< -I $(INC_DIR) -o $@

$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)

clean:
	@$(RM) $(OBJ_DIR)

uninstall: clean
	@$(RM) $(NAME)

reinstall: uninstall all

.PHONY: all uninstall clean reinstall