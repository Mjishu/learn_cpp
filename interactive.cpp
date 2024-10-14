#include <iostream>
#include <string>
#include <curl/curl.h>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *out)
{
    size_t totalSize = size * nmemb;
    out->append((char *)contents, totalSize);
    return totalSize;
}

int call_api(std::string &city_name)
{
    CURL *curl;
    CURLcode res;
    std::string resposneString;

    curl = curl_easy_init();
    if (curl)
    {
        std::string response_string;
        std::string header_string;

        std::string url = "http://api.weatherapi.com/v1/current.json?key=bd6ea40dff0c4acc8cc150209242107&q=" + city_name;
        std::cout << "url is " << url;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);

        struct curl_slist *headers = nullptr;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        // headers = curl_slits_append(headers, "Authorization : Bearer ");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
        {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        else
        {
            std::cout << "Response data " << response_string << std::endl;
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
    return 0;
}

int main()
{
    std::string name;
    std::cout << "What is your name\n";
    std::cin >> name;
    std::cout << "Hello " << name << ",\nWould you like to play a game?\nyes(y) or no(n)\n";

    std::string gameBool;
    std::cin >> gameBool;
    if (gameBool == "no" || gameBool == "n")
    {
        std::cout << "See you next time!\n";
        return 0;
    }
    std::string city;
    std::cout << "What city do you live in?\n";
    std::cin >> city;
    call_api(city);
    return 0;
}
