#include "internalTeacher.h"
#include "teacher.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>


using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

using namespace std;


/*******************************************************
 *********** CONSTRUCTORS - DESTRUCTORS **************
 *******************************************************/

Teacher::Teacher()
{}

Teacher::Teacher( string firstName, string lastName, int id )
    : m_firstName( firstName ), m_lastName( lastName ), m_id( id )
{}

/*******************************************************
 ***************** GETTERS - SETTERS *******************
 *******************************************************/

int Teacher::getId() const
{
    return m_id;
}

void Teacher::setId( const int id )
{
    m_id = id;
}

string Teacher::getFirstName() const
{
    return m_firstName;
}

void Teacher::setFirstName( const string &firstName )
{
    m_firstName = firstName;
}

string Teacher::getLastName() const
{
    return m_lastName;
}

void Teacher::setLastName( const string &lastName )
{
    m_lastName = lastName;
}

string Teacher::to_string() const
{
    return "[" + std::to_string( m_id ) + " - " + m_firstName + ", " + m_lastName + "]";
}

/*******************************************************
 *********************** JSON **************************
 *******************************************************/

ptree Teacher::ptree_to_json()
{
    ptree pt;
    pt.put ( "firstName", getFirstName() );
    pt.put ( "lastName", getLastName() );
    pt.put ( "id", getId() );
    pt.put ( "wage", getWage() );

    return pt;
}

void Teacher::get_json( string json )
{
    ptree pt;
    std::istringstream iss ( json );
    read_json ( iss, pt );
    ptree_get_json( pt );
}

void Teacher::ptree_get_json( ptree pt)
{
    m_firstName = pt.get<string>( "firstName" );
    m_lastName  = pt.get<string>( "lastName" );
    m_id        = pt.get<int>   ( "id" );
    setWage( pt.get<int>        ( "wage" ) );
}

/*******************************************************
 **************** OPERATORS OVERLOADING ****************
 *******************************************************/

bool Teacher::operator==( const Teacher &t )
{ 
    if ( m_id == 0 && t.m_id == 0 )
    {
        return ( m_firstName == t.m_firstName && m_lastName == t.m_lastName );
    }
    else if ( m_id == t.m_id )
    {
        return true;
    }
    else
        return false;
}

ostream &operator<<( ostream &stream, const Teacher &t )
{
    stream << t.to_string() << endl;
    return stream;
}
