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
    #include <fcntl.h>
    #include <dirent.h>
    #include <errno.h>

    #include "../../libs/my/libmy.h"
    #include "../../libs/myteams/logging_client.h"
    #include "../../libs/myteams/logging_server.h"

/**
** @brief Structure with all infos about the client
**
** @param fd The file descriptor of the client
** @param port The username of the client
** @param is_logged True if the client is logged in
** @param ip The ip of the client
** @param path The password of the client
** @param input The input of the client
** @param username The username of the client
** @param current_dir The current directory of the client
** @param sock_in The structure of the client's socket address
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
typedef struct client {
    int fd;
    int port;
    char *ip;
    char *path;
    char *uuid;
    char *input;
    bool is_logged;
    char *username;
    char *current_dir;
    struct sockaddr_in *sock_in;
} client_t;

/**
** @brief Structure with all datas for the client implementation
**
** @param client The structure containing all infos about the client
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
typedef struct data_t {
    int max_fd;
    fd_set my_fd;
    client_t *client;
} datas_t;

typedef void (*reply)(datas_t *);
typedef void (*store)(datas_t *, char *buffer);
typedef void (*command)(int fd, datas_t *, client_t *);

/* Server Functions */
/**
** @brief Init the client and run the client
**
** @param datas The structure containing all infos about the client
**
** @return [int]
** @retval 0 if everything is ok
** @retval 84 if there is an error
**/
int server_ftp(datas_t *datas);

/**
** @brief Init the client and run the client
**
** @param datas The structure containing all infos about the client
**
** @return [int]
** @retval 0 if everything is ok
** @retval 84 if there is an error
**/
int server_manager(datas_t *st);

/* Client Functions */
int client_manager(datas_t *st);
char *read_command(int fd);

/* errors */
int help(int ac, char **av);
int check_int(char *str);
int check_path(char *path);
int error(int ac, char **av);

/* Init & Free */
int init_socket(datas_t *datas);
int init_datas(datas_t *datas, char **av);

void free_datas(datas_t *datas);
void free_client(client_t *list);
void free_2d_array(char **array);

void update_set_fd(datas_t *st);
bool is_closed(int sock);

/* Replies to server */
void ask_to_serv(datas_t *st, char *message);
void store_datas(datas_t *st, char *buffer);
void check_response_from_server(datas_t *st, const char *response);
void reply_110(datas_t *st);
void reply_111(datas_t *st);
void reply_202(datas_t *st);
void reply_203(datas_t *st);
void reply_206(datas_t *st);
void reply_208(datas_t *st);
void reply_211(datas_t *st);
void reply_212(datas_t *st);
void reply_220(datas_t *st);
void reply_221(datas_t *st);
void reply_222(datas_t *st);
void reply_223(datas_t *st);
void reply_231(datas_t *st);
void reply_232(datas_t *st);
void reply_233(datas_t *st);
void reply_234(datas_t *st);
void reply_235(datas_t *st);
void reply_236(datas_t *st);
void reply_237(datas_t *st);
void reply_238(datas_t *st);
void reply_241(datas_t *st);
void reply_242(datas_t *st);
void reply_243(datas_t *st);
void reply_244(datas_t *st);
void reply_245(datas_t *st);
void reply_402(datas_t *st);
void reply_403(datas_t *st);
void reply_406(datas_t *st);
void reply_408(datas_t *st);
void reply_411(datas_t *st);
void reply_412(datas_t *st);
void reply_420(datas_t *st);
void reply_421(datas_t *st);
void reply_422(datas_t *st);
void reply_423(datas_t *st);
void reply_431(datas_t *st);
void reply_432(datas_t *st);
void reply_433(datas_t *st);
void reply_434(datas_t *st);
void reply_435(datas_t *st);
void reply_436(datas_t *st);
void reply_437(datas_t *st);
void reply_438(datas_t *st);
void reply_441(datas_t *st);
void reply_442(datas_t *st);
void reply_443(datas_t *st);
void reply_444(datas_t *st);
void reply_445(datas_t *st);
void reply_500(datas_t *st);

/* Storage of datas */
void store_uuid(datas_t *st, char *buffer);
void store_username(datas_t *st, char *buffer);
void store_new_message(datas_t *st, char *buffer);
void wrong_user_uuid(datas_t *st, char *buffer);
void store_correspondant(datas_t *st, char *buffer);
void store_new_message(datas_t *st, char *buffer);
void print_all_users(datas_t *st, char *buffer);
void new_team_created(datas_t *st, char *buffer);
void new_channel_created(datas_t *st, char *buffer);
void new_thread_created(datas_t *st, char *buffer);
void new_reply_created(datas_t *st, char *buffer);
void print_infos_user(datas_t *st, char *buffer);
void team_subscription(datas_t *st, char *buffer);

void help1(void);
void help2(void);
void help3(void);

#endif /* !MAIN_H_ */
