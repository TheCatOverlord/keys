#include <ncurses.h>
#include <unistd.h>

int main()
{
    int i = 0;
    int x=0,y=0;
    int max_x,max_y;
    char ch;
    initscr();
    noecho();
    keypad(stdscr,TRUE);

    //print a welcome message
    mvprintw(0,0,"Use W,A,S,D or the Arrow keys to move along the x,y axis and q,e,z,c to move diagonal. esc to exit.");

    getmaxyx(stdscr,max_y,max_x);

    //print the border
    i = 0;
    while(i<max_x)
    {
	mvprintw(1,i,"-");
	mvprintw(max_y-1,i,"-");
	i++;
    }
    i = 1;
    while(i<max_y)
    {
	mvprintw(i,0,"|");
	mvprintw(i,max_x-1,"|");
	i++;
    }

    //print corners of the border
    mvprintw(1,0,"+");
    mvprintw(max_y-1,0,"+");
    mvprintw(1,max_x-1,"+");
    mvprintw(max_y-1,max_x-1,"+");

    //print the start location of the player
    x = (max_x/2);
    y = (max_y/2);
    mvprintw(y,x,"#");

    //key press loop
    while(ch != 27)
    {
        //get screen size
        getmaxyx(stdscr,max_y,max_x);
        //get the key
        ch = getch();
        //wipe the screen
        clear();

        //print how to message
        mvprintw(0,0,"Use W,A,S,D or the Arrow keys to move along the x,y axis and q,e,z,c to move diagonal. esc to exit.");
        //filter key and colision detection
        if(ch == 3 || ch == 'w')
        {
		y--;
		if(y>(max_y-2) || x>(max_x-2) || y<2 || x<1)
		{
			mvprintw(0,max_x-13,"out of bounds");
			y++;
		}
	}
        else if(ch == 2 || ch == 's')
        {
		y++;
		if(y>(max_y-2) || x>(max_x-2) || y<2 || x<1)
		{
			mvprintw(0,max_x-13,"out of bounds");
			y--;
		}
	}
        else if(ch == 5 || ch == 'd')
        {
		x++;
		if(y>(max_y-2) || x>(max_x-2) || y<2 || x<1)
		{
			mvprintw(0,max_x-13,"out of bounds");
			x--;
		}
	}
        else if(ch == 4 || ch == 'a')
        {
		x--;
		if(y>(max_y-2) || x>(max_x-2) || y<2 || x<1)
		{
			mvprintw(0,max_x-13,"out of bounds");
			x++;
		}
	}
        else if(ch == 'e')
        {
		x++;
		y--;
		if(y>(max_y-2) || x>(max_x-2) || y<2 || x<1)
		{
			mvprintw(0,max_x-13,"out of bounds");
			x--;
			y++;
		}
	}
        else if (ch == 'q')
        {
		x--;
		y--;
		if(y>(max_y-2) || x>(max_x-2) || y<2 || x<1)
		{
			mvprintw(0,max_x-13,"out of bounds");
			x++;
			y++;
		}
	}
        else if(ch == 'z')
        {
		x--;
		y++;
		if(y>(max_y-2) || x>(max_x-2) || y<2 || x<1)
		{
			mvprintw(0,max_x-13,"out of bounds");
			x++;
			y--;
		}
	}
        else if(ch == 'c')
        {
		x++;
		y++;
		if(y>(max_y-2) || x>(max_x-2) || y<2 || x<1)
		{
			mvprintw(0,max_x-13,"out of bounds");
			x--;
			y--;
		}
	}
        else
        {
		mvprintw(0,max_x-11,"invalid key");
	}

        //print border
        i = 0;
        while(i<max_x)
        {
		mvprintw(1,i,"-");
		mvprintw(max_y-1,i,"-");
		i++;
	}
        i = 1;
        while(i<max_y)
        {
		mvprintw(i,0,"|");
		mvprintw(i,max_x-1,"|");
		i++;
	}

        //print corners
        mvprintw(1,0,"+");
        mvprintw(max_y-1,0,"+");
        mvprintw(1,max_x-1,"+");
        mvprintw(max_y-1,max_x-1,"+");

        //print player
        mvprintw(y,x,"#");

        //refresh
        refresh();
    }
    //end curses
    endwin();
    return 0;
}
