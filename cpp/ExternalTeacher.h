#ifndef ExternalTeacher_h
#define ExternalTeacher_h

#include <string>

#include "teacher.h"


class ExternalTeacher : public Teacher
{

public:  
    /******* constructors - destructors *******/

    ExternalTeacher();
    ExternalTeacher( string firstName, string lastName, int wage , int id = 0 );
    ExternalTeacher( const ExternalTeacher& et );

    virtual ~ExternalTeacher(){}

    /******* getters - setters *******/

    int getWage() const override;
    void setWage( const int wage ) override;

    int getId() const;
    void setId( const int id );


    /******* JSON *******/

    string to_json() override;
    ptree ptree_to_json() override;


private:
    int m_wage;
};

#endif // ExternalTeacher_h
