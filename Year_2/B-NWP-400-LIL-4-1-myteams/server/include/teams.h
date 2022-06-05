/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-anthony.becarne [WSL: Ubuntu-20.04]
** File description:
** teams
*/

#ifndef TEAMS_H_
    #define TEAMS_H_
    #include <stdbool.h>

/**
** @brief Linked list containing all users registered in a team
**
** @param uuid The uuid of the current user
** @param next The next user in the list
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
typedef struct user_s {
    char *uuid;
    char *username;
    bool is_logged;
    struct user_s *next;
} user_t;

/**
** @brief Linked list containing all replies in a thread
**
** @param message The message of the current reply
** @param next The next reply in the list
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
typedef struct reply_s {
    char *message;
    char *comment_body;
    struct reply_s *next;
} reply_t;

/**
** @brief Linked list containing all threads in a channel
**
** @param uuid The uuid of the current user
** @param replies The linked list of replies in the thread
** @param next The next user in the list
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
typedef struct thread_s {
    char *uuid;
    char *description;
    char *title;
    reply_t *all_replies;
    struct thread_s *next;
} thread_t;

/**
** @brief Linked list containing all users registered in a team
**
** @param uuid The uuid of the current thread
** @param threads The linked list of threads in the channel
** @param next The next thread in the list
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
typedef struct channel_s {
    char *uuid;
    char *description;
    char *title;
    thread_t *all_threads;
    struct channel_s *next;
} channel_t;

/**
** @brief Linked list containing all teams
**
** @param uuid The uuid of the current team
** @param users The linked list of users in the team
** @param channels The linked list of channels in the team
** @param next The next team in the list
** @param description The description of the team
**
** @author Anthony Becarne - anthony.becarne@epitech.eu
**/
typedef struct team_s {
    char *uuid;
    char *description;
    char *title;
    user_t *users;
    channel_t *all_channels;
    struct team_s *next;
} team_t;

#endif /* !TEAMS_H_ */
