/*
** EPITECH PROJECT, 2021
** get_file
** File description:
** get_file
*/

#include "asm.h"
#include "lib.h"

char *get_o_filepath(char *filepath)
{
    char *o_filepath;
    int len = my_strlen(filepath);

    if (!(len > 1 && filepath[len - 1] == 's' && filepath[len - 2] == '.')) {
        write(2, "Error: invalid file must be a [.s] file\n", 40);
        return (NULL);
    }
    o_filepath = malloc(sizeof(char) * (my_strlen(filepath) + 3));
    if (o_filepath == NULL)
        return (NULL);
    my_strcpy(o_filepath, filepath);
    o_filepath[len - 1] = '\0';
    my_strcat(o_filepath, "cor");
    return (o_filepath);
}

int add_node(file_t **ptr, char *line, int h)
{
    file_t *element = malloc(sizeof(file_t));

    if (element == NULL)
        return (-1);
    element->data = my_strdup(line);
    if (element->data == NULL)
        return (-1);
    element->data = clear_str(element->data);
    element->line = h;
    element->next = *ptr;
    *ptr = element;
    return (0);
}

int get_file(file_t **ptr, char *filepath)
{
    FILE *stream = fopen(filepath, "r");
    size_t n = 0;
    char *line = NULL;
    ssize_t size = 0;

    if (stream == NULL) {
        write(2, "Error: file does not exist\n", 27);
        return (84);
    }
    for (int i = 1;(size = getline(&line, &n, stream)) > 0; i++) {
        if (line[size - 1] == '\n')
            line[size - 1] = '\0';
        else
            line[size] = '\0';
        if (add_node(ptr, line, i) == -1)
            return (84);
    }
    free(line);
    fclose(stream);
    return (0);
}