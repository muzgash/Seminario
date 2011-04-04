/*Copyleft (Ɔ) <2011>, <Gerardo Gutierrez>
 *All rights reserved
 *
 *This program is free software: you can redistribute it and/or modify
 *it under the terms of the GNU General Public License as published by
 *the Free Software Foundation, either version 3 of the License, or
 *(at your option) any later version.
 *
 *This program is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *GNU General Public License for more details.
 *
 *You should have received a copy of the GNU General Public License
 *along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 */

#include<iostream>
#include<fstream>
#include<cmath>

#define h 1.0e-2
#define w 3

using namespace std;

/**Runge-kutta method example code
We are going to integrate the a simple differential equation

y'=w*y

prime means the time derivative.
so we want to find the trajectories y(t) of the system.
*/

double expo(double t,double y){
  ///function y'
  return w*y;
}

double other(double t, double y){
  ///other function to play with
  return w*sin(y)-y*y;
}

double rk_step(double t,double y, double (*function)(double, double)){
  ///This is a general function that calculates an integration step h
  //Using the adventage of a pointer to a function
  double k1,k2,k3,k4;
  
  k1=h*function(t,y);
  k2=h*function(t+h/2,y+k1/2);
  k3=h*function(t+h/2,y+k2/2);
  k4=h*function(t+h,y+k3);
  
  return y+k1/6+k2/3+k3/3+k4/6;
}



int main(int argc, char *argv[]){
  
  ///File Stream for output
  ofstream outfile;
  outfile.open("exponential.dat");
  
  ///Initial conditions
  double yo=0.2;
  
  ///State variables: Position and speed
  double x,y;
  
  ///First integration step
  //be aware that a callback passing is made referencing the location in memory
  y=rk_step(0.0,yo,&expo);
  
  //printed in prompt for debugging purposes
  cout<<h<<" "<<yo<<endl<<x<<" "<<y<<endl;
  
  //first 2 lines printed in stream
  outfile<<h<<" "<<yo<<endl<<x<<" "<<y<<endl;
  
  for(int i=0;i<100;i++){
    y=rk_step(h+i*h,y,&expo);
    
    outfile<<h+i*h<<" "<<y<<endl;
  }
  
  return 0;
}