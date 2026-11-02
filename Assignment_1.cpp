#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
// Structure to store student details
struct Student {
   int id;
   char name[30];
   float cgpa;
};
// Function to add a new student record using realloc()
Student* addStudent(Student *s, int *n, int id, const char *name, float 
cgpa) {
   int newSize = (*n) + 1;
   s = (Student*)realloc(s, newSize * sizeof(Student));
   s[*n].id = id;
   strcpy(s[*n].name, name);
   s[*n].cgpa = cgpa;
   *n = newSize;
   return s;
}
// Function to display all student records
void displayStudents(Student *s, int n) {
   for (int i = 0; i < n; i++) {
       cout << s[i].id << "  " << s[i].name << "  " << s[i].cgpa << 
endl;
   }
}
// Linear Search to find student record by ID
void linearSearch(Student *s, int n, int keyId) {
   int comparisons = 0;
   for (int i = 0; i < n; i++) {
       comparisons++;
       if (s[i].id == keyId) {
           cout << "Linear Search: Found " << s[i].name << " in " << 
comparisons << " comparisons" << endl;
           return;
       }

   }
   cout << "Linear Search: ID " << keyId << " not found" << endl;
}
// Binary Search to find student record by ID (requires sorted ID array)
void binarySearch(Student *s, int n, int keyId) {
   int low = 0;
   int high = n - 1;
   int comparisons = 0;
   while (low <= high) {
       comparisons++;
       int mid = (low + high) / 2;
       if (s[mid].id == keyId) {
           cout << "Binary Search: Found " << s[mid].name << " in " << 
comparisons << " comparisons" << endl;
           return;
       }
       else if (s[mid].id < keyId) low = mid + 1;
       else high = mid - 1;
   }
   cout << "Binary Search: ID " << keyId << " not found" << endl;
}
// Bubble Sort to sort student records by Name alphabetically
void bubbleSortByName(Student *s, int n) {
   for (int i = 0; i < n - 1; i++) {
       for (int j = 0; j < n - i - 1; j++) {
           if (strcmp(s[j].name, s[j + 1].name) > 0)
               swap(s[j], s[j + 1]);
       }
   }
}
// Selection Sort to sort student records by CGPA in descending order
void selectionSortByCGPA(Student *s, int n) {
   for (int i = 0; i < n - 1; i++) {
       int maxIdx = i;
       for (int j = i + 1; j < n; j++)
           if (s[j].cgpa > s[maxIdx].cgpa) maxIdx = j;
       swap(s[i], s[maxIdx]);
   }
}

// Sort student records by ID in ascending order for Binary Search
void sortByID(Student *s, int n) {
   for (int i = 0; i < n - 1; i++) {
       for (int j = 0; j < n - i - 1; j++) {
           if (s[j].id > s[j + 1].id) swap(s[j], s[j + 1]);
       }
   }
}
int main() {
   int n = 0;
   Student *s = (Student*)malloc(sizeof(Student));
   // Add student records dynamically using realloc()
   s = addStudent(s, &n, 105, "Rohan", 8.5);
   s = addStudent(s, &n, 102, "Aarav", 9.4);
   s = addStudent(s, &n, 108, "Sneha", 8.9);
   s = addStudent(s, &n, 101, "Priya", 9.1);
   s = addStudent(s, &n, 103, "Neha", 9.6);
   cout << "Initial Student Database:" << endl;
   displayStudents(s, n);
   cout << "\nSearch Before Sorting (ID 103):" << endl;
   linearSearch(s, n, 103);
   bubbleSortByName(s, n);
   cout << "\nSorted by Name Alphabetically (Bubble Sort):" << endl;
   displayStudents(s, n);
   selectionSortByCGPA(s, n);
   cout << "\nSorted by CGPA Descending (Selection Sort):" << endl;
   displayStudents(s, n);
   sortByID(s, n);
   cout << "\nSearch After Sorting by ID (ID 103):" << endl;
   linearSearch(s, n, 103);
   binarySearch(s, n, 103);
   free(s);
   return 0;
}
