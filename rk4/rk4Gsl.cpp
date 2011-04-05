#include<iostream>
#include<fstream>
#include<cmath>
#include<gsl/gsl_odeiv.h>
#include<gsl/gsl_errno.h>

#define step 1e-1

using namespace std;

int absolute(double t, const double y[], double f[], void *params){
  f[0]=y[2];
  f[1]=-0.6*y[1]-y[2]+abs(y[0])-1;
  f[2]=y[1];
  
  return GSL_SUCCESS;
}

int main(int argc, char **argv){
  
  ofstream outfile;
  outfile.open("absolute.dat");
  
  const gsl_odeiv_step_type *Type=gsl_odeiv_step_rk8pd;
  
  gsl_odeiv_step *Step=gsl_odeiv_step_alloc(Type,3);
  
  gsl_odeiv_system Sys={absolute,NULL,3,NULL};
  
  double t=0.0,tf=1000,yerr[3];
  double y[3]={0.0,0.0,0.0}; //Initial conditions
  
  while(t<tf){
    
    int status=gsl_odeiv_step_apply(Step,t,step,y,yerr,NULL,NULL,&Sys);
    
    outfile<<y[0]<<" "<<y[1]<<" "<<y[2]<<endl;
    
    t++;
    
  }
  
  outfile.close();
  
  return 0;
}