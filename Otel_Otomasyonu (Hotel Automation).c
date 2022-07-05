#include <stdio.h>
#include <stdlib.h>

typedef struct musteri
{
    char *ad;
    char *soyad;
    int *tcno;

} bilgileri;
typedef struct tarih
{
    int gun;
    int ay;
    int yil;
} t;
typedef struct oda
{
    int kackisilik;
    int odanumarasi;
    int odadurumu;
    int fiyatbilgisi;
    t giristarihi;
    t cikistarihi;
    bilgileri musterimiz;
} bilgisi;
void musteriekleme(bilgisi *odalarimiz);
int fiyathesapla(bilgisi *odalarimiz,int odanumarasi);
void kayitsilme(bilgisi *odalarimiz,int odanumarasi);
int gunsayisihesapla(t giristarihi,t cikistarihi);
void odadurumu(bilgisi *odalarimiz);
void odabilgisi(bilgisi *odalarimiz,int odano);
void fiyatbilgisi();
void tarihguncelleme(bilgisi *odalarimiz,int odanumarasi);



int main()
{
    int odasayisi=200,odano;
    int knowlodge;
    bilgisi *odalar;
    odalar=(bilgisi *)calloc(odasayisi,sizeof(bilgisi));
    printf("-------------------OTELIMIZE HOSGELDINIZ--------------------\n");
    printf(" -------------1,2 ve 4 kisilik odalarimiz mevcuttur------------\n");
    printf("  ----------Oda sayimiz 1 ile 200 arasindadir-----------------\n");
    printf("   --------Oda durumumuz 1 ise doludur , 2 ise bostur--------\n");
    printf("             -------TC no 6 hanelidir-------\n");
    printf("-----Gerceklestireceginiz islemleri soldaki sayi sirasina gore gerceklestirebilirsiniz-----\n");
    printf("\n\n");
    printf("1-->Musteri ekleme\n");
    printf("2-->Oda bilgisi alma\n");
    printf("3-->Oda durumu alma\n");
    printf("4-->Fiyat bilgisi alma\n");
    printf("5-->Cikis islemi\n");
    printf("6-->Uygulamadan cikma\n");
    printf("\n\n");


    while(knowlodge!=6)
    {
        printf("Uygulamada yapacaginiz secimi giriniz: ");
        scanf("%d",&knowlodge);

        switch(knowlodge)
        {
        case 1:
            musteriekleme(odalar);
            printf("\n\n");
            break;
        case 2:
            printf("Oda bilgisi almak icin oda numarasini soyleyiniz:");
            scanf("%d",&odano);
            odabilgisi(odalar,odano);
            printf("\n\n");
            break;
        case 3:
            odadurumu(odalar);
            printf("\n\n");
            break;
        case 4:
            fiyatbilgisi();
            printf("\n\n");
            printf("\nKayit yapalim mi : \n");
            printf("\nKayit icin 1'i tuslayiniz istemiyorsaniz baska islemler yapabilirsiniz: \n");
            break;
        case 5:
            printf("\nCikisini yapmak istediginiz oda numarasini giriniz: \n");
            scanf("%d",&odano);
            kayitsilme(odalar,odano);
            printf("\nYine bekleriz\n");
            break;
        case 6:
            free(odalar);
            printf("\n\n");
            printf("-----Uygulamamizi kullandiginiz icin tesekkurler-----\n");
            break;
        default:
            break;
        }

    }

    return 0;
}

void musteriekleme(bilgisi *odalarimiz)
{
    int k;
    char musteriadi[15];
    char musterisoyadi[15];
    int tcno;
    int kontrol;
    printf("Oda numarnizi seciniz: ");
    scanf("%d",&kontrol);
    if(odalarimiz[kontrol-1].odadurumu!=0)
    {
        printf("Odamiz rezervasyonludur isterseniz baska bir odaya kaydinizi yapabilirim\n");
        return 0;
    }
    odalarimiz[kontrol-1].odanumarasi=kontrol;

    printf("Musterinin adini ve soyadini giriniz:");
    scanf("%s %s",&musteriadi,&musterisoyadi);
    printf("Musterinin tc'nosunu giriniz:");
    scanf("%d",&tcno);
    odalarimiz[kontrol-1].musterimiz.ad=(char *)malloc(sizeof(char)*strlen(musteriadi));
    odalarimiz[kontrol-1].musterimiz.soyad=(char *)malloc(sizeof(char)*strlen(musterisoyadi));
    odalarimiz[kontrol-1].musterimiz.tcno=(int *)malloc(sizeof(int)*6);
    strcpy(odalarimiz[kontrol-1].musterimiz.ad,musteriadi);
    strcpy(odalarimiz[kontrol-1].musterimiz.soyad,musterisoyadi);
    odalarimiz[kontrol-1].musterimiz.tcno=tcno;

    printf("Simdi kac kisilik odada kalacaginizi seciniz: ");
    scanf("%d",&odalarimiz[kontrol-1].kackisilik);
    printf("Giris tarihini girin ");
    scanf("%d/%d/%d",&odalarimiz[kontrol-1].giristarihi.gun,&odalarimiz[kontrol-1].giristarihi.ay,&odalarimiz[kontrol-1].giristarihi.yil);
    printf("Cikis tarihini girin ");
    scanf("%d/%d/%d",&odalarimiz[kontrol-1].cikistarihi.gun,&odalarimiz[kontrol-1].cikistarihi.ay,&odalarimiz[kontrol-1].cikistarihi.yil);

    odalarimiz[kontrol-1].fiyatbilgisi=fiyathesapla(odalarimiz,kontrol);
    printf("Toplam tutariniz-->%d TL\n",odalarimiz[kontrol-1].fiyatbilgisi);

    printf("Kayit islemlerini tamamlamak istermisiniz Evet ise '2'yi Hayir ise '3'u tuslayiniz: \n");
    scanf("%d",&k);

    if(k==2)
    {
        odalarimiz[kontrol-1].odadurumu=1;
    }
    else if(k==3)
    {
        kayitsilme(odalarimiz,kontrol);
    }


}
int fiyathesapla(bilgisi *odalarimiz,int odanumarasi)
{
    int kackisi,toplam,fiyat;
    int gun=gunsayisihesapla(odalarimiz[odanumarasi-1].giristarihi,odalarimiz[odanumarasi-1].cikistarihi);
    printf("Kalacaginiz gun sayisi %d gun\n",gun);
    int x=odalarimiz[odanumarasi-1].kackisilik;
    if(x==1)
    {
        fiyat=gun*200;
    }
    else if(x==2)
    {
        fiyat=gun*150;
    }
    else if(x==4)
    {
        fiyat=gun*100;
    }

    return fiyat;
}


void kayitsilme(bilgisi *odalarimiz,int odanumarasi)
{
       int i;

        odalarimiz[odanumarasi-1].odadurumu=0 ;
        for(i=0; i<odanumarasi; i++)
        {
            odalarimiz[odanumarasi-1].musterimiz.ad=(char *)calloc(sizeof(char),15);
            odalarimiz[odanumarasi-1].musterimiz.soyad=(char *)calloc(sizeof(char),15);
            odalarimiz[odanumarasi-1].musterimiz.tcno=(int *)calloc(sizeof(int),6);
        }
        printf("%d numarali odamizin cikis islemi tamamlanmistir\n",odanumarasi);
}

int gunsayisihesapla(t giristarihi,t cikistarihi)
{
    if(giristarihi.gun>cikistarihi.gun)
    {
        cikistarihi.ay-=1;
        cikistarihi.gun+=30;
    }
    else if(giristarihi.ay>cikistarihi.ay)
    {
        cikistarihi.yil-=1;
        cikistarihi.ay+=12;
    }
    t farkimiz;
    farkimiz.gun=cikistarihi.gun-giristarihi.gun;
    farkimiz.ay=cikistarihi.ay-giristarihi.ay;
    farkimiz.yil=cikistarihi.yil-giristarihi.yil;

    int gunsayimiz=farkimiz.gun + farkimiz.ay*30 + farkimiz.yil*365;
    return gunsayimiz;

}

void odadurumu(bilgisi *odalarimiz)
{
    int i,odasayisi=200;
    for(i=0; i<odasayisi; i++)
    {
        if(odalarimiz[i].odadurumu!=0)
        {
            printf("-----------------------------------------------\n");
            printf("Oda numarasi-->%d\n",odalarimiz[i].odanumarasi);
            printf("Musterimizin adi , soyadi ve tc'si-->%s %s %d\n",odalarimiz[i].musterimiz.ad,odalarimiz[i].musterimiz.soyad,odalarimiz[i].musterimiz.tcno);
            printf("Kac kisilik odada kaldigi-->%d\n",odalarimiz[i].kackisilik);
            printf("Fiyat bilgisi-->%d TL\n",odalarimiz[i].fiyatbilgisi);
            printf("Giris tarihi-->%d/%d/%d\n",odalarimiz[i].giristarihi.gun,odalarimiz[i].giristarihi.ay,odalarimiz[i].giristarihi.yil);
            printf("Cikis tarihi-->%d/%d/%d\n",odalarimiz[i].cikistarihi.gun,odalarimiz[i].cikistarihi.ay,odalarimiz[i].cikistarihi.yil);
            printf("-----------------------------------------------\n");

        }
    }
}
void odabilgisi(bilgisi *odalarimiz,int odano)
{
    if(odalarimiz[odano-1].odadurumu!=0)
    {
        printf("%d numarali oda %d/%d/%d tarihine kadar doludur.\n",odano,odalarimiz[odano-1].cikistarihi.gun,odalarimiz[odano-1].cikistarihi.ay,odalarimiz[odano-1].cikistarihi.yil);

    }
    else
    {
        printf("%d numarali oda bostur isterseniz kayit icin islem yapabilirsiniz: \n",odano);
    }
}
void fiyatbilgisi()
{
    int kackisilik,kalacaginizgunsayisi;
    int fiyat;
    t giristarihi,cikistarihi;
    printf("\n1,2 ve 4 kisilik odalarimiz mevcuttur kac kisilik oda isterseniz\n");
    printf("Kac kislik odada kalacaginizi seciniz: ");
    scanf("%d",&kackisilik);
    printf("Giris tarihini girin ");
    scanf("%d/%d/%d",&giristarihi.gun,&giristarihi.ay,&giristarihi.yil);
    printf("Cikis tarihini girin ");
    scanf("%d/%d/%d",&cikistarihi.gun,&cikistarihi.ay,&cikistarihi.yil);
    kalacaginizgunsayisi=gunsayisihesapla(giristarihi,cikistarihi);
    if(kackisilik==1)
    {
        fiyat=kalacaginizgunsayisi*200;
    }
    else if(kackisilik==2)
    {
        fiyat=kalacaginizgunsayisi*150;
    }
    else if(kackisilik==4)
    {
        fiyat=kalacaginizgunsayisi*100;
    }
    printf("Toplam tutariniz : %dTL\n",fiyat);

}



