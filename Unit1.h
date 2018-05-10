//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TChart *Chart1;
        TFastLineSeries *Series1;
        TFastLineSeries *Series2;
        TFastLineSeries *Series3;
        TFastLineSeries *Series4;
        TBitBtn *Button1;
        TBitBtn *Button2;
        TLabeledEdit *FoEdit;
        TLabeledEdit *PogrechnostEdit;
        TLabeledEdit *ApogrEdit;
        TLabeledEdit *WpogrEdit;
        TLabeledEdit *VpogrEdit;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
double A, Fwsp, Fwo, Fp, d, Amax;
int V, N, W, M, R, R1, Rb, Rmax, R2;
double Wsp[100], Wo[100];
double Wp0[1000], Wp10[1000], Wp1[1000], Wp11[1000], Wp2[1000], Wp12[1000],
              Wp3[1000], Wp13[1000], Wpb[1000], Wpmax[1000], Wpmin[1000], Wp[1000];

void FrequencyWSP()
{
   int i;

   V=1;
   Fwsp=A/V;
   N=0; i=0;
   while(Fwsp>=0.0374999999999)
         {
          if(Fwsp<=0.04250000001)
                                {
                           Wsp[i]=Fwsp;
                           i=i+1;
                           N=N+1;
                                }
          V=V+1;
          Fwsp=A/V;
         }
}

void FrequencyWO()
{
   int i;

   W=1;
   Fwo=A/W;
   i=0;
   M=0;
   while(Fwo>=0.02999999999)
          {
          Wo[i]=Fwo;
          i=i+1;
          M=M+1;
          W=W+1;
          Fwo=A/W;
          }
}

void FrequencyP()
{
 int i,j,k;

 k=0;
 R=0;
 for(i=0;i<M;i++)
        {
       for(j=0;j<N;j++)
                {
              Fp=Wo[i]+Wsp[j];
              if(Fp>=0.06999999999)
                        {
                   Wp[k]=Fp;
                   k=k+1;
                   R=R+1;
                        }
              Fp=Wo[i]-Wsp[j];
              if(Fp>=0.06999999999)
                        {
                   Wp[k]=Fp;
                   k=k+1;
                   R=R+1;
                        }
                }
       }
}

void OdEl() //����� ���������� ��������� �������
{
 int i,j;
 double de;

    for(i=0;i<R;i++){
         if(Wp[i]>0){
            for(j=i+1;j<R;j++)
                        {
                if(Wp[i]==Wp[j]) Wp[j]=0;
                de=Wp[i]-Wp[j];
                if(de<0) de=-de;
                if(de<0.000000001) Wp[j]=0;
                        }
                     }
                     }
   R1=0;
   j=0;
   for(i=0;i<R;i++)
        {
       if(Wp[i]>0)
                {
              Wp1[j]=Wp[i];
              j=j+1;
              R1=R1+1;
                }
        }
}

void inclear()
{
 int i,j;
 double p,p1;
//����� ������������ �������� ������� �� �����������
        Wpb[0]=Wp1[0];
        for(i=1;i<R1;i++){
              if(Wp1[i]<Wpb[0]) Wpb[0]=Wp1[i]; //����� ������������ ��������
                         }
    for(i=1;i<R1;i++)   //����������� �� ����������� ��������� ���������
        {
        p1=1;
        for(j=0;j<R1;j++)
                {
            p=Wp1[j]-Wpb[i-1];
            if(p>0)
                   {
                if(p<p1)
                        {
                   p1=p;
                   Wpb[i]=Wp1[j];
                        }
                   }
                }
        }
     Rb=R1;
}

void MAXMIN()
{
 int i,j;
 double dl,dl1,dp;

      for(i=0;i<Rb;i++)
                {
              dl=1;
              for(j=0;j<R1;j++)
                        {
                   dl1=Wpb[i]-Wp1[j];
                   if(dl1<0) dl1=-dl1;
                   if(dl1<dl)
                                {
                             dl=dl1;
                             dp=Wp1[j];
                                }
                        }
             if(dl>=0.000000001)
                        {
                       if(dp<Wpb[i])
                                {
                            if(Wpmin[i]!=0) if(Wpmin[i]>dp) Wpmin[i]=dp;
                            if(Wpmin[i]==0) Wpmin[i]=dp;
                                }
                       if(dp>Wpb[i])
                                {
                            if(Wpmax[i]!=0) if(Wpmax[i]<dp) Wpmax[i]=dp;
                            if(Wpmax[i]==0) Wpmax[i]=dp;
                                }
                        }
             if(dl<0.000000001)
                        {
                      if(Wpmin[i]!=0) if(Wpmin[i]>dp) Wpmin[i]=dp;
                      if(Wpmin[i]==0) Wpmin[i]=dp;
                        }
                }

}
//---------------------------------------------------------------------------
#endif