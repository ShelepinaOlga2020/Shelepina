#include <iostream>
#include <SDL.h>
#include <locale.h>

#define W_WIDTH 800
#define W_HEIGHT 600

using namespace std;

void laba19(SDL_Window* window);
void laba20(SDL_Window* window);
void lab20f(SDL_Window* window);
void lab20s(SDL_Window* window);
void laba21(SDL_Window* window);
void laba22(SDL_Window* window);
void laba23(SDL_Window* window);



int main(int kol, char** str) {
    setlocale(LC_ALL, "Rus");
    int number = 0;
    SDL_Window* m_Window = nullptr;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        cout << "Error of initialization SDL" << endl;
        return -1;
    }

    if (!(m_Window = SDL_CreateWindow("lb", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W_WIDTH, W_HEIGHT, SDL_WINDOW_SHOWN))) {
        cout << "Could not create the window" << endl;
        SDL_Quit();
        return -2;
    }

    // 0 - команда выхода
    do {
        std::cout << "Введите номер лабы. Для выхода 0" << std::endl;
        std::cin >> number;

        switch (number) {
        case 19:
            laba19(m_Window);
            break;
        case 20:
            laba20(m_Window);
            break;
        case 21:
            cout << "В разработке" << endl;
            /*laba21(m_Window);*/
            break;
        case 22:
            cout << "В разработке" << endl;
           /* laba22(m_Window);*/
            break;
        case 23:
            cout << "В разработке" << endl;
            /*laba23(m_Window);*/
            break;
        default:
            if (number != 0)
                std::cout << "Неизвестный номер лабы (" << std::endl;
        }

    } while (number != 0);

    SDL_DestroyWindow(m_Window);
    SDL_Quit();

    return 0;
}

void laba19(SDL_Window* m_Window) {
    SDL_Surface* m_Surface = nullptr;

    if (!(m_Surface = SDL_GetWindowSurface(m_Window))) {
        cout << "Could not create the renderer" << endl;
        return;
    }

    SDL_Surface* tmp = SDL_LoadBMP("laba/img/image.bmp");

    SDL_SetColorKey(tmp, SDL_TRUE, SDL_MapRGB(tmp->format, 255, 255, 255));

    SDL_FillRect(m_Surface, NULL, SDL_MapRGB(m_Surface->format, 200, 255, 255));
    SDL_Rect rect = { W_WIDTH - 500, 0, 0, 0 };

    SDL_BlitSurface(tmp, NULL, m_Surface, &rect);

    SDL_UpdateWindowSurface(m_Window);

    SDL_FreeSurface(m_Surface);

    SDL_Delay(5000);
}

void lab20f(SDL_Window* m_Window) {
    SDL_Renderer* renderer = SDL_CreateRenderer(m_Window, 1, 0);
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 1, 0, 0, 0);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            SDL_Rect rect2 = { 100 * i, 100 * j, 100, 100 };
          if (i % 2 != j % 2) { SDL_SetRenderDrawColor(renderer, 1, 0, 0, 0); SDL_RenderFillRect(renderer, &rect2); }
            else { SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0); SDL_RenderFillRect(renderer, &rect2); }
        }
    }
    SDL_RenderPresent(renderer);
    SDL_UpdateWindowSurface(m_Window);
    SDL_Delay(5000);
}
void lab20s(SDL_Window* m_Window) {
    SDL_Renderer* renderer = SDL_CreateRenderer(m_Window, 1, 0);
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
    SDL_RenderClear(renderer);
    SDL_Surface* m_Surface = nullptr;
    SDL_SetRenderDrawColor(renderer, 1, 0, 0, 0);
    SDL_Rect rect = { 250, 200, 300, 250 };
    SDL_RenderFillRect(renderer, &rect);
    // точка крыши (400;50)
    //прямая от одного края до точки 1 (250;200), (400;50)
    //до 2 точки (550;200), (400;50)

    SDL_SetRenderDrawColor(renderer, 150, 75, 0, 0);
    int krisha1 = 250, krisha2 = 200;
    for (int i = 250; i < 400; i++) {
        SDL_RenderDrawLine(renderer, i, 200, krisha1, krisha2);
        krisha1++; krisha2--;
    }
    for (int i = 400; i < 550; i++) {
        SDL_RenderDrawLine(renderer, i, 200, krisha1, krisha2);
        krisha1++; krisha2++;
    }

    SDL_RenderDrawLine(renderer, 250, 200, 400, 50);
    SDL_RenderDrawLine(renderer, 550, 200, 400, 50);
    SDL_SetRenderDrawColor(renderer, 120, 120, 120, 0);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            SDL_Rect rect2 = { 350 + 50 * i, 275 + 50 * j, 50, 50 };
            SDL_RenderFillRect(renderer, &rect2);
        }
    SDL_SetRenderDrawColor(renderer, 1, 0, 0, 0);
    SDL_RenderDrawLine(renderer, 400, 275, 400, 375);
    SDL_RenderDrawLine(renderer, 350, 325, 450, 325);

    SDL_Rect rect4 = { 0,450,800,150 };
    SDL_SetRenderDrawColor(renderer, 78, 105, 26, 0);
    SDL_RenderFillRect(renderer, &rect4);

    SDL_RenderPresent(renderer);

    SDL_UpdateWindowSurface(m_Window);

    SDL_Delay(5000);
}




void laba20(SDL_Window* m_Window) {
    int k;
    do {
        std::cout << "Введите номер задание. Для выхода 0" << std::endl;
        std::cin >> k;

        switch (k) {
        case 1:
            lab20f(m_Window);
            break;
        case 2:
            lab20s(m_Window);
            break;
        case 3:
            laba21(m_Window);
            break;

        default:
            if (k != 0)
                std::cout << "Неизвестный номер задания (" << std::endl;

        }

    } while (k != 0);
}
    

 


void laba21(SDL_Window* window) {


}

void laba22(SDL_Window* window) {


}

void laba23(SDL_Window* window) {


}