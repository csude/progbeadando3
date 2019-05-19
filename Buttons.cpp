#include "Buttons.hpp"
#include <sstream>
#include <string>
using namespace genv;

Button::Button(Window *w, int x, int y, int sx, int sy):
    Widget(w, x, y, sx, sy){}

void Button::draw() {
    gout << move_to(_x, _y) << color(0,100,0) << box(_size_x, _size_y);
    gout<<move_to(_x+12,_y+20)<<color(255,255,255)<<text(szam);
}

void Button::selectDraw(){
    gout<<move_to(_x+2,_y+2)<<color(255,228,181)<<box(_size_x-4,_size_y-4);
    gout<<move_to(_x+12,_y+20)<<color(0,0,255)<<text(szam);
}

char Button::handle(event ev) {
    for(int i =1;i<10;i++){
        char e =' ';
        std::stringstream conv;
        conv << i;
        conv >> e;
        if (ev.type == ev_key && ev.keycode == e){szam = e;_kiad = true;}
    }
    if (ev.type == ev_key && ev.keycode == key_backspace){
        szam = ' ';
        _kiad = true;
    }
}





