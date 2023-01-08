#include <iostream>
#include "field.h"
#include <ctime>

int main() {
    Field field1;
    std::srand(std::time(nullptr));

    field1[0].fish = new Fish();
    while (!field1.fieldIsReady()){
        field1[std::rand() % 9].addBoot(new Boot());
    }

    field1.showField();




}
