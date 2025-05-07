#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char src_lang[10], tgt_lang[10], text[BUFFER_SIZE];
    char translated[BUFFER_SIZE] = {0};

    // Get input from user
    printf("Enter source language (e.g., en): ");
    scanf("%s", src_lang);
    printf("Enter target language (e.g., es): ");
    scanf("%s", tgt_lang);
    getchar();  // clear newline
    printf("Enter text to translate: ");
    fgets(text, BUFFER_SIZE, stdin);
    text[strcspn(text, "\n")] = 0;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    // Send language codes and text
    send(sock, src_lang, sizeof(src_lang), 0);
    send(sock, tgt_lang, sizeof(tgt_lang), 0);
    send(sock, text, strlen(text) + 1, 0);

    // Receive translated result
    recv(sock, translated, BUFFER_SIZE, 0);
    printf("\nTranslated Text: %s\n", translated);

    close(sock);
    return 0;
}
