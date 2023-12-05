#include "construction.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4NistManager.hh"
#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4VisAttributes.hh"

DetectorConstruction::DetectorConstruction()
{}

DetectorConstruction::~DetectorConstruction()
{}

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  G4NistManager* nist = G4NistManager::Instance();
  
  G4double world_x = 2.0 * m;
  G4double world_y = 3.0 * m; 
  G4double world_z = 3.0 * m;
  
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");
  G4bool checkOverlaps = true;
  
  G4double log_x = 0.5 * world_x;
  G4double log_y = 0.5 * world_y;
  G4double log_z = 0.5 * world_z;
  G4Material* world_log = nist->FindOrBuildMaterial("G4_Cu");
  G4Material* inner_log = nist->FindOrBuildMaterial("G4_lAr");

  G4Box *SolidWorld = new G4Box("World", 0.5 * world_x, 0.5 * world_y, 0.5 * world_z);       

  G4LogicalVolume *logicWorld = new G4LogicalVolume(SolidWorld,  
                                                    world_mat,                                       
                                                    "World");                                       

  G4VPhysicalVolume* physWorld = new G4PVPlacement(nullptr,
                                                   G4ThreeVector(),                           
                                                   logicWorld,                                
                                                   "World",                                   
                                                   nullptr,                                  
                                                   false,                                     
                                                   0,                                         
                                                   checkOverlaps);                            

  G4Box *solidlog = new G4Box("Log", 0.5 * log_x, 0.5 * log_y, 0.5 * log_z);           

  G4LogicalVolume *logiclog = new G4LogicalVolume(solidlog,  
                                                  world_log, //  LAr                            
                                                  "Log");                                     

  G4VPhysicalVolume* physlog = new G4PVPlacement(nullptr,
                                                 G4ThreeVector(),          
                                                 logiclog,                
                                                 "Log",                    
                                                 logicWorld,              
                                                 false,                   
                                                 0,                        
                                                 checkOverlaps);           

  
  G4VisAttributes* blue = new G4VisAttributes(G4Colour::Blue());
  blue->SetVisibility(true);
  blue->SetForceWireframe(true);
  logiclog->SetVisAttributes(blue);

  G4Box *solidlog2 = new G4Box("Log2", 0.3 * log_x, 0.3 * log_y, 0.3 * log_z);           

  G4LogicalVolume *logiclog2 = new G4LogicalVolume(solidlog2,  
                                                  inner_log, //  LAr                             
                                                  "Log2");                                     

  G4VPhysicalVolume* physlog2 = new G4PVPlacement(nullptr,
                                                 G4ThreeVector(),          
                                                 logiclog2,                
                                                 "Log2",                    
                                                 logiclog,              
                                                 false,                   
                                                 0,                        
                                                 checkOverlaps);           

  
  G4VisAttributes* green = new G4VisAttributes(G4Colour::Green());
  green->SetVisibility(true);
  green->SetForceWireframe(true);
  logiclog2->SetVisAttributes(green);



  return physWorld; 
}
