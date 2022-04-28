//****************************************************************************************************
//������������ ����������
//****************************************************************************************************
#include "cactionmessage.h"

//****************************************************************************************************
//���������� ����������
//****************************************************************************************************

//****************************************************************************************************
//���������
//****************************************************************************************************

//****************************************************************************************************
//����������������
//****************************************************************************************************

//****************************************************************************************************
//����������� � ����������
//****************************************************************************************************

//----------------------------------------------------------------------------------------------------
//�����������
//----------------------------------------------------------------------------------------------------
CActionMessage::CActionMessage(const std::string &message,int32_t screen_x,int32_t screen_y,std::shared_ptr<IAction> iAction_Ptr)
{ 
 Message=message;
 ScreenX=screen_x;
 ScreenY=screen_y;
 iAction_NextPtr=iAction_Ptr;
 Init();
}
//----------------------------------------------------------------------------------------------------
//����������
//----------------------------------------------------------------------------------------------------
CActionMessage::~CActionMessage()
{
}

//****************************************************************************************************
//�������� �������
//****************************************************************************************************

//----------------------------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------------------------

//****************************************************************************************************
//�������� �������
//****************************************************************************************************

//----------------------------------------------------------------------------------------------------
//��������� �������� � ���������
//----------------------------------------------------------------------------------------------------
void CActionMessage::Execute(std::shared_ptr<IPart> iPart_Ptr,CGameState &cGameState)
{
 //��������� ��������� � ������� ���������
 cGameState.AddMessage(Message,ScreenX,ScreenY); 
 if (iAction_NextPtr.get()!=NULL) iAction_NextPtr->Execute(iPart_Ptr,cGameState);	
}
//----------------------------------------------------------------------------------------------------
//�������������
//----------------------------------------------------------------------------------------------------
void CActionMessage::Init(void)
{
 if (iAction_NextPtr.get()!=NULL) iAction_NextPtr->Init();
}