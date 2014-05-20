#include "curl_data.h"

size_t MyCurl::write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

void MyCurl::get_file()
{
  CURL* easyhandle = curl_easy_init();

  FILE* file = fopen("tecaj.xml", "w");

  curl_easy_setopt( easyhandle, CURLOPT_URL, "http://www.pbz.hr/Downloads/HNBteclist.xml" ) ;
  //curl_easy_setopt(easyhandle, CURLOPT_FOLLOWLOCATION, 1L);

  curl_easy_setopt(easyhandle, CURLOPT_WRITEFUNCTION, write_data);

  curl_easy_setopt( easyhandle, CURLOPT_WRITEDATA, file) ;

  curl_easy_perform( easyhandle );

  curl_easy_cleanup( easyhandle );

  fclose(file);
}
