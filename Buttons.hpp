#ifndef BUTTONS_H
#define BUTTONS_H
#include "widgets.hpp"
#include<functional>

class Button: public Widget
{
protected:
    char szam;
    bool _kiad;
public:
  Button(Window *w, int x, int y, int sx, int sy);
  void draw() override;
  void selectDraw() override;
  char handle(genv::event ev) override;

};

#endif /* BUTTONS_H */
