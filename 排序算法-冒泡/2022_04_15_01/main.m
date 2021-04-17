//
//  main.m
//  2022_04_15_01
//
//  Created by dulei on 2021/4/15.
//

#import <Foundation/Foundation.h>

void bubble_sort(int arr[], int n)
{
    bool flag = false;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                
                flag = true;
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
    
    bubble_sort(res, 5);
    display(res, 5);
    return 0;
}
