#include "Filename.h"

std::string AVN::getFilenameOnly(const std::string &strFullFilePath)
{
    //try find forward slash
    size_t lastSlashPos = strFullFilePath.find_last_of("/");

    //if it doesn't exist try to find backlash
    if(lastSlashPos == std::string::npos)
    {
        lastSlashPos = strFullFilePath.find_last_of("\\");
    }

    //if there is still nothing found then filename is just input string
    if(lastSlashPos == std::string::npos)
    {
        return strFullFilePath;
    }

    //Otherwise take the substring and return
    return strFullFilePath.substr(lastSlashPos + 1);
}

std::string AVN::getFileDirectory(const std::string &strFullFilePath)
{
    //try find forward slash
    size_t lastSlashPos = strFullFilePath.find_last_of("/");

    //if it doesn't exist try to find backlash
    if(lastSlashPos == std::string::npos)
    {
        lastSlashPos = strFullFilePath.find_last_of("\\");
    }

    //if there is still nothing found then filename is just input string
    if(lastSlashPos == std::string::npos)
    {
        return strFullFilePath;
    }

    //Otherwise take the substring and return
    return strFullFilePath.substr(0, lastSlashPos);
}

std::string AVN::createFullFilePath(const std::string &strFileDirectory, const std::string &strFilenameOnly)
{
    //This function only checks whether the directory has a trailing slash and adds it as necessary

    std::string strFullFilePath = strFileDirectory;
    bool bForwardSlash = false;

    //try find forward slash
    size_t lastSlashPos = strFullFilePath.find_last_of("/");

    //if it doesn't exist try to find backlash
    if(lastSlashPos == std::string::npos)
    {
        lastSlashPos = strFullFilePath.find_last_of("\\");
        if(lastSlashPos == std::string::npos)
        {
            //If not slashes are found determine by OS
#ifdef __unix__
            bForwardSlash = true;
#endif

            //Otherwise it is windows so leave as false as set above
        }
        //Found forward slash leave as false as set above
    }
    else
    {
        //Otherwise we found a forward slash so mark to use it
        bForwardSlash = true;
    }

    if(bForwardSlash)
    {
        if(strFullFilePath[strFullFilePath.length()-1] != '/')
            strFullFilePath.append("/");
    }
    else
    {
        if(strFullFilePath[strFullFilePath.length()-1] != '\\')
            strFullFilePath.append("\\");
    }
    strFullFilePath.append(strFilenameOnly);

    return strFullFilePath;
}
