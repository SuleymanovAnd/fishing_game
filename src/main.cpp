#include <iostream>
#include "field.h"
#include <ctime>
#include "windows.h"


int main() {
    Field field1;
    std::srand(std::time(nullptr));

    field1[0].fish = new Fish();
    while (!field1.fieldIsReady()){
        field1[std::rand() % 9].addBoot(new Boot());
    }


    field1.showField();
    while (!field1.gameOver()){
        std::cout << "Cast your line into one of the 9 sectors of the pond:";
        int game = 0;
        std::cin >> game;
        try{field1.openSector(game);}
        catch (FieldExceptions &oth){
            std::cerr << oth.what();
        }
        Sleep(3000);
        system("cls");
        field1.showField();
    }





}
