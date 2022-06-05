/*
** EPITECH PROJECT, 2020
** 101pong
** File description:
** Graphical Interface
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>


int displayed(sfCircleShape *ball, sfRectangleShape *paddle1, sfRectangleShape *paddle2)
{
    sfVideoMode mode = {1300, 1000, 32};
    sfRenderWindow* window;
    sfEvent event;
    sfVector2f move_ball;
    sfVector2f paddleUp;
    sfVector2f paddleDown;

    move_ball.x = 0.5;
    move_ball.y = 0.5;

    float xPosBall;
    float yPosBall;

    float xPosP1;
    float yPosP1;
    float xPosP2;
    float yPosP2;

    paddleUp.x = 0;
    paddleUp.y = -25;

    paddleDown.x = 0;
    paddleDown.y = 25;


    window = sfRenderWindow_create(mode, "SFML window", sfClose, NULL);
    while (sfRenderWindow_isOpen(window))
    {
        sfCircleShape_move(ball, move_ball);

        xPosBall = sfCircleShape_getPosition(ball).x;
        yPosBall = sfCircleShape_getPosition(ball).y;

        if ((xPosBall <= 0 || xPosBall >= 1240)) {
            move_ball.x *= -1;
            sfCircleShape_move(ball, move_ball);
        }
        if ((yPosBall <= 0 || yPosBall >= 940)) {
            move_ball.y *= -1;
            sfCircleShape_move(ball, move_ball);
        }
    
        /* Process events */
        while (sfRenderWindow_pollEvent(window, &event))
        {
            xPosP1 = sfRectangleShape_getPosition(paddle1).x;
            yPosP1 = sfRectangleShape_getPosition(paddle1).y;
            xPosP2 = sfRectangleShape_getPosition(paddle2).x;
            yPosP2 = sfRectangleShape_getPosition(paddle2).y;

            if ((event.key.code == sfKeyZ) && (yPosP1 >= 25)) {
                sfRectangleShape_move(paddle1, paddleUp);
            }
            if ((event.key.code == sfKeyS) && (yPosP1 <= 780)) {
                sfRectangleShape_move(paddle1, paddleDown);
            }
            if ((event.key.code == sfKeyUp) && (yPosP2 >= 25)) {
                sfRectangleShape_move(paddle2, paddleUp);
            }
            if ((event.key.code == sfKeyDown) && (yPosP2 <= 780)) {
                sfRectangleShape_move(paddle2, paddleDown);
            }

            /* Close window : exit */
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }

        /* Clear the screen */
        sfRenderWindow_clear(window, sfBlack);

        sfRenderWindow_drawCircleShape(window, ball, NULL);
        sfRenderWindow_drawRectangleShape(window, paddle1, NULL);
        sfRenderWindow_drawRectangleShape(window, paddle2, NULL);

        /* Update the window */
        sfRenderWindow_display(window);
    }
}

int main(void)
{
    sfVector2f origin1;
    origin1.x = 5;
    origin1.y = 400;

    sfVector2f origin2;
    origin2.x = 1270;
    origin2.y = 400;

    sfVector2f size;
    size.x = 25;
    size.y = 200;


    sfRectangleShape *paddle1;
    paddle1 = sfRectangleShape_create();
    sfRectangleShape_setPosition(paddle1, origin1);

    sfRectangleShape *paddle2;
    paddle2 = sfRectangleShape_create();
    sfRectangleShape_setPosition(paddle2, origin2);

    sfRectangleShape_setSize(paddle1, size);
    sfRectangleShape_setSize(paddle2, size);


    sfCircleShape *ball;
    sfVector2f ball_pos;
    ball = sfCircleShape_create();

    sfCircleShape_setRadius(ball, 30);
    ball_pos.x = 650-30;
    ball_pos.y = 500-30;
    sfCircleShape_setPosition(ball, ball_pos);
    sfCircleShape_setFillColor(ball, sfWhite);

    displayed(ball, paddle1, paddle2);
    return (0);
}