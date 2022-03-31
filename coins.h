extern const int COINS_MAX_TARGET;
extern const int COINS_FAIL;

// make_change(coins, len, target, qty) is passed len coin denominations
//   and determines how to produce the target amount using those coins
// notes: return value is the number of coins in solution or
//          COINS_FAIL if make_change could not find an answer
//        qty[i] is the number of coins[i] in the solution or 0 if COINS_FAIL
//        if a solution exists, the return value is the sum of qty elements
//        if the target is zero, the return value is zero
// requires: coins, qty are valid arrays with length >= len [not asserted]
//           coins are all unique positive values [not asserted]
//           coins is sorted in ascending order [not asserted]
//           0 <= target <= COINS_MAX_TARGET
//           0 < len
// effects: modifies qty (overwrites qty)
// time: ??? (add this documentation to your .c file)
int make_change(const int coins[], int len, int target, int qty[]);
