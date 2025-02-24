#include "WordList.h"
#include <iostream>//
#include <cmath>

WordList::WordList(std::istream& stream){
    std::string word;
    bool valid;
    while(getline(stream, word)){
        valid = true;
        for(char a : word){
            if(!std::islower(a) && a != '\r'){
                //std::cout << "|" << a << "|" << std::endl;//
                valid = false;
                break;
            }
        }
        if(valid){
            mWords.push_back(word);
        }
    }
    //std::cout << mWords.size() << std::endl;//
}

Heap WordList::correct(const std::vector<Point>& points, size_t maxcount, float cutoff) const{
    Heap scores(maxcount);
    float d, sumScore;
    for(std::string word : mWords){
        if(word.size() == points.size()){
            sumScore = 0;
            for(size_t i = 0; i < word.size(); i++){ 
                d = pow(pow(QWERTY[word[i]-97].x-points[i].x, 2) + pow(QWERTY[word[i]-97].y-points[i].y, 2), .5); // ascii a = 97
                sumScore += 1 / (10 * pow(d, 2) + 1);
            }
            sumScore /= word.size();
            if(sumScore >= cutoff){
                if(scores.count() < scores.capacity()){
                    scores.push(word, sumScore);
                }
                else{
                    scores.pushpop(word, sumScore);
                }
            }
        }
    }
    
    return scores;
}
