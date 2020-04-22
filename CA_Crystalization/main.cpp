// generated by Fast Light User Interface Designer (fluid) version 1.0305

#include "main.h"
#include <time.h>
#include <stdlib.h>
#include <FL/Fl_Image.H>
#include <cmath>
#include <FL/Fl_Shared_Image.H>

int border_condition=0;

int nuclei=0;

int neighborhood=0;

int hex_type=0;

Fl_Double_Window *window_main=(Fl_Double_Window *)0;

Fl_Value_Input *input_scale=(Fl_Value_Input *)0;

Fl_Value_Input *input_cellsX=(Fl_Value_Input *)0;

Fl_Value_Input *input_cellsY=(Fl_Value_Input *)0;

Fl_Value_Input *input_radiusN=(Fl_Value_Input *)0;

Fl_Round_Button *btn_hand=(Fl_Round_Button *)0;

static void cb_btn_hand(Fl_Round_Button*, void*) {
  callback_hand();
}

Fl_Round_Button *btn_regular=(Fl_Round_Button *)0;

static void cb_btn_regular(Fl_Round_Button*, void*) {
  callback_regular();
}

Fl_Round_Button *btn_random=(Fl_Round_Button *)0;

static void cb_btn_random(Fl_Round_Button*, void*) {
  callback_random();
}

Fl_Round_Button *btn_periodic=(Fl_Round_Button *)0;

static void cb_btn_periodic(Fl_Round_Button*, void*) {
  callback_periodic();
}

Fl_Round_Button *btn_absorbing=(Fl_Round_Button *)0;

static void cb_btn_absorbing(Fl_Round_Button*, void*) {
  callback_absorbing();
}

Fl_Round_Button *btn_neumann=(Fl_Round_Button *)0;

static void cb_btn_neumann(Fl_Round_Button*, void*) {
  callback_neumann();
}

Fl_Round_Button *btn_moore=(Fl_Round_Button *)0;

static void cb_btn_moore(Fl_Round_Button*, void*) {
  callback_moore();
}

Fl_Round_Button *btn_pentagonal=(Fl_Round_Button *)0;

static void cb_btn_pentagonal(Fl_Round_Button*, void*) {
  callback_pentagonal();
}

Fl_Round_Button *btn_hexagonal=(Fl_Round_Button *)0;

static void cb_btn_hexagonal(Fl_Round_Button*, void*) {
  callback_hexagonal();
}

Fl_Round_Button *btn_radial=(Fl_Round_Button *)0;

static void cb_btn_radial(Fl_Round_Button*, void*) {
  callback_radial();
}

Fl_Round_Button *btn_left=(Fl_Round_Button *)0;

static void cb_btn_left(Fl_Round_Button*, void*) {
  callback_left();
}

Fl_Round_Button *btn_right=(Fl_Round_Button *)0;

static void cb_btn_right(Fl_Round_Button*, void*) {
  callback_right();
}

Fl_Round_Button *btn_randomN=(Fl_Round_Button *)0;

static void cb_btn_randomN(Fl_Round_Button*, void*) {
  callback_randomN();
}

static void cb_window_choose(Fl_Double_Window*,void*){
  callback_done();
}

Fl_Button *btn_start=(Fl_Button *)0;

static void cb_btn_start(Fl_Button*, void*) {
  callback_start();
}

static void cb_window_result(Fl_Double_Window*,void*){
  callback_close();
}

Fl_Value_Input *input_nucleiX=(Fl_Value_Input *)0;

Fl_Value_Input *input_nucleiY=(Fl_Value_Input *)0;

Fl_Value_Input *input_nucleiR=(Fl_Value_Input *)0;

Fl_Value_Input *input_radius=(Fl_Value_Input *)0;

int main() {
  { window_main = new Fl_Double_Window(800, 320, "Rozrost ziaren");
    { input_scale = new Fl_Value_Input(125, 43, 32, 32, "Scale:");
      input_scale->minimum(1);
      input_scale->maximum(100);
      input_scale->value(16);
    } // Fl_Value_Input* input_scale
    { input_cellsX = new Fl_Value_Input(125, 8, 32, 32, "Number of cells:");
      input_cellsX->minimum(5);
      input_cellsX->maximum(100);
      input_cellsX->value(32);
    } // Fl_Value_Input* input_cellsX
    { input_cellsY = new Fl_Value_Input(170, 8, 32, 32, "x");
      input_cellsY->minimum(5);
      input_cellsY->maximum(100);
      input_cellsY->value(16);
    } // Fl_Value_Input* input_cellsY
    { btn_hand = new Fl_Round_Button(10, 140, 96, 35, "Hand-Chosen");
      btn_hand->down_box(FL_ROUND_DOWN_BOX);
      btn_hand->callback((Fl_Callback*)cb_btn_hand);
      btn_hand->set();
    } // Fl_Round_Button* btn_hand
    { btn_regular = new Fl_Round_Button(10, 175, 96, 35, "Regular");
      btn_regular->down_box(FL_ROUND_DOWN_BOX);
      btn_regular->callback((Fl_Callback*)cb_btn_regular);
    } // Fl_Round_Button* btn_regular
    { btn_random = new Fl_Round_Button(10, 210, 96, 35, "Random");
      btn_random->down_box(FL_ROUND_DOWN_BOX);
      btn_random->callback((Fl_Callback*)cb_btn_random);
    } // Fl_Round_Button* btn_random
    { btn_periodic = new Fl_Round_Button(225, 35, 96, 25, "Periodic");
      btn_periodic->down_box(FL_ROUND_DOWN_BOX);
      btn_periodic->callback((Fl_Callback*)cb_btn_periodic);
      btn_periodic->set();
    } // Fl_Round_Button* btn_periodic
    { btn_absorbing = new Fl_Round_Button(225, 60, 96, 25, "Absorbing");
      btn_absorbing->down_box(FL_ROUND_DOWN_BOX);
      btn_absorbing->callback((Fl_Callback*)cb_btn_absorbing);
    } // Fl_Round_Button* btn_absorbing
    { btn_neumann = new Fl_Round_Button(440, 35, 96, 25, "von Neumann");
      btn_neumann->down_box(FL_ROUND_DOWN_BOX);
      btn_neumann->callback((Fl_Callback*)cb_btn_neumann);
      btn_neumann->set();
    }
    { btn_moore = new Fl_Round_Button(440, 60, 96, 25, "Moore");
      btn_moore->down_box(FL_ROUND_DOWN_BOX);
      btn_moore->callback((Fl_Callback*)cb_btn_moore);
    }
    { btn_pentagonal = new Fl_Round_Button(440, 85, 96, 25, "Pentagonal");
      btn_pentagonal->down_box(FL_ROUND_DOWN_BOX);
      btn_pentagonal->callback((Fl_Callback*)cb_btn_pentagonal);
    }
    { btn_hexagonal = new Fl_Round_Button(440, 110, 96, 25, "Hexagonal");
      btn_hexagonal->down_box(FL_ROUND_DOWN_BOX);
      btn_hexagonal->callback((Fl_Callback*)cb_btn_hexagonal);
    }
    { btn_left = new Fl_Round_Button(580, 110, 60, 25, "Left");
      btn_left->down_box(FL_ROUND_DOWN_BOX);
      btn_left->callback((Fl_Callback*)cb_btn_left);
      btn_left->deactivate();
      btn_left->set();
    }
    { btn_right = new Fl_Round_Button(640, 110, 60, 25, "Right");
      btn_right->down_box(FL_ROUND_DOWN_BOX);
      btn_right->callback((Fl_Callback*)cb_btn_right);
      btn_right->deactivate();
    }
    { btn_randomN = new Fl_Round_Button(700, 110, 80, 25, "Random");
      btn_randomN->down_box(FL_ROUND_DOWN_BOX);
      btn_randomN->callback((Fl_Callback*)cb_btn_randomN);
      btn_randomN->deactivate();
    }
    { btn_radial = new Fl_Round_Button(440, 135, 96, 25, "Radial");
      btn_radial->down_box(FL_ROUND_DOWN_BOX);
      btn_radial->callback((Fl_Callback*)cb_btn_radial);
    }
    { input_radiusN = new Fl_Value_Input(640, 135, 32, 32, "Radius:");
      input_radiusN->minimum(8);
      input_radiusN->maximum(100);
      input_radiusN->value(2);
      input_radiusN->deactivate();
    }
    { btn_start = new Fl_Button(205, 288, 50, 35, "Start");
      btn_start->callback((Fl_Callback*)cb_btn_start);
    } // Fl_Button* btn_start
    { input_nucleiX = new Fl_Value_Input(255, 177, 32, 32, "Number of nuclei:");
      input_nucleiX->minimum(8);
      input_nucleiX->maximum(100);
      input_nucleiX->value(8);
      input_nucleiX->deactivate();
    } // Fl_Value_Input* input_nucleiX
    { input_nucleiY = new Fl_Value_Input(300, 177, 32, 32, "x");
      input_nucleiY->minimum(8);
      input_nucleiY->maximum(100);
      input_nucleiY->value(4);
      input_nucleiY->deactivate();
    } // Fl_Value_Input* input_nucleiY
    { new Fl_Box(280, 5, 25, 25, "Boundary condition:");
    } // Fl_Box* o
    { new Fl_Box(480, 5, 25, 25, "Neighborhood:");
    } // Fl_Box* o
    { new Fl_Box(50, 110, 25, 25, "Nuclei choice:");
    } // Fl_Box* o
    { input_nucleiR = new Fl_Value_Input(254, 212, 32, 32, "Number of nuclei:");
      input_nucleiR->minimum(8);
      input_nucleiR->maximum(100);
      input_nucleiR->value(5);
      input_nucleiR->deactivate();
    } // Fl_Value_Input* input_nucleiR
    { input_radius = new Fl_Value_Input(354, 212, 32, 32, "Radius:");
      input_radius->minimum(8);
      input_radius->maximum(100);
      input_radius->value(5);
      input_radius->deactivate();
    } // Fl_Value_Input* input_radius
    window_main->size_range(800, 320, 800, 320);
    window_main->end();
  } // Fl_Double_Window* window_main
  window_main->show();
    return Fl::run();
}

void callback_hand() {
  btn_hand->value(1);
  btn_regular->value(0);
  btn_random->value(0);
  input_nucleiX->deactivate();
  input_nucleiY->deactivate();
  input_nucleiR->deactivate();
  input_radius->deactivate();
  nuclei=0;
}

void callback_regular() {
  btn_hand->value(0);
  btn_regular->value(1);
  btn_random->value(0);
  input_nucleiX->activate();
  input_nucleiY->activate();
  input_nucleiR->deactivate();
  input_radius->deactivate();
  nuclei=1;
}

void callback_random() {
  btn_hand->value(0);
  btn_regular->value(0);
  btn_random->value(1);
  input_nucleiX->deactivate();
  input_nucleiY->deactivate();
  input_nucleiR->activate();
  input_radius->activate();
  nuclei=2;
}

void callback_absorbing() {
  btn_absorbing->value(1);
  btn_periodic->value(0);
  border_condition=1;
}

void callback_periodic() {
  btn_absorbing->value(0);
  btn_periodic->value(1);
  border_condition=0;
}

void callback_neumann() {
  btn_neumann->value(1);
  btn_moore->value(0);
  btn_pentagonal->value(0);
  btn_hexagonal->value(0);
  btn_radial->value(0);
  neighborhood=0;
  btn_left->deactivate();
  btn_right->deactivate();
  btn_randomN->deactivate();
  input_radiusN->deactivate();
}

void callback_moore() {
  btn_neumann->value(0);
  btn_moore->value(1);
  btn_pentagonal->value(0);
  btn_hexagonal->value(0);
  btn_radial->value(0);
  neighborhood=1;
  btn_left->deactivate();
  btn_right->deactivate();
  btn_randomN->deactivate();
  input_radiusN->deactivate();
}

void callback_pentagonal() {
  btn_neumann->value(0);
  btn_moore->value(0);
  btn_pentagonal->value(1);
  btn_hexagonal->value(0);
  btn_radial->value(0);
  neighborhood=2;
  btn_left->deactivate();
  btn_right->deactivate();
  btn_randomN->deactivate();
  input_radiusN->deactivate();
}

void callback_hexagonal() {
  btn_neumann->value(0);
  btn_moore->value(0);
  btn_pentagonal->value(0);
  btn_hexagonal->value(1);
  btn_radial->value(0);
  neighborhood=3;
  btn_left->activate();
  btn_right->activate();
  btn_randomN->activate();
  input_radiusN->deactivate();
}

void callback_radial() {
  btn_neumann->value(0);
  btn_moore->value(0);
  btn_pentagonal->value(0);
  btn_hexagonal->value(0);
  btn_radial->value(1);
  neighborhood=4;
  btn_left->deactivate();
  btn_right->deactivate();
  btn_randomN->deactivate();
  input_radiusN->activate();
}

void callback_left() {
  btn_left->value(1);
  btn_right->value(0);
  btn_randomN->value(0);
  hex_type=0;
}

void callback_right() {
  btn_left->value(0);
  btn_right->value(1);
  btn_randomN->value(0);
  hex_type=1;
}

void callback_randomN() {
  btn_left->value(0);
  btn_right->value(0);
  btn_randomN->value(1);
  hex_type=2;
}

Fl_Double_Window *window_result=(Fl_Double_Window *)0;

Imagebox *result=(Imagebox *)0;

Fl_Double_Window *window_choose=(Fl_Double_Window *)0;

Fl_Button *btn_done=(Fl_Button *)0;

static void cb_btn_done(Fl_Button*, void*) {
  callback_done();
}

int callback_start() {
  int x=input_cellsX->value();
  int y=input_cellsY->value();
  int s=input_scale->value();
  int parameterA=0,parameterB=0,parameterC=0;
  switch(nuclei){
    case 1:
      parameterA=input_nucleiX->value();
      parameterB=input_nucleiY->value();
      break;
    case 2:
      parameterA=input_nucleiR->value();
      parameterB=input_radius->value();
      break;
  }
  switch(neighborhood){
    case 3:
      parameterC=hex_type;
      break;
    case 4:
      parameterC=input_radiusN->value();
  }
  { window_result = new Fl_Double_Window(x*s, y*s, "Results");
    { result = new Imagebox(s,x,y,nuclei,parameterA,parameterB,border_condition,neighborhood,parameterC);
      result->box(FL_FLAT_BOX);
      result->color(FL_BACKGROUND2_COLOR);
      result->selection_color(FL_BACKGROUND_COLOR);
      result->labeltype(FL_NORMAL_LABEL);
      result->labelfont(0);
      result->labelsize(14);
      result->labelcolor(FL_FOREGROUND_COLOR);
      result->align(Fl_Align(FL_ALIGN_CENTER));
      result->when(FL_WHEN_RELEASE);
    } // Imagebox* result
    window_result->callback((Fl_Callback*)cb_window_result);
    window_result->end();
  } // Fl_Double_Window* window_result
  { window_choose = new Fl_Double_Window(195, 70);
    { btn_done = new Fl_Button(70, 35, 55, 30, "Done");
      btn_done->callback((Fl_Callback*)cb_btn_done);
    } // Fl_Button* btn_done
    { new Fl_Box(70, 5, 55, 30, "Choose nuclei cells.");
    } // Fl_Box* o
    window_choose->callback((Fl_Callback*)cb_window_choose);
    window_choose->end();
  } // Fl_Double_Window* window_choose

  window_result->show();
  if(nuclei==0){
    result->draw_image();
    window_choose->show();
  }
  else{
    result->create_nuclei();
    result->set_colors();
    Fl::add_timeout(result->speed,callback_grow);
  }
  return Fl::run();
}


void callback_done() {
  window_choose->hide();
  result->create_nuclei();
  result->set_colors();
  Fl::add_timeout(result->speed,callback_grow);
}

void callback_grow(void*){
  if(result->grow()>0)
    Fl::add_timeout(result->speed,callback_grow);
}
void callback_close(){
  delete result->current_image;
  delete result->next_image;
  delete result->neighbors;
  if(result->neighborhood==4)
    delete result->offset;
  delete result->colors;
  delete result;
  delete window_choose;
  delete window_result;
}