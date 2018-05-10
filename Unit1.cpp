//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#include <conio.h>
#include <fstream>
#pragma hdrstop
#include <stdio.h>

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
int k,l;
FILE *myfile;

   A=1;
   Rmax=0;
   d=0.000001;
   while(A>=0.5){
             FrequencyWSP();
             FrequencyWO();
             FrequencyP();
             OdEl();
             if(R1>Rmax){
                 Rmax=R1;
                 Amax=A;
                         }
              A=A-0.000001;
                }
   A=Amax;
   FrequencyWSP();
   FrequencyWO();
   FrequencyP();
   OdEl();
   inclear();
   if(Amax<1){
      A=1;
      while(A>Amax){
           FrequencyWSP();
           FrequencyWO();
           FrequencyP();
           OdEl();
           MAXMIN();
           A=A-0.000001;
                    }
               }
   A=Amax-0.000001;
   while(A>=0.5){
           FrequencyWSP();
           FrequencyWO();
           FrequencyP();
           OdEl();
           MAXMIN();
           A=A-0.000001;
                }
  void MAXMIN1();
  for(k=0;k<Rb;k++){
        Wp3[k]=(Wpmax[k]+Wpmin[k])/2;
        Wp13[k]=((Wpmax[k]-Wp3[k])/Wp3[k])*100;
                   }
  for(k=0;k<Rb;k++){
      Series4->AddXY(Wp3[k],Wp13[k],"",clBlack);
                   }
   l=0;

  myfile = fopen("rezult.txt", "w");

  if(Wp13[0]<Wp13[1])
                        {
                        fprintf(myfile, "%lf %lf %d\n", Wp13[0], Wp3[0], l);
                        l=l+1;
                        }
  for(k=1;k<Rb-1;k++)
        if((Wp13[k]<Wp13[k-1]) && (Wp13[k]<Wp13[k+1]))
                        {
                        fprintf(myfile, "%lf %lf %d\n", Wp13[k], Wp3[k], l);
                        l=l+1;
                        }
  if(Wp13[Rb-1]<Wp13[Rb-2])
                        {
                        fprintf(myfile, "%lf %lf %d\n", Wp13[Rb-1], Wp3[Rb-1], l);
                        l=l+1;
                        }
   fclose(myfile);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
double Fgmin, Fgmax, dFg, Fo, Fbmin, Fbmax, Fbomin, Fomin;
double ddo, d, Fg, Fbo, Fb, F1, d1, F2, d2, d3, d4;
int i,w,v,Ipogr,Wpogr,Vpogr,Vpogr1,Wpogr1;

  Fgmin=0.5;
  Fgmax=1.0000000001;
  dFg=0.0001;
  Fo=0.0784613177339900;
  Fbmin=0.01999999999;
  Fbmax=0.04000000001;
  Fbomin=0.02999999999;
  Fomin=0.06999999999;
  ddo=0;

  i=1;
  Fg=Fgmin+(i-1)*dFg;
  while(Fg<=Fgmax){
            d=1;

            w=1;
            Fbo=Fg/w;
            while(Fbo>=Fbomin){
                     v=1;
                     Fb=Fg/v;
                     while(Fb>Fbmax){
                                v=v+1;
                                Fb=Fg/v;
                                    }
                     while(Fb>=Fbmin){
                                if(Fbo>=Fb) F1=Fbo-Fb;
                                           else F1=Fb-Fbo;
                                if(F1>=Fomin){
                                            if(F1>=Fo) d1=(F1-Fo)/Fo;
                                            if(F1<Fo) d1=(Fo-F1)/Fo;
                                              }
                                if(F1<Fomin) d1=1;
                                F2=Fbo+Fb;
                                if(F2>=Fomin){
                                            if(F2>=Fo) d2=(F2-Fo)/Fo;
                                            if(F2<Fo) d2=(Fo-F2)/Fo;
                                              }
                                if(F2<Fomin) d2=1;
                                d3=d2-d1;
                                if(d3>=0) d4=d1;
                                         else d4=d2;
                                if(d>=d4){
                                          d=d4;
                                          Wpogr1=W;
                                          Vpogr1=V;
                                          }
                                v=v+1;
                                Fb=Fg/v;
                                        }
                     w=w+1;
                     Fbo=Fg/w;
                                 }
            if(ddo<=d){
                       ddo=d;
                       Ipogr=i;
                       Vpogr=Vpogr1;
                       Wpogr=Wpogr1;
                      }
            i=i+1;
            Fg=Fgmin+(i-1)*dFg;
                   }
  PogrechnostEdit->Text=FloatToStr(ddo);
  ApogrEdit->Text=IntToStr(Ipogr);
  WpogrEdit->Text=IntToStr(Wpogr);
  VpogrEdit->Text=IntToStr(Vpogr);

}
//---------------------------------------------------------------------------













