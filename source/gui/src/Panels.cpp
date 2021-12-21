#include <wx/stattext.h>
#include <string>
#include <vector>
#include <wx/intl.h>
#include "Communicate.h"
#include "./../../FileHandlerPI/FileHandler.h"
#include "./../../CompilersPI/Tree.h"
#include "./../../CompilersPI/SelectTree.h"
#include "./../../CompilersPI/Compiler.h"
#include "./../../CompilersPI/Parser.h"
#include "./../../CompilersPI/SyntaxParser.h"
#include "./../../CompilersPI/Node.h"
#include "./../../ExecMachine/ExecuteMachine.h"
#include <map>
#include <iostream>


RightBottomPanel::RightBottomPanel(wxPanel *parent)
    :wxPanel(parent, wxID_ANY, wxDefaultPosition,
            wxSize(270, 150), wxBORDER_SUNKEN)
{
   m_text = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxPoint(20,20), wxSize(580,500),wxTE_MULTILINE);
}

LeftPanel::LeftPanel(wxPanel* parent)
    : wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1),wxBORDER_SUNKEN)
{ 
    m_parent = parent;
    m_refresh = new wxButton(this, 1005, wxT("ОБНОВИТЬ"), wxPoint(10,10),
            wxDefaultSize);

//    m_rightTableResult = ((Communicate *)m_parent->GetParent())->m_rbp->m_text;
 /* Connect(ID_MINUS, wxEVT_COMMAND_BUTTON_CLICKED,
      wxCommandEventHandler(LeftPanel::OnMinus));
*/};

void LeftPanel::refresh()
{
     wxLocale qw(wxLANGUAGE_RUSSIAN);
   
   FileHandler* fileHandler = new FileHandler();
   std::string path("/PIDB/data/tables");
   fileHandler->readEntities(path);
  
   std::vector<std::string> tables = fileHandler->getEntities();
   int v_size = tables.size();
   m_tables_button = new wxButton*[v_size];
   wxGridSizer* grid = new wxGridSizer(1,v_size, 0,0);
   
  
   for(int i = 0; i < v_size;i++) //colums
   {
  
       m_tables_button[i] = new wxButton(this, wxID_ANY, tables[i].c_str(), wxPoint(60, 50+i*50), wxDefaultSize);
       m_tables_button[i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&LeftPanel::OnButtonClicked, this); 
   }
   this->SetSizer(grid);
   grid->Layout();
   m_rightTableResult = ((Communicate *)m_parent->GetParent())->m_rbp->m_text;

};

void LeftPanel::OnButtonClicked(wxCommandEvent &evt)
{
    wxLocale qw(wxLANGUAGE_RUSSIAN);
 
    wxObject* button = evt.GetEventObject();
    wxButton* btn = static_cast<wxButton*>(button);
    std::string table(btn->GetLabel().mb_str());
    std::string query = "ВЫБРАТЬ 1,2,3 ИЗ " +  table;
   
    Compiler* comp = ((Communicate *)m_parent->GetParent())->comp;
    Parser* parser = new SyntaxParser(query);
    FileHandler* fh = ((Communicate *)m_parent->GetParent())->fh;
    ExecuteMachine* me = ((Communicate *)m_parent->GetParent())->mc;
 
    comp->setQuery(query);
    parser->setQuery(query);
    
    Tree* selectTree = new SelectTree(query);
    comp->compile(parser, selectTree);
    std::map<std::string, std::string> plan = comp->get_plan();
    me->execute(plan, fh);

    m_rightTableResult->Clear();
    m_rightTableResult->Refresh();

    m_rightTableResult->ChangeValue(me->getTableResult());

  
 
    delete parser;
    delete selectTree;
};

RightPanel::RightPanel(wxPanel * parent)
       : wxPanel(parent, wxID_ANY, wxDefaultPosition,
         wxSize(300, 300), wxBORDER_SUNKEN)
{
    m_exec_query = new wxButton(this, 1006, wxT("ВЫПОЛНИТЬ"), wxPoint(20, 550),
            wxDefaultSize);

    m_text_input = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxPoint(20, 20),
            wxSize(580,500), wxTE_MULTILINE);
      m_text_output = new wxStaticText(this, -1, wxT("rbpanel"), wxPoint(20, 550),
              wxSize(580, 500));

}

void RightPanel::executeInputedQuery()
{

    wxLocale qw(wxLANGUAGE_RUSSIAN);
    m_rightTableResult = ((Communicate *)m_parent->GetParent())->m_rbp->m_text;

    std::string query(m_text_input->GetValue().mb_str());
    std::cout << query << "INputer qyue\n";
    Compiler* comp = ((Communicate *)m_parent->GetParent())->comp;
    Parser* parser = new SyntaxParser(query);
    FileHandler* fh = ((Communicate *)m_parent->GetParent())->fh;
    ExecuteMachine* me = ((Communicate *)m_parent->GetParent())->mc;
 
    comp->setQuery(query);
    parser->setQuery(query);
    
    Tree* selectTree = new SelectTree(query);
    comp->compile(parser, selectTree);
    std::map<std::string, std::string> plan = comp->get_plan();
    me->execute(plan, fh);

    m_rightTableResult->Clear();
    m_rightTableResult->Refresh();

    m_rightTableResult->ChangeValue(me->getTableResult());

  
 
    delete parser;
 
};





