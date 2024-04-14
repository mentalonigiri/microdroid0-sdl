#include "SDL.h"
#include "SDL_main.h"

int SDL_main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);  // Initialize SDL2

    SDL_Window *window;        // Declare a pointer to an SDL_Window
    SDL_Renderer *renderer;    // Declare a pointer to an SDL_Renderer

    // Create an application window with the following settings:
    window = SDL_CreateWindow("SDL2 Example",                     // window title
                              SDL_WINDOWPOS_UNDEFINED,            // initial x position
                              SDL_WINDOWPOS_UNDEFINED,            // initial y position
                              640,                                // width, in pixels
                              480,                                // height, in pixels
                              SDL_WINDOW_OPENGL);                 // flags

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        SDL_Log("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    // Create a renderer for the window
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Clear the renderer to the draw color
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // Draw the renderer
    SDL_RenderPresent(renderer);

    // Wait for 5 seconds
    SDL_Delay(5000);

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up SDL2 and exit the program
    SDL_Quit();
    return 0;
}
