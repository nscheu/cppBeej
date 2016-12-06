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
//        /**
//         * Gets the Pieces Vector
//        */
//        std::shared_ptr<std::vector<Piece>> getPieces();
        /**
         * Collects the mouse cursor location
         * @param x the mouse's x position
         * @param y the mouse's y position
         */
        void catchXYfromClick(int x, int y);
        /**
         * Adds a piece to the game state
         * @param piece the piece
         */
        void addPiece(Piece piece);
        /**
         * Gets the vector index of the clicked piece
         * If not a piece, return -1
         * @param x the mouse's x position
         * @param y the mouse's y position
         * @return the index of the piece that was clicked
         */
        int whichPieceWasClicked(int x, int y);
        /**
         * Checks if the mouse coords were on a piece
         * @param x the mouse's x position
         * @param y the mouse's y position
         * @param x_piece the piece's x position
         * @param y_piece the piece's y position
         * @return true if on piece, false else
         */
        bool wasThisPieceClicked(int x, int y, int x_piece, int y_piece);
    private:
    /* The 8x8 game board */
    std::vector< Piece > gameBoard_;
    
};

#endif /* GameState_h */
