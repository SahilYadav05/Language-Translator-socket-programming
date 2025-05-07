#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void real_translate(const char* text, char* result, const char* src_lang, const char* tgt_lang) {
    char command[2048];
    FILE* fp;

    snprintf(command, sizeof(command),
             "python3 translate.py %s %s \"%s\"", src_lang, tgt_lang, text);

    fp = popen(command, "r");
    if (fp == NULL) {
        strcpy(result, "Translation failed.");
        return;
    }

    fgets(result, BUFFER_SIZE, fp);
    pclose(fp);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char result[BUFFER_SIZE] = {0};
    char src_lang[10], tgt_lang[10];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 3);

    printf("Server is listening on port %d...\n", PORT);

    new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);

    recv(new_socket, src_lang, sizeof(src_lang), 0);
    recv(new_socket, tgt_lang, sizeof(tgt_lang), 0);
    recv(new_socket, buffer, BUFFER_SIZE, 0);

    printf("Request: [%s -> %s] %s\n", src_lang, tgt_lang, buffer);

    real_translate(buffer, result, src_lang, tgt_lang);

    send(new_socket, result, strlen(result), 0);

    close(new_socket);
    close(server_fd);

    return 0;
}
