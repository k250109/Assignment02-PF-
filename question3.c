#include <stdio.h>
#define ROW 3
#define COLUMN 3
void display_sector(int row, int col, int grid[ROW][COLUMN]) {
  int value = grid[row][col];
  printf("\n--- Sector: %d x %d ---\n", row + 1, col + 1);
  printf("Current Status Flag: %d\n", value);
  printf("Power Status: %s\n", (value & 1) ? "ON" : "OFF");
  printf("Overload Warning: %s\n", (value >> 1 & 1) ? "Overloaded" : "Normal");
  printf("Maintainence Required: %s\n\n", (value >> 2 & 1) ? "Yes" : "No");
}
void update_sector(int grid[ROW][COLUMN]) {
  int row, col;
  printf("Enter row and column number for grid (1-%d) (1-%d): ", ROW, COLUMN);
  scanf("%d %d", &row, &col);
  if (row > ROW || col > COLUMN) {
    printf("\nInvalid row and col number! try again.\n\n");
    return;
  }
  row--;
  col--;
  display_sector(row, col, grid);
  int status_flag;
  printf("Enter new status flag (0-7): ");
  scanf("%d", &status_flag);
  if (status_flag > 7 || status_flag < 0) {
    printf("Invalid Status Flag! Try again.\n");
    return;
  }
  grid[row][col] = status_flag;
  printf("\nSuccessfully updated status flag: `%d` for grid %d x %d\n\n",
         grid[row][col], row, col);
}
void query_sector(int grid[ROW][COLUMN]) {
  int row, col;
  printf("Enter row and column number for grid (1-%d) (1-%d): ", ROW, COLUMN);
  scanf("%d %d", &row, &col);
  if (row > ROW || col > COLUMN) {
    printf("\nInvalid row and col number! try again.\n\n");
    return;
  }
  row--;
  col--;
  display_sector(row, col, grid);
}
void system_diagnostic(int grid[ROW][COLUMN]) {
  printf("\n--- System Diagnostic ---\n");
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COLUMN; j++) {
      int value = grid[i][j];
      if (value & 2) {
        printf(
            "\033[33m Grid sector [%d x %d]: %d has overload warning \033[0m\n",
            i, j, grid[i][j]);
      }
      if (value & 4) {
        printf("\033[33m Grid sector [%d x %d]: %d requires maintainence "
               "\033[0m\n",
               i, j, grid[i][j]);
      }
    }
  }
  printf("\n");
}
int main() {
  int grid[ROW][COLUMN] = {{3, 1, 2}, {3, 4, 5}, {6, 7, 7}};
  int choice;
  do {
    printf("\n--- Welcome to IESCO grid-sector Management System ---\n");
    printf("[1]. Update sector status\n");
    printf("[2]. Query Sector Status\n");
    printf("[3]. Run System Diagnostic\n");
    printf("[4]. Exit\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    while (getchar() != '\n');
    switch (choice) {
    case 1:
      update_sector(grid);
      break;
    case 2:
      query_sector(grid);
      break;
    case 3:
      system_diagnostic(grid);
      break;
    case 4:
      printf("\nThank you for using the app!\n");
      break;
    default:
      printf("\nInvalid Input! Please try again\n\n");
      continue;
    }
  } while (choice != 4);
  return 0;
}