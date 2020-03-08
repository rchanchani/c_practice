#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NELEMS(x)  (int)(sizeof(x) / sizeof((x)[0]))

void init_trans(int* n_row, int* n_col)
{
  printf("Enter the dimensions of the transition matrix, "
    "the number of rows followed by the number of columns.\n");
  if(scanf("%d %d", n_row, n_col) != 2)
  {
    printf("Include the correct number of dimensions\n");
  }  else {
    printf("The size of the transition matrix is: %d x %d\n", *n_row, *n_col);
  }
  return;
}

void populate(int n_row, int n_col, double trans[n_row][n_col])
{
  for (int row=0; row<n_row; row++)
  {
    for(int col=0; col<n_col; col++)
    {
      scanf("%lf     ", &trans[row][col]);
    }
    printf("\n");
  }
  return;
}

int main (int argc, char *argv[]) {
  int n_row, n_col, row, col;

  init_trans(&n_row, &n_col); /*ask for the size of the transition matrix */
  double trans_mat[n_row][n_col]; /* create unpopulated transition matrix */
  populate(n_row, n_col, trans_mat); /* allow user to populate transition matrix */
  printf("\nThe transition matrix is:\n");
  for (int row=0; row<n_row; row++)
  {
    for(int col=0; col<n_col; col++)
    {
      printf("%f     ", trans_mat[row][col]);
    }
    printf("\n");
  }
  return 0;
}
