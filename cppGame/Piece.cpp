//
//  Piece.cpp
//  cppGame
//
//  Created by Nicholas Scheuring on 12/5/16.
//  Copyright © 2016 Nick Scheuring. All rights reserved.
//
#include <stdio.h>
#include <SDL2/SDL.h>
#include <ctime>
#include "Piece.h"

using namespace std;


Piece::Piece(const int& ex, const int& why) {
    Piece::x_ = ex;
    Piece::y_ = why;
    setColor();
}

void Piece::setColor() noexcept{
    //srand(time(NULL));
    int randNum = rand() % 5 + 1;
    if(randNum == 1) {
        Piece::color_ = make_tuple(255,0,0);
    }
    else if(randNum == 2) {
        Piece::color_ = make_tuple(0,255,0);
    }
    else if(randNum == 3) {
        Piece::color_ = make_tuple(0,0,255);
    }
    else if(randNum == 4) {
        Piece::color_ = make_tuple(255,255,0);
    }
    else if(randNum == 5) {
        Piece::color_ = make_tuple(0,255,255);
    }
}

int Piece::getX() {
    return Piece::x_;
}

int Piece::getY() {
    return Piece::y_;
}

int Piece::getR() {
    return get<0>(this->color_);
}

int Piece::getG() {
    return get<1>(this->color_);
}

int Piece::getB() {
    return get<2>(this->color_);
}
