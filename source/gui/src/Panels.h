#include <wx/wx.h>
#include <wx/panel.h>



class LeftPanel : public wxPanel
{
   public:

       wxTextCtrl* m_rightTableResult;

       LeftPanel(wxPanel *parent);
       wxButton *m_refresh;
       wxButton** m_tables_button;
       void refresh();
       void OnButtonClicked(wxCommandEvent& evt);
};

class RightPanel : public wxPanel
{
   public:
       wxTextCtrl* m_rightTableResult;

       RightPanel(wxPanel *parent);

       void OnSetText(wxCommandEvent & event);

       wxButton *m_exec_query;
       wxTextCtrl *m_text_input;
       wxStaticText *m_text_output;
      
       void executeInputedQuery();
};

class RightBottomPanel : public wxPanel
{
   public:
      RightBottomPanel(wxPanel *parent);
     
      wxTextCtrl *m_text;

      void OnTableResult(wxCommandEvent& event);
 
};


