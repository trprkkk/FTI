#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include<windows.h>


int main(void)
{
	FILE *fp;
	char name[51];
	int f;
	double gg;
	int r;
	double rc;
	gg = 0;
	r = 0;
		for (f = 1; f <= 10; f++) {

			int s;

			/* 乱数の種を初期化 */
			srand(time(NULL));

			/* 1 〜 9 のランダムな数値 */
			s = rand() % 9;

			printf("%d\n", s);
			/*program copied from https://webkaru.net/clang/display-random-numbers-between-1-and-10/ */

			int si;
			clock_t start, end;
				start = clock();

			while (!kbhit())
			{
				int k;
				int n;
				int c;
				
				k = getch();
				switch (k) {
				case 0x30:
					c = 0;
					break;
				case 0x31:
					c = 1;
					break;
				case 0x32:
					c = 2;
					break;
				case 0x33:
					c = 3;
					break;
				case 0x34:
					c = 4;
					break;
				case 0x35:
					c = 5;
					break;
				case 0x36:
					c = 6;
					break;
				case 0x37:
					c = 7;
					break;
				case 0x38:
					c = 8;
					break;
				case 0x39:
					c = 9;
					break;
				}

				if (s == c) {
					end = clock();
					printf("Hit\n");
					printf("%.2f秒かかりました\n", (double)(end - start) / CLOCKS_PER_SEC);
					r = r + 1;
					break;

				}
				else {
					end = clock();
					printf("Unhit\n");
					printf("%.2f秒かかりました\n", (double)(end - start) / CLOCKS_PER_SEC);
					break;

				}
				
			}
			
			gg = gg + (double)(end - start) / CLOCKS_PER_SEC;
		}
		
		rc = (double)r / 10 * 100;
		printf("%.4f秒\n", gg);
		printf("正答数%d\n", r);
		printf("正答率%.1f％\n", rc);
		Sleep(2 * 1000);
		printf("Please enter your name :");
		scanf("%s", name);
		fp = fopen("Result.txt", "a");
		fprintf(fp, "%s\n", name);
		fprintf(fp, "%.2f秒\n", gg);
		fprintf(fp,"正答数%d\n", r);
		fprintf(fp, "正答率%.1f％\n", rc);
		fprintf(fp, "-o-o-o-o-o-o-o-o-o-\n");
		fclose(fp);

    return (0);
}