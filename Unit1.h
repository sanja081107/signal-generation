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
#include <BubbleCh.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TChart *Chart1;
        TFastLineSeries *Series1;
        TFastLineSeries *Series3;
        TFastLineSeries *Series4;
        TBitBtn *Button1;
        TBitBtn *Button2;
        TLabeledEdit *FoEdit;
        TLabeledEdit *PogrechnostEdit;
        TLabeledEdit *ApogrEdit;
        TLabeledEdit *WpogrEdit;
        TLabeledEdit *VpogrEdit;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TRadioButton *RadioButton3;
        TRadioButton *RadioButton4;
        TRadioButton *RadioButton5;
        TRadioButton *RadioButton6;
        TButton *Button3;
        TLabel *Label1;
        TListBox *ListBox1;
        TLabel *Label2;
        TButton *Button4;
        TButton *Button5;
        TButton *Button6;
        TButton *Button7;
        TEdit *ScaleY;
        TLabel *Label3;
        TEdit *ScaleX;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TStaticText *StaticText2;
        TButton *Button8;
        TEdit *ScaleXmin;
        TEdit *ScaleYmin;
        TFastLineSeries *Series2;
        TPointSeries *Series5;
        TButton *Button9;

        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall RadioButton1Click(TObject *Sender);
        void __fastcall RadioButton2Click(TObject *Sender);
        void __fastcall RadioButton3Click(TObject *Sender);
        void __fastcall RadioButton4Click(TObject *Sender);
        void __fastcall RadioButton5Click(TObject *Sender);
        void __fastcall RadioButton6Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
double A, Fwsp, Fwo, Fp, d, Amax, x01, x02;
int V, N, W, M, R, R1, Rb, Rmax, R2;
double Wsp[100], Wo[100];
double Wp0[1000], Wp10[1000], Wp1[1000], Wp11[1000], Wp2[1000], Wp12[1000],Wp3[1000],
       Wp13[1000], Wpb[1000], Wpmax[1000], Wpmin[1000], Wp[1000],MinX[1000000],MinY[1000000],
       MinXX[10000],MinYY[10000];

AnsiString str, str2;   //переменнsые для названия теекстовых документов

struct TZap{
     double s_x, s_y, s_nom;
     } Zap[200], p;

        int size = sizeof(TZap);
        FILE *myfile, *Fz, *Fs, *Obshchiy;
        char File_Zap[] = "zapisi.dat";

void FrequencyWSP()
{
   int i;

   V=1;
   Fwsp=A/V;
   N=0; i=0;
   while(Fwsp>=x01)
         {
         if(Fwsp<=x02)
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

void OdEl() //поиск одинаковых элементов мвссива
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
//далее расположение базового массива по возрастанию
        Wpb[0]=Wp1[0];
        for(i=1;i<R1;i++){
              if(Wp1[i]<Wpb[0]) Wpb[0]=Wp1[i]; //поиск минимального элемента
                         }
    for(i=1;i<R1;i++)   //расположние по возрастанию остальных элементов
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

void MAXMIN1()
{
 int i;

   for(i=0;i<Rb;i++)
        {
         if(Wpmax[i]==0) Wpmax[i]=Wpb[i];
         if(Wpmin[i]==0) Wpmin[i]=Wpb[i];
        }
}
//---------------------------------------------------------------------------
#endif
