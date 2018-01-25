#include "datamodelrepository.h"
#include "actressmapper.h"
#include "filmmapper.h"
#include "covermapper.h"

void DatamodelRepository::init()
{
    actressmapper::getInstance();
    filmmapper::getInstance();
    covermapper::getInstance();
}

