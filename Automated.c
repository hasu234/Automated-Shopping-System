#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/*Structure Start*/
struct product
{
    int price;
    char name[20]; //Product Name
    int number[50];//Product Number
}product;
/*Structure End*/
void mainMenu();
void empty_cart();
int count_cart_item() ;
/*Function For Admin*/
void admin();
void adm_add();
void adm_delete();
void adm_calculate();
/*Function For User*/
void user_main();
void user_viewAll();
void search_product();
void user_order();
void user_viewCart();
int main()
{
    mainMenu();
}
void mainMenu(){
int ch;
system("COLOR F1");
 do
 {
   printf("\n\t------------------------------------------------");
   printf("\n\t|        AUTOMATED SHOPPING SYSTEM             |");
   printf("\n\t------------------------------------------------");
   printf("\n\n");
   printf("\nPress <1> ADMIN");
   printf("\nPress <2> USER");
   printf("\nPress <0> EXIT");
   printf("\nEnter your Choice ::");
   scanf("%d",&ch);
   switch (ch)
   {
    case 1 : admin();
    break;
    case 2: user_main();
    break;
    case 0:exit(0);
    break;
    default:
    printf("Wrong Choice !");
    break;
   }
 }
 while(ch!=-1);
}
void admin()
{
 int ch;
 char adm_name[20]="admin";
 char adm_pass[20]="admin";
 char temp_name[20],temp_pass[20];
 system("COLOR F1");
 printf("\n\tAdmin Name:- ");
 scanf("%s",temp_name);
 printf("\n\tPassword:- ");
 scanf("%s",temp_pass);
 if(strcmp(adm_name,temp_name) == 0 && strcmp(adm_pass,temp_pass) == 0)
 {
	do
 	{
   		printf("\n\t------------------------------------------------");
   		printf("\n\t|         AUTOMATED SHOPPING SYSTEM            |");
   		printf("\n\t------------------------------------------------");
   		printf("\n\n");
   		printf("\nPress <1> Insert New Product ");
   		printf("\nPress <2> Delete Product ");
		printf("\nPress <3> Checkout And Payment ");
		printf("\nPress <4> Main Menu");
		printf("\nPress <0> Exit ");
   		printf("\nEnter your Choice ::");
   		scanf("%d",&ch);
   		switch (ch)
   		{
            case 1: adm_add();
            break;
			case 2: adm_delete();
			break;
			case 3: adm_calculate();
			break;
			case 4: mainMenu();
            break;
            case 0: exit(0);
            break;
            default:
            printf("Wrong Choice !");
            break;
   		}
 	}while(ch!=0);
 }
 else
   printf("Password and User Name Are Not Matched\n");
}
/*Start User Function*/
void user_main()//main user side function
{
 int ch,exsist_cart_product;
 char user_name[20]="user";
 char user_pass[20]="user";
 char temp_name[20],temp_pass[20];
 system("COLOR F1");
 printf("\n\tUser Name:- ");
 scanf("%s",temp_name);
 printf("\n\tPassword:- ");
 scanf("%s",temp_pass);
 if(strcmp(user_name,temp_name) == 0 && strcmp(user_pass,temp_pass) == 0)
 {
	do
 	{
   		printf("\n\t------------------------------------------------");
   		printf("\n\t|          AUTOMATED SHOPPING SYSTEM           |");
   		printf("\n\t------------------------------------------------");
   		printf("\n\n");
   		exsist_cart_product = count_cart_product();
   		printf("\nPress <1> View All Products");
   		printf("\nPress <2> Search Needed Product");
		printf("\nPress <3> Order Product");
		printf("\nPress <4> View Your Cart (%d Product in cart)",exsist_cart_product);
		printf("\nPress <5> Empty cart ");
   		printf("\nPress <6> Main Menu");
   		printf("\nPress <0> Exit");
   		printf("\nEnter your Choice ::");
   		scanf("%d",&ch);
   		switch (ch)
   		{
            case 1: user_viewAll();
            break;
			case 2: search_product();
			break;
			case 3: user_order();
			break;
			case 4: user_viewCart();
			break;
			case 5: empty_cart();
			    break;
			case 6: mainMenu();
                break;
            case 0: exit(0);
	    		break;
            default:
	    		printf("Wrong Choice !");
	    		break;
   		}
 	}while(ch!=0);
 }
 else
   printf("Password and User Name Are Not Matched\n");
}
void adm_add()
{
	struct product;
	FILE *fp;
	fp=fopen("products.txt","a");
	printf("\n\tEnter Product Number ::");
	scanf("%s",product.number);
	setbuf(stdin,NULL);
	printf("\n\t Enter Product Name  ::");
	scanf("%s",product.name);
	setbuf(stdin,NULL);
	printf("\n\t Enter Price of Product ::");
	scanf("%d",&product.price);
	if(fp == NULL)
	{
	    printf("\n Error In Opening File....");
	}
	else
	{
		fprintf(fp,"\n%s %s %d \n",product.number,product.name,product.price);
		printf("Record Inserted ! ...... \n");
		fclose(fp);
	}
}
void adm_delete()
{
	FILE *fpt,*fptr;
	struct product;
	int found=0;
	char name[20];
	fpt=fopen("products.txt","r");
	if(fpt==NULL)
	{
		printf("\n Error In Opening File....");
	}
	fptr=fopen("temp.txt","w");
	if(fptr==NULL)
	{
		printf("\n Error In Opening File....");
	}
	setbuf(stdin,NULL);
	printf("\n Enter Name In Uppercase  : ");
	scanf("%s",name);
	while(fscanf(fpt,"%s %s %d\n",product.number,product.name,&product.price)!=EOF)
	{
		if(product.name==0)
			break;
		if(strcmp(product.name,name)==0)
		{
			found=1;
		}
		else
		{
			fprintf(fptr,"%s ",product.number);
			fprintf(fptr,"%s ",product.name);
			fprintf(fptr,"%d ",product.price);
		}
	}
	fclose(fptr);
	fclose(fpt);
	if(found==0)
	{
		printf("\n\n\n *****************************************\n\n");
		printf("\n Record Not Found....");
		printf("\n\n\n *****************************************\n\n");
	}
	else
	{
		fpt=fopen("products.txt","w");
		if(fpt==NULL)
		{
			printf("\n Error In Opening File....");
		}
		fptr=fopen("temp.txt","r");
		if(fptr==NULL)
		{
			printf("\n Error In Opening File....");
		}
		while(fscanf(fptr,"%s %s %d \n",product.number,product.name,&product.price)!=EOF)
		{
			if(product.name==0)
				break;
			fprintf(fpt,"%s %s %d \n",product.number,product.name,product.price);
		}
		printf("\n Record Successfully Deleted...............................!\n");
		fclose(fptr);
		fclose(fpt);
	}
}
void adm_calculate()
{
	FILE *cart;
	int amount = 0,x,y;
	cart = fopen("user_cart.txt","r");
	if(cart == NULL)
	{
		printf("file does not found !");
		exit(1);
	}
	else
	{
		printf("NUMBER \tNAME \tPRICE\n");
		while( fscanf(cart,"%s %s %d \n",product.number,product.name,&product.price) != EOF )
		{
				printf("%s\t %s\t %d \n",product.number,product.name,product.price);
				amount=amount + product.price;
		}
				printf("\n\t Total Amount :: %d /-TK\n",amount);
                printf("Enter Amount Which Received From Customer: ");
                scanf("%d",&x);
                printf("Your Advanced Amount Is: %d/-TK\n\n",x-amount);
	}
	printf("\nTHANKS FOR VISITING US!!\n");
	return 0;
}
/*End Admin Function*/

void user_viewAll()
{
    char ch;
	FILE *fp;
	fp = fopen("products.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);
	}
	else
	{
		printf("Number \tName  \tPrice\n");
		while( fscanf(fp,"%s %s %d\n",product.number,product.name,&product.price) != EOF )
      		{
			printf("%s \t%s \t%d \n",product.number,product.name,product.price);
		    }
	}
}

/*START adding selected item to the user cart */
void user_order()
{
   struct product;
	FILE *fp;
	FILE *cart;//user cart file
	int flag=0,chup;
	char ch[20];
	fp = fopen("products.txt","r");
    printf("*** -------------------------------------------- ***\n");
	printf("NUMBER \tNAME \tPRICE\n");
	while( fscanf(fp,"%s %s %d\n",product.number,product.name,&product.price) != EOF )
    printf("%s \t%s \t%d \n",product.number,product.name,product.price);
    printf("*** -------------------------------------------- ***");
	printf("\n\t Enter Product Name ::");
	scanf("%s",ch);
	chup=strupr(ch);
	fp = fopen("products.txt","r");
	cart = fopen("user_cart.txt","a");
	if(fp == NULL)
	{
		printf("File Does Not Found !");
		exit(1);
	}
	else
	{
		while(fscanf(fp,"%s %s %d\n",product.number,product.name,&product.price) != EOF)
		{
			if(strcmp(product.name,chup) == 0)
			{	flag=1;
				printf("\n \n");
				printf("\n\t\tNumber ::%s",product.number);
				printf("\n\t\tProduct Name ::%s",product.name);
				printf("\n\t\tCost of Product ::%d",product.price);
				fprintf(cart,"%s %s %d \n",product.number,product.name,product.price);
				printf("\n\n\tItem Added To cart! \n");
			}
		}
		if(flag == 0)
			printf("\nRecord Not Found\n");
	}
	fclose(cart);
	fclose(fp);
}
/*Code For Search Needed Product*/
void search_product() //Search Using Product Name
{
	struct product;
	FILE *fp;
	FILE *cart;
	int flag=0,findproduct2,name2;
	char findproduct[20],ans,name[20];
	printf("Enter Product Name ::");
	scanf("%s",findproduct);
	findproduct2=strupr(findproduct);
	fp = fopen("products.txt","r");
	cart = fopen("user_cart.txt","a");
	if(fp == NULL)
	{
		printf("File Does Not Found !");
		exit(1);
	}
	else
	{
		while(fscanf(fp,"%s %s %d \n",product.number,product.name,&product.price) != EOF)
		{
			if(strcmp(product.name,findproduct2) == 0)
			{	flag=1;
				printf("\n\t\tNumber ::%s",product.number);
				printf("\n\t\tProduct Name ::%s",product.name);
				printf("\n\t\tCost of Product ::%d",product.price);
			}
		}
		if(flag == 0)
			printf("\nRecord Not Found\n");
	}
	fclose(cart);
	fclose(fp);
}
int count_cart_product()
{
	char ch;
	FILE *cart;
	int i,count = 0;
	cart = fopen("user_cart.txt ","r");
	if(cart == NULL)
	{
		printf("File Does Not Found !");
		exit(1);
	}
	else
	{
		while( fscanf(cart,"%s %s %d \n",product.number,product.name,&product.price) != EOF )
		{
				count=count + 1;
		}
				return count;
	}
	fclose(cart);
}
void user_viewCart()
{
	char ch;
	FILE *cart;
	int i,amount = 0;
	cart = fopen("user_cart.txt","r");
	if(cart == NULL)
	{
		printf("File Does Not Found !");
		exit(1);
	}
	else
	{
		while( fscanf(cart,"%s %s %d \n",product.number,product.name,&product.price) != EOF )
		{
				printf(" %s %s %d \n",product.number,product.name,product.price);
				amount=amount + product.price;
		}
				printf("\n\t Total Amount :: %d /-TK",amount);
	}
}
void empty_cart()
{
	FILE *filter;
	filter = fopen("user_cart.txt","w");
	char name[20],number[20];
	int price;
	if(filter == NULL)
	{
		printf("File Does Not Found !");
		exit(1);
	}
	else
	{
		while( fscanf(filter,"%s %s %s %d %s \n",product.number,product.name,&product.price) != EOF )
		{
			fprintf(filter,"%s %s %d\n",number,name,price);
		}
	}
	fclose(filter);
}
