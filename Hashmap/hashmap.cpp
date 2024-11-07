#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{

    // Creation
    unordered_map<string, int> m;

    // Insertion
    pair<string, int> p = make_pair("Scorpio", 9);
    m.insert(p);

    pair<string, int> p2("alto", 11);
    m.insert(p2);

    m["fortuner"] = 10;

    // Access
    cout << m.at("alto") << endl;
    cout << m.at("Scorpio") << endl;

    cout << m["fortuner"] << endl;

    // Search
    cout << m.count("Scorpio") << endl;
}
