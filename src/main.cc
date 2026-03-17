#include <memory>
#include <string>

#include <TCanvas.h>
#include <TLatex.h>

int main( int argc, char* argv[] ){
  auto str_name = std::string{ argv[1] }.append(".png");
  auto c = std::unique_ptr<TCanvas>{new TCanvas("canv", "canv", 800, 600)};
  c->cd();
  auto text = std::unique_ptr<TLatex>{new TLatex(0.25, 0.2, "fuck.")};
  text->SetNDC();  
  text->SetTextSize(0.05);
  text->Draw();
  c->Update();
  c->Print( str_name.c_str() );

  return 111;
}