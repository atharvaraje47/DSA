#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Student
{
    int id;
    char name[50];
    float cgpa;
};

int main()
{
    Student *s = NULL;
    int n, i, key;

    cout << "Enter number of students: ";
    cin >> n;

    s = (Student*)malloc(n * sizeof(Student));

    for(i = 0; i < n; i++)
    {
        cout << "\nEnter ID, Name and CGPA: ";
        cin >> s[i].id >> s[i].name >> s[i].cgpa;
    }

    // Linear Search
    cout << "\nEnter ID to search: ";
    cin >> key;

    int found = 0;

    for(i = 0; i < n; i++)
    {
        if(s[i].id == key)
        {
            cout << "Student Found (Linear Search)";
            cout << "\nName: " << s[i].name;
            cout << "\nCGPA: " << s[i].cgpa;
            found = 1;
            break;
        }
    }

    if(!found)
        cout << "Student Not Found";

    // Expand memory using realloc()
    s = (Student*)realloc(s, (n + 1) * sizeof(Student));

    cout << "\n\nEnter New Student ID, Name and CGPA: ";
    cin >> s[n].id >> s[n].name >> s[n].cgpa;
    n++;

    // Sort students by ID
    for(i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(s[j].id > s[j+1].id)
            {
                Student temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }

    // Binary Search
    int low = 0, high = n - 1, mid;
    found = 0;

    cout << "\nEnter ID for Binary Search: ";
    cin >> key;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(s[mid].id == key)
        {
            cout << "Student Found (Binary Search)";
            cout << "\nName: " << s[mid].name;
            cout << "\nCGPA: " << s[mid].cgpa;
            found = 1;
            break;
        }
        else if(s[mid].id < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if(!found)
        cout << "Student Not Found";

    free(s);

    return 0;
}
