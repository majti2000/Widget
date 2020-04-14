#ifndef SZAMBEALLITO_HPP_INCLUDED
#define SZAMBEALLITO_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

using namespace std;

class Szambeallito : public Widget {
protected:
    bool _checked;
    string sz;
public:
    Szambeallito(int x, int y, string sz);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool is_checked();
};

#endif // SZAMBEALLITO_HPP_INCLUDED