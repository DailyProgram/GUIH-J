#include "InterfaceSequences.h"
#include <ctime>
#include <iostream>

int *Sequences1::get_vector(unsigned int length, int subdate) {
    int *resultvector = new int[length];
    for (int i = 0; i < length; i++) {
        resultvector[i] = i + 1;
    }
    return resultvector;
}

int *Sequences2::get_vector(unsigned int length, int subdate) {
    int *resultvector = new int[length];
    for (int i = length - 1; i >= 0; i--) {
        resultvector[length - 1 - i] = i + 1;
    }
    return resultvector;
}

int *Sequences3::get_vector(unsigned int length, int subdate) {
    int *resultvector = new int[length];
    srand(time(0));
    for (int i = 0; i < length; i++) {
        resultvector[i] = 1 + rand() % length;
    }
    return resultvector;
}

int *Sequences4::get_vector(unsigned int length, int subdate) {//0-up 1-down
    int *resultvector = new int[length];

    for (int i = 0; i < length; i++) {
        resultvector[i] = i + 1;
    }
    for (int i = 0; i < length - 1; i++) {
        if (i % 2 == 0) {
            int swp = resultvector[i];
            resultvector[i] = resultvector[i + 1];
            resultvector[i + 1] = swp;
        }
    }
    return resultvector;
}


int *Sequences5::get_vector(unsigned int length, int subdate) {

    int *resultvector = new int[length];

    int delim = length / subdate;
    int key = length;
    for (int j = 1; j <= subdate; j++) {
        for (int i = length - delim * j; i < length - delim * (j - 1); i++) {
            resultvector[i] = key;
            key--;
        }
    }
    resultvector[0] = 1;


    return resultvector;

}

int *Sequences6::get_vector(unsigned int length, int subdate) {
    int *resultvector = new int[length];
    for (int i = 0; i < length; i++) {
        resultvector[i] = i + 1;
    }

    srand(time(0));
    for (int i = 0; i < subdate; i++) {
        int swp1 = rand() % length;
        int swp2 = rand() % length;
        int sub = resultvector[swp1];
        resultvector[swp1] = resultvector[swp2];
        resultvector[swp2] = sub;

    }
    return resultvector;

}

int *Sequences7::get_vector(unsigned int length, int subdate) {
    int *resultvector = new int[length];
    srand(time(0));
    for (int i = 0; i < length; i++) {
        resultvector[i] = 1 + rand() % length;
    }
    int repeat_elem = 1 + rand() % length;
    int percent = ((float) length / (float) 100) * subdate;

    for (int i = 0; i < percent; i++) { resultvector[i] = repeat_elem; }
    return resultvector;
}


int *Sequences8::get_vector(unsigned int length, int subdate) {
    int *resultvector = new int[length];
    for (int i = 0; i < length; i++) {
        if (i % 2 == 0) { resultvector[i] = 0; }
        else { resultvector[i] = 1; }
    }
    return resultvector;
}
