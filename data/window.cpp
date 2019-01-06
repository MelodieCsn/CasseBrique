#include "window.h"
#include <list>
#include <unistd.h>
#include <sys/ioctl.h>

void init_colors(void)
{
  start_color();
  init_pair(WBLACK,   COLOR_WHITE, COLOR_BLACK);
  init_pair(WCYAN,    COLOR_WHITE, COLOR_CYAN);
  init_pair(WBLUE,    COLOR_WHITE, COLOR_BLUE);
  init_pair(WYELLOW,  COLOR_WHITE, COLOR_YELLOW);  
  init_pair(WGREEN,   COLOR_WHITE, COLOR_GREEN); 
  init_pair(WMAGENTA, COLOR_WHITE, COLOR_MAGENTA);
  init_pair(WRED,     COLOR_WHITE, COLOR_RED);  
  init_pair(WWHITE,   COLOR_BLACK, COLOR_WHITE);
  init_pair(BCYAN,    COLOR_BLACK, COLOR_CYAN);
  init_pair(BBLUE,    COLOR_BLACK, COLOR_BLUE);
  init_pair(BYELLOW,  COLOR_BLACK, COLOR_YELLOW);  
  init_pair(BGREEN,   COLOR_BLACK, COLOR_GREEN); 
  init_pair(BMAGENTA, COLOR_BLACK, COLOR_MAGENTA);
  init_pair(BRED,     COLOR_BLACK, COLOR_RED);
  init_pair(BBLACK,   COLOR_BLACK, COLOR_BLACK);
  init_pair(BWHITE,   COLOR_BLACK, COLOR_WHITE);
}

void startProgramX() {
  initscr();             // initialize curses
  cbreak();              // pass key presses to program, but not signals
  noecho();              // don't echo key presses to screen
  keypad(stdscr, TRUE);  // allow arrow keys
  timeout(0);            // no blocking on getch()
  curs_set(0);           // set the cursor to invisible
  init_colors();
}

void stopProgramX() {
  refresh();
  getch();    
  endwin();
}

void Window::update() const{
  wrefresh(win);
  wrefresh(frame);
  refresh();
}

Window::Window(int h,int w, int x, int y, char c)
  : height(h), width(w), startx(x), starty(y), bord(c)
{
  colorwin=WBLACK;
  colorframe=WWHITE;
  frame=newwin(h+2,w+2,y,x);
  win=subwin(frame,h,w,y+1,x+1);
  wbkgd(frame,COLOR_PAIR(colorframe));
  wbkgd(win,COLOR_PAIR(colorwin));
  wattron(frame,COLOR_PAIR(colorframe));
  wattron(win,COLOR_PAIR(colorwin));
  update();
  wborder(frame,c,c,c,c,c,c,c,c);
}

Window::~Window(){
  wborder(frame, ' ', ' ', ' ',' ',' ',' ',' ',' ');
  wattroff(win,COLOR_PAIR(colorwin));
  wattroff(win,COLOR_PAIR(colorframe));
  werase(win);
  update();
  delwin(win); 
}

void Window::print(int x, int y, string s, Color c) const {
  wattron(win,COLOR_PAIR(c));
  mvwprintw(win,y,x,s.c_str());
  wattroff(win,COLOR_PAIR(c));
  update();  
}

void Window::print(int x, int y, char s, Color c) const{
  wattron(win,COLOR_PAIR(c));
  mvwaddch(win,y,x,s);
  wattroff(win,COLOR_PAIR(c));
  update();
}

void Window::print(int x, int y, string s) const{
  mvwprintw(win,y,x,s.c_str());
  update();  
}

void Window::print(int x, int y, char s) const{
  mvwaddch(win,y,x,s);
  update();  
}

// Les fonctions print suivantes ont été rajoutées, en se servant des précédents comme modèles

void Window::print(Balle ball) const {
  char ch='@';
  int x=ball.getX();
  int y=ball.getY();
  wattron(win,COLOR_PAIR(WBLACK));
  mvwaddch(win,y,x,ch);
  wattroff(win,COLOR_PAIR(WBLACK));
  update();  
}

void Window::print(Raquette raq) const {
  char ch=' ';
  int x=raq.getX();
  int y=raq.getY();
  wattron(win,COLOR_PAIR(WRED));
  mvwaddch(win,y,x,ch);
  mvwaddch(win,y,x+raq.getLength()-1,ch);
  wattroff(win,COLOR_PAIR(WRED));
  for(int i=x+1;i<x+raq.getLength()-1;i++){
    wattron(win,COLOR_PAIR(WGREEN));
    mvwaddch(win,y,i,ch);
    wattroff(win,COLOR_PAIR(WGREEN));
    }
  update();
}

void Window::print(Brique br) const {
  char ch=' ';
  int x=br.getX();
  int y=br.getY();
  Color col;
  switch(br.getPv()){
  case 1:
    col = WRED;
    break;
  case 2:
    col = WYELLOW;
    break;
  case 3:
    col = WGREEN;
    break;
  case 4:
    col = WBLUE;
    break;
  case 5:
    col = WMAGENTA;
    break;
  }
  wattron(win,COLOR_PAIR(col));
  mvwaddch(win,y,x,ch);
  wattroff(win,COLOR_PAIR(col));
  update();  
}

void Window::print(Lettre lettre, Color c) const {
  char ch=' ';
  unsigned long long int i=lettre.getForme();
  int x=lettre.getX();
  int y=lettre.getY();
  wattron(win,COLOR_PAIR(c));
  while(i>0){
    if(x==lettre.getX()+lettre.getWidth()){
      x=lettre.getX();
      y+=1;
    }
    if((i%10)!=0)
      mvwaddch(win,y,x,ch);
    i=i/10;
    x+=1;
  }
  wattroff(win,COLOR_PAIR(c));
  update();
 }

int Window::getX() const { return startx;} 
int Window::getY() const { return starty;} 
int Window::getHeight() const { return height;} 
int Window::getWidth() const { return width;}  
Color Window::getCouleurBordure() const{ return colorframe;}
Color Window::getCouleurFenetre() const{ return colorwin;}

void Window::setCouleurBordure(Color c){
  colorframe=c;
  wattron(frame,COLOR_PAIR(colorframe));
  wborder(frame, bord,bord,bord,bord,bord,bord,bord,bord);
  update();
}

void Window::setCouleurFenetre(Color c){
  colorwin=c;
  wattron(win,COLOR_PAIR(colorwin));
  wbkgd(win,COLOR_PAIR(colorwin));
  update();  
}

void Window::clear() const{ werase(win); update(); }

int termSize(bool b){
  struct winsize size;
  ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
  if(b)
    return size.ws_col;
  return size.ws_row;  
}
