#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minTimeDifference(vector<string> time)
{
    // cooonverting time string to integer
    vector<int> minutes;
    for (int i = 0; i < time.size(); i++)
    {
        string current = time[i];
        int hours = stoi(current.substr(0, 2));
        int min = stoi(current.substr(3, 2));
        int totalMinutes = hours * 60 + min;
        minutes.push_back(totalMinutes);
    }
    // sort minutes integer
    sort(minutes.begin(), minutes.end());

    // difference and calculate min diff
    int mini = INT16_MAX;
    for (int i = 1; i < minutes.size(); i++)
    {
        int diff = minutes[i] - minutes[i - 1];
        mini = min(mini, diff);
    }
    // we didnt compare last to first
    int lastDiff = (minutes[0] + 1440) - minutes.back();
    mini = min(mini, lastDiff);
    cout << mini;
}

int main()
{
    int n;
    cout << "Enter number of inputs you wanna give:-";
    vector<string> time(n);
    cout << "Enter the times in HH:MM format:";
    for (int i = 0; i < n; i++)
    {
        cin >> time[i];
    }
    int result = minTimeDifference(time);
    cout << "Minimun time difference: " << result << " minitues " << endl;
    return 0;
}