//
//  main.m
//  2021_04_19_01
//
//  Created by dulei on 2021/4/19.
//

#import <Foundation/Foundation.h>

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++) {
        int flag = false;
        for (int j = 0; j < n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            flag = true;
        }
        
        if (!flag) {
            break;
        }
    }
}

void select_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        int min_idx = i;
        for (int j = i; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

void insert_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0) {
            if (arr[j] < arr[j-1]) {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                j--;
            } else {
                break;
            }
        }
    }
}

void shell_sort(int arr[], int n)
{
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int index = i - gap;
            while (index >= 0 && temp < arr[index]) {
                arr[index+gap] = arr[index];
                index -= gap;
            }
            
            arr[index+gap] = temp;
        }
    }
}

void shell_sort_1(int arr[], int n)
{
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int idx = i - gap;
            while (idx >= 0 && temp < arr[idx]) {
                arr[idx+gap] = arr[idx];
                idx -= gap;
            }
            
            arr[idx+gap] = temp;
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

int main(int argc, const char * argv[]) {

    int res[5] = {1,5,3,6,2};
//    insert_sort(res, 5);
//    shell_sort(res, 5);
    shell_sort_1(res, 5);
    display(res, 5);
    return 0;
}
