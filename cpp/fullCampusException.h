#ifndef FULLCAMPUSEXCEPTION_H
#define FULLCAMPUSEXCEPTION_H

#include <stdexcept>
#include <string>


class FullCampusException : public std::runtime_error
{

public:
    explicit FullCampusException();

};

#endif // FULLCAMPUSEXCEPTION_H
