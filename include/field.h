#include <iostream>
#include "fish.h"
#include "boot.h"
#include "exceptions.h"

class Field {

    int field [9];
    bool opnField [9];

public:

    Fish *fish = NULL;
    Boot *boot1 = NULL;
    Boot *boot2 = NULL;
    Boot *boot3 = NULL;

    Field ();
    Field (const Field &oth);
    Field& operator [] (int value);
    void showField ();
    void openSector (int sectorNum);
    ~Field ();

};