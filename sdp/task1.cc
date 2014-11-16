#include <iostream>
#include <iomanip>
using namespace::std;

class FPWM{
  
  int width;
  char fill;
  int precision;

  public:
    FPWM(int w, char f, int p) : width(w), fill(f), precision(p){};
    friend ostream& operator<<(ostream& out, const FPWM& fpwm_instance);        
};

ostream& operator<<(ostream& out, const FPWM& fpwm_instance){

    out << setiosflags(ios::fixed) << setprecision(fpwm_instance.precision) << setw(fpwm_instance.width) << setfill(fpwm_instance.fill);

    return out;
}

ostream& fixed_precision(ostream& out){
  out << setiosflags(ios::fixed) << setprecision(2);

  return out;
}

int main(){

  cout << FPWM(10, '*', 2) <<  2.34 << endl;

  return 0;
}