#include <iostream>
#include <algorithm>
#include "TMath.h"
#include "RecWFCTA.h"
using namespace std;

double RecWFCTA::MeanX;
double RecWFCTA::MeanY;
double RecWFCTA::SigmaX;
double RecWFCTA::SigmaY;
double RecWFCTA::Skewness;
int RecWFCTA::Npix;
int RecWFCTA::Npe[1024];
int RecWFCTA::Npmt[1024];
const double (*RecWFCTA::pmtmap)[2];

RecWFCTA::RecWFCTA():Focus(2870),Pix(32),Dpmt(26.9),MAXDIST(Dpmt+5),NPEMIN(30)
{
}

double RecWFCTA::GetDist(int tube, double sourcex, double sourcey)
{
  double dist;
  sourcex *= Focus;
  sourcey *= Focus; 
  dist = sqrt((pmtmap[tube][0]-sourcex)*(pmtmap[tube][0]-sourcex)
        +(pmtmap[tube][1]-sourcey)*(pmtmap[tube][1]-sourcey));  
  return dist;
}

double RecWFCTA::ImageInit()
{
   int i;
   for(i=0; i<Pix*Pix; i++){
      Npe[i] = 0;
      Npmt[i] = 0;
      CleanImage[i] = 0;
   }
   Npix = 0; 
}

int RecWFCTA::mSetImage()
{
  for(int i=0;i<Pix*Pix;i++)
  {
    if(Image[i][0]>=0&Image[i][1]>=NPEMIN)
    {
      Npe[Npix] = int(Image[i][1]);
      Npmt[Npix] = i;
      Npix++;
    }
  }
}


void RecWFCTA::SetPointing(double zenith,double azimuth)

{
  Tel_Z =zenith;//*TMath::DegToRad();
  Tel_A = azimuth;//*TMath::DegToRad();
  GetEulerMatrix();
}


void RecWFCTA::SetArrivalPosition( double theta, double phi)
{
  rectheta = theta;
  recphi = phi;
  double _l = sin(theta)*cos(phi);
  double _m = sin(theta)*sin(phi);
  double _n = sqrt(1-_l*_l-_m*_m);
  double l,m,n;
  Euler(_l,_m,_n,&l,&m,&n);
  double sourcex = -l;
  double sourcey = -m;
  DSourceX = sourcex*Focus;
  DSourceY = sourcey*Focus;
}


void RecWFCTA::SetCore(double x,double y)
{
  Corex = x;
  Corey = y;
}


Int_t RecWFCTA::ImageClean()
{
/*************By Llma************/

  int i, j, cnt;
  double distance;

  int  fnpixels;
  int  *fNpixfriends;

  fnpixels = Npix;
  fNpixfriends = new Int_t[fnpixels];

  cnt = 0;  
  for(i=0;i<fnpixels;i++) {
     cnt=0;
     for(j=0;j<fnpixels;j++) {
        if(i==j) continue;
        distance = Dist(i,j);
        if(distance<=MAXDIST) {
           cnt++;
        }
     }
     fNpixfriends[i]=cnt;
  }
   
  j = 0;
  for(i=0; i<fnpixels; i++){
    if(fNpixfriends[i]>=1){
      Npmt[j] = Npmt[i];
      Npe[j] = Npe[i];
      j++;
    }
  }
  Npix = j;

  /////////////////////////////////
  DPenear = 0.;
  DPefar =  0.;
  DPixnear = 0;
  DPixfar = 0;
  for(i=0; i<fnpixels; i++)
  {
    if(fNpixfriends[i]>=4)
    {
      DPenear += Npe[i];
      DPixnear ++;
    }
    if(fNpixfriends[i]>=1&fNpixfriends[i]<4)
    {
      DPefar += Npe[i];
      DPixfar ++;
    }
  }

  delete[] fNpixfriends;

}


Int_t RecWFCTA::IslandImageClean()
{
/*************By Biby************/

  double distance;
  int npix = Npix;
  int* fpixused = new int[npix];
  int pmtmaxid = 0;
  double npemax = 0;
  
  for(int i=0;i<npix;i++)
  {
    
    fpixused[i] = 0;
    if(Npe[i]>npemax) {npemax=Npe[i];pmtmaxid = i;}
  }
  fpixused[pmtmaxid] = 1;

  int cnt;
  while(1)
  {
    cnt = 0;
    for(int i=0;i<npix;i++)
    {
      if(fpixused[i]==0) continue;
      for(int j=0;j<npix;j++)
      {
        distance = Dist(i,j);
        if(distance<=MAXDIST&fpixused[j]==0) {fpixused[j]=1;cnt++;}
      }
    }
    if(cnt==0) break;
  }


  cnt = 0;
  for(int i=0;i<npix;i++)
  {
    if(fpixused[i]==1)
    {
      Npe[cnt]=Npe[i];
      Npmt[cnt]=Npmt[i];
      cnt++;
    }
  }
  Npix = cnt;

 /////////////////////////////
  DPenear = 0.;
  DPefar =  0.;
  DPixnear = 0;
  DPixfar = 0;
  for(int i=0;i<npix;i++)
  {
    if(fpixused[i]==1)
    {
      DPixnear++;
      DPenear += Npe[i];
    }
    else
    {
      DPixfar ++;
      DPefar += Npe[i];
    }
  }

  delete[] fpixused; 
}


Double_t RecWFCTA::Dist(Int_t ipix1, Int_t ipix2)
{
   Double_t x1, x2, y1, y2;
   Int_t pixID_1, pixID_2;
   pixID_1 = Npmt[ipix1];
   pixID_2 = Npmt[ipix2];
   x1 = pmtmap[pixID_1][0];
   y1 = pmtmap[pixID_1][1];
   x2 = pmtmap[pixID_2][0];
   y2 = pmtmap[pixID_2][1];
   Double_t distance = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
   return distance;
}


int RecWFCTA::GetCleanTube(int itube1, double *pe, int *itube0 )
{
  *itube0 = Npmt[itube1];
  *pe = Npe[itube1];
}

void RecWFCTA::GetCleanImage()
{
  int itube0;
  double pe;
  for(int i=0; i<Npix; i++)
  {
    GetCleanTube(i, &pe, &itube0 );
    CleanImage[itube0] = pe;
  }
}

void RecWFCTA::Calc()
{
  double x,y,npe;
  double mx = 0;
  double my = 0;
  double sx = 0;
  double sy = 0;
  double sxy = 0;
  double nn = 0;
  double r = 0;
  double a,b;
  double rbar,erbar,rmsr;
  double *edgepe = new double[Npix];

  Edgepmt=0;
  for(int i=0;i<Npix;i++)
  {
    x = pmtmap[Npmt[i]][0];
    y = pmtmap[Npmt[i]][1];
    npe = Npe[i];
    r = sqrt((x-mx)*(x-mx) + (y-my)*(y-my));
    rbar += r;
    erbar += r*npe;
    rmsr += r*r*npe;
    mx += x*npe;
    my += y*npe;
    sx += x*x*npe;
    sy += y*y*npe;
    sxy += x*y*npe;
    nn += npe;
    //Find the edgemax
    if(fabs(x)>405.0||fabs(y)>360)
    {
      edgepe[Edgepmt] = npe;
      Edgepmt++;
    }
  }
  if(Edgepmt>0) Edgemax = TMath::MaxElement(Edgepmt,edgepe);
  else Edgemax=0;

  mx /= nn;
  my /= nn;
  sx /= nn;
  sy /= nn;
  sxy /= nn;
  double cx = sx - mx*mx;
  double cy = sy - my*my;
  double cxy = sxy - mx*my;

  a = (cy-cx+sqrt((cy-cx)*(cy-cx)+4*cxy*cxy))/(2*cxy);
  b = my-a*mx;

  double ssx = (cx+2*a*cxy+a*a*cy)/(1+a*a);
  double ssy = (a*a*cx-2*a*cxy+cy)/(1+a*a);

  double delta = atan2(DSourceY-my,DSourceX-mx);
  if(delta<0) delta += TMath::TwoPi();

  DSize = nn;
  DMeanX = mx;
  DMeanY = my;
  DLength = sqrt(ssx);
  DWidth = sqrt(ssy);
  DDist = sqrt(mx*mx+my*my);
  DAngleDist = sqrt(pow(DSourceX-DMeanX,2)+pow(DSourceY-DMeanY,2));
  DMiss = b*cos(delta);
  DAlpha = asin(fabs(b)/(DDist*sqrt(1+a*a)));
  DDelta = delta;
  DRbar = rbar/nn;
  DERbar = erbar/nn;
  DRMSx = sqrt(cx);
  DRMSy = sqrt(cy);
  DRMSr = sqrt(rmsr/nn-DERbar*DERbar);
}


Double_t RecWFCTA::GetX(double height)
{
  
  double x;
  int i;
  double a[5] = {-186.555305,-94.919,0.61289,0.0,0.01128292};
  double b[5] = {1222.6562,1144.9069,1305.5948,540.1778,1};
  double c[5] = {994186.38,878153.55,636143.04,772170.16,1e9};

  if(height<=400000) { i = 0; x = a[i]+b[i]*exp(-height/c[i]);}

  if(height>400000&&height<=1000000) {i = 1; x = a[i]+b[i]*exp(-height/c[i]);}

  if(height>1000000&&height<=4000000) {i = 2; x = a[i]+b[i]*exp(-height/c[i]);}

  if(height>4000000&&height<=10000000) {i = 3; x = a[i]+b[i]*exp(-height/c[i]);}

  if(height>10000000) x = a[4]-b[4]*height/c[4];
  
  return x;      
}


bool complare(int a,int b)
{
  return a>b;
}

void RecWFCTA::mGradient()
{
  int i,j;
  MaxPe = 0.;
  SecondPe = 0.;
  ThridPe = 0.;

  double  *npes = new Double_t[Npix];
  for(i=0;i<Npix;i++) npes[i] = Npe[i];

  sort(npes,npes+Npix,complare);

  MaxPe = npes[0];
  SecondPe = npes[0] + npes[1] + npes[2];
  ThridPe = SecondPe + npes[3] + npes[4] + npes[5];

  int cnt = 0;
  double neighborPe = 0.;
  double gradient;
  double distance;
  GradientMax = -1.;
  GradientMean = 0.;
  GradientRMS = 0;
  for(i=0;i<Npix;i++)
  {
    cnt=0;
    neighborPe=0.;
    for(j=0;j<Npix;j++)
    {
      if(i==j) continue;
      distance = Dist(i,j);
      if(distance<=MAXDIST&&npes[j]<npes[i]) 
      {
        neighborPe += npes[j];
        cnt++;
      }
    }
    if(cnt>0) neighborPe /= cnt;
    gradient = neighborPe/npes[i];

    if(gradient>GradientMax) GradientMax = gradient;
    GradientMean += gradient;
    GradientRMS += gradient*gradient;
  }

  GradientMean /= Npix;
  GradientRMS = sqrt(GradientRMS/Npix - GradientMean*GradientMean);

}


void RecWFCTA::Running()
{
  mSetImage();
  //ImageClean();
  IslandImageClean();
  GetCleanImage();
  //Calc();
  //mGradient();

  //Rp =  Dis2core(Corex,Corey,-25,0,rectheta,recphi);
}


void RecWFCTA::GetEulerMatrix()
{
   Tel_Z *= TMath::DegToRad();
   Tel_A *= TMath::DegToRad();
   double cosz, sinz, cosa, sina;
   cosz = cos(Tel_Z);
   sinz = sin(Tel_Z);
   cosa = cos(Tel_A);
   sina = sin(Tel_A);
   matrix[0][0] = cosa*cosz;
   matrix[0][1] = sina*cosz;
   matrix[0][2] = -sinz;
   matrix[1][0] = -sina;
   matrix[1][1] = cosa;
   matrix[1][2] = 0;
   matrix[2][0] = cosa*sinz;
   matrix[2][1] = sina*sinz;
   matrix[2][2] = cosz;
}

void RecWFCTA::Euler(double x0, double y0, double z0, double *x, double *y, double *z)
{

   *x = matrix[0][0]*x0+matrix[0][1]*y0+matrix[0][2]*z0;
   *y = matrix[1][0]*x0+matrix[1][1]*y0+matrix[1][2]*z0;
   *z = matrix[2][0]*x0+matrix[2][1]*y0+matrix[2][2]*z0;

}

double RecWFCTA::Dis2core(double corex, double corey, double x, double y, double the, double phi)
{
   int i;
   double dx,dy,u[3],v[3];
   double L,Rp,temp,psi;
   dx=corex-x; dy=corey-y;
   u[0]=sin(the)*cos(phi); u[1]=sin(the)*sin(phi); u[2]=cos(the);
   L=sqrt(dx*dx+dy*dy);
   v[0]=dx/L; v[1]=dy/L; v[2]=0.;
   temp=0.;
   for(i=0;i<3;i++) temp +=-(u[i]*v[i]);
   psi=acos(temp);
   Rp=L*sin(psi);
   return Rp;
}
