#include <stdio.h>
#include "functions.h"
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  FOOD foods[10], blankfood;
  FRIEND friends[10],blankfriend;

  blankfriend.balance = -1;
  blankfood.price = -1;

  for(int j=0; j<10;j++){
      blankfood.friends[j].balance = -1;
  }

  for(int i = 0; i < 10;i++){
    friends[i].balance = -1;
  }

  for(int i = 0; i < 10;i++){
    foods[i].price = -1;
  }

  for(int i=0;i<10;i++){
    for(int j=0; j<10;j++){
        foods[i].friends[j].balance = -1;
    }
  }

  puts("BillSplit v1.0.0");
  puts("");
  puts("");
  puts("Before proceeding, you must register your friends.");
  puts("");
  firstmenu(friends, foods, blankfriend, blankfood);


  return 0;
}
