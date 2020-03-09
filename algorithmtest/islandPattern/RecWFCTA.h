#ifndef RECWFCTA_H
#define RECWFCTA_H
#include <TMath.h>
#include <TMinuit.h>
class RecWFCTA{
  private:
      static int Npix;
      static int NpixInner;
      static int Npe[1024];
      static int Npmt[1024];
      static double MeanX;
      static double MeanY;
      static double SigmaX;
      static double SigmaY;
      static double Skewness;
      double CleanImage[1024];
      double Rp, Corex, Corey, rectheta, recphi;
      double DSize, DMeanX, DMeanY, DLength, DWidth, DDelta, DAlpha, DDist, DMiss;
      double DSourceX, DSourceY, DAngleDist;
      double DPenear,DPefar,DPixnear,DPixfar;
      double PhoMax, RMax;
      double DPepointing,DPemean,DPixmean,DPixpointing;
      double MaxPe, SecondPe, ThridPe, GradientMax, GradientMean, GradientRMS;
      double DRbar, DERbar, DRMSx, DRMSy, DRMSr;
      double  Edgemax;
      int Edgepmt;
      static const double (*pmtmap)[2];
      const double (*Image)[5];
      const double Focus;
      const double Pix;
      const double Dpmt;
      const double MAXDIST;
      const double NPEMIN;

  private:
    double Tel_A,Tel_Z;
    double matrix[3][3];
    TMinuit *minuit; 

  private:
      void Calc();
      void mGradient();
      double Dist(Int_t ipix1, Int_t ipix2);
      int ImageClean();
      int IslandImageClean();
      int GetCleanTube(int itube1, double *pe, int *itube0 );
      void GetCleanImage();
      Double_t GetDist(int tube,double sourcex,double sourcey);
      int mSetImage();

      void GetEulerMatrix();
      void Euler(double x0, double y0, double z0, double *x, double *y, double *z);
      double Dis2core(double corex, double corey, double x, double y, double the, double phi);
   public:
      RecWFCTA();
      double ImageInit();
      void Running();
      void SetPointing(double TelZ,double TelA);
      int SetImage(double (*image)[5]){Image = (const double(*)[5])image;};
      void SetPMTMap(double (*map)[2]){pmtmap = (const double(*)[2])map;};      
      void SetArrivalPosition(double the, double phi);
      void SetCore(double x,double y);

  public:
      Double_t GetRp() const {return Rp;};
      Double_t GetSourceX() const {return DSourceX;};
      Double_t GetSourceY() const {return DSourceY;};
      Int_t GetNpixAfterClean() const { return Npix;};
      Double_t GetImageAfterClean(double *cleanimage) {for(int i=0;i<1024;i++) cleanimage[i] = CleanImage[i];};
      Double_t GetSize()  const { return DSize;   };
      Double_t GetMeanX()  const { return DMeanX;  };
      Double_t GetMeanY()  const { return DMeanY;  };
      Double_t GetLength() const { return DLength; };
      Double_t GetWidth()  const { return DWidth;  };
      Double_t GetDelta()  const { return DDelta;  }; 
      Double_t GetAlpha()  const { return DAlpha;  };
      Double_t GetDist()  const { return DDist; };
      Double_t GetDMiss() const { return DMiss; };
      Double_t GetDAngleDist() const { return DAngleDist; };
      Double_t GetX(double height) ;
      Double_t GetMaxPe() const { return MaxPe; };
      Double_t GetSecondPe() const { return SecondPe; }; 
      Double_t GetThridPe() const { return ThridPe; };
      Double_t GetGradientMax() const { return GradientMax; };
      Double_t GetGradientMean() const { return GradientMean; };
      Double_t GetGradientRMS() const { return GradientRMS; };
      Double_t GetEdgepmt() const { return Edgepmt; };
      Double_t GetEdgemax() const { return Edgemax; };
      Double_t GetPenear() const {   return DPenear;   };
      Double_t GetPefar() const { return DPefar;   };
      Double_t GetPixnear() const { return DPixnear;   };
      Double_t GetPixfar() const { return DPixfar;   };
      Double_t GetR() const { return DRbar;   };
      Double_t GetER() const { return DERbar;   };
      Double_t GetRMSx() const { return DRMSx;   };
      Double_t GetRMSy() const { return DRMSy;   };
      Double_t GetRMS() const { return DRMSr;   };

      Double_t GetPhoMax()  const { return PhoMax; };
      Double_t GetRMax()  const { return RMax;  };
      Double_t GetPepointing() const { return DPepointing;   };
      Double_t GetPemean() const { return DPemean;   };
      Double_t GetPixmean() const { return DPixmean;   };
      Double_t GetPixpointing() const { return DPixpointing;   };
};
#endif
