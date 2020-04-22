#ifndef IMAGEBOX_H
#define IMAGEBOX_H
#include <FL/Fl_Box.H>
class Imagebox:public Fl_Box{
  public:
    double speed;
    int neighborhood;
    int neighbor_number=0;
    int border;
    int nuclei;
    int scale;
    int cellsX;
    int cellsY;
    int radius;
    int** current_image;
    int** next_image;
    int**** neighbors;
    double*** offset;
    Imagebox(int,int,int,int,int valueA=0,int valueB=0,int border=0,int neighborhood=0,int valueC=0,const char* label=0);
    int handle(int);
    void draw_image();
    void create_nuclei();
    int grow();
    int check_neighbors(int,int,int,int);
    void create_neighbors(int,int);
    int* colors;
    void set_colors();
};



#endif
