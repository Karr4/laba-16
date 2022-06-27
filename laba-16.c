#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

int main()
{
    WINDOW* output;
    
    int n = 5, m = 5;
    
    initscr();
    refresh();
    
    if (!has_colors())
    {
        endwin();
        printf("Error!");
        return 1;
    }
    else
    {
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_BLUE);
        init_pair(2, COLOR_BLACK, COLOR_YELLOW);
        init_pair(3, COLOR_BLACK, COLOR_WHITE);
        init_pair(4, COLOR_WHITE, COLOR_RED);
        cbreak();
        
        int x, y, width = 6, height = 3;
        int a[n][n];
        int res = 1;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                x += 6;
                if ((i + j + 2)%2 != 0)
                {
                    output = newwin(height, width, y, x);
                    box(output, 0, 0);
                    wbkgd(output, COLOR_PAIR(2));
                    wrefresh(output);
                    
                    move(y + 1, x + 2);
                    attron(COLOR_PAIR(2) | A_BOLD);
                    scanw("%d", &a[i][j]);
                    res = res * a[i][j];
                }
                else 
                {
                    output = newwin(height, width, y, x);
                    box(output, 0, 0);
                    wbkgd(output, COLOR_PAIR(1));
                    wrefresh(output);
                    
                    move(y + 1, x + 2);
                    attron(COLOR_PAIR(1) | A_BOLD);
                    scanw("%d", &a[i][j]);
                }
            }
            y += 3;
            x = 0;
        }
        
        x = 40 + n * 6;
        y = 0;
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                x -= 6;
                if (i == j){
                    output = newwin(height, width, y, x);
                    box(output, 0, 0);
                    wbkgd(output, COLOR_PAIR(4));
                    wrefresh(output);
                    
                    move(y + 1, x + 2);
                    attron(COLOR_PAIR(4) | A_BOLD);
                    a[i][j] = res;
                    printw("%d", a[i][j]);
                }
                else {
                    output = newwin(height, width, y, x);
                    box(output, 0, 0);
                    wbkgd(output, COLOR_PAIR(3));
                    wrefresh(output);
                    
                    move(y + 1, x + 2);
                    attron(COLOR_PAIR(3) | A_BOLD);
                    printw("%d", a[i][j]);
                }
            }
            y += 3;
            x = 40 + n * 6;
        }
    }
    refresh();
    getch();
    
    endwin();
    return 0;
}
