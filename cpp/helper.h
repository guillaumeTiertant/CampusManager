#ifndef HELPER_H
#define HELPER_H

#include <string>

using std::string;

class Helper
{

public:
    static string loadJson_File( const string &file );
    static void saveJson_File( const string &file, string json );
};

#endif // HELPER_H
