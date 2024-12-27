#include <iostream>
#ifndef SOBRECARGAIGUALX2_H
#define SOBRECARGAIGUALX2_H
using namespace std;

class SobrecargaIgualx2{
    private:
        int x;
        

    public:
        SobrecargaIgualx2() : x(0){}
        void entrada();

        bool operator==(const SobrecargaIgualx2 &obj) ;
        void salida();
};
#endif
