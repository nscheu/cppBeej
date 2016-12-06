//
//  GameState.hpp
//  cppGame
//
//  Created by Nicholas Scheuring on 12/5/16.
//  Copyright © 2016 Nick Scheuring. All rights reserved.
//

#ifndef GameState_h
#define GameState_h

#include <stdio.h>
#include <vector>
#include "Piece.h"

class GameState{
    public:
        /**
         * Constructor for the Game State object
         *
         */
        GameState();
    private:
    /* The 8x8 game board */
    std::vector< Piece > gameBoard_;
    
};

#endif /* GameState_h */
