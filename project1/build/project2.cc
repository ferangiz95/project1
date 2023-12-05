#include <iostream>
#include <fstream>
#include <cstdlib> 
  
using namespace std;

int main(int argc, char** argv) {
    
  ofstream myfile;
  myfile.open ("project1.txt");
  G4cout << "Writing this to a file.\";
  myfile.close();
  return 0;
 }
