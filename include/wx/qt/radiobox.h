/////////////////////////////////////////////////////////////////////////////
// Name:        wx/qt/radiobox.h
// Author:      Peter Most
// Id:          $Id$
// Copyright:   (c) Peter Most
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_QT_RADIOBOX_H_
#define _WX_QT_RADIOBOX_H_

#include "wx/qt/pointer_qt.h"
#include "wx/qt/groupbox_qt.h"
#include <QtGui/QButtonGroup>

class WXDLLIMPEXP_CORE wxRadioBox : public wxControl, public wxRadioBoxBase
{
public:
    wxRadioBox();

    wxRadioBox(wxWindow *parent,
               wxWindowID id,
               const wxString& title,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               int n = 0, const wxString choices[] = NULL,
               int majorDim = 0,
               long style = wxRA_SPECIFY_COLS,
               const wxValidator& val = wxDefaultValidator,
               const wxString& name = wxRadioBoxNameStr);

    wxRadioBox(wxWindow *parent,
               wxWindowID id,
               const wxString& title,
               const wxPoint& pos,
               const wxSize& size,
               const wxArrayString& choices,
               int majorDim = 0,
               long style = wxRA_SPECIFY_COLS,
               const wxValidator& val = wxDefaultValidator,
               const wxString& name = wxRadioBoxNameStr);

    bool Create(wxWindow *parent,
                wxWindowID id,
                const wxString& title,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                int n = 0, const wxString choices[] = NULL,
                int majorDim = 0,
                long style = wxRA_SPECIFY_COLS,
                const wxValidator& val = wxDefaultValidator,
                const wxString& name = wxRadioBoxNameStr);

    bool Create(wxWindow *parent,
                wxWindowID id,
                const wxString& title,
                const wxPoint& pos,
                const wxSize& size,
                const wxArrayString& choices,
                int majorDim = 0,
                long style = wxRA_SPECIFY_COLS,
                const wxValidator& val = wxDefaultValidator,
                const wxString& name = wxRadioBoxNameStr);

    using wxWindowBase::Show;
    using wxWindowBase::Enable;
    
    virtual bool Enable(unsigned int n, bool enable = true);
    virtual bool Show(unsigned int n, bool show = true);
    virtual bool IsItemEnabled(unsigned int n) const;
    virtual bool IsItemShown(unsigned int n) const;

    virtual unsigned int GetCount() const;
    virtual wxString GetString(unsigned int n) const;
    virtual void SetString(unsigned int n, const wxString& s);

    virtual void SetSelection(int n);
    virtual int GetSelection() const;

    virtual QGroupBox *GetHandle() const;

private:
    // The 'visual' group box:
    wxQtPointer< wxQtGroupBox > m_qtGroupBox;

    // Handles the mutual exclusion of buttons:
    wxQtPointer< QButtonGroup > m_qtButtonGroup;

    DECLARE_DYNAMIC_CLASS(wxRadioBox)
};

#endif // _WX_QT_RADIOBOX_H_