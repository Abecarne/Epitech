/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** check_response_from_server
*/

#include "../../include/main.h"

static void *replies_tab[][2] = {
    {"110 Connection Establishment.", reply_110},
    {"111 HELP.", reply_111},
    {"202 Login accepted.", reply_202},
    {"203 Logout accepted.", reply_203},
    {"206 Message sent correctly.", reply_206},
    {"208 Subscribed to team.", reply_208},
    {"211 Unsubscribed from team.", reply_211},
    {"212 Context changed.", reply_212},
    {"220 Team created.", reply_220},
    {"221 Channel created.", reply_221},
    {"222 Thread created.", reply_222},
    {"223 Reply created.", reply_223},
    {"231 Users list.", reply_231},
    {"232 Messages list.", reply_232},
    {"233 Subscribed teams list.", reply_233},
    {"234 Users in the team list.", reply_234},
    {"235 Existing teams list.", reply_235},
    {"236 Existing channels list.", reply_236},
    {"237 Existing threads list.", reply_237},
    {"238 Existing replies list.", reply_238},
    {"241 User infos.", reply_241},
    {"242 Logged Users infos.", reply_242},
    {"243 Selected team infos.", reply_243},
    {"244 Selected channel infos.", reply_244},
    {"245 Selected thread infos.", reply_245},
    {"402 Error: Login refused.", reply_402},
    {"403 Error: Logout refused.", reply_403},
    {"406 Error: Message not sent.", reply_406},
    {"408 Error: Subscription refused.", reply_408},
    {"411 Error: Unsubscription refused.", reply_411},
    {"412 Error: Context change refused.", reply_412},
    {"420 Error: Team creation refused.", reply_420},
    {"421 Error: Channel creation refused.", reply_421},
    {"422 Error: Thread creation refused.", reply_422},
    {"423 Error: Reply creation refused.", reply_423},
    {"431 Error: Users list not found.", reply_431},
    {"432 Error: Messages not listed.", reply_432},
    {"433 Error: Subscribed teams not listed.", reply_433},
    {"434 Error: Users not listed.", reply_434},
    {"435 Error: Existing teams not listed.", reply_435},
    {"436 Error: Existing channels not listed.", reply_436},
    {"437 Error: Existing threads not listed.", reply_437},
    {"438 Error: Existing replies not listed.", reply_438},
    {"441 Error: User not found.", reply_441},
    {"442 Error: Logged users not found.", reply_442},
    {"443 Error: Selected team not found.", reply_443},
    {"444 Error: Selected channel not found.", reply_444},
    {"445 Error: Selected thread not found.", reply_445},
    {"500 Syntax error, command unrecognized.", reply_500},
    {NULL, NULL},
};

void check_response_from_server(datas_t *st, const char *response)
{
    for (int i = 0; replies_tab[i][0]; i++) {
        if (strcmp(response, (char *)replies_tab[i][0]) == 0) {
            ((reply)replies_tab[i][1])(st);
            return;
        }
    }
}
