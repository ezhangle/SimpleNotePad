#pragma once

//��������
struct SettingsData
{
    int default_code_page_selected{};
    UINT default_code_page{};
};

//�༭������
struct EditSettingData
{
    bool current_line_highlight{};      //��ǰ�и�����ʾ
    COLORREF background_color{ RGB(255, 255, 255) };  //������ɫ

};

////�Զ�����Ϣ
//inline int GetUserDefinedMessgeId()
//{
//    static int current_msg_id = WM_USER + 100;
//    current_msg_id++;
//    return current_msg_id;
//}
//
//const int WM_COLOR_SELECTED = GetUserDefinedMessgeId();     //��Ӧ��ɫѡ��ؼ�ѡ������ɫ
#define WM_COLOR_SELECTED (WM_USER + 100)     //��Ӧ��ɫѡ��ؼ�ѡ������ɫ