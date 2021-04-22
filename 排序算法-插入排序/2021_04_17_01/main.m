//
//  main.m
//  2021_04_17_01
//
//  Created by dulei on 2021/4/17.
//

#import <Foundation/Foundation.h>

void insert_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0) {
            if (arr[j] < arr[j-1]) {
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
                j--;
            } else {
                break;
            }
        }
    }
}

void display(int arr[], int n)
{
    printf("============\n");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf("\n============\n");
}

int main(int argc, const char * argv[])
{
    int res[5] = {3,8,1,4,2};
    insert_sort(res, 5);
    display(res, 5);
    return 0;
}
