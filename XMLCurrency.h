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

    double EurUsa();
    double EurSui();
    double EurHr();

    double UsaSui();
    double UsaHr();

    double SuiHr();
    static std::string date;
private:
    double euro;
    double dollar;
    double kuna;
    double franc;



    double StringToDouble(std::string);

};

#endif // XMLCURRENCY_H
