
all: server client

server: $(OBJ_DIR)/server.o $(COMMON_OBJ)
        $(CC) $(CFLAGS) $^ -o $@

client: $(OBJ_DIR)/client.o $(COMMON_OBJ)
        $(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
        $(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
        mkdir -p $(OBJ_DIR)

clean:
        rm -rf $(OBJ_DIR) server client