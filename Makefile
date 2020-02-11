TARGET = client server
CC = gcc
CFLAGS = -Wall -Wextra -g
normal: $(TARGET)

client: http_client.c
	$(CC) $(CFLAGS) http_client.c -o client
server: http_server.c
	$(CC) $(CFLAGS)  http_server.c -o server
clean:
	$(RM) $(TARGET)
