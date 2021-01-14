//
//  main.cpp
//  polymorphism_human
//
//  Created by 释然 on 2021/1/14.
//
#include <string>
#include <vector>

using namespace std;

void createWorld();

class Human{
    
public:
    string name = "";
    int age = 1;
    
    Human(){
    };
    
    
    virtual void pee(){
        
    };
    
    virtual void walk(){
        
    };
    void crawl(){
        printf("%s crawing...\n",name.c_str());
    };
    
    
};

class Baby:public Human{
    
public:
    Baby(){};
    
    Baby(string name){
        this->name = name;
    };
    
    Baby(string name,int age){
        this->name = name;
        this->age = age;
    };
    
    ~Baby(){
        delete &name;
        delete &age;
    };
    
    void pee() override{
        if ((age)<3) {
            printf("%s pee with it's parents help...\n",name.c_str());
        }else{
            printf("%s pee by itself...\n",name.c_str());
        }
    }
    
    void walk() override{
        if ((age)<2) {
            printf("%s can't walk yet...\n",name.c_str());
        }else{
            printf("%s walking...\n",name.c_str());
        }
    }
};


class Man:public Human{
public:
    Man();
    
    Man(string name,int age){
        this->name = name;
        this->age = age;
    }
    
    void walk() override{
        printf("%s walking...\n",name.c_str());
    }
    
    void pee() override{
        printf("%s pee by standing...\n",name.c_str());
    }
};


class Woman:public Human{
public:

    vector<Baby*> *babys = new vector<Baby*>(10);
    
    Woman();
    
    Woman(string name,int age){
        this->name = name;
        this->age = age;
    }

    Baby* haveABaby(Man* man,string name);

    void walk() override{
        printf("%s walking...\n",name.c_str());
    }
    void pee() override{
        printf("%s pee by sitting...\n",name.c_str());
    }
};

Baby* Woman::haveABaby(Man* man,string name){
    Baby *baby = NULL;
    if (man) {
        baby = new Baby(name);
        babys->push_back(baby);
    }
    return baby;
}

int main(int argc, const char * argv[]) {
    createWorld();
    return 0;
}

void createWorld(){
    //create Adam
    Human* Adam = new Man("Adam",18);
    Adam->walk();
    Adam->pee();
    //create Eve
    Human* Eve = new Woman("Eve",16);
    Eve->walk();
    Eve->pee();
    //Adam meet Eve
    //Eve have a baby Gain
    string name_gain = "Gain";
    Human *Gain =  ((Woman*)Eve)->haveABaby((Man*)Adam,name_gain);
    Gain->walk();
    Gain->pee();
    Gain->crawl();
    //Eve have a baby Abel
    string name_abel = "Abel";
    Human *Abel =  ((Woman*)Eve)->haveABaby((Man*)Adam,name_abel);
    Abel->age = 4;
    Abel->walk();
    Abel->pee();
    Abel->crawl();
}
