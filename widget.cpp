#include "widget.h"
#include "ui_widget.h"
#include"qpainter.h"
#include <QMouseEvent>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QtGui>
#include "qsequentialanimationgroup.h"
#include "qparallelanimationgroup.h"
#include <QWidget>
#include <windows.h>
#include <QSpinBox>


#define SEARCH_TOL 0.03
#define ITERATION_COUNT 5
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
      resize(850,500);
      pix1 = QPixmap(750,450);
           pix2 = QPixmap(750,450);
//ui->spinBox;
//ui->doubleSpinBox;
//lineEdit->setText("0.5");
//lineEdit2->setText("5");
      mytime = new QTimer(this);
 mytime1=new QTimer(this);
 droad = new QPushButton(this);
   droad ->setText("Generate");
   droad->setGeometry(QRect(760,30,80,40));
   connect(droad,SIGNAL(clicked()),this,SLOT(road()));

   sloww = new QPushButton(this);
   sloww ->setText("Scenario2");
   sloww->setGeometry(QRect(760,265,80,40));
   connect(sloww,SIGNAL(clicked()),this,SLOT(slow()));

   label = new QLabel(this);
   label->setGeometry(QRect(760,80,50,25));
   label->setText("point");



   spin = new QSpinBox(this);
     spin->setGeometry(QRect(790,80,50,25));
     spin->setValue(10);
      //spin->setText("10");

      label1 = new QLabel(this);
   label1->setGeometry(QRect(748,110,50,25));
   label1->setText("tension");



   dspin = new QDoubleSpinBox(this);
   dspin->setSingleStep(0.1);
   dspin->setMinimum(0.0);
       dspin->setMaximum(1.0);
       dspin->setValue(0.5);
     dspin->setGeometry(QRect(790,110,50,25));

   fastt = new QPushButton(this);
     fastt ->setText("Scenario1");
    fastt->setGeometry(QRect(760,160,80,40));
     connect( fastt,SIGNAL(clicked()),this,SLOT(fast()));

     label3 = new QLabel(this);
     label3->setGeometry(QRect(755,320,50,25));
     label3->setText("velocity");

     lineEdit4 = new QLineEdit(this);
     lineEdit4->setGeometry(QRect(810,320,30,25));
     lineEdit4->setText("4");


}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *event)
{
//QPainter pp1(&pix1);
QPainter pp(this);
QPixmap hand=QPixmap(":/new/prefix1/8.jpg").scaled(850,500);
pp.drawPixmap(0,0,hand);

pp.drawEllipse(Point,2,2);
//QBrush brush(Qt::red);
//cout<<"aa"<<endl;

if(a==1){
   QPainterPath path;
 pp.setPen(Qt::blue);
    path.moveTo(xx[0],yy[0]);
   CPt *s;
    s=Spline;
  //  cout<<"aa"<<endl;
    int draw;
    for(draw=0;draw<=g*(count-1);draw++)

    {
        path.lineTo(s->x,s->y);
sp1[draw][0]=s->x;
sp1[draw][1]=s->y;
//cout<<sp1[draw][0]<<"aa"<<sp1[draw][1]<<endl;
        s++;

    }
   pp.drawPath(path);
update();
   // cout<<seg_lengths[3]<<endl;
//a=0;
//cout<<"asd"<<endl;
}



if (zz!=0){
    cout<<"t:"<<t<<endl;
    sa= speed(t);
     cout<<sa<<endl;


     SetLengths(sp,n0);
    //cout<<sa<<endl;
    //double cc=sa/total_length;
    ArcLengthPoint(sp1,sa,p);

     QPixmap birdimg=QPixmap(":/new/prefix1/12.png").scaled(80,80);
pp.drawPixmap(p[0]-40,p[1]-40,80,80,birdimg);

         update();

}
if (zzz!=0){

//cout<<"hhhh"<<endl;
   // repaint();
cout<<"tt:"<<tt<<endl;
sa= speed1(tt);
 cout<<sa<<endl;


 SetLengths(sp,n0);
//cout<<sa<<endl;
//double cc=sa/total_length;
ArcLengthPoint(sp1,sa,p);
     QPixmap birdimg=QPixmap(":/new/prefix1/12.png").scaled(80,80);
pp.drawPixmap(p[0]-40,p[1]-40,80,80,birdimg);


         update();
        // if(sa>0.8) mytime1->stop();


}

}


void Widget::mousePressEvent(QMouseEvent *event){

if((event->button()==Qt::LeftButton)&&w==1)
{

    Point = event->pos();
    xx[d]=event->x();
    yy[d]=event->y();
    sp[d][0]=xx[d];
    sp[d][1]=yy[d];
    //cout<<xx[d]<<endl;
    d++;
    count++;
    update();
}

}


void Widget::road(){
   // QString str = lineEdit->text();
     QString str = spin->text();
    g = str.toInt();
    //QString str2 = lineEdit2->text();
     QString str2 = dspin->text();
    te = str2.toDouble();
    //g = 5;
//te = 0.5;
//cout<<g<<endl;
    CSpline(xx,yy,g,te,count);

// s= Spline;
   // ori = 1;
a=1;

update();
}
void Widget::slow(){
//z=1;
if(mytime->isActive())
    return ;
//zz=0;



time = lineEdit4->text().toDouble();
time = 1000/time;
connect(mytime, SIGNAL(timeout()), this, SLOT(myfun()));
mytime->start(time);

update();
}
void Widget::myfun(){
   // cout<<t<<endl;
    if(zzz!=0) zzz=0;
    if(t<1){
zz+=1;
t=zz/10;
/*cout<<"t:"<<t<<endl;
    sa= speed(t);
     cout<<sa<<endl;


     SetLengths(sp,n0);
    //cout<<sa<<endl;
    //double cc=sa/total_length;
    ArcLengthPoint(sp1,sa,p);*/
    }
    else return;
}


  //double cxx[][4],cyy[][4];
double Widget::speed(double t){
    double s;
    if(t<0.2 ){
        s=0.5*aa*t*t;
    }
    else{
        if(t>=0.2&&t<=0.6){
        s=0.2+2*(t-0.2)-0.5*aa*(t-0.2)*(t-0.2);
        }
        else{
            s=0.5*aa1*(1-t)*(1-t);
        }
    }
    return s;
}

void Widget::fast(){
//z=1;
if(mytime1->isActive())
    return ;
//zz=0;

//time = 200;
time = lineEdit4->text().toDouble();
time = 1000/time;
connect(mytime1, SIGNAL(timeout()), this, SLOT(myfun1()));
mytime1->start(time);

update();
}
void Widget::myfun1(){
   // if(zz!=0) zz=0;
    if(tt<1){
zzz+=1;
tt=zzz/10;

    }
     else return;
}



double Widget::speed1(double t){
    double s;
if(t<=0.5){
     s=0.5*aa3*t*t;
}
else{
    s=0.5+2*(t-0.5)-0.5*aa3*(t-0.5)*(t-0.5);
}
    return s;
}





double Widget::ArcIntegrand(double u){
    double a =sqrt(A*u*u*u*u+B*u*u*u+C*u*u+D*u+E);
    //cout<<a<<endl;
    return a;
}

void Widget::GetPointOnSpline(double usearch,double pt[2]){
   pt[0]= ax1*usearch*usearch*usearch+bx1*usearch*usearch+cx1*usearch+dx1;
pt[1]=ay1*usearch*usearch*usearch+by1*usearch*usearch+cy1*usearch+dy1;
cout<<pt[0]<<"aa"<<pt[1]<<endl;
}
//void Widget::SegCoef(double ax,double bx,double cx,double dx,double ay,double by,double cy,double dy){
void Widget::SegCoef(int i){
    ax1 = cxx[i][0];bx1 = cxx[i][1];cx1 = cxx[i][2]; dx1 = cxx[i][3];
     ay1= cyy[i][0];by1 = cyy[i][1]; cy1 = cyy[i][2]; dy1 = cyy[i][3];
A=9*(ax1*ax1+ay1*ay1);
B=12*(ax1*bx1+ay1*by1);
C=6*(ax1*cx1+ay1*cy1)+4*(bx1*bx1+by1*by1);
D=4*(bx1*cx1+by1*cy1);
E=cx1*cx1+cy1*cy1;
//cout<<A<<endl;
}

void Widget::ArcLengthPoint(double spline[][2],double s,double pt[2]){//样条曲线上弧长为s的点

    double uL= 0.0, uR = 1.0, usearch;
   // usearch = ArcLength(uL,uR);
    double segment_dist, ssearch;
    int segment_no=0;
    // 找到曲线段在s范围内
//cout<<"aaa"<<endl;
    do {segment_no++ ;
      //  cout<<segment_no<<endl;
    }while(seg_lengths[segment_no-1]<s);
    segment_no -- ;
    // cout<<segment_no<<endl;
    if(segment_no==0){
        segment_dist = total_length*s ;
    }else{
    segment_dist = total_length*(s-seg_lengths[segment_no-1 ]) ;
    }
    // 建立必须的和片段相关的系数
  //  SegCoef( ax,bx,cx,dx,ay, by, cy,dy);
    SegCoef(segment_no+1 );
   //cout<<segment_no+1<<endl;
  // search segment for bcal para1neter tsearCh that globally gives us an arc length within sEARCH-TOL of s
    do {
    usearch= (uL+uR)/2 ;
   // cout<<usearch<<endl;
    ssearch=ArcLength(uL,usearch);
    if(segment_dist<ssearch+SEARCH_TOL)  uR=usearch;
    else{
    uL= usearch;
    segment_dist -=  ssearch;
    }
    }while((segment_dist>ssearch+SEARCH_TOL)||(segment_dist<ssearch- SEARCH_TOL));
    GetPointOnSpline(usearch,pt);
//cout<<usearch<<endl;
//cout<<p[0]<<"asd"<<p[1]<<endl;
}
double Widget::ArcLength(double ustart,double uend){//区间内弧长
//float ArIntegrand(); //计算积分
double h, sum, u;
int i;
// 计算弧长使用simpson rule
h= (uend- ustart)/(double)ITERATION_COUNT;//
sum = 0 ;
u=ustart+h;
//SegCoef(ax,bx,cx,dx,ay, by, cy,dy) ;
for(i=2;i<=ITERATION_COUNT;i++){
if(!(i&1)) { sum+=4.0*ArcIntegrand(u);
//cout<<u<<endl;
}
else{ sum+=2.0*ArcIntegrand(u);}
u+=h;
}
return( h*(ArcIntegrand(ustart)+sum+ArcIntegrand(uend))/3.0) ;
}


//float seg_length[50];
void Widget::SetLengths(double spline[][2],int npoints)//建立累加弧长表 seg-lengths[]
{
int i, no_segments;
//float arc1ength, ArcLength() ;
double arclength;
//no_segments= npoints-3;
no_segments= npoints ;
arclength = 0.0 ;

seg_length[0] = 0.0 ;
 //cout<<"aaa"<<endl;
for(i=0;i<no_segments;i++){
//SegCoef(ax,bx,cx,dx,ay, by, cy,dy) ;
    SegCoef(i+1);
  //  cout<<"aaa"<<endl;
arclength += ArcLength(0.0,1.0) ;
//cout<<arclength<<endl;
seg_length[i+1] = arclength ;
//cout<<seg_length[i+1] <<endl;
}
total_length=arclength;
//cout<<no_segments<<endl;
//for(i=0;i<=no_segments ;i++) {
    for(i=0;i<no_segments ;i++) {
//seg_lengths[i]= seg_lengths[i]/total_length;
    seg_lengths[i]= seg_length[i+1]/total_length;
    //cout<<seg_lengths[i]<<"aa"<<i<<endl;
}
}


void Widget::CSpline(double x[], double y[], int grain, double tension, int n)
{
int i, np;
n0 = n;
np = n0;
CPt jd[100];
CPt *knots;
knots0 = knots;
//cout<<knots0->x<<endl;
for(i=1; i<=np; i++){
    jd[i].x = x[i-1];
    jd[i].y = y[i-1];
}
jd[0].x = x[0];
jd[0].y = y[0];
jd[np+1].x = x[np-1];
jd[np+1].y = y[np-1];
np=np+2;
knots=jd;
CubicSpline(np,knots,grain,tension);
}

void Widget::CubicSpline(int n, CPT *knots, int grain, double tension)
{
CPt *s;
CPt *k0,*kml,*k1,*k2;
int i,j;
double alpha[50];

GetCardinalMatrix(tension);

for(i=0;i<grain;i++)
    alpha[i] = ((double)i)/grain;

s = Spline;
kml = knots;//5个点的开始
k0 = kml+1;
k1 = k0+1;
k2 = k1+1;

for(i=1;i<n-1;i++){
   // for(i=1;i<n-2;i++){
    for(j=0;j<grain;j++){
        s->x = Matrixx(kml->x,k0->x,k1->x,k2->x,alpha[j]);

        s->y = Matrixy(kml->y,k0->y,k1->y,k2->y,alpha[j]);

       // cxx[i][4]={ax,bx,cx,dx};

       // cout<<"alpha:"<<alpha[j]<<endl;
      //  cout<<s->x<<"a"<<s->y<<endl;
        s++;

    }
   //  cout<<"alpha:"<<ax<<endl;
  // cout<<ax<<"a"<<bx<<endl;
   // cout<<ay<<"a"<<by<<endl;
    cxx[i][0]=ax; cxx[i][1]=bx; cxx[i][2]=cx;cxx[i][3]=dx;
//cout<<cxx[i][0]<<"s"<<cxx[i][1]<<endl;

    cyy[i][0]=ay;cyy[i][1]=by;cyy[i][2]=cy;cyy[i][3]=dy;
 //cout<<cxx[i][0]<<"s"<<cxx[i][1]<<endl;
     //cout<<cyy[i][0]<<"s"<<cyy[i][1]<<endl;

    k0++;kml++;k1++;k2++;
}

}

void Widget::GetCardinalMatrix(double a1)
{
m[0]=-a1; m[1]=2.-a1; m[2]=a1-2.; m[3]=a1;
m[4]=2.*a1; m[5]=a1-3.; m[6]=3.-2*a1; m[7]=-a1;
m[8]=-a1; m[9]=0.; m[10]=a1; m[11]=0.;
m[12]=0.; m[13]=1.; m[14]=0.; m[15]=0.;
}

double Widget::Matrixx(double a, double b, double c, double d, double alpha)
{
double p0,p1,p2,p3;
p0=m[0]*a+m[1]*b+m[2]*c+m[3]*d;
p1=m[4]*a+m[5]*b+m[6]*c+m[7]*d;
p2=m[8]*a+m[9]*b+m[10]*c+m[11]*d;
p3=m[12]*a+m[13]*b+m[14]*c+m[15]*d;
 ax=p0;bx=p1;cx=p2;dx=p3;
return(p3+alpha*(p2+alpha*(p1+alpha*p0)));
}
double Widget::Matrixy(double a, double b, double c, double d, double alpha)
{
double p0,p1,p2,p3;
p0=m[0]*a+m[1]*b+m[2]*c+m[3]*d;
p1=m[4]*a+m[5]*b+m[6]*c+m[7]*d;
p2=m[8]*a+m[9]*b+m[10]*c+m[11]*d;
p3=m[12]*a+m[13]*b+m[14]*c+m[15]*d;
 ay=p0;by=p1;cy=p2;dy=p3;
return(p3+alpha*(p2+alpha*(p1+alpha*p0)));
}







