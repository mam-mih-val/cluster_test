#include <memory>
#include <string>
#include <functional>

#include <TCanvas.h>
#include <TLatex.h>
#include <TFile.h>
#include <TTree.h>

int main( int argc, char* argv[] ){
  auto str_name = std::string{ argv[1] }.append(".png");
  auto str_file_name = std::string{ argv[2] };
  auto c = std::unique_ptr<TCanvas>{new TCanvas("canv", "canv", 800, 600)};
  c->cd();
  auto text = std::unique_ptr<TLatex>{new TLatex(0.25, 0.2, "fuck.")};
  text->SetNDC();  
  text->SetTextSize(0.05);
  text->Draw();
  c->Update();
  c->Print( str_name.c_str() );

  auto file = std::unique_ptr<TFile, std::function<void(TFile*)>>{ TFile::Open( str_file_name.c_str(), "read"), [](auto* f){ f->Close(); }};
  
  if( !file )
    return 9;
  TTree* tree{nullptr};
  file->GetObject( "t", tree );
  if( !tree )
    return 9;

  return 111;
}