#include <bits/stdc++.h>
#include <chrono>

using namespace std;
// Template for a generic Student object
template <typename T>
class Student {
private:
    string id;
    string name;
    double gpa;

public:
    // Constructor
    Student(){};
    Student(string studentId, string studentName, T studentGpa) {
        id = studentId;
        name = studentName;
        gpa = studentGpa;
    }

    bool operator>(const Student<T>& other) const {
        // Sort by name by default
        return name > other.name;
    }
    bool operator<(const Student<T>& other) const {
        // Sort by name by default
        return name < other.name;
    }

    // Friend function for printing
    friend ostream& operator<<(ostream& os, const Student<T>& s) {
        os << "ID: " << s.id << ", Name: " << s.name << ", GPA: " << s.gpa;
        return os;
    }

    string getID() const {
        return id;
    }
    string getName() const {
        return name;
    }
    const double getGPA()const{
        return gpa;
    }
    explicit operator int() const {
        return static_cast<int>(gpa);
    }
};


template <class T>
void insertionSort(vector<Student<T>>& students, bool sortByGPA , int& comparisons) {
    for (int i = 1; i < students.size(); i++) {
        Student<T> key = students[i];
        int j = i - 1;
        while (j >= 0 && ((sortByGPA && students[j].getGPA() < key.getGPA()) || (!sortByGPA && students[j] > key))) {
            students[j + 1] = students[j];
            j = j - 1;
            comparisons++;
        }
        students[j + 1] = key;
    }
}
template <class T>
void BubbleSort(vector<Student<T>> &students , bool sortByGPA , int & comparisons){
    for (int i = 0; i < students.size()-1; ++i) {
        for (int j = 0; j < students.size()-1-i; ++j) {
            if((sortByGPA &&students[j].getGPA() < students[j+1].getGPA()) ||(!sortByGPA &&students[j] > students[j+1]))
                swap(students[j] , students[j+1]);
        }
    }
    // no. of comparision = (n*(n-1))/2
    comparisons = (students.size()*(students.size()-1))/2;
}
template <class T>
void SelectionSort(vector<Student<T>> &students , bool sortByGPA , int & comparisons){
    int i,j,k;
    for ( i = 0; i < students.size()-1 ; ++i) {
        for (j=k=i ; j < students.size(); ++j) {
            if((sortByGPA&& students[j].getGPA() > students[k].getGPA()) || (!sortByGPA &&students[j] < students[k]))
                k=j;
        }
        swap(students[i] ,students[k]);
    }
    // no. of comparision = (n*(n-1))/2
    comparisons = (students.size()*(students.size()-1))/2;
}
template<typename T>
int partition(vector<Student<T>> &students, int left, int right,bool sortByGPA, int &comparisons) {
    int i = left;
    for(int j=left+1;j<=right;j++) {
        // students[j]<students[left]
        if((sortByGPA&& students[j].getGPA() > students[left].getGPA()) || (!sortByGPA &&students[j] < students[left])) {
            i++;
            comparisons++;
            swap(students[j],students[i]);
        }
    }
    swap(students[i],students[left]);
    return i;
}
template<typename T>
void QuickSort(vector<Student<T>> &students,int left, int right, bool sortByGPA, int &comparisons) {
    if(left >= right)
        return;
    int pivot = partition(students,left,right,sortByGPA,comparisons);
    QuickSort(students,left,pivot-1,sortByGPA,comparisons);
    QuickSort(students,pivot+1,right,sortByGPA,comparisons);
}
// void countSort(float a[],float b[],int n) {
//     int max=0;
//     int k;
//     for(int i=1;i<n;i++) {
//         if((int)a[i]>max) {
//             max=(int)a[i];
//             k=max;
//         }
//     }
//     int c[k+1];
//     int cc[k+1];
//     for(int i=1;i<=k;i++) {
//         c[i]=0;
//         cc[i]=0;
//     }
     // for(int j=1;j<=n;j++) {
     //     c[(int)a[j]] ++;
     // }
//     cc[1]=c[1];
//     for(int i=2;i<=k;i++) {
//         cc[i]=c[i]+c[i-1];
//     }
//     for(int i=n;i>0;i--) {
//         b[cc[(int)a[i]]] = a[i];
//         cc[(int)a[i]]--;
//     }
// }
template<typename T>
void CountSort(vector<Student<T>> &students,vector<Student<T>> &result) {
    int max=0;
    int k;
    for(int i=1;i<students.size();i++) {
        if(static_cast<int>(students[i].getGPA())>max) {
            max=static_cast<int>(students[i].getGPA());
            k=max;
        }
    }
    int c[k+1];
    int cc[k+1];
    for(int i=1;i<=k;i++) {
        c[i]=0;
        cc[i]=0;
    }
    for(int j=0;j<students.size();j++) {
        c[static_cast<int>(students[j].getGPA())] ++;
    }
    cc[1]=c[1];
    for(int i=2;i<=k;i++) {
        cc[i]=c[i]+c[i-1];
    }
    for(int i=students.size()-1;i>=0;i--) {
        result[students.size()-cc[static_cast<int>(students[i].getGPA())]] = students[i];
        cc[static_cast<int>(students[i].getGPA())]--;
    }
}
template <typename T>
void print(ostream& os, const vector<T>& students) {
    for (const T& student : students) {
        os << student << endl;
    }
}


int main() {
    // Read student data from file (students.txt)
    ifstream infile("students.txt");
    if (!infile.is_open()) {
        cerr << "Error opening file 'students.txt'" << endl;
        return 1;
    }

    int numStudents;
    infile >> numStudents;
    infile.ignore();

    vector<Student<double>> students;  // Use double for GPA

    for (int i = 0; i < numStudents; ++i) {
        string name, id;
        double gpa;
        getline(infile, name);  // Read entire line for full name
        getline(infile, id);
        infile >> gpa;
        infile.ignore();  // Consume newline character

        students.push_back(Student<double>(id, name, gpa));
    }

    infile.close();

    // Menu for selecting sorting algorithm
    cout << "Select a sorting algorithm:" << endl;
    cout << "1. Insertion Sort" << endl;
    cout << "2. Selection Sort" << endl;
    cout << "3. Bubble Sort" << endl;
    cout << "4. Shell Sort" << endl;
    cout << "5. Merge Sort" << endl;
    cout << "6. Quick Sort" << endl;
    cout << "7. Count Sort" << endl;

    int comparisons = 0;
    int choice;
    cout << "Enter your choice (1-7): ";
    cin >> choice;

    cout << "Sort by:" << endl;
    cout << "1. Name" << endl;
    cout << "2. GPA" << endl;
    cout << "Enter your choice (1-2): ";
    int sortBy;
    cin >> sortBy;
    bool sortByGPA = sortBy == 2;

    switch (choice) {
        case 1: {
            auto start = chrono::high_resolution_clock::now();
            insertionSort(students, sortByGPA, comparisons);
            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

            string fileName = sortByGPA ? "SortedByGPA.txt" : "SortedByName.txt";
            ofstream outputFile(fileName);
            if (!outputFile.is_open()) {
                cerr << "Error opening file '" << fileName << "'" << endl;
                return 1;
            }


            outputFile << "Insertion Sort"<<endl;
            outputFile << "Number of comparisons: " << comparisons << endl;
            outputFile << "Running Time (microseconds): " << duration.count() << endl;
            outputFile << (sortByGPA ? "Students Sorted By GPA:\n" : "Students Sorted By Name:\n");
            print(outputFile, students);
            outputFile.close();
            break;
        }
            // Add cases for other sorting algorithms similarly
        case 2: {
            auto start = chrono::high_resolution_clock::now();
            SelectionSort(students, sortByGPA, comparisons);
            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

            string fileName = sortByGPA ? "SortedByGPA.txt" : "SortedByName.txt";
            ofstream outputFile(fileName);
            if (!outputFile.is_open()) {
                cerr << "Error opening file '" << fileName << "'" << endl;
                return 1;
            }


            outputFile << "Selection Sort"<<endl;
            outputFile << "Number of comparisons: " << comparisons << endl;
            outputFile << "Running Time (microseconds): " << duration.count() << endl;
            outputFile << (sortByGPA ? "Students Sorted By GPA:\n" : "Students Sorted By Name:\n");
            print(outputFile, students);
            outputFile.close();
            break;
        }
        case 3: {
            auto start = chrono::high_resolution_clock::now();
            BubbleSort(students, sortByGPA, comparisons);
            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

            string fileName = sortByGPA ? "SortedByGPA.txt" : "SortedByName.txt";
            ofstream outputFile(fileName);
            if (!outputFile.is_open()) {
                cerr << "Error opening file '" << fileName << "'" << endl;
                return 1;
            }


            outputFile << "Bubble Sort"<<endl;
            outputFile << "Number of comparisons: " << comparisons << endl;
            outputFile << "Running Time (microseconds): " << duration.count() << endl;
            outputFile << (sortByGPA ? "Students Sorted By GPA:\n" : "Students Sorted By Name:\n");
            print(outputFile, students);
            outputFile.close();
            break;
        }
        case 6: {
            auto start = chrono::high_resolution_clock::now();
            QuickSort(students,0,students.size()-1,sortByGPA,comparisons);
            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

            string fileName = sortByGPA ? "SortedByGPA.txt" : "SortedByName.txt";
            ofstream outputFile(fileName);
            if (!outputFile.is_open()) {
                cerr << "Error opening file '" << fileName << "'" << endl;
                return 1;
            }


            outputFile << "Quick Sort"<<endl;
            outputFile << "Number of comparisons: " << comparisons << endl;
            outputFile << "Running Time (microseconds): " << duration.count() << endl;
            outputFile << (sortByGPA ? "Students Sorted By GPA:\n" : "Students Sorted By Name:\n");
            print(outputFile, students);
            outputFile.close();
            break;
        }
        case 7: {
            auto start = chrono::high_resolution_clock::now();
            vector<Student<double>> result(students.size());
            CountSort(students,result);
            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

            string fileName = sortByGPA ? "SortedByGPA.txt" : "SortedByName.txt";
            ofstream outputFile(fileName);
            if (!outputFile.is_open()) {
                cerr << "Error opening file '" << fileName << "'" << endl;
                return 1;
            }


            outputFile << "Count Sort"<<endl;
            outputFile << "Number of comparisons: " << "It's non-comparison algorithm." << endl;
            outputFile << "Running Time (microseconds): " << duration.count() << endl;
            outputFile << (sortByGPA ? "Students Sorted By GPA:\n" : "Students Sorted By Name:\n");
            print(outputFile, result);
            outputFile.close();
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
            break;
    }

    cout << "Student data sorted and written to file successfully!!" << endl;
    return 0;
}