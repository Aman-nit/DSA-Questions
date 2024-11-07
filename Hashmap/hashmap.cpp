// UNORDER MAP ->o(1)
// ORDER MAP ->o(logn)

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
    if (m.find("fortuner") != m.end())
    {
        cout << "Fortuner found." << endl;
    }
    else
    {
        cout << "Fortuner not found " << endl;
    }
    cout << m.size() << endl;
    cout << m["Hammer"] << endl;
    cout << m.size() << endl;

    cout << "Printing all entries... " << endl;

    for (auto i : m)
    {
        cout << i.first << " --> " << i.second << endl;
    }

    return 0;
}
