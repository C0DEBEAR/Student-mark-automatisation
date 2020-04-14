
// Muhammet Yusuf PIROGLU 			17010011089

#include <stdio.h>
#include <stdlib.h>

//														Ders bilgileri tutulan struct
typedef struct dersler{
	char ders_adi[15];
	int vize_notu;
	int final_notu;
}dersler;
//															Ogrenci bilgileri iceren struct
typedef struct ogrenci_bilgi{
	int numara;
	char ad[10];
	char soyad[10];
	int ders_sayisi;
	 dersler *ders;
}ogrenci_bilgi;
//															Kelime Uzunluk Bulma Fonsiyonu
int kelime_uzunlugu_bulma(char isim[10]){
	
	int i=0;
	
	while(isim[i] != 0){		
	i++;
	}
	
	return i;
}

//																Ogrenci Bulma Fonsiyonu
int Ogrenci_bul(char isim[20], ogrenci_bilgi *ogrenci1, int ogrenci_sayisi){
				
	int isim_uzunlugu = kelime_uzunlugu_bulma(isim);
	int i,j,k,a;
	int sayac=0;
	int bulunan=0,ortalama;
	
    for(i=0;i<ogrenci_sayisi;i++){
    	
    	int kayit_uzunluk = kelime_uzunlugu_bulma((ogrenci1+i)->ad);
    	
    	for(j=0;j<isim_uzunlugu;j++){
    		
    		if(isim[j] == (ogrenci1+i)->ad[j] && isim_uzunlugu == kayit_uzunluk){
                sayac++;
                
                if(sayac==isim_uzunlugu){
                	
                	bulunan=1;
	
                        printf("Numara : %d\nAd     : %s\nSoyad  : %s\n",(ogrenci1+i)->numara, (ogrenci1+i)->ad, (ogrenci1+i)->soyad);
            
                        if((ogrenci1+i)->ders_sayisi>0){
			
			            	printf("Dersler ve Durumlari\n ");
			    	
                               /* for(k=0;k<(ogrenci1+i)->ders_sayisi;k++){
                
			                        printf("%d-%s\n ",k+1, ((ogrenci1+i)->ders+k)->ders_adi);
									}*/
									for(k=0;k<(ogrenci1+i)->ders_sayisi;k++){
                					ortalama=(((ogrenci1+i)->ders+k)->vize_notu)*0.4+(((ogrenci1+i)->ders+k)->final_notu)*0.6;
                					if(ortalama >=60){
                						
                						printf("%d-%s		 Vize:%d  	 Final:%d   	 Ort:%d    	Durum:Gecti\n ",k+1, ((ogrenci1+i)->ders+k)->ders_adi,((ogrenci1+i)->ders+k)->vize_notu,((ogrenci1+i)->ders+k)->final_notu,ortalama);
									}
									else{
										
										printf("%d-%s		 Vize:%d  	 Final:%d   	 Ort:%d   	Durum:Kaldi\n ",k+1, ((ogrenci1+i)->ders+k)->ders_adi,((ogrenci1+i)->ders+k)->vize_notu,((ogrenci1+i)->ders+k)->final_notu,ortalama);
									}
			                        }
			                   }
			               
			               
					    else {
					    		printf("Ders Kaydi Bulunmamaktadir!\n");
						}
                	sayac=0;
                	printf("\n");}
				}
            	
				else continue;
				
				
			}
    		
		}
  	

	if(bulunan==0){
	
	printf("\n");
    printf("Aradiginiz kisi kayitta bulunamadi!\n");}
    printf("Devam etmek icin herhangi bir tusa basin.\n");
    getch(a);
    system("cls");
}

int kelime_uzunlugu_bul(char isim[20]){
	
	int i=0;
	while(isim[i] != 0){

		i++;

	}

	return i;
}


int main(int argc, char *argv[]) {
	// 															Struct Alma ve Atama
	int ogrenci_sayisi,i;
	char isim[20];
	 struct ogrenci_bilgi *ogrenci;
	 ogrenci = &ogrenci;
	 
	 struct  dersler *ders;
	 ders = &ders;
		
		printf("Ogrenci Sayisi  :");
	scanf("%d",&ogrenci_sayisi);
	system("cls");
	ogrenci=(ogrenci_bilgi *)malloc(ogrenci_sayisi*sizeof(ogrenci_bilgi));
	for(i=0;i<ogrenci_sayisi;i++){
		printf("%d.Numara       :",i+1);
		scanf("%d",&(ogrenci+i)->numara);
		printf("%d.Ad           :",i+1);
		scanf("%s",&(ogrenci+i)->ad);
		printf("%d.Soyad        :",i+1);
		scanf("%s",&(ogrenci+i)->soyad);
		printf("%d.Ders Sayisi  :",i+1);
		scanf("%d",&(ogrenci+i)->ders_sayisi);
		((ogrenci+i)->ders)=(dersler *) malloc((ogrenci+i)->ders_sayisi * sizeof(dersler));
			int j=0;
			for(j;j<(ogrenci+i)->ders_sayisi;j++){
				system("cls");
				printf("%d.Ders Adi  :",j+1);
				scanf("%s",&((ogrenci+i)->ders+j)->ders_adi);
				printf("%d.Vize Notu :",j+1);
				scanf("%d",&((ogrenci+i)->ders+j)->vize_notu);
				printf("%d.Final Notu:",j+1);
				scanf("%d",&((ogrenci+i)->ders+j)->final_notu);
				system("cls");
				}	
	
	}
	
	
	//														Menu
	system("cls");
	while(1){
		int secim;
		printf("\t\t\t\t#MENU\n\n");
		printf("[1]Ogrenci Ara\n[2]Durum Goster\n[3]Listele\n[4]Cikis\n\nIslem:");
		scanf("%d",&secim);
		switch(secim){
			
			case 1:				
					//									Ogrenci Ara
				system("cls");
				printf("Aranacak Isim:");
				scanf("%s",&isim);
				Ogrenci_bul( isim,ogrenci,ogrenci_sayisi);				
				break;
				case 2:
					//											Durum Goster
					system("cls");
					int i,k,a,ortalama;
					for(i=0;i<ogrenci_sayisi;i++){
    	
    				   	
    		
    		printf("\n\n[%d] %s %s\n------------------------------------\n",((ogrenci+i)->numara), ((ogrenci+i)->ad), ((ogrenci+i)->soyad));
            
                        if((ogrenci+i)->ders_sayisi>0){
			
			            	printf("Ders ve Durumlari:\n ");
			    	
                                for(k=0;k<(ogrenci+i)->ders_sayisi;k++){
                					ortalama=(((ogrenci+i)->ders+k)->vize_notu)*0.4+(((ogrenci+i)->ders+k)->final_notu)*0.6;
                					if(ortalama >=60){
                						
                						printf("%d-%s\t\t:Gecti\n ",k+1, ((ogrenci+i)->ders+k)->ders_adi);
									}
									else{
										
										 	printf("%d-%s\t\t:Kaldi%\n ",k+1, ((ogrenci+i)->ders+k)->ders_adi);
									}
			                        }
			                        
			               }
					    else {
					    		printf("\n\nDers Kaydi Bulunmamaktadir!\n");
					    		 
						}
				
				
			
    		
		}
					 printf("Devam etmek icin herhangi bir tusa basin.\n");
				    getch(a);
				    system("cls");
					break;
					
					case 3:
						//								Listele
						system("cls");
						int x,k1,a1,ortalama1;
					for(x=0;x<ogrenci_sayisi;x++){
    	
    				   	
    		
    		printf("\n\n[%d] %s %s\n------------------------------------\n",((ogrenci+x)->numara), ((ogrenci+x)->ad), ((ogrenci+x)->soyad));
            printf("Ders Sayisi:%d\n",((ogrenci+x)->ders_sayisi));
                        if((ogrenci+x)->ders_sayisi>0){
			
			            	printf("Dersler ve Durumlari:\n ");
			    	
                                for(k1=0;k1<(ogrenci+x)->ders_sayisi;k1++){
                					ortalama1=(((ogrenci+x)->ders+k1)->vize_notu)*0.4+(((ogrenci+x)->ders+k1)->final_notu)*0.6;
                					if(ortalama1 >=60){
                						
                						printf("%d-%s		 Vize:%d  	 Final:%d   	 Ort:%d    	Durum:Gecti\n ",k1+1, ((ogrenci+x)->ders+k1)->ders_adi,((ogrenci+x)->ders+k1)->vize_notu,((ogrenci+x)->ders+k1)->final_notu,ortalama1);
									}
									else{
										
										printf("%d-%s		 Vize:%d  	 Final:%d   	 Ort:%d   	Durum:Kaldi\n ",k1+1, ((ogrenci+x)->ders+k1)->ders_adi,((ogrenci+x)->ders+k1)->vize_notu,((ogrenci+x)->ders+k1)->final_notu,ortalama1);
									}
			                        }
			                        
			               }
					    else {
					    		printf("\n\nDers Kaydi Bulunmamaktadir!\n");
					    		 
						}
				
				
			
    		
		}
					 printf("Devam etmek icin herhangi bir tusa basin.\n");
				    getch(a1);
				    system("cls");
					break;
						
						
						
						
						
						break;
						case 4:
							//								Cikis
							return 0;
							break;
		}
		
	}
	
	
	
	return 0;
}
