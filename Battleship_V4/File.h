#ifndef FILE_H
#define FILE_H

#include <fstream>
using namespace std;

class File {
public:
    File();
    File(const File& orig);
    void readBin();
    void wrtBin();
    virtual ~File();
private:
    fstream fileStream;
};

#endif /* FILE_H */