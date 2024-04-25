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
void ShellSort(vector<Student<T>>& students, bool sortByGPA, int& comparisons) {
    int n = students.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            Student<T> temp = students[i];
            int k;
            if (sortByGPA) {
                for (k = i; k >= gap && students[k - gap].getGPA() < temp.getGPA(); k -= gap) {
                    students[k] = students[k - gap];
                    comparisons++;
                }
            } else {
                for (k = i; k >= gap && students[k - gap] > temp; k -= gap) {
                    students[k] = students[k - gap];
                    comparisons++;
                }
            }
            students[k] = temp;
        }
    }
}

template<typename T>
void merge(vector<Student<T>>& students, int left, int mid, int right, bool sortByGPA, int& comparisons) {
    int const n1 = mid - left + 1;
    int  const n2 = right - mid;

    vector<Student<T>> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = students[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = students[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if ((sortByGPA && L[i].getGPA() >= R[j].getGPA()) || (!sortByGPA && L[i] < R[j])) {
            students[k] = L[i];
            i++;
        } else {
            students[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        students[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        students[k] = R[j];
        j++;
        k++;
    }
}
template<typename T>
void MergeSort(vector<Student<T>>& students, int left, int right, bool sortByGPA, int& comparisons) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        MergeSort(students, left, mid, sortByGPA, comparisons);
        MergeSort(students, mid + 1, right, sortByGPA, comparisons);
        merge(students, left, mid, right, sortByGPA, comparisons);
        comparisons+=(mid-left+1);
    }
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
/* void countSort(float a[],float b[],int n) {
     int max=0;
     int k;
     for(int i=1;i<n;i++) {
         if((int)a[i]>max) {
             max=(int)a[i];
             k=max;
         }
     }
     int c[k+1];
     int cc[k+1];
     for(int i=1;i<=k;i++) {
         c[i]=0;
         cc[i]=0;
     }
 for(int j=1;j<=n;j++) {
     c[(int)a[j]] ++;
 }
     cc[1]=c[1];
     for(int i=2;i<=k;i++) {
         cc[i]=c[i]+c[i-1];
     }
     for(int i=n;i>0;i--) {
         b[cc[(int)a[i]]] = a[i];
         cc[(int)a[i]]--;
     }
 }*/
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

    int comparisons=0;
    auto start = chrono::steady_clock::now();
    insertionSort(students, false, comparisons);
    auto stop = chrono::steady_clock::now();
    auto diff =stop - start;

    string fileName =  "SortedByName.txt";
    ofstream outputFile(fileName,ios::app);
    if (!outputFile.is_open()) {
        cerr << "Error opening file '" << fileName << "'" << endl;
        return 1;
    }
    outputFile << "\nInsertion Sort"<<endl;
    outputFile << "Number of comparisons: " << comparisons << endl;
    outputFile << "Running Time (milliseconds): "  << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    outputFile << "Students Sorted By Name:\n";
    print(outputFile, students);
    // outputFile.close();
    //sort by gpa
    comparisons=0;
    start = chrono::steady_clock::now();
    insertionSort(students, true, comparisons);
    stop = chrono::steady_clock::now();
    diff =stop - start;

    fileName =  "SortedByGPA.txt";
    ofstream outputFile2(fileName,ios::app);
    if (!outputFile2.is_open()) {
        cerr << "Error opening file '" << fileName << "'" << endl;
        return 1;
    }
    outputFile2 << "\nInsertion Sort"<<endl;
    outputFile2 << "Number of comparisons: " << comparisons << endl;
    outputFile2 << "Running Time (milliseconds): " << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    outputFile2 << "Students Sorted By Name:\n";
    print(outputFile2, students);

    //selection sort
    comparisons=0;
    start = chrono::steady_clock::now();
    SelectionSort(students, false, comparisons);
    stop = chrono::steady_clock::now();
    diff = stop - start;
    outputFile << "\nSelection Sort"<<endl;
    outputFile << "Number of comparisons: " << comparisons << endl;
    outputFile << "Running Time (milliseconds): " << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    outputFile << "Students Sorted By Name:\n";
    print(outputFile, students);
    // outputFile.close();
    //sort by gpa
    comparisons=0;
    start = chrono::steady_clock::now();
    SelectionSort(students, true, comparisons);
    stop = chrono::steady_clock::now();
    diff = stop - start;

    outputFile2 << "\nSelection Sort"<<endl;
    outputFile2 << "Number of comparisons: " << comparisons << endl;
    outputFile2 << "Running Time (milliseconds): " << chrono::duration<double, milli>(diff).count() << " ms"  << endl;
    outputFile2 << "Students Sorted By Name:\n";
    print(outputFile2, students);

    //bubble sort
    comparisons=0;
    start = chrono::steady_clock::now();
    BubbleSort(students, false, comparisons);
    stop = chrono::steady_clock::now();
    diff = stop - start;
    outputFile << "\nBubble Sort"<<endl;
    outputFile << "Number of comparisons: " << comparisons << endl;
    outputFile << "Running Time (milliseconds): " << chrono::duration<double, milli>(diff).count() << " ms"  << endl;
    outputFile << "Students Sorted By Name:\n";
    print(outputFile, students);

    //sort by gpa
    comparisons=0;
    start = chrono::steady_clock::now();
    BubbleSort(students, true, comparisons);
    stop = chrono::steady_clock::now();
    diff = stop - start;

    outputFile2 << "\nBubble Sort"<<endl;
    outputFile2 << "Number of comparisons: " << comparisons << endl;
    outputFile2 << "Running Time (milliseconds): " << chrono::duration<double, milli>(diff).count() << " ms"  << endl;
    outputFile2 << "Students Sorted By Name:\n";
    print(outputFile2, students);
    //shell sort
    comparisons=0;
    start = chrono::steady_clock::now();
    ShellSort(students, false, comparisons);
    stop = chrono::steady_clock::now();
    diff = stop - start;
    outputFile << "\nShell Sort"<<endl;
    outputFile << "Number of comparisons: " << comparisons << endl;
    outputFile << "Running Time (milliseconds): " << chrono::duration<double, milli>(diff).count() << " ms"  << endl;
    outputFile << "Students Sorted By Name:\n";
    print(outputFile, students);
    //sort by gpa
    comparisons=0;
    start = chrono::steady_clock::now();
    ShellSort(students, true, comparisons);
    stop = chrono::steady_clock::now();
    diff = stop - start;

    outputFile2 << "\nShell Sort"<<endl;
    outputFile2 << "Number of comparisons: " << comparisons << endl;
    outputFile2 << "Running Time (milliseconds): " << chrono::duration<double, milli>(diff).count() << " ms"  << endl;
    outputFile2 << "Students Sorted By Name:\n";
    print(outputFile2, students);

    //merge sort
    comparisons=0;
    start = chrono::steady_clock::now();
    MergeSort(students, 0, students.size() - 1, false, comparisons);
    stop = chrono::steady_clock::now();
    diff = stop - start;
    outputFile << "\nMerge Sort"<<endl;
    outputFile << "Number of comparisons: " << comparisons << endl;
    outputFile << "Running Time (milliseconds): " << chrono::duration<double, milli>(diff).count() << " ms"  << endl;
    outputFile << "Students Sorted By Name:\n";
    print(outputFile, students);
    //sort by gpa
    comparisons=0;
    start = chrono::steady_clock::now();
    MergeSort(students, 0, students.size() - 1, true, comparisons);
    stop = chrono::steady_clock::now();
    diff = stop - start;

    outputFile2 << "\nMerge Sort"<<endl;
    outputFile2 << "Number of comparisons: " << comparisons << endl;
    outputFile2 << "Running Time (milliseconds): " << chrono::duration<double, milli>(diff).count() << " ms"  << endl;
    outputFile2 << "Students Sorted By Name:\n";
    print(outputFile2, students);

    //quick sort
    comparisons=0;
    start = chrono::steady_clock::now();
    QuickSort(students,0,students.size()-1,false,comparisons);
    stop = chrono::steady_clock::now();
    diff = stop - start;
    outputFile << "\nQuick Sort"<<endl;
    outputFile << "Number of comparisons: " << comparisons << endl;
    outputFile << "Running Time (milliseconds): " << chrono::duration<double, milli>(diff).count() << " ms"  << endl;
    outputFile << "Students Sorted By Name:\n";
    print(outputFile, students);
    //sort by gpa
    comparisons=0;
    start = chrono::steady_clock::now();
    QuickSort(students,0,students.size()-1,true,comparisons);
    stop = chrono::steady_clock::now();
    diff = stop - start;

    outputFile2 << "\nQuick Sort"<<endl;
    outputFile2 << "Number of comparisons: " << comparisons << endl;
    outputFile2 << "Running Time (milliseconds): " << chrono::duration<double, milli>(diff).count() << " ms"  << endl;
    outputFile2 << "Students Sorted By Name:\n";
    print(outputFile2, students);

    //count sort
    comparisons=0;
    start = chrono::steady_clock::now();
    vector<Student<double>> result(students.size());
    CountSort(students,result);
    stop = chrono::steady_clock::now();
    diff = stop - start;

    outputFile2 << "\nCount Sort"<<endl;
    outputFile2 << "Number of comparisons: " << comparisons << endl;
    outputFile2 << "Running Time (milliseconds): " << chrono::duration<double, milli>(diff).count() << " ms"  << endl;
    outputFile2 << "Students Sorted By Name:\n";
    print(outputFile2, students);
    cout << "Student data sorted and written to file successfully!!" << endl;
}

