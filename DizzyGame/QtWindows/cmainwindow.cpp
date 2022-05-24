//****************************************************************************************************
//подключаемые библиотеки
//****************************************************************************************************
#include "cmainwindow.h"
#include "ui_cmainwindow.h"
#include <QtWidgets>
#include <stdint.h>
#include <memory>

//****************************************************************************************************
//глобальные переменные
//****************************************************************************************************

//****************************************************************************************************
//константы
//****************************************************************************************************
static std::string CaptionName("Dizzy Game v1.0");

//****************************************************************************************************
//макроопределения
//****************************************************************************************************

//****************************************************************************************************
//конструктор и деструктор
//****************************************************************************************************

//----------------------------------------------------------------------------------------------------
//конструктор
//----------------------------------------------------------------------------------------------------
CMainWindow::CMainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::CMainWindow)
{
 ui->setupUi(this);
 setWindowTitle(tr(CaptionName.c_str()));

 Left=false;
 Right=false;
 Up=false;
 Down=false;
 Fire=false;

 qImage=QImage(CGame::SCREEN_WIDTH,CGame::SCREEN_HEIGHT,QImage::Format_ARGB32_Premultiplied);
 iVideo_Ptr.reset(IVideo::CreateNewCVideoSoftware(CGame::SCREEN_WIDTH,CGame::SCREEN_HEIGHT));
 iVideo_Ptr->Init();
 cGame_Ptr.reset(new CGame());

 Enabled=cGame_Ptr->Init(iVideo_Ptr.get());

 //setGeometry(0,0,CGame::SCREEN_WIDTH,CGame::SCREEN_HEIGHT);
 //подключим таймер обновления экрана
 TimerId=startTimer(TIMER_INTERVAL_MS);
}
//----------------------------------------------------------------------------------------------------
//деструктор
//----------------------------------------------------------------------------------------------------
CMainWindow::~CMainWindow()
{
 killTimer(TimerId);
 delete(ui);
}

//****************************************************************************************************
//закрытые функции
//****************************************************************************************************

//----------------------------------------------------------------------------------------------------
//обработчик таймера
//----------------------------------------------------------------------------------------------------
void CMainWindow::timerEvent(QTimerEvent *qTimerEvent_Ptr)
{
 if (qTimerEvent_Ptr->timerId()!=TimerId) return;

 static int32_t tick=0;
 tick++;
 tick%=30;
 if (tick!=0) return;
 if (Enabled==false)
 {
  update();
  return;
 }
 cGame_Ptr->OnTimer(Left,Right,Up,Down,Fire,iVideo_Ptr.get());
 update();
}

//----------------------------------------------------------------------------------------------------
//обработчик события перерисовки
//----------------------------------------------------------------------------------------------------
void CMainWindow::paintEvent(QPaintEvent *qPaintEvent_Ptr)
{
 //вызываем отрисовку
 uint32_t width;
 uint32_t height;
 iVideo_Ptr->GetScreenSize(width,height);
 void *iptr;
 iVideo_Ptr->GetVideoPointer(iptr);
 uint32_t linesize;
 iVideo_Ptr->GetLineSize(linesize);

 uint32_t *sptr=reinterpret_cast<uint32_t*>(iptr);
 for(int32_t y=0;y<CGame::SCREEN_HEIGHT;y++,sptr+=linesize)
 {
  uint32_t *sptrx=sptr;
  QRgb *img=reinterpret_cast<QRgb*>(qImage.scanLine(y));
  for(int32_t x=0;x<CGame::SCREEN_WIDTH;x++,sptrx++,img++)
  {
   uint32_t color=*(sptrx);
   color|=(0xff<<24);
   //uint8_t r=(color>>0)&0xff;
   //uint8_t g=(color>>8)&0xff;
   //uint8_t b=(color>>16)&0xff;
   *img=color;//qRgba(r,g,b,0xff);
   //qImage.setPixel(x,y,qRgb(r,g,b));
  }
 }

 QPixmap qPixmap=QPixmap::fromImage(qImage);
 QPainter qPainter(this);
// qPainter.setRenderHint(QPainter::Antialiasing,true);
 float aspect=static_cast<float>(CGame::SCREEN_WIDTH)/static_cast<float>(CGame::SCREEN_HEIGHT);
 uint32_t new_width=static_cast<uint32_t>(aspect*this->height());
 uint32_t new_height=this->height();
 if (new_width>this->width())
 {
  new_width=this->width();
  new_height=this->width()/aspect;
 }
 uint32_t ox=(this->width()-new_width)/2;
 uint32_t oy=(this->height()-new_height)/2;
 //qPainter.drawPixmap(0,0,this->width(),this->height(),qPixmap);
 qPainter.fillRect(0,0,this->width(),this->height(),Qt::black);
 qPainter.drawPixmap(ox,oy,new_width,new_height,qPixmap);

 //QPainter qPainter(this);
 //qPainter.drawImage(0,0,qImage.scaled(this->width(),this->height(),Qt::KeepAspectRatio)); - так гораздо медленнее
}
//----------------------------------------------------------------------------------------------------
//обработчик нажатия клавиши
//----------------------------------------------------------------------------------------------------
void CMainWindow::keyPressEvent(QKeyEvent *pe)
{
 if (pe->key()==Qt::Key_Left) Left=true;
 if (pe->key()==Qt::Key_Right) Right=true;
 if (pe->key()==Qt::Key_Up) Up=true;
 if (pe->key()==Qt::Key_Down) Down=true;
 if (pe->key()==Qt::Key_Space) Fire=true;
 if (pe->key()==Qt::Key_Escape) close();
}
//----------------------------------------------------------------------------------------------------
//обработчик отпускания клавиши
//----------------------------------------------------------------------------------------------------
void CMainWindow::keyReleaseEvent(QKeyEvent *pe)
{
 if (pe->key()==Qt::Key_Left) Left=false;
 if (pe->key()==Qt::Key_Right) Right=false;
 if (pe->key()==Qt::Key_Up) Up=false;
 if (pe->key()==Qt::Key_Down) Down=false;
 if (pe->key()==Qt::Key_Space) Fire=false;
}
//****************************************************************************************************
//открытые функции
//****************************************************************************************************


