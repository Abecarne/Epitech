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
    #include <uuid/uuid.h>

    #include "teams.h"
    #include "../../libs/my/libmy.h"
    #include "../../libs/myteams/logging_client.h"
    #include "../../libs/myteams/logging_server.h"

typedef enum cl_location {
    NUL,
    TEAM,
    CHANNEL,
    THREAD,
    REPLY,
}client_location;

/**
** @brief Structure with all infos about the client
**
** @param fd The file descriptor of the client
** @param username The username of the client
** @param password The password of the client
** @param is_logged The boolean that indicates if the client is logged
** @param path The current path of the client
** @param input The command entered by the client
** @param next The next node of the linked list (client)
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
typedef struct client {
    int fd;
    char *uuid;
    char *username;
    char *password;
    bool is_logged;
    char *path;
    char *input;
    char *location_uuid;
    client_location location;
    struct client *next;
} client_t;

/**
** @brief Structure with all infos about the server
**
** @param fd The file descriptor of the client
** @param port The username of the client
** @param path The password of the client
** @param c_path The boolean that indicates if the client is logged
** @param sock_in The current path of the client
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
typedef struct serv {
    int fd;
    int port;
    char *path;
    char *c_path;
    struct sockaddr_in *sock_in;
} serv_t;

/**
** @brief Structure with all datas for the server implementation
**
** @param nb_max_fd The number of max file descriptor
** @param nb_clients The number of clients
** @param serv The structure containing all infos about the server
** @param all_clients The linked list of clients
** @param all_fd_clients The fd_set with all file descriptors of the clients
** @param tmp_fd_clients The copy of all_fd_clients
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
typedef struct data_t {
    int nb_max_fd;
    int nb_clients;
    serv_t *serv;
    client_t *all_clients;
    team_t *all_teams;
    fd_set all_fd_clients;
    fd_set tmp_fd_clients;
} datas_t;

typedef void (*command)(int fd, datas_t *, client_t *);

/* Server Functions */
/**
** @brief Init the server and start the server
**
** @param st The structure containing all datas
**
** @return [int] The return code of the function
** @retval 0 if everything is ok
** @retval 84 if there is an error
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
int server_ftp(datas_t *datas);

/**
** @brief Init the server and start the server
**
** @param st The structure containing all datas
**
** @return [int] The return code of the function
** @retval 0 if everything is ok
** @retval 84 if there is an error
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
int server_manager(datas_t *st);

/**
** @brief Accepts a new client
**
** @param st The structure with all infos
**
** @return [int] The file descriptor of the new client connected
** @retval 0 if everything is ok
** @retval -1 if there is an error
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
int accept_connection(datas_t *st);

/**
** @brief Gets input from client
**
** @param client_fd The client file descriptor
**
** @return [char*] The client input
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
char *read_client(int client_fd);

/* Linked List Functions */
/**
** @brief Add a new client to the linked list
**
** @param list The linked list of clients
** @param fd The client file descriptor
**
** @return [client_t*] The new linked list
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
client_t *add_node(client_t *list, int fd);

/**
** @brief Remove a client with fd **fd_to_rm** from the linked list
**
** @param list The linked list of clients
** @param fd_to_rm The client file descriptor to remove
**
** @return [client_t*] The new linked list of clients
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
client_t *remove_node(client_t *list, int fd_to_rm);

/**
** @brief Counts the number of nodes in the linked list
**
** @param list The linked list of clients
**
** @return [int] The number of clients in the linked list
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
int count_nodes(client_t *list);

/**
** @brief Init all variables in the new client
**
** @param node The new client to fill
** @param fd The file descriptor of the client
**
** @return [void]
**/
void fill_client(client_t *node, int fd);

/**
** @brief Print the linked list of clients
**
** @param list The linked list to print
**
** @return [void]
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
void print_list(client_t *list);

/**
** @brief Get the client by fd
**
** @param list The linked list of clients
** @param fd The file descriptor of the client to find
**
** @return [client_t*] The client with the fd **fd**
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
client_t *get_client_by_fd(client_t *list, int fd);

/**
** @brief Removes the client with fd **fd** from the linked list
** It also frees the memory of the client
**
** @param list The linked list of clients
** @param tmp The copy of the linked list of clients
** @param fd_to_rm The file descriptor of the client to remove
** @param prev The previous node of the client to remove
**
** @return [void]
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
void maybe_remove(client_t *list, client_t *tmp, int fd_to_rm, client_t *prev);

/* Client Functions */
/**
** @brief Loops over the linked list of clients and
** calls the function **move_client**
**
** @param st The structure containing all datas
**
** @return [int] The return code of the function
** @retval 0 if no error
** @retval 84 if an error occured
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
int client_manager(datas_t *st);

/* Commands Functions */
/**
** @brief execute the /use command
** According to the parameters of the command,
** it changes the current team/channel/thread of the client
**
** @param fd The file descriptor of the client
** @param st The structure containing all datas
** @param client The client to print the help menu
**
** @return [void]
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**
**/
void exec_use(int fd, datas_t *st, client_t *client);

/**
** @brief execute the /user command
**
** @param fd The file descriptor of the client
** @param st The structure containing all datas
** @param client The client to print the help menu
**
** @return [void]
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**
**/
void exec_user(int fd, datas_t *st, client_t *client);

/**
** @brief execute the /help command
**
** @param fd The file descriptor of the client
** @param st The structure containing all datas
** @param client The client to print the help menu
**
** @return [void]
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**
**/
void exec_help(int fd, datas_t *st, client_t *client);

/**
** @brief execute the /list command
**
** @param fd The file descriptor of the client
** @param st The structure containing all datas
** @param client The client to print the help menu
**
** @return [void]
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**
**/
void exec_list(int fd, datas_t *st, client_t *client);

/**
** @brief execute the /info command
**
** @param fd The file descriptor of the client
** @param st The structure containing all datas
** @param client The client to print the help menu
**
** @return [void]
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**
**/
void exec_info(int fd, datas_t *st, client_t *client);

/**
** @brief execute the /send command
**
** @param fd The file descriptor of the client
** @param st The structure containing all datas
** @param client The client to print the help menu
**
** @return [void]
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**
**/
void exec_send(int fd, datas_t *st, client_t *client);

/**
** @brief execute the /users command
**
** @param fd The file descriptor of the client
** @param st The structure containing all datas
** @param client The client to print the help menu
**
** @return [void]
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**
**/
void exec_users(int fd, datas_t *st, client_t *client);

/**
** @brief execute the /login command
**
** @param fd The file descriptor of the client
** @param st The structure containing all datas
** @param client The client to print the help menu
**
** @return [void]
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**
**/
void exec_login(int fd, datas_t *st, client_t *client);

/**
** @brief execute the /logout command
**
** @param fd The file descriptor of the client
** @param st The structure containing all datas
** @param client The client to print the help menu
**
** @return [void]
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**
**/
void exec_logout(int fd, datas_t *st, client_t *client);

/**
** @brief execute the /create command
**
** @param fd The file descriptor of the client
** @param st The structure containing all datas
** @param client The client to print the help menu
**
** @return [void]
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**
**/
void exec_create(int fd, datas_t *st, client_t *client);

/**
** @brief execute the /messages command
**
** @param fd The file descriptor of the client
** @param st The structure containing all datas
** @param client The client to print the help menu
**
** @return [void]
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**
**/
void exec_messages(int fd, datas_t *st, client_t *client);

/**
** @brief execute the /subscribe command
**
** @param fd The file descriptor of the client
** @param st The structure containing all datas
** @param client The client to print the help menu
**
** @return [void]
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**
**/
void exec_subscribe(int fd, datas_t *st, client_t *client);

/**
** @brief execute the /subscribed command
**
** @param fd The file descriptor of the client
** @param st The structure containing all datas
** @param client The client to print the help menu
**
** @return [void]
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**
**/
void exec_subscribed(int fd, datas_t *st, client_t *client);

/**
** @brief execute the /unsubscribe command
**
** @param fd The file descriptor of the client
** @param st The structure containing all datas
** @param client The client to print the help menu
**
** @return [void]
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**
**/
void exec_unsubscribe(int fd, datas_t *st, client_t *client);

/* errors */
/**
** @brief Print an help message on the standard output
**
** @param ac numbers of arguments
** @param av arguments
**
** @return [int]
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
int help(int ac, char **av);

/**
** @brief Check if a string is only composed of digits
**
** @param str The string to check
**
** @return [int]
** @retval 0 if the string is only composed of digits
** @retval 1 if the string is not only composed of digits
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
int check_int(char *str);

/**
** @brief Check if the string passed as parameter
** is a valid path or not
**
** @param path The path to check
**
** @return [int]
** @retval 0 if the path is valid
** @retval 1 if the path is not valid
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
int check_path(char *path);

/**
** @brief Main error handling function
** Check the number of arguments,
** the validity of the arguments,
** and the validity of the path.
**
** @param ac numbers of arguments
** @param av arguments
**
** @return [int]
** @retval 0 if everything is ok
** @retval 1 if there is an error
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
int error(int ac, char **av);

/* Init & Free */
/**
** @brief Init the server and fill the structure
**
** @param datas The structure containing all datas
**
** @return [int]
** @retval 0 if everything is ok
** @retval 84 if there is an error
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
int init_socket(datas_t *datas);

/**
** @brief Init all variables in structure **datas**
** Fill the server
** Set linked list to NULL
**
** @param datas The structure containing all datas
** @param av The arguments from main()
**
** @return [int]
** @retval 0 if everything is ok
** @retval 84 if there is an error
**/
int init_datas(datas_t *datas, char **av);

/**
** @brief Free all possible datas in **datas**
**
** @param datas The structure to free
**
** @return [void]
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
void free_datas(datas_t *datas);

/**
** @brief Free all possible datas in the server **datas**
**
** @param datas The structure to free
**
** @return [void]
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
void free_server(serv_t *datas);

/**
** @brief Free all variables in the client **list**
**
** @param list The single client to free
**
** @return [void]
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
void free_client(client_t *list);

/**
** @brief Free all clients in the linked list **list**
**
** @param list The linked list to free
**
** @return [void]
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
void free_clients(client_t *list);

/**
** @brief Free a 2d array of char
**
** @param array The array to free
**
** @return [void]
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
void free_2d_array(char **array);

/**
** @brief Generates a new unique uuid
**
** @return [char*] The new uuid
**
** @author Anthony Becarne (anthony.becarne@epitech.eu)
**/
char *generate_uuid(void);

/* Send Functions */
/**
** @brief Answer to the client with the right datas.
** If a command is rightly written, the function
** write on **fd** the answer containing the data
** Otherwise, it writes on **fd** "Wrong command"
**
** @param fd The client's fd
** @param st The struct containing all the datas
** @param actual The actual client
**
** @author Anthony Becarne (anthony.becarne@epitech.eu)
**/
void dispatch_send(int fd, datas_t *st, client_t *actual);

/**
** @brief Send the UUID of the client **actual** by writing on his **fd**
**
** @param fd The fd of the client
** @param st The struct containing all the datas
** @param actual The actual client
**
** @author Anthony Becarne (anthony.becarne@epitech.eu)
**/
void send_uuid(int fd, datas_t *st, client_t *actual);

/**
** @brief Send the username of the client **actual** by writing on his **fd**
**
** @param fd The fd of the client
** @param st The struct containing all the datas
** @param actual The actual client
**
** @author Anthony Becarne (anthony.becarne@epitech.eu)
**/
void send_username(int fd, datas_t *st, client_t *actual);

/* Error functions */
/**
** @brief Checks if the client is allowed to use /use
**
** @param client The client to check
** @return [bool]
**
** @author Anthony Becarne (anthony.becarne@epitech.eu)
**/
bool is_error_use(client_t *client);

/**
** @brief Checks if the client is allowed to use /list
**
** @param client The client to check
** @return [bool]
**
** @author Anthony Becarne (anthony.becarne@epitech.eu)
**/
bool is_error_list(client_t *client);

/**
** @brief Checks if the client is allowed to use /info
**
** @param client The client to check
** @return [bool]
**
** @author Anthony Becarne (anthony.becarne@epitech.eu)
**/
bool is_error_info(client_t *client);

/**
** @brief Checks if the client is allowed to use /send
**
** @param client The client to check
** @return [bool]
**
** @author Anthony Becarne (anthony.becarne@epitech.eu)
**/
bool is_error_send(datas_t *st, client_t *client);

/**
** @brief Checks if the client is allowed to use /user
**
** @param client The client to check
** @return [bool]
**
** @author Anthony Becarne (anthony.becarne@epitech.eu)
**/
bool is_error_user(client_t *client);

/**
** @brief Checks if the client is allowed to use /login
**
** @param client The client to check
** @return [bool]
**
** @author Anthony Becarne (anthony.becarne@epitech.eu)
**/
bool is_error_login(client_t *client);

/**
** @brief Checks if the client is allowed to use /users
**
** @param client The client to check
** @return [bool]
**
** @author Anthony Becarne (anthony.becarne@epitech.eu)
**/
bool is_error_users(client_t *client);

/**
** @brief Checks if the client is allowed to use /create
**
** @param client The client to check
** @return [bool]
**
** @author Anthony Becarne (anthony.becarne@epitech.eu)
**/
bool is_error_create(client_t *client);

/**
** @brief Checks if the client is allowed to use /logout
**
** @param client The client to check
** @return [bool]
**
** @author Anthony Becarne (anthony.becarne@epitech.eu)
**/
bool is_error_logout(client_t *client);

/**
** @brief Checks if the client is allowed to use /messages
**
** @param client The client to check
** @return [bool]
**
** @author Anthony Becarne (anthony.becarne@epitech.eu)
**/
bool is_error_messages(client_t *client);

/**
** @brief Checks if the client is allowed to use /subscribe
**
** @param st The struct containing all the datas
** @param client The client to check
** @return [bool]
**
** @author Anthony Becarne (anthony.becarne@epitech.eu)
**/
bool is_error_subscribe(datas_t *st, client_t *client);

/**
** @brief Checks if the client is allowed to use /subscribed
**
** @param client The client to check
** @return [bool]
**
** @author Anthony Becarne (anthony.becarne@epitech.eu)
**/
bool is_error_subscribed(client_t *client);

/**
** @brief Checks if the client is allowed to use /unsubscribe
**
** @param st The struct containing all the datas
** @param client The client to check
** @return [bool]
**
** @author Anthony Becarne (anthony.becarne@epitech.eu)
**/
bool is_error_unsubscribe(datas_t *st, client_t *client);

/* Team Functions */
/**
** @brief Check if the **target_uuid** exists in all_teams or not
**
** @param st The struct containing all the datas
** @param target_uuid The uuid of the team to check
**
** @return [bool] True if the team exists, false otherwise
**
** @author Anthony Becarne (anthony.becarne@epitech.eu)
**/
bool is_uuid_in_teams(datas_t *st, char *target_uuid);

/**
** @brief Check if the **target_uuid** exists in all_clients or not
**
** @param st The struct containing all the datas
** @param target_uuid The uuid of the user to check
**
** @return [bool] True if the user exists, false otherwise
**
** @author Anthony Becarne (anthony.becarne@epitech.eu)
**/
bool is_uuid_in_users(datas_t *st, char *target_uuid);

/**
** @brief Get the instance of the team with **uuid**
**
** @param st The struct containing all the datas
** @param uuid The uuid of the team to get
**
** @return [team_t*] The instance of the team
**
** @author Anthony Becarne (anthony.becarne@epitech.eu)
**/
team_t *get_team_by_uuid(datas_t *st, char *uuid);

/**
** @brief Get the instance of the channel with **uuid**
**
** @param st The struct containing all the datas
** @param uuid The uuid of the channel to get
**
** @return [channel_t*] The instance of the channel
**
** @author Anthony Becarne (anthony.becarne@epitech.eu)
**/
channel_t *get_channel_by_uuid(team_t *team, char *uuid);

/**
** @brief Get the instance of the thread with **uuid**
**
** @param st The struct containing all the datas
** @param uuid The uuid of the thread to get
**
** @return [thread_t*] The instance of the thread
**
** @author Anthony Becarne (anthony.becarne@epitech.eu)
**/
thread_t *get_thread_by_uuid(channel_t *channel, char *uuid);

/**
** @brief Get the instance of the client with **uuid**
**
** @param st The struct containing all the datas
** @param uuid The uuid of the client to get
**
** @return [client_t*] The instance of the thread
**
** @author Anthony Becarne (anthony.becarne@epitech.eu)
**/
client_t *get_client_by_uuid(datas_t *st, char *uuid);

/**
** @brief get all the uuid in  the /create command line
**
** @param commande line parser
** @return char *
**/
char **get_uuid(char **arg);

/**
** @brief verify the order of the uuid and the validity of the uuid
**
** @param uuid tableau of uuid and the data_t and the client
** @return bool
**/
bool valide_uuid(char **uuid, datas_t *st, client_t *client, int *n);

/**
** @brief get the type of structure that conteint this uuid
**
** @param uuid and the datat
** @return int
**/

int get_uuid_type(char *uuid, datas_t *st);

void create_thread(thread_t **list, client_t *client, int fd, char **init);
void create_reply(reply_t **list, client_t *client, int fd, char **init);
void create_channel(channel_t **list, client_t *client, int fd, char **init);
void create_teams(datas_t *st, client_t *client, int fd, char **init);
void show_teams(int client_fd, team_t *teams);
void show_channels(int client_fd, channel_t *channels);
void show_threads(int client_fd, thread_t *threads);
void show_replies(int client_fd, reply_t *replies);
void *get_something_from_uuid(char *uuid, team_t *team, int i);

/* Coding style for DOMINIQUE */
void case_of_nul(datas_t *st, int fd, char **init, client_t *client);
void case_of_team(datas_t *st, int fd, char **init, client_t *client);
void case_of_channel(datas_t *st, int fd, char **init, client_t *client);
void case_of_thread(datas_t *st, int fd, char **init, client_t *client);
void case_of_nul2(datas_t *st, int fd, client_t *client);
void case_of_team2(datas_t *st, int fd, client_t *client);
void case_of_channel2(datas_t *st, int fd, client_t *client);
void case_of_thread2(datas_t *st, int fd, client_t *client);

void help1(int fd);
void help2(int fd);
void help3(int fd);

void add_user_to_team(team_t *team, datas_t *st, client_t *client);

#endif /* !MAIN_H_ */
