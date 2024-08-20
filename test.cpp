# include <stdio.h>

int main(int argc, char **argv){
  int cnt;
  for (cnt =1; cnt < argc; cnt++) printf("%s\n", argv[cnt]);
  return 0;

}
