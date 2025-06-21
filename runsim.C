/** --------------------------------------------------------------------
 **
 **  Define the SOFIA simulation setup for p2p-fission experiments
 **  Author: <j.l.rodriguez.sanchez@udc.es>
 **
 **  Last Update: 22/07/21
 **  Comments:
 **         - 22/07/21 : Initial setup
 **
 **  Configuration:
 **  (1) Select the right generator "fGenerator"
 **  (2) Select the detectors that you wish for the simulation, for instance,
 *"fCalifa = true"
 **  (3) Look at the file "s455_setup.par" that the positions of your detectors
 *are right
 **
 **  Execute it as follows:
 **  root -l 'runsim.C(1000)'
 **  where 1000 means the number of events
 **
 **/

void runsim(Int_t nEvents = 100) {
  // ----------- Configuration area ----------------------------------

  FairLogger::GetLogger()->SetLogVerbosityLevel("low");
  FairLogger::GetLogger()->SetColoredLog(true);

  TString OutFile = " sim_real17_7mm_deadL.root"; // Output file for data
  TString ParFile = "par.root"; // Output file for params

  Bool_t fVis = true;             // Store tracks for visualization
  Bool_t fUserPList = false;      // Use of R3B special physics list
  Bool_t fR3BMagnet = false;      // Magnetic field definition
  Bool_t fCalifaDigitizer = true; // Apply hit digitizer task
  Bool_t fCalifaHitFinder = true; // Apply hit finder task

  // MonteCarlo engine: TGeant3, TGeant4, TFluka  --------------------
  TString fMC = "TGeant4";

  // Event generator type: box for particles or ascii&inclroot for p2p-fission
  TString generator1 = "box";
  TString generator2 = "ascii";
  TString generator3 = "inclroot";
  TString fGenerator = generator2;

  // Input event file in the case of ascii generator
  TString fEventFile;
  if (fGenerator.CompareTo("ascii") == 0)
      fEventFile = "quasi_ascii.txt";
  else if (fGenerator.CompareTo("inclroot") == 0)
    fEventFile = "p_U238_560.root";



  // ---------  Detector selection: true - false ---------------------
  // ---- R3B and SOFIA detectors as well as passive elements

  Bool_t fTracker = true; // AMS-Tracker + Vacuum chamber + LH2 target
 // TString fTrackerGeo = "/shared/storage/physnp/xjb519/R3BRoot/geometry/target_area_alpide_twoarms_v24.geo.root";
 //TString fTrackerGeo = "target_area_alpide_barrels_idealv2026.geo.root";
  TString fTrackerGeo =  "target_area_alpide_barrels_new8_thinner_7mmv2026.geo.root";
  //TString fTrackerGeo = "target_area_alpide_barrels_idealv2026.geo.root";
  Bool_t fCalifa = false; // Califa Calorimeter
  TString fCalifaGeo = "califa_full.geo.root";
  Int_t fCalifaGeoVer = 2022;
  Double_t fCalifaCryTh = 0.000080; // In GeV: 0.000080 means 80 keV per crystal
  Double_t fCalifaHitEnergyTh = 0.0; // Threshold in GeV per cluster hit
  Double_t fCalifaNonU = 0.5; // Non-uniformity: 1 means +-1% max deviation



  // ---- End of Configuration area   ---------------------------------------

  // ---- Stable part   -----------------------------------------------------
  TString dir = gSystem->Getenv("VMCWORKDIR");
  TString r3b_geomdir = dir + "/geometry/";
  gSystem->Setenv("GEOMPATH", r3b_geomdir.Data());
  r3b_geomdir.ReplaceAll("//", "/");

  TString r3b_confdir = dir + "/gconfig/";
  gSystem->Setenv("CONFIG_DIR", r3b_confdir.Data());
  r3b_confdir.ReplaceAll("//", "/");

  // ----    Debug option   -------------------------------------------------
  gDebug = 0;

  // -----   Timer   --------------------------------------------------------
  TStopwatch timer;
  timer.Start();

  // -----   Create simulation run   ----------------------------------------
  FairRunSim *run = new FairRunSim();
  run->SetName(fMC);                           // Transport engine
  run->SetSink(new FairRootFileSink(OutFile)); // Output file
  

  // -----   Runtime data base   --------------------------------------------
  FairRuntimeDb *rtdb = run->GetRuntimeDb();
  
  // -----   Load detector parameters    ------------------------------------
  FairParAsciiFileIo* parIo1 = new FairParAsciiFileIo();
  parIo1->open("/shared/storage/physnp/xjb519/Simulations/twobarrelsconf.par", "in");
    //parIo1->open(parIo1);
    rtdb->setFirstInput(parIo1);
    rtdb->print();

    R3BTGeoPar* targetPar = NULL;
    R3BTGeoPar* califaPar = NULL;
        
    if (fCalifa)
        califaPar = (R3BTGeoPar*)rtdb->getContainer("CalifaGeoPar");


  // -----   R3B Special Physics List in G4 case
 /* if ((fUserPList) && (fMC.CompareTo("TGeant4") == 0)) {
    run->SetUserConfig("g4R3bConfig.C");
    run->SetUserCuts("SetCuts.C");
  }*/

  // -----   Create media   -------------------------------------------------
  run->SetMaterials("media_r3b.geo"); // Materials

  // -----   Create R3B geometry --------------------------------------------

  // Cave definition
  FairModule *cave = new R3BCave("CAVE");
  cave->SetGeometryFileName("r3b_cave_vacuum.geo");
  run->AddModule(cave);

   /*R3BCalifa* califa = new R3BCalifa("califa_full.geo.root");
   califa->SelectGeometryVersion(2022);
   run->AddModule(califa);*/

  


  // Tracker, vacuum chamber and LH2 target definitions
   if (fTracker) 
  {
      TGeoRotation *rtarget = new TGeoRotation("Targetrot");
      rtarget->RotateX(0);
      rtarget->RotateY(0);
      rtarget->RotateZ(0);
      auto tra = new R3BAlpide(fTrackerGeo, {0, 0, 0, rtarget});
     // auto tra2 = new R3BDeadL(fTrackerGeo, {0, 0, 0, rtarget});
      tra->SetEnergyCut(1e-6);
     // tra2->SetEnergyCut(1e-6);	 // 1 keV
      run->AddModule(tra);
     // run->AddModule(tra2);
      
//      auto digi2 = new R3BDeadLDigitizer("DeadL");
 //     digi2->SetLabframe();

    //  run->AddTask(digi2);

      auto digi = new R3BAlpideDigitizer("Alpide");
      //digi->SetLabframe();
      digi->SetSigma(0.0006);
      run->AddTask(digi);
      //auto digi2 = new R3BDeadLDigitizer("DeadL");
      //digi2->SetLabframe();

      //run->AddTask(digi2);
  } 

    // CALIFA Calorimeter
  /* if (fCalifa)
    {
      int fCalifaGeoVer = 2021;
      int  fCalifaNonU = 1.0; // Non-uniformity: 1 means +-1% max deviation


            R3BCalifa* califa = new R3BCalifa(fCalifaGeo, { 0., 0., 0. });
            califa->SelectGeometryVersion(fCalifaGeoVer);
            run->AddModule(califa);
            
        auto *califaDig = new R3BCalifaDigitizer();
        califaDig->SetNonUniformity(fCalifaNonU);
        //califaDig->SetRealConfig(CalifaExpConfig); // Real Configuration goes here
        califaDig->SetExpEnergyRes(5.);            // 5. means 5% at 1 MeV
        //califaDig->SetComponentRes(6.);
        califaDig->SetDetectionThreshold(0.000080); // in GeV!! 0.000010 means 10 keV
        //califaDig->SetParContainers();              // Only if SetRealConfig is set to TRUE!
        run->AddTask(califaDig);
        
        auto *CalifaCal2Cluster = new R3BCalifaCrystalCal2Cluster();
        //CalifaCal2Cluster->IsSimulation(true);
        CalifaCal2Cluster->SetRandomization(kFALSE);
        //CalifaCal2Cluster->SetClusterWindow(0.25);
        CalifaCal2Cluster->SetCrystalThreshold(0.000080); // 70keV
        CalifaCal2Cluster->SetGammaClusterThreshold(0.0);
        CalifaCal2Cluster->SetProtonClusterThreshold(0.0);
        CalifaCal2Cluster->IsSimulation(kTRUE);
        run->AddTask(CalifaCal2Cluster);
    }*/


  // ---- End of field map section

  // -----   Create PrimaryGenerator   --------------------------------------

  // 1 - Create the Main API class for the Generator
  FairPrimaryGenerator *primGen = new FairPrimaryGenerator();

  if (fGenerator.CompareTo("box") == 0) {
    // Define the BOX generator
    Int_t pdgId = 2212;      // proton beam
    Double32_t theta1 = 0.; // polar angle distribution
    Double32_t theta2 = 0.;
    Double32_t momentum = 0.8;
    FairBoxGenerator *boxGen = new FairBoxGenerator(pdgId, 1);
    boxGen->SetThetaRange(theta1, theta2);
    boxGen->SetPRange(momentum,  momentum);
    boxGen->SetPhiRange(0., 0.);
    boxGen->SetXYZ(0.0, 0.0, -20.0);
    primGen->AddGenerator(boxGen);

    // 208-Pb fragment
    auto *ionGen = new FairIonGenerator(92, 238, 92, 1, 0., 0., 1.10, 0., 0., -6.);
    //primGen->AddGenerator(ionGen);
    
    //FairIonGenerator *ionGen =  new FairIonGenerator(6, 12, 6, 1, 0., 0., 1.10, 0., 0., -6.);
    //primGen->AddGenerator(ionGen);
    
    
    auto *califagen = new R3BCALIFATestGenerator(pdgId, 1);
    califagen->SetCosTheta();
    califagen->SetThetaRange(7., 180.);
    califagen->SetPRange(momentum, momentum);
    califagen->SetPhiRange(0., 360.);
    califagen->SetLorentzBoost(0.75);
    //califagen->SetBoxXYZ(-0.1,-0.1,-0.75,0.1,0.1,0.75);
    califagen->SetBoxXYZ(-0.1,-0.1,-0.75,0.1,0.1,4.25);//5cm
    //primGen->AddGenerator(califagen);
  }
  
  if (fGenerator.CompareTo("ascii") == 0)
    {
        R3BAsciiGenerator* gen = new R3BAsciiGenerator((dir + "/input/p2p/" + fEventFile).Data());
         //gen->SetXYZ(0., 0., 0.);
      //  gen->SetDxDyDz(0.1, 0.1, 1.5); // Dx, Dy, Lh2-Length=1.5cm
        //gen->SetDxDyDz(0.1, 0.1, 5.);// Dx, Dy, Lh2-Length=5cm
        primGen->AddGenerator(gen);
    }


    if (fGenerator.CompareTo("inclroot") == 0)
    {
        R3BINCLRootGenerator* gen = new R3BINCLRootGenerator((dir + "/../inclglab/buildsrc/" + fEventFile).Data());
        //gen->SetOnlyFission(kTRUE);
        gen->SetOnlyP2pFission(kTRUE);
        gen->SetXYZ(0., 0., 0.);
        gen->SetDxDyDz(0., 0., 0.);
        primGen->AddGenerator(gen);
    }

  run->SetGenerator(primGen);

  //-------Set visualisation flag to true------------------------------------
  run->SetStoreTraj(fVis);



  // -----   Initialize simulation run   ------------------------------------
  run->Init();

  // -----   Runtime database   ---------------------------------------------
  Bool_t kParameterMerged = kTRUE;
  FairParRootFileIo *parOut = new FairParRootFileIo(kParameterMerged);
  parOut->open(ParFile.Data());
  rtdb->setOutput(parOut);
  rtdb->saveOutput();
  rtdb->print();

  // -----   Start run   ----------------------------------------------------
  if (nEvents > 0)
    run->Run(nEvents);

  // -----   Finish   -------------------------------------------------------
  timer.Stop();
  Double_t rtime = timer.RealTime() / 60.;
  Double_t ctime = timer.CpuTime() / 60.;
  cout << endl << endl;
  cout << "Macro finished succesfully." << endl;
  cout << "Output file is " << OutFile << endl;
  cout << "Parameter file is " << ParFile << endl;
  cout << "Real time " << rtime << " min, CPU time " << ctime << " min" << endl
       << endl;

  cout << " Test passed" << endl;
  cout << " All ok " << endl;
  gApplication->Terminate();
}
