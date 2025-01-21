#include "Errors.h"
#include "Move.h"
#include <iostream>

Move::Move(const std::string& input){
    int arg = 0;
    std::string comment = ""; 
    char inputReader = ' ';

    for(int i = 0; i < int(input.size()); i++){
        inputReader = input[i];
        switch(arg){
            case 0:
                if(!std::isdigit(inputReader) || inputReader == '0'){throw ParseError("Invalid Turn Number");}
                this->number = inputReader - 48; // ASCII 1 is 49
                arg++;
                break;
            case 1:
                if(std::isspace(inputReader)){arg++; break;}
                else{throw ParseError("Invalid space formating");}
            case 2:
                if(std::isspace(inputReader)){break;}
                inputReader = std::toupper(inputReader);
                if(!(inputReader == 'X' || inputReader == 'O')){throw ParseError("Invalid Player");}
                this->player = inputReader;
                arg++;
                break;
            case 3:
                if(std::isspace(inputReader)){arg++; break;}
                else{throw ParseError("Invalid space formating");}
            case 4:
                if(std::isspace(inputReader)){break;}
                inputReader = std::toupper(inputReader);
                if(!(inputReader == 'A' || inputReader == 'B' || inputReader == 'C')){throw ParseError("Invalid Row");}
                this->row = inputReader - 65; // ASCII A == 65
                arg++;
                break;
            case 5:
                if(!std::isdigit(inputReader) || !(inputReader == '1' || inputReader == '2' || inputReader == '3')){throw ParseError("Invalid Column");}
                this->column = inputReader - 49;
                arg++;
                break;
            case 6:
                if(std::isspace(inputReader)){arg++; break;}
                else{throw ParseError("Invalid space formating");}
            case 7:
                if(std::isspace(inputReader)){break;}
                if(!std::isspace(input[i-1]) || inputReader != '#'){throw ParseError("Invalid Commet");}
                if(i+1 < int(input.size())){
                    comment = input.std::string::substr(i+1);
                }
                return;
        }
    }
}

std::string Move::to_string() const{
    std::string moveText = std::to_string(this->number) + " " + this->player + " " + char(row + 65) + std::to_string(column);
    return moveText;
}
