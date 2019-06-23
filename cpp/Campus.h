#ifndef Campus_h
#define Campus_h

#include <string>
#include <vector>
#include <memory>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "teacher.h"
#include "student.h"


using std::string;
using std::vector;
using std::shared_ptr;

template <typename T>
using vect_ptr = vector<shared_ptr<T>>;


class Teacher;

class Campus
{

public:
    /******* constructors - destructors *******/

    Campus();
    Campus( string state, string city, int capacity = 0 );

    ~Campus();


    /******* methods *******/

    void addStudent( Student s );
    void removeStudent( Student rs );
    const vect_ptr< Student > getStudents();

    void addTeacher( shared_ptr< Teacher > t );
    void removeTeacher( shared_ptr< Teacher > t );
    const vect_ptr< Teacher > getTeachers() const;

    void displayStudents();
    void displayTeachers();

    bool operator==(Campus const& b);

    /******* getters - setters *******/

    string getState() const;
    void setState( const string &state );

    string getCity() const;
    void setCity( const string &city );

    int getCapacity() const;
    void setCapacity( int capacity );


    /******* JSON *******/

    void get_json( string json );
    string to_json();
    void get_json_students( ptree pt );
    void get_json_teachers( ptree pt );


    template<class T>
    void vect_JSONIFY( string key, const vect_ptr<T> &list, ptree &pt );

    template<class T>
    void get_json_vector( string key, vect_ptr<T> &list, ptree pt );

private:
    string m_state;
    string m_city;
    int m_capacity;
    vect_ptr< Student > m_studentsList;
    vect_ptr< Teacher > m_teachersList;
};

#endif // Campus_h
