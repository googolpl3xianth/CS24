#include "Board.h"
#include "Errors.h"
#include "Move.h"

int main(int argc, char** argv) {
    bool verbose = false;
    Board newGame;

    if(argc == 2 && std::string(argv[1]) == "-v") {
        verbose = true;
    }

    if(verbose) {
        std::cout << "> ";
    }
    std::string line = "Null";

    while(line != ""){
        std::getline(std::cin, line);
        try{
            if(std::cin.eof()){ newGame.checkState(); return 0; }
            Move newMove(line);
            try{
                newGame.addMove(newMove);
                if(verbose){
                    newGame.printGrid();
                }
            }
            catch(const InvalidMove& e){
                if(verbose){
                    std::cout << "Invalid move: " << e.what() << std::endl;
                }
                else{
                    std::cout << "Invalid move.\n";
                }
                return 2; 
            }
        }
        catch(const ParseError& e) {
            if(verbose){
                std::cout << "Parse error: " << e.what() << std::endl;
            }
            else{
                std::cout << "Parse error.\n";
            }
            return 1;
        }
    }
    newGame.checkState();
}
