/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** commands3
*/

#include "../../include/main.h"

void exec_help(int fd, datas_t *st, client_t *client)
{
    (void)fd;
    (void)st;
    (void)client;
    dprintf(fd, "214 Help message.\n");
    dprintf(fd, "USER <username> : Specify user for authentication\n");
    dprintf(fd, "PASS <password> : Specify password for authentication\n");
    dprintf(fd, "CWD <pathname> : Change working directory\n");
    dprintf(fd, "CDUP : Change working directory to parent directory\n");
    dprintf(fd, "QUIT : Disconnection\n");
    dprintf(fd, "DELE <pathname> : Delete file on the server\n");
    dprintf(fd, "PWD : Print working directory\n");
    dprintf(fd, "PASV : Enable \"passive\" mode for data transfer\n");
    dprintf(fd, "PORT <host-port> : Enable active mode for data transfer\n");
    dprintf(fd, "HELP [<string>] : List available commands\n");
    dprintf(fd, "NOOP : Do nothing\n");
    dprintf(fd, "RETR <pathname> : Download file from server to client\n");
    dprintf(fd, "STOR <pathname> : Upload file from client to server\n");
    dprintf(fd, "LIST [<pathname>] : List files in the Working Dir\r\n");
}

void exec_retr(int fd, datas_t *st, client_t *client)
{
    (void)fd;
    (void)st;
    (void)client;
    if (client->is_logged != 1) {
        dprintf(fd, "530 Not logged in.\r\n");
        return;
    }
    dprintf(fd, "150 File status okay; about to open data connection.\r\n");
    dprintf(fd, "226 Closing data connection.\n");
    dprintf(fd, "Requested file action successful\r\n");
}

void exec_stor(int fd, datas_t *st, client_t *client)
{
    (void)fd;
    (void)st;
    (void)client;
    return;
}

char **get_files_dir(char *path)
{
    DIR *dir = opendir(path);
    struct dirent *ent;
    char **files = NULL;
    int i = 0;

    if (dir == NULL)
        return (NULL);
    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_name[0] != '.') {
            files = realloc(files, sizeof(char *) * (i + 2));
            files[i] = strdup(ent->d_name);
            files[i + 1] = NULL;
            i++;
        }
    }
    closedir(dir);
    return (files);
}

void exec_list(int fd, datas_t *st, client_t *client)
{
    (void)fd;
    (void)st;
    (void)client;
    char **files = NULL;

    if (client->is_logged != 1) {
        dprintf(fd, "530 Not logged in.\r\n");
        return;
    }
    files = get_files_dir(client->path);
    dprintf(fd, "150 File status okay; about to open data connection.\r\n");
    for (int i = 0; files[i] != NULL; i++) {
        dprintf(fd, "%s\r\n", files[i]);
    }
    dprintf(fd, "226 Closing data connection.\n");
    dprintf(fd, "Requested file action successful\r\n");
}
