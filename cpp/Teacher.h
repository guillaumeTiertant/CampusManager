#ifndef Teacher_h
#define Teacher_h

#include <string>

#include "campus.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>


using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

using std::string;


class Teacher
{

public:
    /******* constructeurs - destructeurs *******/

    Teacher();
    Teacher( string firstName, string lastName, int id = 0 );

    virtual ~Teacher(){}


    /******* getters - setters *******/

    int getId() const;
    void setId( const int id );

    virtual int getWage() const = 0;
    virtual void setWage( const int wage ) = 0;

    string getFirstName() const;
    void setFirstName( const string &firstName );

    string getLastName() const;
    void setLastName( const string &lastName );

    bool operator==( Teacher const& s );

    string to_string() const;


    /******* JSON *******/

    void get_json( string json );
    void ptree_get_json( boost::property_tree::ptree pt );
    virtual ptree ptree_to_json() = 0;
    virtual string to_json() = 0;


protected:
    string m_firstName;
    string m_lastName;
    int m_id;
};

std::ostream& operator<<( std::ostream& sortie, Teacher const &s );

#endif // Teacher_h
