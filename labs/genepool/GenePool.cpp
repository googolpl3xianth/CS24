#include "GenePool.h"
#include <iostream>
#include <sstream>

// GenePool Member Functions
GenePool::GenePool(std::istream& stream){
    count = 0;

    std::string line = "";
    int index = 0;
    Person* newPerson;

    //std::cout << "what is going on" << std::endl;//
    
    while(getline(stream, line)){
        std::stringstream ss(line);
        if(line[0] != '#' && std::isalpha(line[0])){
            newPerson = new Person;
            while(getline(ss, line, '\t')){
                //std::cout << index << " |" << line << "|" << std::endl;//
                switch(index){
                    case 0:
                        newPerson->setName(line);
                        index++;
                        break;
                    case 1:
                        if(line == "female"){
                            newPerson->setGender(Gender::FEMALE);
                        }
                        else if(line == "male"){
                            newPerson->setGender(Gender::MALE);
                        }
                        else if(line == "???"){
                            newPerson->setGender(Gender::ANY);
                        }
                        else{
                            std::cerr << "Error: Gender input: \"" << line << "\"" << std::endl;
                            exit(1);
                        }
                        index++;
                        break;
                    case 2:
                        if(line == "???"){
                            newPerson->setMother(NULL);
                        }
                        else{
                            Person *temp = find(line);
                            newPerson->setMother(temp);
                            temp->addChild(newPerson);
                        }
                        index++;
                        break;
                    case 3:
                        line = line.std::string::substr(0, line.size());
                        if(line == "???"){
                            newPerson->setFather(NULL);
                        }
                        else{
                            Person *temp = find(line);
                            newPerson->setFather(temp);
                            temp->addChild(newPerson);
                        }
                        mTree[newPerson->name()] = newPerson;
                        count++;
                        index = 0;
                        break;               
                    default:
                        std::cerr << "Error: input index: " << index << std::endl;
                        exit(1);
                }
            }
        }
    }
    /*for(Person* person : everyone()){
        std::cout << person->name() << " " << std::endl;
    }*///
    //std::cout << "wtf" << std::endl;//
}
GenePool::~GenePool(){
    for(auto member : mTree){
        delete member.second;
    }
}
std::set<Person*> GenePool::everyone() const{
    std::set<Person*> everyone;
    for(auto member : mTree){
        everyone.insert(member.second);
    }
    return everyone;
}
Person* GenePool::find(const std::string& name) const{
    try{
        return mTree.at(name);
    }
    catch(const std::out_of_range& e){
        return NULL;
    }
}

