#include<stdio.h>
#include<string.h>
#define MAX 100

struct Room {
	char roomId[5];
	int type;
	double price;
	int status; 
};
struct Room list[MAX] = {
	{"101", 1, 350000, 0},
	{"234", 2, 400000, 1},
	{"135", 1, 200000, 0},
	{"132", 2, 300000, 0},
	{"173", 2, 670000, 1},
	{"720", 1, 540000, 1},
	{"479", 2, 720000, 1},
	{"179", 1, 150000, 0},
	{"610", 1, 270000, 1},
	{"528", 2, 360000, 0},
	{"427", 1, 580000, 1},
	{"821", 1, 710000, 1},
	{"900", 2, 930000, 0}
};
int n = 13;
struct Booking {
	char bookId[20];
	char roomId[5];
	char customerName[50];
	int days;
	double totalCost;
};
void display();
void add_room();
void update_room();
void lock_room();
void show_room();
void show_empty();
int main(){
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
				break;
			case 7:
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
void display(){
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
			flag = 1;
		do{
		printf("moi ban nhap loai phong (1/2): ");
		scanf("%d",&list[i].type);
		getchar();
		if(list[i].type != 1 && list[i].type != 2){
			printf("Loi: loai phong chi duoc chon 1 hoac 2!\n");
			}
		}while(list[i].type != 1 && list[i].type != 2);
		do{
		printf("moi ban nhap gia phong %s: ",list[i].roomId);
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
    printf("+--------+-------------------------+--------------------+-----------+\n");
    printf("|%-5s|%-25s|%-20s|%-11s|\n", "Ma phong", "Loai phong","Gia phong","Trang thai");
    printf("+--------+-------------------------+--------------------+-----------+\n");
    for (int i = start; i < end && i < n; i++) {
        printf("|%-8s|%-25d|%-16.0lf VND|%-11d|\n", list[i].roomId, list[i].type, list[i].price, list[i].status);
    }
    printf("+--------+-------------------------+--------------------+-----------+\n");
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
	printf("+--------+-------------------------+--------------------+-----------+\n");
	printf("|%-5s|%-25s|%-20s|%-11s|\n", "Ma phong", "Loai phong","Gia phong","Trang thai");
	printf("+--------+-------------------------+--------------------+-----------+\n");
	for(int i = 0; i < n; i++){
		if(list[i].type == cpy_type && list[i].status == 0){
			flag = 1;
			printf("|%-8s|%-25d|%-16.0lf VND|%-11d|\n", list[i].roomId, list[i].type, list[i].price, list[i].status);
		}
	}
	printf("+--------+-------------------------+--------------------+-----------+\n");
	if(flag == 0){
		(cpy_type == 1) ? printf("Hien tai khong co trong phong don\n") : printf("Hien tai khong co trong phong doi\n");
	}
}
