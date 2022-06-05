/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** main
*/

#ifndef MAIN_H_
    #define MAIN_H_

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdbool.h>

    #include <sys/stat.h>
    #include <sys/time.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <dirent.h>

typedef struct client {
    int fd;
    char *username;
    char *password;
    bool is_logged;
    bool is_root;
    char *path;
    char *input;
    struct client *next;
}client_t;

typedef struct serv {
    int fd;
    int port;
    char *path;
    char *c_path;
    struct sockaddr_in *sock_in;
    socklen_t sock_in_size;
}serv_t;

typedef struct data_t {
    int nb_max_fd;
    int nb_clients;
    serv_t *serv;
    client_t *all_clients;
    fd_set all_fd_clients;
    fd_set tmp_fd_clients;
}datas_t;

typedef void (*command)(int fd, datas_t *, client_t *);

/* Server Functions */
int server_ftp(datas_t *datas);
int server_manager(datas_t *st);

int accept_connection(int socket_fd);
char *read_client(int client_fd);
int receive_data(int client_fd, char *buffer, int buffer_size);
int send_data(int client_fd, char *buffer, int buffer_size);
int close_connection(int client_fd);

/* Linked List Functions */
client_t *add_node(client_t *list, int fd, char *path);
client_t *remove_node(client_t *list, int fd_to_rm);
int count_nodes(client_t *list);
void fill_client(client_t *node, int fd, char *path);
void print_list(client_t *list);
client_t *get_client_by_fd(client_t *list, int fd);
void maybe_remove(client_t *list, client_t *tmp, int fd_to_rm, client_t *prev);

/* Client Functions */
int client_manager(datas_t *st);

/* Commands Functions */
void exec_cwd(int fd, datas_t *st, client_t *client);
void exec_pwd(int fd, datas_t *st, client_t *client);
void exec_quit(int fd, datas_t *st, client_t *client);
void exec_noop(int fd, datas_t *st, client_t *client);
void exec_user(int fd, datas_t *st, client_t *client);
void exec_pass(int fd, datas_t *st, client_t *client);
void exec_cdup(int fd, datas_t *st, client_t *client);
void exec_dele(int fd, datas_t *st, client_t *client);
void exec_pasv(int fd, datas_t *st, client_t *client);
void exec_port(int fd, datas_t *st, client_t *client);
void exec_help(int fd, datas_t *st, client_t *client);
void exec_retr(int fd, datas_t *st, client_t *client);
void exec_stor(int fd, datas_t *st, client_t *client);
void exec_list(int fd, datas_t *st, client_t *client);

/* errors */
int help(int ac, char **av);
int check_int(char *str);
int check_path(char *path);
int error(int ac, char **av);

/* Utils */
int count_args(char *str);
char *remove_last_char(char *str);
char **str_to_word_array(char *str);

/* Init & Free */
int init_socket(datas_t *datas);
int init_datas(datas_t *datas, char **av);

void free_datas(datas_t *datas);
void free_server(serv_t *datas);
void free_client(client_t *list);
void free_clients(client_t *list);
void free_2d_array(char **array);

#endif /* !MAIN_H_ */
