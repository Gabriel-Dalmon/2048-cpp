#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <SDL_ttf.h>
#include "../../include/gamelogic/TextObject.h"
#include "../../include/engine/SDLRenderer.h"
#include "../../include/utils/BitMaths.h"


TextObject::TextObject(const char* text, SDL_Rect* rect, const char* fontPath, SDL_Color color, int fontSize) : GameObject() {
	this->rect = rect;
	TTF_Font* font = TTF_OpenFont(text, fontSize);
	//src/assets/fonts/ttf-bitstream-vera-1.10/Vera.ttf
	this->surface = TTF_RenderText_Blended(font, text, color);
}

TextObject::~TextObject() {}



void TextObject::render(SDLScreen* screen) {
	SDL_BlitSurface(this->surface, NULL, screen->surface, this->rect);

}