#include <stdint.h>
#include <stdbool.h>

bool feasible(const int32_t piles[], int32_t n, int32_t h, int32_t speed){
    
    if(!piles || n<=0 || speed <= 0 || h <= 0){
        return false;
    }
    
    int64_t totalHours = 0;
    for( int32_t i = 0; i<n ; i++){
        totalHours += (piles[i] + speed - 1)/speed;
        if(totalHours > h)
            return false;
    }
    return (totalHours <= h);
}

int32_t minEatingSpeed(const int32_t piles[], int32_t n, int32_t h){
    
    if(!piles || n<=0 || h <= 0){
        return -1;
    }
    
    int32_t low = 1;
    int32_t high = piles[0];
    
    for(int32_t i = 1; i < n; i++){
        if(piles[i] > high){
            high = piles[i];
        }
    }
    
    int32_t mid;
    int32_t ans = high;
    
    while(low <= high){
        
        mid = low + ((high - low)>>1);
        
        if(feasible(piles, n, h, mid)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
        
    }
    return ans;
}

int main(void) {
    int32_t piles[] = {3, 11, 7, 5};
    int32_t n = sizeof(piles) / sizeof(piles[0]);
    int32_t h = 8;

    printf("%d\n", minEatingSpeed(piles, n, h));
    return 0;
}