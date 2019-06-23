#include "helper.h"

#include <iostream>
#include <fstream>

using namespace std;


void Helper::saveJson_File( const std::string& file, string json )
{
    ofstream fichier( file, ios::out | ios::trunc );

    if ( fichier )
    {
        fichier << json;
        fichier.close();
    }
    else
    {
        cerr << "Fichier inexistant ou non lisible.\n";
    }

    return;
}

string Helper::loadJson_File( const string &file )
{
    string json;
    string ligne;
    ifstream fichier( file, ios::in );

    if( fichier )
    {
        while( getline(fichier, ligne))
        {
            json += ligne;
        }

        fichier.close();
    }

    else
    {
        cerr << "Erreur à l'ouverture !" << endl;
    }

    return json;
}
