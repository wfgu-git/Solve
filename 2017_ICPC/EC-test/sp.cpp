#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int main(int argc, char *args[]) {
  if (argc != 4) {
    puts("INPUT ERROR");
    return -1;
  }

  char *outFile = args[1];
  char *ansFile = args[2];
  char *resFile = args[3];

  FILE *out = fopen(outFile, "r");
  FILE *ans = fopen(ansFile, "r");
  FILE *res = fopen(resFile, "w");

  if (!out || !ans) {
    puts("INPUT ERROR");
    return -1;
  }

  int x = -1;
  int y = rand() % 10;
  assert(fscanf(out, "%d", &x) != EOF);


  fprintf(res, "<?xml version=\"1.0\"?>\n");
  fprintf(res, "<result outcome=\"%s\" security=\"%s\"/>\n",
          (x == y) ? "Yes" : "No - Wrong Answer", args[3]);

  fclose(out);
  fclose(ans);
  fclose(res);
}
