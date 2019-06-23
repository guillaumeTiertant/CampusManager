#include "iostream"
#include <algorithm>

#include "campus.h"
#include "internalTeacher.h"
#include "externalTeacher.h"
#include "fullCampusException.h"


using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;
using namespace std;


/*******************************************************
 *********** CONSTRUCTORS - DESTRUCTORS **************
 *******************************************************/

Campus::Campus()
{}

Campus::Campus( string state, string city, int capacity )
   : m_state( state ), m_city( city ), m_capacity( capacity )
{}

Campus::~Campus()
{}

/*******************************************************
 ***************** GETTERS - SETTERS *******************
 *******************************************************/

string Campus::getState() const
{
   return m_state;
}

void Campus::setState( const string &state )
{
   m_state = state;
}

string Campus::getCity() const
{
   return m_city;
}

void Campus::setCity( const string &city )
{
   m_city = city;
}

int Campus::getCapacity() const
{
   return m_capacity;
}

void Campus::setCapacity( int capacity )
{
   m_capacity = capacity;
}

const vect_ptr<Teacher> Campus::getTeachers() const
{
   return m_teachersList;
}

const vect_ptr<Student> Campus::getStudents()
{
   sort( m_studentsList.begin(), m_studentsList.end(),
         [](const shared_ptr<Student> a, const shared_ptr<Student> b){ return a->getId() < b->getId(); } );

   return m_studentsList;
}

/*******************************************************
 ********************** METHODS ************************
 *******************************************************/

/*********** STUDENTS ***********/

void Campus::addStudent( Student s )
{
   auto student = make_shared<Student>( s );
   if  ( m_capacity > (int)m_studentsList.size() || m_capacity == 0 )
      m_studentsList.push_back( student );

   else
      throw FullCampusException();
}

void Campus::removeStudent( Student rs )
{
   m_studentsList.erase(
            remove_if( begin( m_studentsList ), end( m_studentsList ),
                       [=]( shared_ptr<Student> a){ return *a == rs; }),
            end( m_studentsList ) );
}

void Campus::displayStudents()
{
   getStudents();

   for( auto s : m_studentsList )
   {
      cout << *s << endl;
   }
}


/*********** TEACHERS ***********/

void Campus::addTeacher( shared_ptr<Teacher> t )
{
   if( typeid( *t ) == typeid( InternalTeacher ) )
   {
      auto it = dynamic_pointer_cast<InternalTeacher>( t );
      m_teachersList.push_back( std::make_shared<InternalTeacher>( *it ) );
   }
   else if( typeid( *t ) == typeid( ExternalTeacher ) )
   {
      auto et = dynamic_pointer_cast<ExternalTeacher>( t );
      m_teachersList.push_back( make_shared<ExternalTeacher>( *et ) );
   }
}

void Campus::removeTeacher( shared_ptr<Teacher> t )
{
   m_teachersList.erase(
            remove_if( begin( m_teachersList ), end( m_teachersList ),
                       [=]( shared_ptr<Teacher> a ){ return *a == *t; }),
            m_teachersList.end() );
}

void Campus::displayTeachers()
{
   getTeachers();

   for( shared_ptr<Teacher> t : m_teachersList )
   {
      cout << *t << endl;
   }
}

/*******************************************************
 **************** OPERATORS OVERLOADING ****************
 *******************************************************/

bool Campus::operator==( const Campus &b )
{
   return ( m_state == b.m_state && m_city == b.m_city );
}

/*******************************************************
 *********************** JSON **************************
 *******************************************************/

string Campus::to_json()
{
   ptree pt;

   pt.put( "state", m_state );
   pt.put( "city", m_city );
   pt.put( "capacity", m_capacity );

   vect_JSONIFY<Student>( "studentsList", m_studentsList, pt );
   vect_JSONIFY<Teacher>( "teachersList", m_teachersList, pt );

   ostringstream oss;
   write_json ( oss, pt, true /*(default: 1)*/ );
   return oss.str();

}


void Campus::get_json( string json )
{
   ptree pt;
   istringstream is ( json );

   read_json ( is, pt );

   m_state     = pt.get<string> ( "state" );
   m_city      = pt.get<string> ( "city" );
   m_capacity  = pt.get<int>    ( "capacity" );

   get_json_vector<Student>( "studentsList", m_studentsList, pt );
   get_json_vector<Teacher>( "teachersList", m_teachersList, pt );

}


template<class T>
void Campus::vect_JSONIFY( string key, const vect_ptr< T > &list, ptree &pt )
{
/*
    By creating a tree "A" containing empty keys
and inserting the tree "A" in another tree,
"A" automatically becomes a JSON array [].
*/
   ptree array;

   for ( shared_ptr<T> t : list )
   {
      array.push_back( make_pair( "", t->ptree_to_json() ) );
   }

   pt.push_back( make_pair( key, array) );
}

template<typename T>
void Campus::get_json_vector( string key, vect_ptr< T > &list, ptree pt )
{
   ptree ptList = pt.get_child( key );

   list.clear();

   for ( auto T_ptElement : ptList )
   {
      ptree pt_T;

      pt_T.push_back( T_ptElement );
      pt_T = pt_T.get_child( "." );
      boost::optional<string> typeDef = pt_T.get_optional<string>( "type" );

      string currentType;

      if ( typeDef )
         currentType = typeDef.get();

      else
         currentType = "NULL";


      if ( currentType == "external" )
         m_teachersList.push_back( make_shared<ExternalTeacher>() );

      else if ( currentType == "internal"  )
         m_teachersList.push_back( make_shared<InternalTeacher>() );

      else
         m_studentsList.push_back( make_shared<Student>() );

      list.back()->ptree_get_json( pt_T );
   }
}



