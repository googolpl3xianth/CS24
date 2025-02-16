#include "Person.h"

// Person Member Functions

Person::Person(){
    mName = "";
    mGender = Gender::ANY;
    mMother = NULL;
    mFather = NULL;
}
Person::Person(std::string newName, Gender newGender, Person* mother, Person* father){
    mName = newName;
    mGender = newGender;
    mMother = mother;
    mFather = father;
}

// Required Getter Functions
const std::string& Person::name()   const{ return mName; }
Gender             Person::gender() const{ return mGender; }
Person*            Person::mother() { return mMother; }
Person*            Person::father() { return mFather; }

// Setter
void Person::setName(std::string newName){ mName = newName; }
void Person::setGender(Gender newGender){ mGender = newGender; }
void Person::setMother(Person* newMother){ mMother = newMother; }
void Person::setFather(Person* newFather){ mFather = newFather; }
void Person::addChild(Person* newChild){ mChildren.insert(newChild);}

// Required Relationship Functions
std::set<Person*> Person::ancestors(PMod pmod){
    std::set<Person*> ancestors;
    if(mMother != NULL && (pmod == PMod::MATERNAL || pmod == PMod::ANY)){
        ancestors.insert(mMother);
        ancestors.merge(mMother->ancestors());
    }
    if(mFather != NULL && (pmod == PMod::PATERNAL || pmod == PMod::ANY)){
        ancestors.insert(mFather);
        ancestors.merge(mFather->ancestors());
    }
    return ancestors;
}
std::set<Person*> Person::aunts(PMod pmod, SMod smod){
    std::set<Person*> aunts;
    if(mMother != NULL && (pmod == PMod::ANY || pmod == PMod::MATERNAL)){
        aunts.merge(mMother->sisters(PMod::ANY, smod));
    }
    if(mFather != NULL && (pmod == PMod::ANY || pmod == PMod::PATERNAL)){
        aunts.merge(mFather->sisters(PMod::ANY, smod));
    }
    return aunts;
}
std::set<Person*> Person::brothers(PMod pmod, SMod smod){
    std::set<Person*> brothers;
    if(mMother != NULL && (pmod == PMod::ANY || pmod == PMod::MATERNAL)){
        for(Person* child : mMother->mChildren){
            if(child != this && child->mGender == Gender::MALE && (smod == SMod::ANY || (smod == SMod::FULL && child->mFather == mFather && mFather != NULL) || (smod == SMod::HALF && (child->mFather != mFather || mFather == NULL)))){
                brothers.insert(child);
            }
        }
    }
    if(mFather != NULL && (pmod == PMod::ANY || pmod == PMod::PATERNAL)){
        for(Person* child : mFather->mChildren){
            if(child != this && child->mGender == Gender::MALE && (smod == SMod::ANY || (smod == SMod::FULL && child->mMother == mMother && mMother != NULL) || (smod == SMod::HALF && (child->mMother != mMother || mMother == NULL)))){
                brothers.insert(child);
            }
        }
    } 
    return brothers;
}
std::set<Person*> Person::children(){ return mChildren; }
std::set<Person*> Person::cousins(PMod pmod, SMod smod){
    std::set<Person*> cousins;
    for(Person* aunt : aunts(pmod, smod)){
        cousins.merge(aunt->children());
    }
    for(Person* uncle : uncles(pmod, smod)){
        cousins.merge(uncle->children());
    }
    return cousins;
}
std::set<Person*> Person::daughters(){
    std::set<Person*> daughters;
    for(Person* person : mChildren){
        if(person->mGender == Gender::FEMALE){
            daughters.insert(person);
        }
    }
    return daughters;
}
std::set<Person*> Person::descendants(){
    std::set<Person*> descendants = mChildren;
    if(!mChildren.empty()){
        for(Person* child : mChildren){
            descendants.merge(child->descendants());
        }
    }
    return descendants;
}
std::set<Person*> Person::grandchildren(){
    std::set<Person*> grandchildren;
    for(Person* child : mChildren){
        grandchildren.merge(child->children());
    }
    return grandchildren;
}
std::set<Person*> Person::granddaughters(){
    std::set<Person*> granddaughters;
    for(Person* child : mChildren){
        for(Person* grandChild : child->mChildren){
            if(grandChild->mGender == Gender::FEMALE){ granddaughters.insert(grandChild); }
        }
    }
    return granddaughters;
}
std::set<Person*> Person::grandfathers(PMod pmod){
    std::set<Person*> grandfathers;
    if(mMother != NULL && mMother->mFather != NULL && (pmod == PMod::MATERNAL || pmod == PMod::ANY)){ grandfathers.insert(mMother->mFather); }
    if(mFather != NULL && mFather->mFather != NULL && (pmod == PMod::PATERNAL || pmod == PMod::ANY)){ grandfathers.insert(mFather->mFather); }
    return grandfathers;
}
std::set<Person*> Person::grandmothers(PMod pmod){
    std::set<Person*> grandmothers;
    if(mMother != NULL && mMother->mMother != NULL && (pmod == PMod::MATERNAL || pmod == PMod::ANY)){ grandmothers.insert(mMother->mMother); }
    if(mFather != NULL && mFather->mMother != NULL && (pmod == PMod::PATERNAL || pmod == PMod::ANY)){ grandmothers.insert(mFather->mMother); }
    return grandmothers;
}
std::set<Person*> Person::grandparents(PMod pmod){
    std::set<Person*> grandparents;
    if(mMother != NULL && (pmod == PMod::MATERNAL || pmod == PMod::ANY)){ grandparents.merge(mMother->parents()); }
    if(mFather != NULL && (pmod == PMod::PATERNAL || pmod == PMod::ANY)){ grandparents.merge(mFather->parents()); }
    return grandparents;
}
std::set<Person*> Person::grandsons(){
    std::set<Person*> grandsons;
    for(Person* child : mChildren){
        for(Person* grandChild : child->mChildren){
            if(grandChild->mGender == Gender::MALE){ grandsons.insert(grandChild); }
        }
    }
    return grandsons;
}
std::set<Person*> Person::nephews(PMod pmod, SMod smod){
    std::set<Person*> nephews;
    for(Person* sibling : siblings(pmod, smod)){
        nephews.merge(sibling->sons());
    }
    return nephews;
}
std::set<Person*> Person::nieces(PMod pmod, SMod smod){
    std::set<Person*> nieces;
    for(Person* sibling : siblings(pmod, smod)){
        nieces.merge(sibling->daughters());
    }
    return nieces;
}
std::set<Person*> Person::parents(PMod pmod){
    std::set<Person*> parents;
    if(mMother != NULL && (pmod == PMod::ANY || pmod == PMod::MATERNAL)){ parents.insert(mMother); }
    if(mFather != NULL && (pmod == PMod::ANY || pmod == PMod::PATERNAL)){ parents.insert(mFather); }
    return parents;
}
std::set<Person*> Person::siblings(PMod pmod, SMod smod){
    std::set<Person*> siblings;
    if(mMother != NULL && (pmod == PMod::ANY || pmod == PMod::MATERNAL)){
        for(Person* child : mMother->mChildren){
            if(child != this && (smod == SMod::ANY || (smod == SMod::FULL && child->mFather == mFather && mFather !=NULL) || (smod == SMod::HALF && (child->mFather != mFather || mFather == NULL)))){
                siblings.insert(child);
            }
        }
    }
    if(mFather != NULL && (pmod == PMod::ANY || pmod == PMod::PATERNAL)){
        for(Person* child : mFather->mChildren){
            if(child != this && (smod == SMod::ANY || (smod == SMod::FULL && child->mMother == mMother && mMother != NULL) || (smod == SMod::HALF && (child->mMother != mMother || mMother == NULL)))){
                siblings.insert(child);
            }
        }
    }
    return siblings;
}
std::set<Person*> Person::sisters(PMod pmod, SMod smod){
    std::set<Person*> sisters;
    if(mMother != NULL && (pmod == PMod::ANY || pmod == PMod::MATERNAL)){
        for(Person* child : mMother->mChildren){
            if(child != this && child->mGender == Gender::FEMALE && (smod == SMod::ANY || (smod == SMod::FULL && child->mFather == mFather && mFather != NULL) || (smod == SMod::HALF && (child->mFather != mFather || mFather == NULL)))){
                sisters.insert(child);
            }
        }
    }
    if(mFather != NULL && (pmod == PMod::ANY || pmod == PMod::PATERNAL)){
        for(Person* child : mFather->mChildren){
            if(child != this && child->mGender == Gender::FEMALE && (smod == SMod::ANY || (smod == SMod::FULL && child->mMother == mMother && mMother != NULL) || (smod == SMod::HALF && (child->mMother != mMother || mMother == NULL)))){
                sisters.insert(child);
            }
        }
    }
    return sisters;
}
std::set<Person*> Person::sons(){
    std::set<Person*> sons;
    for(Person* child : mChildren){
        if(child->mGender == Gender::MALE){
            sons.insert(child);
        }
    }
    return sons;
}
std::set<Person*> Person::uncles(PMod pmod, SMod smod){
    std::set<Person*> uncles;
    if(mMother != NULL && (pmod == PMod::ANY || pmod == PMod::MATERNAL)){
        uncles.merge(mMother->brothers(PMod::ANY, smod));
    }
    if(mFather != NULL && (pmod == PMod::ANY || pmod == PMod::PATERNAL)){
        uncles.merge(mFather->brothers(PMod::ANY, smod));
    }
    return uncles;
}   
