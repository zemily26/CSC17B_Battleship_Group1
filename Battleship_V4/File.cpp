#include <iostream>
using namespace std;

#include "File.h"

File::File() {
}

File::File(const File& orig) {
}

File::~File() {
}


//reading binary files
void File::readBin() {
  //put code in here lol
}

//writing binary files 
void File::wrtBin(/*data*/ char *a) {
  /* From Older Version of Battleship 
    void wrtBin(fstream &out, data *a, int size){
      out.write(reinterpret_cast<char *>(a), sizeof(a));
    } 
  */
  fileStream.write(reinterpret_cast<char *>(a),sizeof(a));
}
