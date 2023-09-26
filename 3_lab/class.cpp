#include "class.hpp"
#include <stdlib.h>

Point::Point(){
    x = 400;
    y = 300;
    speed_x = -3 + rand() % 7;
    speed_y = -3 + rand() % 7;
    rgba_color = new int[4]{
        rand()%255,
        rand()%255,
        rand()%255,
        rand()%255
    };
}

void Point::reflection(int x, int y){
        if (x >= 800-8 || x <= 0+8)
            speed_x *= -1;
        
        if (y >= 600-8 || y <= 0+8)
            speed_y *= -1;
    }

int Point::get_x(){
    return x;
}
int Point::get_y(){
    return y;
}

void Point::set_x(int new_x){
    x = new_x;
}
void Point::set_y(int new_y){
    y = new_y;
}