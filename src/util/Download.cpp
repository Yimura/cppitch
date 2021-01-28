#include "Download.hpp"
#include <curl_easy.h>
#include <curl_ios.h>
#include <curl_exception.h>
#include <fstream>
#include <iostream>
#include <ostream>

using namespace curl;
using namespace std;

Download::Download(/* args */)
{
}

Download::~Download()
{
}

void Download::download_file()
{
    ofstream file;
    file.open("./sending.cc");

    curl_ios<ostream> writer(file);
    curl_easy easy(writer);

    easy.add<CURLOPT_URL>("https://raw.githubusercontent.com/ultravideo/uvgRTP/master/examples/sending.cc");
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