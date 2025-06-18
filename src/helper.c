#include "inc/helper.h"

void set_x (int n) {
    for (int count_n = 0; count_n < n; count_n++) {
            PySys_WriteStdout(" ");
    }
}

void set_y (int n) {

    for (int count_n = 0; count_n < n; count_n++) {
        PySys_WriteStdout("\n");
    }
}

void swop(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;   
}

int clamp (int x, int minimum, int maximum) {
    if (x < minimum) {
        return minimum;
    } if (x > maximum) {
        return maximum;
    }
    return x;
}


void draw_duck(int s) {
    char ascii_duck[2][5] = {
        {"=##\n\0"},
        {" ###\0"},
    };
    for (int i = 0; i < 2; i++) {
        
        set_x(s);
        PySys_WriteStdout("%s", ascii_duck[i]);
    }
        
        

}
