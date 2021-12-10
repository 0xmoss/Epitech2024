/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD01-
** File description:
** pyramid.c
*/


int check_path(const int *floors, int floor)
{
    int shorter = floors[0];

    for (int i = 0; i <= floor; i++) {
        if (floors[i] < shorter)
            shorter = floors[i];
    }
    return (shorter);
}

int pyramid_path(int size, const int **map)
{
    int path = 0;

    for (int floor = 0; floor < size; floor++) {
        path += check_path(map[floor], floor);
    }
    return (path);
}