#include "field.h"

Field::Field() {

    for (int i = 0; i<9;++i){
        field[i] = 0;
        opnField[i] = false;
    }
}

Field& Field::operator [] (int value){

    if (fish == NULL ) {
        field[value] = 1;
        return *this;
    }
    else {
        if (field[value] != 1 && field[value != 2]){
            if(boot1 == NULL || boot2 == NULL || boot3 == NULL){
                field[value] = 2;
                return *this;
            }else {
                FieldExceptions ("boots already placed");
            }
        }else {
            throw FieldExceptions ( "this place in the pond is already taken");
        }
    }


}

Field::Field(const Field& oth){
    for (int i = 0; i<9;++i){
        field[i] = oth.field[i];
        opnField[i] = oth.opnField[i];
    }
}

void Field::showField(){
    for (int i =0;i<9;++i){
        if (opnField[i] == false){
            std::cout << field[i] <<" ";
            if ((i+1)%3 == 0){std::cout << std::endl;}
        }
    }
}

void Field::openSector  (int sectorNum){
    opnField[sectorNum] = true;

    if (field[sectorNum] == 1){
        //throw win;
    }  else if(field[sectorNum] == 2){
        //  throw loss;
    }else {
        std::cout << "this place is empty";}
}

Field::~Field () {
    delete fish;
    delete boot1;
    delete boot2;
    delete boot3;
};