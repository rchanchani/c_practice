#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define ACTION_SIZE 12
#define FILE_NAME 1024

int get_row(FILE *file, size_t row_num, char delim[]) {
  size_t n_line, field = 0;
  char row[BUFFER_SIZE];
  char *line[BUFFER_SIZE];

  while (fgets(row, BUFFER_SIZE, file)) {
    if (n_line == row_num) {
        char* element = strtok(row, delim);
        while (element != NULL) {
            if(strcmp(",", element) != 0 &&  strcmp("\n", element) != 0)
            {
              printf("%s\n", element);
              line[field++] = strdup(element);
            }
            element = strtok(NULL, delim);
        }
        printf("Length of line %ld is %ld elements!\n", n_line, field);
        return 0;
    } else {
      n_line++;
    }
  }
  printf("There is no row %ld in the file you selected.\n", row_num);
  return 0;
}

int get_col(FILE *file, size_t col_num, char delim[]) {
  size_t n_line = 0, field, nelem = 0;
  char *col[BUFFER_SIZE], row[BUFFER_SIZE];

  while (fgets(row, BUFFER_SIZE, file)) {
    char* element = strtok(row, delim);
    field = 0;
    while (element != NULL) {
        if(strcmp(",", element) != 0 &&  strcmp("\n", element) != 0 && field == col_num)
        {
          printf("%s\n", element);
          col[nelem++] = strdup(element);
        }
        element = strtok(NULL, delim);
        field++;
    }
  }
  printf("Length of column %ld is %ld elements!\n", col_num, nelem);
  return 0;
}

int main(int argc, char **argv) {
   FILE *file;
   char file_name[FILE_NAME], action[ACTION_SIZE], read_file[5], row[20], col[10];
   int n_chars = 0;
   char delim[]  = "\"";
   char *endptr;

   while (1) {
     printf("Read in a .csv file? (yes/quit): ");
     scanf("%11s", read_file);
     while (n_chars < strlen(read_file)) {
       read_file[n_chars] = tolower(read_file[n_chars]);
       n_chars++;
     }
     if (!strcmp(read_file, "yes")) {
       printf("Enter the filename including extension (.csv): ");
       scanf("%1023s", file_name);
       file = fopen(file_name, "r");
       if (!file) {
         printf("Error: could not open %s\n", file_name);
         return -1;
       }
       printf("What would you like to do? Get (row, col, elem, quit): ");
       scanf("%60s", action);
       if (!strcmp(action, "row")) {
         printf("Which row? (starting from 0 for field names): ");
         scanf("%21s", row);
         size_t n_row = strtol(row, &endptr, 10);
         get_row(file, n_row , delim);
         exit(0);
       } else if (!strcmp(action, "col")) {
         printf("Which column? (starting from 0 for first column): ");
         scanf("%21s", col);
         size_t n_col = strtol(col,&endptr,10);
         get_col(file, n_col, delim);
         exit(0);
       } else {
         printf("Invalid response\n");
         continue;
       }
     } else if (!strcmp(read_file, "quit")) {
       printf("Quitting...\n");
       exit(0);
     } else {
       printf("Enter a valid option (yes/quit): ");
     }
   }
   fclose(file);
   return 0;
 }
