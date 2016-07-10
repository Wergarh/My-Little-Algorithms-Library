#include <stdio.h>
#include "Array.h"

int main(int argc, char **argv)
{
	const int sz = 10;
    int a[sz] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    
    for(int i = 0; i < sz; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    
    shiftLeft(a, sz, 6);
   
    for(int i = 0; i < sz; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    
	return 0;
}
