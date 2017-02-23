#ifndef WIDGET_H
#define WIDGET_H
#include <math.h>
#include <QWidget>
#include<iostream>
#include <QPushButton>
#include <QApplication>
#include <QLineEdit>
#include <QPixmap>
#include <QLabel>
#include <QPropertyAnimation>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QtGui>
#include <QLineEdit>
#include <QDoubleSpinBox>
using namespace std;
struct CPT { double x; double y;};
#define CPt CPT
#define MAX_NO 100
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    double ArcIntegrand(double u);
    double ArcLength(double ustart,double uend);
    //void ArcLengthPoint(float *spline[2],float s,float*pt);
    void ArcLengthPoint(double spline[][2],double s,double pt[2]);
    void SetLengths(double spline[][2],int npoints);
    void GetPointOnSpline(double usearch,double pt[2]);
    //void SegCoef(double ax,double bx,double cx,double dx,double ay,double by,double cy,double dy);
    void SegCoef(int i);
    double speed(double t);
     double speed1(double t);

    CPt Spline[1024];
    void CSpline(double x[], double y[], int grain, double tension, int n);
    void CubicSpline(int n, CPT *knots, int grain, double tension);
    void GetCardinalMatrix(double a1);
    double Matrixx(double a, double b, double c, double d, double alpha);
    double Matrixy(double a, double b, double c, double d, double alpha);
  //  void carr();
 //  int zz=0;

private slots:
   void road();
   void slow();
   void fast();
   void myfun();
   void myfun1();

private:
    Ui::Widget *ui;

   //  QPixmap pix1,pix2;
     QPoint Point;
   int w=1,d = 0,count = 0,g=0,a=0,z=0,v=0,time=0;
     double xx[100]={0};
     double yy[100]={0};
     double te=0;
     CPt *knots0;
      CPt *s;
    //  CPt *k0,*kml,*k1,*k2;
        double sp[][2],sp1[][2];
        double p[2];
        double total_length;
        double seg_lengths[MAX_NO];
        double seg_length[50];
        double ax,bx,cx,dx,ay,by,cy,dy;
        double A,B,C,D,E;
        double sa;
        double cxx[10][4],cyy[10][4];
        double ax1 , bx1 , cx1, dx1 ;
        double ay1, by1 , cy1 , dy1;
        double aa=10,aa1=2.5,aa2=-0.5,aa3=4,aa4=-3;
        double t=0,tt=0,zz=0,zzz=0;
     int n0;
     double m[16];
     QPropertyAnimation *animation;
     QTimer *mytime,*mytime1;

     QLabel *myWidget,*label,*label1,*label2,*label3;
QPushButton *droad,*sloww,*fastt;
     QString path;
      QPixmap pix1,pix2;
      QDoubleSpinBox *doubleSpinBox;
      QSpinBox *spinBox;
      QLineEdit *lineEdit3,*lineEdit4;
      QSpinBox *spin;
      QDoubleSpinBox *dspin;
};

#endif // WIDGET_H
