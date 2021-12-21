#include "Panels.h"
#include <wx/wxprec.h>
#include "./../../FileHandlerPI/FileHandler.h"
#include "./../../CompilersPI/Tree.h"
#include "./../../CompilersPI/SelectTree.h"
#include "./../../CompilersPI/Compiler.h"
#include "./../../CompilersPI/Parser.h"
#include "./../../CompilersPI/SyntaxParser.h"
#include "./../../CompilersPI/Node.h"
#include "./../../ExecMachine/ExecuteMachine.h"


class Communicate : public wxFrame
{
public:
    Communicate(const wxString& title);

   
    LeftPanel *m_lp;
    RightPanel *m_rp;
    RightBottomPanel *m_rbp;
    wxPanel *m_parent;
   
    ExecuteMachine* mc ;
    FileHandler* fh  ;
    Tree* selectTree ;
    Parser* sp ;
    Compiler* comp ; 

    void OnRefresh(wxCommandEvent& event);
    void OnExecuteQuery(wxCommandEvent& event);
    DECLARE_EVENT_TABLE()
};
