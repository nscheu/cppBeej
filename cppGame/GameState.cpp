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
    this->firstTile_ = -1;
    this->secondTile_ = -1;
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
    int pieceIndex = whichPieceWasClicked(x, y);
    // If there is an active tile
    if(this->firstTile_ >= 0){
        std::cout << "fol 1 " << this->firstTile_ << " " << this->secondTile_ << std::endl;
        //If the second tile exists already
        if(this->secondTile_ >= 0){
            // Then this piece is a new piece to swap
            this->firstTile_ = pieceIndex;
            this->secondTile_ = -1;
            std::cout << "fol 2 " << this->firstTile_ << " " << this->secondTile_ << std::endl;
        }
        else{
            //This choice is the second in a swap
            this->secondTile_ = pieceIndex;
            std::cout << "fol 3 " << this->firstTile_ << " " << this->secondTile_ << std::endl;
            // DO the swap here
            swapCaller();
        }
    }
    else{
        // This is the active tile
        this->firstTile_ = pieceIndex;
    }
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
            //std::cout << "Clicke:: x= " << x << " y=" << y << "p-x" << this->gameBoard_[i].getX() << "p-y" <<this->gameBoard_[i].getY() << std::endl;
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
    return (x >= x_piece && x < x_piece + 50 && y_piece <= y && y_piece > y - 50);
}


/**
 * Swap the two pieces
 *
 */
void GameState::swapPieces(){
    Piece temp = this->gameBoard_[this->secondTile_];
    this->gameBoard_[this->secondTile_] = this->gameBoard_[this->firstTile_];
    this->gameBoard_[this->firstTile_] = temp;
}


/**
 * Calls the Swap function
 *
 */
void GameState::swapCaller(){
    swapPieces();
    scanForVertMatches();
    scanForHoriMatches();
    if(this->matchedPieces_.size() > 0){
        deleteMatchedPieces();
    }
    else{
        swapPieces();
    }
}

/**
 *  Scans the board for sets of 3
 *
 */
void GameState::scanForMatches(){
    scanForVertMatches();
    scanForHoriMatches();
    deleteMatchedPieces();
}

/**
 *  Scans the board for Vertical sets of 3
 *
 */
void  GameState::scanForVertMatches(){
    int compTileIdx = 7;
    int firstRange = -1;
    int lastRange = -1;
    
    // Scan each column
    for(int i = 0; i < 8; i++){
        std::cout << i << " i" << std::endl;
        //set the column index
        compTileIdx = (i * 8);
        // Scan for column matches
        for(int j = 7; j > 1; j--){
            std::cout << j << " j" << std::endl;
            // Loop through the pieces above the start piece
            for(int k = 6; k > -1; k--){
                std::cout << k << " k" << std::endl;
                // If adjacent match not found
                if(!this->doPiecesMatch(j + compTileIdx, k + compTileIdx)){
                    std::cout << k << " match not found" << std::endl;
                    // Set the last in the range to the last checked piece
                    lastRange = k + compTileIdx + 1;
                    // if (first item checked - last item checked) > 2 -> seq 3
                    if((j + compTileIdx - lastRange) > 2){
                        // Mark all in range for delete
                        for(int l = lastRange; l >= (j + compTileIdx); l++){
                            this->matchedPieces_.insert(l);
                        }
                    }
                    // Reset j to not recheck the pieces marked for delete
                    //std::cout << j << " j was" << std::endl;
                    //j = k + compTileIdx;
                    //std::cout << j << " j is" << std::endl;
                    // kill k loop
                    k = -1;
                }
            }
        }
    }
}
/**
 *  Scans the board for Horizontal sets of 3
 *
 */
void  GameState::scanForHoriMatches(){
    int firstRange = -1;
    int lastRange = -1;
    
    //Loop through each row
    for(int i = 0; i < 6; i++){
        // i == the first index to compare
        // loop through the rest of the row
        for(int j = 0; j < 64; j += 8){
            //loop through the rest of the row
            for(int k = 8 + i; k <= (40 + i); i += 8){
                // If adjacent match not found
                if(!this->doPiecesMatch(j, k)){
                    // Set the last in the range to the last checked piece
                    lastRange = k - 8;
                    // if (first item checked - last item checked) > 2 -> seq 3
                    if((j - lastRange) > (2 * 8)){
                        // Mark all in range for delete
                        for(int l = lastRange; l >= j; l++){
                            this->matchedPieces_.insert(l);
                        }
                    }
                    // Reset j to not recheck the pieces marked for delete
                    //j = k;
                    // kill k loop
                    k = 99;
                }
            }
        }
    }
}

/**
 *  deletes matched pieces from the game board
 *  [Does not actually delete them, rather resets
 *   the color to a new color]
 */
void  GameState::deleteMatchedPieces(){
    
    // Iterate the set of pieces to "delete"
    for(auto f : this->matchedPieces_) {
        // use f here
        this->gameBoard_[f].setColor();
    }
    
    // Clear the matched pieces set as they have been 'deleted'
    this->matchedPieces_.clear();
}


/**
 * Checks if two pieces color matches
 * @return true if match, false else
 */
bool GameState::doPiecesMatch(int p1, int p2){
    bool rMatch = this->gameBoard_[p1].getR() == this->gameBoard_[p2].getR();
    bool gMatch = this->gameBoard_[p1].getG() == this->gameBoard_[p2].getG();
    bool bMatch = this->gameBoard_[p1].getB() == this->gameBoard_[p2].getB();
    return rMatch && gMatch && bMatch;
}
