//
// Created by pda on 10.06.19.
//

#ifndef H_J_INTERFACESEQUENCES_H
#define H_J_INTERFACESEQUENCES_H


class InterfaceSequences {
public:
    ~InterfaceSequences() {};

    virtual int *get_vector(unsigned int length, int subdate) = 0;
};

class Sequences1 : public InterfaceSequences {
public:
    int *get_vector(unsigned int length, int subdate) override;
};

class Sequences2 : public InterfaceSequences {
public:
    int *get_vector(unsigned int length, int subdate) override;
};

class Sequences3 : public InterfaceSequences {
public:
    int *get_vector(unsigned int length, int subdate) override;
};

class Sequences4 : public InterfaceSequences {
public:
    int *get_vector(unsigned int length, int subdate) override;
};

class Sequences5 : public InterfaceSequences {
public:
    int *get_vector(unsigned int length, int subdate) override;
};

class Sequences6 : public InterfaceSequences {
public:
    int *get_vector(unsigned int length, int subdate) override;
};

class Sequences7 : public InterfaceSequences {
public:
    int *get_vector(unsigned int length, int subdate) override;
};

class Sequences8 : public InterfaceSequences {
public:
    int *get_vector(unsigned int length, int subdate) override;
};


#endif //H_J_INTERFACESEQUENCES_H
