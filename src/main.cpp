#include <iostream>
#include "field.h"

int main() {
    Field field1;

    field1[0].fish = new Fish();
    field1[5].boot1 = new Boot();
    field1[3].boot2 = new Boot();
    field1[7].boot3 = new Boot();

}
