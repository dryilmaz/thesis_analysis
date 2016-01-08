{
  TFile * mainroot = new TFile("result.root","READ");


  /////////////////////////
  ///rapidity res /////////
  /////////////////////////

  ////////////////////////
  //// 60 - 100 //////////
  ////////////////////////

  TH2F *hist_rapidity_res_60_100 = (TH2F*)mainroot->Get("hist_deltaY_60_100");
  TCanvas *rapidity_resolution = new TCanvas("Rapidity_Res_60_100","Rapidity_Res_60_100",0,0,1600,1600);
  rapidity_resolution->Divide(1,3);
  rapidity_resolution->cd(1);

    hist_rapidity_res_60_100->SetTitle("");
    hist_rapidity_res_60_100->GetXaxis()->SetTitle("y_{gen}");
    hist_rapidity_res_60_100->GetYaxis()->SetTitle("y_{gen}-y_{colo}");
    hist_rapidity_res_60_100->Draw("colz");

  rapidity_resolution->cd(2);

    TProfile *rapidity_profile = hist_rapidity_res_60_100->ProfileX();
    rapidity_profile->SetTitle("Rapidity_Res_60_100");
    rapidity_profile->SetMinimum(-0.2);
    rapidity_profile->SetMaximum(0.2);
    rapidity_profile->GetXaxis()->SetTitle("y_{gen}");
    rapidity_profile->GetYaxis()->SetTitle("y_{gen}-y_{colo}");
    rapidity_profile->Draw();
    TLine *l =new TLine(2.5,-0.2,2.5,0.2);
    l->SetLineColor(kRed);
    l->Draw("SAME");
    TLine *l1 = new TLine(-2.5,-0.2,-2.5,0.2);
    l1->SetLineColor(kRed);
    l1->Draw("SAME");

  rapidity_resolution->cd(3);
    TH1D * projection_60_100 = hist_rapidity_res_60_100->ProjectionY();
    TF1 *fit_projection_60_100 = new TF1("fit_projection_60_100","gaus",-0.2,0.2);
    projection_60_100->Fit("fit_projection_60_100","","",-0.2,0.2);
    projection_60_100->GetYaxis()->SetTitle("Events");
    projection_60_100->SetTitle("");
    projection_60_100->Draw();

  rapidity_resolution->Print("plots/rapi_60_100.eps");

  ////////////////////////
  //// 100 - 150 /////////
  ////////////////////////

  TH2F *hist_rapidity_res_100_150 = (TH2F*)mainroot->Get("hist_deltaY_100_150");
  TCanvas *rapidity_resolution1 = new TCanvas("Rapidity_Res_100_150","Rapidity_Res_100_150",0,0,1600,1600);
  rapidity_resolution1->Divide(1,3);
  rapidity_resolution1->cd(1);

    hist_rapidity_res_100_150->SetTitle("");
    hist_rapidity_res_100_150->GetXaxis()->SetTitle("y_{gen}");
    hist_rapidity_res_100_150->GetYaxis()->SetTitle("y_{gen}-y_{colo}");
    hist_rapidity_res_100_150->Draw("colz");

  rapidity_resolution1->cd(2);

    TProfile *rapidity_profile1 = hist_rapidity_res_100_150->ProfileX();
    rapidity_profile1->SetMinimum(-0.2);
    rapidity_profile1->SetMaximum(0.2);
    rapidity_profile1->GetXaxis()->SetTitle("y_{gen}");
    rapidity_profile1->GetYaxis()->SetTitle("y_{gen}-y_{colo}");
    rapidity_profile1->SetTitle("Rapidity_Res_100_150");
    rapidity_profile1->Draw();
    TLine *l =new TLine(2.5,-0.2,2.5,0.2);
    l->SetLineColor(kRed);
    l->Draw("SAME");
    TLine *l1 = new TLine(-2.5,-0.2,-2.5,0.2);
    l1->SetLineColor(kRed);
    l1->Draw("SAME");

  rapidity_resolution1->cd(3);

    TH1D * projection_100_150 = hist_rapidity_res_100_150->ProjectionY();
    TF1 *fit_projection_100_150 = new TF1("fit_projection_100_150","gaus",-0.2,0.2);
    projection_100_150->Fit("fit_projection_100_150","","",-0.2,0.2);
    projection_100_150->GetYaxis()->SetTitle("Events");
    projection_100_150->SetTitle("");
    projection_100_150->Draw();

    rapidity_resolution1->Print("plots/rapi_100_150.eps");


  ///////////////////////
  /////150 - 250 ////////
  ///////////////////////

  TH2F *hist_rapidity_res_150_200 = (TH2F*)mainroot->Get("hist_deltaY_150_200");
  TCanvas *rapidity_resolution2 = new TCanvas("Rapidity_Res_150_200","Rapidity_Res_150_200",0,0,1600,1600);
  rapidity_resolution2->Divide(1,3);
  rapidity_resolution2->cd(1);

    hist_rapidity_res_150_200->SetTitle("");
    hist_rapidity_res_150_200->GetXaxis()->SetTitle("y_{gen}");
    hist_rapidity_res_150_200->GetYaxis()->SetTitle("y_{gen}-y_{colo}");
    hist_rapidity_res_150_200->Draw("colz");

  rapidity_resolution2->cd(2);

    TProfile *rapidity_profile2 = hist_rapidity_res_150_200->ProfileX();
    rapidity_profile2->SetMinimum(-0.2);
    rapidity_profile2->SetMaximum(0.2);
    rapidity_profile2->GetXaxis()->SetTitle("y_{gen}");
    rapidity_profile2->GetYaxis()->SetTitle("y_{gen}-y_{colo}");
    rapidity_profile2->SetTitle("Rapidity_Res_150_200");
    rapidity_profile2->Draw();
    TLine *l =new TLine(2.5,-0.2,2.5,0.2);
    l->SetLineColor(kRed);
    l->Draw("SAME");
    TLine *l1 = new TLine(-2.5,-0.2,-2.5,0.2);
    l1->SetLineColor(kRed);
    l1->Draw("SAME");

  rapidity_resolution2->cd(3);

    TH1D * projection_150_200 = hist_rapidity_res_150_200->ProjectionY();
    TF1 *fit_projection_150_200 = new TF1("fit_projection_150_200","gaus",-0.2,0.2);
    projection_150_200->Fit("fit_projection_150_200","","",-0.2,0.2);
    projection_150_200->GetYaxis()->SetTitle("Events");
    projection_150_200->SetTitle("");
    projection_150_200->Draw();

  rapidity_resolution2->Print("plots/rapi_150_200.eps");

  //////////////////////////
  //R32 for genjet/////////
  /////////////////////////

  TH1F *hist2genjetht = (TH1F*)mainroot->Get("histgen2jetht");
  TH1F *hist3genjetht = (TH1F*)mainroot->Get("histgen3jetht");
  TCanvas *ratio3over2gen = new TCanvas("3jets2jetsgen","3jets and 2 jets gen",0,0,1600,1600);

  ratio3over2gen->Divide(1,2);
  ratio3over2gen->cd(1);
    gPad->SetGrid();
    gPad->SetLogy();
    gPad->SetLogx();

    hist2genjetht->SetMarkerStyle(23);
    hist2genjetht->SetLineColor(kRed);
    hist2genjetht->SetMarkerColor(kRed);
    hist2genjetht->GetXaxis()->SetRangeUser(100,2000);
    hist2genjetht->SetTitle("gen HT dist. jets #geq 3 and #geq 2");
    hist2genjetht->GetXaxis()->SetTitle("genjet HT (GeV)");
    hist2genjetht->Draw("E1");
    hist3genjetht->SetMarkerStyle(22);
    hist3genjetht->SetMarkerColor(kBlue);
    hist3genjetht->SetLineColor(kBlue);
    hist3genjetht->Draw("SAME E1");


    ratio3over2gen->cd(2);
    gPad->SetGrid();
    TH1F *Ratio32gen = (TH1F*)hist3genjetht->Clone("Ratio32gen");
    Ratio32gen->SetLineColor(kBlue);
    Ratio32gen->SetMinimum(0);
    Ratio32gen->SetMaximum(1);
    Ratio32gen->GetXaxis()->SetRangeUser(100,2000);
    Ratio32gen->Divide(hist2genjetht);
    Ratio32gen->SetMarkerStyle(21);
    Ratio32gen->SetTitle("Ratio of Njets>3 over Njets>2");
    Ratio32gen->GetXaxis()->SetTitle("Gen HT (GeV)");
    Ratio32gen->GetYaxis()->SetTitle("Ratio_{32} for Genjet");
    Ratio32gen->Draw();
    ratio3over2gen->Print("plots/Ratiogenjet32.eps");


    ////////////////////////
    //R32 for colojet///////
    ////////////////////////

    TH1F *hist2colojetht = (TH1F*)mainroot->Get("histcolo2jetht");
    TH1F *hist3colojetht = (TH1F*)mainroot->Get("histcolo3jetht");
    TCanvas *ratio3over2colo = new TCanvas("3jets2jetscolo","3 jets and 2 jets colo",0,0,1600,1600);

    ratio3over2colo->Divide(1,2);
    ratio3over2colo->cd(1);
    gPad->SetGrid();
    gPad->SetLogy();
    gPad->SetLogx();

    hist2colojetht->SetMarkerStyle(23);
    hist2colojetht->SetLineColor(kBlue);
    hist2colojetht->SetMarkerColor(kBlue);
    hist2colojetht->GetXaxis()->SetRangeUser(100,2000);
    hist2colojetht->SetTitle("colo HT dist. jets #geq3 and #geq2");
    hist2colojetht->GetXaxis()->SetTitle("colo HT (GeV)");
    hist2colojetht->Draw("E1");
    hist3colojetht->SetMarkerStyle(22);
    hist3colojetht->SetMarkerColor(kRed);
    hist3colojetht->SetLineColor(kRed);
    hist3colojetht->Draw("SAME E1");

    ratio3over2colo->cd(2);
    gPad->SetGrid();
    TH1F *Ratio32colo = (TH1F*)hist3colojetht->Clone("Ratio32colo");
    Ratio32colo->SetLineColor(kBlue);
    Ratio32colo->SetMinimum(0);
    Ratio32colo->SetMaximum(1);
    Ratio32colo->GetXaxis()->SetRangeUser(100,2000);
    Ratio32colo->Divide(hist2colojetht);
    Ratio32colo->SetMarkerStyle(21);
    Ratio32colo->SetTitle("R_{32} Njets #geq3 over Njets #geq2");
    Ratio32colo->GetXaxis()->SetTitle("Colo HT (GeV)");
    Ratio32colo->GetYaxis()->SetTitle("R_{32} for Colojet");
    Ratio32colo->Draw();
    ratio3over2colo->Print("plots/Ratiocolojet32.eps");


    ///////////////////////////
    ///r32 colo over r32 gen///
    ///////////////////////////

    TCanvas *coloandgen = new TCanvas("coloandgen","R_{32}",0,0,1600,1600);
    coloandgen->Divide(1,2);
    coloandgen->cd(1);
    gPad->SetGrid();
    Ratio32colo->SetMarkerStyle(20);
    Ratio32colo->SetMarkerColor(kRed);
    Ratio32colo->SetLineColor(kRed);
    Ratio32colo->SetTitle("ColoJet and GenJet");
    Ratio32colo->GetYaxis()->SetTitle("Ratio R_{32} colo and gen");
    Ratio32colo->GetXaxis()->SetTitle("HT (GeV)");
    Ratio32colo->Draw();
    Ratio32gen->SetMarkerStyle(26);
    Ratio32gen->SetMarkerColor(kRed);
    Ratio32gen->Draw("SAME");


    coloandgen->cd(2);
    TH1F *coloovergenr32 = (TH1F*)Ratio32colo->Clone("coloovergenr32");
    gPad->SetGrid();
    coloovergenr32->Divide(Ratio32gen);
    coloovergenr32->SetMinimum(0);
    coloovergenr32->SetMaximum(2);
    coloovergenr32->SetTitle("Ratio");
    coloovergenr32->Draw();
    coloandgen->Print("plots/coloovergenr32.eps");

    //////////////////////////////////////////
    //////l nl nnl ///////////////////////////
    //////////////////////////////////////////

    TH2F *leadingjetpt = (TH2F*)mainroot->Get("histresleadingjet");
    TH2F *nleadingjetpt = (TH2F*)mainroot->Get("hist_nleading_pt_res");
    TH2F *nnleadingjetpt = (TH2F*)mainroot->Get("hist_nnleading_pt_res");

    //////////////////////////////////////
    ///leadingjet ////////////////////////
    //////////////////////////////////////

    TCanvas* leading_jet_pt_canvas = new TCanvas("leading_jet_pt_canvas","leading_jet_pt_canvas",0,0,1600,1600);
    leading_jet_pt_canvas->Divide(1,2);
    leading_jet_pt_canvas->cd(1);
    leadingjetpt->SetTitle("leading jet pt");
    leadingjetpt->Draw("colz");

    leading_jet_pt_canvas->cd(2);
    TProfile *leading_jet_pt_profile = leadingjetpt->ProfileX();
    gPad->SetGrid();
    leading_jet_pt_profile->SetMinimum(-0.5);
    leading_jet_pt_profile->SetMaximum(0.5);
    leading_jet_pt_profile->Draw("][ hist");

    leading_jet_pt_canvas->Print("plots/leading_jet_pt_profile.eps");



}
