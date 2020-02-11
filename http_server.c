#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
int main ()
{	
	//Open HTML File to serve
	FILE *html_data;
	html_data = fopen("index.html", "r");
	
	//Read HTML File data
	char response_data[1024];
	fgets(response_data, 1024, html_data);

	//Response Header
	char http_header[2048] = "HTTP/1.1 200 OK\r\n\n";
	strcat(http_header, response_data);

	//Create a socket
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	//Define the Address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(8001);
	server_address.sin_addr.s_addr = INADDR_ANY;

	bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

	listen(server_socket, 5);

	int client_socket;
	while(1)
	{
		//Accept Client Socket
		client_socket = accept(server_socket, NULL, NULL);
		//Send data back to client
		send(client_socket, http_header, sizeof(http_header), 0);
		close(client_socket);
	}
	


	return 0;

}