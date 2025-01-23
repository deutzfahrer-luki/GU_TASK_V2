#include "loaddata.h".h"
#include <iostream>

// Initialisierung des statischen Zeigers auf das Singleton
LoadData* LoadData::instance = nullptr;

LoadData::LoadData() {
}

LoadData* LoadData::getInstance() {
    if (instance == nullptr) {
        instance = new LoadData();
    }
    return instance;
}
