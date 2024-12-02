#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string , int> StudentGrades;

    StudentGrades["Omar"] = 100;
    StudentGrades["Mohamed"] = 98;
    StudentGrades["Ahmed"] = 44;

    cout << "Map values: " << endl;
    for (const auto &pair: StudentGrades)
    {
        cout << "Student: " << pair.first << " , Grade " << pair.second << endl;
    }

}
