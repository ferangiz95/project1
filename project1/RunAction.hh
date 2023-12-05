#ifndef RunAction_HH
#define RunAction_HH

#include "G4UserRunAction.hh"
//#include "G4Run.hh"
#include "globals.hh"

//class G4Run;

class RunAction : public G4UserRunAction
{
  public:
    RunAction();
    ~RunAction() override = default;

    void BeginOfRunAction(const G4Run*) override;
    void   EndOfRunAction(const G4Run*) override;
};

#endif

