#include <iostream>
#include <fstream>
#include <cctype>

const std::string WHITESPACE = " \n\r\t\f\v";

using namespace std;

std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string &s)
{
    return rtrim(ltrim(s));
}

void movingAvg(int n, float *arr)
{
    for (int i = n - 1; i > 1; i--)
    {
        arr[i] = (arr[i] + arr[i - 1] + arr[i - 2]) / n;
    }
    arr[1] = (arr[1] + arr[0]) / 2;
    arr[0] = arr[0] / n;
}

void printArray(float *arr, int n)
{
    for (int i = 0; i < n;)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    ifstream csv;
    float arr[140];
    int i = 0;

    csv.open("nifty.csv");

    while (csv.good())
    {
        string line, line2;
        getline(csv, line, ',');

        cout << trim(line) << endl;

        // if (isdigit(line[0]))
        // {
        //     arr[i++] = stof(line);
        // }
    }

    movingAvg(3, arr);
    printArray(arr, i);
    movingAvg(5, arr);
    printArray(arr, i);

    csv.close();
}