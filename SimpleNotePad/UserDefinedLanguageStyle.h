#pragma once
#include "simplemarshal.h"
using namespace dakuang;
//
class CUserLanguage : public Marshallable
{
public:
    struct SyntaxStyle : public Marshallable
    {
        COLORREF color{};
        bool bold{};
        bool italic{};

        // ͨ�� Marshallable �̳�
        virtual void marshal(SimplePack&) const override;
        virtual void unmarshal(const SimpleUnpack&) override;
    };

    std::set<std::wstring> m_ext;   //��չ���б�

    std::wstring ExtListToString() const;    //����չ���б�ת�����ַ���
    void ExtListFromString(const std::wstring& str);

    bool IsStyleExist(int id);
    SyntaxStyle& GetStyle(int id);
    void SetStyle(int id, const SyntaxStyle& style);
    void RemoveStyle(int id);

    // ͨ�� Marshallable �̳�
    virtual void marshal(SimplePack&) const override;
    virtual void unmarshal(const SimpleUnpack&) override;

private:
    std::map<int, SyntaxStyle> m_style_map;     //����һ�����Ե��û��Զ����б�key: ��ʽ����ţ�value: �û��Զ�����ʽ
};

//�����û��Զ�������Ը�ʽ
class CUserDefinedLanguageStyle : public Marshallable
{
public:
    bool IsLanguageExist(const std::wstring& language_name);
    CUserLanguage& GetLanguage(const std::wstring& language_name);
    const CUserLanguage& GetLanguage(const std::wstring& language_name) const;
    std::wstring FindLanguageByFileName(const std::wstring& file_name) const;

    //void Load();
    //void Save();

    // ͨ�� Marshallable �̳�
    virtual void marshal(SimplePack&) const override;
    virtual void unmarshal(const SimpleUnpack&) override;

private:
    std::map<std::wstring, CUserLanguage> m_language_map;   //�����������Ե��û��Զ����б�key: ���Ե����ƣ�vlaue: �����Ե��û��Զ����б�
};

