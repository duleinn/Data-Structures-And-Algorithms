//
//  main.m
//  2021_04_16_01
//
//  Created by dulei on 2021/4/16.
//

#import <Foundation/Foundation.h>

void select_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void select_sort_1(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++) {
        int flag = false;
        for (int j = 0; j < n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                flag = true;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if (!flag) {
            break;
        }
    }
}

void display(int arr[], int n)
{
    printf("\n================\n");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf("\n================\n");
}

int main(int argc, const char * argv[])
{
    int res[5] = {1,2,3,5,9};
    
    select_sort(res, 5);
    select_sort_1(res, 5);
    bubble_sort(res, 5);
    display(res, 5);
    
    return 0;
}
