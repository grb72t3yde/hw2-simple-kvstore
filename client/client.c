#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <ctype.h>
#include <stdlib.h>

#include "sock.h"

int main(int argc, char **argv)
{
    int opt;
    char *server_host_name, *server_port;

    /* Parsing args */
    while ((opt = getopt(argc, argv, "h:p:")) != -1) {
        switch (opt) {
        case 'h':
            server_host_name = malloc(strlen(optarg) + 1);
            strncpy(server_host_name, optarg, strlen(optarg));
        case 'p':
            server_port = malloc(strlen(optarg) + 1);
            strncpy(server_port, optarg, strlen(optarg));
            break;
        case '?':
            fprintf(stderr, "Unknown option \"-%c\"\n", isprint(optopt) ?
                    optopt : '#');
            return 0;
        }
    }

    /* Open a client socket fd */
    int clientfd __attribute__((unused)) = open_clientfd(server_host_name, server_port);

    /* Start your coding client code here! */

    return 0;
}
