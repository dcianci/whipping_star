#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <unistd.h>
#include <getopt.h>
#include <cstring>

#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TString.h"
#include "TNtuple.h"
#include "TChain.h"
#include "TMath.h"
#include "TSystem.h"
#include "TMatrixT.h"
#include "TRandom.h"
#include "TError.h"
#include "TCanvas.h"
#include "TH2F.h"
#include "TGraph.h"

#include "params.h"
#include "SBNconfig.h"
#include "SBNchi.h"
#include "SBNspec.h"
#include "SBNosc.h"
#include "SBNfit.h"
#include "SBNfit3pN.h"
#include "SBNmultisim.h"

#define no_argument 0
#define required_argument 1
#define optional_argument 2

using namespace sbn;

/*************************************************************
 *************************************************************
 *		BEGIN example.cxx
 ************************************************************
 ************************************************************/
int main(int argc, char* argv[])
{

	std::string xml = "example.xml";
	int iarg = 0;
	opterr=1;
	int index;

	/*************************************************************
	 *************************************************************
	 *		Command Line Argument Reading
	 ************************************************************
	 ************************************************************/
	const struct option longopts[] =
	{
		{"xml", 		required_argument, 	0, 'x'},
		{0,			no_argument, 		0,  0},
	};

	while(iarg != -1)
	{
		iarg = getopt_long(argc,argv, "x:", longopts, &index);

		switch(iarg)
		{
			case 'x':
				xml = optarg;
				break;
			case '?':
			case 'h':
				std::cout<<"Allowed arguments:"<<std::endl;
				std::cout<<"\t-x\t--xml\t\tInput .xml file for SBNconfig"<<std::endl;
				return 0;
		}
	}

	/*************************************************************
	 *************************************************************
	 *			Main Program Flow
	 ************************************************************
	 ************************************************************/
	time_t start_time = time(0);
	std::cout<<"Begining Covariance Calculation: "<<std::endl;

	//a tag to identify outputs
	std::string tag = "EXAMPLE1";

	//Create a SBNmultisim object initilizing with the inputted xml
	//This will load all the files and weights as laid out
	SBNmultisim example_multisim(xml);

	//Form the covariance matrix from loaded weights and MC events
	example_multisim.formCovarianceMatrix(tag);

	//and make some plots of the resulting things
	//Will be outputted in the form: SBNfit_covariance_plots_TAG.root
	example_multisim.printMatricies(tag);

	std::cout << "Total wall time: " << difftime(time(0), start_time)/60.0 << " Minutes.\n";
	return 0;

}
