#ifndef HELPER_H
#define HELPER_H

#ifndef _WIN32
    #include <python3.12/Python.h>
#else
    #include <python3.11/Python.h>
    #include <windows.h>
    void enable_ansi_escape_sequences();
#endif
#include <stdlib.h>
#include <stdio.h>

void set_x_and_y (int x, int y);
void draw_duck(int s, int y);
void swop(int *a, int *b);
int clamp (int x, int minimum, int maximum);
void draw (int *x, int *y, int len);
#endif