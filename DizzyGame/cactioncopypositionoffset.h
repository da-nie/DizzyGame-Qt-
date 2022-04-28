#ifndef C_ACTION_COPY_POSITION_OFFSET_H
#define C_ACTION_COPY_POSITION_OFFSET_H

//****************************************************************************************************
//����� �������� "�������� ������� �� ���������"
//****************************************************************************************************

//****************************************************************************************************
//������������ ����������
//****************************************************************************************************
#include "iaction.h"
#include <stdint.h>
#include <memory>

//****************************************************************************************************
//����������������
//****************************************************************************************************

//****************************************************************************************************
//���������
//****************************************************************************************************

//****************************************************************************************************
//��������������� ����������
//****************************************************************************************************

//****************************************************************************************************
//����� �������� "�������� ������� �� ���������"
//****************************************************************************************************
class CActionCopyPositionOffset:public IAction
{
 public:
  //-������������---------------------------------------------------------------------------------------
  //-���������------------------------------------------------------------------------------------------
  //-���������------------------------------------------------------------------------------------------
 private:
  //-����������-----------------------------------------------------------------------------------------
  std::string Name_One;//��� ������� �������� (������� ����������)
  std::string Name_Two;//��� ������� �������� (� ������� �������� ����������)
  int32_t OffsetX;//��������
  int32_t OffsetY;
  std::shared_ptr<IAction> iAction_NextPtr;//��������� �� ��������� ��������
 public:
  //-�����������----------------------------------------------------------------------------------------
  CActionCopyPositionOffset(const std::string &name_one,const std::string &name_two,int32_t offset_x,int32_t offset_y,std::shared_ptr<IAction> iAction_Ptr=std::shared_ptr<IAction>(NULL));
  //-����������-----------------------------------------------------------------------------------------
  ~CActionCopyPositionOffset();
 public:
  //-�������� �������-----------------------------------------------------------------------------------
  void Execute(std::shared_ptr<IPart> iPart_Ptr,CGameState &cGameState);//��������� �������� � ���������
  void Init(void);//�������������
 private:
  //-�������� �������-----------------------------------------------------------------------------------  
};

#endif