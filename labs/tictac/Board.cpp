#include "Errors.h"
#include "Board.h"

#include <iostream>
#include <cmath>

Board::Board(){
    turnNum = 0;
    turn = ' ';
    for(int i = 0; i < int(numCol); i++){
        for(int j = 0; j < int(numRow); j++){
            grid[i][j] = ' ';
        }
    }
}

char Board::getTurn(){ return turn; }

void Board::checkState(){
    if(turn == ' '){ // Check if no move made
        std::cout << "Game in progress: New game." << std::endl;
        return;
    }

    if(checkWin() != ' '){ // Check win
        std::cout << "Game over: " << checkWin() << " wins." << std::endl;
        return;
    }

    // Check for draw
    if(turnNum == 9){
        std::cout << "Game over: Draw." << std::endl;
        return;
    }

    // Check turn
    std::cout << "Game in progress: " << turn << "\'s turn." << std::endl;
}

void Board::addMove(Move newMove){
    if(turn == ' '){
        turn = newMove.player;
    }
    else if(turn != newMove.player){
        throw InvalidMove("Out of turn");
    }
    if(turn == 'X'){ turn = 'O'; }
    else{            turn = 'X'; }

    if(newMove.number != ++turnNum){ throw InvalidMove("Move number invalid"); }

    if(checkWin() == ' '){ // Make sure game isn't already over
        if(grid[newMove.column][newMove.row] == ' '){
            grid[newMove.column][newMove.row] = newMove.player;
        }
        else{
            throw InvalidMove("Space already filled");
        }
    }
    else{
        //throw InvalidMove("Game already over");
	throw ParseError("Test");
    }
}

char Board::checkWin(){
    char index;
    for(int i = 0; i < numCol; i++){ // check col
        index = grid[i][0];
        for(int j = 1; j < numRow; j++){
            if(index == ' ' || grid[i][j] != index){
                break;
            }
            else if(j == numRow-1){
                return index;
            }
        }
    }

    for(int i = 0; i < numRow; i++){ // check row
        index = grid[0][i];
        for(int j = 1; j < numCol; j++){
            if(index == ' ' || grid[j][i] != index){
                break;
            }
            else if(j == numCol-1){
                return index;
            }
        }
    }
    
    for(int i = 0; i < 2; i++){
        index = grid[0][(numRow-1)*i];
        for(int j = 1; j < numCol; j++){ // check diagonals
            if(index == ' ' || grid[j][(numCol-1)*i+int(pow(-1,i))*j] != index){
                break;
            }
            else if(j == numCol-1){
                return index;
            }
        }
    }
    return ' '; // no win yet
}

void Board::printGrid(){ // assume 3x3
    std::cout << "   1   2   3 " << std::endl;
    std::cout << "A  " << grid[0][0] << " | " << grid[1][0] << " | " << grid[2][0] << std::endl;
    std::cout << "  ---+---+---" << std::endl;
    std::cout << "B  " << grid[0][1] << " | " << grid[1][1] << " | " << grid[2][1] << std::endl;
    std::cout << "  ---+---+---" << std::endl;
    std::cout << "C  " << grid[0][2] << " | " << grid[1][2] << " | " << grid[2][2] << std::endl;

}
