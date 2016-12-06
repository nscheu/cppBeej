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
#include <set>
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
        /**
         * Swap the two pieces
         *
         */
        void swapPieces();
        /**
         * Calls the Swap function
         *
         */
        void swapCaller();
        /**
         *  Scans the board for sets of 3
         *
         */
        void scanForMatches();
        /**
         *  Scans the board for Vertical sets of 3
         *
         */
        void  scanForVertMatches();
        /**
         *  Scans the board for Horizontal sets of 3
         *
         */
        void  scanForHoriMatches();
        /**
         *  deletes matched pieces from the game board
         *  [Does not actually delete them, rather resets 
         *   the color to a new color]
         */
        void  deleteMatchedPieces();
        /**
         * Checks if two pieces color matches
         * @return true if match, false else
         */
        bool doPiecesMatch(int p1, int p2);
    private:
    /* The 8x8 game board */
    std::vector< Piece > gameBoard_;
    /* The active tile */
    int firstTile_;
    /* The active tile */
    int secondTile_;
    /* Indexes of matched pieces */
    std::set<int> matchedPieces_;
    
};

#endif /* GameState_h */
