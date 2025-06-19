#include "inc/helper.h"

void set_x_and_y (int x, int y) {
    PySys_WriteStdout("\x1B[%d;%df", y, x);
}
#ifdef _WIN32
    void enable_ansi_escape_sequences() {
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD dwMode = 0;

        if (hOut == INVALID_HANDLE_VALUE) return;

        // Get the current console mode
        if (!GetConsoleMode(hOut, &dwMode)) return;

        // Enable the virtual terminal processing flag
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, dwMode);
    }
#endif

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


void draw_duck(int s, int y) {
    char ascii_duck[2][5] = {
        {"=## \0"},
        {" ###\0"},
    };
    for (int i = 0; i < 2; i++) {   
        set_x_and_y(s, y+i);
        PySys_WriteStdout("%s", ascii_duck[i]);
    }
        
}

void draw (int *x, int *y, int len) {

    for (int k = 0; k < len; k++) {
        int tmp_index = k;
        for (int l = k; l < len; l++) {
            if (y[l] < y[tmp_index]) {
                tmp_index = l;
            }
        }
        swop(&y[k], &y[tmp_index]);
        swop(&x[k], &x[tmp_index]);
    }


    for (int o = 0; o < len; o++) {
        draw_duck(x[o], y[o]);
    }
    PySys_WriteStdout("\n\n");
}