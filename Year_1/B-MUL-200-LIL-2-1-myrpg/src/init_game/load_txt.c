/*
** EPITECH PROJECT, 2020
** load_txt.c
** File description:
** load txt
*/

#include "my.h"
#include "framing_engine.h"

void load_txt(framing *lvl, char *true_path)
{
    sfVector2f scale = {2, 2};
    sfVector2f pos = {0, 0};

    lvl->map_txt.txt = sfTexture_createFromFile(true_path, NULL);
    lvl->map_txt.sprite = sfSprite_create();
    lvl->map_txt.pos = pos;
    lvl->map_txt.scale = scale;
    lvl->map_txt.x = 0;
    lvl->map_txt.y = 0;
    lvl->map_txt.rotate = 0;
    lvl->map_txt.status = 0;
    lvl->map_txt.clock = sfClock_create();
    sfSprite_setTexture(lvl->map_txt.sprite, lvl->map_txt.txt, sfTrue);
    sfSprite_setScale(lvl->map_txt.sprite, lvl->map_txt.scale);
    sfSprite_setPosition(lvl->map_txt.sprite, lvl->map_txt.pos);
}

char *build_true_path(char *path)
{
    int size = my_strlen(path) + my_strlen(".jpg");
    char *true_path = malloc(sizeof(char) * (size + 1));

    if (true_path != NULL) {
        my_strcat(true_path, path);
        my_strcat(true_path, ".jpg");
    }
    return (true_path);
}

int prepare_txt(framing *lvl, char *path)
{
    char *true_path = build_true_path(path);

    if (true_path == NULL)
        return (unload_map(lvl, 1));
    load_txt(lvl, true_path);
    if (true_path != NULL)
        free(true_path);
    return (0);
}
