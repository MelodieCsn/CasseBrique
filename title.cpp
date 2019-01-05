#include "title.h"

Title::Title() : win(20,40,0,0){
  data[0]=Lettre(0,0,'c');
  data[1]=Lettre(4,0,'a');
  data[2]=Lettre(8,0,'s');
  data[3]=Lettre(12,0,'s');
  data[4]=Lettre(16,0,'e');
  data[5]=Lettre(20,2,'-');
  data[6]=Lettre(0,6,'b');
  data[7]=Lettre(4,6,'r');
  data[8]=Lettre(8,6,'i');
  data[9]=Lettre(10,6,'q');
  data[10]=Lettre(14,6,'u');
  data[11]=Lettre(18,6,'e');
  
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
