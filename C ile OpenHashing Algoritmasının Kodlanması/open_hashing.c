#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

/* Linked List'de öğe saklamak için düğüm oluşturuluyor. */
struct dugum
{
    int key;
    int value;
    struct dugum *next;

};
 /* Hash tablosunda bir Linked List depolanıyor. */
 struct dizi_oge 
 {    /* Hash tablosuna bağlı Linked List'in kuyruk elemanı tanımlanıyor. */
     struct dugum * kuyruk;
     /* Hash tablosuna bağlı Linked List'in baştaki elemanı tanımlanıyor. */ 
     struct dugum * bas_index;
     
 };
 struct dizi_oge*dizi;
 /* Hash tablosu elemanlarının sayısı belirleniyor */
 int boyut=0; 
 /* Hash tablosunun maksimum kapasitesi belirleniyor */
 int max = 10;
 /* Her anahtara karşılık gelen index belirleniyor */
 struct hash_tablo(int key)
 {
     return (key % max);
 }

struct dugum* eleman_ekle(struct node *list,int index_bul);
void eleman_sil (int key);
void tekrarlama();
void yeni_dizi();

void ekle(int key,int value)
{
 float n=0.0;
 int index=hash_tablo(key);

 /* Verilen index Linked List'ten çıkarılıyor */
 struct dugum *list=(struct dugum*) dizi[index].bas_index;
 
 /* Hash tablosuna eklenecek öğe oluşturuluyor */
struct dugum *item=(struct dugum*) malloc(sizeof(struct dugum));
item ->key=key;
item ->next=NULL;
item ->value=value;

if (liste==NULL)
{
   /*Hash tablosunda Linked List yoksa */
   printf("%d(key) ve %d(value) ekleniyor. \n" , key,value);
   dizi[index].bas_index=item;
   dizi[index].kuyruk=item;
   boyut++;
}
else
{
    /*Hash tablosunda mevcut bir Linked List varsa */
    int index_bul=bul(list,key);
    if(index_bul== -1)
    {
       /* Anahtar Linked List'te bulunamamıştır.Linked List'in sonuna anahtar ekleniyor. */
       dizi[index].kuyruk ->next = item;
       dizi[index].kuyruk = item;
       boyut++;
    }
      else
      {
           /* Anahtar Linked List'te mevcut. Mevcut olan değer güncelleniyor. */
           struct dugum *eleman=eleman_ekle(list,index_bul);
           eleman -> value = value;

           
      }
}
/*Yük faktörü hesaplanıyor */
n=(1.0*boyut) / max;
if(n >= 0.75)
{
/*Yeniden yazılyor */
printf("Yeniden yaz \n");
tekrarlama();
}
}
void tekrarlama()
{
  struct dizi_oge *temp=dizi;
  int i=0,n=max;
  boyut=0;
  max=2*max;

  /* Dizi öğesi yeni oluşturulan Hash Tablosuna atanır */
  dizi=(struct dizi_oge*) malloc(max * sizeof(struct dugum ));
  yeni_dizi();

  for(i=0; i<n ; i++)
  {
    /*Hash tablosundan i konumundaki Linked List çıkarılıyor */
    struct dugum* list = (struct dugum* ) temp[i].bas_index;

    if(list==NULL)
    {
      /* Linked List yoksa devam ediliyor */
      continue;

    }
    else
    {
      /*Linked List varsa liste sonuna kadar taşımaya ve erişmeye devam ediliyor,
      Bir anahtar ve değer alınır ve yeni Hash tablosuna eklenir. */

      while (list != NULL)
      {
        ekle(list -> key, list -> value);
        list=list ->next;
      }
      
      
    }
    
  }
  temp=NULL;
}
/* Bu fonskiyon verilen anahtarı Linked List'te bulur.İndeksini döndürür ve anahtar yoksa -1 değerini döndürür. */
int bul(struct dugum *list, int key)
{
  int donus = 0;
  struct dugum *temp=list;
  while(temp != NULL)
  {
    if (temp -> key==key)
    {
      return donus;
    }
    temp=temp -> next;
    donus++;
  }
  return -1;
}
/*Linked List'te bulunan düğüm eleman_bul değerine döndürülüyor. */
struct dugum* eleman_ekle(struct dugum* list, int eleman_bul)
{
  int i=0;
  struct dugum*temp=list;
  while (i !=eleman_bul)
  {
    temp=temp -> next;
    i++;
  }
  return temp;
}
/* !!!Hash tablosundan eleman çıkartılıyor!!! */
void eleman_sil(int key)
{
   int index = hashtablo(key);
   struct dugum *list =(struct dugum*) dizi[index].bas_index;

   if(list==NULL)
   {
     printf("Bu anahtar yok.");
   }
   else
   {
     int eleman_bul=bul(list, key);

     if(eleman_bul==-1)
     {
       printf("Bu anahtar yok.");
     }
     else
     {
       struct dugum *temp=list;
       if(temp -> key == key)
       {
          dizi[index].bas_index=temp ->next;
          printf("Bu anahtar kaldırıldı.");
          return;
       }
       while (temp -> next -> key !=key)
       {
         temp=temp ->next;
       }
       if(dizi[index].kuyruk==temp -> next)
       {
         temp -> next =NULL;
         dizi[index].kuyruk=temp;
       }
       else
       {
         temp ->next = temp ->next ->next;
       }
       printf("Bu anahtar kaldırıldı.");
       
     }
    
   }
   
}
/* Hash tablosu görüntüleniyor */
void goster()
{
  int i=0;
  for(i=0; i<max; i++)
  {
      struct dugum *temp=dizi[i].bas_index;
      if(temp==NULL)
      {
          printf("Dizi[%d] elemanı yok \n" , i);
      }
      else
      {
           printf("Dizi[%d] öğelerine sahip \n" , i);
           while (temp != NULL)
           {
              printf("key= %d  value= %d  \t" , temp ->key, temp ->value);
              temp=temp ->next;
           }
           printf("\n");
           
      }
      
  }
}
/* Hash tablosunu başlatmak için */
void yeni_dizi()
{
  int i = 0;
  for(i=0; i<max; i++)
  {
    dizi[i].bas_index=NULL;
    dizi[i].kuyruk=NULL;
  }
}
/* Hash tablosunun boyutu döndürülüyor */
int dizi_boyut()
{
  return boyut;
}
void main()
{
  int secim, key,value,n,k;
  clrscr();

  dizi=(struct dizi_oge* ) malloc(max *sizeof(struct dizi_oge*));
  yeni_dizi();

  do
  {
		printf("MENÜ: \n1.Öğeyi hash tablosuna ekleme"
                              "\n2.Öğeyi hash tablosundan çıkarma"
                              "\n3.Hash tablosunun boyutunu kontrol etme" 
                              "\n4.Hash tablosunu görüntüleyin"
		       "\n\n Lütfen seçim yapınız: ");

              
 		scanf("%d", & secim); 

        switch (secim)
        {
          case 1:
              printf("Hash tablosuna eleman ekleme\n");
		      printf("Anahtarı ve değeri girin:\t");
		      scanf("%d %d", &key, &value);
		      ekle(key, value);

              break;

          case 2:
              printf("Hash tablosunda silme  \n  Silinecek değeri girin:");
		      scanf("%d", &key);
		      eleman_sil(key);
              

             break;

          case 3:
               n = dizi_boyut();
		      printf("Hash tablosunun boyutu :%d \n", n);
 
		      break;

          case 4:
              
               goster();

               break;

           default:
             printf("Yanlış değer \n");
 
        }
        printf("\nDevam etmek istiyorsanız:(1'e basınız)\t");
		scanf("%d", &k);
 
 
  } while (k==1);
     getch();
  
}

