//
//  Piece.hpp
//  cppGame
//
//  Created by Nicholas Scheuring on 12/5/16.
//  Copyright © 2016 Nick Scheuring. All rights reserved.
//

#ifndef Piece_h
#define Piece_h

#include <stdio.h>
#include <SDL2/SDL.h>

#include <tuple>
class Piece {
public:
    
    Piece(const int& x, const int&y);
    
    int getX();
    int getY();
    int getR();
    int getG();
    int getB();
    
    void setColor() noexcept;
    
    
private:
    int x_;
    int y_;
    
    std::tuple<int, int, int> color_;
};


#endif /* Piece_h */
