#include <iostream>
#include "fish.h"
#include "boot.h"
#include "exceptions.h"

class Field {

    int field [9];
    bool opnField [9];
    Boot * boots [3] = {NULL,NULL,NULL};
    int place = -1;
    bool fieldReady = false;
public:

    Fish *fish = NULL;


    Field ();
    Field (const Field &oth);
    Field& operator [] (int value);
    void addBoot (Boot *oth);
    void showField ();
    bool fieldIsReady ();
    void openSector (int sectorNum);
    ~Field ();

};