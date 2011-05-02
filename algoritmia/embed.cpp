#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

bool embed()
{
  ifstream If;
  ofstream Of;
  If.open("datos_planos.dat");
  Of.open("2d.dat");
  double a,b;
  
  while(!If.eof()){
    If>>a;
    If>>b;
    Of<<a-b/((a*b)-1)<<" "<<sin(a*b)<<endl;
  }
  return true;
}

int main(int argc, char* argv[])
{
  
  if(!embed()) cout<<"bad embed"<<endl;
  
 return 0; 
}