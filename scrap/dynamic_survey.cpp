#include <iostream>
#include <vector>

#include "utils.cpp"

using std::cin;
using std::cout;
using std::vector;

int main(int argc, char const *argv[])
{
    // vector<int> surveyData;
    // surveyData.reserve(30);

    cout << "Enter next survey response or -1 to end: ";
    int surveyResponse;
    cin >> surveyResponse;

    // add one more element to avoid subtracting one when
    const int MAX_RESPONSE = 11;
    int histogram[MAX_RESPONSE] = {0};

    while (surveyResponse != -1) {
        ++histogram[surveyResponse];
        cout << "Enter next survey response or -1 to end: ";
        cin >> surveyResponse;
    }

    int mostResponse = histogram[0];
    int mostUsed = 0;
    for (int i = 0; i < MAX_RESPONSE; ++i) {
        if (histogram[i] > mostResponse) {
            mostResponse = histogram[i];
            mostUsed = i;
        }
    }

    cout << "The most given response is " << mostUsed << " with "
         << mostResponse << " instances of use.\n";
}
