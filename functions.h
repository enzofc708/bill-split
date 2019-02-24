#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct _FRIEND{
  char name[21];
  float balance;
} FRIEND;

typedef struct _FOOD{
  char name[21];
  float price;
  FRIEND friends[11];
} FOOD;

void addfriend(FRIEND *friendp, FOOD *foodp, FRIEND blankfriend, FOOD blankfood);
void mainmenu(FRIEND *friendp, FOOD *foodp, FRIEND blankfriend, FOOD blankfood);
int findBfriend(FRIEND *friendp);
void foodmenu(FRIEND *friendp, FOOD *foodp, FRIEND blankfriend, FOOD blankfood);
void friendmenu(FRIEND *friendp, FOOD *foodp, FRIEND blankfriend, FOOD blankfood);

int findFriend(FRIEND f, FRIEND *friendp){
  for(int i = 0; i<findBfriend(friendp); i++){
    if (strcmp(f.name, friendp[i].name)==0) return i;
  }
}

int findLastFood(FOOD *foodp){
  for(int i = 9; i > -1; i--){
    if(foodp[i].price != -1) return i;
  }
}

int findLastFriend(FRIEND *friendp){
  for(int i = 9; i > -1; i--){
    if(friendp[i].balance != -1) return i;
  }
}

int friendInList(FRIEND f, FRIEND *friendp){
  for (int i = 0; i< findBfriend(friendp); i++){
    if (strcmp(f.name,friendp[i].name) == 0){
      return 1;
    }
  }
  return 0;
}

int findBfood(FOOD *foodp){
  for(int i = 0; i<10; i++){
    if(foodp[i].price == -1) return i;
  }
}

void addfood(FRIEND *friendp, FOOD *foodp, FRIEND blankfriend, FOOD blankfood){
  puts("");
  int n = findBfood(foodp);
  puts("Enter the Food name:");
  char name[21];
  scanf("%s",name);getchar();
  strcpy(foodp[n].name, name);
  puts("Enter the Food price:");
  float price;
  scanf("%f",&price);
  foodp[n].price = price;
  puts("");
  puts("Select the Friends who are eating this Food:");
  for(int i = 0; i < findBfriend(friendp);i++){
    printf("%d. %s\n",i+1,friendp[i].name);
  }
  puts("0-Done");
  int ansf;
  scanf("%d",&ansf);getchar();
  while(ansf < 0 || ansf > findBfriend(friendp)){
    puts("Please, select an valid option.");
    scanf("%d",&ansf);getchar();
  }
  while(ansf!=0){
    if (friendInList(friendp[ansf-1], foodp[n].friends)) {
      puts("This Friend is already assigned to this Food!");
      puts("");
    }
    else{
      foodp[n].friends[findBfriend(foodp[n].friends)] = friendp[ansf-1];
      printf("Now %s is eating %s!",friendp[ansf-1].name, foodp[n].name);
      puts("");
    }
    puts("Select the Friends who are eating this Food:");
    for(int i = 0; i < findBfriend(friendp);i++){
      printf("%d. %s\n",i+1,friendp[i].name);
    }
    puts("0-Done");
    scanf("%d",&ansf);getchar();
  }
  foodmenu(friendp, foodp, blankfriend, blankfood);
}

void rmvfriend(FRIEND *friendp, FOOD *foodp, FRIEND blankfriend, FOOD blankfood){
  puts("");
  puts("Select the Friend you want to remove:");
  for(int i =0; i< findBfriend(friendp);i++){
    printf("%d. %s\n", i+1, friendp[i].name);
  }
  puts("0. Cancel");
  int ans;
  scanf("%d",&ans);getchar();
  while(ans < 0 || ans > findBfood(foodp)){
    puts("Select an valid option.");
    scanf("%d",&ans);getchar();
  }
  while(ans != 0){
    friendp[ans-1] = blankfriend;
    for(int i = ans-1; i < findLastFriend(friendp);i++){
      FRIEND temp = friendp[i];
      friendp[i] = friendp[i+1];
      friendp[i+1] = temp;
    }
    rmvfriend(friendp, foodp, blankfriend, blankfood);
  }
  friendmenu(friendp, foodp, blankfriend, blankfood);
}

void rmvfood(FRIEND *friendp, FOOD *foodp, FRIEND blankfriend, FOOD blankfood){
  puts("");
  puts("Select the Food you want to remove:");
  for(int i =0; i< findBfood(foodp);i++){
    printf("%d. %s\n", i+1, foodp[i].name);
  }
  puts("0. Cancel");
  int ans;
  scanf("%d",&ans);getchar();
  while(ans < 0 || ans > findBfood(foodp)){
    puts("Select an valid option.");
    scanf("%d",&ans);getchar();
  }
  while(ans != 0){
    foodp[ans-1] = blankfood;
    for(int i = ans-1; i < findLastFood(foodp);i++){
      FOOD temp = foodp[i];
      foodp[i] = foodp[i+1];
      foodp[i+1] = temp;
    }
    rmvfood(friendp, foodp, blankfriend, blankfood);
  }
  foodmenu(friendp, foodp, blankfriend, blankfood);
}

void foodmenu(FRIEND *friendp, FOOD *foodp, FRIEND blankfriend, FOOD blankfood){
  puts("1. Add Food");
  puts("2. Remove Food");
  puts("3. Back");
  int ans;
  scanf("%d",&ans);getchar();
  while(ans < 1 || ans > 3){
    puts("");
    puts("Invalid! Please type a number from 1 to 3.");
    scanf("%d",&ans);getchar();
  }


  switch(ans){
    case 1:
    addfood(friendp, foodp, blankfriend, blankfood);
    break;

    case 2:
    rmvfood(friendp, foodp, blankfriend, blankfood);
    break;

    case 3:
    mainmenu(friendp, foodp, blankfriend, blankfood);
    break;
  }

}


void firstmenu(FRIEND *friendp, FOOD *foodp, FRIEND blankfriend, FOOD blankfood){
  puts("Press 1 to add a new Friend");
  puts("Press 2 to finish registering");
  int ans;
  scanf("%d",&ans);getchar();
  while(ans < 1 || ans > 2){
    puts("");
    puts("Invalid! Please choose option 1 or 2.");
    scanf("%d",&ans);getchar();
  }
  switch(ans){
    case 1:
    addfriend(friendp, foodp, blankfriend, blankfood);
    break;

    case 2:
    mainmenu(friendp, foodp, blankfriend, blankfood);
    break;
  }
}


int findBfriend(FRIEND *friendp){
  for(int i = 0; i<10; i++){
    if(friendp[i].balance == -1) return i;
  }
}

void addfriend(FRIEND *friendp, FOOD *foodp, FRIEND blankfriend, FOOD blankfood){
  puts("");
  int n = findBfriend(friendp);
  puts("Enter the Friend name:");
  char name[21];
  scanf("%s",name);getchar();
  strcpy(friendp[n].name, name);
  friendp[n].balance = 0;
  puts("");
  firstmenu(friendp, foodp, blankfriend, blankfood);
}

void addfriend2(FRIEND *friendp, FOOD *foodp, FRIEND blankfriend, FOOD blankfood){
  puts("");
  int n = findBfriend(friendp);
  puts("Enter the Friend name:");
  char name[21];
  scanf("%s",name);getchar();
  strcpy(friendp[n].name, name);
  friendp[n].balance = 0;
  puts("");
  friendmenu(friendp, foodp, blankfriend, blankfood);
}

void friendmenu(FRIEND *friendp, FOOD *foodp, FRIEND blankfriend, FOOD blankfood){
  puts("");
  puts("1. Add Friend");
  puts("2. Remove Friend");
  puts("3. Back");
  puts("");
  int ans;
  scanf("%d",&ans);getchar();
  while(ans < 1 || ans > 3){
    puts("");
    puts("Invalid! Please type a number from 1 to 3.");
    scanf("%d",&ans);getchar();
  }


  switch(ans){
    case 1:
    addfriend2(friendp, foodp, blankfriend, blankfood);
    break;

    case 2:
    rmvfriend(friendp, foodp, blankfriend, blankfood);
    break;

    case 3:
    mainmenu(friendp, foodp, blankfriend, blankfood);
    break;
  }
}

void closebill(FRIEND *friendp, FOOD *foodp, FRIEND blankfriend, FOOD blankfood){
  for(int i = 0; i < findBfood(foodp); i++){
    float amount = findBfriend(foodp[i].friends);
    float value = foodp[i].price/amount;
    for(int j = 0; j < amount; j++){
      int friendnum =  findFriend(foodp[i].friends[j], friendp);
      friendp[friendnum].balance += value;
    }
  }
  puts("Is the tip included (10%%)?");
  puts("");
  puts("1. Yes");
  puts("2.No");
  int ans;
  scanf("%d",&ans);
  while(ans < 1 || ans > 2){
    puts("");
    puts("Choose option 1 or 2.");
    scanf("%d",&ans);
  }
  if (ans == 1){
    for(int i = 0; i < findBfriend(friendp); i++){
      friendp[i].balance *= 1.1;
    }
  }

  for(int i = 0; i < findBfriend(friendp); i++){
    printf("%s must pay %0.2f\n", friendp[i].name, friendp[i].balance);
  }
}

void mainmenu(FRIEND *friendp, FOOD *foodp, FRIEND blankfriend, FOOD blankfood){
  puts("");
  puts("Main Menu:");
  puts("1. Manage Foods");
  puts("2. Manage Friends");
  puts("3. Close Bill");
  puts("");
  int ans;
  scanf("%d",&ans);getchar();
  while(ans < 1 || ans > 3){
    puts("");
    puts("Invalid! Please type a number from 1 to 3.");
    scanf("%d",&ans);getchar();
  }

  switch (ans) {
    case 1:
    foodmenu(friendp, foodp, blankfriend, blankfood);
    break;

    case 2:
    friendmenu(friendp, foodp, blankfriend, blankfood);
    break;

    case 3:
    closebill(friendp, foodp, blankfriend, blankfood);
    break;
  }
}
