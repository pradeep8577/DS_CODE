#include<stdio.h>
struct product
{
  int id;
  char name[50];
  float price;
  float gst;
};

void traverse(struct product *prodar, int lp);

int main()
{
    struct product p;
    struct product prod_arr[100];
    
    int pos = 0;
    int i = 0, cur_sz = 0;

    FILE *f1;
    f1 = fopen("product.txt", "r");
    while (fscanf(f1, "%d%d%s%f%f", &pos, &p.id, p.name, &p.price, &p.gst) != EOF)
    {
 		prod_arr[i] = p;
		cur_sz++;
		i++;     	
    }

	traverse(prod_arr, cur_sz);
	fclose(f1);
}


void traverse(struct product *prodar, int lp)
{
    int cur_pos = 0;
    if (lp != -1)
    {
        printf("\n-----------------------------------------------------------------------\n");
        printf("SR.NO.\tID\tNAME\t\t\t\tPRICE\t\tGST");
        printf("\n-----------------------------------------------------------------------\n");
        while (cur_pos < lp)
        {
            printf("%d\t%d\t%s\t\t\t\t%0.2f\t\t%0.2f\n", ++cur_pos, prodar[cur_pos].id, prodar[cur_pos].name, prodar[cur_pos].price, prodar[cur_pos].gst);
            
        }
        printf("-----------------------------------------------------------------------\n");
    }
}

