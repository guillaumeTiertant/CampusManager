#ifndef TRYCODE_TEMP_H
#define TRYCODE_TEMP_H

#include "campus.h"

#include "student.h"
#include "externalTeacher.h"
#include "internalTeacher.h"
#include "teacher.h"

#include <stdio.h>
#include <string>
#include <vector>
#include <memory>
#include "helper.h"

namespace tryCode {

using namespace std;


//Declaration of Student

Student marvin ( "Marvin", "Gaye", 1 );
Student jean ( "Jean", "Alesi", 2 );
Student louise ( "Louise", "Michel", 3 );
Student pierre ( "Pierre", "Desprosge", 4 );
Student eric ( "Eric", "Clapton", 5 );
Student eric1 ( "Eric", "Clapton", 6 );
Student eric2 ( "Eric", "Clapton" );
Student paul ( "Paul", "Scholes", 7 );
Student olivier ( "Olivier", "Adam", 7 );


//Declaration of Teacher

ExternalTeacher marc ( "Marc", "Weber", 2100, 1 );
ExternalTeacher jeanne ( "Jeanne", "Cheral", 2600, 2 );
ExternalTeacher bill ( "Bill", "Gates", 1800 );

InternalTeacher louis ( "Louis", "Blanc", 3 );
InternalTeacher john ( "John", "Lennon", 4 );
InternalTeacher bertrand ( "Bertrand", "Cantat", 5 );


//Declaration of Campus

Campus montpellier ( "Montpellier", "Herault", 7 );
Campus montpellier1 ( "Montpellier", "Herault" );
Campus paris ( "Paris", "Paris", 2500 );
Campus toulouse ( "Toulouse", "Haute Garonne", 1700 );
Campus montpellier2;


void addStudents()
{
    montpellier.addStudent( marvin );
    montpellier.addStudent( jean );
    montpellier.addStudent( louise );
    montpellier.addStudent( pierre );
    montpellier.addStudent( eric );
    montpellier.addStudent( eric1 );
    montpellier.addStudent( eric2 );
}

void addTeachers()
{
    montpellier.addTeacher( make_shared<ExternalTeacher>( marc ) );
    montpellier.addTeacher( make_shared<ExternalTeacher>( jeanne ) );
    montpellier.addTeacher( make_shared<ExternalTeacher>( bill ) );
    montpellier.addTeacher( make_shared<InternalTeacher>( louis ) );
    montpellier.addTeacher( make_shared<InternalTeacher>( john ) );
    montpellier.addTeacher( make_shared<InternalTeacher>( bertrand ) );
}

void campus()
{
    cout << "Comparaison Campus" << endl;

    if ( montpellier == montpellier1 )
        cout << "Les campus sont egaux!" << endl;
    else
        cout << "Les campus ne sont pas egaux!" << endl;

    if ( paris == toulouse )
        cout << "Les campus sont egaux!" << endl;
    else
        cout << "Les campus ne sont pas egaux!" << endl;

    cout << "***********************************************" << endl;
    cout << "***********************************************" << endl << endl;
}

void student()
{
    cout << "Comparaison Etudiants" << endl;

    if ( eric == eric1 )
        cout << "Les etudiants sont egaux!" << endl;
    else
        cout << "Les etudiants ne sont pas egaux!" << endl;

    if ( eric == eric2 )
        cout << "Les etudiants sont egaux!" << endl;
    else
        cout << "Les etudiants ne sont pas egaux!" << endl;

    if ( eric1 == eric2 )
        cout << "Les etudiants sont egaux!" << endl;
    else
        cout << "Les etudiants ne sont pas egaux!" << endl;

    if ( olivier == paul )
        cout << "Les etudiants sont egaux!" << endl;
    else
        cout << "Les etudiants ne sont pas egaux!" << endl;

    cout << "***********************************************" << endl;
    cout << "***********************************************" << endl << endl;
    cout << "Liste des etudiants triée" << endl;

    montpellier.displayStudents();

    montpellier.removeStudent( marvin );
    montpellier.removeStudent( jean );
    montpellier.removeStudent( louise );
    montpellier.removeStudent( pierre );
    montpellier.removeStudent( eric );

    cout << "***********************************************" << endl;
    cout << "***********************************************" << endl << endl;
    cout << "Liste des etudiants apres suppression via removeStudent" << endl;

    montpellier.displayStudents();

    cout << "***********************************************" << endl;
    cout << "***********************************************" << endl << endl;
}

void teacher()
{
    cout << "Liste des professeurs" << endl;

    montpellier.displayTeachers();

    montpellier.removeTeacher( make_shared<ExternalTeacher>( marc ) );
    montpellier.removeTeacher( make_shared<InternalTeacher>( john ) );
    montpellier.removeTeacher( make_shared<InternalTeacher>( bertrand ) );


    cout << "***********************************************" << endl;
    cout << "***********************************************" << endl << endl;
    cout << "Liste des professeurs apres suppression via removeTeacher" << endl;

    montpellier.displayTeachers();

    cout << "***********************************************" << endl;
    cout << "***********************************************" << endl << endl;
}

void json()
{
    cout << "Save et Load JSON" << endl << endl;

    cout << "Affichage des etudiants et professeurs du campus de Montpellier" << endl;

    montpellier.displayStudents();
    cout << endl;
    montpellier.displayTeachers();
    cout << montpellier.to_json();

    Helper::saveJson_File( "json_campus.json",  montpellier.to_json() );
    Helper::loadJson_File( "json_campus.json" );
    montpellier2.get_json( Helper::loadJson_File( "json_campus.json" ) );

    cout << "Affichage des etudiants et professeurs copies dans le campus Montpellier 2 a partir d'un export JSON" << endl;

    montpellier2.displayStudents();
    cout << endl;
    montpellier2.displayTeachers();
}

}

#endif // TRYCODE_TEMP_H
