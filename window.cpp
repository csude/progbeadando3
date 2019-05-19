#include "window.hpp"
#include "graphics.hpp"
#include "widgets.hpp"
#include "iostream"
using namespace genv;

Window::~Window(){
  for(Widget *widget: widgets){
    delete widget;
  }
}

void Window::register_w(Widget *w) {
  widgets.push_back(w);
}


void Window::event_loop() {
    event ev;
    int focus = 0;
    while(gin >> ev && ev.keycode != key_escape) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                }
            }
        }
        if (ev.type == ev_key && ev.keycode == key_up && focus > 8){focus -= 9;}
        if (ev.type == ev_key && ev.keycode == key_right && focus!=80){focus += 1;}
        if (ev.type == ev_key && ev.keycode == key_down && focus < 72){focus += 9;}
        if (ev.type == ev_key && ev.keycode == key_left && focus != 0){focus -= 1;}
        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }
        gout << move_to(0,0) << color(230,230,250) << box(600,600);
        gout << move_to(216,100)<<color(0,0,0)<<box(3,355);
        gout << move_to(336,100)<<color(0,0,0)<<box(3,355);
        gout << move_to(100,216)<<color(0,0,0)<<box(355,3);
        gout << move_to(100,336)<<color(0,0,0)<<box(355,3);
        for (Widget * w : widgets) {
            w->draw();
        }
        if (focus != -1){
            widgets[focus]->selectDraw();
        }

        gout << refresh;
    }

}
