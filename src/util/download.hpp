#pragma once
#include <curl_easy.h>
#include <curl_ios.h>
#include <curl_exception.h>
#include <fstream>
#include <iostream>
#include <ostream>

using namespace curl;
using namespace std;

namespace cppitch::download
{
    inline void file(const char* file_url, const char* location)
    {
        ofstream file;
        file.open(location);

        curl_ios<ostream> writer(file);
        curl_easy easy(writer);

        easy.add<CURLOPT_URL>(file_url);
        easy.add<CURLOPT_FOLLOWLOCATION>(1L);

        try
        {
            easy.perform();
        }
        catch(curl_easy_exception& e)
        {
            std::cerr << e.what() << '\n';

            e.print_traceback();
        }

        file.close();
    }
}