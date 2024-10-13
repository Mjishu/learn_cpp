#include <iostream>
#include <string>
#include <curl/curl.h>

void callWeather(std::string city)
{
    std::cout << "Your city is: " << city << "\n";
}

void initinalize_curl()
{
    CURL *curl;
    CURLcode res;
    std::string resposneString;

    curl = curl_easy_init() if (cur)
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
    callWeather(city);
    return 0;
}
