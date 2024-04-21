#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct product
{
    int id;
    char product_name[30];
    int remain;
    float price;
};

struct cart
{
    int id;
    char product_id[30];
    char product_name[30];
    float price;
    float sum;
    char coupon[30];
    float final_sum;
    int user_id;
};

struct user
{
    int id;
    char name[30];
    char address[30];
    char phone_number[15];
};

struct order
{
    int id;
    char product_id[30];
    char product_name[30];
    float price;
    float final_sum;
    char payment[100];
    char status[30];
    int user_id;
    int cart_id;
};



// Hàm thêm sản phẩm mới
void addProduct(struct product **products, int *productCount, int id, char *name, int remain, float price) {
    *products = (struct product *)realloc(*products, (*productCount + 1) * sizeof(struct product));
    (*products)[*productCount].id = id;
    strcpy((*products)[*productCount].product_name, name);
    (*products)[*productCount].remain = remain;
    (*products)[*productCount].price = price;
    (*productCount)++;
    printf("Da them san pham moi thanh cong.\n");
}

// Hàm cập nhật thông tin sản phẩm
void updateProduct(struct product *products, int productCount, int id, int new_remain, float new_price) {
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            products[i].remain = new_remain;
            products[i].price = new_price;
            printf("Cap nhat thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay hoa don co ID tuong ung.\n");
}

// Hàm xóa sản phẩm
void deleteProduct(struct product **products, int *productCount, int id) {
    int found = 0;
    for (int i = 0; i < *productCount; i++) {
        if ((*products)[i].id == id) {
            for (int j = i; j < *productCount - 1; j++) {
                (*products)[j] = (*products)[j + 1];
            }
            (*productCount)--;
            found = 1;
            printf("Da xoa thanh cong.\n");
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay hoa don co ID tuong ung.\n");
    }
}

// Hàm cập nhật giỏ hàng
void updateCart(struct cart *carts, int cartCount, int id, float new_final_sum) {
    for (int i = 0; i < cartCount; i++) {
        if (carts[i].id == id) {
            carts[i].final_sum = new_final_sum;
            printf("Da cap nhat thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay hoa don co ID tuong ung.\n");
}

// Hàm xóa giỏ hàng
void deleteCart(struct cart **carts, int *cartCount, int id) {
    int found = 0;
    for (int i = 0; i < *cartCount; i++) {
        if ((*carts)[i].id == id) {
            for (int j = i; j < *cartCount - 1; j++) {
                (*carts)[j] = (*carts)[j + 1];
            }
            (*cartCount)--;
            found = 1;
            printf("Da xoa thanh cong.\n");
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay hoa don co ID tuong ung.\n");
    }
}

// Hàm cập nhật hóa đơn
void updateOrder(struct order *orders, int orderCount, int id, char *new_status) {
    for (int i = 0; i < orderCount; i++) {
        if (orders[i].id == id) {
            strcpy(orders[i].status, new_status);
            printf("Cap nhat thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay hoa don co ID tuong ung.\n");
}

// Hàm xóa hóa đơn
void deleteOrder(struct order **orders, int *orderCount, int id) {
    int found = 0;
    for (int i = 0; i < *orderCount; i++) {
        if ((*orders)[i].id == id) {
            for (int j = i; j < *orderCount - 1; j++) {
                (*orders)[j] = (*orders)[j + 1];
            }
            (*orderCount)--;
            found = 1;
            printf("Da xoa thanh cong.\n");
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay hoa don co ID tuong ung.\n");
    }
}

  int main() {
    struct product *products = NULL;
    int productCount = 0;

    struct cart *carts = NULL;
    int cartCount = 0;

    struct user *users = NULL;
    int userCount = 0;

    struct order *orders = NULL;
    int orderCount = 0;

    int choice;
    do {
        printf("\n====== MENU ======\n");
        printf("1. Them san pham moi\n");
        printf("2. Cap nhat thong tin san pham\n");
        printf("3. Xoa san pham\n");
        printf("4. Cap nhat gio hang\n");
        printf("5. Xoa gio hang");
        printf("6. Cap nhat hoa don\n");
        printf("7. Xoa hoa don\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban :");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int id, remain;
                float price;
                char name[30];
                printf("Nhap ID san pham: ");
                scanf("%d", &id);
                printf("Nhap ten san pham : ");
                scanf("%s", name);
                printf("Nhap so luong con lai : ");
                scanf("%d", &remain);
                printf("Nhap gia san pham: ");
                scanf("%f", &price);
                addProduct(&products, &productCount, id, name, remain, price);
                break;
            }
            case 2: {
                int id, new_remain;
                float new_price;
                printf("Nhap ID san pham can cap nhat : ");
                scanf("%d", &id);
                printf("Nhap so luong moi: ");
                scanf("%d", &new_remain);
                printf("Nhap gia moi: ");
                scanf("%f", &new_price);
                updateProduct(products, productCount, id, new_remain, new_price);
                break;
            }
            case 3: {
                int id;
                printf("Nhap ID san pham can xoa : ");
                scanf("%d", &id);
                deleteProduct(&products, &productCount, id);
                break;
            }
            case 4: {
                int id;
                float new_final_sum;
                printf("Nhap ID gio hang can cap nhat : ");
                scanf("%d", &id);
                printf("Nhap tong gia moi : ");
                scanf("%f", &new_final_sum);
                updateCart(carts, cartCount, id, new_final_sum);
                break;
            }
            case 5: {
                int id;
                printf("Nhap ID gio hang can xoa : ");
                scanf("%d", &id);
                deleteCart(&carts, &cartCount, id);
                break;
            }
            case 6: {
                int id;
                char new_status[30];
                printf("Nhap ID hoa don can cap nhat : ");
                scanf("%d", &id);
                printf("Nhap hoa don moi:  ");
                scanf("%s", new_status);
                updateOrder(orders, orderCount, id, new_status);
                break;
            }
            case 7: {
                int id;
                printf("Nhap ID hoa don can xoa : ");
                scanf("%d", &id);
                deleteOrder(&orders, &orderCount, id);
                break;
            }
            case 0:
                printf("Thoat chuong trinh. \n");
                break;
            default:
                printf("Khong ton tai.\n");
                break;
        }
    } while (choice != 0);

    // Giải phóng bộ nhớ đã cấp phát
    free(products);
    free(carts);
    free(users);
    free(orders);

    return 0;
}