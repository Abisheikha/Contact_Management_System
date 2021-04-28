/*Contact management system*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct contact
{
	char name[100],email[100],mobile_no[100];
}user[100],temp;
void add_contact();
void delete_contact();
void edit_contact();
void search();
void display();
void validate_contact_details();
int i=0,j=0,k;
char temp_name[100];
void add_contact()
{
	printf("Enter name: ");
	scanf("%s",&user[i].name);
	printf("Enter mobile number: ");
	scanf("%s",&user[i].mobile_no);
	printf("Enter email: ");
	scanf("%s",&user[i].email);
	validate_contact_details();
	i++;
}
void validate_contact_details()
{
	char temp_email[100],temp_mobile[100];
	int l=0,m=0,flag;
	j=0;
	/*-----------name validation-----------*/
	strcpy(temp_name,user[i].name);
	while(j<=i)
	{
		if((!(strcmp(temp_name,user[j].name)))&& i!=j)
		{
			printf("The name already exits in contacts,enter some other name..\n\n");
			main();
		}
		/*----------------------mobile number validation------------------*/
		strcpy(temp_mobile,user[i].mobile_no);
		if(i==j)
		{
			while(l<=i)
			{
				if((!(strcmp(temp_mobile,user[l].mobile_no)))&& i!=l)
				{
					printf("The mobile number already exits!!!\n\n");
					main();
				}
				if(strlen(temp_mobile)>12)
				{
					printf("Please enter valid mobile number..\n\n");
					main();
				}	
				if(l==i)
				{
					if((strlen(temp_mobile)==11 && temp_mobile[0]=='0')||(strlen(temp_mobile)==10 && temp_mobile[0]!='0')||(strlen(temp_mobile)==12 && (temp_mobile[0]=='9' && temp_mobile[1]=='1')))
					{
						k=0;
						while(temp_mobile[k]!='\0')
						{
							if(!(temp_mobile[k]>='0' && temp_mobile[k]<='9'))
								break;
							k++;
						}
						if(k!=strlen(temp_mobile))
						{
							printf("Please enter valid mobile number...\n\n");
							main();
						}
					}
					else
					{
						printf("Please enter valid mobile number...\n\n");
						main();
					}
				}
				l++;
			}
			/*------------------email validation--------------------*/
			strcpy(temp_email,user[i].email);
			k=0;
			while(k<=i)
			{
				if(strlen(temp_email)<5)
				{
					printf("Please enter valid email id...\n\n");
					main();
				}
				if((!(strcmp(temp_email,user[k].email))) && i!=k)
				{
					printf("The email id already exits,enter some other email address..\n\n");
					main();
				}
				k++;
			}
			if(i==k-1)
			{
				flag=0;
				while(temp_email[m]!='\0')
				{
					if(!(temp_email[m]>='A' && temp_email[m]<='Z'))
					{
						if(temp_email[m]=='@' && m>2 && (temp_email[m+1]>='a' && temp_email[m+1]<='z'))
							flag++;
						else if(temp_email[m]=='.' && (temp_email[m-1]>='a' && temp_email[m-1]<='z')&& (temp_email[m+1]>='a' && temp_email[m+1]<='z'))
							flag++;
					}
					else
					{
						printf("Please enter valid email with small letters..\n\n");
						main();
					}
					m++;
				}
				if(flag!=2 && m==strlen(temp_email))
				{
					printf("Please enter valid email..\n\n");
					main();
				}
				else
					printf("Contact added successfully!!!\n");
			}
		
		}
		j++;
	}
}
void delete_contact()
{
	printf("Enter the name of the contact to be deleted: ");
	scanf("%s",&temp_name);
	for(k=0;k<i;k++)
	{
		if(!(strcmp(temp_name,user[k].name)))
		{
			strcpy(user[k].name,"NULL");
			strcpy(user[k].mobile_no,"NULL");
			strcpy(user[k].email,"NULL");
			printf("Contact deleted successfully!!\n");
			break;
		}
	}
	if(i==k)
	{
		printf("The contact doesn't exists....\n");
	}
}
void edit_contact()
{
	printf("Enter name of contact to edit: ");
	scanf("%s",&temp_name);
	for(k=0;k<i;k++)
	{
		if(!(strcmp(temp_name,user[k].name)))
		{
			printf("\n-----Edit the %s contact:-----\n",user[k].name);
			printf("Enter name: ");
			scanf("%s",&user[k].name);
			printf("Enter mobile number: ");
			scanf("%s",&user[k].mobile_no);
			printf("Enter email: ");
			scanf("%s",&user[k].email);	
			break;
		}
	}
	if(k==i)
		printf("The contact doesn't exits....\n");
}
void search()
{
	printf("Enter name: ");
	scanf("%s",&temp_name);
	for(k=0;k<i;k++)
	{
		if(!(strcmp(temp_name,user[k].name)))
		{
			printf("\n------Contact details of %s------\n",user[k].name);
			printf("Name: %s\nMobile number: %s\nEmail Id: %s\n",user[k].name,user[k].mobile_no,user[k].email);
			break;
		}
	}
	if(k==i)
	{
		printf("The contact doesn't exits....\n");
	}
}
void sort()
{
	int k,l;
	for(k=0;k<i-1;k++)
	{
		for(l=k+1;l<i;l++)
		{
			if(strcmp(user[k].name,user[l].name)> 0)
			{
				temp=user[k];
				user[k]=user[l];
				user[l]=temp;
			}
		}
	}
}
void display()
{
	sort();
	printf("\n-------CONTACTS LIST-------\n\n");
	for(j=0;j<i;j++)
	{
		if((strcmp(user[j].name,"NULL")))
			printf("Name: %s\nMobile number: %s\nEmail Id: %s\n\n",user[j].name,user[j].mobile_no,user[j].email);
	}
	if(i==0)
	{
		printf("No contacts saved...\n");
	}
}
int main()
{
	int choice;
	printf("\tCONTACT MANAGEMENT\n");
	while(1)
	{
		printf("\n1.Add a contact\n2.Delete a contact\n3.Edit contact\n4.Search a contact\n5.Display contacts\n6.exit\n");
		printf("Enter choice: ");
		scanf("%d",&choice);
		printf("\n");
		switch(choice)
		{		
			case 1: 
			{
				add_contact();
				break;
			}
			case 2:
			{
				delete_contact();
				break;		
			}
			case 3:
			{
				edit_contact();
				break;		
			}
			case 4:
			{
				search();
				break;
			}
			case 5:
			{
				display();
				break;
			}
			case 6:
			{
				exit(1);
				break;
			}
			default:
			{
				printf("Invalid choice");
				break;
			}
		}
	}
	return 0;
}
