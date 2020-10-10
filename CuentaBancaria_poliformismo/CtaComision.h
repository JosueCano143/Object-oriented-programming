
#ifndef CtaComision_h
#define CtaComision_h

#include "CtaBanc.h"

class CtaComision : public CtaBanc {
    public:    
        CtaComision();    
        CtaComision( int n, double s, double com);    
        double getComision() { return comision; }    
        void setComision(double com) { comision = com; }    
        void mostrar();
        bool retira(double cant);
    private:    
        double comision;
    };

CtaComision::CtaComision():CtaBanc(){    
    comision = 0;
}

CtaComision::CtaComision(int n, double s, double com): CtaBanc(n,s) {    
    comision = com;
}


bool CtaComision::retira(double cant) {
    if (saldo >= (cant + comision)) {
        saldo -= (cant + comision);
        return true;
    }
    else
        return false;
}

void CtaComision::mostrar() {    
    cout << "Cuenta: " << numCuenta << '\t'
        << "Saldo: " << saldo << endl  
        << "Comision: " << comision << endl;  
}


#endif /* CtaComision_h */