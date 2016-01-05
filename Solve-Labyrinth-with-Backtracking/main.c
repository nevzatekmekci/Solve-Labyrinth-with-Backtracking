//
//  main.c
//  Solve-Labyrinth-with-Backtracking
//
//  Created by nevzat ekmekçi on 24/12/15.
//  Copyright © 2015 nevzat ekmekçi. All rights reserved.
//

#include <stdio.h>
#define MAX_STACK_SIZE 100
#define FALSE 0
#define BOYUT 8
#define TRUE 1
#define CIKIS_SUTUN 6
#define CIKIS_SATIR 6
/* stack size belirlendi
 true ve false tanımlandı
 çıkış satır ve sütun konumu verildi*/

typedef struct{
    int yatay;
    int dikey;
}DIRECTION;
//yön değişkeni tanımlandı
typedef struct {
    int satir;
    int sutun;
    int yon;
}STACK;
int boyut,K,L,top=-1;
DIRECTION hareket[4] = {{-1,0},{0,1},{1,0},{0,-1}};
STACK stack[MAX_STACK_SIZE];

/*
 printf("Matris boyutunu veriniz\n");
 scanf("%d",&boyut);
 */

int labyrinth[BOYUT+2][BOYUT+2]={
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,0,0,1,1,1,1},
    {1,0,1,0,1,1,1,1,1,1},
    {1,1,0,1,1,1,1,1,1,1},
    {1,0,1,1,0,1,1,1,1,1},
    {1,1,0,0,1,0,1,1,1,1},
    {1,1,1,1,1,1,0,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
};
int markedLabyrinth[BOYUT][BOYUT];
int main(int argc, const char * argv[]) {

    printf("Çıkış noktasının X ve Y koordinatlarını veriniz\n");
    scanf("%d %d",&K,&L);
    
    int i,yon,bulundu=FALSE;
    stack[0].satir=1;
    stack[0].sutun=1;
    stack[0].yon=1;
    markedLabyrinth[1][1]=1;
    top=0;
    
    //yığıt boşalmadıkça ve çıkış bulunmadıkça dön.
    while ((top<0)&&(!(stack[top].satir==K && stack[top].sutun==L))) {
        i=0;
        while (labyrinth[stack[top].satir+hareket[i][0]][stack[top].sutun+hareket[i][1]]==1) {
            
        }
    }
      //dolaşacağımız labirent
    return 0;
}
void yolBul(void){
    short int satir,sutun,y_satir,y_sutun;
    //sati ve sutun o an bulunulan pozisyonu tutacak
    //y_satir ve y_sutun ise gidilecek yeni pozisyonu tutacak

    //ilk konuma hareket edildi
    while(top&amp;gt;-1 &amp;amp;&amp;amp; !bulundu;){
        konum=pop(yigit,&amp;amp;top);
        satir=konum.satir;
        sutun=konum.sutun;//hangi satır ve sutundan
        yon=konum.yon;//hangi yönde kalmıştık
        
        while(yon&amp;lt;8 &amp;amp;&amp;amp; !bulundu){
            //bütün yönlere bakılıp herhangi bir yöne
            //hareket edilemediyse ve çıkış bulunduysa
            //döngüden çık
            y_satir=satir+hareket[yon].dikey;
            y_sutun=sutun+hareket[yon].yatay;
            
            if(y_satir=CIKIS_SATIR &amp;amp;&amp;amp; y_sutun=CIKIS_SUTUN)
                bulundu=1;//cikis bulundu
            else if(labirent[y_satir][y_sutun] &amp;amp;&amp;amp; gezildi[y_satir][y_sutun]){
                //eğer yeni pozisyon duvar değil ve daha önceden
                //ziyaret edilmediyse hareket et
                gezildi[y_satir][y_sutun]=1;
                konum.satir=satir;
                konum.sutun=sutun;
                //yeni konuma gelmeden önceki konumu yığıta ekle
                konum.yon=++yon;
                //bir sonraki yön bilgisini yığıta ekle
                //çünkü geri dönüldüğünde aramaya bir sonraki
                //yönden devam edilecek
                push(yigit,&amp;amp;top,konum);
                satir=y_satir;
                sutun=y_sutun;
                yon=0;
                //yeni konum hareket noktası olarak güncellendi
            }
            else ++yon;
            //bu konuma hareket edilmiyor bir sonraki yöne git
        }//tüm yönler denendi bir adım geri dön
    }//yığıt boşaldığında yada çıkış bulunduğunda döngüden çıkılacak
    if(bulundu){
        //eğer bulunduysa stack yazdırılacak
        printf(&amp;quot;\nizlenen yol:\nsatir sutun\n&amp;quot;);
        for(i=0;i&amp;lt;=top,i++)
            printf(&amp;quot;\n%d %d&amp;quot;,yigit[i].satir,yigit[i].sutun);
        printf(&amp;quot;\n%d %d&amp;quot;,satir,sutun);
        printf(&amp;quot;\n%d %d&amp;quot;,CIKIS_SATIR,CIKIS_SUTUN);
    }else printf(&amp;quot;Cikis yolu bulunamadi!\n&amp;quot;);
}
