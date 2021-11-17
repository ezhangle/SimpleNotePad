﻿#pragma once

#include "../scintilla/include/SciLexer.h"
#include "../scintilla/include/Scintilla.h"

// CScintillaEditView 视图

#define SCINTILLA_MARGIN_LINENUMBER 0
#define MARGIN_FOLD_INDEX 1

class CScintillaEditView : public CView
{
    DECLARE_DYNCREATE(CScintillaEditView)

protected:
    CScintillaEditView();           // 动态创建所使用的受保护的构造函数
    virtual ~CScintillaEditView();

public:
    struct KeepCurrentLine
    {
        KeepCurrentLine(CScintillaEditView* view)
            : m_view(view)
        {
            //保存当前行
            current_line = m_view->GetFirstVisibleLine();
        }
        ~KeepCurrentLine()
        {
            //恢复当前行
            m_view->SetFirstVisibleLine(current_line);
        }

        CScintillaEditView* m_view{};
        int current_line{};
    };

    virtual void OnDraw(CDC* pDC);      // 重写以绘制该视图
#ifdef _DEBUG
    virtual void AssertValid() const;
#ifndef _WIN32_WCE
    virtual void Dump(CDumpContext& dc) const;
#endif
#endif

    void SetText(const wstring& text);
    void GetText(wstring& text);
    const wchar_t* GetText(int& size);      //获取文本（返回字符串指针，需要自行释放内存）
    const char* GetTextUtf8(int& size);      //获取UTF8格式文本（返回字符串指针，需要自行释放内存）
    void SetFontFace(const wchar_t* font_face);
    void SetFontSize(int font_size);
    void SetTabSize(int tab_size);
    void SetSel(int start, int end, const wstring& edit_str);        //设置选中范围（位置以字符为单位）
    void GetSel(int& start, int& end);      //获取选中范围（位置以字符为单位）
    void SetSelByBytes(int start, int end);     //设置选中范围（以字节为单位）
    void SetBackgroundColor(COLORREF color);
    void SetReadOnly(bool read_only);
    bool IsReadOnly();
    int GetCursorIndex();       //获取光标位置
    std::wstring GetSelectedText();         //获取选中文本
    std::string GetSelectedTextWithUtf8();  //获取UTF8格式的选中文本
    CPoint GetCursorPosition();   //获取光标的坐标

    void Undo();
    void Redo();
    void Cut();
    void Copy();
    void Paste();
    void Paste(const wstring& text);
    void SelectAll();
    void EmptyUndoBuffer();     //清空撤销缓存

    void ReplaceSelected(const wstring& replace_str);   //替换选中的字符串

    enum eWordWrapMode
    {
        WW_WORD,
        WW_CHARACTER,
        WW_WHITESPACE
    };
    void SetWordWrap(bool word_wrap, eWordWrapMode mode = WW_WORD);

    bool IsEditChangeNotificationEnable();
    void SetEditChangeNotificationEnable(bool enable);

    bool CanUndo();
    bool CanRedo();
    bool CanPaste();
    bool IsSelectionEmpty();
    bool IsModified();
    void SetModified();
    void SetSavePoint();

    void SetLineNumberWidth(int width);
    void ShowLineNumber(bool show);
    void SetLineNumberColor(COLORREF color);

    int GetZoom();
    void SetZoom(int zoom);

    enum eEolMode
    {
        EOL_CRLF,
        EOL_CR,
        EOL_LF
    };
    void SetEolMode(eEolMode eolMode);
    eEolMode GetEolMode();

    void ConvertEolMode(eEolMode eolMode);

    void SetViewEol(bool show);

    int GetFirstVisibleLine();
    void SetFirstVisibleLine(int line);

    int GetLineHeight();

    void SetCurrentLineHighlight(bool highlight);   //设置当前行高亮
    void SetCurrentLineHighlightColor(COLORREF color);  //设置当前行高亮颜色

    void SetSelectionBackColor(COLORREF color);     //设置选中部分的背景色

    void GotoLine(int line);    //跳转到行

    enum class MarkStyle
    {
        MARK_ALL = 1,
        SELECTION_MARK,
        HTML_MATCH
    };
    void SetMark(MarkStyle mark_style, int start, int length);
    void ClearMark(MarkStyle mark_style, int start, int length);
    void ClearAllMark(MarkStyle mark_style);

    //语法解析
    void SetLexer(int lexer);
    void SetKeywords(int id, const char* keywords);
    void SetSyntaxColor(int id, COLORREF color);
    void SetSyntaxFontStyle(int id, bool bold, bool italic);
    void SetLexerNormalText();

    static eEolMode JudgeEolMode(const wstring& str);
    static int CharactorPosToBytePos(int pos, const wchar_t* str, size_t size);     //将字符的位置转换成字节的位置（使用UTF8编码）
    static int BytePosToCharactorPos(int pos, const char* str, size_t size);     //将字节的位置转换成字符的位置（使用UTF8编码）

    void SetFold();

    void SetContextMenu(CMenu* pMenu, CWnd* pMenuOwner);

private:

private:
    bool m_change_notification_enable = true;      //如果为false，则不响应文本改变消息
    int m_line_number_width = 36;
    COLORREF m_line_number_color{};
    COLORREF m_background_color{ RGB(255,255,255) };
    COLORREF m_current_line_highlight_color{ RGB(234, 243, 253) };

    CMenu* m_pMenu{};
    CWnd* m_pContextMenuOwner{};
    bool m_modified{};

protected:
    DECLARE_MESSAGE_MAP()
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
public:
    afx_msg void OnPaint();
    virtual void PreSubclassWindow();
    virtual void OnInitialUpdate();
    afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
};
