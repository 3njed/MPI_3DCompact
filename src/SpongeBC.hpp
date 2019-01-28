#ifndef _SPONGEBCH_
#define _SPONGEBCH_

#include <iostream>
#include "Macros.hpp"
#include "Options.hpp"
#include "Domain.hpp"
#include "IdealGas.hpp"
#include "BC.hpp"
#include "Utils.hpp"
#include "AbstractSingleBlockMesh.hpp"


class SpongeBC{

    public:

	AbstractSingleBlockMesh *msh;
	Domain *domain;
	IdealGas *idealGas;
	BC *bc;
	Options *opt;

	int Nx, Ny, Nz, N;

        int pxSize[3], pySize[3], pzSize[3]; 
        int pxStart[3], pyStart[3], pzStart[3];
        int pxEnd[3], pyEnd[3], pzEnd[3];
	int mpiRank;

	double avgT;
	double epsP;
	double spongeP;
	double spongeStrength;
	double spongeLX;
	double spongeLY;
	double spongeLZ;

	double *sigma;
	double *spongeRhoAvg;
	double *spongeRhoUAvg;
	double *spongeRhoVAvg;
	double *spongeRhoWAvg;
	double *spongeRhoEAvg;

	Options::SpongeKind spongeKind;
    
	SpongeBC(AbstractSingleBlockMesh *msh, Domain *domain, IdealGas *idealGas, BC *bc, C2Decomp *c2d, Options *opt, int mpiRank);
	void initRectSpongeBC();
	void initCylSpongeBC();

};

#endif
