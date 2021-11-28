#pragma once

//
class CUserLanguage
{
public:
    struct SyntaxStyle
    {
        COLORREF color{};
        bool bold{};
        bool italic{};
    };

    std::set<std::wstring> m_ext;   //��չ���б�
    std::wstring ExtListToString() const;    //����չ���б�ת�����ַ���
    void ExtListFromString(const std::wstring& str);

    bool IsStyleExist(int id);
    SyntaxStyle& GetStyle(int id);
    void SetStyle(int id, const SyntaxStyle& style);
    void RemoveStyle(int id);

private:
    std::map<int, SyntaxStyle> m_style_map; //����һ�����Ե��û��Զ����б�key: ��ʽ����ţ�value: �û��Զ�����ʽ
};

//�����û��Զ�������Ը�ʽ
class CUserDefinedLanguageStyle
{
public:
    bool IsLanguageExist(const std::wstring& language_name);
    CUserLanguage& GetLanguage(const std::wstring& language_name);
    const CUserLanguage& GetLanguage(const std::wstring& language_name) const;
    std::wstring FindLanguageByFileName(const std::wstring& file_name) const;

    void Load();
    void Save();

private:
    std::map<std::wstring, CUserLanguage> m_language_map;   //�����������Ե��û��Զ����б�key: ���Ե����ƣ�vlaue: �����Ե��û��Զ����б�
};

