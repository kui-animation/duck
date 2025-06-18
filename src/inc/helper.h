#ifndef HELPER_H
#define HELPER_H

#include <python3.12/Python.h>
#include <stdlib.h>
#include <stdio.h>

void set_x (int n);
void set_y (int n);
void draw_duck(int s);
void swop(int *a, int *b);
int clamp (int x, int minimum, int maximum);

#endif