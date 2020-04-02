#ifndef IMAGEBOX_H
#define IMAGEBOX_H
#include <FL/Fl_Box.H>
#include "imageStack.h"
class Imagebox:public Fl_Box{
  public:
    Imagebox(int,int,int,int,const char* label=0);
    int handle(int);
    int** make_image_array(int, int,int);
    void draw_image(int, int,int**);

};



#endif
