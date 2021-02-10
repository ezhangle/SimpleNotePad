#pragma once
#ifndef COMMON_DATA_H
#define COMMON_DATA_H


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
    COLORREF current_line_highlight_color{ RGB(234, 243, 253) };    //��ǰ�и�����ɫ
    COLORREF background_color{ RGB(255, 255, 255) };  //������ɫ
    CString font_name;	//��������
    int font_size{ 9 };		//�����С
    int tab_width{ 4 };     //�Ʊ�����

    //ʮ�����Ʋ鿴��
    CString font_name_hex;	//ʮ�����Ʋ鿴������������
    int font_size_hex{ 9 };		//ʮ�����Ʋ鿴���������С
    bool show_invisible_characters_hex{ false };    //�Ƿ���ʾ���ɼ��ַ�
};

//�Զ�����Ϣ
inline int GetUserDefinedMessgeId()
{
    static int current_msg_id = WM_USER + 100;
    current_msg_id++;
    return current_msg_id;
}

namespace MessageId
{
    const int a = GetUserDefinedMessgeId();
};

//static const int WM_COLOR_SELECTED = GetUserDefinedMessgeId();     //��Ӧ��ɫѡ��ؼ�ѡ������ɫ
#define WM_COLOR_SELECTED (WM_USER + 100)     //��Ӧ��ɫѡ��ؼ�ѡ������ɫ

#endif // !COMMON_DATA_H
