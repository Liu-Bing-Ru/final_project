﻿using namespace std;
#define SDL_MAIN_INCLUDED
#include <iostream>
#include<Windows.h>
#include<stdio.h>
#include<SDL.h>
#include <SDL_image.h>
#undef main
#include <cstring>
#include <cstdlib>
#include <time.h>
// +
#include <SDL_mixer.h>
int start = 0;


SDL_Renderer* renderer;
SDL_Window* window;
bool isRunning;
bool fullscreen;
void handleEvents();
void update();
void render();

int windowW, windowH;

//START*****************************************************************************************
//int cnt = 0;
//bool moveRight = true;
SDL_Event event;

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* ren);

};

class GameObject {
public:
    GameObject(const char* texturesheet, SDL_Renderer* ren, double x, double y, int h, int w);
    ~GameObject();
    void Update();
    void Update2();
    void Update3();
    //+
    void Fall();
    void Fall2();
    void Fall3();
    void Fallbump();
    void Fallbump2();
    // int CollideCat();
    // int CollideBump();

     //void Closewindow();
     //+
    void Render();

private:
    double xpos;
    double ypos;
    int objH;
    int objW;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;
};

SDL_Texture* TextureManager::LoadTexture(const char* fileName, SDL_Renderer* ren)
{
    SDL_Surface* tempSurface = IMG_Load(fileName);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
    SDL_FreeSurface(tempSurface);

    return tex;
}

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren, double x, double y, int h, int w)
{
    renderer = ren;
    objTexture = TextureManager::LoadTexture(texturesheet, ren);

    xpos = x;
    ypos = y;
    objH = h;
    objW = w;
}
double* px1, * py1;
void GameObject::Update()
{
    srcRect.h = objH;
    srcRect.w = objW;

    srcRect.h = 1248.0;
    srcRect.w = 1728.0;
    srcRect.x = 0.0;
    srcRect.y = 0.0;

    destRect.x = xpos;
    destRect.y = ypos;
    px1 = &xpos;
    py1 = &ypos;
    destRect.w = srcRect.w / 3;
    destRect.h = srcRect.h / 3;

    switch (event.type)
    {
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_w:
            ypos += -10;
            break;
            //START*****************************************************************************************
        case SDLK_LEFT:
            if (xpos >= -195)
                xpos += -15;
            break;
        case SDLK_RIGHT:
            if (xpos <= 425)
                xpos += 15;
            break;
            //END*****************************************************************************************
        case SDLK_s:
            ypos += 10;
            break;
        default:
            break;
        }
    case SDL_KEYUP:
        switch (event.key.keysym.sym)
        {
        case SDLK_w:
            xpos += 0;
            break;
        case SDLK_a:
            xpos += 0;
            break;
        case SDLK_d:
            ypos += 0;
            break;
        case SDLK_s:
            ypos += 0;
            break;
        default:
            break;
        }
    }
}

void GameObject::Update2()
{

    srcRect.h = 1800.0;
    srcRect.w = 2400.0;
    srcRect.x = 0.0;
    srcRect.y = 0.0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w / 3;
    destRect.h = srcRect.h / 3;

}
void GameObject::Update3()
{

    srcRect.h = 1800.0;
    srcRect.w = 2400.0;
    srcRect.x = 0.0;
    srcRect.y = 0.0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w / 3;
    destRect.h = srcRect.h / 3;

}

double* fx1, * fy1, * fx2, * fy2, * fx3, * fy3, * bx1, * by1, * bx2, * by2;

//+

void GameObject::Fall()
{
    srcRect.h = 1800.0;
    srcRect.w = 2400.0;
    srcRect.x = 0.0;
    srcRect.y = 0.0;

    destRect.x = xpos;
    destRect.y = ypos;
    if (start == 1) {
        fx1 = &xpos;
        fy1 = &ypos;
    }

    //cout << endl << endl << fx1 << endl << endl;
    destRect.w = srcRect.w / 3;
    destRect.h = srcRect.h / 3;

    for (int i = 0; i < 80; i++)
    {
        if ((i / 2 == 0)) {
            continue;
        }
        else if (xpos > 350) {
            xpos = 10;
        }
        else if (ypos < 400)
        {
            ypos += 0.08;
        }
        else if (ypos <= 450)
        {
            ypos = -400.0;
            xpos += 70;
        }
    }
}


void GameObject::Fall2()
{
    srcRect.h = 1800.0;
    srcRect.w = 2400.0;
    srcRect.x = 0.0;
    srcRect.y = 0.0;

    destRect.x = xpos;
    destRect.y = ypos;
    if (start == 1) {
        fx2 = &xpos;
        fy2 = &ypos;
    }

    destRect.w = srcRect.w / 3;
    destRect.h = srcRect.h / 3;

    for (int i = 0; i < 80; i++)
    {
        if ((i / 5 == 0) or (i / 3 == 0)) {
            continue;
        }
        else if (xpos > 350) {
            xpos = -280;
        }
        else if (ypos < 400)
        {
            ypos += 0.08;
        }
        else if (ypos <= 450)
        {
            ypos = -400.0;
            xpos += 30;
        }
    }
}



void GameObject::Fall3()
{
    srcRect.h = 1800.0;
    srcRect.w = 2400.0;
    srcRect.x = 0.0;
    srcRect.y = 0.0;

    destRect.x = xpos;
    destRect.y = ypos;
    if (start == 1) {
        fx3 = &xpos;
        fy3 = &ypos;
    }

    destRect.w = srcRect.w / 3;
    destRect.h = srcRect.h / 3;

    for (int i = 0; i < 80; i++)
    {
        if ((i / 2 == 0)) {
            continue;
        }
        else if (xpos <= -350) {
            xpos = -350;
        }
        else if (ypos < 400)
        {
            ypos += 0.08;
        }
        else if (ypos > 450)
        {
            ypos = -400.0;
            xpos += 70;
        }
    }
}



void GameObject::Fallbump()
{
    srcRect.h = 1200.0;
    srcRect.w = 1600.0;
    srcRect.x = 0.0;
    srcRect.y = 0.0;

    destRect.x = xpos;
    destRect.y = ypos;
    bx1 = &xpos;
    by1 = &ypos;
    destRect.w = srcRect.w / 3;
    destRect.h = srcRect.h / 3;

    for (int i = 0; i < 20; i++)
    {
        if (i / 2 == 0) {
            continue;
        }
        else if (xpos > 450) {
            xpos = 100;
        }
        else if (ypos < 400)
        {
            ypos += 0.08;
        }
        else if (ypos <= 450)
        {
            ypos = -400.0;
            xpos += 30;
        }
    }
}

void GameObject::Fallbump2()
{
    srcRect.h = 1200.0;
    srcRect.w = 1600.0;
    srcRect.x = 0.0;
    srcRect.y = 0.0;

    destRect.x = xpos;
    destRect.y = ypos;
    bx2 = &xpos;
    by2 = &ypos;
    destRect.w = srcRect.w / 3;
    destRect.h = srcRect.h / 3;

    for (int i = 0; i < 20; i++)
    {
        if ((i / 5 == 0) or (i / 3 == 0)) {
            continue;
        }
        if (xpos > 500) {
            xpos = -200;
        }
        else if (ypos < 400)
        {
            ypos += 0.05;
        }
        else if (ypos > 300)
        {
            ypos = -400.0;
            xpos += 60;
        }
    }
}


void GameObject::Render()
{
    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}
int CollideCat();
int CollideCat()
{
    int score = 0;
    if (((*fx1 + 120 <= *px1 + 84) && (*fx1 + 120 >= *px1 - 84)) || ((*fx1 - 120 >= *px1 - 84) && (*fx1 - 120 <= *px1 + 84))) {
        if (((*fy1 + 9 <= *py1 + 6) && (*fy1 + 9 >= *py1 - 6)) || ((*fy1 - 9 <= *py1 + 6) && (*fy1 - 9 >= *py1 - 6))) {
            score = score + 1;

        }
    }
    if (((*fx2 + 120 <= *px1 + 84) && (*fx2 + 120 >= *px1 - 84)) || ((*fx2 - 120 >= *px1 - 84) && (*fx2 - 120 <= *px1 + 84))) {
        if (((*fy2 + 9 <= *py1 + 6) && (*fy2 + 9 >= *py1 - 6)) || ((*fy2 - 9 <= *py1 + 6) && (*fy2 - 9 >= *py1 - 6))) {
            score = score + 1;

        }
    }
    if (((*fx3 + 120 <= *px1 + 84) && (*fx3 + 120 >= *px1 - 84)) || ((*fx3 - 120 >= *px1 - 84) && (*fx3 - 120 <= *px1 + 84))) {
        if (((*fy3 + 9 <= *py1 + 6) && (*fy3 + 9 >= *py1 - 6)) || ((*fy3 - 9 <= *py1 + 6) && (*fy3 - 9 >= *py1 - 6))) {

            score = score + 1;
        }
    }
    return score;

}
int CollideBump()
{

    //  if ( ((*bx1 + 800 <= *px1 + 864) && (*bx1 + 800 >= *px1 - 864)) || ((*bx1 - 800 >= *px1 - 864) && (*bx1 - 800 <= *px1 + 864) ) ) {
      //    if (((*by1 + 600 <= *py1 + 624) && (*by1 + 600 >= *py1 - 624)) || ((*by1 - 600 <= *py1 + 624) && (*by1 - 600 >= *py1 - 624))  /**by1 == *py1*/) {
        //      return 1;
          //}
  //    }
  //    if (((*bx2 + 800 <= *px1 + 864) && (*bx2 + 800 >= *px1 - 864)) || ((*bx2 - 800 >= *px1 - 864) && (*bx2 - 800 <= *px1 + 864))) {
   //       if (((*by2 + 600 <= *py1 + 624) && (*by2 + 600 >= *py1 - 624)) || ((*by2 - 600 <= *py1 + 624) && (*by2 - 600 >= *py1 - 624)) /**by2 == *py1*/) {
     //         return 1;
      //    }
      //}
    if (((*bx1 + 50 <= *px1 + 84) && (*bx1 + 50 >= *px1 - 84)) || ((*bx1 - 50 >= *px1 - 84) && (*bx1 - 50 <= *px1 + 84))) {
        if (((*by1 + 5 <= *py1 + 5) && (*by1 + 5 >= *py1 - 10)) || ((*by1 - 5 <= *py1 + 10) && (*by1 - 5 >= *py1 - 10))  /**by1 == *py1*/) {
            return 1;
        }
    }
    if (((*bx2 + 50 <= *px1 + 84) && (*bx2 + 50 >= *px1 - 84)) || ((*bx2 - 50 >= *px1 - 84) && (*bx2 - 50 <= *px1 + 84))) {
        if (((*by2 + 5 <= *py1 + 10) && (*by2 + 5 >= *py1 - 10)) || ((*by2 - 5 <= *py1 + 10) && (*by2 - 5 >= *py1 - 10)) /**by2 == *py1*/) {
            return 1;
        }
    }
    /*if (a > 1000) {
        return 1;
    }
    else {
        return 0;
    }*/
    //return 0;
}
/*void GameObject::Closewindow() {
   // SDL_FreeSurface(tempSurface)
}*/

GameObject* player;
GameObject* bg;
GameObject* bg1;
GameObject* trash;
GameObject* trash2;
GameObject* trash3;
GameObject* dog;
GameObject* dog2;



int main(int argc, char** argv)

{
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT,
        MIX_DEFAULT_CHANNELS, 1024);

    Mix_Music* music = Mix_LoadMUS("music.mp3");
    Mix_PlayingMusic();
    Mix_PlayMusic(music, -1);

    fullscreen = false;
    int flags = 0;
    flags = SDL_WINDOW_RESIZABLE;
    if (fullscreen) {
        flags = flags | SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0 || Mix_Init(MIX_INIT_MP3)==-1) {
        std::cout << "Subsystems Initialized!\n";
        //MIX_INIT_MP3 == 1;
        window = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, flags);
        // +
        Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT,
            MIX_DEFAULT_CHANNELS, 2048);

        Mix_Music* music = Mix_LoadMUS("music.mp3");
        Mix_PlayingMusic();



        // +
        if (window) {
            std::cout << "Window Created!\n";
            SDL_SetWindowMinimumSize(window, 100, 100);
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 150);
            std::cout << "Renderer created!\n";
            SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
            isRunning = true;
        }

        int playerW = 1000, playerH = 600;
        SDL_GetRendererOutputSize(renderer, &windowW, &windowH);
        //START*****************************************************************************************
        player = new GameObject("cloud.png", renderer, 0, 290, playerH, playerW);
        bg = new GameObject("bg.png", renderer, 0, 0, playerH, playerW);
        trash = new GameObject("cat.png", renderer, -350, -350, playerH, playerW);
        trash2 = new GameObject("cat.png", renderer, 200, -350, playerH, playerW);
        trash3 = new GameObject("cat.png", renderer, 400, -350, playerH, playerW);
        dog = new GameObject("planet.png", renderer, 0, -300, playerH, playerW);
        dog2 = new GameObject("planet.png", renderer, 450, -300, playerH, playerW);
        bg1 = new GameObject("bg1.png", renderer, 0, 0, playerH, playerW);

        std::cout << "windowH: " << windowH << std::endl;
        std::cout << "windowW: " << windowW << std::endl;
        std::cout << "playerH: " << playerH << std::endl;
        start = 1;
        //END*****************************************************************************************

    }

    //START*****************************************************************************************
    const int FPS = 60;
    const int frameDelay = 400 / FPS; //max time between frames

    Uint32 frameStart;
    int frameTime;
    //END*****************************************************************************************
    int scoreans = 0;

    while (isRunning) {


        //START*****************************************************************************************
        frameStart = SDL_GetTicks(); //how many miliseconds from we first initialized
        //END*****************************************************************************************

        handleEvents();
        update();
        render();//讀圖片


        //+
        scoreans = scoreans + CollideCat();
        //+
        // 
        //START*****************************************************************************************
        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) // To smoothen our the movement
        {
            SDL_Delay(frameDelay - frameTime);
        }
        //END*****************************************************************************************
    }
    cout << endl << endl << scoreans / 10 << endl << endl;
    // window = SDL_CreateWindow("Test Window1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, flags);


     //frees memory associated with renderer and window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window); //error here
    SDL_Quit();

    return 0;
}

//handles any events that SDL noticed.
void handleEvents() {
    //the only event we'll check is the SDL_QUIT event.
    //SDL_Event event; change to global

    SDL_PollEvent(&event);


    switch (event.type) {
    case SDL_QUIT:
        isRunning = false;
        break;
    default:
        break;
    }
}

//simple render function
void render() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);


    //START*****************************************************************************************
    if (CollideBump() == 1) {
        bg1->Render();

        isRunning = false;
        //   Sleep(10000);
    }
    else {
        bg->Render();
        player->Render();
        trash->Render();
        trash2->Render();
        trash3->Render();
        dog->Render();
        dog2->Render();
    }


    //END*****************************************************************************************

     //your stuff to render would typically go here.
    SDL_RenderPresent(renderer);
}



//simple update function
void update() {
    //if things could update the code would go in here.
    //START*****************************************************************************************
   //  if (cnt == 800) {
   //     moveRight = false;
   //  }
   //  else if (cnt == 0) {
   //     moveRight = true;
   //  }
   //  if (moveRight == true) {
   //     cnt++;
   //  }
   //  else { cnt--; }
   //  destR.h = 96;
   //  destR.w = 96;
   //  destR.x = cnt;

    player->Update();
    bg->Update2();
    bg1->Update3();
    trash->Fall();
    trash2->Fall2();
    trash3->Fall3();
    dog->Fallbump();
    dog2->Fallbump2();

    //END*****************************************************************************************
}