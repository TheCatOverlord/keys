#include <ncurses.h>
int main()
{
    int max_x,max_y;
    char ch;
    initscr();
    noecho();
    keypad(stdscr,TRUE);
    getmaxyx(stdscr,max_y,max_x);
    int x=(max_x/2),y=(max_y/2),i=0;
    mvprintw(0,0,"press any key to start");
    while(ch != 27)
    {
        getmaxyx(stdscr,max_y,max_x);
        ch = getch();
        clear();
        mvprintw(0,0,"Use W,A,S,D or the Arrow keys to move along the x,y axis and q,e,z,c to move diagonal. esc to exit.");
        if(ch == 3 || ch == 'w')
        {y--;i=0;if(y>(max_y-2) || x>(max_x-2) || y<2 || x<1){mvprintw(0,max_x-13,"out of bounds");y++;}}
        else if(ch == 2 || ch == 's')
        {y++;i=0;if(y>(max_y-2) || x>(max_x-2) || y<2 || x<1){mvprintw(0,max_x-13,"out of bounds");y--;}}
        else if(ch == 5 || ch == 'd')
        {x++;i=0;if(y>(max_y-2) || x>(max_x-2) || y<2 || x<1){mvprintw(0,max_x-13,"out of bounds");x--;}}
        else if(ch == 4 || ch == 'a')
        {x--;i=0;if(y>(max_y-2) || x>(max_x-2) || y<2 || x<1){mvprintw(0,max_x-13,"out of bounds");x++;}}
        else if(ch == 'e')
        {x++;y--;i=0;if(y>(max_y-2) || x>(max_x-2) || y<2 || x<1){mvprintw(0,max_x-13,"out of bounds");x--;y++;}}
        else if (ch == 'q')
        {x--;y--;i=0;if(y>(max_y-2) || x>(max_x-2) || y<2 || x<1){mvprintw(0,max_x-13,"out of bounds");x++;y++;}}
        else if(ch == 'z')
        {x--;y++;i=0;if(y>(max_y-2) || x>(max_x-2) || y<2 || x<1){mvprintw(0,max_x-13,"out of bounds");x++;y--;}}
        else if(ch == 'c')
        {x++;y++;i=0;if(y>(max_y-2) || x>(max_x-2) || y<2 || x<1){mvprintw(0,max_x-13,"out of bounds");x--;y--;}}
        else
        {mvprintw(0,max_x-11,"invalid key");i=0;}
        while(i<max_x)
        {mvprintw(1,i,"-");mvprintw(max_y-1,i,"-");i++;}
        i = 1;
        while(i<max_y)
        {mvprintw(i,0,"|");mvprintw(i,max_x-1,"|");i++;}
        mvprintw(1,0,"+");
        mvprintw(max_y-1,0,"+");
        mvprintw(1,max_x-1,"+");
        mvprintw(max_y-1,max_x-1,"+");
        mvprintw(y,x,"#");
        refresh();
    }
    endwin();
    return 0;
}