/*EKLENECEKLER 
--> MENÜLER ARASÝ DOLAÞMAYI YAP
*/
void anamenu();
void ogrencibilgimenusu();
#include <stdio.h>
#include <string.h>
#include <conio.h>
int secim,secim1,secim2;
int ogrencisayisi,derssayisi;
char ogrenciismi[10];
int n=1;
struct derst{
	float toplam;
}derstoplam[10];
struct ders{
	char dersadi[10];
	int vize,final;
	float gecmenotu;
}derskodu[10];
struct ogrencibilgileri{
	char ad[10],soyad[10];
	int no;
	float nottoplam;
	struct ders derskodu[10];
}ogrenci[50];
ogrencibilgilerial(){
	ogrenci[50].nottoplam=0;
	printf("Kac ogrenci oldugunu yaziniz: "); scanf("%d",&ogrencisayisi);
	printf("Kac ders oldugunu yaziniz: "); scanf("%d",&derssayisi);
	for(int i=0;i<ogrencisayisi;i++){
		printf("%d. Ogrencinin Adi: ",i+1); scanf("%s",&ogrenci[i].ad);
		printf("%d. Ogrencinin Soyadi: ",i+1); scanf("%s",&ogrenci[i].soyad);
		printf("%d. Ogrencinin Numarasi: ",i+1); scanf("%d",&ogrenci[i].no);
		for(int j=0;j<derssayisi;j++){
			printf("Derskodu: %d\n",j+1);
			printf("Dersin Adini Yaziniz: "); scanf("%s",&ogrenci[i].derskodu[j].dersadi);
			printf("%s Dersinin Vize Notu: ",ogrenci[i].derskodu[j].dersadi); scanf("%d",&ogrenci[i].derskodu[j].vize);
			printf("%s Dersinin Final Notu: ",ogrenci[i].derskodu[j].dersadi); scanf("%d",&ogrenci[i].derskodu[j].final);
			ogrenci[i].derskodu[j].gecmenotu=(ogrenci[i].derskodu[j].vize*0.4)+(ogrenci[i].derskodu[j].final*0.6);
			ogrenci[i].nottoplam+=ogrenci[i].derskodu[j].gecmenotu;
			}
		}
	}
	dersortalamasi(){
	int sayac=0;
	while(sayac<derssayisi){
	for(int k=0;k<derssayisi;k++){
		for(int i=0;i<ogrencisayisi;i++){
		    for(int j=0;j<derssayisi;j++){
		    	while(k==sayac && j==sayac){
		    		derstoplam[k].toplam+=ogrenci[i].derskodu[j].gecmenotu;
		    		break;
				}
			}
	    } 
	}
	sayac++;
   }
	return 0;
}
ogrencibilgilerikaydi(){
	ogrenci[50].nottoplam=0;
	for(int i=0;i<ogrencisayisi;i++){
		printf("\n%d. Ogrenci: \n",i+1);
		printf("Ad: %s\n",ogrenci[i].ad);
		printf("Soyad: %s\n",ogrenci[i].soyad);
		printf("Numara: %d\n",ogrenci[i].no);
		for(int j=0;j<derssayisi;j++){
			printf("\n%s: \n",ogrenci[i].derskodu[j].dersadi);
			printf("Vize: %d\n",ogrenci[i].derskodu[j].vize);
			printf("Final: %d\n",ogrenci[i].derskodu[j].final);
			printf("Gecmenotu: %.2f\n",ogrenci[i].derskodu[j].gecmenotu);
		}
		printf("Not Ortalamasi: %.2f\n",ogrenci[i].nottoplam/derssayisi);
	}
}
void dersbilgimenusu(){ //switch case yapýsýna cevir menuye dönmeyi ekle
		printf("Geri Gelmek Icin '0' a Basiniz.\n");
		for(int j=0;j<derssayisi;j++){
    			printf("  %d. %s\n",j+1,ogrenci[0].derskodu[j].dersadi);
			}
		scanf("%d",&secim2);
		if(secim2==0){
			anamenu();
		}
		while(n<=derssayisi){
			if(secim2==n){
			for(int i=0;i<ogrencisayisi;i++){
		printf("\n%d. Ogrenci: \n",i+1);
		printf("Ad: %s\n",ogrenci[i].ad);
		printf("Soyad: %s\n",ogrenci[i].soyad);
		printf("Numara: %d\n",ogrenci[i].no);
			printf("\n%s: \n",ogrenci[i].derskodu[n-1].dersadi);
			printf("Vize: %d\n",ogrenci[i].derskodu[n-1].vize);
			printf("Final: %d\n",ogrenci[i].derskodu[n-1].final);
			printf("Gecmenotu: %.2f\n",ogrenci[i].derskodu[n-1].gecmenotu);
			
	    }
			printf("\n%s Dersinin Ortalamasi: %.2f\n",ogrenci[0].derskodu[n-1].dersadi,derstoplam[n-1].toplam/ogrencisayisi);
			break;
		}
		else n++;
		}
}
void ogrencibilgimenusu(){
	printf("Geri Gelmek Icin '0' a Basiniz.\n");
	printf("   1.Butun Ogrencilerin Bilgileri.\n   2.Secili Ogrencinin Bilgileri.\n"); scanf("%d",&secim1);
	switch(secim1){
		case 0: anamenu(); break;
		case 1: ogrencibilgilerikaydi(); ogrencibilgimenusu(); break;
		case 2: printf("Ogrencinin Adini Yaziniz.\n"); scanf("%s",&ogrenciismi);
		for(int i=0;i<ogrencisayisi;i++){
		if(strcmp(ogrenciismi,ogrenci[i].ad)==0){
		printf("Ad: %s\n",ogrenci[i].ad);
		printf("Soyad: %s\n",ogrenci[i].soyad);
		printf("Numara: %d\n",ogrenci[i].no);
		for(int j=0;j<derssayisi;j++){
			printf("\n%s: \n",ogrenci[i].derskodu[j].dersadi);
			printf("Vize: %d\n",ogrenci[i].derskodu[j].vize);
			printf("Final: %d\n",ogrenci[i].derskodu[j].final);
			printf("Gecmenotu: %.2f\n",ogrenci[i].derskodu[j].gecmenotu);
		}
		printf("Not Ortalamasi: %.2f\n",ogrenci[i].nottoplam/derssayisi);
		break;
	}
    } ogrencibilgimenusu(); break;
	}
}
void anamenu(){
	printf("---------------------- A N A   M E N U ----------------------\n");
	printf("  1. Ogrenci Bilgileri\n  2. Ders Bilgileri\n"); scanf("%d",&secim);
	switch(secim){
		case 1: ogrencibilgimenusu(); break;
		case 2: dersbilgimenusu(); break; 
	}
}
int main(){
	ogrencibilgilerial();
	ogrencibilgilerikaydi();
	dersortalamasi();
	for(int i=0;i<derssayisi;i++){
			printf("\n%s Dersinin Ortalamasi: %.2f\n",ogrenci[i].derskodu[i].dersadi,derstoplam[i].toplam/ogrencisayisi);
	}
	anamenu();
	return 0;
}
