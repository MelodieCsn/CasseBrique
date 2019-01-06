#include "title.h"
#include <unistd.h>

Title::Title(int X, int Y) : win(5,44,X,Y){
  data[0]=Lettre(0,0,'c');
  data[1]=Lettre(4,0,'a');
  data[2]=Lettre(8,0,'s');
  data[3]=Lettre(12,0,'s');
  data[4]=Lettre(16,0,'e');
  data[5]=Lettre(20,2,'-');
  data[6]=Lettre(23,0,'b');
  data[7]=Lettre(27,0,'r');
  data[8]=Lettre(31,0,'i');
  data[9]=Lettre(33,0,'q');
  data[10]=Lettre(37,0,'u');
  data[11]=Lettre(41,0,'e');
  
  win.setCouleurBordure(BBLACK);
}

void Title::fade(bool b) const {
  if(b)
    for(int i=11;i>-1;i--){
      win.print(data[i],BBLACK);
      usleep(100000);
    }
  else
    for(int i=0;i<12;i++){
      win.print(data[i],WWHITE);
      usleep(200000);
    }
}

void Title::clignoter() const {
  for(int i=0;i<12;i++)
      win.print(data[i],WMAGENTA);
  usleep(200000);
  for(int i=0;i<12;i++)
      win.print(data[i],WBLUE);
  usleep(200000);
  for(int i=0;i<12;i++)
      win.print(data[i],WGREEN);
  usleep(200000);
  for(int i=0;i<12;i++)
      win.print(data[i],WYELLOW);
  usleep(200000);
  for(int i=0;i<12;i++)
      win.print(data[i],WRED);
  usleep(200000);
  for(int i=0;i<12;i++)
      win.print(data[i],BBLACK);
  usleep(200000);
  for(int i=0;i<12;i++)
      win.print(data[i],WWHITE);
  usleep(200000);
}
