# Variáveis de Compilação
CC       := gcc
CFLAGS   := -Wall -Wextra -Werror -std=c11 -Iinclude -g -O0
TARGET   := bin/hello
VALGRIND := valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes

# Caminhos
SRC_DIR  := src
OBJ_DIR  := obj
BIN_DIR  := bin

# Localiza todos os arquivos .c em src/ e gera os nomes para .o em obj/
SRC      := $(wildcard $(SRC_DIR)/*.c)
OBJ      := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

.PHONY: all run check clean

all: $(TARGET)

# Linkagem (Cria a pasta bin/ se não existir)
$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	@echo "🔗 Linkando: $@"
	@$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

# Compilação (Cria a pasta obj/ se não existir)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "🔨 Compilando: $<"
	@$(CC) $(CFLAGS) -c $< -o $@

run: all
	@echo "🚀 Executando..."
	@./$(TARGET)

check: all
	@echo "🔍 Analisando memória..."
	@$(VALGRIND) ./$(TARGET)

clean:
	@echo "🧹 Limpando..."
	@rm -rf $(OBJ_DIR) $(BIN_DIR)