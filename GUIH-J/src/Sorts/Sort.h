//
// Created by pda on 16.06.19.
//

#ifndef H_J_SORT_H
#define H_J_SORT_H

#include <time.h>

class Resultdata {
private:
    int swp;
    int eql;
    double time;
public:
    void set_swp(int);

    void set_eql(int);

    void set_time(double);

    int get_swp();

    int get_eql();

    double get_time();
};

class InterfaceSort{

public:
    virtual Resultdata *sorting(int *, unsigned int) = 0;


};

class Heapsort : public InterfaceSort {
protected:
    void siftDown(int *numbers, int root, int bottom);

public:
    Resultdata *sorting(int *, unsigned int) override;

};

class Jsort : public InterfaceSort {
public:
    Resultdata *sorting(int *, unsigned int) override;
};

#endif //H_J_SORT_H
