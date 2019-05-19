#include "graphics.hpp"
#include "widgets.hpp"
#include "window.hpp"
#include "Buttons.hpp"
#include <vector>
#include <iostream>
using namespace std;
using namespace genv;



class MyWindow : public Window {
protected:
    vector <Button> b;
public:
  MyWindow();
};


MyWindow::MyWindow()
{
    for(int i =0;i<81;i++){
       Button *button = new Button(this,100+(i%9)*40,100+(i/9)*40,35,35);
    }
}



int main() {
  gout.open(600, 600);
  MyWindow *window = new MyWindow();
  window->event_loop();
  delete window;
  return 0;
}






