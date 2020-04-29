#include "Imagebox.h"
#include <FL/Fl.H>
#include <FL/Fl_Image.H>
#include <iostream>
#include "main.h"
#include <cmath>
#include <time.h>
#include <unistd.h>


Imagebox::Imagebox(int s,int cX,int cY,int preset,int valueA,int valueB,int border,int neighborhood,int valueC,const char* label):Fl_Box(0,32,cX*s,cY*s,label){
  srand(time(NULL));
  this->neighborhood=neighborhood;
  this->border=border;
  this->speed=0.01;
  this->nuclei=1;
  this->scale=s;
  this->cellsX=cX;
  this->cellsY=cY;
  this->radius=valueC;
  create_neighbors(neighborhood,valueC);
  this->current_image=new int*[cellsX];
  this->next_image=new int*[cellsX];
  for(int i=0;i<cellsX;i++){
    this->current_image[i]=new int[cellsY];
    this->next_image[i]=new int[cellsY];
  }
  for(int i=0;i<cellsX;i++)
    for(int j=0;j<cellsY;j++){
      this->current_image[i][j]=0;
      this->next_image[i][j]=0;
    }
  int x,y,n=0;
  int** tab;
  bool flag=false;
  switch(preset){
    case 1:
      x=cellsX/valueA;
      y=cellsY/valueB;
      for(int i=x/2;i<cellsX;i+=x)
        for(int j=y/2;j<cellsY;j+=y){
          this->current_image[i][j]=1;
        }
      break;
    case 2:
      tab=new int*[valueA];
      for(int i=0;i<valueA;i++)
         tab[i]=new int[2];
      int total=cellsX*cellsY;
      for(int i=0;i<valueA;i++){
        if(total<=0)break;
        int nr=rand()%total;
        for(int i=0;i<cellsX;i++)
          for(int j=0;j<cellsY;j++){
            if(current_image[i][j]==0)
              if(!nr--){
                current_image[i][j]=1;
                total--;
                if(valueB>0){
                  for(int k=valueB*(-1);k<=valueB;k++)
                    for(int l=valueB*(-1);l<=valueB;l++)
                      if(current_image[(i+k+cellsX)%cellsX][(j+l+cellsY)%cellsY]==0&&sqrt(pow(k,2)+pow(l,2))<=valueB){
                        current_image[(i+k+cellsX)%cellsX][(j+l+cellsY)%cellsY]=2;
                        total--;
                      }
                }
                goto doublebreak;
              }
          }
        doublebreak:;
      }
      for(int i=0;i<valueA;i++)
        delete[] tab[i];
      delete[] tab;
  }
}
void Imagebox::draw_image() {
  int size=w()*h()*4;
  unsigned char* image_data=new unsigned char[size];
  for(int i=0;i<cellsY;i++)
    for(int j=0;j<cellsX;j++){
      int R=255;
      int G=255;
      int B=255;
      if (current_image[j][i]>0){
        if(nuclei>1){
            R=colors[current_image[j][i]-1];
            G=colors[current_image[j][i]-1];
        }
        else {
          R=0;
          G=0;
        }
        B=0;
      }
      for(int k=0;k<scale;k++)
        for(int l=0;l<scale;l++){
          image_data[((i*scale*scale+k*scale)*cellsX+j*scale+l)*4]=R;
          image_data[((i*scale*scale+k*scale)*cellsX+j*scale+l)*4+1]=G;
          image_data[((i*scale*scale+k*scale)*cellsX+j*scale+l)*4+2]=B;
          image_data[((i*scale*scale+k*scale)*cellsX+j*scale+l)*4+3]=255;
        }
    }
  Fl_Image *image=new Fl_RGB_Image(image_data,cellsX*scale,cellsY*scale,4,0);
  this->image(image);
}
void Imagebox::draw_energy() {
  int size=w()*h()*4;
  unsigned char* image_data=new unsigned char[size];
  for(int i=0;i<cellsY;i++)
    for(int j=0;j<cellsX;j++){
      int R=255/neighbor_number*next_image[j][i];
      int G=255-255/neighbor_number*next_image[j][i];
      int B=0;
      for(int k=0;k<scale;k++)
        for(int l=0;l<scale;l++){
          image_data[((i*scale*scale+k*scale)*cellsX+j*scale+l)*4]=R;
          image_data[((i*scale*scale+k*scale)*cellsX+j*scale+l)*4+1]=G;
          image_data[((i*scale*scale+k*scale)*cellsX+j*scale+l)*4+2]=B;
          image_data[((i*scale*scale+k*scale)*cellsX+j*scale+l)*4+3]=255;
        }
    }
  Fl_Image *image=new Fl_RGB_Image(image_data,cellsX*scale,cellsY*scale,4,0);
  this->image(image);
}
int Imagebox::handle(int event){

  if(event!=FL_PUSH||!window_choose->shown())
    return 0;
  if(current_image[Fl::event_x()/scale][(Fl::event_y()-32)/scale]==0)
    current_image[Fl::event_x()/scale][(Fl::event_y()-32)/scale]=1;
  else current_image[Fl::event_x()/scale][(Fl::event_y()-32)/scale]=0;
  draw_image();
  window_result->redraw();
  return 1;
}
void Imagebox::create_nuclei(){
  draw_image();
  for(int i=0;i<cellsX;i++)
    for(int j=0;j<cellsY;j++){
      if(current_image[i][j]==1){
        current_image[i][j]=nuclei;
        nuclei++;
      }
      else current_image[i][j]=0;
    }
  nuclei--;

  window_result->redraw();
}

void Imagebox::set_colors(){
  colors=new int[nuclei];
  int* n=new int[nuclei];
  for(int i=0;i<nuclei;i++)
    n[i]=(255/nuclei)*(i);
  int c=nuclei;
  for(int j=0;j<nuclei;j++){
    int r=rand()%c;
    for(int i=0;i<nuclei;i++){
      if(n[i]==-1)
        continue;
      if(r>0){
        r--;
        continue;
      }
      c--;
      colors[j]=n[i];
      n[i]=-1;
      break;
    }
  }
}

int Imagebox::grow(){
  int changed=0;
  for(int i=0;i<cellsX;i++)
    for(int j=0;j<cellsY;j++)
      if(current_image[i][j]==0){
        int v=check_neighbors(i,j,neighborhood,border);
        if(v>0){
          next_image[i][j]=v;
          changed++;
        }
      }
  if(changed!=0){
    for(int i=0;i<cellsX;i++)
      for(int j=0;j<cellsY;j++)
        current_image[i][j]=next_image[i][j];
    draw_image();
    window_result->redraw();
  }
  return changed;
}
void Imagebox::make_energy_array(){
  for(int x=0;x<cellsX;x++)
    for(int y=0;y<cellsY;y++){
      int* tab=new int[nuclei];
      for(int i=0;i<nuclei;i++)
        tab[i]=0;
      int real_neighbors=0;
      for(int k=0;k<neighbor_number;k++){
        int dx=neighbors[x][y][k][0];
        int dy=neighbors[x][y][k][1];
        if((border==1)&&(x+dx<0||x+dx>=cellsX||y+dy<0||y+dy>=cellsY))
          continue;
        if (neighborhood==4){
          double dX=dx-offset[x][y][0]+offset[(x+dx+cellsX)%cellsX][(y+dy+cellsY)%cellsY][0];
          double dY=dy-offset[x][y][1]+offset[(x+dx+cellsX)%cellsX][(y+dy+cellsY)%cellsY][1];
          double l=sqrt(pow(dX,2)+pow(dY,2));
          if(l>radius)
            continue;
        }
        if(current_image[(x+dx+cellsX)%cellsX][(y+dy+cellsY)%cellsY]>0)
          tab[current_image[(x+dx+cellsX)%cellsX][(y+dy+cellsY)%cellsY]-1]++;
        real_neighbors++;
      }
      int pool=0;
      for(int i=0;i<nuclei;i++)
        if(tab[i]>0)pool++;
      pool--;
      int energy=real_neighbors-tab[current_image[x][y]-1];;
      next_image[x][y]=energy;
  }
}
int Imagebox::monte_carlo(int& iterations,double kt,bool def){
  bool** tab=new bool*[cellsX];
  for(int i=0;i<cellsX;i++){
    tab[i]=new bool[cellsY];
    for(int j=0;j<cellsY;j++)
    tab[i][j]=false;
  }
  int total=cellsX*cellsY;
  while(total>0){
    int nr=rand()%total;
    for(int i=0;i<cellsX;i++)
      for(int j=0;j<cellsY;j++)
        if(tab[i][j]==false)
          if(!nr--){
            total--;
            tab[i][j]==true;
            mc_try(i,j,kt);
            goto doublebreak;
          }
    doublebreak:;
  }
  for(int i=0;i<cellsX;i++)
    delete[] tab[i];
  delete tab;
  if(def==true){
    for(int i=0;i<cellsX;i++)
      for(int j=0;j<cellsY;j++)
        mc_try(i,j,kt,false);
    draw_energy();
  }
  else draw_image();
  window_result->redraw();
  return --iterations;
}

void Imagebox::mc_try(int x,int y,double kt,bool change){
  int* tab=new int[nuclei];
  for(int i=0;i<nuclei;i++)
    tab[i]=0;
  int real_neighbors=0;
  for(int k=0;k<neighbor_number;k++){
    int dx=neighbors[x][y][k][0];
    int dy=neighbors[x][y][k][1];
    if((border==1)&&(x+dx<0||x+dx>=cellsX||y+dy<0||y+dy>=cellsY))
      continue;
    if (neighborhood==4){
      double dX=dx-offset[x][y][0]+offset[(x+dx+cellsX)%cellsX][(y+dy+cellsY)%cellsY][0];
      double dY=dy-offset[x][y][1]+offset[(x+dx+cellsX)%cellsX][(y+dy+cellsY)%cellsY][1];
      double l=sqrt(pow(dX,2)+pow(dY,2));
      if(l>radius)
        continue;
    }
    if(current_image[(x+dx+cellsX)%cellsX][(y+dy+cellsY)%cellsY]>0)
      tab[current_image[(x+dx+cellsX)%cellsX][(y+dy+cellsY)%cellsY]-1]++;
    real_neighbors++;
  }
  int pool=0;
  for(int i=0;i<nuclei;i++)
    if(tab[i]>0)pool++;
  pool--;
  int energy=real_neighbors;
  int before=energy-tab[current_image[x][y]-1];
  next_image[x][y]=before;
  if(pool>0&&change==true){
    int after=0;
    int nr=rand()%pool;
    for(int i=0;i<nuclei;i++){
      if (tab[i]==0||i==current_image[x][y]-1)
        continue;
      if(--nr){
        after=energy-tab[i];
        nr=i+1;
        break;
      }
    }
    int p;
    if(after-before<=0)
      p=1;
    else p=exp((before-after)/kt);
    double l=((double)(rand()%10000))/10000;
    if(l<p){
      current_image[x][y]=nr;
      next_image[x][y]=after;
    }
  }
  delete[] tab;
}

int Imagebox::check_neighbors(int x,int y,int neighborhood,int border){
  int* tab=new int[nuclei];
  for(int i=0;i<nuclei;i++)
    tab[i]=0;
  for(int k=0;k<neighbor_number;k++){
    int dx=neighbors[x][y][k][0];
    int dy=neighbors[x][y][k][1];
    if((border==1)&&(x+dx<0||x+dx>=cellsX||y+dy<0||y+dy>=cellsY))
      continue;
    if (neighborhood==4){
      double dX=dx-offset[x][y][0]+offset[(x+dx+cellsX)%cellsX][(y+dy+cellsY)%cellsY][0];
      double dY=dy-offset[x][y][1]+offset[(x+dx+cellsX)%cellsX][(y+dy+cellsY)%cellsY][1];
      double l=sqrt(pow(dX,2)+pow(dY,2));
      if(l>radius)
        continue;
    }
    if(current_image[(x+dx+cellsX)%cellsX][(y+dy+cellsY)%cellsY]>0)
      tab[current_image[(x+dx+cellsX)%cellsX][(y+dy+cellsY)%cellsY]-1]++;
  }
  int nr=0,val=0;
  for(int i=0;i<nuclei;i++)
    if(tab[i]>val){
      nr=i+1;val=tab[i];
    }
  delete[] tab;
  return nr;
}
void Imagebox::create_neighbors(int type,int param){
  neighbors=new int***[cellsX];
  for(int i=0;i<cellsX;i++)
    neighbors[i]=new int**[cellsY];
  switch(type){
    case 0:{//von Neumann
      int** n=new int*[4];
      for(int i=0;i<4;i++)
        n[i]=new int[2];
      int nr=0;
      for(int i=-1;i<2;i++)
        for(int j=-1;j<2;j++)
          if(abs(i)-abs(j)!=0){
            n[nr][0]=i;
            n[nr][1]=j;
            nr++;
          }
      for(int i=0;i<cellsX;i++)
        for(int j=0;j<cellsY;j++)
          neighbors[i][j]=n;
      neighbor_number=4;
      break;
    }
    case 1:{//Moore
      int** n=new int*[8];
      for(int i=0;i<8;i++)
        n[i]=new int[2];
      int nr=0;
      for(int i=-1;i<2;i++)
        for(int j=-1;j<2;j++){
          if(i==0&&j==0)continue;
          n[nr][0]=i;
          n[nr][1]=j;
          nr++;
        }
      for(int i=0;i<cellsX;i++)
        for(int j=0;j<cellsY;j++)
          neighbors[i][j]=n;
      neighbor_number=8;
      break;
    }
    case 2:{//Pentagonal
      int*** n=new int**[4];
      for(int k=0;k<4;k++){
        n[k]=new int*[5];
        for(int i=0;i<5;i++)
          n[k][i]=new int[2];
      }
      for(int k=-1;k<2;k+=2){
        int nr1=0, nr2=0;
        for(int i=-1;i<2;i++)
          for(int j=-1;j<2;j++){
            if((i!=0||j!=0)&&i!=k){
              n[k+1][nr1][0]=i;
              n[k+1][nr1][1]=j;
              nr1++;
            }
            if((i!=0||j!=0)&&j!=k){
              n[k+2][nr2][0]=i;
              n[k+2][nr2][1]=j;
              nr2++;
            }
          }
      }
      for(int i=0;i<cellsX;i++)
        for(int j=0;j<cellsY;j++)
          neighbors[i][j]=n[rand()%4];
      neighbor_number=5;
      break;
    }
    case 3:{
      switch(param){
        case 0:{
          int** n=new int*[6];
          for(int i=0;i<6;i++)
            n[i]=new int[2];
          int nr=0;
          for(int i=-1;i<2;i++)
            for(int j=-1;j<2;j++){
              if(i==j)continue;
                n[nr][0]=i;
                n[nr][1]=j;
                nr++;
            }
          for(int i=0;i<cellsX;i++)
            for(int j=0;j<cellsY;j++)
              neighbors[i][j]=n;
          break;
        }
        case 1:{
          int** n=new int*[6];
          for(int i=0;i<6;i++)
            n[i]=new int[2];
          int nr=0;
          for(int i=-1;i<2;i++)
            for(int j=-1;j<2;j++){
              if(i+j==0)continue;
                n[nr][0]=i;
                n[nr][1]=j;
                nr++;
            }
          for(int i=0;i<cellsX;i++)
            for(int j=0;j<cellsY;j++)
              neighbors[i][j]=n;
          break;
        }
        case 2:{
          int***n=new int**[2];
          for(int k=0;k<2;k++){
            n[k]=new int*[6];
            for(int i=0;i<6;i++)
              n[k][i]=new int[2];
          }
          int nr1=0,nr2=0;
          for(int i=-1;i<2;i++)
            for(int j=-1;j<2;j++){
              if(i!=j){
                n[0][nr1][0]=i;
                n[0][nr1][1]=j;
                nr1++;
              }
              if(i+j!=0){
                n[1][nr2][0]=i;
                n[1][nr2][1]=j;
                nr2++;
              }
            }
          for(int i=0;i<cellsX;i++)
            for(int j=0;j<cellsY;j++)
              neighbors[i][j]=n[rand()%2];
        }
      }
      neighbor_number=6;
      break;
    }
    case 4:{
      int rect=pow((2*param+1),2)-1;
      int** n=new int*[rect];
      for(int i=0;i<rect;i++)
        n[i]=new int[2];
      int nr=0;
      for(int i=0-param;i<=param;i++)
        for(int j=0-param;j<=param;j++){
          if(i==0&&j==0)continue;
          n[nr][0]=i;
          n[nr][1]=j;
          nr++;
        }
      for(int i=0;i<cellsX;i++)
        for(int j=0;j<cellsY;j++)
          neighbors[i][j]=n;

      offset=new double**[cellsX];
      for(int i=0;i<cellsX;i++){
        offset[i]=new double*[cellsY];
        for(int j=0;j<cellsY;j++){
          offset[i][j]=new double[2];
          offset[i][j][0]=((double)(rand()%998)-499)/1000;
          offset[i][j][1]=((double)(rand()%998)-499)/1000;
        }
      }
      neighbor_number=rect;
    }
  }
}
