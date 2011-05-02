#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

bool isFull(double TS[][], double xi, double yi,double e){
  //discrimina la caja si esta tiene un piunto adentro.
  for(int i=0; i<2049){
    if((TS[i][0]>xi)&&(TS[i][1]>yi)&&(TS[i][0]<xi+e)&&(TS[i][1]<yi+e)) return true;
  }
  return false;
}

int main(int argc, char* argv[])
{
  
  ifstream read;
  read.open("2d.dat");
  
  double serie[2049][2];
  double maxy,maxx,minx,miny;//hay que hallar las fronteras para no botar caspa en cajas innecesarias
  int i=0
  while(!read.feof()){    
    read>>serie[i][0];
    read>>serie[i][1];
    
    i++;
  }
  
  
  
 return 0; 
}