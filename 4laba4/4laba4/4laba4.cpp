#include "pch.h"
#include "Header.h"

int main() {
    setlocale(LC_ALL, "Russian");

    vector<Website> websites = {
        Website("https://example.com"),
        Website("https://example.com/about"),
        Website("http://example.net"),
        Website("https://example.net/contact"),
        Website("https://blog.example.com"),
        Website("https://shop.example.com"),
        Website("http://another-example.com"),
        Website("https://another-example.com/products"),
        Website("https://another-example.com/services")
    };

    cout << "Выберите критерий группировки:" << endl;
    cout << "1. По домену" << endl;
    cout << "2. По протоколу" << endl;
    cout << "3. По пути" << endl;

    int choice;
    cin >> choice;

    map<string, vector<Website>> groupedWebsites;

    switch (choice) {
    case 1:
        groupedWebsites = WebsiteGroup::GroupByDomain(websites);
        break;
    case 2:
        groupedWebsites = WebsiteGroup::GroupByProtocol(websites);
        break;
    case 3:
        groupedWebsites = WebsiteGroup::GroupByPath(websites);
        break;
    default:
        cout << "Некорректный выбор." << endl;
        main();
    }

    // Вывод результатов
    for (const auto& group : groupedWebsites) {
        cout << "\nКлюч: " << group.first << endl;
        for (const auto& website : group.second) {
            cout << " - " << website.Url << endl;
        }
    }

    return 0;
}