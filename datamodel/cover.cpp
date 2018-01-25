#include "cover.h"
#include "covermapper.h"

cover::cover()
{
    setMapper(covermapper::getInstance());

}

void cover::setFileName(string fn)
{
    fileName=fn;
}

string cover::getFileName()
{
    return fileName;
}
