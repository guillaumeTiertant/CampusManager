#include "fullCampusException.h"

FullCampusException::FullCampusException()
    : std::runtime_error( "Plus de places disponibles dans ce campus" )
{}
