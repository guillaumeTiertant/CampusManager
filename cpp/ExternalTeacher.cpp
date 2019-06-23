#include "externalTeacher.h"

using namespace std;


/*******************************************************
 *********** CONSTRUCTEURS - DESTRUCTEURS **************
 *******************************************************/

ExternalTeacher::ExternalTeacher() : Teacher()
{}

ExternalTeacher::ExternalTeacher( string firstName, string lastName, int wage, int id )
    : Teacher( firstName, lastName, id), m_wage( wage )
{}

ExternalTeacher::ExternalTeacher( const ExternalTeacher &et )
    : Teacher( et.getFirstName(), et.getLastName(), et.getId() ), m_wage(et.getWage() )
{}


/*******************************************************
 ***************** GETTERS - SETTERS *******************
 *******************************************************/

int ExternalTeacher::getWage() const
{
    return m_wage;
}

void ExternalTeacher::setWage( const int wage )
{
    m_wage = wage;
}

int ExternalTeacher::getId() const
{
    return m_id;
}

void ExternalTeacher::setId( const int id )
{
    m_id = id;
}

/*******************************************************
 *********************** JSON **************************
 *******************************************************/


string ExternalTeacher::to_json()
{
    ostringstream oss;
    write_json ( oss, this->ptree_to_json(), true/*(1 par defaut)*/ );
    return oss.str();
}

ptree ExternalTeacher::ptree_to_json()
{
    ptree pt = Teacher::ptree_to_json();
    pt.put ( "type", "external" );

    return pt;
}
