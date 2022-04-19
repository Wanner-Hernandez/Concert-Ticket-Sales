// C code
// // This code will compute the values of the sales ticket sales for concerts
// and sort the entries by those values
// Wanner HernandezR CMIS 102
// November 24, 2019
#include <stdio.h>
#define MAXN 100 
// max characters in a group/concert name 
#define MAXG 50 
// max concerts/groups
#define MAXC 4  
// max categories (Had to increase this to 4)
char  group  [MAXG][MAXN];
int   fans   [MAXG][MAXC];
float prices [MAXC];
float sales  [MAXG];
int count = 0;

void welcome () {
  printf ("\nWelcome to the User Friendly Ticket Sales Calculator\n");
  printf ("This application will aid you calculating ticket sales: \n");
  printf ("Created By: Wanner HernandezRiveron \n CMIS 102 \n\n\n");
} // end function welcome

void printArray () {
  printf ("%15s%5s%5s%5s%10s\n", "Concert", "s1", "s2", "s3", "s4" "Sales");
// had to add (s4)
    for (int i = 0; i < count; i++) {
  printf ("%15s", group [i]);
    for (int j = 0; j < MAXC; j++) {
  printf ("%5d", fans[i][j]);
} // end for each category
  printf ("%10.2f\n", sales [i]);
} // end for each group
} // end function printArray

void computeSales () {
    for (int i = 0; i < count; i++) {
      sales [i] = 0;
    for (int j = 0; j < MAXC; j++) {
      sales [i] += prices [j] * fans [i][j];
} // end for each category
} // end for each group
} // end function computeSales

void switchRows (int m, int n) {
  char tc;
  int  ti;
  float v;
// printf ("Switching %d with %d\n", m, n);
    for (int i = 0; i < MAXN; i++) {
      tc = group [m][i];
      group [m][i] = group [n][i];
      group [n][i] = tc;
} // end for each character in a group name
    for (int i = 0; i < MAXC; i++) {
      ti = fans [m][i];
      fans [m][i] = fans [n][i];
      fans [n][i] = ti;
} // end for each fan category
      v = sales [m];
      sales [m] = sales [n];
      sales [n] = v;
} // end switch

int findMinSales (int m) {
  float min = fans [m][0];
  int target = m;
  for (int i = m+1; i < count; i++)
    if (fans [i][0] < min) {
      min = fans [i][0];
      target = i;
    }// end new max found
  return target;
}// end function findMinSales

void sortBySales () {
  int target;
  for (int i = 0; i < count; i++) {
    target = findMinSales (i);
  if (target > i)
    switchRows (i, target);
}// for each concert
}// end function sortBySales

void getData () {
// for (int i = 0; i < MAXG; i++) sales [i] = 0;
  printf ("Enter ticket prices in each of %d cateogories: ", MAXC); 
    for (int i = 0; i < MAXC; i++)
      scanf ("%f", &prices [i]);
  printf ("-- Enter group and fans in %d categories\n", MAXC); 
  printf (" . to finish entries:\n");
    for (int i = 0; i < MAXG; i++) {
      scanf ("%s", group[i]);
    if (group [i][0] == '.')
    break;
      count++;
    for (int j = 0; j < MAXC; j++)
      scanf ("%d", &fans[i][j]);
} // end for each group
} // end function getData

void totalSalesCalculator (){ 
// function to calculate the total sales
    float total = 0;
    int salesSize = sizeof(sales);
    for (int i = 0; i < salesSize; i++) {
      total += sales[i];
}
  printf("\nThe total Sale is %.2lf \n\n", total); 
}//End function totalSalesCalculator

int main(void) {
  welcome ();
  getData ();
  computeSales ();
  printArray ();
  printf ("\n --- Sorted ---\n");
  sortBySales ();
  printArray ();
  totalSalesCalculator();
  printf("... bye ...\n");
  return 0;
}
