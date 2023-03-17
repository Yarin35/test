/*
** EPITECH PROJECT, 2023
** my_new_file.c
** File description:
** my_new_file
*/

#include "pixel.h"

char *enter_name(framebuffer_t *buffer, sfEvent *event)
{
    char *name = my_calloc(sizeof(unsigned char), 10);

    if (buffer->namelen == 9)
        return NULL;
    if (event->type == sfEvtTextEntered) {
        if (event->text.unicode >= 48 && event->text.unicode <= 122)
            name[buffer->namelen ++] = (char)event->text.unicode;
        if (event->text.unicode == 0 && buffer->namelen > 0)
            name[-- buffer->namelen] = '\0';
    }
    name[buffer->namelen] = '\0';
    buffer->namelen = 0;
    if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
        if (!buffer->namefull)
            buffer->namefull = true;
        else
            buffer->namefull = false;
        return name;
    }
    return name;
}

void my_new_file(framebuffer_t *buff, sfEvent *event)
{
    char *filename = enter_name(buff, event);

    if (filename) {
        buff->name = my_strcat(buff->name, filename);
        sfText_setString(buff->text, buff->name);
        free(filename);
    }
    return;
}
