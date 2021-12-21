#include "Communicate.h"
#include "./../../FileHandlerPI/FileHandler.h"
#include "./../../CompilersPI/Tree.h"
#include "./../../CompilersPI/SelectTree.h"
#include "./../../CompilersPI/Compiler.h"
#include "./../../CompilersPI/Parser.h"
#include "./../../CompilersPI/SyntaxParser.h"
#include "./../../CompilersPI/Node.h"
#include "./../../ExecMachine/ExecuteMachine.h"


BEGIN_EVENT_TABLE(Communicate, wxFrame)
    EVT_BUTTON(1005, Communicate::OnRefresh)
    EVT_BUTTON(1006, Communicate::OnExecuteQuery)
END_EVENT_TABLE()

Communicate::Communicate(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(980, 560))
{
  m_parent = new wxPanel(this, wxID_ANY);

  wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

  m_lp = new LeftPanel(m_parent);
  m_rp = new RightPanel(m_parent);
  m_rbp = new RightBottomPanel(m_parent);

  hbox->Add(m_lp, 1, wxEXPAND | wxALL, 5);
  hbox->Add(m_rp, 1, wxEXPAND | wxALL, 5);
  hbox->Add(m_rbp, 1, wxEXPAND | wxALL, 5);

  m_parent->SetSizer(hbox);

  mc = new ExecuteMachine();
  fh = new FileHandler();
 
  
  comp = new Compiler();

  this->Centre();
};

void Communicate::OnRefresh(wxCommandEvent& event)
{
    m_lp->refresh();
};

void Communicate::OnExecuteQuery(wxCommandEvent& event)
{
   m_rp->executeInputedQuery();
};
