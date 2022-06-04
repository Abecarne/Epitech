/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-anthony.becarne [WSL: Ubuntu-20.04]
** File description:
** help
*/

#include "../../include/main.h"

void help1(void)
{
    printf("- /help --> Prints the list of commands.\n");
    printf("- /login [\"username\"] \
    --> Set the username used by client\n");
    printf("- /logout --> Logout from the server\n");
    printf("- /users \
    --> Get the list of all users that exist on the domain.\n");
}

void help2(void)
{
    printf("- /user [\"user_uuid\"] \
    --> Get informations about an user.\n");
    printf("- /send [\"user_uuid\"] [\"message\"] \
    --> Send a message to a user\n");
    printf("        Please note that the max message \
    lenght is 512 characters.\n");
    printf("        Please note that the max username \
    lenght is 32 characters.\n");
    printf("- /messages [\"user_uuid\"] \
    --> List all messages exchange with an user.\n");
}

void help3(void)
{
    printf("- /subscribe [\"team_uuid\"] \
    --> Subscribe to the event of a team and its sub directories\n");
    printf("        (enables reception of all events from a team).\n");
    printf("- /subscribed ?[\"team_uuid\"] \
    --> List all subscribed teams or all users subscribed to a team.\n");
    printf("- /unsubscribe [\"team_uuid\"] \
    --> Unsubscribe from a team.\n");
    printf("- /use ?[\"team_uuid\"] ?[\"channel_uuid\"] \
    ?[\"thread_uuid\"] --> Specify a context team/channel/thread.\n");
}
