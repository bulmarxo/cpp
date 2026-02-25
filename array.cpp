#include "array.h"
#include <string>
#include <iostream>

using namespace std;

int countOccurrences(const string a[], int n, string target){ //complete & debugged

    if(n < 0){
        return -1;
    }

    int o = 0;
    int i = 0;

    while(i < n){

        if(a[i] == target){
            o++;    
        }
        i++;
    }

    return o;
}

int locateOccurrence(const string str[], int n, string target){ // complete & debugged

    if(n < 0){
        return -1; // checks for valid string 
    }

    int i = 0;

    while(i < n){

        if(str[i] == target){
            
            return i;
        }
        i++;
    }

return -1;
}

int locateMin(const string a[], int n)// complete & debugged
{

    int min = 0;

    if(n <= 0){ //checks for out of bounds values
        return -1;
    }


   for(int i = 0; i < n; i++){ //performs lexicographic comparison, returning smallest val
        if(a[i] < a[min]){
            min = i;
        }
   }

    return min; //return min
}

int eliminateDuplicates(string a[], int n)// complete & debugged
{

    if(n < 0){ //checks for appropriate array size
        return -1;
    }

    int pr = 0; //read-write indexes
    int se = 1;

    while(se < n){

        if(a[se] != a[pr]){

            pr++;
            se++;
            continue;
        }
        else{

           for(int shift = se; shift < n - 1; shift++){ //shifts all indexes after duplicate left, replacing duplicate

            a[shift] = a[shift + 1];

           }
           n--; //shrinks viable array size

        }

    }

    return n;
}

bool contains(const string a1[], int n1, const string a2[], int n2)//complete & debugged
{
    if (n1 < 0 || n2 < 0) return false;
    if (n2 == 0) return true;

    int j = 0; // index into a2
    for (int i = 0; i < n1 && j < n2; i++) {
        if (a1[i] == a2[j]) {
            j++;
        }
    }
    return j == n2;

}

int divide(string a[], int n, string divider) //complete & debugged
{
    if(n < 0){ // bounds check
        return -1;
    }

    int fNL = 0; // variables to sort < > divider
    int fG = n;
    int i = 0;

    while(i < fG){

        if(a[i] < divider){ //shifts value to the left

            string temp = a[i];
            a[i] = a[fNL];
            a[fNL] = temp;

            fNL++;
            i++;
        }
        else if(a[i] > divider){ //shifts value to the right

            fG--;

            string temp = a[i];
            a[i] = a[fG];
            a[fG] = temp;
        }
        else{
            i++;
        }

        
    }

    

    return fNL;
}

int moveToBack(string a[], int n, int pos)//complete & debugged
{

    if (n < 0 || pos < 0 || pos >= n){ //bounds check
        return -1;
    }

    string store; //stores val at index pos 
    store = a[pos];
    int i = pos;

    while(i < n-1){ //shifts all subsequent letters to the left

        a[i] = a[i + 1];
        i++;
    }

    a[n-1] = store; // n - 1 becomes val at index pos 

    return pos; //returns og index of pos 
}
