#define _XOPEN_SOURCE_EXTENDED
#define _POSIX_C_SOURCE 199309L
#include <ncurses.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <cstdio>

using namespace std;

void sigWinch(int signo)
{
    winsize size;
    ioctl(fileno(stdout),TIOCGWINSZ,(char *) &size);
    resizeterm(size.ws_row,size.ws_col);
}

int main()
{
    initscr();
    signal(SIGWINCH,sigWinch);

    noecho();
    curs_set(0);
    start_color();
    int green=0;
    init_pair(green,COLOR_GREEN,COLOR_BLUE);
    attron(COLOR_PAIR(green)|A_BLINK);
    move(10,30);
    printw("For the swarm!");
    refresh();
    getch();
    endwin();
    return 0;
}
