#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char user[100];
  char action[100];

  printf("Enter 'yes' or something else: ");
  scanf("%s", user);
  if (!strcmp(user,"yes")) {
    printf("Hello, world!\n"
            "The strcmp function returns a 0 if the two strings are "
            "identical.\nThis is inconvenient because, in an if-statement, "
            "0 is a logical false.\n");
  } else {
    printf("You didn't enter the word 'yes'!.\n");
  }
  return 0;
}
