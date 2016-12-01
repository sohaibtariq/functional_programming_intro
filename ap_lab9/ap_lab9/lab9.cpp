#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int solve_linear(int arr[]) {
    int a = arr[1] ;
    int b = arr[2] * (-1);
    
    return b / a;
}

int determinant(int arr[]) {
    int a = arr[0];
    int b = arr[1];
    int c = arr[2];

    return (b*b - (4 * a * c));
}
float* solve_quadratic(int arr[]) {
    int a = arr[0];
    int b = arr[1];
    int c = arr[2];

    float r1 =((b*(-1)) + sqrt(b*b -(4 * a * c)))/(2*a);
    float r2 = ((b*(-1)) - sqrt(b*b - (4 * a * c))) / (2 * a);
    float root[2] = { r1,r2 };
    
    //cout << "root 1:" << r1 << endl ;
    //cout << "root 2:" << r2 << endl ;
    return root;
}

int main() {

    int a = 0;
    int b = 0;
    int c = 0;

    cout << "Enter an equation in the form ax^2+bx+c=0:" << endl;
    cout << "Enter a:";
    cin >> a;
    cout << "Enter b:";
    cin >> b;
    cout << "Enter c:";
    cin >> c;

    int arr[3] = { a,b,c };

    if (a == 0) {
        cout << "Answer:"<<solve_linear(arr)<<endl;
    }
    else {
        if (determinant(arr) < 0) 
        {
            cout << "No real roots exist";
            return 0;
        }
        else
        {
            float *roots = solve_quadratic(arr);
            cout << "root 1:" << *roots << endl;
            roots++;
            cout << "root 2:" << *roots << endl;
        }
    }

    return 0;
}
