#include "field.h"
#include <sstream>

Field::Field() {

    for (int i = 0; i<9;++i){
        field[i] = 0;
        opnField[i] = false;
    }
}

Field& Field::operator [] (int value){

    if (fish == NULL ) {
        field[value] = 1;
    }else {
        place = value;
    }
    return *this;


}
void Field::addBoot (Boot *oth){
    if(place == -1){ std::cout << "fish not plased yet"<<std::endl;}
    else {
        if (field[place] != 1 && field[place] != 2) {
            if (boots[0] == NULL || boots[1] == NULL || boots[2] == NULL) {
                if (boots[0] == NULL) { boots[0] = oth; }
                else if (boots[1] == NULL) { boots[1] = oth; }
                else if (boots[2] == NULL) { boots[2] = oth; }
                field[place] = 2;
            } else {
                delete oth;
                fieldReady = true;
            }

        } else {
            delete oth;
        }
    }

}
bool Field::fieldIsReady (){
    return fieldReady;
}

Field::Field(const Field& oth){
    for (int i = 0; i<9;++i){
        field[i] = oth.field[i];
        opnField[i] = oth.opnField[i];
    }
}

void Field::showField(){
    for (int i =0;i<9;++i){
        if (opnField[i] == true){
            std::cout << field[i] <<" ";
        }else {
            std::cout << "- ";
        }
        if ((i+1)%3 == 0){std::cout << std::endl;}
    }
}

bool Field:: gameOver (){
    return endOfGame;
}

void Field::openSector  (int sectorNum){
    if (sectorNum<1 || sectorNum >9){
        std::cout << "You hit the pond. There is no such sector.\n"
                     "Enter a number from 1 to 9.\n";
    }else {

        opnField[sectorNum-1] = true;

        if (field[sectorNum-1] == 1) {
            endOfGame = true;
            ++attempts;
            std::stringstream temp; temp << " You are win. You spent " << attempts << " attempts.\n";
            throw FieldExceptions(temp.str().c_str());

        } else if (field[sectorNum-1] == 2) {
            endOfGame = true;
            throw FieldExceptions("You have caught the boot. You lose\n");
        } else {
            ++attempts;
            std::cout << "this place is empty\n";
        }
    }
}

Field::~Field () {
    delete fish;
    delete boots[0];
    delete boots[1];
    delete boots[2];
};