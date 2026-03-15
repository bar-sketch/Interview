#include <stdio.h>
#include <stdint.h>

int32_t firstOccurrence(const int32_t arr[], int32_t n, int32_t target){
    if(!arr || n<=0)
        return -1;
        
    int32_t low =0;
    int32_t high = n-1;
    int32_t mid;
    int32_t firstIndex = -1;
    while(low <= high){
        mid = low + ((high - low)>>1);
        if(arr[mid] == target){
            firstIndex = mid;
            high = mid - 1;
        }
        else if(arr[mid] > target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
        
    }
    return firstIndex;
}

int32_t lastOccurrence(const int32_t arr[], int32_t n, int32_t target){
    
    if(!arr || n<=0)
        return -1;
    
    int32_t low =0;
    int32_t high = n-1;
    int32_t mid;
    int32_t lastIndex = -1;
    
    while(low <= high){
        
        mid = low + ((high - low)>>1);
        
        if(arr[mid] == target){
            lastIndex = mid;
            low = mid + 1;
        }
        else if(arr[mid] > target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return lastIndex;
}

void binary_Search_First_And_Last_Occurence(const int32_t *arr, int32_t n, int32_t target, int32_t *result, int32_t *size){
    
    if(!arr || n <= 0 || !result || !size)
        return;
        
    result[0] = firstOccurrence(arr, n , target);
    result[1] = lastOccurrence(arr, n, target);
    *size = 2;
    
}


int main(void){
    int32_t arr[8]= {1,4,4,4,4,6,8,20};
    int32_t result[2];
    int32_t size = 0;
    binary_Search_First_And_Last_Occurence(arr, 8, 4, result, &size);
    printf("Result:%d %d Size:%d", result[0], result[1], size);
    return 0;
}