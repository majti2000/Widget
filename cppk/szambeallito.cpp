#include "szambeallito.hpp"
#include "graphics.hpp"
using namespace genv;
using namespace std;

Szambeallito::Szambeallito(int x, int y, string szam)
    : Widget(x,y,gout.twidth(szam)+30, gout.cdescent() + gout.cdescent() + 30), sz(szam)
{
    _checked=false;
}

void Szambeallito::draw()
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
        gout << color(255,255,255) ;
        gout << move_to(_x+3, _y+_size_y/2) << text(sz);
        gout << move_to(_x+_size_x,_y) << box(_size_y/2,_size_y/2) << color(0,0,0) << move_to(_x+_size_x+2,_y+2)
        << box(_size_y/2-4, _size_y/2-4) << color(255,255,255) << move_to(_x+_size_x+_size_y/6,_y+_size_y/2) << text("^");
        gout << move_to(_x+_size_x,_y+_size_y/2) << box(_size_y/2,_size_y/2) << color(0,0,0) 
        << move_to(_x+_size_x+2,_y+_size_y/2+2) << box(_size_y/2-4, _size_y/2-4)
        << color(255,255,255) << move_to(_x+_size_x+_size_y/6,_y+_size_y/3+_size_y/2) << text("v");
    if (_checked){
        gout << move_to(_x+_size_x,_y) << box(_size_y/2,_size_y/2) << color(255,255,255) << move_to(_x+_size_x+2,_y+2)
        << box(_size_y/2-4, _size_y/2-4) << color(0,0,0) << move_to(_x+_size_x+_size_y/6,_y+_size_y/2) << text("^");
        gout << move_to(_x+_size_x,_y+_size_y/2) << box(_size_y/2,_size_y/2) << color(255,255,255) 
        << move_to(_x+_size_x+2,_y+_size_y/2+2) << box(_size_y/2-4, _size_y/2-4)
        << color(0,0,0) << move_to(_x+_size_x+_size_y/6,_y+_size_y/3+_size_y/2) << text("v");
    }
        
    
}

void Szambeallito::handle(event ev)
{
    if (ev.type == ev_key && (ev.keycode == key_enter || ev.keycode == ' ')) {
            _checked = !_checked;
    }
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        _checked = !_checked;
    }
}

bool Szambeallito::is_checked() 
{
    return _checked;
}
