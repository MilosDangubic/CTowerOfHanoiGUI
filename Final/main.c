/*

 * main.c
 *
 *  Created on: 20.06.2018.
 *      Author: Korisnik
 */
#include <stdio.h>
#include "kbgi_files/kbgi_lib.h"

#define MAX_HIGHT 480
#define MAX_WEIGHT 640
#define MAX_DISK_NUMBER 5

struct Disk
{
	int x0;
	int y0;
	int x1;
	int y1;

	int rod;
	int position;
	int reduce;
};






void UpdateDisks(struct Disk *p, int diskNumber,int stepW,int diskW,int diskH,int reduce)
{
	int temp=diskNumber;
	while(temp!=0)
	{
					(*p).x0=(*p).rod*stepW-diskW+(*p).reduce*reduce ;
					(*p).y0=MAX_HIGHT-(*p).position*diskH;
					(*p).x1=(*p).rod*stepW+diskW-(*p).reduce*reduce;
					(*p).y1=MAX_HIGHT-((*p).position-1)*diskH;
					p++;
					temp--;


	}

}

void UpdateDisk(int *positionFrom,int *positionTo, int rodFrom,int rodTo, struct Disk *p,int diskNumber)
{
	int temp=diskNumber;

	while(temp!=0)
	{
		if ((*p).position==(*positionFrom) && (*p).rod==rodFrom)
		{
			(*p).rod=rodTo;
			(*p).position=(*positionTo)+1;



		}
		p++;
		temp--;

	}



}

void Draw(struct Disk *p, int diskNumber, int leftRod, int middleRod, int rightRod)
{
	int tempDiskNumber=diskNumber;
	K_SetFillColor(0, KBGI_YELLOW);
		K_Rectangle(0,leftRod-5,100,leftRod+5,480);
		K_Rectangle(0,middleRod-5,100,middleRod+5,480);
		K_Rectangle(0,rightRod-5,100,rightRod+5,480);
		K_SetFillColor(0, KBGI_RED);
	while(tempDiskNumber!=0)
	{
		if((*p).position>=0)
		{
			K_Rectangle(0,(*p).x0,(*p).y0,(*p).x1,(*p).y1);
			tempDiskNumber--;
		}
		p++;

	}
	K_Wait(1000);
}

// C recursive function to solve tower of hanoi puzzle
void towerOfHanoi(int diskNumber, int left, int right, int middle,struct Disk *p,int *leftRodSize,int *rightRodSize, int *middleRodSize,int stepW,int diskW,int diskH,int reduce,int leftRod,int rightRod, int middleRod,int size)
{

    if (diskNumber == 1)
    {
       // printf("\n Move disk 1 from rod %c to rod %c", leftRod, rightRod);


    	UpdateDisk(leftRodSize,rightRodSize,left,right,p,size);
    	(*leftRodSize)--;
    	(*rightRodSize)++;
    	UpdateDisks(p,size,stepW, diskW, diskH, reduce);
    	K_Clear(0,KBGI_BLACK);
    	Draw(p,size,leftRod,middleRod,rightRod);



        return;
    }


    towerOfHanoi(diskNumber-1, left, middle, right,p,leftRodSize,middleRodSize,rightRodSize, stepW, diskW, diskH, reduce,leftRod,rightRod,middleRod,size);

   // printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    	UpdateDisk(leftRodSize,rightRodSize,left,right,p,size);
    	(*leftRodSize)--;
        (*rightRodSize)++;
		K_Clear(0,KBGI_BLACK);
		UpdateDisks(p,size,stepW, diskW, diskH, reduce);
		Draw(p,size,leftRod,middleRod,rightRod);







    towerOfHanoi(diskNumber-1, middle, right, left,p,middleRodSize,rightRodSize,leftRodSize,stepW, diskW, diskH, reduce,leftRod,rightRod,middleRod,size);
    /*
    UpdateDisk(leftRodSize,rightRodSize,left,right,p,size);
    	(*leftRodSize)--;
    	  (*rightRodSize)++;
    	K_Clear(0,KBGI_BLACK);
    	UpdateDisks(p,size,stepW, diskW, diskH, reduce);
    	Draw(p,size,leftRod,middleRod,rightRod);
    	*/
}

int main()
{
	K_kbgi();
	K_SetFillColor(0, KBGI_RED);
	K_OpenWindow(0,"Test");
	K_SetDrawColor(0, KBGI_BLUE);
	K_SetFillColor(0, KBGI_YELLOW);


	int diskNumber;
	int diskNumberBackUp;
	do
	{
		fflush(stdout);
		setbuf(stdout, NULL);
		printf("Unesite broj diskova\n");
		scanf("%d",&diskNumber);

		diskNumberBackUp=diskNumber;
	}while(diskNumber<0 || diskNumber>MAX_DISK_NUMBER);

	struct Disk diskovi[diskNumber];
	struct Disk *p;
	p=&diskovi[0];


	//Crtanje stapova
	int stepW=MAX_WEIGHT/4;
	int diskH=30;
	int diskW=70;
	int reduce=15;

	int leftRod=stepW;
	int middleRod=2*stepW;
	int rightRod=3*stepW;

	K_SetFillColor(0, KBGI_YELLOW);
	K_Rectangle(0,leftRod-5,100,leftRod+5,480);
	K_Rectangle(0,middleRod-5,100,middleRod+5,480);
	K_Rectangle(0,rightRod-5,100,rightRod+5,480);
	K_SetFillColor(0, KBGI_RED);


	//Postavljane diskova na levi stap



	for(int i=0; i<diskNumber;i++)
		{
			diskovi[i].position=i+1;
			diskovi[i].rod=1;
			diskovi[i].reduce=i;
			diskovi[i].x0=diskovi[i].rod*stepW-diskW+diskovi[i].reduce*reduce ;
			diskovi[i].y0=MAX_HIGHT-(diskovi[i].position)*diskH;
			diskovi[i].x1=diskovi[i].rod*stepW+diskW-diskovi[i].reduce*reduce;
			diskovi[i].y1=MAX_HIGHT-(diskovi[i].position-1)*diskH;


			K_Rectangle(0,diskovi[i].x0,diskovi[i].y0,diskovi[i].x1,diskovi[i].y1);
		}


	//UpdateDisks(p,diskNumber,stepW,diskW,diskH,reduce);
	K_Clear(0,KBGI_BLACK);
	p=&diskovi[0];

	Draw(p,diskNumber,leftRod,middleRod,rightRod);

		int lrs=diskNumber;
		int mrs=0;
		int rrs=0;

		int *leftRodSize, *middleRodSize,*rightRodSize;
		leftRodSize=&lrs;
		middleRodSize=&mrs;
		rightRodSize=&rrs;



		int size=diskNumber;
	towerOfHanoi(diskNumber,1,3,2,p,leftRodSize,rightRodSize,middleRodSize,stepW,diskW,diskH,reduce,leftRod,rightRod,middleRod,size);



	K_WaitAllClose();
	return 0;


}
