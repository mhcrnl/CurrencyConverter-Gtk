#ifndef XMLCURRENCY_H
#define XMLCURRENCY_H

#include "tinyxml.h"
#include <string>
#include <sstream>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <locale>
#include <iostream>


class Currency
{
public:
    Currency()
    {

        initialize();

    }
    ~Currency()
    {

    }

    void initialize();
    
    static double EurUsa();
    static double EurSui();
    static double EurHr();

    static double UsaSui();
    static double UsaHr();

    static double SuiHr();

    const char* getDate();

private:
    static  double euro;
    static  double dollar;
    static  double kuna;
    static  double franc;

    std::string date;



    double StringToDouble(std::string);

};

#endif // XMLCURRENCY_H
