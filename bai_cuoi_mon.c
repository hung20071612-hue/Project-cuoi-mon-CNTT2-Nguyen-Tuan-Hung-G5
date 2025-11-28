#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

struct Room {
	char roomId[5];
	int type;
	double price;
	int status; 
};
struct Room list[MAX] = {
	{"101", 1, 350000, 1},
	{"234", 2, 400000, 1},
	{"135", 1, 200000, 1},
	{"132", 2, 300000, 0},
	{"173", 2, 670000, 1},
	{"720", 1, 540000, 1},
	{"479", 2, 720000, 1},
	{"179", 1, 150000, 2},
	{"610", 1, 270000, 1},
	{"528", 2, 360000, 0},
	{"427", 1, 580000, 1},
	{"821", 1, 710000, 1},
	{"900", 2, 930000, 0}
};
int n = 13;
struct Booking {
	char roomId[5];
	char customerName[50];
	int days;
	double totalCost;
	char bookId[20];
};
struct Booking list_book[MAX] = {
	{"132","Nguyen Van A",5,1500000}
};
int x = 1;
struct Date {
	int day;
	int month;
	int year;
};
struct Date date[MAX]={
	{12,10,2025}
};
int size = 1;
void display();
void add_room();
void update_room();
void lock_room();
void show_room();
void show_empty();
void sort_down();
void book_room();
int valid_date_case7(int day, int month, int year, int flag);
int main(){// 
	int choice;
	do{
		display();
		printf("moi ban nhap lua chon: ");
		scanf("%d",&choice);
		getchar();
		switch(choice){
			case 1:
				add_room();
				break;
			case 2:
				update_room();
				break;
			case 3:
				lock_room();
				break;
			case 4:
				show_room();
				break;
			case 5:
				show_empty();
				break;
			case 6:
				sort_down();
				break;
			case 7:
				book_room();
				break;
			case 8:
				break;
			default:
					printf("moi ban nhap lai!!!!\n");
				break;
		}
	}while(1);
	return 0;
}
void display(){// hien thi menu
	printf("+-----------------------------Mini Hotel-----------------------------+\n");
	printf("|1. Them phong moi                                                   |\n");
	printf("|2. Cap nhat phong                                                   |\n");
	printf("|3. Bao tri phong (khoa)                                             |\n");
	printf("|4. Hien thi danh sach                                               |\n");
	printf("|5. Tim kiem                                                         |\n");
	printf("|6. Sap xep danh sach phong (theo gia phong)                         |\n");
	printf("|7. Check-in (Giao dich)                                             |\n");
	printf("|8. Lich su thue                                                     |\n");
	printf("+--------------------------------------------------------------------+\n");
}
void add_room(){// them phong moi
	int flag = 1;
	do{
		flag = 1;
		printf("moi ban nhap so phong: ");
		fgets(list[n].roomId,sizeof(list[n].roomId),stdin);
		list[n].roomId[strcspn(list[n].roomId, "\n")] = 0;
		if(strlen(list[n].roomId) == 0){
			flag = 0;
			printf("Loi: so phong khong duoc de trong!\n");
			continue;
		}
		for(int i = 0; i < n ; i++){
			if(strcmp(list[n].roomId, list[i].roomId) == 0){
				flag = 0;
				printf("Loi: Phong %s da ton tai!\n",list[n].roomId);
				break;
			}
		}
	}while(flag != 1);
	do{
		printf("moi ban nhap loai phong (1/2): ");
		scanf("%d",&list[n].type);
		getchar();
		if(list[n].type != 1 && list[n].type != 2){
			printf("Loi: loai phong chi duoc chon 1(Don) hoac 2(Doi)!\n");
		}
	}while(list[n].type != 1 && list[n].type != 2);
	do{
		printf("moi ban nhap gia phong %s: ",list[n].roomId);
		scanf("%lf",&list[n].price);
		getchar();
		if(list[n].price <= 0){
			printf("Loi: Gia phong phai lon hon 0!\n");
			continue;
		}
	}while(list[n].price <= 0);
	list[n].status = 0;
	printf("Them phong thanh cong! Phong %s da duoc tao voi trang thai trong.\n",list[n].roomId);
	n++;
}
void update_room(){// cap nhat thong tin phong
	int flag = 0;
	char find_Id[10];
	do{
	printf("moi ban nhap so phong can cap nhat: ");
	fgets(find_Id, sizeof(find_Id), stdin);
	find_Id[strcspn(find_Id, "\n")] = 0;
	for(int i = 0; i < n; i++){
		if(strcmp(find_Id,list[i].roomId) == 0){
			printf("loai phong %s: %d\n",find_Id,list[i].type);
			printf("gia phong %s: %.0lf\n",find_Id,list[i].price);
			printf("Trang thai phong %s: %d\n",find_Id,list[i].status);
			flag = 1;
		do{
		printf("moi ban nhap loai phong (1/2) phong %s muon cap nhat: ",find_Id);
		scanf("%d",&list[i].type);
		getchar();
		if(list[i].type != 1 && list[i].type != 2){
			printf("Loi: loai phong chi duoc chon 1 hoac 2!\n");
			}
		}while(list[i].type != 1 && list[i].type != 2);
		do{
		printf("moi ban nhap gia phong %s muon cap nhat: ",list[i].roomId);
		scanf("%lf",&list[i].price);
		getchar();
		if(list[i].price <= 0){
			printf("Loi: Gia phong phai lon hon 0!\n");
			continue;
			}
		}while(list[i].price <= 0);
		printf("Cap nhat thong tin phong %s thanh cong!\n", list[i].roomId);
			}
		}
		if(flag == 0){
			printf("Loi: Khong tim thay phong %s!\n",find_Id);
			continue;
		}
	}while(flag != 1);
}
void lock_room(){// cap nhat phong khoa
	int flag = 0;
	char find_Id[10];
	printf("moi ban nhap so phong can bao tri: ");
	fgets(find_Id, sizeof(find_Id), stdin);
	find_Id[strcspn(find_Id, "\n")] = 0;
	for(int i = 0; i < n; i++){
		if(strcmp(find_Id,list[i].roomId) == 0){
			if(list[i].status == 1){
				flag = 1;
				printf("Loi: Phong %s dang co khach, khong the dua vao bao tri!\n",find_Id);
				break;
			}
			flag = 1;
			list[i].status = 2;
			printf("Da dua phong %s vao trang thai bao tri thanh cong!\n",find_Id);
		}
	}
	if(flag == 0){
		printf("Loi: khong tim thay phong %s!\n",find_Id);
	}
}
void show_room(){// hien danh sach phong
	int page_room = 1;
	int page_size = 10;
	if(n == 0){
		printf("Danh sach phong hien tai dang trong! Vui long them phong truoc.\n");
		return;
	}
	int result = n/page_size;
    int total_pages = (n % page_size == 0) ? result : result+1;
    do{
    	printf("moi ban chon trang 1->%d de xem: ",total_pages);
    	scanf("%d",&page_room);
    	getchar();
    	int start = (page_room - 1)*page_size;
    	int end = start + page_size;
    printf("+--------+-------------------------+--------------------+------------+\n");
    printf("|%-5s|%-25s|%-20s|%-12s|\n", "Ma phong", "Loai phong","Gia phong","Trang thai");
    printf("+--------+-------------------------+--------------------+------------+\n");
    for (int i = start; i < end && i < n; i++) {
        printf("|%-8s|%-25d|%-16.0lf VND|%-12d|\n", list[i].roomId, list[i].type, list[i].price, list[i].status);
    }
    printf("+--------+-------------------------+--------------------+------------+\n");
    printf("ban co muon thoat khong (y/n): ");
    char page = getchar();
    if(page == 'y' || page == 'Y'){
    	break;
	}
	}while(1);
}
void show_empty(){// hien thi phong trong cua tung loai phong
	int flag = 0;
	int cpy_type;
	do{
		printf("moi ban nhap loai phong (1/2) muon tim con trong: ");
		scanf("%d",&cpy_type);
		getchar();
		if(cpy_type != 1 && cpy_type != 2){
			printf("Loi: Vui long chon 1(don) hoac 2(doi)!\n");
		}
	}while(cpy_type != 1 && cpy_type != 2);
	for(int i = 0; i < n; i++){
		if(list[i].type == cpy_type && list[i].status == 0){
			flag = 1;
			}
		}
		if(flag == 0){
				(cpy_type == 1) ? printf("Hien tai khong co trong phong don\n") : printf("Hien tai khong co trong phong doi\n");
				return;
			}
	printf("+--------+-------------------------+--------------------+-----------+\n");
	printf("|%-8s|%-25s|%-20s|%-11s|\n", "Ma phong", "Loai phong","Gia phong","Trang thai");
	printf("+--------+-------------------------+--------------------+-----------+\n");
	for(int i = 0; i < n; i++){
		if(list[i].type == cpy_type && list[i].status == 0){
			printf("|%-8s|%-25d|%-16.0lf VND|%-11d|\n", list[i].roomId, list[i].type, list[i].price, list[i].status);
		}
	}
	printf("+--------+-------------------------+--------------------+-----------+\n");
}
void sort_down(){// sap xep phong theo gia giam dan
	if(n == 0){
		printf("Danh sach phong trong, khong can sap xep!");
		return;
	}
	char temp2[5];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - 1 - i; j++){
			if(list[j].price < list[j+1].price){
				//gan cac bien vao bien trung gian
				double temp1 = list[j].price;
				strcpy(temp2,list[j].roomId);
				int temp3 = list[j].type;
				int temp4 = list[j].status;
				//doi lai vi tri 
				list[j].price = list[j+1].price;
				strcpy(list[j].roomId,list[j+1].roomId);
				list[j].type = list[j+1].type;
				list[j].status = list[j+1].status;
				//tra lai gia tri can doi
				list[j+1].price = temp1;
				strcpy(list[j+1].roomId,temp2);
				list[j+1].type = temp3;
				list[j+1].status = temp4;
			}
		}
	}
	printf("Da sap xep danh sach phong theo gia giam dan thanh cong!\n");
	show_room();
}
void book_room(){// dat phong 
	int flag = 1;
	do{// kiem tra co thoa man khi nhap ma phong khong?
		int found = 0;
		flag = 1;
		printf("moi ban nhap so phong: ");
		fgets(list_book[x].roomId, sizeof(list_book[x].roomId), stdin);
		list_book[x].roomId[strcspn(list_book[x].roomId, "\n")] = 0;
			for(int i = 0; i < n ; i++){
				if(strcmp(list_book[x].roomId, list[i].roomId) == 0){
					found = 1;
					if(list[i].status == 1){
						flag = 0;
						printf("Loi: Phong %s da co khach!\n",list[i].roomId);
						break;
					}else if(list[i].status == 2){
						flag = 0;
						printf("Loi: Phong %s dang bao tri!\n",list[i].roomId);
						break;
					}
					list[i].status = 1;
				}
			}
		if(found == 0){
			flag = 0;
			printf("Loi: Khong tim thay phong %s!\n",list_book[x].roomId);
		}
	}while(flag != 1);
	do{
		flag = 1;
		printf("moi ban nhap ten khach hang: ");
		fgets(list_book[x].customerName,sizeof(list_book[x].customerName),stdin);
		list_book[x].customerName[strcspn(list_book[x].customerName, "\n")] = 0;
		if(strlen(list_book[x].customerName) == 0){
			printf("ten khanh hang khong duoc de trong!\n");
			flag = 0;
			continue;
		}
		break;
	}while(1);
	do{// kiem tra so ngay o
		printf("moi ban nhap so ngay o phong %s: ",list_book[x].roomId);
		scanf("%d",&list_book[x].days);
		getchar();
		if(list_book[x].days <= 0){
			printf("Loi: So ngay o phai lon hon 0!\n");
			continue;
		}
		break;
	}while(1);
	do{// kiem tra ngay nhan phong
		flag = 1; 
		printf("moi ban nhap ngay nhan phong %s (DD/MM/YYYY): ",list_book[x].roomId);
		scanf("%d/%d/%d",&date[size].day,&date[size].month,&date[size].year);
		getchar();
		flag = valid_date_case7(date[size].day,date[size].month,date[size].year,flag);
	}while(flag != 1);
	for(int i = 0; i < n; i++){
		if(strcmp(list_book[x].roomId, list[i].roomId) == 0){
			list_book[x].totalCost = list[i].price * list_book[x].days;
		}
	}
	sprintf(list_book[x].bookId,"%04d",rand() % 10000);//in ra ngau nhien ma phong
	printf("check-in thanh cong! Ma dat phong: %s\n",list_book[x].bookId);
	printf("+--------+-------------------------+--------------------+----------+----------------------+\n");
    printf("|%-8s|%-25s|%-20s|%-10s|%-22s|\n", "Phong", "Ten Khach","Ngay nhan","So ngay","Tong Tien");
     printf("+--------+-------------------------+--------------------+----------+----------------------+\n");
    printf("|%8s|%25s|%12d/%d/%d|%10d|%18.0lf VND|\n", list_book[x].roomId, list_book[x].customerName,date[size].day,date[size].month,date[size].year,list_book[x].days,list_book[x].totalCost);
    printf("+--------+-------------------------+--------------------+----------+----------------------+\n");
	x++;
	size++;
}
int valid_date_case7(int day, int month, int year, int flag){//kiem tra dieu kien khi nhap ngay nhan phong cua booking
	if(month <= 0 || month > 12 ){
		printf("Thang chi co tu 1->12 thoi!\n");
		flag = 0;
		return flag;
	}else if(year < 2025){
		printf("Khong the nhap nam truoc nam 2025!\n");
		flag = 0;
		return flag;
	}else if(year == 2025){
		if(month < 12){
			printf("Nam 2025 chi co the dat phong tu thang 12 tro di!\n");
			flag = 0;
			return flag;
		}
	}
	switch(month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(day <= 0 || day > 31){
				printf("Moi ban nhap lai so ngay co the co trong thang %d!\n",month);
				flag = 0;
				return flag;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(day <= 0 || day > 30){
				printf("Moi ban nhap lai so ngay co the co trong thang %d!\n",month);
				flag = 0;
				return flag;
			}
			break;
		case 2:
			if((year % 400 == 0)|| (year % 4 == 0 && year % 100 != 0)){
				if(day <= 0 || day > 29){
					printf("Moi ban nhap lai!\n");
					flag = 0;
					return flag;
				}
			}else{
				if(day <= 0 || day > 28){
					if(day == 29){
						printf("Nam %d khong phai nam nhuan, moi ban nhap lai!\n",year);
						flag = 0;
						return flag;
					}
					printf("Moi ban nhap lai so ngay co the co trong thang %d!\n",2);
					flag = 0;
					return flag;
				}
			}
		}
	flag = 1;
	return flag;
}

