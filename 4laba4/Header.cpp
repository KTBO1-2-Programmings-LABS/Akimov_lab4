#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <regex>
#include "pch.h"
#include "Header.h"

using namespace System;
using namespace System::Collections;

class Website {
public:
    string Url;
    string Protocol;
    string Domain;
    string Path;

    Website(const string& url) : Url(url) {
        ParseUrl();
    }

    void ParseUrl() {
        regex url_regex(R"((http|https)://([^/]+)(/?.*))");
        smatch url_match_result;

        if (regex_match(Url, url_match_result, url_regex) && url_match_result.size() == 4) {
            Protocol = url_match_result[1].str();
            Domain = url_match_result[2].str();
            Path = url_match_result[3].str();
        }
        else {
            Protocol = "";
            Domain = "";
            Path = "";
        }
    }

    string GetDomain() const {
        return Domain;
    }

    string GetProtocol() const {
        return Protocol;
    }

    string GetPath() const {
        return Path;
    }
};

// Класс для группировки сайтов
class WebsiteGroup {
public:
    static map<string, vector<Website>> GroupByDomain(const vector<Website>& websites) {
        map<string, vector<Website>> grouped;
        for (const auto& website : websites) {
            grouped[website.GetDomain()].push_back(website);
        }
        return grouped;
    }

    static map<string, vector<Website>> GroupByProtocol(const vector<Website>& websites) {
        map<string, vector<Website>> grouped;
        for (const auto& website : websites) {
            grouped[website.GetProtocol()].push_back(website);
        }
        return grouped;
    }

    static map<string, vector<Website>> GroupByPath(const vector<Website>& websites) {
        map<string, vector<Website>> grouped;
        for (const auto& website : websites) {
            grouped[website.GetPath()].push_back(website);
        }
        return grouped;
    }
};
