#ifndef InternalTeacher_h
#define InternalTeacher_h

#include <string>

#include "teacher.h"


class InternalTeacher : public Teacher
{

public:
    /******* constructors - destructors *******/

    InternalTeacher();
    InternalTeacher( string firstName, string lastName, int id = 0 );
    InternalTeacher( const InternalTeacher &it );

    virtual ~InternalTeacher();


    /******* getters - setters *******/

    int getWage() const override; //ok
    static void setInternalWage( const int wage );

    int getId() const;
    void setId( const int id );


    /******* JSON *******/

    ptree ptree_to_json() override;
    string to_json() override;


private:
    static int m_wage;
    void setWage( const int wage ) override;
};

#endif // InternalTeacher_h
