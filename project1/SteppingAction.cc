#include "SteppingAction.hh"
#include "EventAction.hh"
#include "G4VUserDetectorConstruction.hh"
#include "construction.hh"

#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"

SteppingAction::SteppingAction(EventAction* eventAction)
:G4UserSteppingAction(), fEventAction(eventAction)
{
    //fEventAction = eventAction;
}

SteppingAction::~SteppingAction()
{}

void SteppingAction::UserSteppingAction(const G4Step* step)
{
// Collect energy and track length step by step

  // get volume of the current step
  auto volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume();
  
  G4Track* track = step->GetTrack();
  
  G4double KineticEnergy = track->GetKineticEnergy();
  // energy deposit
  //auto edep = step->GetTotalEnergyDeposit();
  G4double edepStep = step->GetTotalEnergyDeposit();
  fEventAction->AddEdep(edepStep);
  
  if (edepStep <= 0.)
      G4cout<<KineticEnergy<<G4endl;
      return;
  
  // step length
  G4double stepLength = 0.;
  if ( step->GetTrack()->GetDefinition()->GetPDGCharge() != 0. ) {
    stepLength = step->GetStepLength();
  }
 
 //G4cout<<"KineticEnergy= "<<KineticEnergy<<G4endl;
}
