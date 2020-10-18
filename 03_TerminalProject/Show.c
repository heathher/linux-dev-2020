#include <stdio.h>
#include <ncurses.h>

#define DX 2

void show_content(WINDOW *window, int rows, int cols, FILE* f) {
    int c = 0;
    for (int i = 0; i < rows; i++) {
        for (int i = 0; i < cols; i++) {
            if ((c = fgetc(f)) != EOF ) {
                wprintw(window, "%c", c);
            }
            if (c == '\n') {
                break;
            }
        }
    }
    do {
        if (c == 32) {
            for (int i = 0; i < cols; i++) {
                if ((c = fgetc(f)) != EOF ) {
                    wprintw(window, "%c", c);
                }
                if (c == '\n') {
                    break;
                }
            }
            wrefresh(window);
        }
    } while((c = wgetch(window)) != 27);
}

void show_file(FILE* f, const char* filename) {
    WINDOW *window, *content;

    fseek(f, 0, SEEK_END); 
    int size = ftell(f) + 1; 
    fseek(f, 0, SEEK_SET);

    initscr();
    noecho();
    cbreak();
    printw("File: '%s', File Size: '%d' bytes\n", filename, size);
    refresh();

    window = newwin(LINES-DX, COLS-DX, DX, DX);
    box(window, 0, 0);
    wrefresh(window);

    content = newwin(LINES-3*DX, COLS-3*DX, 2 * DX, 2 * DX);
    keypad(content, TRUE);
    scrollok (content, TRUE);
    show_content(content, LINES-3*DX, COLS-3*DX, f);

    endwin();

}

int main(int argc, char **argv) {
    if(argc != 2) {
        printf("ERROR: Invalid number of arguments\n");
        return -1;
    }
    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        printf("ERROR: File can't be opened\n");
        return -1;
    }
    show_file(f, argv[1]);
    fclose(f);
    return 0;
}
