
#ifndef FILE_H
#define FILE_H

#include <fstream>

class File {
public:
    File();
    File(const File& orig);
    virtual ~File();
private:
    std::fstream fileStream;
};

#endif /* FILE_H */

