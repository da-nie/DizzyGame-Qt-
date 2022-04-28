#ifndef C_ACTION_SET_ENABLED_H
#define C_ACTION_SET_ENABLED_H

//****************************************************************************************************
//����� �������� "���������/��������� �������"
//****************************************************************************************************

//****************************************************************************************************
//������������ ����������
//****************************************************************************************************
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
//����� �������� "���������/��������� �������"
//****************************************************************************************************
class CActionSetEnabled:public IAction
{
 public:
  //-������������---------------------------------------------------------------------------------------
  //-���������------------------------------------------------------------------------------------------
  //-���������------------------------------------------------------------------------------------------
 private:
  //-����������-----------------------------------------------------------------------------------------
  std::shared_ptr<IAction> iAction_NextPtr;//��������� �� ��������� ��������
  bool Enabled;//��������� ��������� ��������
 public:
  //-�����������----------------------------------------------------------------------------------------
  CActionSetEnabled(bool enabled,std::shared_ptr<IAction> iAction_Ptr=std::shared_ptr<IAction>(NULL));
  //-����������-----------------------------------------------------------------------------------------
  ~CActionSetEnabled();
 public:
  //-�������� �������-----------------------------------------------------------------------------------
  void Execute(std::shared_ptr<IPart> iPart_Ptr,CGameState &cGameState);//��������� �������� � ���������
  void Init(void);//�������������
 private:
  //-�������� �������-----------------------------------------------------------------------------------  
};

#endif