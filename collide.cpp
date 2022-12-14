// vst1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#undef main
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h>
//#include <windows.h>


SDL_Renderer* renderer;
SDL_Window* window;
SDL_Renderer* renderer2;
SDL_Window* window2;

bool isRunning;
bool isRunning2;
bool fullscreen;
bool fullscreen2;
void handleEvents();
void handleEvents2();
void update();
void render();

int windowW, windowH;

//START*****************************************************************************************
//int cnt = 0;
//bool moveRight = true;
SDL_Event event;
SDL_Event event2;

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
double *fx1,*fy1, *fx2, *fy2, *fx3, *fy3, *bx1, *by1, *bx2, *by2;
//+

void GameObject::Fall()
{
    srcRect.h = 1800.0;
    srcRect.w = 2400.0;
    srcRect.x = 0.0;
    srcRect.y = 0.0;

    destRect.x = xpos;
    destRect.y = ypos;
    fx1 = &xpos;
    fy1 = &ypos;
    destRect.w = srcRect.w / 3;
    destRect.h = srcRect.h / 3;

    for (int i = 0; i < 70; i++)
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
    fx2 = &xpos;
    fy2 = &ypos;
    destRect.w = srcRect.w / 3;
    destRect.h = srcRect.h / 3;

    for (int i = 0; i < 120; i++)
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
    fx3 = &xpos;
    fy3 = &ypos;
    destRect.w = srcRect.w / 3;
    destRect.h = srcRect.h / 3;

    for (int i = 0; i < 80; i++)
    {
        if ((i / 2 == 0) ) {
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


int CollideCat()
{
    int score = 0;
    if (((*fx1 + 1200 <= *px1 + 864) && (*fx1 + 1200 >= *px1 - 864)) || ((*fx1 - 1200 >= *px1 - 864) && (*fx1 - 1200 <= *px1 + 864))) {
        if (((*fy1 + 900 <= *py1 + 624) && (*fy1 + 900 >= *py1 - 624)) || ((*fy1 - 900 <= *py1 + 624) && (*fy1 - 900 >= *py1 - 624))  ) {
            //score = score + 1;
            return score;
        }
    }
    if (((*fx2 + 1200 <= *px1 + 864) && (*fx2 + 1200 >= *px1 - 864)) || ((*fx2 - 1200 >= *px1 - 864) && (*fx2 - 1200 <= *px1 + 864))) {
        if (((*fy2 + 900 <= *py1 + 624) && (*fy2 + 900 >= *py1 - 624)) || ((*fy2 - 900 <= *py1 + 624) && (*fy2 - 900 >= *py1 - 624))  ) {
            //score = score + 1;
            return score;
        }
    }
    if (((*fx3 + 1200 <= *px1 + 864) && (*fx3 + 1200 >= *px1 - 864)) || ((*fx3 - 1200 >= *px1 - 864) && (*fx3 - 1200 <= *px1 + 864))) {
        if (((*fy3 + 900 <= *py1 + 624) && (*fy3 + 900 >= *py1 - 624)) || ((*fy3 - 900 <= *py1 + 624) && (*fy3 - 900 >= *py1 - 624))  ) {
            return score;
            //score = score + 1;
        }
    }
    //return score;

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

int stop = 0;

int main(int argc, char** argv)

{
    fullscreen = false;
    int flags = 0;
    flags = SDL_WINDOW_RESIZABLE;
    if (fullscreen) {
        flags = flags | SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems Initialized!\n";

        window = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, flags);
        
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
        player = new GameObject("assets/cloud.png", renderer, 0, 290, playerH, playerW);
        bg = new GameObject("assets/bg.png", renderer, 0, 0, playerH, playerW);
        trash = new GameObject("assets/cat.png", renderer, -350, -350, playerH, playerW);
        trash2 = new GameObject("assets/cat.png", renderer, 200, -350, playerH, playerW);
        trash3 = new GameObject("assets/cat.png", renderer, 400, -350, playerH, playerW);
        dog = new GameObject("assets/planet.png", renderer, 0, -300, playerH, playerW);
        dog2 = new GameObject("assets/planet.png", renderer, 450, -300, playerH, playerW);
        bg1 = new GameObject("assets/bg1.png", renderer, 0, 0, playerH, playerW);

        std::cout << "windowH: " << windowH << std::endl;
        std::cout << "windowW: " << windowW << std::endl;
        std::cout << "playerH: " << playerH << std::endl;

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
        //CollideCat();
        handleEvents();
        update();
        render();//讀圖片
        
        //scoreans = scoreans + CollideCat();
        //+

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
    
   // window = SDL_CreateWindow("Test Window1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, flags);
/*
    if (isRunning == false) {
        fullscreen2 = false;
        int flags2 = 0;
        flags2 = SDL_WINDOW_RESIZABLE;
        if (fullscreen) {
            flags2 = flags2 | SDL_WINDOW_FULLSCREEN;
        }
        if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
            std::cout << "Subsystems Initialized!\n";

            window2 = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, flags2);
            
            if (window2) {
                std::cout << "Window 2 Created!\n";
                SDL_SetWindowMinimumSize(window2, 100, 100);
            }
            renderer2 = SDL_CreateRenderer(window2, -1, 0);
            if (renderer2) {
                SDL_SetRenderDrawColor(renderer2, 255, 255, 255, 150);
                std::cout << "Renderer 2 created!\n";
                SDL_SetRenderDrawBlendMode(renderer2, SDL_BLENDMODE_BLEND);
                isRunning2 = true;
            }
        }
        while (isRunning2 == true) {
            handleEvents2();
            SDL_SetRenderDrawColor(renderer2, 255, 255, 255, 255);
            SDL_RenderClear(renderer2);
        }
    }*/
    //frees memory associated with renderer and window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
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

void handleEvents2() {
    //the only event we'll check is the SDL_QUIT event.
    //SDL_Event event; change to global

    SDL_PollEvent(&event2);


    switch (event2.type) {
    case SDL_QUIT:
        isRunning2 = false;
        break;
    default:
        break;
    }
}

//simple render function
void render() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    CollideBump();
    //START*****************************************************************************************
    if (CollideBump() == 1) {
        bg1->Render();
        isRunning = false;
        fullscreen2 = false;
        int flags2 = 0;
        flags2 = SDL_WINDOW_RESIZABLE;
        if (fullscreen2) {
            flags2 = flags2 | SDL_WINDOW_FULLSCREEN;
        }
        if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
            std::cout << "Subsystems Initialized!\n";

            window2 = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, flags2);
            
            if (window2) {
                std::cout << "Window 2 Created!\n";
                SDL_SetWindowMinimumSize(window2, 100, 100);
            }
            renderer2 = SDL_CreateRenderer(window2, -1, 0);
            if (renderer2) {
                SDL_SetRenderDrawColor(renderer2, 255, 255, 255, 150);
                std::cout << "Renderer 2 created!\n";
                SDL_SetRenderDrawBlendMode(renderer2, SDL_BLENDMODE_BLEND);
                isRunning2 = true;
            }
        }
        while (isRunning2 == true) {
            handleEvents2();
            SDL_SetRenderDrawColor(renderer2, 255, 255, 255, 255);
            SDL_RenderClear(renderer2);
        }
        
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