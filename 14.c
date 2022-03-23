#include <stdio.h>

int error(int file) {
  printf("Could not open file %d", file);
  return 0;
}
int main() {
  FILE *fout1, *fout2, *fout3, *fin1, *fin2, *fin3;
  char data1[30], data2[30], ch1, ch2, ch3;
  fout1 = fopen("file1.txt", "w");
  fout2 = fopen("file2.txt", "w");
  if (fout1 == NULL) {
    error(1);
  }
  if (fout2 == NULL) {
    error(2);
  }
  printf("Enter content for file1:\n");
  fgets(data1, 30, stdin);
  printf("Enter content for file2:\n");
  fgets(data2, 30, stdin);
  fprintf(fout1, "%s", data1);
  fprintf(fout2, "%s", data2);
  fclose(fout1);
  fclose(fout2);
  fin1 = fopen("file1.txt", "r");
  fin2 = fopen("file2.txt", "r");
  fout3 = fopen("file3.txt", "w");
  if (fin1 == NULL) {
    error(1);
  }
  if (fin2 == NULL) {
    error(2);
  }
  if (fout3 == NULL) {
    error(3);
  }
  do {
    ch1 = getc(fin1);
    ch2 = getc(fin2);

    if (ch1 != ch2) {
      fputc(ch2, fout3);
    }

  } while (ch1 != EOF && ch2 != EOF);
  fclose(fin1);
  fclose(fin2);
  fclose(fout3);
  fin3 = fopen("file3.txt", "r");
  if (fin3 == NULL) {
    printf("Could not read from file 3");
    return 0;
  }
  if ((ch3 = getc(fin3)) == EOF) {
    printf("No difference between file1 and file2");
    return 0;
  }
  printf("Differences between file1 and file2:\n");
  while (ch3 != EOF) {
    printf("%c", ch3);
    ch3 = getc(fin3);
  }
  fclose(fin3);
  return 0;
}
