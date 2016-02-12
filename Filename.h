
#ifndef _FILENAME_
#define _FILENAME_

#include <string>

namespace AVN
{
std::string getFilenameOnly(const std::string &strFullFilePath);
std::string getFileDirectory(const std::string &strFullFilePath);
std::string createFullFilePath(const std::string &strFileDirectory, const std::string &strFilenameOnly);
}

#endif //_FILENAME_
