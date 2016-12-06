//
//  GameState.cpp
//  cppGame
//
//  Created by Nicholas Scheuring on 12/5/16.
//  Copyright © 2016 Nick Scheuring. All rights reserved.
//
#include <iostream>
#include "GameState.h"


GameState::GameState(){
    std::cout << "Game State Constructor" << std::endl;
}

/**
 * Collects the mouse cursor location
 * @param x the mouse's x position
 * @param y the mouse's y position
 */
void GameState::catchXYfromClick(int x, int y){
    std::cout << "GS CXY:: x= " << x << " y=" << y << std::endl;
}

/**
 * Adds a piece to the game state
 * @param piece the piece
 */
void GameState::addPiece(Piece piece){
    this->gameBoard_.push_back(piece);
}
