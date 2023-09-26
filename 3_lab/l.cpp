#include <SDL2/SDL.h>
#include <iostream>
#include <stdlib.h>
#include "class.hpp"

using namespace std;

void delete_points(Point point[], int size){
    for (int i = 0; i < size; i++)
        delete point[i].rgba_color;
    delete point;
}

void DrawCircle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius)
{
   const int32_t diameter = (radius * 2);
   int32_t x = (radius - 1);
   int32_t y = 0;
   int32_t tx = 1;
   int32_t ty = 1;
   int32_t error = (tx - diameter);
   while (x >= y)
   {
      SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);
      if (error <= 0)
      {
         ++y;
         error += ty;
         ty += 2;
      }
      if (error > 0)
      {
         --x;
         tx += 2;
         error += (tx - diameter);
      }
   }
}

int main()
{
    const int windowWidth = 800;
    const int windowHeight = 600;
    int size_points = 100;
    srand(time(NULL));

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return 1;
        cout << "Initialization failed" << endl;
    }

    SDL_Window *window = SDL_CreateWindow("Точки в кружках",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth,
            windowHeight, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        SDL_Quit();
        return 2;
    }

    SDL_Renderer *s = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC) ;
    
    bool quit = false;
    SDL_Event event;

    Point *point = new Point[size_points];
    int timer = 0;

    while (!quit){
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
        SDL_RenderClear(s);
        for (int i = 0; i < size_points; i++)
        {
            SDL_SetRenderDrawColor(s, point[i].rgba_color[0], point[i].rgba_color[1], point[i].rgba_color[2], point[i].rgba_color[3]);
            
            DrawCircle(s, point[i].get_x(), point[i].get_y(), 8);
            // SDL_RenderDrawPoint(s, point[i].get_x(), point[i].get_y());

            point[i].set_x(point[i].get_x() + point[i].speed_x);
            point[i].set_y(point[i].get_y() + point[i].speed_y);

            SDL_SetRenderDrawColor(s, 0x00, 0x00, 0x00, 0xFF);
            point[i].reflection(point[i].get_x(), point[i].get_y());
        }
        if (timer == 6)
        {
            point[rand()%size_points].speed_x = (-2 + rand() % 5);
            point[rand()%size_points].speed_y = (-2 + rand() % 5);
            timer = 0;
        }
        timer++;
        SDL_RenderPresent(s);
    }

    SDL_DestroyWindow(window);
    delete_points(point, size_points);
    SDL_DestroyRenderer(s);
    SDL_Quit();
    return 0;
}