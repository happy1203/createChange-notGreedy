#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "coins.h"
#include "print-coins.h"
#include "cs136-trace.h" 

///////////////////////////////////////////////////////////////////////////// 
// do not modify these constants:
const int COINS_MAX_TARGET = 4095;
const int COINS_FAIL = -1;
const int INT_MAX = 2147483647; 
///////////////////////////////////////////////////////////////////////////// 

// time: O(n^2)

int make_change(const int coins[], int len, int target, int qty[]) {
  int min[4095] = {0};
  int last[4095] = {0}; 
  int minimum = INT_MAX;
  int prev = 0;
  int coins_required = 0;
  int current = 0;
  for (int temp_target = 1; 
       temp_target <= target; ++temp_target) {
    int i = 0; 
    while (i < len) {
      if (coins[i] <= temp_target) {
        if (min[temp_target - coins[i]] != COINS_FAIL) {
          coins_required = 
            min[temp_target - coins[i]] + 1;
          current = i;
        }
        if (min[temp_target - coins[i]] == COINS_FAIL) {
          coins_required = INT_MAX;
          current = COINS_FAIL;
        }
        
        if (coins_required <= minimum) {
          prev = current;
          minimum = coins_required;
        }
      }
      i++; 
    }
    if (minimum < INT_MAX) {
      min[temp_target] = minimum;
      last[temp_target] = prev;
      minimum = INT_MAX;
      prev = 0;   
    } 
    else {
      min[temp_target] = COINS_FAIL;
      last[temp_target] = COINS_FAIL;
    }
  }
  if (min[target] == COINS_FAIL) return COINS_FAIL;
  else {
    int pos = 0; 
    int total = 0; 
    for (; target != 0; total++) { 
      pos = last[target];
      qty[pos]++;
      target -= coins[pos];
    }
    return total; 
  }
}
