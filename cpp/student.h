#ifndef Student_h
#define Student_h

#include <iostream>
#include <string>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>


using std::string;
using std::ostream;

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;


class Student
{

public:
    /******* constructeurs - destructeurs *******/

    Student();
    Student( const Student& s );
    Student( string firstName, string lastName, int id = 0 );

    ~Student();


    /******* getters- setters *******/

    string getLastName() const;
    void setLastName( string lastName );

    string getFirstName() const;
    void setFirstName( string firstName );

    int getId() const;
    void setId( int id );


    /******* methods *******/

    bool operator==( Student const& s );

    string to_string() const;

    string to_json();
    ptree ptree_to_json();
    void get_json( string json );

    void ptree_get_json( ptree pt );
private:
    string m_firstName;
    string m_lastName;
    int m_id;
};

std::ostream& operator<<( std::ostream& sortie, Student const &s );

#endif // Student_h
