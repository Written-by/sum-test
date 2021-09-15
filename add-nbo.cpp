#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[]){
	if(argc!=3){
		printf("syntax : add-nbo <file1> <file2>\n");
		printf("sample : add-nbo a.bin c.bin\n");
		return -1;
	}
	
	FILE *fp1, *fp2;
	uint32_t a, b, sum;

	fp1=fopen(argv[1], "rb");
	fread(&a, sizeof(uint32_t), 1, fp1);
	fp2=fopen(argv[2], "rb");
	fread(&b, sizeof(uint32_t), 1, fp2);

	a=ntohl(a);
	b=ntohl(b);
	sum=a+b;
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, sum, sum);

	fclose(fp2);
	fclose(fp1);
	return 0;
}
