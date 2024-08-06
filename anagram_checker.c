#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
void merge(char arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    //creating temporary arrays
    char l[n1], r[n2];
    //copy the letters to the arrays
    for (i = 0; i < n1; i++) {
        l[i] = tolower(arr[left + i]);
    }
    for (j = 0; j < n2; j++) {
        r[j] = tolower(arr[middle + 1 + j]);
    }
    //merge the temprary arrays
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (l[i] <= r[j]) {
            arr[k] = l[i];
            i++;
        } else {
            arr[k] = r[j];
            j++;
        }
        k++;
    }
    //get the remaining letters of the array l[]
    while (i < n1) {
        arr[k] = l[i];
        i++;
        k++;
    }
    //get the remaining letters of the array r[]
    while (j < n2) {
        arr[k] = r[j];
        j++;
        k++;
    }
}
void mergeSort(char arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);//sort the array into two equal halves
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);// merge the two arrays
    }
}
//function to check if the two sorted strings are anagrams or not
bool areAnagrams(char str1[], char str2[]) {
    int n1 = strlen(str1);//finding the lengths of two strings
    int n2 = strlen(str2);
    if (n1 != n2) {//checking if the lengths are same
        return false;
    }
    mergeSort(str1, 0, n1 - 1);//performing sorting of the arrays
    mergeSort(str2, 0, n2 - 1);
    for (int i = 0; i < n1; i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}
int main() {
    char str1[100];
    char str2[100];
    printf("Enter the first string: ");
    scanf("%s", str1);//getting input of the string 1    
    printf("Enter the second string: ");
    scanf("%s", str2);//getting the input of the string 2
    if (areAnagrams(str1, str2)) {
        printf("The two strings are anagrams.\n");
    } else {
        printf("The two strings are not anagrams.\n");
    }
    return 0;
}