#include "internalTeacher.h"

using namespace std;


/*******************************************************
 *********** CONSTRUCTORS - DESTRUCTOlRS **************
 *******************************************************/


InternalTeacher::InternalTeacher()
    : Teacher()
{}

InternalTeacher::InternalTeacher( string firstName, string lastName, int id )
    : Teacher( firstName, lastName , id )
{}

InternalTeacher::InternalTeacher(const InternalTeacher &it)
    : Teacher( it.getFirstName(), it.getLastName(), it.getId() )
{}

InternalTeacher::~InternalTeacher()
{}

/*******************************************************
 ***************** GETTERS - SETTERS *******************
 *******************************************************/

int InternalTeacher::getWage() const
{
    return m_wage;
}

void InternalTeacher::setInternalWage( const int wage )
{
    m_wage = wage;
}

int InternalTeacher::getId() const
{
    return m_id;
}

void InternalTeacher::setId( const int id )
{
    m_id = id;
}

void InternalTeacher::setWage( const int wage )
{
    m_wage = wage;
}


/*******************************************************
 ***************** STATIC DECLARATION ******************
 *******************************************************/

int InternalTeacher::m_wage = 0;

/*******************************************************
 *********************** JSON **************************
 *******************************************************/

ptree InternalTeacher::ptree_to_json()
{
    ptree pt = Teacher::ptree_to_json();
    pt.put ( "type", "internal" );

    return pt;
}

string InternalTeacher::to_json()
{
    ostringstream oss;
    write_json ( oss, this->ptree_to_json(), true/*(default: 1)*/ );

    return oss.str();
}
