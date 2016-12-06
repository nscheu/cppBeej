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
 * Gets the Pieces Vector
 */
//std::shared_ptr<std::vector<Piece>> getPieces(){
//    
//}

/**
 * Collects the mouse cursor location
 * @param x the mouse's x position
 * @param y the mouse's y position
 */
void GameState::catchXYfromClick(int x, int y){
    std::cout << "GS CXY:: x= " << x << " y=" << y << std::endl;
    int pieceIndex = whichPieceWasClicked(x, y);
    std::cout << "Piece Index:: " << pieceIndex << std::endl;
}

/**
 * Adds a piece to the game state
 * @param piece the piece
 */
void GameState::addPiece(Piece piece){
    this->gameBoard_.push_back(piece);
}

/**
 * Gets the vector index of the clicked piece
 * If not a piece, return -1
 * @param x the mouse's x position
 * @param y the mouse's y position
 * @return the index of the piece that was clicked
 */
int GameState::whichPieceWasClicked(int x, int y){
    int returnVal = -1;
    std::cout << "WPWC BP? : VS: " << (this->gameBoard_).size() << std::endl;
    for(int i = 0; i < (this->gameBoard_).size(); i++){
        if(wasThisPieceClicked(x,y,
                               this->gameBoard_[i].getX(),
                               this->gameBoard_[i].getY())){
            std::cout << "Clicke:: x= " << x << " y=" << y << "p-x" << this->gameBoard_[i].getX() << "p-y" <<this->gameBoard_[i].getY() << std::endl;
            returnVal = i;
            std::cout << "A Piece Was Clicke at index : " << i << std::endl;
            break;
        }
    }
    return returnVal;
}

/**
 * Checks if the mouse coords were on a piece
 * @param x the mouse's x position
 * @param y the mouse's y position
 * @return true if on piece, false else
 */
bool GameState::wasThisPieceClicked(int x, int y, int x_piece, int y_piece){
    return (x_piece >= x && x_piece < x + 50 && y_piece <= y && x_piece > y - 50);
}
