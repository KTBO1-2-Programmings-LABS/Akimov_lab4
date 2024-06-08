#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <regex>



using namespace System::Collections;
using namespace System;
using namespace std;


// Класс для представления сайта
class Website {
public:
    string Url;
    string Protocol;
    string Domain;
    string Path;

    Website(const string& url) : Url(url) {
        ParseUrl();
    }

    void ParseUrl();

    string GetDomain() const;

    string GetProtocol() const;

    string GetPath() const;
};

// Класс для группировки сайтов
class WebsiteGroup {
public:
    static map<string, vector<Website>> GroupByDomain(const vector<Website>& websites);

    static map<string, vector<Website>> GroupByProtocol(const vector<Website>& websites);

    static map<string, vector<Website>> GroupByPath(const vector<Website>& websites);
};
