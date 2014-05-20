#include "XMLCurrency.h"
#include "curl_data.h"
using namespace std;
string Currency::date="";

void Currency::initialize()
{
    MyCurl::get_file();
    date = "Date: ";
    kuna = 1.0;
    TiXmlDocument doc;
    const char* attr;
	if(!doc.LoadFile("tecaj.xml"))
	{
		std::cerr << doc.ErrorDesc() << endl;
		return;
	}

	TiXmlElement* root = doc.FirstChildElement();
	if(root == NULL)
	{
		cerr << "Failed to load file: No root element." << endl;
		doc.Clear();
		return ;
	}

	for(TiXmlElement* elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement())
	{
		string elemName = elem->Value();


		 if(elemName == "ExchRate")
		{


			for(TiXmlElement* e = elem->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
			{
			    string name=e->Value();
			    if(name=="Bank")
                {

                //cout << "Banka: " << e->GetText() << endl;
                }
                else if(name=="CurrencyBase")
                {

                //cout << "Valuta: " << e->GetText() << endl;

                }
                else if(name=="Date")
                {

                date=date + e->GetText();

                //cout << "Datum: " <<date << endl;

                }
                else if(name=="Currency")
                {

                attr = e->Attribute("Code");

                //is it franc;
                if(strcmp(attr,"756")==0)
                {

                 for(TiXmlElement* el = e->FirstChildElement(); el != NULL; el=el->NextSiblingElement())
                 {
                     string data = el->Value();

                     if(data=="MeanRate")
                     {
                         string value=el->GetText();
                         franc = StringToDouble(value);
                     }
                 }
                 }
                 //is it dollar
                if(strcmp(attr,"840")==0)
                {

                 for(TiXmlElement* el = e->FirstChildElement(); el != NULL; el=el->NextSiblingElement())
                 {
                     string data = el->Value();

                     if(data=="MeanRate")
                     {
                         string value=el->GetText();
                         dollar = StringToDouble(value);
                     }
                 }
                 }
                 //is it euro
                if(strcmp(attr,"978")==0)
                {

                 for(TiXmlElement* el = e->FirstChildElement(); el != NULL; el=el->NextSiblingElement())
                 {
                     string data = el->Value();

                     if(data=="MeanRate")
                     {
                         string value=el->GetText();
                         euro = StringToDouble(value);
                     }
                 }
                 }

                }

			}
		}
	}

    doc.Clear();
}

double Currency::StringToDouble(string str)
{
    setlocale(LC_NUMERIC, "Croatian_Croatia.1250"); //to avoid problem with comma in xml file.
    double number;

    const char *s=str.c_str();
    number=atof(s);

    return number;

}

double Currency::EurUsa()
{
    return euro/dollar;
}

double Currency::EurSui()
{
    return euro/franc;
}

double Currency::EurHr()
{
    return euro/kuna;
}

double Currency::UsaHr()
{
    return dollar/kuna;
}

double Currency::UsaSui()
{
    return dollar/franc;
}

double Currency::SuiHr()
{
    return franc/kuna;
}
