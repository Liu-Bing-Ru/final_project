// vst1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#undef main
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h>

using namespace std;

int start = 0;
int collide = 0;
bool startScreen = true;

SDL_Renderer* renderer;
SDL_Window* window;
bool isRunning;
bool fullscreen;
void handleEvents();
void update();
void render();

SDL_Texture* textTexture;
SDL_Rect textRect;


int windowW, windowH;

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
    void Update4();

    void Fall();
    void Fall2();
    void Fall3();
    void Fallbump();
    void Fallbump2();
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
        
        case SDLK_LEFT:
            if (xpos >= -195)
                xpos += -15;
            break;
        case SDLK_RIGHT:
            if (xpos <= 425)
                xpos += 15;
            break;
        
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

void GameObject::Update4()
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

double* fx1 = nullptr, * fy1 = nullptr, * fx2 = nullptr, * fy2 = nullptr, * fx3 = nullptr, * fy3 = nullptr, * bx1 = nullptr, * by1 = nullptr, * bx2 = nullptr, * by2 = nullptr;


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
 
}
const int SCREEN_WIDTH3 = 800;
const int SCREEN_HEIGHT3 = 600;


//全局窗口和渲染器
SDL_Window* window3 = nullptr;
SDL_Renderer* renderer3 = nullptr;

SDL_Texture* LoadImage(std::string file)
{
    SDL_Texture* tex3 = nullptr;
    tex3 = IMG_LoadTexture(renderer3, file.c_str());
    if (tex3 == nullptr)
        throw std::runtime_error("Failed to load image: " + file + IMG_GetError());
    return tex3;
}

//将表面应用到渲染器
void ApplySurface(int x3, int y3, SDL_Texture* tex3, SDL_Renderer* rend3)
{
    SDL_Rect pos;
    pos.x = x3;
    pos.y = y3;
    SDL_QueryTexture(tex3, NULL, NULL, &pos.w, &pos.h);
    SDL_RenderCopy(rend3, tex3, NULL, &pos);
}





GameObject* player;
GameObject* bg;
GameObject* bg1;
GameObject* bg4;
GameObject* trash;
GameObject* trash2;
GameObject* trash3;
GameObject* dog;
GameObject* dog2;


int scoreans = 0;
int main(int argc, char** argv)

{
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT,
    MIX_DEFAULT_CHANNELS, 1024);

    Mix_Music* music = Mix_LoadMUS("assets/music.mp3");
    Mix_PlayingMusic();
    Mix_PlayMusic(music, -1);

    TTF_Init();
    fullscreen = false;
    int flags = 0;
    flags = SDL_WINDOW_RESIZABLE;
    if (fullscreen) {
        flags = flags | SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        cout << "Subsystems Initialized!\n";

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

        player = new GameObject("assets/cloud.png", renderer, 0, 290, playerH, playerW);
        bg = new GameObject("assets/bg.png", renderer, 0, 0, playerH, playerW);
        trash = new GameObject("assets/cat.png", renderer, -350, -350, playerH, playerW);
        trash2 = new GameObject("assets/cat.png", renderer, 200, -350, playerH, playerW);
        trash3 = new GameObject("assets/cat.png", renderer, 400, -350, playerH, playerW);
        dog = new GameObject("assets/planet.png", renderer, 0, -300, playerH, playerW);
        dog2 = new GameObject("assets/planet.png", renderer, 450, -300, playerH, playerW);
        bg1 = new GameObject("assets/bg1.png", renderer, 0, 0, playerH, playerW);
        bg4 = new GameObject("assets/bg4.png", renderer, 0, 0, playerH, playerW);

        std::cout << "windowH: " << windowH << std::endl;
        std::cout << "windowW: " << windowW << std::endl;
        std::cout << "playerH: " << playerH << std::endl;
        start = 1;
    }

    
    const int FPS = 60;
    const int frameDelay = 400 / FPS; //max time between frames

    Uint32 frameStart;
    int frameTime;
    

    while (isRunning) {        
        frameStart = SDL_GetTicks(); //how many miliseconds from we first initialized

        handleEvents();
        update();
        if (collide != 1)
            scoreans = scoreans + CollideCat();

    
        TTF_Font* font = TTF_OpenFont("assets/Unbounded-Regular.ttf", 30);
        if (font == NULL)
            std::cout << TTF_GetError() << std::endl;

        int finalScore = scoreans;
        std::string s = std::to_string(finalScore);
        std::string scoreStr = "Score: ";
        std::string result = std::string(scoreStr) + std::string(s);
        const char* pchar = s.c_str();

        SDL_Surface* textSurf = TTF_RenderText_Solid(font, pchar, {0, 0, 0});
        if (textSurf == NULL)
            std::cout << "textSurf NULL!" << std::endl;
        textTexture = SDL_CreateTextureFromSurface(renderer, textSurf);
        if (textTexture == NULL)
            std::cout << "textTexture NULL!" << std::endl;
        textRect = {495, 389, textSurf->w, textSurf->h};
        SDL_FreeSurface(textSurf);
        TTF_CloseFont(font);

        render();//讀圖片

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) // To smoothen our the movement
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    
     //frees memory associated with renderer and window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window); //error here
    TTF_Quit();
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

    if (startScreen == true) {
        bg4->Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(3000);
        startScreen = false;
    }
    
    if (CollideBump() == 1)
        collide = CollideBump();
    //START*****************************************************************************************
    if (collide == 1) {
        bg1->Render();
        //std::cout << "YAYYYYYYYYYYYYYYYYYYYYY " << std::endl << std::endl;
        //START*****************************************************************************************
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
        //END*****************************************************************************************
        SDL_RenderPresent(renderer);
        //SDL_Delay(10000);
        //isRunning = false;
    }
    else {
        //std::cout << "CollideBump: " << CollideBump() << std::endl;
        bg->Render();
        player->Render();
        trash->Render();
        trash2->Render();
        trash3->Render();
        dog->Render();
        dog2->Render();
        SDL_RenderPresent(renderer);
    }
}



//simple update function
void update() {
    //if things could update the code would go in here.
    player->Update();
    bg->Update2();
    bg1->Update3();
    bg4->Update4();
    trash->Fall();
    trash2->Fall2();
    trash3->Fall3();
    dog->Fallbump();
    dog2->Fallbump2();
}