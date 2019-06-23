#include "student.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>


using namespace std;

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;


/*******************************************************
 *********** CONSTRUCTEURS - DESTRUCTEURS **************
 *******************************************************/

Student::Student() : m_id( 0 )
{}

Student::Student( const Student &s )
    : m_firstName( s.getFirstName() ), m_lastName( s.getLastName() ), m_id( s.getId() )
{}

Student::Student( string firstName, string lastName, int id )
    : m_firstName( firstName ), m_lastName( lastName ), m_id( id )
{}

Student::~Student()
{}


/*******************************************************
 ***************** GETTERS - SETTERS *******************
 *******************************************************/

string Student::getLastName() const
{
    return m_lastName;
}


void Student::setLastName( string lastName )
{
    m_lastName = lastName;
    return;
}


string Student::getFirstName() const
{
    return m_firstName;
}


void Student::setFirstName( string firstName )
{
    m_firstName = firstName;
    return;
}


int Student::getId() const
{
    return m_id;
}


void Student::setId( int id )
{
    m_id = id;
    return;
}


/*******************************************************
 ********************** METHODS ************************
 *******************************************************/

string Student::to_string() const
{
    return "[" +std::to_string( m_id )+ " - " + m_firstName + ", " + m_lastName + "]";
}

/*******************************************************
 *********************** JSON **************************
 *******************************************************/

string Student::to_json()
{
    ostringstream oss;
    write_json ( oss, this->ptree_to_json(), true /*(1 par defaut)*/ );
    return oss.str();
}

ptree Student::ptree_to_json()
{
    ptree pt;
    pt.put ( "firstName", getFirstName() );
    pt.put ( "lastName", getLastName() );
    pt.put ( "id", getId() );

    return pt;
}

void Student::ptree_get_json( ptree pt )
{
    m_firstName = pt.get<string>( "firstName" );
    m_lastName  = pt.get<string>( "lastName" );
    m_id        = pt.get<int>   ( "id" );
}

void Student::get_json( string json )
{
    ptree pt;
    std::istringstream iss ( json );
    read_json (iss, pt);
    ptree_get_json( pt );

}

/*******************************************************
 **************** OPERATORS OVERLOADING ****************
 *******************************************************/

ostream &operator<<( ostream &stream, const Student &s )
{
    stream << s.to_string() << endl;
    return stream;
}

bool Student::operator==( const Student &s )
{
    if ( m_id == 0 && s.m_id == 0 )
    {
        return ( m_firstName == s.m_firstName && m_lastName == s.m_lastName );
    }
    else if ( m_id == s.m_id )
    {
        return true;
    }
    else
        return false;
}
