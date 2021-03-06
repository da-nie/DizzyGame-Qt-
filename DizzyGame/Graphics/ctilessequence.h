#ifndef C_TILES_SEQUENCE_H
#define C_TILES_SEQUENCE_H

//****************************************************************************************************
//класс последовательности тайлов для кусочка карты
//****************************************************************************************************

//****************************************************************************************************
//подключаемые библиотеки
//****************************************************************************************************
#include <stdint.h>
#include <fstream>
#include <vector>

#include "ctile.h"

//****************************************************************************************************
//макроопределения
//****************************************************************************************************

//****************************************************************************************************
//константы
//****************************************************************************************************

//****************************************************************************************************
//предварительные объявления
//****************************************************************************************************

//****************************************************************************************************
//класс последовательности тайлов для кусочка карты
//****************************************************************************************************
class CTilesSequence
{
 public:
  //-перечисления---------------------------------------------------------------------------------------
  //режим анимации
  enum ANIMATION_MODE
  {
   ANIMATION_MODE_SET_STEP,//режим анимации с заданием шага анимации
   ANIMATION_MODE_CYCLIC,//циклическая анимация
   ANIMATION_MODE_ONE_SHOT//однократная анимация
  };
  //-структуры------------------------------------------------------------------------------------------
  //-константы------------------------------------------------------------------------------------------
  static const uint8_t ANIMATION_MODE_SET_STEP_FOR_SAVE=0;//значение для записи анимации с заданием шага
  static const uint8_t ANIMATION_MODE_CYCLIC_FOR_SAVE=1;//значение для записи циклической анимации
  static const uint8_t ANIMATION_MODE_ONE_SHOT_FOR_SAVE=2;//значение для записи циклической анимации
  //-переменные-----------------------------------------------------------------------------------------
 private:
  //-константы------------------------------------------------------------------------------------------
  //-переменные-----------------------------------------------------------------------------------------
  std::vector<CTile> cTile_Sequence;//набор тайлов
  size_t CurrentIndex;//текущий индекс тайла
  ANIMATION_MODE AnimationMode;//режим анимации
 public:
  //-конструктор----------------------------------------------------------------------------------------
  CTilesSequence(const CTile &cTile=CTile(0,0));
  //-деструктор-----------------------------------------------------------------------------------------
  ~CTilesSequence();
 public:
  //-открытые функции-----------------------------------------------------------------------------------
  bool Save(std::ofstream &file);//записать
  bool Load(std::ifstream &file);//сохранить
  void Clear(void);//удалить все элементы
  void AddNewTile(const CTile &cTile);//добавить новый тайл
  CTile& GetTile(size_t index);//получить тайл
  size_t GetSize(void);//получить количество тайлов
  size_t GetCurrentIndex(void);//получить текущий индекс тайла
  void ToNextTile(void);//перейти к следующему индексу тайла в зависимости от режима анимации
  void ToNextTileByForce(void);//перейти к следующему индексу тайла принудительно
  void ToTile(size_t index);//перейти к индексу тайла
  void ResetCurrentIndex(void);//сбросить текущий индекс тайла
  std::vector<CTile>* GetItemPtr(void);//получить указатель на список тайлов
  ANIMATION_MODE GetAnimationMode(void);//получить режим анимации
  void SetAnimationMode(ANIMATION_MODE animation_mode);//задать режим анимации
 private:
  //-закрытые функции-----------------------------------------------------------------------------------  
};

#endif
