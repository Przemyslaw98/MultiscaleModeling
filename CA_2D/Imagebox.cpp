#include "Imagebox.h"
#include <FL/Fl.H>
#include <FL/Fl_Image.H>
#include "imageStack.h"
#include <iostream>
#include "main.h"
Imagebox::Imagebox(int x,int y,int w,int h,const char* label):Fl_Box(x,y,w,h,label){

}
int** Imagebox::make_image_array(int width, int height,int preset) {
  int** outcome=new int*[width];
  for(int i=0;i<width;i++)
    outcome[i]=new int[height];
  for(int i=0;i<width;i++)
    for(int j=0;j<height;j++){
      outcome[i][j]=0;
    }
  int x=width/2,y=height/2;
  switch(preset){
    case 1:
      outcome[x-2][y]=1;
      outcome[x-1][y-1]=1;
      outcome[x-1][y+1]=1;
      outcome[x][y-1]=1;
      outcome[x][y+1]=1;
      outcome[x+1][y]=1;
      break;
    case 2:
      outcome[x][y]=1;
      outcome[x-1][y]=1;
      outcome[x][y-1]=1;
      outcome[x+1][y-1]=1;
      outcome[x+1][y+1]=1;
      break;
    case 3:
      outcome[x][y]=1;
      outcome[x][y-1]=1;
      outcome[x][y+1]=1;
      break;
    case 4:
      for(int i=0;i<width;i++)
        for(int j=0;j<height;j++)
          outcome[i][j]=rand()%2;
  }
  return outcome;
}

void Imagebox::draw_image(int width, int height,int** image_array) {
  unsigned char* image_data=new unsigned char[width*height*1024];
  for(int i=0;i<height;i++)
    for(int j=0;j<width;j++){
      int value;
      if (image_array[j][i]==1)
        value=0;
      else value=255;
      for(int k=0;k<16;k++)
        for(int l=0;l<16;l++){
          image_data[((i*256+k*16)*width+j*16+l)*4]=value;
          image_data[((i*256+k*16)*width+j*16+l)*4+1]=value;
          image_data[((i*256+k*16)*width+j*16+l)*4+2]=value;
          image_data[((i*256+k*16)*width+j*16+l)*4+3]=255;
        }
    }
  Fl_Image *image=new Fl_RGB_Image(image_data,width*16,height*16,4,0);
  this->image(image);
}

int Imagebox::handle(int event){

  if(event!=FL_PUSH)
    return 0;
  int** original_image=stack->peek();
  if(Fl::event_button()!=FL_LEFT_MOUSE||original_image==NULL)
    return 0;
  int width=w()/16;
  int height=h()/16;
  int** edited_image=new int*[width];
  for(int i=0;i<width;i++)
    edited_image[i]=new int[height];
  for(int i=0;i<width;i++)
    for(int j=0;j<height;j++)
      edited_image[i][j]=original_image[i][j];
  if(original_image[Fl::event_x()/16][(Fl::event_y()-55)/16]==0)
    edited_image[Fl::event_x()/16][(Fl::event_y()-55)/16]=1;
  else edited_image[Fl::event_x()/16][(Fl::event_y()-55)/16]=0;
  draw_image(width,height,edited_image);
  //stack->clear();
  stack->push(edited_image);
  btn_prv->activate();
  window_main->redraw();
  return 1;
}
