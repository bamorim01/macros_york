//
//   ----- Silicon PIxel DEtector for R3B (SPIDER):
//         Barrel geometry macro
//
//         Author: Jose Luis <j.l.rodriguez.sanchez@udc.es>
//         University of Coruña, Spain
//         Last Update: 23/07/24 (Jose Luis)
//
//         Comments:
//

#include "TGeoManager.h"
#include "TMath.h"
#include <iomanip>
#include <iostream>

void create_target_area_2026_thicker_geo_new6_deadL_version2(const char *geoTag = "v2026") 
{
  // --------------------------------------------------------------------------
  // Configurable geometry for the target vacuum chamber according to the
  // e-mail on 1st October 2019.
  // Use this macro to create root files with the different configurations
  // and positions of the vacuum chamber.
  //
  // Execute macro:  root -l
  //                 .L create_target_area_2026_thicker_geo.C
  //                 create_target_area_2026_thicker_geo()
  //             or
  //                 root -l 'create_target_area_2026_thicker_geo("v2026_xx")'
  // --------------------------------------------------------------------------

  TGeoRotation *fRefRot = NULL;
  TGeoManager *gGeoMan = NULL;

  // -------   Load media from media file   -----------------------------------
  FairGeoLoader *geoLoad = new FairGeoLoader("TGeo", "FairGeoLoader");
  FairGeoInterface *geoFace = geoLoad->getGeoInterface();
  TString geoPath = gSystem->Getenv("VMCWORKDIR");
  TString medFile = geoPath + "/geometry/media_r3b.geo";
  geoFace->setMediaFile(medFile);
  geoFace->readMedia();
  gGeoMan = gGeoManager;
  // --------------------------------------------------------------------------

  // -------   Geometry file name (output)   ----------------------------------
  TString geoFileName = geoPath  + "/geometry/target_area_alpide_barrels_new8_thinner_7mm";
  geoFileName = geoFileName + geoTag + ".geo.root";
  // --------------------------------------------------------------------------

  // -----------------   Get and create the required media    -----------------
  FairGeoMedia *geoMedia = geoFace->getMedia();
  FairGeoBuilder *geoBuild = geoLoad->getGeoBuilder();

  FairGeoMedium *mVac = geoMedia->getMedium("vacuum");
  if (!mVac)
    Fatal("Main", "FairMedium vacuum not found");
  geoBuild->createMedium(mVac);
  TGeoMedium *pMedVac = gGeoMan->GetMedium("vacuum");
  if (!pMedVac)
    Fatal("Main", "Medium vacuum not found");

  FairGeoMedium *mCu = geoMedia->getMedium("copper");
  if (!mCu)
    Fatal("Main", "FairMedium copper not found");
  geoBuild->createMedium(mCu);
  TGeoMedium *pMed1 = gGeoMan->GetMedium("copper");
  if (!pMed1)
    Fatal("Main", "Medium copper not found");

  FairGeoMedium *mAl = geoMedia->getMedium("aluminium");
  if (!mAl)
    Fatal("Main", "FairMedium aluminium not found");
  geoBuild->createMedium(mAl);
  TGeoMedium *pMed2 = gGeoMan->GetMedium("aluminium");
  if (!pMed2)
    Fatal("Main", "Medium aluminium not found");

  FairGeoMedium *mSteel = geoMedia->getMedium("Steel");
  if (!mSteel)
    Fatal("Main", "FairMedium Steel not found");
  geoBuild->createMedium(mSteel);
  TGeoMedium *pMed3 = gGeoMan->GetMedium("Steel");
  if (!pMed3)
    Fatal("Main", "Medium Steel not found");

  FairGeoMedium *mMylar = geoMedia->getMedium("mylar");
  if (!mMylar)
    Fatal("Main", "FairMedium mylar not found");
  geoBuild->createMedium(mMylar);
  TGeoMedium *pMed4 = gGeoMan->GetMedium("mylar");
  if (!pMed4)
    Fatal("Main", "Medium mylar not found");

  FairGeoMedium *mH2 = geoMedia->getMedium("H2");
  if (!mH2)
    Fatal("Main", "FairMedium H2 not found");
  geoBuild->createMedium(mH2);
  TGeoMedium *pMed5 = gGeoMan->GetMedium("H2");
  if (!pMed5)
    Fatal("Main", "Medium H2 not found");

  FairGeoMedium *mSi = geoMedia->getMedium("silicon");
  if (!mSi)
    Fatal("Main", "FairMedium silicon not found");
  geoBuild->createMedium(mSi);
  TGeoMedium *pMedSi = gGeoMan->GetMedium("silicon");
  if (!pMedSi)
    Fatal("Main", "Medium silicon not found");
    
  FairGeoMedium *mCCooling = geoMedia->getMedium("carboncooling");
  if (!mCCooling)
    Fatal("Main", "FairMedium carboncooling not found");
  geoBuild->createMedium(mCCooling);
  TGeoMedium *pMed42 = gGeoMan->GetMedium("carboncooling");
  if (!pMed42)
    Fatal("Main", "Medium carboncooling not found");

  FairGeoMedium *mPolyamide = geoMedia->getMedium("polyamide");
  if (!mPolyamide)
    Fatal("Main", "FairMedium polyamide not found");
  geoBuild->createMedium(mPolyamide);
  TGeoMedium *pMed43 = gGeoMan->GetMedium("polyamide");
  if (!pMed43)
    Fatal("Main", "Medium polyamide not found");

  FairGeoMedium *mEpo = geoMedia->getMedium("epoxy");
  if (!mEpo)
    Fatal("Main", "FairMedium epoxy not found");
  geoBuild->createMedium(mEpo);
  TGeoMedium *pMed44 = gGeoMan->GetMedium("epoxy");
  if (!pMed44)
    Fatal("Main", "Medium epoxy not found");
    
  FairGeoMedium *mcg = geoMedia->getMedium("carbonglue");
  if (!mcg)
    Fatal("Main", "FairMedium carbonglue not found");
  geoBuild->createMedium(mcg);
  TGeoMedium *pMed45 = gGeoMan->GetMedium("carbonglue");
  if (!pMed45)
    Fatal("Main", "Medium carbonglue not found"); 

  FairGeoMedium *mcf = geoMedia->getMedium("carbonfleece");
  if (!mcf)
    Fatal("Main", "FairMedium carbonfleece not found");
  geoBuild->createMedium(mcf);
  TGeoMedium *pMed46 = gGeoMan->GetMedium("carbonfleece");
  if (!pMed46)
    Fatal("Main", "Medium carbonfleece not found");  
    
  FairGeoMedium *mks = geoMedia->getMedium("kaptonsubs");
  if (!mks)
    Fatal("Main", "FairMedium kaptonsubs not found");
  geoBuild->createMedium(mks);
  TGeoMedium *pMed47 = gGeoMan->GetMedium("kaptonsubs");
  if (!pMed47)
    Fatal("Main", "Medium kaptonsubs not found"); 
    
  FairGeoMedium *mGold = geoMedia->getMedium("gold");
  if (!mGold)
    Fatal("Main", "FairMedium gold not found");
  geoBuild->createMedium(mGold);
  TGeoMedium *pMedGold = gGeoMan->GetMedium("gold");
  if (!pMedGold)
    Fatal("Main", "Medium gold not found"); 

  //pMed5=pMed1=pMed2=pMed3=pMed4=pMed47=pMed46=pMed45=pMed44=pMed43=pMed42=pMedSi=pMedVac;
  

  // --------------   Create geometry and top volume  -------------------------
  gGeoMan = (TGeoManager *)gROOT->FindObject("FAIRGeom");
  gGeoMan->SetName("TARGETAREAgeom");
  TGeoVolume *top = new TGeoVolumeAssembly("TOP");
  gGeoMan->SetTopVolume(top);
  // --------------------------------------------------------------------------

  Double_t offsetZ =
      -0.75 * 2. +
       2.875; // offset with respect to LH2 target cell, entrance at (0,0,-0.75);
  double general_zoffset = -0.75;
  // Mylar windows for LH2 target
  Double_t thinMylar1 = 0.012 / 2.0; // 120micra entrance window
  Double_t thinMylar2 = 0.018 / 2.0; // 180micra exit window
  Double_t LH2targetR = 2. - thinMylar2 * 2.0; // Radius of 2 cm - mylar cylindre
  Double_t LH2targetL = 1.5;  // Length 1.5cm

  // Defintion of the Mother Volume
  auto Part1 = new TGeoTube("Part1", 0., 27., 64. / 2.0);
  auto trans1 = new TGeoCombiTrans("trans1", 0., 0., -25.5+0.75, fRefRot);
  trans1->RegisterYourself();
  
  auto Part2 = new TGeoSphere("Part2", 0., 27., 0., 90., 0., 360.);
  auto trans2 = new TGeoCombiTrans("trans2", 0, 0, 6.0+0.75, fRefRot);
  trans2->RegisterYourself();

  auto Part3 = new TGeoCone("Part3", 39./ 2., 0., 4.61, 0., 7.4);
  auto trans3 = new TGeoCombiTrans("trans3", 0., 0., 5.95+26.4 + 33.8/ 2.+0.75, fRefRot);
  trans3->RegisterYourself();
  
  auto Part4 = new TGeoTube("Part4", 0., 10., 1.2);
  auto trans4 = new TGeoCombiTrans("trans4", 0., 0., 6.775000 - 0.9 + 28.812028 + 33.688 + 1. +0.75, fRefRot);
  trans4->RegisterYourself();
  
  auto Part5 = new TGeoTube("Part5", 26., 29.25, 1.9);
  auto trans5 = new TGeoCombiTrans("trans5", 0., 0., -42.1250 +0.75, fRefRot);
  trans5->RegisterYourself();

  auto pVCWorld = new TGeoCompositeShape("VCbox", "Part1:trans1 + Part2:trans2 + Part3:trans3 + Part4:trans4+ Part5:trans5");
  TGeoVolume *pWorld = new TGeoVolume("TargetChamberWorld", pVCWorld, pMedVac);

  auto t0 = new TGeoCombiTrans(0., 0., 0., fRefRot);
  top->AddNode(pWorld, 0, t0);

  Double_t dx, dy, dz;
  Double_t thx, thy, thz;
  Double_t phx, phy, phz;

  //-------- Chamber
  //-------------------------------------------------------------------------
  Double_t parChamberBarrel[3] = {26.0, 26.4, (46.3 / 2.)};
  TGeoTube *pChamberBarrel = new TGeoTube(parChamberBarrel);
  TGeoVolume *pChamberBarrelLog =
      new TGeoVolume("ChamberBarrelLog", pChamberBarrel, pMed2);
  pChamberBarrelLog->SetVisLeaves(kTRUE);
  pChamberBarrelLog->SetLineColor(34);

  dx = 0.000000;
  dy = 0.000000;
  dz = -42.1250 + 1.7 + 46.3 / 2. + offsetZ + general_zoffset;
  TGeoRotation *rot0 = new TGeoRotation();
  TGeoCombiTrans *pMatrix169 = new TGeoCombiTrans("", dx, dy, dz, rot0);
  pWorld->AddNode(pChamberBarrelLog, 0, pMatrix169);

  // chamber Inner
  Double_t parChamberBarrelIn[3] = {9.625, (9.625 + 2.2), (37.57 / 4.)};
  TGeoTube *pChamberBarrelIn = new TGeoTube(parChamberBarrelIn);
  TGeoVolume *pChamberBarrelInLog =
      new TGeoVolume("ChamberBarrelInLog", pChamberBarrelIn, pMed2);
  pChamberBarrelInLog->SetVisLeaves(kTRUE);
  pChamberBarrelInLog->SetLineColor(34);

  dx = 0.000000;
  dy = 0.000000;
  dz = -37.54000 - 37.57 / 4. + offsetZ + general_zoffset;
  TGeoCombiTrans *pMatrix170 = new TGeoCombiTrans("", dx, dy, dz, rot0);
  pWorld->AddNode(pChamberBarrelInLog, 0, pMatrix170);

  // Inner support
  Double_t parChamberIn[3] = {0., 0.6, ((37.57 - 0.9) / 2.)};
  TGeoTube *pChamberIn = new TGeoTube(parChamberIn);
  TGeoVolume *pChamberInLog = new TGeoVolume("ChamberInLog", pChamberIn, pMed2);
  pChamberInLog->SetVisLeaves(kTRUE);
  pChamberInLog->SetLineColor(34);

  dx = 9.6 - 0.6;
  dy = 0.000000;
  dz = -37.54000 + 0.45 + offsetZ + general_zoffset;
  TGeoCombiTrans *pMatrix100 = new TGeoCombiTrans("", dx, dy, dz, rot0);
  pWorld->AddNode(pChamberInLog, 0, pMatrix100);

  dx = -(9.6 - 0.6);
  dy = 0.000000;
  dz = -37.54000 + 0.45 + offsetZ + general_zoffset;
  TGeoCombiTrans *pMatrix101 = new TGeoCombiTrans("", dx, dy, dz, rot0);
  pWorld->AddNode(pChamberInLog, 1, pMatrix101);

  dy = -(9.6 - 0.6);
  dx = 0.000000;
  dz = -37.54000 + 0.45 + offsetZ + general_zoffset;
  TGeoCombiTrans *pMatrix102 = new TGeoCombiTrans("", dx, dy, dz, rot0);
  pWorld->AddNode(pChamberInLog, 2, pMatrix102);

  dy = (9.6 - 0.6);
  dx = 0.000000;
  dz = -37.54000 + 0.45 + offsetZ + general_zoffset;
  TGeoCombiTrans *pMatrix103 = new TGeoCombiTrans("", dx, dy, dz, rot0);
  pWorld->AddNode(pChamberInLog, 3, pMatrix103);

  Double_t parChamberIn2[3] = {7.6, 9.625, (0.9 / 2.)};
  TGeoTube *pChamberIn2 = new TGeoTube(parChamberIn2);
  TGeoVolume *pChamberIn2Log =
      new TGeoVolume("ChamberIn2Log", pChamberIn2, pMed2);
  pChamberIn2Log->SetVisLeaves(kTRUE);
  pChamberIn2Log->SetLineColor(17);

  dx = 0.000000;
  dy = 0.000000;
  dz = -17.8550 - 0.9 - 37.57 + 0.45 + offsetZ + general_zoffset;
  TGeoCombiTrans *pMatrix104 = new TGeoCombiTrans("", dx, dy, dz, rot0);
  pWorld->AddNode(pChamberIn2Log, 3, pMatrix104);

  Double_t parChamberEndPlate[3] = {(9.625 + 2.2), 29.25, 1.7};
  TGeoTube *pChamberEndPlate = new TGeoTube(parChamberEndPlate);
  TGeoVolume *pChamberEndPlateLog =
      new TGeoVolume("ChamberEndPlateLog", pChamberEndPlate, pMed2);
  pChamberEndPlateLog->SetVisLeaves(kTRUE);
  pChamberEndPlateLog->SetLineColor(34);

  dx = 0.000000;
  dy = 0.000000;
  dz = -42.1250 + offsetZ + general_zoffset;
  TGeoCombiTrans *pMatrix174 = new TGeoCombiTrans("", dx, dy, dz, rot0);
  pWorld->AddNode(pChamberEndPlateLog, 0, pMatrix174);

  Double_t parChamberEndPlateIn[3] = {(3.8), (9.625 + 2.2), 0.45};
  TGeoTube *pChamberEndPlateIn = new TGeoTube(parChamberEndPlateIn);
  TGeoVolume *pChamberEndPlateInLog =
      new TGeoVolume("ChamberEndPlateInLog", pChamberEndPlateIn, pMed2);
  pChamberEndPlateInLog->SetVisLeaves(kTRUE);
  pChamberEndPlateInLog->SetLineColor(34);

  dx = 0.000000;
  dy = 0.000000;
  dz = -17.8550 - 0.45 + offsetZ + general_zoffset;
  TGeoCombiTrans *pMatrix175 = new TGeoCombiTrans("", dx, dy, dz, rot0);
  pWorld->AddNode(pChamberEndPlateInLog, 0, pMatrix175);

  Double_t parTargetEndPlateIn[3] = {(LH2targetR + thinMylar2 * 2.0), 2.44,
                                     0.75};
  TGeoTube *pTargetEndPlateIn = new TGeoTube(parTargetEndPlateIn);
  TGeoVolume *pTargetEndPlateInLog =
      new TGeoVolume("TargetEndPlateLog", pTargetEndPlateIn, pMed2);
  pTargetEndPlateInLog->SetVisLeaves(kTRUE);
  pTargetEndPlateInLog->SetLineColor(46);

  dx = 0.000000;
  dy = 0.000000;
  dz = 0.75000 - 0.75 + general_zoffset;
  TGeoCombiTrans *pMatrix176 = new TGeoCombiTrans("", dx, dy, dz, rot0);
  pWorld->AddNode(pTargetEndPlateInLog, 0, pMatrix176);

  TGeoSphere *SphereChamber =
      new TGeoSphere("SphereChamber", 26.0, 26.4, 15.26, 90., 0., 360.);

  dx = 0.000000;
  dy = 0.000000;
  dz = 6.775000 - 0.9;
  TGeoCombiTrans *pMatrix177 = new TGeoCombiTrans("", dx, dy, dz, rot0);

  Double_t parTargetEndPlateOut[3] = {7.0, 10., 1.};
  TGeoTube *pTargetEndPlateOut = new TGeoTube(parTargetEndPlateOut);
  TGeoVolume *pTargetEndPlateOutLog =
      new TGeoVolume("TargetEndPlateOutLog", pTargetEndPlateOut, pMed2);
  pTargetEndPlateOutLog->SetVisLeaves(kTRUE);
  pTargetEndPlateOutLog->SetLineColor(34);

  dx = 0.000000;
  dy = 0.000000;
  dz = 6.775000 - 0.9 + 28.812028 + 33.688 + 1. + offsetZ + general_zoffset;
  TGeoCombiTrans *pMatrix179 = new TGeoCombiTrans("", dx, dy, dz, rot0);
  pWorld->AddNode(pTargetEndPlateOutLog, 0, pMatrix179);

  Double_t parRingOut[5] = {(4.301 + 2.348 + 0.1), 2.048 + 0.3, 2.348 + 0.3, 0.,
                            360.};
  TGeoTorus *pRingOut = new TGeoTorus(parRingOut);

  Double_t parCone[5] = {(1.9), 4.601, 10., 4.601, 10.};
  TGeoCone *pCone = new TGeoCone(parCone);

  dx = 0.000000;
  dy = 0.000000;
  dz = 1.;
  TGeoCombiTrans *pMatrixSub = new TGeoCombiTrans("", dx, dy, dz, rot0);

  TGeoSubtraction *pSub1 = new TGeoSubtraction(pRingOut, pCone, 0, pMatrixSub);

  TGeoSphere *Sphere = new TGeoSphere("Sphere", 26.6, 30., 15.2, 25., 0., 360.);

  TGeoShape *pROutb = new TGeoCompositeShape("pROutb", pSub1);

  dx = 0.000000;
  dy = 0.000000;
  dz = -26.4 - 1.5;
  TGeoCombiTrans *pMatrixSub1 = new TGeoCombiTrans("", dx, dy, dz, rot0);

  TGeoSubtraction *pSub2 = new TGeoSubtraction(pROutb, Sphere, 0, pMatrixSub1);

  TGeoShape *pRingOutb1 = new TGeoCompositeShape("pRingOutb1", pSub2);

  Double_t parChamberCone[5] = {(33.688 / 2.), 4.301, 4.601, 7.0, 7.3};
  TGeoCone *pChamberCone = new TGeoCone(parChamberCone);

  dx = 0.000000;
  dy = 0.000000;
  dz = 6.775000 - 0.9 + 28.812028 + 33.688 / 2.0;
  TGeoCombiTrans *pMatrix178 = new TGeoCombiTrans("", dx, dy, dz, rot0);

  dx = 0.0000;
  dy = 0.0000;
  dz = 6.775000 - 0.9 + 28.812028 - 2.348 / 2. + 0.15;
  TGeoCombiTrans *pMatrix180 = new TGeoCombiTrans("", dx, dy, dz, rot0);

  TGeoUnion *pBoolNode0 =
      new TGeoUnion(pChamberCone, pRingOutb1, pMatrix178, pMatrix180);

  TGeoShape *pRingOutb = new TGeoCompositeShape("pNode0", pBoolNode0);

  TGeoUnion *pBoolNode1 =
      new TGeoUnion(pRingOutb, SphereChamber, 0, pMatrix177);

  TGeoShape *pFrontChamber =
      new TGeoCompositeShape("pFrontChamber", pBoolNode1);

  TGeoVolume *pFrontChamber_log =
      new TGeoVolume("FrontChamber", pFrontChamber, pMed2);
  pFrontChamber_log->SetVisLeaves(kTRUE);
  pFrontChamber_log->SetLineColor(34);

  dx = 0.0000;
  dy = 0.0000;
  dz = offsetZ + general_zoffset;
  TGeoCombiTrans *pMatrix220 = new TGeoCombiTrans("", dx, dy, dz, rot0);
  pWorld->AddNode(pFrontChamber_log, 0, pMatrix220);

  Double_t parCoolRingIn[5] = {2., 0.2, 0.35, 0., 90.};
  TGeoTorus *pCoolRingIn = new TGeoTorus(parCoolRingIn);
  TGeoVolume *pCoolRingIn_log =
      new TGeoVolume("CoolRingIn", pCoolRingIn, pMed1);
  pCoolRingIn_log->SetVisLeaves(kTRUE);
  pCoolRingIn_log->SetLineColor(46);

  dx = 0.000000;
  dy = 2.440000;
  dz = -2. + offsetZ+ general_zoffset-1.5;
  TGeoRotation *rot1 = new TGeoRotation();
  rot1->RotateY(-90.0);
  TGeoCombiTrans *pMatrix5 = new TGeoCombiTrans("", dx, dy, dz, rot1);
  pWorld->AddNode(pCoolRingIn_log, 0, pMatrix5);

  Double_t parCoolRingIn2[5] = {2., 0.2, 0.35, 270., 90.};
  TGeoTorus *pCoolRingIn2 = new TGeoTorus(parCoolRingIn2);
  TGeoVolume *pCoolRingIn2_log =
      new TGeoVolume("CoolRingIn2", pCoolRingIn2, pMed1);
  pCoolRingIn2_log->SetVisLeaves(kTRUE);
  pCoolRingIn2_log->SetLineColor(46);

  dx = 0.000000;
  dy = -2.44000;
  dz = -2. + offsetZ+ general_zoffset-1.5;
  TGeoCombiTrans *pMatrix6 = new TGeoCombiTrans("", dx, dy, dz, rot1);
  pWorld->AddNode(pCoolRingIn2_log, 0, pMatrix6);

  Double_t parCoolPipeIn[3] = {0.2, 0.35, ((17.855 - 1.25 - 0.75-1.5) / 2.)};
  TGeoTube *pCoolPipeIn = new TGeoTube(parCoolPipeIn);
  TGeoVolume *pCoolPipeIn_log =
      new TGeoVolume("CoolPipeIn", pCoolPipeIn, pMed1);
  pCoolPipeIn_log->SetVisLeaves(kTRUE);
  pCoolPipeIn_log->SetLineColor(46);

  dx = 0.000000;
  dy = -2.44000 - 2.;
  dz = -(17.855 - 1.25) / 2. - 1.25 + offsetZ - 0.75 / 2.+ general_zoffset-0.75;
  TGeoCombiTrans *pMatrix7 = new TGeoCombiTrans("", dx, dy, dz, rot0);
  pWorld->AddNode(pCoolPipeIn_log, 0, pMatrix7);

  dy = 2.44000 + 2.;
  TGeoCombiTrans *pMatrix8 = new TGeoCombiTrans("", dx, dy, dz, rot0);
  pWorld->AddNode(pCoolPipeIn_log, 1, pMatrix8);

  // LH2 target --------------------------------------------------------------
  Double_t parTargetH2[3] = {0., LH2targetR, (LH2targetL / 2.0)};
  TGeoTube *pTargetH2 = new TGeoTube(parTargetH2);
  TGeoVolume *pTargetH2Log = new TGeoVolume("TargetH2Log", pTargetH2, pMed5);
  pTargetH2Log->SetVisLeaves(kTRUE);
  pTargetH2Log->SetLineColor(3);

  dx = 0.000000;
  dy = 0.000000;
  dz = LH2targetL / 2.0;
  TGeoCombiTrans *pMatrix9 =
      new TGeoCombiTrans("", dx, dy, dz + general_zoffset, rot0);
  pWorld->AddNode(pTargetH2Log, 0, pMatrix9);

  // Mylar windows for LH2 target
  Double_t parMylar1[3] = {0., LH2targetR + thinMylar2 * 2., thinMylar1};
  TGeoTube *pMylar1 = new TGeoTube(parMylar1);
  TGeoVolume *pMylar1Log =
      new TGeoVolume("MylarWindowEntranceLog", pMylar1, pMed4);
  pMylar1Log->SetVisLeaves(kTRUE);
  pMylar1Log->SetLineColor(12);

  dx = 0.000000;
  dy = 0.000000;
  dz = -thinMylar1;
  TGeoCombiTrans *pMatrix10 =
      new TGeoCombiTrans("", dx, dy, dz + general_zoffset, rot0);
  pWorld->AddNode(pMylar1Log, 0, pMatrix10);

  Double_t parMylar2[3] = {0., LH2targetR + thinMylar2 * 2., thinMylar2};
  TGeoTube *pMylar2 = new TGeoTube(parMylar2);
  TGeoVolume *pMylar2Log = new TGeoVolume("MylarWindowExitLog", pMylar2, pMed4);
  pMylar2Log->SetVisLeaves(kTRUE);
  pMylar2Log->SetLineColor(12);
  dx = 0.000000;
  dy = 0.000000;
  dz = LH2targetL + thinMylar2;
  TGeoCombiTrans *pMatrix11 =
      new TGeoCombiTrans("", dx, dy, dz + general_zoffset, rot0);
 pWorld->AddNode(pMylar2Log, 0, pMatrix11);

  Double_t parMylar3[3] = {LH2targetR, LH2targetR + thinMylar2 * 2.,
                           (LH2targetL / 2.0)};
  TGeoTube *pMylar3 = new TGeoTube(parMylar3);
  TGeoVolume *pMylar3Log = new TGeoVolume("MylarCylindreLog", pMylar3, pMed4);
  pMylar3Log->SetVisLeaves(kTRUE);
  pMylar3Log->SetLineColor(12);
  dx = 0.000000;
  dy = 0.000000;
  dz = LH2targetL / 2.0;
  TGeoCombiTrans *pMatrix12 =
      new TGeoCombiTrans("", dx, dy, dz + general_zoffset, rot0);
  pWorld->AddNode(pMylar3Log, 0, pMatrix12);

  // Exit mylar window for the vacuum chamber
  Double_t parWin[3] = {0., 7., 0.0100 / 2.0}; // 100 micras
  TGeoTube *pWin1 = new TGeoTube(parWin);
  TGeoVolume *pWin1Log = new TGeoVolume("ExitWinLog", pWin1, pMed4);
  pWin1Log->SetVisLeaves(kTRUE);

  dx = 0.000000;
  dy = 0.000000;
  dz = 6.775000 - 0.9 + 28.812028 + 33.688 + 1. + offsetZ + general_zoffset;
  TGeoCombiTrans *pMatrix13 = new TGeoCombiTrans("", dx, dy, dz, rot0);
  pWorld->AddNode(pWin1Log, 0, pMatrix13);

  // ALPIDE barrel configuration
  const int nbsensorpermultilayer1 = 9; // ALPIDE detectors per multilayer flex
  const int nbsensorpermultilayer2 = 9; // ALPIDE detectors per multilayer flex

  const int nbmultilayers1 = 24;//17; // 1st barrel
  const int nbmultilayers2 = 24; // 2nd barrel
  const double rd1 = 5;
  const double rd2 = 5.7;

  float thEpoxy = 0.0030;    // Two, 30 um
  float thAlBand = 0.0010;   // two, 10 um each
  float thKapton = 0.0075;   // One, 75 um
  float thGlue = 0.0040;     // two, 40 um each
  float thAlpide = 0.0050;   // 50 um
  float thPolymide = 0.000;  // two, 0 um each
  float thCooling = 0.0240;  // one, 240 um
  float thCoolingfleece = 0.0020;  // two, 20 um

  // Multilayer flex boards
  float Multilayerlength = 27.20; // cm
  float MultilayerWd = 1.5;       // cm

  // Barrel position with respect to target
  float dzbarrels = Multilayerlength / 2.0; //+ 2.25-0.75;

  auto EpoxyBand = gGeoManager->MakeBox("Epoxy", pMed44, MultilayerWd / 2.0,
                                                thEpoxy / 2., Multilayerlength / 2.0);

  auto C_coolingfleece = gGeoManager->MakeBox("Coolingfleece", pMed46, MultilayerWd / 2.0,
                                        thCoolingfleece / 2., Multilayerlength / 2.0);
  
  auto C_cooling = gGeoManager->MakeBox("Cooling", pMed42, MultilayerWd / 2.0,
                                        thCooling / 2., Multilayerlength / 2.0);
                                        
  auto AlBand = gGeoManager->MakeBox("Al", pMed2, MultilayerWd / 2.0,
                                     thAlBand / 2., Multilayerlength / 2.0);
                                     
  auto KBand = gGeoManager->MakeBox("Kapton", pMed43, MultilayerWd / 2.0,
                                     thKapton / 2., Multilayerlength / 2.0);
                                    
  auto glue = gGeoManager->MakeBox("Glue", pMed43, MultilayerWd / 2.0,
                                   thGlue / 2., Multilayerlength / 2.0);
                
  auto PolymideBand =
      gGeoManager->MakeBox("Polymide", pMed43, MultilayerWd / 2.0,
                           thPolymide / 2., Multilayerlength / 2.0);
             
  auto Alpide =
      gGeoManager->MakeBox("Alpide", pMedSi, 1.38 / 2., thAlpide / 2., 3.0 / 2.);

  auto DeadL = gGeoManager->MakeBox("Alpide", pMedSi, 0.12 / 2., thAlpide / 2., 3.0 / 2.);


  EpoxyBand->SetLineColor(kGreen);
  EpoxyBand->SetVisLeaves(kTRUE);
  C_coolingfleece->SetLineColor(15);
  C_coolingfleece->SetVisLeaves(kTRUE);
  C_cooling->SetLineColor(10);
  C_cooling->SetVisLeaves(kTRUE);
  glue->SetVisLeaves(kTRUE);
  glue->SetLineColor(kBlue);
  Alpide->SetVisLeaves(kTRUE);
  Alpide->SetLineColor(kRed);
  DeadL->SetVisLeaves(kTRUE);
  DeadL->SetLineColor(kBlack);
  AlBand->SetVisLeaves(kTRUE);
  AlBand->SetLineColor(kGray);
  KBand->SetVisLeaves(kTRUE);
  KBand->SetLineColor(42);
  PolymideBand->SetVisLeaves(kTRUE);
  PolymideBand->SetLineColor(kOrange + 3);

  // int nd = 0;
  Char_t buffer[126];
  TGeoVolume *Layer[nbmultilayers1 + nbmultilayers2];
  int barrelid = 1;
  for (Int_t i = 0; i < 2; i++) {
    sprintf(buffer, "Multilayer_%i", i + 1);
    Layer[i] = gGeoManager->MakeBox(buffer, pMedVac, MultilayerWd / 2.0, thCooling/2.0 + thCoolingfleece + thEpoxy +
                                    thAlBand + thKapton / 2.0 + thGlue +
                                        thAlpide / 2.0 + thPolymide,
                                    Multilayerlength / 2.0);

    Layer[i]->SetVisLeaves(kTRUE);
    Layer[i]->SetLineColor(kOrange);

    if (i == 1){
      barrelid = 2;
    }

    float fdy = 0.;
    fdy -= (thCooling / 2.0 +thCoolingfleece+ thEpoxy/2+ thAlBand + thAlpide / 2.0 + thKapton / 2.0 + thGlue + thPolymide);
    
    auto pMatrixd0 = new TGeoCombiTrans("", 0, fdy, 0., fRefRot);
    Layer[i]->AddNode(EpoxyBand, barrelid, pMatrixd0);
    
    fdy += (thEpoxy + thAlBand) * 0.5;
    pMatrixd0 = new TGeoCombiTrans("", 0, fdy, 0., fRefRot);
    Layer[i]->AddNode(AlBand, barrelid, pMatrixd0);
    
    fdy += (thAlBand + thKapton) * 0.5;
    pMatrixd0 = new TGeoCombiTrans("", 0, fdy, 0., fRefRot);
    Layer[i]->AddNode(KBand, barrelid, pMatrixd0);
    
    fdy += (thKapton + thAlBand) * 0.5;
    pMatrixd0 = new TGeoCombiTrans("", 0, fdy, 0., fRefRot);
    Layer[i]->AddNode(AlBand, barrelid, pMatrixd0);
    
    fdy += (thAlBand + thEpoxy) * 0.5;
    pMatrixd0 = new TGeoCombiTrans("", 0, fdy, 0., fRefRot);
    Layer[i]->AddNode(EpoxyBand, barrelid, pMatrixd0);

    fdy += (thEpoxy + thGlue) * 0.5;
    pMatrixd0 = new TGeoCombiTrans("", 0, fdy, 0., fRefRot);
    Layer[i]->AddNode(glue, barrelid, pMatrixd0);

    fdy += (thGlue + thAlpide) * 0.5;

    if (barrelid == 1) {
      for (Int_t d = 0; d < nbsensorpermultilayer1; d++) {
	//char nameAlpide[64];
	//sprintf(nameAlpide, "Alpide_%d", d+1);
	//TGeoVolume* alpideVol = new TGeoVolume(nameAlpide, Alpide->GetShape(), Alpide->GetMedium());
	//alpideVol->SetLineColor(Alpide->GetLineColor());
        //alpideVol->SetVisLeaves(Alpide->IsVisLeaves());

        pMatrixd0 = new TGeoCombiTrans("", 0.06, fdy,  1.6 -Multilayerlength / 2.0 + 3.0002 * d, fRefRot);
        Layer[i]->AddNode(Alpide, d + 1, pMatrixd0);

	//char nameDeadL[64];
	//sprintf(nameDeadL, "DeadL_%d", d+1);
	//TGeoVolume* deadLVol = new TGeoVolume(nameDeadL, DeadL->GetShape(), DeadL->GetMedium());

	pMatrixd0 = new TGeoCombiTrans("",-0.69, fdy, 1.6 -Multilayerlength / 2.0 + 3.0002 * d, fRefRot);
	Layer[i]->AddNode(DeadL, d + 432, pMatrixd0);
      }
    } else {
      for (Int_t d = 0; d < nbsensorpermultilayer2; d++) {
	//char nameAlpide[64];
        //sprintf(nameAlpide, "Alpide_%d", d+1);
        //TGeoVolume* alpideVol = new TGeoVolume(nameAlpide, Alpide->GetShape(), Alpide->GetMedium());
	//alpideVol->SetLineColor(Alpide->GetLineColor());
        //alpideVol->SetVisLeaves(Alpide->IsVisLeaves());
	pMatrixd0 = new TGeoCombiTrans("",0.06, fdy, 1.6 -Multilayerlength / 2.0 + 3.0002 * d, fRefRot);
        Layer[i]->AddNode(Alpide, d + 1, pMatrixd0);


	//char nameDeadL[64];
	///sprintf(nameDeadL, "DeadL_%d", d+1);
	//TGeoVolume* deadLVol = new TGeoVolume(nameDeadL, DeadL->GetShape(), DeadL->GetMedium());
	pMatrixd0 = new TGeoCombiTrans("",-0.69, fdy, 1.6 -Multilayerlength / 2.0 + 3.0002 * d, fRefRot);
	Layer[i]->AddNode(DeadL, d + 432, pMatrixd0);
      }
            
    }
    
    fdy += (thAlpide + thGlue) * 0.5;
    pMatrixd0 = new TGeoCombiTrans("", 0, fdy, 0., fRefRot);
    Layer[i]->AddNode(glue, barrelid, pMatrixd0);
    
    fdy += (thGlue + thCoolingfleece) * 0.5;
    pMatrixd0 = new TGeoCombiTrans("", 0, fdy, 0., fRefRot);
    Layer[i]->AddNode(C_coolingfleece, barrelid, pMatrixd0);
    
    fdy += (thCoolingfleece + thCooling) * 0.5;
    pMatrixd0 = new TGeoCombiTrans("", 0, fdy, 0., fRefRot);
    Layer[i]->AddNode(C_cooling, barrelid, pMatrixd0);
    
    fdy += (thCooling + thCoolingfleece) * 0.5;
    pMatrixd0 = new TGeoCombiTrans("", 0, fdy, 0., fRefRot);
    Layer[i]->AddNode(C_coolingfleece, barrelid, pMatrixd0);
    
  }

  int vv = 0;
  for (Int_t s = 0; s < nbmultilayers1; s++) {
    double ang = (s * (360. / nbmultilayers1))* TMath::DegToRad();
     double tilt_angle = 15 * TMath::DegToRad();
     //double dx_shift = (rd2 - rd1) * sin(tilt_angle) * cos(ang);  // Horizontal shift in the x-direction
    //double dy_shift = (rd2 - rd1) * sin(tilt_angle) * sin(ang);  // Horizontal shift in the y-direction
    dx = rd1 * cos(ang);
    dy = rd1 * sin(ang);
    // std::cout << "dx1: " << dx << std::endl;
    //std::cout << "dy1: " << dy << std::endl;
    dz = 0.;
   
    double x_rot = dx * cos(tilt_angle) - dy * sin(tilt_angle);  // Rotate in x-direction
    double y_rot = dx * sin(tilt_angle) + dy * cos(tilt_angle);
   
    
    //double tilt_angle = 20.5 * TMath::DegToRad();
   // dz = dx * sin(tilt_angle);

    TGeoRotation *arotb = new TGeoRotation();
    arotb->RotateZ(90. + (s * (360. / nbmultilayers1)));
    
    //if (s % 2 == 0) {
     // arotb->RotateX(180);
     // arotb->RotateY(180);
   // }
    auto pMatrixd0 =
        new TGeoCombiTrans("", x_rot, y_rot, dz + dzbarrels + general_zoffset-0.2, arotb);

    pWorld->AddNode(Layer[0], 1 + s, pMatrixd0);
    vv++;
 }

  vv = 0;
  for (Int_t s = nbmultilayers1; s < nbmultilayers1 + nbmultilayers2; s++) {
    auto index = s - nbmultilayers1;
    double ang = (index * (360. / nbmultilayers2)) * TMath::DegToRad();
    double tilt_angle = 15 * TMath::DegToRad();
    //double dx_offset = (rd2 - rd1) * sin(tilt_angle);
    //double dy_offset = (rd2 - rd1) * (1 - cos(tilt_angle));
    //double dx_shift = (rd2 - rd1) * sin(tilt_angle) * cos(ang);
    //double dy_shift = (rd2 - rd1) * sin(tilt_angle) * sin(ang);
    double dz_offset = (rd2 - rd1) * tan(tilt_angle);
    dx = (rd2 * cos(ang));
    dy = (rd2 * sin(ang));
    double dx1 = (rd1 * cos(ang));
    double dy1 = (rd1 * sin(ang));
    dz = 0.;
    
    double x_offset = 0.0, y_offset = 0.0;
    double x_rot = dx * cos(tilt_angle) - dy * sin(tilt_angle);  
    double y_rot = dx * sin(tilt_angle) + dy * cos(tilt_angle);

    double x_rot1 = dx1 * cos(tilt_angle) - dy1 * sin(tilt_angle);  
    double y_rot1 = dx1 * sin(tilt_angle) + dy1 * cos(tilt_angle);

    double outward_x = (0.7 * cos(ang));
    double outward_y = (0.7 * sin(ang));
    
     x_offset = x_rot1 - x_rot;
     y_offset = y_rot1 - y_rot;

     x_rot += x_offset;
     y_rot += y_offset;

     x_rot += outward_x;
     y_rot += outward_y;
    //double tilt_angle = 20.5 * TMath::DegToRad();
    //dz = dx * sin(tilt_angle);
    //std::cout << "dx2: " << dx << std::endl;
    //std::cout << "dy2: " << dy << std::endl;
    //double offset = (abs(dy) - abs((rd1 * sin(ang))));
    //std::cout << "offset: " << offset << std::endl;

    auto *arotb = new TGeoRotation();
    arotb->RotateZ(90. + (index * (360. / nbmultilayers2)));
    
   // if (index % 2 == 0) {
   //    arotb->RotateX(180);
   //    arotb->RotateY(180);
      //auto pMatrixd0 =
      /// new TGeoCombiTrans("", dx, dy, dz + dzbarrels + general_zoffset+0.2, arotb);
      //pWorld->AddNode(Layer[1], 1 + index, pMatrixd0);
  // }
   //else {
    //auto pMatrixd0 =
      //new TGeoCombiTrans("", dx, dy, dz + dzbarrels + general_zoffset+0.2, arotb);
      //pWorld->AddNode(Layer[1], 1 + index, pMatrixd0);
  // }
    auto pMatrixd0 = new TGeoCombiTrans("", x_rot, y_rot, dz + dzbarrels + general_zoffset-0.2, arotb);
    pWorld->AddNode(Layer[1], 1 + index, pMatrixd0);
    vv++;
  }

  // ---------------   Finish   -----------------------------------------------
  gGeoMan->CloseGeometry();
  gGeoMan->CheckOverlaps(0.001);
  gGeoMan->PrintOverlaps();
  gGeoMan->Test();

  TFile *geoFile = new TFile(geoFileName, "RECREATE");
  top->Write();
  top->Draw("ogl GL");
  geoFile->Close();
  std::cout << "\033[34m Creating geometry:\033[0m "
            << "\033[33m" << geoFileName << " \033[0m" << std::endl;
 // gApplication->Terminate();
}
